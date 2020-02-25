package icatchtek.com.streamingalone.render;

import com.icatchtek.reliant.customer.type.ICatchFrameBuffer;

public interface VideoSDKRender
{
    boolean renderFrame(ICatchFrameBuffer frameBuffer);
    void freeRender();
}
