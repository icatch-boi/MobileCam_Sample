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

package icatchtek.com.streamingalone.ui;

import android.app.Activity;
import android.os.Bundle;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import com.icatchtek.pancam.customer.exception.IchGLSurfaceNotSetException;
import com.icatchtek.pancam.customer.surface.ICatchISurfaceContext;
import com.icatchtek.pancam.customer.surface.ICatchSurfaceContext;

import icatchtek.com.streamingalone.R;

public abstract class BaseSurfaceActivity extends Activity
{
    protected ICatchISurfaceContext surfaceContext;

    /**
     * The sub class should provide a layout file contains SurfaceView component named surfaceView1
     */
    protected abstract void setContentViewWhichHasSurfaceView1();
    /**
     * The surfaceView available notify, The SDK/App methods which needs this surface will work well now.
     */
    protected abstract void surfaceViewAvailableNotify();
    /**
     * The surfaceView unavailable notify, The SDK/App methods which needs this surface will not work well now.
     */
    protected abstract void surfaceViewUnavailableNotify();

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentViewWhichHasSurfaceView1();

        SurfaceView surfaceView = findViewById(R.id.surfaceView1);
        surfaceView.getHolder().addCallback(new SurfaceHolder.Callback() {
            @Override
            public void surfaceCreated(SurfaceHolder holder) {
                SurfaceView surfaceView = findViewById(R.id.surfaceView1);
                surfaceContext = new ICatchSurfaceContext(surfaceView.getHolder().getSurface());
                surfaceViewAvailableNotify();
            }

            @Override
            public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
                try {
                    surfaceContext.setViewPort(0, 0, width, height);
                } catch (IchGLSurfaceNotSetException e) {
                    e.printStackTrace();
                }
            }

            @Override
            public void surfaceDestroyed(SurfaceHolder holder) {
                surfaceViewUnavailableNotify();
            }
        });
    }
}
