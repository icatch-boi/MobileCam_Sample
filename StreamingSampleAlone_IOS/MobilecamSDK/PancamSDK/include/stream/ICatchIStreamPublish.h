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

#ifndef __ICATCH_I_STREAM_PUBLISH_H__
#define __ICATCH_I_STREAM_PUBLISH_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include <string>
#include <stdint.h>

#include "type/CredentialSDK.h"

using namespace std;
using namespace com::icatchtek::pancam;

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

class ICatchIStreamPublish
{
public:
    virtual ~ICatchIStreamPublish() {};

public:
    /**
     * start publish streaming to rtmp-server
     *
     * @return Operations succeed, return true, otherwise return false.
     * @throws IchStreamNotRunningException The session is closed or not prepared.
     * @throws IchStreamNotSupportException The stream video or audio format is not supported
     * @throws IchStreamPublishException    The streaming publish state error
     */
    virtual int32_t startPublishStreaming(string rtmpUrl)  = 0;

    /**
     * stop publish streaming to rtmp-server
     *
     * @return Operations succeed, return true, otherwise return false.
     * @throws IchInvalidArgumentException  The streaming publish flow error.
     * @throws IchStreamNotRunningException The session is closed or not prepared.
     * @throws IchStreamPublishException    The streaming publish state error
     */
    virtual int32_t stopPublishStreaming() = 0;

    /**
     * get streaming state whether it can supported publish
     *
     * @return Operations succeed, return true, otherwise return false.
     * @throws IchStreamNotSupportException The streaming is not support to publish.
     * @throws IchStreamNotRunningException The session is closed or not prepared.
     */
    virtual int32_t isStreamSupportPublish() = 0;

    virtual string createChannel(CredentialSDK& credential, string resolution, string broadCastTitle, bool vrProjection) = 0;

    virtual int32_t deleteChannel() = 0;

    virtual string startLive() = 0;

    virtual int32_t stopLive() = 0;
};

}}}

#endif

