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

#ifndef __ICATCH_I_STREAM_CONTROL_H__
#define __ICATCH_I_STREAM_CONTROL_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include <vector>
#include <string>
#include <memory>
#include <stdint.h>

#include "type/ICatchImageSize.h"
#include "type/ICatchAudioFormat.h"
#include "type/ICatchFrameBuffer.h"
#include "type/ICatchExtensionInfo.h"

using namespace std;
using namespace com::icatchtek::reliant;

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * Interface to control the stream.
 */
class ICatchIStreamControl
{
public:
    virtual ~ICatchIStreamControl() {};

public:
    /**
     * Enable audio when doing preview.
     * @param audioFormat Audio settings.
     * @return Return true if no error occurred, otherwise return false.
     * @throws IchAudioAlreadyEnabledException The audio streaming is already enabled.
     * @throws IchTransportException Indicates transport error.
     * @throws IchNotSupportedException The operation not supported by The SDK.
     * @throws IchInvalidArgumentException The format settings not supported by The SDK.
     */
    virtual int32_t enableAudio() = 0;

    /**
     * Disable audio when doing preview.
     * @return Return true if no error occurred, otherwise return false.
     * @throws IchAudioAlreadyDisabledException The already streaming already disabled.
     * @throws IchTransportException Indicates transport error.
     * @throws IchNotSupportedException The operation not supported by The SDK.
     * @throws IchInvalidArgumentException The format settings not supported by The SDK.
     */
    virtual int32_t disableAudio() = 0;

    /** Start movie record.
     * @param fileName The record video file name, with full path.
     * @param remote From remote or Not.
     * @return Return true if no error occurred, otherwise return false.
     * @throws IchInvalidSessionException Invalid session, the session may be destroyed.
     * @throws IchTransportException Transport error, comes from usb or net.
     * @throws IchStreamNotRunningException The streaming not running exception.
     * @throws IchMuxerAlreadyStartedException The muxer already started.
     * @throws IchMuxerStartFailedException Start muxer failed.
     **/
    virtual int32_t startMovieRecord(string fileName, bool remote) = 0;

    /** Start movie record.
     * @param fileName The record video file name, with full path.
     * @param remote From remote or Not.
     * @return Return true if no error occurred, otherwise return false.
     * @throws IchInvalidSessionException Invalid session, the session may be destroyed.
     * @throws IchTransportException Transport error, comes from usb or net.
     * @throws IchStreamNotRunningException The streaming not running exception.
     * @throws IchMuxerAlreadyStartedException The muxer already started.
     * @throws IchMuxerStartFailedException Start muxer failed.
     **/
    virtual int32_t startMovieRecord(string fileName, bool remote, bool tag360) = 0;

    /**
     * Stop movie record.
     * @return Return true if no error occurred, otherwise return false.
     * @throws IchInvalidSessionException Invalid session, the session may be destroyed.
     * @throws IchTransportException Transport error, comes from usb or net.
     * @throws IchStreamNotRunningException The streaming not running exception.
     * @throws IchMuxerNotStartedException The muxer not started.
     */
    virtual int32_t stopMovieRecord() = 0;

    virtual int32_t addMovieRecordInfo(const char* info) = 0;

    /**
     * Get supported image size.
     * @return The supported image sizes.
     * @throws IchInvalidSessionException Invalid session, the session may be destroyed.
     * @throws IchTransportException Transport error, comes from usb or net.
     * @throws IchStreamNotRunningException The streaming not running exception.
     * @throws IchNotSupportedException The operation not supported by SDK.
     */
    virtual int32_t getSupportedImageSizes(vector<ICatchImageSize>& imageSizes) = 0;

    /**
     * Set image size.
     * @param imageSize The image size to be set.
     * @return Return true if no error occurred, otherwise return false.
     * @throws IchInvalidSessionException Invalid session, the session may be destroyed.
     * @throws IchTransportException Transport error, comes from usb or net.
     * @throws IchStreamNotRunningException The streaming not running exception.
     * @throws IchNotSupportedException The operation not supported by SDK.
     */
    virtual int32_t setImageSize(ICatchImageSize& imageSize) = 0;

    /**
     * Snap an image.
     * @param image Used to receive the snapped image.
     * @param timeoutInMS timeout in million seconds.
     * @return Return true if no error occurred, otherwise return false.
     * @throws IchInvalidSessionException Invalid session, the session may be destroyed.
     * @throws IchTransportException Transport exception, network or usb error.
     * @throws IchStreamNotRunningException Streaming had not be started.
     * @throws IchImageSizeNotSpecifiedException Image size not specified.
     * @throws IchNotSupportedException Operation not supported.
     */
    virtual int32_t snapImage(int32_t count, string path, int32_t timeoutInMS) = 0;
    virtual int32_t snapImage(vector<shared_ptr<ICatchFrameBuffer> > images, bool stitched, int32_t timeoutInMS) = 0;

    virtual int32_t executeExtensionCommand(shared_ptr<ICatchExtensionInfo> extensionInfo) = 0;
};

}}}

#endif
