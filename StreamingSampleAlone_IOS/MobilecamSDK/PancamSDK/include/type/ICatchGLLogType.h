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

#ifndef __ICATCH_GL_LOG_TYPE__
#define __ICATCH_GL_LOG_TYPE__

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * ICatch sdk's log type macros
 *
 * @author peng.tan
 *
 */
typedef enum ICatchGLLogType
{
    /** type for opengl log */
    ICH_GL_LOG_TYPE_OPENGL      = 0x00,
    /** type for stream log */
    ICH_GL_LOG_TYPE_STREAM      = 0x01,
    /** type for common log */
    ICH_GL_LOG_TYPE_COMMON      = 0x02,
    /** type for develop log */
    ICH_GL_LOG_TYPE_DEVELOP     = 0x03,
} ICatchGLLogType;

}}}

#endif

