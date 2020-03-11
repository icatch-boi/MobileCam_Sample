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

#ifndef __ICATCH_GL_POINT_H__
#define __ICATCH_GL_POINT_H__

#include "WindowsApi.h"

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * Point
 */
class ICAT_API ICatchGLPoint
{
public:
    /**
     * Constructor.
     * @param x x value.
     * @param y y value.
     */
    ICatchGLPoint(float x, float y);

public:
    /**
     * Get x.
     * @return x value.
     */
    float getX();
    /**
     * Get y.
     * @return y value.
     */
    float getY();

private:
    float x;
    float y;
};

}}}

#endif

