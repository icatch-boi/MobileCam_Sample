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

#ifndef __ICATCH_I_PANCAM_GL_H__
#define __ICATCH_I_PANCAM_GL_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include <stdint.h>

#include "gl/ICatchIPancamGLTransform.h"
#include "surface/ICatchSurfaceContext.h"

using namespace com::icatchtek::pancam;

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * Used to show pancam image.
 */
class ICatchIPancamGL
{
public:
    virtual ~ICatchIPancamGL(){ };

public:
    /**
     * Get pancamGL transform
     *
     * @return PancamGLTransform();
     *
     * @throws IchDeprecatedException The instance is deprecated, You should get new one using ICatchIPancamRender.enableGLRender.
     */
    virtual int32_t getPancamGLTransform(shared_ptr<ICatchIPancamGLTransform>& pancamGLTransform) = 0;

    /**
     * Init the pancam object, You should specify panoramaType, currently we only support
     * type which called ICH_GL_PANORAMA_TYPE_SPHERE, the feature SPHERE_VR, SPHERE_SEMI will
     * coming soon.
     * @param panoramaType The panorama type.
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    virtual int32_t init() = 0;

    /**
     * Init the pancam object, You should specify panoramaType, currently we only support
     * type which called ICH_GL_PANORAMA_TYPE_SPHERE, the feature SPHERE_VR, SPHERE_SEMI will
     * coming soon.
     * @param panoramaType The panorama type.
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    virtual int32_t init(int32_t panoramaType) = 0;

    /**
     * Release the pancam object.
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    virtual int32_t release() = 0;

    /**
     * change panorama type
     * @param panoramaType The panorama type.
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    virtual int32_t changePanoramaType(int32_t panoramaType) = 0;

    /**
     * Set the SDK's inner picture format which used for rendering, This format must be
     * corresponded with the image or decoded stream format you specified when using
     * still image, doing preview or video playback.
     * In Android platform, The SDK will decode H.264 stream itself in order to get
     * better performance, so you do not need to call this method.
     * In IOS platform, you should decode the H.264 stream to YUV_I420 or NV12 since our
     * SDK just support these two YUV formats only.
     * @param format The SDK's inner picture format which used for rendering.
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    virtual int32_t setFormat(int32_t format, int32_t width, int32_t height) = 0;

    /**
     * Remove the format currently being used for rendering, Notice that once you clear
     * current format, The SDK will stop rendering until you call setFormat again.
     *
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    virtual int32_t clearFormat() = 0;

    /**
     * Set the surface context, which used to render panorama picture.
     * @param surfaceType The surface type.
     * @param surfaceContext The surface context.
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    virtual int32_t setSurface(int32_t surfaceType, shared_ptr<ICatchSurfaceContext> surfaceContext) = 0;

    /**
     * Remove the surface context which used to render panorama picture.
     * @param surfaceType The surface type.
     * @param surfaceContext The surface context.
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    virtual int32_t removeSurface(int32_t surfaceType, shared_ptr<ICatchSurfaceContext> surfaceContext) = 0;
};

}}}

#endif
