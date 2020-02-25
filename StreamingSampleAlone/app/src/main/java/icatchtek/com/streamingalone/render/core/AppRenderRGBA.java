package icatchtek.com.streamingalone.render.core;

import android.graphics.Bitmap;
import android.graphics.Bitmap.Config;
import android.graphics.Canvas;
import android.graphics.PixelFormat;
import android.graphics.Rect;
import android.view.SurfaceHolder;

import com.icatchtek.reliant.customer.type.ICatchFrameBuffer;

import java.nio.ByteBuffer;

import icatchtek.com.streamingalone.render.VideoAppRender;


public class AppRenderRGBA implements VideoAppRender
{
    private Rect drawRect;
    private SurfaceHolder surfaceHolder;

    private byte[] pixelBuf;
    private Bitmap bitmapPic;
    private ByteBuffer bitmapBuf;

    public AppRenderRGBA(SurfaceHolder surfaceHolder, Rect drawRect)
    {
        this.drawRect       = drawRect;
        this.surfaceHolder  = surfaceHolder;
        this.surfaceHolder.setFormat(PixelFormat.RGBA_8888);
    }

    public void freeRender() {

    }

    public void setFormat(int width, int height)
    {
        pixelBuf = new byte[width * height * 4];
        bitmapBuf = ByteBuffer.wrap(pixelBuf);

        bitmapPic = Bitmap.createBitmap(width, height, Config.ARGB_8888);
    }

    @Override
    public boolean renderFrame(ICatchFrameBuffer frameBuffer)
    {
        if (frameBuffer.getFrameSize() > pixelBuf.length) {
            return false;
        }

        System.arraycopy(frameBuffer.getBuffer(), 0, pixelBuf, 0, frameBuffer.getFrameSize());
        bitmapPic.copyPixelsFromBuffer(bitmapBuf);
        bitmapBuf.rewind();

        Canvas canvas = surfaceHolder.lockCanvas();
        if (canvas == null) { return false; }
        canvas.drawBitmap(bitmapPic, null, drawRect, null);
        surfaceHolder.unlockCanvasAndPost(canvas);

        return true;
    }
}
