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

#ifndef __ICATCH_FILE_TYPE_H__
#define __ICATCH_FILE_TYPE_H__

namespace com{ namespace icatchtek{ namespace reliant{

typedef enum ICatchFileType
{
    ICH_FILE_TYPE_IMAGE       = 0x01,
    ICH_FILE_TYPE_VIDEO       = 0x02,
    ICH_FILE_TYPE_AUDIO       = 0x04,
    ICH_FILE_TYPE_TEXT        = 0x08,
    ICH_FILE_TYPE_ALL         = 0x0F,
    ICH_FILE_TYPE_UNKNOWN     = 0x10,
} ICatchFileType;

}}}

#endif

