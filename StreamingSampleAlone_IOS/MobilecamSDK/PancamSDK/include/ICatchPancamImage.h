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

#ifndef __ICATCH_PANCAM_PANCAM_IMAGE_H__
#define __ICATCH_PANCAM_PANCAM_IMAGE_H__

#include <stdint.h>
#include "WindowsApi.h"

#include "type/ICatchGLImage.h"
#include "type/ICatchGLColor.h"
#include "type/ICatchGLDisplayPPI.h"
#include "surface/ICatchSurfaceContext.h"

#include "ICatchIPancamImage.h"

namespace com{ namespace icatchtek{ namespace pancam {
class ICatchPancamGL;
}}}

namespace com{ namespace icatchtek{ namespace pancam { namespace core {
class VrRenderControl;
}}}}

using namespace com::icatchtek::pancam;
using namespace com::icatchtek::pancam::core;

namespace com{ namespace icatchtek{ namespace pancam {

/**
 * The class to render panoramic image.
 */
class ICAT_API ICatchPancamImage : public ICatchIPancamImage
{
public:
    ICatchPancamImage(int32_t sessionID, shared_ptr<ICatchGLColor> defaultColor, shared_ptr<ICatchGLDisplayPPI> displayPPI);

public:
    int32_t enableRender(shared_ptr<ICatchSurfaceContext> surfaceContext);
    int32_t enableGLRender(shared_ptr<ICatchIPancamGL>& pancamGL);
    int32_t enableGLRender(shared_ptr<ICatchIPancamGL>& pancamGL, int32_t panoramaType);

    int32_t setFormat(int32_t format, int32_t imageW, int32_t imageH);

    int32_t update(shared_ptr<ICatchGLImage> image);
    int32_t update(shared_ptr<ICatchGLImage> image, float pitchValue);

    int32_t updateDepthInfo(shared_ptr<ICatchGLImage> depthImage);
    int32_t updateDepthInfo(
        shared_ptr<ICatchGLImage> depthImage, float distanceFactor, float linePosition);
    int32_t updateDepthInfo(
        shared_ptr<ICatchGLImage> depthImage, shared_ptr<ICatchGLImage> paletteImage, float distanceFactor, float linePosition);
    int32_t updateModelingInfo(shared_ptr<ICatchGLImage> coloeImage, shared_ptr<ICatchGLImage> depthImage);
    int32_t updateModelingInfo(shared_ptr<ICatchGLImage> colorImage, vector<shared_ptr<ICatchGLVertexInfo> > vertexInfos);

    int32_t drawRoiRegion(shared_ptr<ICatchRect> innerRect, shared_ptr<ICatchRect> outerRect);
    int32_t clearRoiRegion();

    int32_t clear();

private:
    shared_ptr<ICatchGLDisplayPPI> displayPPI;
    shared_ptr<ICatchSurfaceContext> surfaceContext;

private:
    int32_t panoramaType;

private:
    shared_ptr<ICatchPancamGL> pancamGL;
    shared_ptr<VrRenderControl> control;
};

}}}

#endif

