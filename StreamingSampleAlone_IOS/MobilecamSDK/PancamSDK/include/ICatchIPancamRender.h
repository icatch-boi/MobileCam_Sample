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

#ifndef __ICATCH_I_PANCAM_RENDER_H__
#define __ICATCH_I_PANCAM_RENDER_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include <stdint.h>
#include "gl/ICatchIPancamGL.h"
#include "stream/ICatchIStreamProvider.h"
#include "stream/ICatchIStreamVideoDecoder.h"
#include "stream/ICatchIStreamAudioDecoder.h"
#include "surface/ICatchSurfaceContext.h"

using namespace com::icatchtek::pancam;

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * The interface provides methods to set render method.
 */
class ICatchIPancamRender
{
public:
    virtual ~ICatchIPancamRender() { };

public:
    /**
     * Enable The SDK rendering without GL rendering.
     *
     * @return Return true if no error occurred, otherwise return false.
     *
     * @throws IchStreamAlreadyStartedException stream running exception, this method should be called before stream started.
     */
    virtual int32_t enableRender(shared_ptr<ICatchSurfaceContext> surfaceContext) = 0;

    /**
     * Enable The SDK rendering without GL rendering.
     *
     * @return Return true if no error occurred, otherwise return false.
     *
     * @throws IchStreamAlreadyStartedException stream running exception, this method should be called before stream started.
     */
    virtual int32_t enableRender(shared_ptr<ICatchSurfaceContext> surfaceContext, shared_ptr<ICatchIStreamVideoDecoder> videoDecoder, shared_ptr<ICatchIStreamAudioDecoder> audioDecoder) = 0;

    /**
     * Enable The SDK rendering with GL feature, this method will provide an interface which called ICatchIPancamGL.
     * App should use this interface to set GL feature provided by iCatch SDK.
     *
     * @return instance of ICatchIPancamGL's implementation.
     *
     * @throws IchStreamAlreadyStartedException stream running exception, this method should be called before stream started.
     */
    virtual int32_t enableGLRender(shared_ptr<ICatchIPancamGL>& pancamGL) = 0;

    /**
     * Enable The SDK rendering with GL feature, this method will provide an interface which called ICatchIPancamGL.
     * App should use this interface to set GL feature provided by iCatch SDK.
     *
     * @return instance of ICatchIPancamGL's implementation.
     *
     * @throws IchStreamAlreadyStartedException stream running exception, this method should be called before stream started.
     */
    virtual int32_t enableGLRender(shared_ptr<ICatchIPancamGL>& pancamGL, int32_t panoramaType) = 0;

    /**
     * Enable The SDK rendering with GL feature, this method will provide an interface which called ICatchIPancamGL.
     * App should use this interface to set GL feature provided by iCatch SDK.
     *
     * @return instance of ICatchIPancamGL's implementation.
     *
     * @throws IchStreamAlreadyStartedException stream running exception, this method should be called before stream started.
     */
    virtual int32_t enableGLRender(shared_ptr<ICatchIPancamGL>& pancamGL, shared_ptr<ICatchIStreamVideoDecoder> videoDecoder, shared_ptr<ICatchIStreamAudioDecoder> audioDecoder) = 0;

    /**
     * Enable The SDK rendering with GL feature, this method will provide an interface which called ICatchIPancamGL.
     * App should use this interface to set GL feature provided by iCatch SDK.
     *
     * @return instance of ICatchIPancamGL's implementation.
     *
     * @throws IchStreamAlreadyStartedException stream running exception, this method should be called before stream started.
     */
    virtual int32_t enableGLRender(shared_ptr<ICatchIPancamGL>& pancamGL, int32_t panoramaType, shared_ptr<ICatchIStreamVideoDecoder> videoDecoder, shared_ptr<ICatchIStreamAudioDecoder> audioDecoder) = 0;

    /**
     * Disable pancam GL feature, this means The app should do the render itself.
     * this method will provide an interface which called ICatchIStreamProvider.
     * App should use this interface to get streaming info and frame info and then rendering frames.
     * @return instance of ICatchIStreamProvider's implementation.
     * @throws IchStreamAlreadyStartedException streaming running exception, this method should be called before stream started.
     */
    virtual int32_t disableRender(shared_ptr<ICatchIStreamProvider>& streamProvider) = 0;
};

}}}

#endif
