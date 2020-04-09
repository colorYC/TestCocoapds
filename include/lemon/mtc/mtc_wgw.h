/************************************************************************

        Copyright (c) 2005-2011 by Juphoon System Software, Inc.
                       All rights reserved.

     This software is confidential and proprietary to Juphoon System,
     Inc. No part of this software may be reproduced, stored, transmitted,
     disclosed or used in any form or by any means other than as expressly
     provided by the written license agreement between Juphoon and its
     licensee.

     THIS SOFTWARE IS PROVIDED BY JUPHOON "AS IS" AND ANY EXPRESS OR
     IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
     ARE DISCLAIMED. IN NO EVENT SHALL JUPHOON BE LIABLE FOR ANY DIRECT,
     INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
     OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
     STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
     IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
     POSSIBILITY OF SUCH DAMAGE.

                    Juphoon System Software, Inc.
                    Email: support@juphoon.com
                    Web: http://www.juphoon.com

************************************************************************/
/*************************************************
  File name     : mtc_wgw.h
  Module        : multimedia talk client
  Author        : bob.liu
  Created on    : 2017-06-13
  Description   :
    Marcos and structure definitions required by the mtc webrtc gateway.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_WGW_H__
#define _MTC_WGW_H__

#include "mtc_def.h"

/**
 * @file mtc_wgw.h
 * @brief MTC WebRTC Gateway Interface Functions
 */

/**
 * @defgroup MtcWgwKey MTC notification key of media event.
 * @{
 */

/**
 * @brief A key whose value is a string object in JSON format reflecting
 * the configuration of ICE servers.
 */
#define MtcWgwIceServersKey                 "iceServers"

/**
 * @brief A key whose value is a string object in JSON format reflecting
 * the fail reason.
 */
#define MtcWgwFailReasonKey                 "MtcWgwFailReasonKey"

/**
 * @brief A key whose value is a string object in JSON format reflecting
 * the instanceid.
 */
#define MtcWgwInstanceIdKey                 "MtcWgwInstanceIdKey"

/**
 * @brief A key whose value is a string object in JSON format reflecting
 * the username.
 */
#define MtcWgwUsernameKey                 "MtcWgwUsernameKey"

/**
 * @brief A key whose value is a string object in JSON format reflecting
 * the data.
 */
#define MtcWgwDataKey                 "MtcWgwDataKey"

/** @} */


/**
 * @defgroup MtcWgwNotification MTC notification of session event.
 * @{
 */

/**
 * @brief Posted when initialize OK.
 *
 * The pcInfo of this notification contains
 * @ref MtcWgwIceServersKey.
 */
#define MtcWgwConnectOkNotification "MtcWgwConnectOkNotification"

/**
 * @brief Posted when initialize failed.
 *
 * The pcInfo of this notification is ZNULL.
 */
#define MtcWgwConnectDidFailNotification "MtcWgwConnectDidFailNotification"

/**
 * @brief Posted when send data OK.
 *
 * The pcInfo of this notification is ZNULL.
 */
#define MtcWgwSendDataOkNotification "MtcWgwSendDataOkNotification"

/**
 * @brief Posted when send data failed.
 *
 * The pcInfo of this notification is ZNULL.
 */
#define MtcWgwSendDataDidFailNotification "MtcWgwSendDataDidFailNotification"

/**
 * @brief Posted when receive data OK.
 *
 * The pcInfo of this notification is an array of string.
 */
#define MtcWgwRecvDataOkNotification "MtcWgwRecvDataOkNotification"

/**
 * @brief Posted when data received.
 *
 * The pcInfo of this notification contains
 * @ref MtcWgwInstanceIdKey, @ref MtcWgwUsernameKey and @ref MtcWgwDataKey.
 */
#define MtcWgwDataRecvedNotification "MtcWgwDataRecvedNotification"

/**
 * @brief Posted when receive data failed.
 *
 * The pcInfo of this notification is ZNULL.
 */
#define MtcWgwRecvDataDidFailNotification "MtcWgwRecvDataDidFailNotification"

/**
 * @brief Posted when receive data.
 *
 * The pcInfo of this notification is an array of string.
 */
#define MtcWgwDataReceivedNotification "MtcWgwDataReceivedNotification"

/**
 * @brief Posted when notify fail event success.
 *
 * The pcInfo of this notification is ZNULL.
 */
#define MtcWgwNotifyOkNotification "MtcWgwNotifyOkNotification"

/**
 * @brief Posted when notify fail event failed.
 *
 * The pcInfo of this notification is ZNULL.
 */
#define MtcWgwNotifyDidFailNotification "MtcWgwNotifyDidFailNotification"

/**
 * @brief Posted when keepalive ok.
 *
 * The pcInfo of this notification is ZNULL.
 */
#define MtcWgwKeepAliveOkNotification "MtcWgwKeepAliveOkNotification"

/**
 * @brief Posted when keepalive failed.
 *
 * The pcInfo of this notification contains @ref MtcWgwFailReasonKey.
 */
#define MtcWgwKeepAliveDidFailNotification "MtcWgwKeepAliveDidFailNotification"

/**
 * @brief Posted when peer disconnected.
 *
 * The pcInfo of this notification contains @ref MtcWgwUsernameKey.
 */
#define MtcWgwPeerDisconnectedNotification "MtcWgwPeerDisconnectedNotification"

/** @} */

#ifdef __cplusplus
EXPORT_FLAG {
#endif

/**
 * @brief MTC notify WebRTC server join conf ok event.
 *
 * @param  zCookie Cookie.
 * @param  pcServiceId The service ID.
 * @param  pcSessId The session ID, use conference number for conference.
 * @param  pcInstanceId Instance ID string.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 */
MTCFUNC ZINT Mtc_WgwConnect(ZCOOKIE zCookie, ZCONST ZCHAR *pcServiceId,
    ZCONST ZCHAR *pcSessId, ZCONST ZCHAR *pcInstanceId);

/**
 * @brief MTC destroy session.
 */
MTCFUNC ZVOID Mtc_WgwDisconnect(ZFUNC_VOID);

/**
 * @brief MTC send data to peer.
 *
 * @param  zCookie Cookie.
 * @param  pcData Data string.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 */
MTCFUNC ZINT Mtc_WgwSend(ZCOOKIE zCookie, ZCONST ZCHAR *pcData);

/**
 * @brief MTC receive data from peer.
 *
 * @param  zCookie Cookie.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 */
MTCFUNC ZINT Mtc_WgwRecv(ZCOOKIE zCookie);

/**
 * @brief MTC notify WebRTC server join conf fail event.
 *
 * @param  zCookie Cookie.
 * @param  pcServiceId The service ID.
 * @param  pcSessId conf ID if conf exist, empty for other fail.
 * @param  pcInstanceId Instance ID string.
 * @param  pcReason fail reason.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 */
MTCFUNC ZINT Mtc_WgwNotify(ZCOOKIE zCookie, ZCONST ZCHAR *pcServiceId,
    ZCONST ZCHAR * pcSessId, ZCONST ZCHAR *pcInstanceId, ZCONST ZCHAR *pcReason);

/**
 * @brief MTC notify keepalive to webrtc.
 *
 * @param  zCookie Cookie.
 *
 * @retval ZOK on successfully.
 * @retval ZFAILED on failed.
 */
MTCFUNC ZINT Mtc_WgwKeepAlive(ZCOOKIE zCookie);

#ifdef __cplusplus
}
#endif

#endif
