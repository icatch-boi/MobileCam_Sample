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

#ifndef __ICATCH_SURFACE_CONTEXT_WINDOWS_H__
#define __ICATCH_SURFACE_CONTEXT_WINDOWS_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include <stdint.h>

#include <thread>
#include <memory>

#include "ICatchIGLFunctions.h"
#include "type/ICatchGLPoint.h"
#include "gl/ICatchIPancamGLTransform.h"

//#include "Surface_util.h"
#include "surface/ICatchSurfaceContext.h"

using namespace std;
using namespace com::icatchtek::pancam;

typedef struct GLSContext GLScontext;

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

class ICAT_API ICatchSurfaceContext_Windows : public ICatchSurfaceContext
{
public:
    ICatchSurfaceContext_Windows(shared_ptr<ICatchIGLFunctions> iGL);

public:
    void setRender(shared_ptr<ICatchSurfaceRender> surfaceRender);

private:
    ICatchSurfaceContext_Windows& operator = (const ICatchSurfaceContext_Windows &noncopyable);
    ICatchSurfaceContext_Windows(const ICatchSurfaceContext_Windows &noncopyable);

public:
    shared_ptr<ICatchIGLFunctions> iGL;
};

}}}

#endif

