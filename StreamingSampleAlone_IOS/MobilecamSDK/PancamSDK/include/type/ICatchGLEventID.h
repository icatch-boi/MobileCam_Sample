/**************************************************************************
 *
 *         Copyright (c) 2014-2018 by iCatch Technology, Inc.
 *
 *  This software is copyrighted by and is the property of Sunplus
 *  Technology, Inc. All rights are reserved by Sunplus Technology, Inc.
 *  This software may only be used in accordance with the
 *  corresponding license agreement. Any unauthorized use, duplication,
 *  distribution, or disclosure of this software is expressly forbidden.
 *
 *  This Copyright notice MUST not be removed or modified without prior
 *  written consent of iCatch Technology, Inc.
 *
 *  iCatch Technology, Inc. reserves the right to modify this
 *  software without notice.
 *
 *  iCatch Technology, Inc.
 *  19-1, Innovation First Road, Science-Based Industrial Park,
 *  Hsin-Chu, Taiwan, R.O.C.
 *
 *  Author: peng.tan
 *  Email:  peng.tan@sunmedia.com.cn
 *
 **************************************************************************/

#ifndef __ICATCH_PANCAM_EVENT_ID__
#define __ICATCH_PANCAM_EVENT_ID__

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 *  The event provided by libStreaming.
 */
#define PHO_LIB_STREAMING_EVENT_SERVER_STREAM_ERROR             0x41
#define PHO_LIB_STREAMING_EVENT_REMOTE_STREAM_CLOSED            0x42

#define PHO_LIB_STREAMING_EVENT_VIDEO_STREAM_PLAYING_STATUS     0x43
#define PHO_LIB_STREAMING_EVENT_AUDIO_STREAM_PLAYING_STATUS     0x44

#define PHO_LIB_STREAMING_EVENT_VIDEO_STREAM_PLAYING_ENDED      0x45
#define PHO_LIB_STREAMING_EVENT_AUDIO_STREAM_PLAYING_ENDED      0x46

#define PHO_LIB_STREAMING_EVENT_VIDEO_PLAYBACK_CACHING_PROGRESS 0x47
#define PHO_LIB_STREAMING_EVENT_VIDEO_PLAYBACK_CACHING_CHANGED  0x48

#define PHO_LIB_STREAMING_EVENT_AUDIO_PLAYBACK_CACHING_PROGRESS 0x49
#define PHO_LIB_STREAMING_EVENT_AUDIO_PLAYBACK_CACHING_CHANGED  0x4A

#define PHO_LIB_STREAMING_EVENT_H264_FRAME_RANGE_DROPPED        0x4B

#define PHO_LIB_STREAMING_EVENT_TRANSPORT_VIDEO_STREAM_STATUS   0x4C
#define PHO_LIB_STREAMING_EVENT_TRANSPORT_AUDIO_STREAM_STATUS   0x4D
#define PHO_LIB_STREAMING_EVENT_VIDEO_STREAM_NO_EIS_INFORMATION 0x4E

#define PHO_LIB_STREAMING_EVENT_USB_FRAME_TRANSFER_FAILED       0x4F

#define PHO_LIB_LIVE_EVENT_NETWORK_DISCONNECT                   0x51

/**
 * The class of ICatch event ID.
 */
typedef enum ICatchGLEventID
{
    /**
     * The event ID of stream status, indicates decode interval or pts.<br>
     * IntValue1: decode(contains render) interval in million seconds between the current and previous. <br>
     * DoubleValue1: The current image's presentation time in seconds.
     */
    ICH_GL_EVENT_STREAM_STATUS     = 0x00,

    /** The event ID of stream closed. */
    //ICH_GL_EVENT_STREAM_CLOSED     = 0x01,
    ICH_GL_EVENT_STREAM_CLOSED                      = PHO_LIB_STREAMING_EVENT_REMOTE_STREAM_CLOSED,

    /**
     * The event ID of render status.
     * IntValue1: The time needed to do the render for current image.
     */
    ICH_GL_EVENT_RENDER_STATUS     = 0x10,

    /** The event ID of decoder status. */
    ICH_GL_EVENT_DECODER_STATUS    = 0x11,

    /**
     * The event ID of colorspace status. <br>
     * IntValue1: The time needed to do the color space convert in million seconds for current image.
     */
    ICH_GL_EVENT_COLORSPACE_STATUS = 0x12,

    ICH_GL_EVENT_FRAME_INTERVAL_INFO = 0x13,

    /**
       * Events comes from other modules.
       */
    ICH_GL_EVENT_SERVER_STREAM_ERROR                = PHO_LIB_STREAMING_EVENT_SERVER_STREAM_ERROR,

    /** Indicate video stream playing status */
    ICH_GL_EVENT_VIDEO_STREAM_PLAYING_STATUS        = PHO_LIB_STREAMING_EVENT_VIDEO_STREAM_PLAYING_STATUS,

    /** Indicate audio stream playing status */
    ICH_GL_EVENT_AUDIO_STREAM_PLAYING_STATUS        = PHO_LIB_STREAMING_EVENT_AUDIO_STREAM_PLAYING_STATUS,

    ICH_GL_EVENT_VIDEO_STREAM_PLAYING_ENDED         = PHO_LIB_STREAMING_EVENT_VIDEO_STREAM_PLAYING_ENDED,
    ICH_GL_EVENT_AUDIO_STREAM_PLAYING_ENDED         = PHO_LIB_STREAMING_EVENT_AUDIO_STREAM_PLAYING_ENDED,

    ICH_GL_EVENT_VIDEO_PLAYBACK_CACHING_PROGRESS    = PHO_LIB_STREAMING_EVENT_VIDEO_PLAYBACK_CACHING_PROGRESS,
    ICH_GL_EVENT_VIDEO_PLAYBACK_CACHING_CHANGED     = PHO_LIB_STREAMING_EVENT_VIDEO_PLAYBACK_CACHING_CHANGED,

    ICH_GL_EVENT_AUDIO_PLAYBACK_CACHING_PROGRESS    = PHO_LIB_STREAMING_EVENT_AUDIO_PLAYBACK_CACHING_PROGRESS,
    ICH_GL_EVENT_AUDIO_PLAYBACK_CACHING_CHANGED     = PHO_LIB_STREAMING_EVENT_AUDIO_PLAYBACK_CACHING_CHANGED,

    ICH_GL_EVENT_H264_FRAME_RANGE_DROPPED           = PHO_LIB_STREAMING_EVENT_H264_FRAME_RANGE_DROPPED,

    ICH_GL_EVENT_TRANSPORT_VIDEO_STREAM_STATUS      = PHO_LIB_STREAMING_EVENT_TRANSPORT_VIDEO_STREAM_STATUS,
    ICH_GL_EVENT_TRANSPORT_AUDIO_STREAM_STATUS      = PHO_LIB_STREAMING_EVENT_TRANSPORT_AUDIO_STREAM_STATUS,
    ICH_GL_EVENT_VIDEO_STREAM_NO_EIS_INFORMATION    = PHO_LIB_STREAMING_EVENT_VIDEO_STREAM_NO_EIS_INFORMATION,

    ICH_GL_EVENT_USB_FRAME_TRANSFER_FAILED          = PHO_LIB_STREAMING_EVENT_USB_FRAME_TRANSFER_FAILED,

    ICH_GL_EVENT_LIVE_NETWORK_DISCONNECT            = PHO_LIB_LIVE_EVENT_NETWORK_DISCONNECT,
    /**
     * Undefined or invalid eventID.
     */
    ICH_GL_EVENT_UNDEFINED                          = 0xFF,
} ICatchGLEventID;

}}}

#endif

