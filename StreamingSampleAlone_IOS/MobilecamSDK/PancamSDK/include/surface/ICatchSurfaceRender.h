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

#ifndef __ICATCH_PANCAM_GLES_RENDER_H__
#define __ICATCH_PANCAM_GLES_RENDER_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include <stdint.h>
#include "WindowsApi.h"

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

class ICAT_API ICatchSurfaceRender
{
public:
    virtual ~ICatchSurfaceRender() {}

public:
    virtual bool needSetup() = 0;
    virtual int32_t setup() = 0;
    virtual int32_t tearDown() = 0;

    virtual int32_t render(bool force) = 0;
    virtual int32_t needRender() = 0;

public:
    virtual int32_t setViewPort(int32_t x, int32_t y, int32_t width, int32_t height, bool force) = 0;
};

}}}

#endif

