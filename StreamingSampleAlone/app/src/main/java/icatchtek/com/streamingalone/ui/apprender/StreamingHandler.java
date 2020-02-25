package icatchtek.com.streamingalone.ui.apprender;

import android.graphics.Rect;
import android.util.Log;
import android.view.SurfaceView;

import com.icatchtek.pancam.customer.stream.ICatchIStreamProvider;
import com.icatchtek.reliant.customer.exception.IchNotSupportedException;
import com.icatchtek.reliant.customer.exception.IchTryAgainException;
import com.icatchtek.reliant.customer.type.ICatchAudioFormat;
import com.icatchtek.reliant.customer.type.ICatchCodec;
import com.icatchtek.reliant.customer.type.ICatchFrameBuffer;
import com.icatchtek.reliant.customer.type.ICatchVideoFormat;

import icatchtek.com.streamingalone.render.core.AppRenderH264;
import icatchtek.com.streamingalone.render.core.AppRenderPCMA;
import icatchtek.com.streamingalone.render.core.AppRenderRGBA;
import icatchtek.com.streamingalone.render.AudioAppRender;
import icatchtek.com.streamingalone.render.VideoAppRender;

public class StreamingHandler
{
    private SurfaceView surfaceView;
    private ICatchIStreamProvider streamProvider;

    private boolean videoRun;
    private Thread videoThread;
    private VideoAppRender videoRender;

    private boolean audioRun;
    private Thread audioThread;
    private AudioAppRender audioRender;

    public StreamingHandler(ICatchIStreamProvider streamProvider)
    {
        this.videoRun = false;
        this.streamProvider = streamProvider;
    }

    public void setSurfaceView(SurfaceView surfaceView)
    {
        this.surfaceView = surfaceView;
    }

    public boolean start()
    {
        if (this.videoRun || this.audioRun) {
            return true;
        }

        try {
            if (this.streamProvider.containsVideoStream()) {
                ICatchVideoFormat videoFormat = this.streamProvider.getVideoFormat();
                if (videoFormat != null) {
                    if (videoFormat.getCodec() == ICatchCodec.ICH_CODEC_H264) {
                        AppRenderH264 renderH264 = new AppRenderH264(surfaceView.getHolder());
                        renderH264.setFormat(videoFormat);
                        this.videoRender = renderH264;
                    }
                    else if (videoFormat.getCodec() == ICatchCodec.ICH_CODEC_RGBA_8888) {
                        Rect drawRect = new Rect(0, 0, surfaceView.getWidth(), surfaceView.getHeight());
                        AppRenderRGBA renderRGBA = new AppRenderRGBA(surfaceView.getHolder(), drawRect);
                        renderRGBA.setFormat(videoFormat.getVideoW(), videoFormat.getVideoH());
                        this.videoRender = renderRGBA;
                    }
                    else {
                        /* For demo purposes, we only support two video formats. */
                        throw new IchNotSupportedException("Codec: " + videoFormat.getCodec() + " not supported now");
                    }

                    this.videoRun = true;
                    this.videoThread = new videoRenderThread();
                    this.videoThread.start();
                }
            }
            else {
                Log.i("__app_render__", "No video stream found");
            }
        }
        catch (Exception ex) {
            Log.i("__app_render__", "-----------------------------3");
            ex.printStackTrace();
        }

        try {
            if (this.streamProvider.containsAudioStream()) {
                ICatchAudioFormat audioFormat = this.streamProvider.getAudioFormat();
                if (audioFormat != null) {
                    if (audioFormat.getCodec() == ICatchCodec.ICH_CODEC_PCM) {
                        AppRenderPCMA renderPCMA = new AppRenderPCMA();
                        renderPCMA.setFormat(audioFormat);
                        this.audioRender = renderPCMA;
                    }
                    this.audioRun = true;
                    if (this.audioRender != null) {
                        this.audioThread = new AudioRenderThread();
                        this.audioThread.start();
                    }
                }
            }
            else {
                Log.i("__app_render__", "No audio stream found");
            }
        }
        catch (Exception ex) {
            ex.printStackTrace();
        }
        Log.i("__app_render__", "-----------------------------Z");
        return true;
    }

    public boolean stop()
    {
        Log.i("__app_render__", "-----------------------------B");
        if (!this.videoRun && !this.audioRun) {
            return true;
        }

        Log.i("__app_render__", "-----------------------------C");
        this.videoRun = false;
        if (this.videoThread != null) {
            try {
                this.videoThread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        this.audioRun = false;
        if (this.audioThread != null) {
            try {
                this.audioThread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        if (this.videoRender != null) {
            this.videoRender.freeRender();
        }

        if (this.audioRender != null) {
            this.audioRender.freeRender();
        }

        return true;
    }

    private class videoRenderThread extends Thread
    {
        @Override
        public void run()
        {
            ICatchFrameBuffer frameBuffer = new ICatchFrameBuffer(2880 * 1440 * 4);

            Log.i("__app_render_video__", "do rendering");
            while (videoRun) {

                Log.i("__app_render_video__", "get next Frame");
                boolean retVal = false;
                try {
                    retVal = streamProvider.getNextVideoFrame(frameBuffer);
                } catch (IchTryAgainException e) {
                    e.printStackTrace();
                    continue;
                } catch (Exception e) {
                    e.printStackTrace();
                    break;
                }
                if (!retVal || frameBuffer.getFrameSize() <= 0) {
                    Log.i("__app_render_video__", "failed, frameSize: " + frameBuffer.getFrameSize());
                    break;
                }

                Log.i("__app_render_video__", "try to render, frameSize: " + frameBuffer.getFrameSize());
                videoRender.renderFrame(frameBuffer);
            }
            Log.i("__app_render_video__", "quit render thread");
        }
    }

    private class AudioRenderThread extends Thread {

        @Override
        public void run() {

            ICatchFrameBuffer frameBuffer = new ICatchFrameBuffer(10240);

            Log.i("__app_render_pcma__", "do rendering");
            while (videoRun) {

                Log.i("__app_render_pcma__", "get next Frame");
                boolean retVal = false;
                try {
                    retVal = streamProvider.getNextAudioFrame(frameBuffer);
                } catch (IchTryAgainException e) {
                    e.printStackTrace();
                    continue;
                } catch (Exception e) {
                    e.printStackTrace();
                    break;
                }

                if (!retVal || frameBuffer.getFrameSize() <= 0) {
                    try {
                        Thread.sleep(5);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    Log.i("__app_render_pcma__", "break, frameSize: " + frameBuffer.getFrameSize());
                    break;
                }

                Log.i("__app_render_pcma__", "try to render, frameSize: " + frameBuffer.getFrameSize());
                audioRender.renderFrame(frameBuffer);
            }
            Log.i("__app_render_pcma__", "quit render thread");
        }
    }
}
