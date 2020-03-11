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

#ifndef __ICATCH_I_PANCAM_GL_TRANSFORM_H__
#define __ICATCH_I_PANCAM_GL_TRANSFORM_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include <memory>
#include <stdint.h>
#include "type/ICatchGLPoint.h"

using namespace std;
using namespace com::icatchtek::pancam;

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * The pancamGL class, which contains methods to set or clear render format,
 * also contains methods to control the panoramic image shown on the surface.
 */
class ICatchIPancamGLTransform
{
public:
    virtual ~ICatchIPancamGLTransform(){ };

public:
    /**
     * Reset the rotate angle to the initial values.
     * This method does not reset the distance or scale factor.
     * @return Return true if no error occurred, otherwise return false.
     */
    virtual int32_t reset() = 0;

    /**
     * Set the distance between the camera and the point (0, 0, 0)
     * @param distance The distance.(&gt;= 0.0 &amp;&amp; &lt;= 5.0)
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    virtual int32_t locate(float distance) = 0;

    /**
     * Scale the panoramic image shown on the surface.
     * @param factor The scale factor of the near face's with &amp; height.(&gt;= 0.20 &amp;&amp; &lt;= 3.50)
     * @param distance The distance between the camera and the frustum. (&gt;= 0.10 &amp;&amp; &lt;= 0.90)
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    virtual int32_t scale(float factor) = 0;
    virtual int32_t scale(float factor, float distance) = 0;

    /**
     * Rotate the panoramic image shown on the surface. this method is often used with the gyro.
     * @param orientation The rotation of the screen, currently we support 0, 90, 180, 270 degrees.
     *                    The APP should use one of the macro which defined ICatchGLRotation.
     * @param speedX  The x angle speed of the gyro event
     * @param speedY  The y angle speed of the gyro event.
     * @param speedZ  The z angle speed of the gyro event.
     * @param timestamp The timestamp The time in nanosecond at which the gyro event happened.
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    virtual int32_t rotate(int32_t rotation, float speedX, float speedY, float speedZ, int64_t timestamp) = 0;

    /**
     * Rotate the panoramic image shown on the surface from the start point to the end point.
     * @param startPoint The start point of this movement.
     * @param endPoint The end point of this movement.
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    virtual int32_t rotate(shared_ptr<ICatchGLPoint> startPoint, shared_ptr<ICatchGLPoint> endPoint) = 0;

    virtual int32_t updateGyro(float speedX, float speedY, float speedZ, int64_t timestamp) = 0;
    virtual int32_t updateAccel(float speedX, float speedY, float speedZ, int64_t timestamp) = 0;
};

}}}

#endif
