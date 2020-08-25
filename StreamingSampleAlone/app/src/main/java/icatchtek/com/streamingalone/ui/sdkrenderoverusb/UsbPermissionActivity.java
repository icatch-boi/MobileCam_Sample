package icatchtek.com.streamingalone.ui.sdkrenderoverusb;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.hardware.usb.UsbDevice;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.Toast;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import icatchtek.com.streamingalone.R;
import icatchtek.com.streamingalone.ui.sdkrenderoverusb.usb.NotificationHandler;
import icatchtek.com.streamingalone.ui.sdkrenderoverusb.usb.USBHost_Feature;
import icatchtek.com.streamingalone.ui.sdkrenderoverusb.usb.MainActivityAttributes;

public class UsbPermissionActivity extends Activity
{
    private int usbType;
    private Spinner spDevices;
    private Map<String, UsbDevice> usbDeviceMap = new HashMap<>();

    private USBHost_Feature feature;

    //----------------------------------------------------------------------------------------------
    /* Override activity's lifecycle methods. */
    //----------------------------------------------------------------------------------------------
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_usb_premission);

        /* create feature, set device, register */
        Handler handler = new UsbNotificationHandler(this);
        this.feature = new USBHost_Feature(this, handler);
        this.feature.register();

        /* ------------------------------------*/
        /* The usb list */
        /* ------------------------------------*/
        spDevices = (Spinner)findViewById(R.id.sp_devices);
        spDevices.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
                String key = adapterView.getItemAtPosition(i).toString();
                UsbDevice usbDevice = usbDeviceMap.get(key);
                feature.setUsbDevice(UsbPermissionActivity.this, usbDevice.getVendorId(), usbDevice.getProductId());
            }

            @Override
            public void onNothingSelected(AdapterView<?> adapterView) {
                feature.setUsbDevice(UsbPermissionActivity.this, USBHost_Feature.USB_VENDOR_ID, USBHost_Feature.USB_PRODUCT_ID);
            }
        });

        Spinner spUSBType = (Spinner)findViewById(R.id.sp_usb_type);
        spUSBType.setOnItemSelectedListener(new Spinner.OnItemSelectedListener() {

            public void onItemSelected(AdapterView<?> arg0, View arg1, int arg2, long arg3) {
                String content = arg0.getItemAtPosition(arg2).toString();
                if (content.equals(MainActivityAttributes.USB_TYPE_ISO_KEY)) {
                    usbType = MainActivityAttributes.USB_TYPE_ISO;
                }
                if (content.equals(MainActivityAttributes.USB_TYPE_BULK_KEY)) {
                    usbType = MainActivityAttributes.USB_TYPE_BULK;
                }
            }

            public void onNothingSelected(AdapterView<?> arg0) {
                usbType = MainActivityAttributes.USB_TYPE_ISO;

            }
        });
        spUSBType.setSelection(1);

        /* ------------------------------------*/
        /* The usb related operations */
        /* ------------------------------------*/
        Button request_permission = findViewById(R.id.request_permission);
        request_permission.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                feature.requestPermission();
            }
        });

        Button preview_activity = findViewById(R.id.PreviewActivity);
        preview_activity.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent();
                intent.putExtra("usbType", usbType);
                intent.putExtra("vendorID", feature.getVendorID());
                intent.putExtra("productID", feature.getProductID());
                intent.setClass(UsbPermissionActivity.this, SDKRenderActivity2.class);
                startActivity(intent);
            }
        });
    }

    protected void onDestroy()
    {
        super.onDestroy();

        if (this.feature != null) {
            this.feature.unregister();
        }
    }

    protected void onResume()
    {
        super.onResume();
        updateSpinner();
    }

    private void updateSpinner()
    {
        List<UsbDevice> usbDevices = feature.getExistsUsbDevices();
        if (usbDevices == null) {
            Toast.makeText(this, "No usb device connected to your phone, Please check the connection", Toast.LENGTH_SHORT).show();
            return;
        }

        ArrayAdapter<String> adapter = new ArrayAdapter<>(this , android.R.layout.simple_spinner_item);
        for (UsbDevice usbDevice : usbDevices) {
            String usbName = USBHost_Feature.generateNameForUsbDevice(usbDevice);
            adapter.add(usbName);
            usbDeviceMap.put(usbName, usbDevice);
        }
        spDevices.setAdapter(adapter);
    }

    class UsbNotificationHandler extends NotificationHandler
    {
        UsbNotificationHandler(Context context)
        {
            super(context);
        }

        @Override
        public void handleMessage(Message message) {
            super.handleMessage(message);
            switch (message.what)
            {
                case USBHost_Feature.HANDLER_USB_DEVICE_ATTACHED_ID:
                    Toast.makeText(UsbPermissionActivity.this, "get the usb device attached event", Toast.LENGTH_SHORT).show();
                    updateSpinner();
                    break;
                case USBHost_Feature.HANDLER_USB_DEVICE_DETACHED_ID:
                    Toast.makeText(UsbPermissionActivity.this, "get the usb device detached event", Toast.LENGTH_SHORT).show();
                    updateSpinner();
                    break;
                default:
                    break;
            }
        }
    }
}
