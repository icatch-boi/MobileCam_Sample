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

#ifndef __ICATCH_ERROR_H__
#define __ICATCH_ERROR_H__

namespace com{ namespace icatchtek{ namespace reliant{

typedef enum ICatchError
{
    ICH_SUCCEED                     = 0x00,

    /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
    /* Should not modify the error code */
    ICH_DEVICE_BUSY                 = -1,
    ICH_DEVICE_ERROR                = -2,

    ICH_NOT_SUPPORTED               = -3,
    ICH_NOT_IMPLEMENTED             = -4,
    ICH_PERMISSION_DENIED           = -5,

    ICH_TRY_AGAIN                   = -6,

    ICH_BUF_TOO_SMALL               = -7,
    ICH_OUT_OF_MEMORY               = -8,

    ICH_FILE_NOT_FOUND              = -9,
    ICH_PATH_NOT_FOUND              = -10,

    ICH_INVALID_SESSION             = -11,
    ICH_INVALID_ARGUMENT            = -12,

    ICH_SOCKET_ERROR                = -13,
    ICH_WIFI_DISCONNECTED           = -14,

    /* !!!!!!!!!!!!matches linux err no !!!!!!!!!!!!!!!!!!!! */
    ICH_ERROR_IO                    = -21,
    ICH_ERROR_ACCESS                = -22,

    ICH_ERROR_NO_DEVICE             = -23,
    ICH_ERROR_NOT_FOUND             = -24,
    ICH_ERROR_BUSY                  = -25,

    ICH_ERROR_TIMEOUT               = -26,
    ICH_ERROR_OVERFLOW              = -27,

    ICH_ERROR_PIPE                  = -28,
    ICH_ERROR_INTERRUPTED           = -29,

    ICH_ERROR_INVALID_DEVICE        = -30,
    ICH_ERROR_INVALID_MODE          = -31,
    /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

    /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
    ICH_CALLBACK_EXISTS             = -40,
    ICH_JNI_EXP                     = -41,

     /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
    ICH_NO_USB_INTERFACE            = -42,
    ICH_NO_USB_ENDPOINT             = -43,
    ICH_NO_USB_FRAME_INFO           = -44,
    ICH_NO_USB_STREAM               = -45,
    /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

    /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
    ICH_LISTENER_EXISTS             = -60,
    ICH_LISTENER_NOT_EXISTS         = -61,

    ICH_SEEK_FAILED                 = -71,
    ICH_PAUSE_FAILED                = -72,
    ICH_RESUME_FAILED               = -73,

    ICH_PB_MEM_FULL                 = -81,
    ICH_PB_CACHING                  = -82,
    ICH_PB_PLAY_END                 = -83,
    ICH_PB_STREAM_PAUSED            = -84,

    ICH_VIDEO_STREAM_CLOSED         = -90,
    ICH_AUDIO_STREAM_CLOSED         = -91,
    ICH_STREAM_NOT_RUNNING          = -92,
    ICH_STREAM_NOT_SUPPORT          = -93,

    /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
    ICH_SESSION_PASSWORD_ERR        = -100,
    ICH_PTP_INIT_FAILED             = -101,
    ICH_WAIT_TIME_OUT               = -102,
    ICH_PUBLISH_ALREADY_START       = -103,
    ICH_PUBLISH_ALREADY_STOP        = -104,
    /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

    ICH_MUXER_ALREADY_STARTED       = -110,
    ICH_MUXER_START_FAILED          = -111,
    ICH_MUXER_NOT_STARTED           = -112,
    ICH_MUXER_WAINTING_KEY_FRAME    = -113,

    ICH_OPEN_FAIL                   = -120,
	ICH_ERROR_NULL					= -121,

    /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */
    ICH_RESOURCE_NOT_READY          = -202,

    ICH_SESSION_EXISTS              = -203,
    ICH_SESSION_NOT_EXISTS          = -204,

    ICH_STREAM_PLAYING_ENDED        = -205,
    ICH_STREAM_ALREADY_STARTED      = -206,

    ICH_TRANSPORT_ERROR             = -207,

    /* -------------------------------- */
    /* opengl es error code (important) */
    ICH_RENDER_NOT_INIT                 = -210,
    ICH_RENDER_ALREADY_INIT             = -211,
    ICH_RENDER_NOT_STARTED              = -212,
    ICH_RENDER_ALREADY_STARTED          = -213,
    ICH_SURFACE_NOT_SET                 = -214,
    ICH_SURFACE_ALREADY_SET             = -215,
    ICH_FORMAT_NOT_SUPPORTED            = -216,
    ICH_FORMAT_NOT_SPECIFIED            = -217,
    ICH_PICTURE_NOT_SPECIFIED           = -218,
    ICH_SPHERE_TYPE_NOT_SUPPORTED       = -219,
    ICH_NOT_INIT                        = -220,
    ICH_ALREADY_INIT                    = -221,
    ICH_GL_RENDER_NEED_SETUP            = -222,
    ICH_GL_PICTURE_SIZE_NOT_SPECIFIED   = -223,
    /* opengl es error code (important) */
    /* -------------------------------- */

	ICH_USB_W_DEVICE_NOT_FOUND			= -230,
	ICH_USB_W_PLATFORM_NOT_READY		= -231,
	ICH_USB_W_CREATE_FGRAPH_FAILED		= -232,
	ICH_USB_W_ADD_FAILTER_FAILED		= -233,
	ICH_USB_W_REMOVE_FAILTER_FAILED		= -234,
	ICH_USB_W_GENERAL_UNKNOWN_ERROR		= -235,
	ICH_USB_W_DSHOW_BOJECT_FAILED		= -236,
	ICH_USB_W_FIND_STILL_PIN_FAILED		= -237,
	ICH_USB_W_FIND_INTERFACE_FAILED		= -238,
	ICH_USB_W_BUILD_FILTER_CHAIN_FAILED = -239,
	ICH_USB_W_CONNECT_TWO_PINS_FAILED	= -240,
	ICH_USB_W_RENDER_STREAM_FAILED		= -241,
	ICH_USB_W_TRIGGER_CAPTURE_IMAGE_FAILED = -242,
	ICH_USB_W_SEND_EXU_COMMAND_FAILED	= -243,
	ICH_USB_W_START_STREAM_FAILED		= -244,

    ICH_UNKNOWN_ERROR					= -0xFF,
} ICatchError;

/**---------------------------------------------------
 * check icatch value, return bool or icatch value
 */
#define STREAM_CHECK_RET_BOOL( ret )    \
do {                                    \
    if( ret != true ) {                 \
        ICATCH_API_OUT();               \
        return false;                   \
    }                                   \
} while( 0 );


}}}

#endif

