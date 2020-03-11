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

#ifndef __ICATCH_SURFACE_CONTEXT_WINDOWS_EGL_H__
#define __ICATCH_SURFACE_CONTEXT_WINDOWS_EGL_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include <stdint.h>
#include <EGL/egl.h>

#include <thread>
#include <memory>

#include "type/ICatchGLPoint.h"
#include "gl/ICatchIPancamGLTransform.h"

#include "ICatchIGLFunctions.h"
#include "surface/ICatchSurfaceContext.h"

using namespace std;
using namespace com::icatchtek::pancam;

typedef struct GLSContext GLScontext;

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

class ICAT_API ICatchSurfaceContext_WindowsEGL : public ICatchSurfaceContext
{
public:
    ICatchSurfaceContext_WindowsEGL();
    ~ICatchSurfaceContext_WindowsEGL();

private:
    ICatchSurfaceContext_WindowsEGL& operator = (const ICatchSurfaceContext_WindowsEGL &noncopyable);
    ICatchSurfaceContext_WindowsEGL(const ICatchSurfaceContext_WindowsEGL &noncopyable);

public:
    int32_t start(int32_t windowW, int32_t windowH);
    int32_t stop();

    shared_ptr<ICatchSurfaceRender> getRender();
    int32_t setViewPort(int32_t x, int32_t y, int32_t width, int32_t height, bool force);

public:
    void winLoopFunc();
    void setGLTransform(shared_ptr<ICatchIPancamGLTransform> glTransform);

public:
    void setRender(shared_ptr<ICatchSurfaceRender> surfaceRender);

public: // change to public, access in none member class function
    bool setupWindows();
    bool renderWindows();
    bool tearDownWindows();

public: // change to public, access in none member class function
    int32_t viewPortX;
    int32_t viewPortY;
    int32_t viewPortW;
    int32_t viewPortH;
    bool viewPortUpdate;

public: // change to public, access in none member class function
    shared_ptr<GLSContext> glsContext;
    shared_ptr<ICatchIGLFunctions> iGL;
    shared_ptr<ICatchIPancamGLTransform> glTransform;
};

}}}

#endif

