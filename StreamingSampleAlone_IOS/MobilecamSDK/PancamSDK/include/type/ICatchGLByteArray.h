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

#ifndef __ICATCH_GL_BYTE_ARRAY_H__
#define __ICATCH_GL_BYTE_ARRAY_H__

#include <stdint.h>

namespace com{ namespace icatchtek{ namespace pancam{ 

class ICatchGLByteArray
{
private:
    bool     deep;
    uint8_t* array;
    int32_t  dataLength;
    int32_t  arrayLength;

private:
    ICatchGLByteArray(const ICatchGLByteArray &floatArray);

public:
    ICatchGLByteArray(uint8_t* array, int32_t dataLength, int32_t arrayLength, bool deep);
    ~ICatchGLByteArray();

    int32_t putArray(uint8_t* array, int32_t dataLength);

    uint8_t* getArray();
    int32_t  getDataLength();
    int32_t  getArrayLength();
};

}}}

#endif

