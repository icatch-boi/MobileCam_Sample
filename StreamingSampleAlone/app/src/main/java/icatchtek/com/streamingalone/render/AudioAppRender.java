package icatchtek.com.streamingalone.render;

import com.icatchtek.reliant.customer.type.ICatchFrameBuffer;

public interface AudioAppRender
{
    boolean renderFrame(ICatchFrameBuffer frameBuffer);
    void freeRender();
}
