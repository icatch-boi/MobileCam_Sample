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

#ifndef __ICATCH_PANCAM_CONFIG_H__
#define __ICATCH_PANCAM_CONFIG_H__

#include <string>
#include "WindowsApi.h"

using namespace std;

class ICAT_API ICatchPancamConfig
{
private:
    ICatchPancamConfig();
    static ICatchPancamConfig* instance;

public:
    static ICatchPancamConfig* getInstance();

    // preview cache config
    bool setPreviewCacheParam(int32_t cacheTimeInMs, int32_t dropFrameTimeOverMs = 200);
    int32_t getPreviewCacheTime();

    // software decoder
    bool setSoftwareDecoder(bool softwareDecoder);

    bool setOutputCodec(int32_t codec, int32_t outputCodec);

    // save streaming file log.
    bool enableDumpTransportStream(bool videoStream, string filePath);
    bool disableDumpTransportStream(bool videoStream);

    bool enableRTPOverTCP();
    bool disableRTPOverTCP();

    void setExtHeadCheck(bool enable);
    bool getExtHeadCheck();
};

#endif

