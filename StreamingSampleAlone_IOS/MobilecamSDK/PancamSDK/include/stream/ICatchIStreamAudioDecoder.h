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

#ifndef __ICATCH_I_STREAM_AUDIO_DECODER_H__
#define __ICATCH_I_STREAM_AUDIO_DECODER_H__

#include "type/ICatchAudioFormat.h"
#include "type/ICatchFrameBuffer.h"

using namespace com::icatchtek::reliant;

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

class ICatchIStreamAudioDecoder
{
public:
    virtual ~ICatchIStreamAudioDecoder() { }

public:
    virtual bool prepareDecoder(ICatchAudioFormat& inputFormat, ICatchAudioFormat& outputFormat) = 0;
    virtual bool decodeNext(ICatchFrameBuffer* inputFrame, ICatchFrameBuffer* outputFrame) = 0;
    virtual bool destroyDecoder() = 0;
};

}}}

#endif