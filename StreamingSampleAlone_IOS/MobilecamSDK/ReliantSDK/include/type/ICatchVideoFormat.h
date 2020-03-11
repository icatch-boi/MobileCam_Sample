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

#ifndef __ICATCH_VIDEO_FORMAT_H__
#define __ICATCH_VIDEO_FORMAT_H__

#include <string>
#include <memory>
#include "WindowsApi.h"

using namespace std;

namespace com{ namespace icatchtek{ namespace reliant{

#define MAX_MEDIA_ATTR_SIZE 255
#define DEFAULT_VIDEO_STREAM_NO   0

typedef enum ICatchStreamType
{
    ICH_STREAM_TYPE_AUDIO           = 0x01,
    ICH_STREAM_TYPE_VIDEO           = 0x02,
    ICH_STREAM_TYPE_VIDEO_COLOR     = 0x03,
    ICH_STREAM_TYPE_VIDEO_IR        = 0x04,
    ICH_STREAM_TYPE_VIDEO_DEPTH     = 0x05,
    ICH_STREAM_TYPE_UNKNOWN         = 0xFF,
} ICatchStreamType;

class ICAT_API ICatchVideoFormat
{
public:
    ICatchVideoFormat();
    ICatchVideoFormat(const ICatchVideoFormat& another);
    ICatchVideoFormat(unsigned int value, unsigned int value2 = 0);

    ~ICatchVideoFormat();

    int getStreamNo();
    void setStreamNo(int streamNo);

    int getStreamType();
    void setStreamType(int streamType);

    string getCodecName();
    void setCodecName(string codecName);

    string getMediumName();
    void setMediumName(string mediumName);

    int getCodec();
    void setCodec(int codec);

    int getVideoW();
    void setVideoW(int videoW);

    int getVideoH();
    void setVideoH(int videoH);

    unsigned int getBitrate();
    void setBitrate( unsigned int bitrate );

    void setFrameRate(unsigned int frameRate);
    unsigned int getFrameRate();

    int getDurationUs();
    void setDurationUs(int durationUs);

    int getMaxInputSize();
    void setMaxInputSize(int maxInputSize);

    int getCsd_0_size();
    const unsigned char* getCsd_0();
    int setCsd_0(const unsigned char* csd_0, int dataSize);

    int getCsd_1_size();
    const unsigned char* getCsd_1();
    int setCsd_1(const unsigned char* csd_1, int dataSize);

    int getCsd_2_size();
    const unsigned char* getCsd_2();
    int setCsd_2(const unsigned char* csd_1, int dataSize);

public:
    shared_ptr<ICatchVideoFormat> clone();
    void cloneTo(shared_ptr<ICatchVideoFormat> videoFormat);

public:
    string toString();
    static bool fromString(ICatchVideoFormat& videoFormat, string attributes);

private:
    int streamNo;
    int streamType;

    string codecName;
    string mediumName;

    int codec;

    int videoW;
    int videoH;

    unsigned int bitrate;
    unsigned int frameRate;

    int durationUs;
    int maxInputSize;

    int csd_0_size;
    int csd_1_size;
    int csd_2_size;

    unsigned char csd_0[MAX_MEDIA_ATTR_SIZE];
    unsigned char csd_1[MAX_MEDIA_ATTR_SIZE];
    unsigned char csd_2[MAX_MEDIA_ATTR_SIZE];
};

}}}

#endif
