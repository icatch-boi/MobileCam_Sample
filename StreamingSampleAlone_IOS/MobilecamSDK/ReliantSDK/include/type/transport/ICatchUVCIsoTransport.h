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

#ifndef __ICATCH_UVC_ISO_TRANSPORT_H__
#define __ICATCH_UVC_ISO_TRANSPORT_H__

#include <memory>
#include "type/ICatchExtensionInfo.h"
#include "type/transport/ICatchITransport.h"

using namespace std;
using namespace com::icatchtek::reliant;

namespace com{ namespace icatchtek{ namespace reliant{

class ICatchUVCIsoTransport : public ICatchITransport
{
public:
    ICatchUVCIsoTransport(int vendorID, int productID, int fileDescriptor);

public:
    shared_ptr<ICatchITransport> clone();

public:
    int getTransportType();

public:
    int prepareTransport();
    int destroyTransport();

public:
    int executeExtensionCommand(shared_ptr<ICatchExtensionInfo> extensionInfo);

private:
    int vendorID;
    int productID;
    int fileDescriptor;
};

}}}

#endif
