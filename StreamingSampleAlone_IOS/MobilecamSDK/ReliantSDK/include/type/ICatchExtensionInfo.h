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

#ifndef __ICATCH_EXTENSION_INFO_H__
#define __ICATCH_EXTENSION_INFO_H__

#include <string>
#include <stdint.h>
#include "WindowsApi.h"

namespace com{ namespace icatchtek{ namespace reliant{

typedef enum ICatchExtensionDirection {
    ICH_EXTENSION_DIR_IN, 
    ICH_EXTENSION_DIR_OUT
} ICatchExtensionDirection;

/**
 * The class of Extension command info(bean) file, should be implement.
 * Not implemented now. So not available for API.
 */
class ICAT_API ICatchExtensionInfo
{
public:
    ICatchExtensionInfo();
    ICatchExtensionInfo(int bufferSize);
    ICatchExtensionInfo(uint8_t* buffer, int bufferSize);
    ICatchExtensionInfo(const ICatchExtensionInfo& info);

public:
    virtual ~ICatchExtensionInfo();

public:
    int getInfoID();
    void setInfoID(int infoID);

    int getDirection();
    void setDirection(int direction);

    uint8_t* getBuffer();
    int getBufferSize();
    int getDataSize();
    void setDataSize(int dataSize);

    uint8_t* getSpecialParam();
    int getSpecialParamSize();

    int setSpecialParam(uint8_t* specialParam, int paramSize);

public:
    std::string toString();

private:
    int         innerAlloc;

    int         infoID;
    int         direction;

private:
    uint8_t*    buffer;
    int         bufferSize;
    int         dataSize;

private:
    uint8_t*    specialParam;
    int         specialParamSize;
};

}}}

#endif
