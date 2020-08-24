package icatchtek.com.streamingalone.ui.sdkrenderoverusb;

import android.content.res.Resources;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.View;
import android.widget.Button;

import com.icatchtek.control.customer.ICatchCameraLog;
import com.icatchtek.control.customer.ICatchCameraProperty;
import com.icatchtek.control.customer.ICatchCameraSession;
import com.icatchtek.control.customer.type.ICatchCamLogLevel;
import com.icatchtek.control.customer.type.ICatchCamLogType;
import com.icatchtek.pancam.customer.ICatchIPancamPreview;
import com.icatchtek.pancam.customer.ICatchPancamSession;
import com.icatchtek.pancam.customer.type.ICatchGLColor;
import com.icatchtek.pancam.customer.type.ICatchGLDisplayPPI;
import com.icatchtek.reliant.customer.exception.IchInvalidSessionException;
import com.icatchtek.reliant.customer.exception.IchTransportException;
import com.icatchtek.reliant.customer.transport.ICatchITransport;
import com.icatchtek.reliant.customer.transport.ICatchUVCBulkTransport;
import com.icatchtek.reliant.customer.transport.ICatchUVCIsoTransport;
import com.icatchtek.reliant.customer.transport.ICatchUsbScsiTransport;
import com.icatchtek.reliant.customer.transport.ICatchUsbTransportLog;
import com.icatchtek.reliant.customer.type.ICatchH264StreamParam;
import com.icatchtek.reliant.customer.type.ICatchStreamParam;

import icatchtek.com.streamingalone.R;
import icatchtek.com.streamingalone.ui.BaseSurfaceActivity;
import icatchtek.com.streamingalone.ui.sdkrenderoverusb.usb.MainActivityAttributes;
import icatchtek.com.streamingalone.ui.sdkrenderoverusb.usb.NotificationHandler;
import icatchtek.com.streamingalone.ui.sdkrenderoverusb.usb.USBHost_Feature;

public class SDKRenderActivity2 extends BaseSurfaceActivity
{
    public static int __USB_TYPE__  = MainActivityAttributes.USB_TYPE_BULK;
    public static int __VENDOR_ID__ = USBHost_Feature.USB_VENDOR_ID;
    public static int __PRODUCT_ID  = USBHost_Feature.USB_PRODUCT_ID;

    private USBHost_Feature feature;

    private ICatchITransport transport;
    private ICatchPancamSession pancamSession;
    private ICatchCameraSession cameraSession;
    private ICatchCameraProperty cameraProperty;

    private ICatchIPancamPreview preview;
    private boolean renderReady = false;

    @Override
    protected void setContentViewWhichHasSurfaceView1()
    {
        setContentView(R.layout.activity_render_usb);
    }

    //----------------------------------------------------------------------------------------------
    /* Override activity's lifecycle methods. */
    //----------------------------------------------------------------------------------------------
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        /* init logger first */
        initSDKLogger2();
        String pancamSDKPath = Environment.getExternalStorageDirectory().getPath();
        initUsbTransportLog(pancamSDKPath);

        /* create feature, set device, register */
        Handler handler = new NotificationHandler(this);
        this.feature = new USBHost_Feature(this, handler);
        this.feature.setUsbDevice(this, __VENDOR_ID__,  __PRODUCT_ID);
        this.feature.register();

        /* ------step 1------------------------*/
        /* create and prepare transport */
        /* ------step 1------------------------*/
        try {
            switch (__USB_TYPE__) {
                case MainActivityAttributes.USB_TYPE_ISO:
                    this.transport = new ICatchUVCIsoTransport(__VENDOR_ID__, __PRODUCT_ID, this.feature.getFileDescriptor());
                    break;
                case MainActivityAttributes.USB_TYPE_SCSI:
                    this.transport = new ICatchUsbScsiTransport(this.feature.getUsbDevice(), this.feature.getUsbDeviceConnection());
                    break;
                case MainActivityAttributes.USB_TYPE_BULK:
                default: /* default bulk */
                    this.transport = new ICatchUVCBulkTransport(this.feature.getUsbDevice(), this.feature.getUsbDeviceConnection());
                    break;
            }
        }
        catch (Exception ex) {
            ex.printStackTrace();
            Log.i("__render_over_usb__", "exit with create transport exception: " + ex.getMessage());
            System.exit(-1);
        }

        try {
            transport.prepareTransport();
        } catch (IchTransportException ex) {
            ex.printStackTrace();
            Log.i("__render_over_usb__", "exit with prepare transport exception: " + ex.getMessage());
            System.exit(1);
        }

        /* ------step 2------------------------*/
        /* create and prepare session */
        /* ------step 2------------------------*/
        /* get display ppi needed by session */
        DisplayMetrics displayMetrics = Resources.getSystem().getDisplayMetrics();
        ICatchGLDisplayPPI displayPPI = new ICatchGLDisplayPPI(displayMetrics.xdpi, displayMetrics.ydpi);

        /* create session, prepare session, and get the preview client */
        try {
            pancamSession = ICatchPancamSession.createSession();
            pancamSession.prepareSession(transport, ICatchGLColor.BLACK, displayPPI);
        } catch (IchTransportException ex) {
            ex.printStackTrace();
            Log.i("__render_over_usb__", "exit with create/prepare pancam session exception: " + ex.getMessage());
            System.exit(-1);
        }
        this.preview = this.pancamSession.getPreview();
        if (this.preview == null) {
            Log.i("__render_over_usb__", "could not get preview client");
            System.exit(-1);
        }

        /* The step 3 please refers to prepareRender() method, The surfaceView's operations must waiting The SurfaceView component ready */

        /* ------step 4------------------------*/
        /* start/stop streaming after each onclick event triggered */
        /* ------step 4------------------------*/
        Button btn_start_stream = findViewById(R.id.start_stream);
        btn_start_stream.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                /* prepare render if needed, only need to do once */
                if (!renderReady) {
                    prepareRender();
                    renderReady = true;
                }
                /* create stream parameter & use it as parameter to start stream */
                try {
                    ICatchStreamParam param = new ICatchH264StreamParam();
                    boolean retVal = preview.start(param);
                    if (!retVal) {
                        Log.i("__render_over_usb__", "start stream failed, retVal false ");
                      }
                }
                catch(Exception ex) {
                    ex.printStackTrace();
                    Log.i("__render_over_usb__", "start stream failed: " + ex.getMessage());
                }
            }
        });

        Button btn_stop_stream = findViewById(R.id.stop_stream);
        btn_stop_stream.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                /* stop grab frame & render process */
                try {
                    preview.stop();
                }
                catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        });

        /* ------------------------------------*/
        /* The usb related operations */
        /* ------------------------------------*/
        Button btn_exu_cmd_set = findViewById(R.id.exuCmdSet);
        btn_exu_cmd_set.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                /* The parameters here should be filled with the extended command information you added to the camera, including command type (Set/Get), data format, data length, etc. */
                int cmdID = 0x0;                  /* your exu cmd's cmd ID */
                int dataSize = 0x08;              /* your exu cmd's  data size */
                byte[] data = new byte[dataSize]; /* fill the data with the format that the camera can understand. */

                /* a set command */
                sendExtensionSetCommand(cmdID, data, dataSize);
            }
        });

        Button btn_exu_cmd_get = findViewById(R.id.exuCmdGet);
        btn_exu_cmd_get.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                /* The parameters here should be filled with the extended command information you added to the camera, including command type (Set/Get), data format, data length, etc. */
                int cmdID = 0x0;                  /* your exu cmd's cmd ID */
                int dataSize = 0x08;              /* your exu cmd's  data size */
                byte[] data = new byte[dataSize]; /* fill the data with the format that the camera can understand. */

                /* a get command */
                dataSize = sendExtensionGetCommand(cmdID, data);
                Log.i("xx", "dataSize: " + dataSize);
            }
        });
    }

    protected void onStart()
    {
        super.onStart();

        /* create and prepare command session */
        this.cameraSession = ICatchCameraSession.createSession();
        try {
            this.cameraSession.prepareSession(this.transport);
            this.cameraProperty = this.cameraSession.getPropertyClient();
        } catch (Exception ex) {
            ex.printStackTrace();
            Log.i("__render_over_usb__", "exit with create/prepare camera session exception: " + ex.getMessage());
        }
    }

    private void prepareRender()
    {
        /* ------step 3------------------------*/
        /* decide to use app render, get an instance of ICatchIStreamProvider' object */
        /* ------step 3------------------------*/
        try {
            /* disable render, create streaming provider(app instance) */
            boolean retVal = this.preview.enableRender(surfaceContext);
            Log.i("__render_over_usb__", "call enable render method retVal: " + retVal);
        }
        catch(Exception ex)
        {
            ex.printStackTrace();
            Log.i("__render_over_usb__", "call disable render method failed: " + ex.getMessage());
            System.exit(-1);
        }
    }

    protected void surfaceViewAvailableNotify()
    {
        Log.i("__render_over_usb__", "surfaceViewAvailableNotify");
    }

    protected void surfaceViewUnavailableNotify()
    {
        Log.i("__render_over_usb__", "surfaceViewUnavailableNotify");
    }

    protected void onStop()
    {
        super.onStop();

        /* destroy command session */
        try {
            if (this.cameraSession != null) {
                this.cameraSession.destroySession();
            }
        }
        catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    protected void onDestroy()
    {
        super.onDestroy();

        /* stop grab frame & render process */
        try {
            preview.stop(); // call just for safe
        }
        catch (Exception ex) {
            ex.printStackTrace();
        }

        /* ------step 6------------------------*/
        /* destroy session */
        /* ------step 6------------------------*/
        /* destroy session, destroy session */
        try {
            pancamSession.destroySession();
        } catch (IchInvalidSessionException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        /* ------step 7------------------------*/
        /* destroy transport */
        /* ------step 7------------------------*/
        try {
            this.transport.destroyTransport();
        } catch (IchTransportException e) {
            e.printStackTrace();
        }

        /* ------------------------------------*/
        /* unregister feature(usb) */
        /* ------------------------------------*/
        if (this.feature != null) {
            this.feature.unregister();
        }
    }

    public void sendExtensionSetCommand(int command, byte[] data, int dataSize)
    {
        try {
            cameraProperty.setProperty(command, data, dataSize);
        }
        catch(Exception ex) {
            ex.printStackTrace();
        }
    }

    public int sendExtensionGetCommand(int command, byte[] data)
    {
        try {
            return cameraProperty.getProperty(command, data);
        }
        catch(Exception ex) {
            ex.printStackTrace();
        }
        return 0;
    }

    private void initSDKLogger2()
    {
        String pancamSDKPath = Environment.getExternalStorageDirectory().getPath();

        ICatchCameraLog.getInstance().setDebugMode(true);
        ICatchCameraLog.getInstance().setFileLogPath(pancamSDKPath);
        ICatchCameraLog.getInstance().setFileLogOutput(true);
        ICatchCameraLog.getInstance().setSystemLogOutput(true);

        ICatchCameraLog.getInstance().setLog(ICatchCamLogType.ICH_CAM_LOG_TYPE_COMMON, true);
        ICatchCameraLog.getInstance().setLogLevel(ICatchCamLogType.ICH_CAM_LOG_TYPE_COMMON, ICatchCamLogLevel.ICH_CAM_LOG_LEVEL_INFO);
    }

    private void initUsbTransportLog(String path) {
        ICatchUsbTransportLog.getInstance().setFileLogPath(path);
        ICatchUsbTransportLog.getInstance().setDebugMode(true);
        ICatchUsbTransportLog.getInstance().setFileLogOutput(true);
        ICatchUsbTransportLog.getInstance().setSystemLogOutput(true);
    }
}
