/**************************************************************************
 *
 *         Copyright (c) 2014 by iCatch Technology Co., Ltd.
 *
 *  This software is copyrighted by and is the property of Sunplus
 *  Technology Co., Ltd. All rights are reserved by Sunplus Technology
 *  Co., Ltd. This software may only be used in accordance with the
 *  corresponding license agreement. Any unauthorized use, duplication,
 *  distribution, or disclosure of this software is expressly forbidden.
 *
 *  This Copyright notice MUST not be removed or modified without prior
 *  written consent of Sunplus Technology Co., Ltd.
 *
 *  Sunplus Technology Co., Ltd. reserves the right to modify this
 *  software without notice.
 *
 *  Sunplus Technology Co., Ltd.
 *  19, Innovation First Road, Science-Based Industrial Park,
 *  Hsin-Chu, Taiwan, R.O.C.
 *
 *  Author: peng.tan
 *  Email:  peng.tan@sunmedia.com.cn
 *
 **************************************************************************/

#ifndef __ICATCH_FILE__
#define __ICATCH_FILE__

#include <string>
using namespace std;

#include "WindowsApi.h"

namespace com{ namespace icatchtek{ namespace reliant{

/**
 * The class of ICatch file, should be implement.
 * Not implemented now. So not available for API.
 */
class ICAT_API ICatchFile
{
public:
    explicit ICatchFile(int fileHandle);
    ICatchFile(const    ICatchFile& file);
    ICatchFile(int fileHandle, int type, string filePath, unsigned long long fileSize);
    ICatchFile(int fileHandle, int type, string filePath, string fileName, unsigned long long fileSize);
    ICatchFile(int fileHandle, int type, string filePath, unsigned long long fileSize, string date);
    ICatchFile(int fileHandle, int type, string filePath, unsigned long long fileSize, string date, double frameRate, unsigned int fileWidth, unsigned int fileHeight, unsigned int fileDuration);
    ~ICatchFile();

    int getFileHandle();
    string  getFilePath();
    string  getFileName();
    string  getFileDate();
    int     getFileType();

    unsigned long long getFileSize();
    double getFileFrameRate();
    unsigned int getFileWidth();
    unsigned int getFileHeight();
    unsigned int getFileProtection();
    unsigned int getFileDuration();

    void setFileSize(unsigned long long fileSize);
    void setFileProtection(unsigned int protection);

public:
    string toString();
    static bool fromString(ICatchFile& file, string attributes);

private:
    void resetAttribute();

private:
    int                 fileHandle;

    string              fileName;
    string              filePath;
    string              fileDate;
    int                 fileType;
    unsigned long long  fileSize;
    double              frameRate;
    unsigned int        fileWidth;
    unsigned int        fileHeight;
    unsigned int        fileProtection;
    unsigned int        fileDuration;
};

}}}

#endif

