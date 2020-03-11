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

#ifndef __ICATCH_JPEG_STREAM_PARAM_H__
#define __ICATCH_JPEG_STREAM_PARAM_H__

#include <string>
#include <memory>
#include "WindowsApi.h"
#include "ICatchStreamParam.h"

using namespace std;
using namespace com::icatchtek::reliant;

namespace com{ namespace icatchtek{ namespace reliant{

class ICAT_API ICatchJPEGStreamParam : public ICatchStreamParam
{
public:
    ICatchJPEGStreamParam(int width = 640, int height = 360, int bitrate = 5000000, int frameRate = 30, int qSize = 50);
    virtual ~ICatchJPEGStreamParam();

public:
    int getCodec();
    int getWidth();
    int getHeight();
    int getBitRate();
    int getFrameRate();

public:
    string getCmdLineParam();

public:
    string toString();
    static shared_ptr<ICatchJPEGStreamParam> fromString(string attributes);

protected:
    int codec;
    int videoW;
    int videoH;
    int qSize;
    int bitRate;
    int frameRate;
};

}}}

#endif
