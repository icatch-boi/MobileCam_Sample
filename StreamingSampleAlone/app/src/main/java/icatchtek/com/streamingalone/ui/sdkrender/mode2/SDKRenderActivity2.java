package icatchtek.com.streamingalone.ui.sdkrender.mode2;

import android.app.Activity;
import android.content.res.Resources;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.SurfaceView;
import android.view.View;
import android.widget.Button;

import com.icatchtek.pancam.customer.ICatchIPancamPreview;
import com.icatchtek.pancam.customer.ICatchPancamSession;
import com.icatchtek.pancam.customer.stream.ICatchIStreamProvider;
import com.icatchtek.pancam.customer.surface.ICatchISurfaceContext;
import com.icatchtek.pancam.customer.surface.ICatchSurfaceContext;
import com.icatchtek.pancam.customer.type.ICatchGLColor;
import com.icatchtek.pancam.customer.type.ICatchGLDisplayPPI;
import com.icatchtek.reliant.customer.exception.IchInvalidSessionException;
import com.icatchtek.reliant.customer.exception.IchTransportException;
import com.icatchtek.reliant.customer.transport.ICatchINETTransport;
import com.icatchtek.reliant.customer.transport.ICatchITransport;
import com.icatchtek.reliant.customer.type.ICatchH264StreamParam;
import com.icatchtek.reliant.customer.type.ICatchStreamParam;

import icatchtek.com.streamingalone.R;

public class SDKRenderActivity2 extends Activity
{
    private ICatchITransport transport;
    protected ICatchPancamSession pancamSession;

    private ICatchIPancamPreview preview;
    private StreamingHandler     streamingHandler;

    //----------------------------------------------------------------------------------------------
    /* Override activity's lifecycle methods. */
    //----------------------------------------------------------------------------------------------
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_render);

        /* ------step 1------------------------*/
        /* create and prepare transport */
        /* ------step 1------------------------*/
        transport = new ICatchINETTransport("192.168.1.1");
        try {
            transport.prepareTransport();
        } catch (IchTransportException e) {
            e.printStackTrace();
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
        } catch (IchTransportException e) {
            e.printStackTrace();
            System.exit(-1);
        }
        this.preview = this.pancamSession.getPreview();
        if (this.preview == null) {
            System.exit(-1);
        }

        /* ------step 3------------------------*/
        /* decide to use app render, get an instance of ICatchIStreamProvider' object */
        /* ------step 3------------------------*/
        try {
            /* disable render, create streaming provider(app instance) */
            ICatchIStreamProvider streamProvider = this.preview.disableRender();
            this.streamingHandler = new StreamingHandler(streamProvider);
        }
        catch(Exception ex)
        {
            ex.printStackTrace();
            System.exit(-1);
        }

        /* ------step 4------------------------*/
        /* start/stop streaming after each onclick event triggered */
        /* ------step 4------------------------*/
        Button btn_start_stream = findViewById(R.id.start_stream);
        btn_start_stream.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                /* create stream parameter & use it as parameter to start stream */
                try {
                    ICatchStreamParam param = new ICatchH264StreamParam();
                    boolean retVal = preview.start(param);
                    if (!retVal) {
                        return;
                    }
                }
                catch(Exception ex) {
                    ex.printStackTrace();
                    return;
                }
                SurfaceView surfaceView = findViewById(R.id.surfaceView1);
                ICatchISurfaceContext surfaceContext = new ICatchSurfaceContext(surfaceView.getHolder().getSurface());
                streamingHandler.start(surfaceContext, pancamSession.getImage());
            }
        });

        Button btn_stop_stream = findViewById(R.id.stop_stream);
        btn_stop_stream.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                /* stop grab frame & render process */
                streamingHandler.stop();
                try {
                    preview.stop();
                }
                catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        });
    }

    protected void onDestroy()
    {
        super.onDestroy();

        /* ------step 5------------------------*/
        /* destroy session */
        /* ------step 5------------------------*/
        /* create session, prepare session */
        try {
            pancamSession.destroySession();
        } catch (IchInvalidSessionException e) {
            e.printStackTrace();
            System.exit(-1);
        }

        /* ------step 6------------------------*/
        /* destroy transport */
        /* ------step 6------------------------*/
        try {
            this.transport.destroyTransport();
        } catch (IchTransportException e) {
            e.printStackTrace();
        }
    }
}
