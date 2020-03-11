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

#ifndef __ICATCH_GL_IMAGE_H__
#define __ICATCH_GL_IMAGE_H__

#include <map>
#include <memory>
#include "type/ICatchGLImage.h"
#include "type/ICatchGLStablizationInfo.h"

#include "ICatchGLByteArray.h"

namespace com{ namespace icatchtek{ namespace pancam{

#define VR_RAW_IMAGE_KEY_A_RGB  0x01
#define VR_RAW_IMAGE_KEY_RGB_A  0x02
#define VR_RAW_IMAGE_KEY_DEPTH  0x03
#define VR_RAW_IMAGE_KEY_DEPTH_8BIT 0x04

#define VR_RAW_IMAGE_KEY_YUV_Y  0x11
#define VR_RAW_IMAGE_KEY_YUV_U  0x12
#define VR_RAW_IMAGE_KEY_YUV_V  0x13
#define VR_RAW_IMAGE_KEY_YUV_UV 0x14

class ICatchGLImage
{
public:
    ICatchGLImage();
    ICatchGLImage(int32_t format, int32_t imageW, int32_t imageH, bool deep);
    ICatchGLImage(int32_t format, int32_t imageW, int32_t imageH, int32_t bufferSize);

public:
    ~ICatchGLImage();

public:
    int32_t putData(uint8_t* buffer, int32_t dataSize);
    int32_t putData(int32_t key, uint8_t* buffer, int32_t dataSize);

public:
    int32_t getFormat();
    int32_t getImageW();
    int32_t getImageH();
    com::icatchtek::pancam::ICatchGLByteArray* getData(int32_t key);

public:
    void setImageTime(double imageTime);
    double getImageTime();

    void setStablizationInfo(com::icatchtek::pancam::ICatchGLStablizationInfo& stablizationInfo);
    com::icatchtek::pancam::ICatchGLStablizationInfo getStablizationInfo();

public:
    int32_t cloneTo(std::shared_ptr<com::icatchtek::pancam::ICatchGLImage> imageRaw);

private:
    int32_t init(int32_t format, int32_t imageW, int32_t imageH, bool deep);
    int32_t uninit();
    int32_t calculateDataSize(int32_t format, int32_t imageKey, int32_t imageW, int32_t imageH);

private:
    bool                        deep;
    int32_t                     format;
    int32_t                     imageW;
    int32_t                     imageH;
    double                      imageTime;

private:
    com::icatchtek::pancam::ICatchGLStablizationInfo stablizationInfo;
    std::map<int32_t, com::icatchtek::pancam::ICatchGLByteArray*> imageData;
};

}}}

#endif

