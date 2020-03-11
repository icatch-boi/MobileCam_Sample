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

#ifndef __ICATCH_I_PANCAM_PERVIEW_H__
#define __ICATCH_I_PANCAM_PERVIEW_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include "type/ICatchStreamParam.h"
#include "stream/ICatchIStreamControl.h"
#include "stream/ICatchIStreamPublish.h"
#include "stream/ICatchIStreamStablization.h"

#include "ICatchIPancamRender.h"

using namespace com::icatchtek::reliant;
using namespace com::icatchtek::pancam;

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * The interface to render preview panoramic streaming.
 */
class ICatchIPancamPreview : public ICatchIPancamRender
{
public:
    virtual ~ICatchIPancamPreview() { };

public:
    /**
     * Start preview stream with stream parameter.
     *
     * @return Return true if no error occurred, otherwise return false.
     *
     * @throws IchStreamNotSupportException Indicates the stream not supported by SDK.
     */
    virtual int32_t start(shared_ptr<ICatchStreamParam> streamParam) = 0;

    /**
     * Start preview stream with stream parameter, enable audio or not.
     *
     * @param streamParam The stream parameter.
     * @param enableAudio enable audio or not.
     * @return Return true if no error occurred, otherwise return false.
     *
     * @throws IchStreamNotSupportException Indicates Streaming not supported, the size may not match.
     * @throws IchInvalidSessionException Indicates invalid session exception.
     * @throws IchTransportException Indicates transport exception, from network or usb transport.
     * @throws IchInvalidArgumentException Invalid argument.
     * @throws IchStreamAlreadyStartedException The stream already started, should close it first.
     */
    virtual int32_t start(shared_ptr<ICatchStreamParam> streamParam, bool enableAudio) = 0;

    /**
     * Start preview stream with stream parameter, enable audio or not.
     *
     * @param streamParam The stream parameter.
     * @param enableAudio enable audio or not.
     * @return Return true if no error occurred, otherwise return false.
     *
     * @throws IchStreamNotSupportException Indicates Streaming not supported, the size may not match.
     * @throws IchInvalidSessionException Indicates invalid session exception.
     * @throws IchTransportException Indicates transport exception, from network or usb transport.
     * @throws IchInvalidArgumentException Invalid argument.
     * @throws IchStreamAlreadyStartedException The stream already started, should close it first.
     */
    virtual int32_t start(shared_ptr<ICatchStreamParam> streamParam, bool enableAudio, int32_t outputFPS) = 0;

    /**
     * Start preview stream with stream parameter, enable audio or not.
     *
     * @param streamParam The stream parameter.
     * @param enableAudio enable audio or not.
     * @return Return true if no error occurred, otherwise return false.
     *
     * @throws IchStreamNotSupportException Indicates Streaming not supported, the size may not match.
     * @throws IchInvalidSessionException Indicates invalid session exception.
     * @throws IchTransportException Indicates transport exception, from network or usb transport.
     * @throws IchInvalidArgumentException Invalid argument.
     * @throws IchStreamAlreadyStartedException The stream already started, should close it first.
     */
    virtual int32_t start(shared_ptr<ICatchStreamParam> streamParam, bool enableAudio, int32_t outputFPS, bool convertVideo, bool convertAudio) = 0;

    /**
     * Stop preview streaming.
     *
     * @return Return true if no error occurred, otherwise return false.
     *
     * @throws IchStreamNotRunningException The streaming not running, so stop will fail.
     * @throws IchInvalidSessionException Indicates invalid session exception.
     * @throws IchTransportException Indicates transport exception, from network or usb transport.
     */
    virtual int32_t stop() = 0;
    virtual int32_t stop(int32_t nextOps) = 0;

    virtual int32_t getThumbnail(std::shared_ptr<ICatchFrameBuffer> frameBuffer, int timeoutInMS) = 0;
    virtual int32_t getThumbnail(int32_t streamNo, std::shared_ptr<ICatchFrameBuffer> frameBuffer, int timeoutInMS) = 0;

    /**
     *  get stream control instance.
     *
     * @return the stream control instance.
     *
     * @throws IchStreamNotRunningException stream not running, forget to start stream?
     * @throws IchNotSupportedException stream does not support app to control the stream though the SDK.
     */
    virtual int32_t getStreamControl(shared_ptr<ICatchIStreamControl>& control) = 0;

    /**
     *  get stream publish instance.
     *
     * @return the stream control instance.
     *
     * @throws IchStreamNotRunningException stream not running, forget to start stream?
     * @throws IchNotSupportedException stream does not support app to publish the stream through the SDK.
     */
    virtual int32_t getStreamPublish(shared_ptr<ICatchIStreamPublish>& publish) = 0;

    /**
     *  get stream publish instance.
     *
     * @return the stream control instance.
     *
     * @throws IchStreamNotRunningException stream not running, forget to start stream?
     * @throws IchNotSupportedException stream does not support app to publish the stream through the SDK.
     */
    virtual int32_t getStreamStablization(shared_ptr<ICatchIStreamStablization>& stablization) = 0;

    virtual bool isStreamingOn() = 0;
};

}}}

#endif
