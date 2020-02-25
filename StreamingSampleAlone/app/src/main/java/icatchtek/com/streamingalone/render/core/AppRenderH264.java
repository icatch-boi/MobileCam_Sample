package icatchtek.com.streamingalone.render.core;

import android.media.MediaCodec;
import android.media.MediaCodec.BufferInfo;
import android.media.MediaFormat;
import android.util.Log;
import android.view.SurfaceHolder;

import com.icatchtek.reliant.customer.type.ICatchFrameBuffer;
import com.icatchtek.reliant.customer.type.ICatchVideoFormat;

import java.io.IOException;
import java.nio.ByteBuffer;

import icatchtek.com.streamingalone.render.VideoAppRender;

public class AppRenderH264 implements VideoAppRender
{
    private SurfaceHolder   surfaceHolder;

    private MediaCodec      decoder;

    private BufferInfo      output_info;
    private ByteBuffer[]    input_buffers;

    public AppRenderH264(SurfaceHolder surfaceHolder) {
        this.surfaceHolder    = surfaceHolder;
    }

     public void freeRender() {
        if (decoder != null) {
            decoder.stop();
            decoder.release();
        }
    }

    public void setFormat(ICatchVideoFormat videoFormat)
    {
        MediaFormat mediaFormat = MediaFormat.createVideoFormat(
                "video/avc",
                videoFormat.getVideoW(),
                videoFormat.getVideoH());

        Log.e("__render_h264__", "takes 0.2: " + videoFormat.getVideoW());
        Log.e("__render_h264__", "takes 0.2: " + videoFormat.getVideoH());

        try {
            this.decoder = MediaCodec.createDecoderByType("video/avc");
        } catch (IOException e) {
            e.printStackTrace();
            return;
        }
        this.decoder.configure(mediaFormat, this.surfaceHolder.getSurface(), null, 0);
        this.decoder.start();

        this.output_info    = new BufferInfo();
        this.input_buffers    = this.decoder.getInputBuffers();
        //this.output_buffers    = this.decoder.getOutputBuffers();

        Log.e("__render_h264__", "decode-----" + decoder.getCodecInfo().getName());
    }

    @Override
    public boolean renderFrame(ICatchFrameBuffer frameBuffer) {

        do {
            int input_buffer_index = decoder.dequeueInputBuffer(0);

            if (input_buffer_index >= 0) {

                ByteBuffer input_buffer = input_buffers[input_buffer_index];
                input_buffer.rewind();
                input_buffer.put(frameBuffer.getBuffer(), 0, frameBuffer.getFrameSize());

                long framePresentation = (long)(frameBuffer.getPresentationTime() * 1000 * 1000);
                decoder.queueInputBuffer(input_buffer_index, 0, frameBuffer.getFrameSize(), framePresentation, 0);

                dequeueAndRenderOutputBuffer(0);
                break;
            }
            else {

                Log.e("__render_h264__", "dequeue input buffer failed: " + input_buffer_index);


                /* because we could not get an valid input buffer index, so we dequeue output buffer to try
                 * to leave some space. This below comment comes from VLC(doc/ChangeLog-2014 line 15610):
                 * <<dequeueOutputBuffer should have an higher priority since releasing an output buffer
                 * often allows MediaCodec to make progress>>, "allows MediaCodec to make progress" this
                 * may be very important. */
                if (!dequeueAndRenderOutputBuffer(0) && !dequeueAndRenderOutputBuffer(30 * 1000)) {
                    Log.e("__render_h264__", "dequeue output buffer failed with timeout 0");
                    return false;
                }
            }
        } while (true);

        return true;
    }

    private boolean dequeueAndRenderOutputBuffer(int timeout) {

        Log.e("__render_h264__", "dequeue output buffer with timeout: " + timeout);

        int    output_buffer_index    = decoder.dequeueOutputBuffer(output_info, timeout);
        if (output_buffer_index == MediaCodec.INFO_OUTPUT_BUFFERS_CHANGED) {
            Log.e("__render_h264__", "INFO_OUTPUT_BUFFERS_CHANGED ");
            return false;
        }
        if (output_buffer_index == MediaCodec.INFO_OUTPUT_FORMAT_CHANGED) {
            updateFormat(decoder.getOutputFormat());
            Log.e("__render_h264__", "INFO_OUTPUT_FORMAT_CHANGED");
            return false;
        }
        if (output_buffer_index ==  MediaCodec.INFO_TRY_AGAIN_LATER) {
            Log.e("__render_h264__", "INFO_TRY_AGAIN_LATER: " + output_buffer_index);
            return false;
        }

        decoder.releaseOutputBuffer(output_buffer_index, true);
        Log.e("__render_h264__",  "data from " + output_info.offset + " to " + output_info.size);

        return true;
    }

    private void updateFormat(MediaFormat mediaFormat)
    {
        int videoW = mediaFormat.getInteger(MediaFormat.KEY_WIDTH);
        int videoH = mediaFormat.getInteger(MediaFormat.KEY_HEIGHT);

        int colorSpace = mediaFormat.getInteger(MediaFormat.KEY_COLOR_FORMAT);
        Log.i("__h264_decoder_lollop__", "videoW: " + videoW);
        Log.i("__h264_decoder_lollop__", "videoW: " + videoH);
        Log.i("__h264_decoder_lollop__", "output decode color format: " + colorSpace);
    }

}
