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

#ifndef __ICATCH_I_PANCAM_IMAGE_H__
#define __ICATCH_I_PANCAM_IMAGE_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include <memory>

#include "WindowsApi.h"
#include "type/ICatchRect.h"
#include "type/ICatchGLImage.h"
#include "type/ICatchGLVertexInfo.h"

#include "gl/ICatchIPancamGL.h"

using namespace std;
using namespace com::icatchtek::reliant;

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * The interface to render panoramic image.
 */
class ICAT_API ICatchIPancamImage
{
public:
    virtual ~ICatchIPancamImage() { };

public:

    /**
     * Enable render.
     *
     * @return Return true if no error occurred, otherwise return false.
     */
    virtual int32_t enableRender(shared_ptr<ICatchSurfaceContext> surfaceContext) = 0;

    /**
     * Enable GL render.
     *
     * @return Return true if no error occurred, otherwise return false.
     */
    virtual int32_t enableGLRender(shared_ptr<ICatchIPancamGL>& pancamGL) = 0;

    /**
     * Enable GL render.
     *
     * @return Return true if no error occurred, otherwise return false.
     */
    virtual int32_t enableGLRender(shared_ptr<ICatchIPancamGL>& pancamGL, int32_t panoramaType) = 0;

    virtual int32_t setFormat(int32_t format, int32_t imageW, int32_t imageH) = 0;

    /**
     * Specify an panoramic image which will be rendered to the surface.
     *
     * @param image The panoramic image.
     *
     * @return Return true if no error occurred, otherwise return false.
     * @throws IchInvalidArgumentException Indicates wrong parameter.
     */
    virtual int32_t update(shared_ptr<ICatchGLImage> image) = 0;
    virtual int32_t update(shared_ptr<ICatchGLImage> image, float pitchValue) = 0;

    virtual int32_t updateDepthInfo(shared_ptr<ICatchGLImage> depthImage) = 0;
    virtual int32_t updateDepthInfo(shared_ptr<ICatchGLImage> depthImage, float distanceFactor, float linePositionY) = 0;
    virtual int32_t updateDepthInfo(shared_ptr<ICatchGLImage> depthImage, shared_ptr<ICatchGLImage> paletteImage, float distanceFactor, float linePositionY) = 0;
    virtual int32_t updateModelingInfo(shared_ptr<ICatchGLImage> coloeImage, shared_ptr<ICatchGLImage> depthImage) = 0;
    virtual int32_t updateModelingInfo(shared_ptr<ICatchGLImage> colorImage, vector<shared_ptr<ICatchGLVertexInfo> > vertexInfos) = 0;

    virtual int32_t drawRoiRegion(shared_ptr<ICatchRect> innerRect, shared_ptr<ICatchRect> outerRect) = 0;
    virtual int32_t clearRoiRegion() = 0;

    /**
     * Clear previous panoramic image, This will let the SDK to draw surface with default color.
     * The default color will be the color you specified in the ICatchPancamSession's prepareSession
     * method.
     *
     * @return Return true if no error occurred, otherwise return false.
     */
    virtual int32_t clear() = 0;
};

}}}

#endif

