package icatchtek.com.streamingalone.ui.sdkrenderoverusb.usb;

public class MainActivityAttributes
{
    public static final int USB_TYPE_ISO                        = 0;
    public static final int USB_TYPE_BULK                       = 1;
    public static final int USB_TYPE_SCSI                       = 2;
    public static final int USB_TYPE_NONE                       = 3;

    public static final String USB_TYPE_ISO_KEY                 = "USB ISO"; // see the defines in res.values.array.spingarr_usb_type
    public static final String USB_TYPE_BULK_KEY                = "USB BULK";// see the defines in res.values.array.spingarr_usb_type
    public static final String USB_TYPE_SCSI_KEY                = "USB SCSI";// see the defines in res.values.array.spingarr_usb_type
    public static final String USB_TYPE_NONE_KEY                = "USB NONE";// see the defines in res.values.array.spingarr_usb_type

    //----------------------------------------------------------------------------------------------
    /* Render type definitions. */
    //----------------------------------------------------------------------------------------------
    public static final int RENDER_TYPE_NO                      = 0x01;
    public static final int RENDER_TYPE_GL                      = 0x02;
    public static final int RENDER_TYPE_NORMAL                  = 0x03;

    public static final String RENDER_TYPE_NO_KEY               = "RENDER_TYPE_NO";
    public static final String RENDER_TYPE_GL_KEY               = "RENDER_TYPE_GL";
    public static final String RENDER_TYPE_NORMAL_KEY           = "RENDER_TYPE_NORMAL";

    //----------------------------------------------------------------------------------------------
    /* Panorama type definitions. */
    //----------------------------------------------------------------------------------------------
    public static final int PANORAMA_TYPE_FISH_EYE              = 0x00;
    public static final int PANORAMA_TYPE_SPHERE                = 0x01;
    public static final int PANORAMA_TYPE_PERSPECTIVE           = 0x01;
    public static final int PANORAMA_TYPE_SPHERE_SEMI           = 0x02;
    public static final int PANORAMA_TYPE_CRYSTAL_BALL          = 0x03;
    public static final int PANORAMA_TYPE_ASTEROID              = 0x04;
    public static final int PANORAMA_TYPE_NORMAL                = 0x05;
    public static final int PANORAMA_TYPE_VIRTUAL_R             = 0x06;
    public static final int PANORAMA_TYPE_REJECTED              = 0xFF;

    public static final String PANORAMA_TYPE_FISH_EYE_KEY       = "PANORAMA_TYPE_FISH_EYE";
    public static final String PANORAMA_TYPE_SPHERE_KEY         = "PANORAMA_TYPE_SPHERE";
    public static final String PANORAMA_TYPE_PERSPECTIVE_KEY    = "PANORAMA_TYPE_PERSPECTIVE";
    public static final String PANORAMA_TYPE_SPHERE_SEMI_KEY    = "PANORAMA_TYPE_SPHERE_SEMI";
    public static final String PANORAMA_TYPE_CRYSTAL_BALL_KEY   = "PANORAMA_TYPE_CRYSTAL_BALL";
    public static final String PANORAMA_TYPE_ASTEROID_KEY       = "PANORAMA_TYPE_ASTEROID";
    public static final String PANORAMA_TYPE_NORMAL_KEY         = "PANORAMA_TYPE_NORMAL";
    public static final String PANORAMA_TYPE_VIRTUAL_R_KEY      = "PANORAMA_TYPE_VIRTUAL_R";
}
