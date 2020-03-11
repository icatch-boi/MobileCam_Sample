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

#ifndef __ICATCH_PANCAM_PANCAM_INFO_H__
#define __ICATCH_PANCAM_PANCAM_INFO_H__

#include <string>
#include "WindowsApi.h"

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * The control class. mainly used for event &amp; event listener.
 */
class ICAT_API ICatchPancamInfo
{
public:

    /**
     * Constructor
     * @param sessionID The session ID This object belongs to.
     */
    ICatchPancamInfo(int32_t sessionID);

public:

    /**
     * Get the SDK version.
     * @return The version of the SDK.
     */
    static std::string getSDKVersion();

private:
    int32_t sessionID;
    static std::string sdkVersion;

private:
    ICatchPancamInfo(ICatchPancamInfo& info);
    ICatchPancamInfo& operator = (const ICatchPancamInfo&);
};

}}}

#endif

