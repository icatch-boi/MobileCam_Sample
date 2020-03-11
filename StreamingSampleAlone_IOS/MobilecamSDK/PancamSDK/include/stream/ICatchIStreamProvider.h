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

#ifndef __ICATCH_I_STREAM_PROVIDER_H__
#define __ICATCH_I_STREAM_PROVIDER_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include <stdint.h>
#include <vector>
#include <memory>

#include "type/ICatchVideoFormat.h"
#include "type/ICatchAudioFormat.h"
#include "type/ICatchFrameBuffer.h"

using namespace com::icatchtek::reliant;

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * The interface to provide stream information.
 * 1. get video&audio format.
 * 2. get video/audio frame.
 * 3. .etc.
 */
class ICatchIStreamProvider
{
public:
    virtual ~ICatchIStreamProvider() {};

public:
    /**
     * Query whether the sdk's contains video stream or not.
     *
     * @return Return true if the SDK had setup a video stream, otherwise return false.
     *
     * @throws IchInvalidSessionException The session is closed or not prepared.
     * @throws IchStreamNotRunningException stream closed by the App or the camera.
     * @throws IchTransportException Indicates transport exception, from network or usb transport.
     * @throws IchDeprecatedException The instance is deprecated, You should get new one using ICatchIPancamRender.disableRender.
     */
    virtual bool containsVideoStream() = 0;

    /**
     * Query whether the sdk's contains audio stream or not.
     *
     * @return Return true if the SDK had setup a audio stream, otherwise return false.
     *
     * @throws IchInvalidSessionException The session is closed or not prepared.
     * @throws IchStreamNotRunningException stream closed by the App or the camera.
     * @throws IchTransportException Indicates transport exception, from network or usb transport.
     * @throws IchDeprecatedException The instance is deprecated, You should get new one using ICatchPancamRender.disableRender.
     */
    virtual bool containsAudioStream() = 0;

    /**
     * Get icatch video format, such as video width, video height, csd-0, csd-1, codec name.
     *
     * @return instance of ICatchVideoFormat.
     *
     * @throws IchInvalidSessionException The session is closed or not prepared.
     * @throws IchStreamNotRunningException stream closed by the App or the camera.
     * @throws IchTransportException Indicates transport exception, from network or usb transport.
     * @throws IchDeprecatedException The instance is deprecated, You should get new one using ICatchIPancamRender.disableRender.
     */
    virtual int32_t getVideoFormat(shared_ptr<ICatchVideoFormat>& videoFormats) = 0;
    virtual int32_t getVideoFormat(int32_t streamNo, shared_ptr<ICatchVideoFormat>& videoFormat) = 0;
    virtual int32_t getVideoFormats(vector<shared_ptr<ICatchVideoFormat> >& videoFormats) = 0;

    /**
     * Get icatch audio format, such codec, channel, frequency etc.
     * @return instance of ICatchAudioFormat.
     *
     * @throws IchInvalidSessionException The session is closed or not prepared.
     * @throws IchStreamNotRunningException stream closed by the App or the camera.
     * @throws IchTransportException Indicates transport exception, from network or usb transport.
     * @throws IchDeprecatedException The instance is deprecated, You should get new one using ICatchIPancamRender.disableRender.
     */
    virtual int32_t getAudioFormat(shared_ptr<ICatchAudioFormat>& audioFormat) = 0;
    virtual int32_t getAudioFormat(int32_t streamNo, shared_ptr<ICatchAudioFormat>& audioFormat) = 0;
    virtual int32_t getAudioFormats(vector<shared_ptr<ICatchAudioFormat> >& audioFormat) = 0;

    /**
     * Get video frame from SDK. if no frames stored in SDK, this
     * method will be blocked for a while to wait new frames. after that this API will throws try again exception.
     *
     * @param frameBuffer the buffer with which will store the video frame.
     * @return Operations succeed, return true, otherwise return false.
     *
     * @throws IchTransportException Indicates transport exception, from network or usb transport.
     * @throws IchVideoStreamClosedException video stream closed.
     * @throws IchStreamNotRunningException stream closed by the App or the camera.
     * @throws IchTryAgainException could not get frame at this moment, should try again next.
     * @throws IchInvalidSessionException The session has not been prepared or already been destroyed..
     * @throws IchBufferTooSmallException The input buffer too small, please allocate a new buffer with bigger size.
     * @throws IchPbStreamPausedException The stream had been paused by SDK or APP in video playback mode.
     * @throws IchDeprecatedException The instance is deprecated, You should get new one using ICatchIPancamRender.disableRender.
     */
    virtual int32_t getNextVideoFrame(std::shared_ptr<ICatchFrameBuffer> frameBuffer) = 0;
    virtual int32_t getNextVideoFrame(int32_t streamNo, std::shared_ptr<ICatchFrameBuffer> frameBuffer, bool& continueWait) = 0;

    /**
     ** Get audio frame from SDK. if no frames stored in SDK, this
     * method will be blocked for a while to wait new frames. after that this API will throws try again exception.
     *
     * @param frameBuffer the buffer with which will store the audio frame.
     * @return Operations succeed, return true, otherwise return false.
     *
     * @throws IchTransportException Indicates transport exception, from network or usb transport.
     * @throws IchAudioStreamClosedException audio stream closed.
     * @throws IchStreamNotRunningException stream closed by the App or the camera.
     * @throws IchTryAgainException could not get frame at this moment, should try again next.
     * @throws IchInvalidSessionException The session has not been prepared or already been destroyed..
     * @throws IchBufferTooSmallException The input buffer too small, please allocate a new buffer with bigger size.
     * @throws IchPbStreamPausedException The stream had been paused by SDK or APP in video playback mode.
     * @throws IchDeprecatedException The instance is deprecated, You should get new one using ICatchIPancamRender.disableRender.
     */
    virtual int32_t getNextAudioFrame(std::shared_ptr<ICatchFrameBuffer> frameBuffer) = 0;
    virtual int32_t getNextAudioFrame(int32_t streamNo, std::shared_ptr<ICatchFrameBuffer> frameBuffer, bool& continueWait) = 0;
};

}}}

#endif

