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

#ifndef __ICATCH_GL_LOG_LEVEL__
#define __ICATCH_GL_LOG_LEVEL__

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * ICatch sdk's log level macros
 *
 * @author peng.tan
 *
 */
typedef enum ICatchGLLogLevel
{
    /** log level debug */
    ICH_GL_LOG_LEVEL_DEBUG          = 0x00,
    /** log level info */
    ICH_GL_LOG_LEVEL_INFO           = 0x01,
     /** log level warn */
    ICH_GL_LOG_LEVEL_WARN           = 0x03,
    /** log level error */
    ICH_GL_LOG_LEVEL_ERROR          = 0x05,
    /** log level fatal error */
    ICH_GL_LOG_LEVEL_FATAL_ERROR    = 0x06,
} ICatchGLLogLevel;

}}}

#endif

