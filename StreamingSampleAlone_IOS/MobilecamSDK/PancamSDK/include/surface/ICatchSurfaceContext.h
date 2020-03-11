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

#ifndef __ICATCH_PANCAM_SURFACE_CONTEXT_H__
#define __ICATCH_PANCAM_SURFACE_CONTEXT_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include <memory>
#include <stdint.h>
#include "WindowsApi.h"
#include "surface/ICatchSurfaceRender.h"

using namespace std;
using namespace com::icatchtek::pancam;

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * interface of surface context.
 */
class ICAT_API ICatchSurfaceContext
{
public:
    ICatchSurfaceContext();
    virtual ~ICatchSurfaceContext();

public:
    virtual bool needSetup();

    /**
     * Set up surface context.
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    virtual int32_t setup();

    /**
     * Tear down surface context.
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    virtual int32_t tearDown();

    /**
     * Trigger the SDK to render. But the SDK will do not render if no necessary to do.
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    virtual int32_t render();

    /**
     * Trigger the SDK to render.
     * @param force Tells the SDK to do the render, Whether it is necessary or not.
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    virtual int32_t render(bool force);

    /**
     * Get the info about whether there is nessary to render or not.
     */
    virtual bool    needRender();

public:
    /**
     * Set the view port, the SDK will draw panoramic pictures in this region.
     * @param x The start x.
     * @param y The start y.
     * @param width the with.
     * @param height the height.
     * @return Return true if no error happened, otherwise return false.
     * @throws IchGLSurfaceNotSetException The surface not set, the surface context should be set to the SDK first.
     */
    virtual int32_t setViewPort(int32_t x, int32_t y, int32_t width, int32_t height);

    /**
     *  Set the view port, the SDK will draw panoramic pictures in this region.
     * @param x The start x.
     * @param y The start y.
     * @param width the with.
     * @param height the height.
     * @param force force to setViewPort or not.
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    virtual int32_t setViewPort(int32_t x, int32_t y, int32_t width, int32_t height, bool force);

public:

    /**
     * The method will be called by the SDK, please do not call this.
     */
    virtual void setRender(shared_ptr<ICatchSurfaceRender> surfaceRender);

protected:
    shared_ptr<ICatchSurfaceRender> surfaceRender;
};

}}}

#endif

