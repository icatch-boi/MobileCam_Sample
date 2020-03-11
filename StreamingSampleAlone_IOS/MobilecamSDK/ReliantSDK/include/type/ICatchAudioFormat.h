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

#ifndef __ICATCH_AUDIO_FORMAT_H__
#define __ICATCH_AUDIO_FORMAT_H__

#include <string>
#include <memory>
#include <string.h>
#include "WindowsApi.h"

using namespace std;

namespace com{ namespace icatchtek{ namespace reliant{

#define DEFAULT_AUDIO_STREAM_NO   0

class ICAT_API ICatchAudioFormat
{
public:
    ICatchAudioFormat();
    ICatchAudioFormat(const ICatchAudioFormat& another);

    int getCodec();
    void setCodec(int codec);

    int getFrequency();
    void setFrequency(int frequency);

    int getSampleBits();
    void setSampleBits(int sampleBits);

    int getNChannels();
    void setNChannels(int nChannels);

public:
    shared_ptr<ICatchAudioFormat> clone();

public:
    string toString();
    static bool fromString(ICatchAudioFormat& audioFromat, string attributes);

private:
    int codec;
    int frequency;
    int nChannels;
    int sampleBits;
};

}}}

#endif

