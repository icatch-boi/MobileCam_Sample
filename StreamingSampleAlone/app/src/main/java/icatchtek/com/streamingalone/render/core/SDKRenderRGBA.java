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

package icatchtek.com.streamingalone.render.core;

import com.icatchtek.pancam.customer.ICatchIPancamImage;
import com.icatchtek.pancam.customer.surface.ICatchISurfaceContext;
import com.icatchtek.pancam.customer.type.ICatchGLImageRaw;
import com.icatchtek.reliant.customer.exception.IchInvalidArgumentException;
import com.icatchtek.reliant.customer.type.ICatchCodec;
import com.icatchtek.reliant.customer.type.ICatchFrameBuffer;

import icatchtek.com.streamingalone.render.VideoSDKRender;

public class SDKRenderRGBA implements VideoSDKRender
{
    private int width;
    private int height;

    private ICatchISurfaceContext surfaceContext;
    private ICatchIPancamImage pancamImage;

    public SDKRenderRGBA(ICatchISurfaceContext surfaceContext, ICatchIPancamImage pancamImage)
    {
        this.surfaceContext = surfaceContext;
        this.pancamImage = pancamImage;
    }

    public void freeRender()
    {
        this.pancamImage.clear();
    }

    public boolean setFormat(int codec, int width, int height)
    {
        if (codec != ICatchCodec.ICH_CODEC_RGBA_8888) {
            /* For demo purposes, we only support rgba 8888 */
            return false;
        }
        try {
            this.pancamImage.enableRender(surfaceContext);
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }

        this.width = width;
        this.height = height;
        return true;
    }

    public boolean renderFrame(ICatchFrameBuffer frameBuffer)
    {
        try {
            ICatchGLImageRaw image = new ICatchGLImageRaw(ICatchCodec.ICH_CODEC_RGBA_8888, width, height, frameBuffer.getBuffer());
            this.pancamImage.update(image);
        } catch (IchInvalidArgumentException e) {
            e.printStackTrace();
            return false;
        }
        return true;
    }
}
