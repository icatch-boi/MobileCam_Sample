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

#ifndef __ICATCH_DEPTH_NET_TRANSPORT_H__
#define __ICATCH_DEPTH_NET_TRANSPORT_H__

#include <string>
#include <memory>
#include "WindowsApi.h"
#include "type/transport/ICatchITransport.h"

using namespace std;
using namespace com::icatchtek::reliant;

namespace com{ namespace icatchtek{ namespace reliant{

class ICAT_API ICatchDepthNetTransportLogger
{
public:
    ICatchDepthNetTransportLogger();

private:
    static shared_ptr<ICatchDepthNetTransportLogger> instance;
public:
    static shared_ptr<ICatchDepthNetTransportLogger> getInstance();

public:
    void setDebugMode(bool enable);
    void setFileLogOutput(bool bOut);
    void setFileLogOutputPath(string path);
    void setSystemLogOutput(bool bOut);

private:
    ICatchDepthNetTransportLogger(ICatchDepthNetTransportLogger& log);
    ICatchDepthNetTransportLogger & operator = (const ICatchDepthNetTransportLogger&);
};

}}}

#endif
