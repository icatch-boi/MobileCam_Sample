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

#ifndef __ICATCH_PANCAM_SURFACE_CONTEXT_ANDROID_EGL_H__
#define __ICATCH_PANCAM_SURFACE_CONTEXT_ANDROID_EGL_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include <stdint.h>
#include <thread>
#include <EGL/egl.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>

#include "ICatchIGLFunctions.h"
#include "surface/ICatchSurfaceContext.h"

using namespace com::icatchtek::pancam;

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

class ICatchSurfaceContext_AndroidEGL : public ICatchSurfaceContext
{
public:
    ICatchSurfaceContext_AndroidEGL(ANativeWindow* nativeWindow);
    ~ICatchSurfaceContext_AndroidEGL();

private:
    ICatchSurfaceContext_AndroidEGL& operator = (const ICatchSurfaceContext_AndroidEGL &noncopyable);
    ICatchSurfaceContext_AndroidEGL(const ICatchSurfaceContext_AndroidEGL &noncopyable);

public:
    int32_t start();
    int32_t stop();

public:
    int32_t setViewPort(int32_t x, int32_t y, int32_t width, int32_t height, bool force);

public:
    void setRender(shared_ptr<ICatchSurfaceRender> surfaceRender);

private:
    bool initialize_EGL(int32_t& windowW, int32_t& windowH);
    void destroy_EGL();

private:
    void renderLoop();

private:
    bool setupAndroid();
    bool renderAndroid();
    bool tearDownAndroid();
    int32_t setViewPortAndroid(int32_t windowW, int32_t windowH);

private:
    EGLDisplay      eglDisplay;
    EGLSurface      eglSurface;
    EGLContext      eglContext;

private:
    int32_t         viewPortX;
    int32_t         viewPortY;
    int32_t         viewPortW;
    int32_t         viewPortH;
    bool            viewPortChange;
    bool            viewPortReady;

private:
    bool                    renderRun;
    shared_ptr<std::thread> renderThd;

private:
    ANativeWindow*                  nativeWindow;
    shared_ptr<ICatchIGLFunctions>  iGL;
};

}}}

#endif

