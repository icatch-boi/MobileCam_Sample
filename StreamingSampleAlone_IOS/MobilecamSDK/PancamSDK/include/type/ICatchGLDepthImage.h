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

#ifndef __ICATCH_GL_DEPTH_IMAGE_H__
#define __ICATCH_GL_DEPTH_IMAGE_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include <stdint.h>
#include "type/ICatchGLImage.h"

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

typedef enum ICatchGLDepthPaintType {
    ICH_GL_DEPTH_PAINT_TYPE_NONE,
    ICH_GL_DEPTH_PAINT_TYPE_GRAY,
    ICH_GL_DEPTH_PAINT_TYPE_HEAT_MAP,
} ICatchGLPaintOutputType;

/**
 * Represents an depth image used by SDK.
 */
class ICatchGLDepthImage : public ICatchGLImage
{
public:
    ICatchGLDepthImage();
    ICatchGLDepthImage(int32_t paintType);

public:
    int32_t getPaintType();
    void setPaintType(int32_t paintType);

private:
    int32_t paintType;
};

}}}

#endif

