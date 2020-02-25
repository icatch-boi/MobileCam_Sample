package icatchtek.com.streamingalone.render;

import com.icatchtek.reliant.customer.type.ICatchFrameBuffer;

public interface VideoAppRender
{
    boolean renderFrame(ICatchFrameBuffer frameBuffer);
    void freeRender();
}
