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

#ifndef __ICATCH_I_PANCAM_VIDEO_PLAYBACK_H__
#define __ICATCH_I_PANCAM_VIDEO_PLAYBACK_H__

#include "type/ICatchFile.h"
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
 * The interface to render playback panoramic streaming.
 */
class ICatchIPancamVideoPlayback : public ICatchIPancamRender
{
public:
    virtual ~ICatchIPancamVideoPlayback() { };

public:
    /**
     * Play icatch video file from camera to from phone.
     *
     * @param file The file with which you want to play.
     * @param disableAudio disable audio or not.
     * @param remote Tells the SDK whether the video file comes from your file or from the camera.
     * @return Return true if no error happened, otherwise return false.
     *
     * @throws IchStreamNotSupportException Indicates Streaming not supported, the size may not match.
     * @throws IchInvalidSessionException Indicates invalid session exception.
     * @throws IchTransportException Indicates transport exception, from network or usb transport.
     * @throws IchFileNotFoundException invalid file name or path.
     * @throws IchInvalidArgumentException Invalid argument.
     * @throws IchStreamAlreadyStartedException The stream already started, should close it first.
     */
    virtual int32_t play(shared_ptr<ICatchFile> file, bool disableAudio, bool remote) = 0;

    /**
     * Play icatch video file from camera to from phone.
     *
     * @param file The file with which you want to play.
     * @param disableAudio disable audio or not.
     * @param remote Tells the SDK whether the video file comes from your file or from the camera.
     * @return Return true if no error happened, otherwise return false.
     *
     * @throws IchStreamNotSupportException Indicates Streaming not supported, the size may not match.
     * @throws IchInvalidSessionException Indicates invalid session exception.
     * @throws IchTransportException Indicates transport exception, from network or usb transport.
     * @throws IchFileNotFoundException invalid file name or path.
     * @throws IchInvalidArgumentException Invalid argument.
     * @throws IchStreamAlreadyStartedException The stream already started, should close it first.
     */
    virtual int32_t play(shared_ptr<ICatchFile> file, bool disableAudio, bool remote, double cachingTime) = 0;

    /**
     * Stop playing icatch video file.
     *
     * @return Return true if no error happened, otherwise return false.
     *
     * @throws IchStreamNotRunningException Stream not running, forget to call play?
     * @throws IchInvalidSessionException Indicates invalid session exception, this comes from wificamSDK.
     * @throws IchTransportException Indicates transport exception, from network or usb transport.
     */
    virtual int32_t stop() = 0;

    virtual int32_t getThumbnail(std::shared_ptr<ICatchFrameBuffer> frameBuffer, int timeoutInMS) = 0;
    virtual int32_t getThumbnail(int32_t streamNo, std::shared_ptr<ICatchFrameBuffer> frameBuffer, int timeoutInMS) = 0;

    virtual bool isStreamingOn() = 0;

    /**
     * Pause the panoramic stream.
     *
     * @return Return true if no error happened, otherwise return false.
     *
     * @throws IchInvalidSessionException Indicates invalid session.
     * @throws IchTransportException Indicates transport exception, from network or usb transport.
     * @throws IchStreamNotRunningException Stream not running, forget to call play?
     * @throws IchPauseFailedException Indicates pause failed.
     */
    virtual int32_t pause() = 0;

    /**
     * Resume the panoramic stream.
     *
     * @return Return true if no error happened, otherwise return false.
     *
     * @throws IchStreamNotRunningException Stream not running, forget to call play?
     * @throws IchInvalidSessionException Indicates invalid session.
     * @throws IchTransportException Indicates transport exception, from network or usb transport.
     * @throws IchResumeFailedException Indicates seek failed.
     */
    virtual int32_t resume() = 0;

    /**
     * Seek to the specified position of the panoramic stream.
     *
     * @param pts The seek position in seconds.
     * @return Return true if no error happened, otherwise return false.
     *
     * @throws IchInvalidSessionException Indicates invalid session.
     * @throws IchTransportException Indicates transport exception, from network or usb transport.
     * @throws IchStreamNotRunningException Stream not running, forget to call play?
     * @throws IchSeekFailedException Indicates seek failed.
     */
    virtual int32_t seek(double pts) = 0;

    /**
     * Get the length of the panoramic stream.
     *
     * @return Return true if no error happened, otherwise return false.
     *
     * @throws IchStreamNotRunningException Stream not running, forget to call play?
     * @throws IchInvalidSessionException Indicates invalid session exception, this comes from wificamSDK.
     * @throws IchTransportException Indicates transport exception, from network or usb transport.
     */
    virtual int32_t getLength(double& length) = 0;

    /**
     *  get stream control instance.
     *
     * @return the stream control instance.
     *
     * @throws IchStreamNotRunningException stream not running, forget to start stream?
     * @throws IchNotSupportedException stream does not support app to control the stream though the SDK.
     */
    virtual int32_t getStreamControl(shared_ptr<ICatchIStreamControl>& streamControl) = 0;

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
};

}}}

#endif
