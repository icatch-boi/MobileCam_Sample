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

package icatchtek.com.streamingalone.ui.sdkrender.mode1;

import android.app.Activity;
import android.content.res.Resources;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.SurfaceView;

import com.icatchtek.pancam.customer.ICatchIPancamPreview;
import com.icatchtek.pancam.customer.ICatchPancamSession;
import com.icatchtek.pancam.customer.surface.ICatchISurfaceContext;
import com.icatchtek.pancam.customer.surface.ICatchSurfaceContext;
import com.icatchtek.pancam.customer.type.ICatchGLColor;
import com.icatchtek.pancam.customer.type.ICatchGLDisplayPPI;
import com.icatchtek.reliant.customer.exception.IchInvalidSessionException;
import com.icatchtek.reliant.customer.exception.IchTransportException;
import com.icatchtek.reliant.customer.transport.ICatchINETTransport;
import com.icatchtek.reliant.customer.transport.ICatchITransport;

import icatchtek.com.streamingalone.R;

public class SDKRenderActivity1 extends Activity
{
    private ICatchITransport transport;
    protected ICatchPancamSession pancamSession;

    private ICatchIPancamPreview preview;

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
            SurfaceView surfaceView = findViewById(R.id.surfaceView1);
            ICatchISurfaceContext surfaceContext = new ICatchSurfaceContext(surfaceView.getHolder().getSurface());
            boolean retVal = this.preview.enableRender(surfaceContext);
            if (!retVal) {
                System.exit(-1);
            }
        }
        catch(Exception ex)
        {
            ex.printStackTrace();
        }
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
}
