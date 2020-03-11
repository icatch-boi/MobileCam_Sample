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

#ifndef __ICATCH_CODEC_H__
#define __ICATCH_CODEC_H__

namespace com{ namespace icatchtek{ namespace reliant{

/**
 * Pancam codec definitions.
 */
typedef enum ICatchCodec
{
    /** qcelp */
    ICH_CODEC_QCELP             = 0x01,
    /** amr */
    ICH_CODEC_AMR               = 0x02,
    /** amr wb */
    ICH_CODEC_AMR_WB            = 0x03,
    /** mpa */
    ICH_CODEC_MPA               = 0x04,
    /** mpa_robust */
    ICH_CODEC_MPA_ROBUST        = 0x05,
    /** x mp3 draft 00 */
    ICH_CODEC_X_MP3_DRAFT_00    = 0x06,
    /** mp4a latm */
    ICH_CODEC_MP4A_LATM         = 0x07,
    /** vorbis */
    ICH_CODEC_VORBIS            = 0x08,
    /** vp8 */
    ICH_CODEC_VP8               = 0x09,
    /** ac3 */
    ICH_CODEC_AC3               = 0x10,
    /** eac3 */
    ICH_CODEC_EAC3              = 0x21,
    /** mp4v es */
    ICH_CODEC_MP4V_ES           = 0x22,
    /** mpeg4 generic */
    ICH_CODEC_MPEG4_GENERIC     = 0x23,
    /** mpv */
    ICH_CODEC_MPV               = 0x24,
    /** mpv */
    ICH_CODEC_MP2T              = 0x25,
    /** mp2t */
    ICH_CODEC_H261              = 0x26,
    /** h263 1998 */
    ICH_CODEC_H263_1998         = 0x27,
    /** h263 2000 */
    ICH_CODEC_H263_2000         = 0x28,
    /** h264 */
    ICH_CODEC_H264              = 0x29,
    /** dv */
    ICH_CODEC_DV                = 0x30,
    /** h265 */
    ICH_CODEC_HEVC              = 0x31,
    /** jpeg */
    ICH_CODEC_JPEG              = 0x40,
    /** x qt */
    ICH_CODEC_X_QT              = 0x41,
    /** x qt quicktime */
    ICH_CODEC_X_QT_QUICKTIME    = 0x42,
    /** pcmu */
    ICH_CODEC_PCMU              = 0x43,
    /** gsm */
    ICH_CODEC_GSM               = 0x44,
    /** dvi4 */
    ICH_CODEC_DVI4              = 0x45,
    /** pcma */
    ICH_CODEC_PCMA              = 0x46,
    /** mp1s */
    ICH_CODEC_MP1S              = 0x47,
    /** mp2p */
    ICH_CODEC_MP2P              = 0x48,
    /** l8 */
    ICH_CODEC_L8                = 0x49,
    /** l16, usually used by SDK */
    ICH_CODEC_L16               = 0x50,
    /** l20 */
    ICH_CODEC_L20               = 0x60,
    /** l24 */
    ICH_CODEC_L24               = 0x61,
    /** g726 16 */
    ICH_CODEC_G726_16           = 0x62,
    /** mpv */
    ICH_CODEC_G726_24           = 0x63,
    /** g726 24 */
    ICH_CODEC_G726_32           = 0x64,
    /** g726 32 */
    ICH_CODEC_G726_40           = 0x65,
    /** g726 40 */
    ICH_CODEC_SPEEX             = 0x66,
    /** speex */
    ICH_CODEC_ILBC              = 0x67,
    /** ilbc */
    ICH_CODEC_OPUS              = 0x68,
    /** t140 */
    ICH_CODEC_T140              = 0x69,
    /** dat12 */
    ICH_CODEC_DAT12             = 0x70,
    /** vnd onvif metadata */
    ICH_CODEC_VND_ONVIF_METADATA= 0x81,
    /** BITMAP */
    ICH_CODEC_BITMAP            = 0x82,

    /** BITMAP */
    ICH_CODEC_PCM               = 0x90,
    /** RGB565 */
    ICH_CODEC_RGB565            = 0x91,
    /** RGB888 */
    ICH_CODEC_RGB888            = 0x92,
    /** BRG888 */
    ICH_CODEC_BGR888            = 0x93,
    /** ARGB_8888 */
    ICH_CODEC_ARGB_8888         = 0x94,
    /** RGBA_8888 */
    ICH_CODEC_RGBA_8888         = 0x95,
    /** I420 */
    ICH_CODEC_YUV_I420          = 0x96,
    /** NV12 */
    ICH_CODEC_YUV_NV12          = 0x97,
    /** NV16 */
    ICH_CODEC_YUV_NV16          = 0x98,
    /** DEPTH 16 bit */
    ICH_CODEC_DEPTH_16BIT       = 0x99,
    /** IR NV16 */
    ICH_CODEC_YUV_IR_NV16       = 0x9A,
    /** COLOR NV16 */
    ICH_CODEC_YUV_COLOR_NV16    = 0x9B,
    /** IR 8BIT */
    ICH_CODEC_IRAD_8_BIT        = 0x9C,

	/** General codecs, the app should use this  */
    ICH_CODEC_DEPTH				= 0xA0,
    ICH_CODEC_IR				= 0xA1,
    ICH_CODEC_COLOR				= 0xA2,
    ICH_CODEC_DEPTH_IR          = 0xA3,
    ICH_CODEC_DEPTH_COLOR       = 0xA4,
    ICH_CODEC_DEPTH_IR_COLOR    = 0xA5,

    ICH_CODEC_AST_RGBL_RGBR     = 0xA6,
    ICH_CODEC_AST_IRADL_IRADR   = 0xA7,
    ICH_CODEC_AST_DEPTH_16BIT   = 0xA8,
    ICH_CODEC_AST_RGBL_RGBR_DEPTH = 0xA9,

    /** DEPTH Ethernet codecs */
    ICH_CODEC_DEPTH_COMPRESSED  = 0xB0,
    ICH_CODEC_IR_H264           = 0xB1,
    ICH_CODEC_COLOR_H264        = 0xB2,
    ICH_CODEC_DEPTH_IR_H264     = 0xB3,
    ICH_CODEC_DEPTH_IR_I420     = 0xB4,
    ICH_CODEC_DEPTH_IR_NV16     = 0xB5,
    ICH_CODEC_DEPTH_COLOR_H264  = 0xB6,
    ICH_CODEC_DEPTH_COLOR_I420  = 0xB7,
    ICH_CODEC_DEPTH_COLOR_NV16  = 0xB8,
    ICH_CODEC_DEPTH_IR_COLOR_NV16  = 0xB9,
    ICH_CODEC_DEPTH_IR_COLOR_I420  = 0xBA,

    /** undefined codec id */
    ICH_CODEC_UNKNOWN           = 0xFF
} ICatchCodec;

}}}

#endif
