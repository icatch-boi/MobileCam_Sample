package icatchtek.com.streamingalone.render.core;

import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.util.Log;

import com.icatchtek.reliant.customer.type.ICatchAudioFormat;
import com.icatchtek.reliant.customer.type.ICatchCodec;
import com.icatchtek.reliant.customer.type.ICatchFrameBuffer;

import icatchtek.com.streamingalone.render.AudioAppRender;

public class AppRenderPCMA implements AudioAppRender
{
    private AudioTrack track;
    private int        codec;

    public AppRenderPCMA() {

    }

    public void freeRender() {
        if (track != null) track.stop();
    }

    public void setFormat(ICatchAudioFormat audioFormat) {

        Log.i("render_pcma", "frequency: " + audioFormat.getFrequency());
        Log.i("render_pcma", "nchannels: " + audioFormat.getNChannels());
        Log.i("render_pcma", "sampleBits: " + audioFormat.getSampleBits());

        int frequency  = audioFormat.getFrequency();
        int nchannels  = audioFormat.getNChannels() == 2 ? AudioFormat.CHANNEL_IN_STEREO : AudioFormat.CHANNEL_IN_LEFT;
        int sampleBits = audioFormat.getSampleBits() == 16 ? AudioFormat.ENCODING_PCM_16BIT : AudioFormat.ENCODING_PCM_8BIT;

        int bufferSize = AudioTrack.getMinBufferSize(frequency, nchannels, sampleBits);

        Log.i("render_pcma", "frequency: " + frequency);
        Log.i("render_pcma", "nchannels: " + nchannels);
        Log.i("render_pcma", "sampleBits: " + sampleBits);

        this.codec = audioFormat.getCodec();
        this.track = new AudioTrack(AudioManager.STREAM_MUSIC, frequency, nchannels, sampleBits, bufferSize, AudioTrack.MODE_STREAM);
        this.track.play();
    }

    public boolean renderFrame(ICatchFrameBuffer frame) {

        Log.i("render_pcma", "codec: " + codec);
        if (codec != ICatchCodec.ICH_CODEC_PCM) {
            return false;
        }
        track.write(frame.getBuffer(), 0, frame.getFrameSize());
        Log.i("render_pcma", "put audio frame: " + frame.getPresentationTime());

        return true;
    }
}
