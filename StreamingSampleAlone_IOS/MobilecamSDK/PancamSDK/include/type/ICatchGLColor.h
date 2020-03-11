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

#ifndef __ICATCH_GL_COLOR_H__
#define __ICATCH_GL_COLOR_H__

#include "WindowsApi.h"

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * The color of the SDK.
 * Each r, b, b attribute should not be more than 255.
 */
class ICAT_API ICatchGLColor
{
private:
    float r;
    float g;
    float b;
    float a;

public:
    /**
     * Default constructor, black color.
     */
    ICatchGLColor();

    /**
     * The constructor with user specified r,g,b,a.
     * @param r red component.
     * @param g green component.
     * @param b blue component.
     * @param a alpha component.
     */
    ICatchGLColor(float r, float g, float b, float a);

    /** The copy constructor. */
    ICatchGLColor(const ICatchGLColor& color);

public:

    /**
     * Get the red component.
     * @return Red component.
     */
    float getR();

    /**
     * Set the red component.
     * @param r Red component.
     */
    void setR(float r);

    /**
     * Get the green component.
     * @return Green component.
     */
    float getG();

    /**
     * Set green component.
     * @param Green component.
     */
    void setG(float g);

    /**
     * Get blue component.
     * @return Blue component.
     */
    float getB();

    /**
     * Set blue component.
     * @param Blue component.
     */
    void setB(float b);

    /**
     * Get alpha component.
     * @return Alpha component.
     */
    float getA();

    /**
     * Set appha component.
     * @param Alpha component.
     */
    void setA(float a);

    /**
     * Get red color used by the SDK core.
     * @param Red component.
     */
    float getGLR();

    /**
     * Get red green used by the SDK core.
     * @param Green component.
     */
    float getGLG();

    /**
     * Get blue color used by the SDK core.
     * @param Bblue component.
     */
    float getGLB();

    /**
     * Get alpha color used by the SDK core.
     * @param Alpha component.
     */
    float getGLA();
};

const ICatchGLColor IGL_COLOR_BLACK(0, 0, 0, 0);
const ICatchGLColor IGL_COLOR_WHITE(255, 255, 255, 0);
const ICatchGLColor IGL_COLOR_RED(255, 0, 0, 0);
const ICatchGLColor IGL_COLOR_GREEN(0, 255, 0, 0);
const ICatchGLColor IGL_COLOR_BLUE(0, 0, 255, 0);

}}}

#endif

