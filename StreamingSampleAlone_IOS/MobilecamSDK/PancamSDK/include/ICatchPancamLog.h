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
 **************************************************************************/

#ifndef __ICATCH_PANCAM_PANCAM_LOG__
#define __ICATCH_PANCAM_PANCAM_LOG__

#include <string>
#include "WindowsApi.h"

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * This logger cass contains methods which the customer could used to denable/disable the sdk's debug mode,
 * set log level and destination(to file or to ddms).
 *
 * @author peng.tan
 *
 */
class ICAT_API ICatchPancamLog
{
public:
    /** singleton */
    static ICatchPancamLog* getInstance();

public:
    /**
     * Write log information to ddms.
     */
    void setFileLogOutput(bool fileLog);

    /**
     * Set file log's path.
     */
    void setFileLogPath(std::string path);

    /**
     * Write log information to file.
     */
    void setSystemLogOutput(bool systemLog);

    void setDebugMode(bool debugMode);

    /**
     * Enable/disable pancam log.
     * @param enable true --> enable pancam log; false --> disable pancam log;
     */
    void setLog(int32_t type, bool enable);

    /**
     * Specify log level(for pancam) of the SDK, Logs which above this log level will be recorded.
     * @param level The SDK's log level.
     */
    void setLogLevel(int32_t type, int32_t level);

    /* write log to SDK's log mech api */
    void writeLog(int32_t type, int32_t level, const char* tag, const char* message);

private:
    ICatchPancamLog(){}
    static ICatchPancamLog* pancamLog;
};

}}}

#endif

