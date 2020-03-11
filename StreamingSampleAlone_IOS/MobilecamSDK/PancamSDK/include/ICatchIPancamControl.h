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

#ifndef __ICATCH_I_PANCAM_CONTROL_H__
#define __ICATCH_I_PANCAM_CONTROL_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include "ICatchIPancamListener.h"

using namespace com::icatchtek::pancam;

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * The control class. mainly used for event &amp; event listener.
 */
class ICatchIPancamControl
{
public:
    virtual ~ICatchIPancamControl() { };

public:
    /**
     * Add event listener.
     * @param eventID The eventID with which this event listener belongs to.
     * @param listener The event listener which will be added.
     * @throws IchListenerExistsException Indicates the corresponded event listener already exists.
     * @throws IchInvalidSessionException Invalid session, the session may be destroyed.
     */
    virtual int32_t addEventListener(int32_t eventID, shared_ptr<ICatchIPancamListener> listener) = 0;

    /**
     * Remove event listener.
     * @param eventID The eventID with which this event listener belongs to.
     * @param listener The event listener which will be removed.
     * @throws IchListenerNotExistsException Indicates the corresponded event listener not exists.
     * @throws IchInvalidSessionException Invalid session, the session may be destroyed.
     */
    virtual int32_t removeEventListener(int32_t eventID, shared_ptr<ICatchIPancamListener> listener) = 0;
};

}}}

#endif
