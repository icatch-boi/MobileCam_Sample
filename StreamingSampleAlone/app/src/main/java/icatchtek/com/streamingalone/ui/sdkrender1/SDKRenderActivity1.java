/**************************************************************************
 *
 *         Copyright (c) 2014 by iCatch Technology Co., Ltd.
 *
 *  This software is copyrighted by and is the property of Sunplus
 *  Technology Co., Ltd. All rights are reserved by Sunplus Technology
 *  Co., Ltd. This software may only be used in accordance with the
 *  corresponding license agreement. Any unauthorized use, duplication,
 *  distribution, or disclosure of this software is expressly forbidden.
 *
 *  This Copyright notice MUST not be removed or modified without prior
 *  written consent of Sunplus Technology Co., Ltd.
 *
 *  Sunplus Technology Co., Ltd. reserves the right to modify this
 *  software without notice.
 *
 *  Sunplus Technology Co., Ltd.
 *  19, Innovation First Road, Science-Based Industrial Park,
 *  Hsin-Chu, Taiwan, R.O.C.
 *
 *  Author: peng.tan
 *  Email:  peng.tan@sunmedia.com.cn
 *
 **************************************************************************/

package icatchtek.com.streamingalone.ui.sdkrender1;

import android.content.res.Resources;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.View;
import android.widget.Button;

import com.icatchtek.pancam.customer.ICatchIPancamPreview;
import com.icatchtek.pancam.customer.ICatchPancamSession;
import com.icatchtek.pancam.customer.type.ICatchGLColor;
import com.icatchtek.pancam.customer.type.ICatchGLDisplayPPI;
import com.icatchtek.reliant.customer.exception.IchInvalidSessionException;
import com.icatchtek.reliant.customer.exception.IchTransportException;
import com.icatchtek.reliant.customer.transport.ICatchINETTransport;
import com.icatchtek.reliant.customer.transport.ICatchITransport;
import com.icatchtek.reliant.customer.type.ICatchH264StreamParam;
import com.icatchtek.reliant.customer.type.ICatchStreamParam;

import icatchtek.com.streamingalone.R;
import icatchtek.com.streamingalone.ui.BaseSurfaceActivity;

public class SDKRenderActivity1 extends BaseSurfaceActivity
{
    private ICatchITransport transport;
    protected ICatchPancamSession pancamSession;

    private ICatchIPancamPreview preview;
    private boolean renderReady = false;

    @Override
    protected void setContentViewWhichHasSurfaceView1()
    {
        setContentView(R.layout.activity_render);
    }

    //----------------------------------------------------------------------------------------------
    /* Override activity's lifecycle methods. */
    //----------------------------------------------------------------------------------------------
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

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
                        Log.i("__render__", "start stream failed, retVal false ");
                    }
                }
                catch(Exception ex) {
                    ex.printStackTrace();
                    Log.i("__render__", "start stream failed: " + ex.getMessage());
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
    }

    @Override
    protected void onDestroy()
    {
        super.onDestroy();

        /* Add code there to make ensure that the stream is closed */
        try {
            this.preview.stop();
        } catch (Exception e) {
            e.printStackTrace();
        }

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

    private void prepareRender()
    {
        /* ------step 3------------------------*/
        /* decide to use app render, get an instance of ICatchIStreamProvider' object */
        /* ------step 3------------------------*/
        try {
            /* disable render, create streaming provider(app instance) */
            boolean retVal = this.preview.enableRender(surfaceContext);
            Log.i("__render__", "call enable render method retVal: " + retVal);
        }
        catch(Exception ex)
        {
            ex.printStackTrace();
            Log.i("__render__", "call disable render method failed: " + ex.getMessage());
            System.exit(-1);
        }
    }

    protected void surfaceViewAvailableNotify()
    {
        Log.i("__render__", "surfaceViewAvailableNotify");
    }

    protected void surfaceViewUnavailableNotify()
    {
        Log.i("__render__", "surfaceViewUnavailableNotify");
    }
}
