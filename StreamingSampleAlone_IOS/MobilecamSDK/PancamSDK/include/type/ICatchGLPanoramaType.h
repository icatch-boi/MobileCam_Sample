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

#ifndef __ICATCH_GL_PANORAMA_TYPE_H__
#define __ICATCH_GL_PANORAMA_TYPE_H__

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/** panorama type */
typedef enum ICatchGLPanoramaType
{
    ICH_GL_PANORAMA_TYPE_FISH_EYE       = 0x00,

    /** panorama type sphere */
    ICH_GL_PANORAMA_TYPE_SPHERE         = 0x01,
    ICH_GL_PANORAMA_TYPE_PERSPECTIVE    = 0x01,

    ICH_GL_PANORAMA_TYPE_ASTEROID       = 0x04,

    /** panorama type sphere vr */
    ICH_GL_PANORAMA_TYPE_VIRTUAL_R      = 0x06,

    /** panorama type depth 3D */
    ICH_GL_PANORAMA_TYPE_DEPTH_3D       = 0x07,
} ICatchGLPanoramaType;

}}}

#endif

