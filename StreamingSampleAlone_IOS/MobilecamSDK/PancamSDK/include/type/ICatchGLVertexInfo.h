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

#ifndef __ICATCH_GL_VERTEX_INFO_H__
#define __ICATCH_GL_VERTEX_INFO_H__

#include <vector>
#include "WindowsApi.h"
#include "type/ICatchGLFloatArray.h"

using namespace std;
using namespace com::icatchtek::pancam;

namespace com{ namespace icatchtek{ namespace pancam{

class ICAT_API ICatchGLVertexInfo
{
public:
    ICatchGLVertexInfo(int32_t rows, int32_t cols, vector<float> vertexBuffer);
    ICatchGLVertexInfo(int32_t count, float* vertexBuffer, float* texcoordBuffer);
    ~ICatchGLVertexInfo();

public:
    int32_t getCount();
    float* getVertex();
    float* getTexcoord();

private:
    ICatchGLVertexInfo(const ICatchGLVertexInfo& vertexInfo);

private:
    int32_t count;
    ICatchGLFloatArray* vertex;
    ICatchGLFloatArray* texcoord;
};

}}}

#endif

