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

#ifndef __ICATCH_PANCAM_PANCAM_SESSION_H__
#define __ICATCH_PANCAM_PANCAM_SESSION_H__

/* -----------------------------------------------------------------------------
 * Header files, namespace references.
 */
#include "WindowsApi.h"
#include "type/ICatchGLColor.h"
#include "type/ICatchGLDisplayPPI.h"
#include "type/transport/ICatchITransport.h"

#include "ICatchIPancamListener.h"

#include "ICatchPancamInfo.h"
#include "ICatchIPancamControl.h"
#include "ICatchIPancamImage.h"
#include "ICatchIPancamPreview.h"
#include "ICatchIPancamVideoPlayback.h"

using namespace com::icatchtek::reliant;
using namespace com::icatchtek::pancam;

/* -----------------------------------------------------------------------------
 * class &namespace definitions
 */
namespace com{ namespace icatchtek{ namespace pancam {

/**
 * The pancam session class. you may want more than one
 * pancam sessions based on your business logic.
 */
class ICAT_API ICatchPancamSession
{
public:
    /**
     * The class method which used to create session.
     * @return The new pancam session.
     */
    ICatchPancamSession(int32_t sessionID);
    ~ICatchPancamSession();

public:
    static int32_t addEventListener(int32_t icatchEvtID, shared_ptr<ICatchIPancamListener> listener, bool forAllSession);
    static int32_t delEventListener(int32_t icatchEvtID, shared_ptr<ICatchIPancamListener> listener, bool forAllSession);

public:
    /* get the id of this session */
    int32_t getSessionID();

    /**
     * Prepare pancam session, with default color, and the screen's displayPPI.
     * @param defaultColor The default color with you want the SDK render to surface
     *                     when no images updated to it.
     * @param displayPPI The screen's displayPPI, pixels per inch.
     * @return Return ICH_SUCCEED if no error occurred, otherwise return an error code.
     */
    int32_t prepareSession(shared_ptr<ICatchITransport> transport, shared_ptr<ICatchGLColor> defaultColor, shared_ptr<ICatchGLDisplayPPI> displayPPI);

    /**
     * Destroy session, release resources.
     * @return Return true if no error occurred, otherwise return false.
     */
    bool destroySession();

    /**
     * Get pancam info.
     * @return the pancam info
     */
    shared_ptr<ICatchPancamInfo> getInfo();

    /**
     * Get pancam control.
     * @return the pancam control.
     */
    shared_ptr<ICatchIPancamControl> getControl();

    /**
     * Get pancam image.
     * @return the pancam image.
     */
    shared_ptr<ICatchIPancamImage> getImage();

    /**
     * Get pancam preview.
     * @return the pancam preview.
     */
    shared_ptr<ICatchIPancamPreview> getPreview();

    /**
     * Get pancam playback.
     * @return pancam playback.
     */
    shared_ptr<ICatchIPancamVideoPlayback> getVideoPlayback();

private:
    int32_t                                     sessionID;
    shared_ptr<ICatchITransport>            transport;

    shared_ptr<ICatchPancamInfo>            info;
    shared_ptr<ICatchIPancamControl>        control;
    shared_ptr<ICatchIPancamImage>          image;
    shared_ptr<ICatchIPancamPreview>        preview;
    shared_ptr<ICatchIPancamVideoPlayback>  videoPlayback;

private:
    ICatchPancamSession(ICatchPancamSession& session);
    ICatchPancamSession& operator = (const ICatchPancamSession&);
};

}}}

#endif

