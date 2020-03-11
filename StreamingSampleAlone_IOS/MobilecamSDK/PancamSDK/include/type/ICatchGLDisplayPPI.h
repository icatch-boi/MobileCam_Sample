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

#ifndef __ICATCH_GL_DISPLAY_PPI_H__
#define __ICATCH_GL_DISPLAY_PPI_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include <stdint.h>
#include "WindowsApi.h"

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * Represents the display PPI of the screen.
 */
class ICAT_API ICatchGLDisplayPPI
{
public:
    /**
     * Default constructor, with xdpi 200.0f and y dpi 200.0f.
     */
    ICatchGLDisplayPPI();

    /**
     * Constructor, specify the x dpi and y dpi
     * @param xdpi x dpi.
     * @param ydpi y dpi.
     */
    ICatchGLDisplayPPI(float xdpi, float ydpi);

public:
    /**
     * Get x dpi.
     * @return x dpi.
     */
    float getXdpi();

    /**
     * Set x dpi.
     * @param xdpi x dpi.
     */
    void setXdpi(float xdpi);

    /**
     * Get y dpi.
     * @return y dpi.
     */
    float getYdpi();

    /**
     * Set y dpi.
     * @param ydpi y dpi.
     */
    void setYdpi(float ydpi);

private:
    float xdpi;
    float ydpi;
};

}}}

#endif

