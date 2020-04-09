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
  File name     : mtc_cli_db.h
  Module        : multimedia talk client
  Author        : leo.lv
  Created on    : 2010-02-06
  Description   :
      Data structure and function declare required by MTC client database.

  Modify History:
  1. Date:        Author:         Modification:
*************************************************/
#ifndef _MTC_CLI_DB_H__
#define _MTC_CLI_DB_H__

#include "mtc_def.h"

/**
 * @file
 * @brief MTC Conference Interfaces
 *
 * This file includes session and conference interface function.
 */
#ifdef __cplusplus
extern "C" {
#endif

/** @brief The router first conn protocol type. */
typedef enum EN_MTC_CLI_DB_ROUTER_FIRSTCONN_TYPE
{
    EN_MTC_CLI_DB_ROUTER_FIRSTCONN_UDP    = 0x00, /**<@brief udp. */
    EN_MTC_CLI_DB_ROUTER_FIRSTCONN_TCP,  /**<@brief tcp. */
    EN_MTC_CLI_DB_ROUTER_FIRSTCONN_HTTP  /**<@brief http. */
} EN_MTC_CLI_DB_ROUTER_FIRSTCONN_TYPE;

/** @brief The router path select algo type. */
typedef enum EN_MTC_CLI_DB_ROUTER_PATHALGO_TYPE
{
    EN_MTC_CLI_DB_ROUTER_PATHALGO_INTERVALBEST    = 0x00, /**<@brief interval best. */
    EN_MTC_CLI_DB_ROUTER_PATHALGO_ALLTIMEBEST,  /**<@brief all time best. */
} EN_MTC_CLI_DB_ROUTER_PATHALGO_TYPE;

/** @brief MTC sts upload type */
typedef enum EN_MTC_CLI_DB_STSUPLOAD_TYPE
{
    EN_MTC_CLI_DB_STSUPLOAD_NORMAL = 0,
    EN_MTC_CLI_DB_STSUPLOAD_ALILOG
} EN_MTC_CLI_DB_STSUPLOAD_TYPE;

#ifdef __cplusplus
}
#endif

/**
 * @file mtc_cli_db.h
 * @brief MTC Client Database Interface Functions.
 */
#ifdef __cplusplus
EXPORT_FLAG {
#endif

/**
 * @brief Apply all data change to all components.
 *
 * @retval ZOK Apply data change successfully.
 * @retval ZFAILED Apply data change failed.
 */
MTCFUNC ZINT Mtc_CliDbApplyAll(ZFUNC_VOID);

/**
 * @brief Get data change apply flag.
 *
 * @return Data change apply flag.
 *
 * @see @ref Mtc_CliDbSetApplyChange
 */
MTCFUNC ZBOOL Mtc_CliDbGetApplyChange(ZFUNC_VOID);

/**
 * @brief Set data change apply flag realtime.
 *
 * @retval ZOK Set data change apply flag successfully.
 * @retval ZFAILED Set data change apply flag failed.
 *
 * @see @ref Mtc_CliDbGetApplyChange
 */
MTCFUNC ZINT Mtc_CliDbSetApplyChange(ZBOOL bApply);

/**
 * @brief Get data HTTP proxy.
 *
 * @return Data HTTP proxy.
 *
 * @see @ref Mtc_CliDbSetHttpProxy
 */
MTCFUNC ZCONST ZCHAR * Mtc_CliDbGetHttpProxy(ZFUNC_VOID);

/**
 * @brief Set data HTTP proxy realtime.
 *
 * @retval ZOK Set data HTTP proxy successfully.
 * @retval ZFAILED Set data HTTP proxy failed.
 *
 * @see @ref Mtc_CliDbGetHttpProxy
 */
MTCFUNC ZINT Mtc_CliDbSetHttpProxy(ZCONST ZCHAR *pcProxy);

/**
 * @brief Get DNS local listen port from database.
 *
 * @return The DNS local listen port.
 *
 * @see @ref Mtc_CliDbSetDnsLclPort
 */
MTCFUNC ZUINT Mtc_CliDbGetDnsLclPort(ZFUNC_VOID);

/**
 * @brief Set DNS local listen port.
 *
 * @param [in] iPort DNS local listen port.
 *
 * @retval ZOK Set DNS local listen port successfully.
 * @retval ZFAILED Set DNS local listen port failed.
 *
 * @see @ref Mtc_CliDbGetDnsLclPort
 */
MTCFUNC ZINT Mtc_CliDbSetDnsLclPort(ZUINT iPort);

/**
 * @brief Get DNS primary or secondary server IP from database.
 *
 * @param [in] bPrimary DNS primary option.
 *
 * @return The DNS primary or secondary server IP.
 *
 * @see @ref Mtc_CliDbSetDnsServIp
 */
MTCFUNC ZUINT Mtc_CliDbGetDnsServIp(ZBOOL bPrimary);

/**
 * @brief Set DNS primary or secondary server IP.
 *
 * @param [in] bPrimary DNS primary option.
 * @param [in] iServIp DNS primary or secondary server IP.
 *
 * @retval ZOK Set DNS primary or secondary server IP successfully.
 * @retval ZFAILED Set DNS primary or secondary server IP failed.
 *
 * @see @ref Mtc_CliDbGetDnsServIp
 */
MTCFUNC ZINT Mtc_CliDbSetDnsServIp(ZBOOL bPrimary, ZUINT iServIp);

/**
 * @brief Get DNS primary or secondary server port from database.
 *
 * @param [in] bPrimary DNS primary option.
 *
 * @return The DNS primary or secondary server port.
 *
 * @see @ref Mtc_CliDbSetDnsServPort
 */
MTCFUNC ZUINT Mtc_CliDbGetDnsServPort(ZBOOL bPrimary);

/**
 * @brief Set DNS primary or secondary server port.
 *
 * @param [in] bPrimary DNS primary option.
 * @param [in] iPort DNS primary or secondary server port.
 *
 * @retval ZOK Set DNS primary or secondary server port successfully.
 * @retval ZFAILED Set DNS primary or secondary server port failed.
 *
 * @see @ref Mtc_CliDbGetDnsServPort
 */
MTCFUNC ZINT Mtc_CliDbSetDnsServPort(ZBOOL bPrimary, ZUINT iPort);

/**
 * @brief Get DNS use google dns server flag from local database.
 *
 * @return The DNS use google dns server flag.
 *
 * @see @ref Mtc_CliDbSetDnsUseGoogle
 */
MTCFUNC ZBOOL Mtc_CliDbGetDnsUseGoogle(ZFUNC_VOID);

/**
 * @brief Set DNS use google dns server flag.
 *
 * @param [in] bUse The DNS use google dns server flag.
 *             ZTRUE for using google public dns server as second DNS server.
 *             ZFALSE for not use.
 *
 * @retval ZOK Set DNS use google dns server flag successfully.
 * @retval ZFAILED Set DNS use google dns server flag failed.
 *
 * @see @ref Mtc_CliDbGetDnsUseGoogle
 */
MTCFUNC ZINT Mtc_CliDbSetDnsUseGoogle(ZBOOL bUse);

/**
 * @brief Get data Host Maps.
 *
 * @return Data Host Maps.
 *
 * @see @ref Mtc_CliDbSetHostMaps
 */
MTCFUNC ZCONST ZCHAR * Mtc_CliDbGetHostMaps(ZFUNC_VOID);

/**
 * @brief Set data Host Maps.
 *
 * @retval ZOK Set data Host Maps successfully.
 * @retval ZFAILED Set data Host Maps failed.
 *
 * @see @ref Mtc_CliDbGetHostMaps
 */
MTCFUNC ZINT Mtc_CliDbSetHostMaps(ZCONST ZCHAR *pcHostMaps);

/**
 * @brief Get first connect type.
 *
 * @return Data First connect type.
 *
 * @see @ref Mtc_CliDbSetFirstConnType
 */
MTCFUNC ZUINT Mtc_CliDbGetFirstConnType(ZFUNC_VOID);

/**
 * @brief Set first connect type.
 *
 * @param [in] iFirstConnType The first connect protocol type.
 *
 * @retval ZOK Set type successfully.
 * @retval ZFAILED Set type failed.
 *
 * @see @ref Mtc_CliDbGetFirstConnType
 */
MTCFUNC ZINT Mtc_CliDbSetFirstConnType(ZUINT iFirstConnType);

/**
 * @brief Get use statistics mod enable.
 *
 * @return Stsc used flag.
 *
 * @see @ref Mtc_CliDbSetStsEnable
 */
MTCFUNC ZBOOL Mtc_CliDbGetStsEnable(ZFUNC_VOID);

/**
 * @brief Set use statistics mod enable.
 *
 * @retval ZOK Set stsc enable flag successfully.
 * @retval ZFAILED Set stsc enable flag failed.
 *
 * @see @ref Mtc_CliDbGetStsEnable
 */
MTCFUNC ZINT Mtc_CliDbSetStsEnable(ZBOOL bEnable);

/**
 * @brief Get use statistics login enable.
 *
 * @return Stsc used flag.
 *
 * @see @ref Mtc_CliDbSetStsLoignEnable
 */
MTCFUNC ZBOOL Mtc_CliDbGetStsLoginEnable(ZFUNC_VOID);

/**
 * @brief Set use statistics login enable.
 *
 * @retval ZOK Set stsc enable flag successfully.
 * @retval ZFAILED Set stsc enable flag failed.
 *
 * @see @ref Mtc_CliDbGetStsLoginEnable
 */
MTCFUNC ZINT Mtc_CliDbSetStsLoginEnable(ZBOOL bEnable);

/*
 * @brief Get statistics upload type.
 *
 * @retval The statistics upload type
 *
 * @see @ref Mtc_CliDbSetStsUploadType
 */
MTCFUNC ZUINT Mtc_CliDbGetStsUploadType(ZFUNC_VOID);

/**
 * @brief Set statistics upload type.
 *
 * @param [in] iType The statistics upload type @ref EN_MTC_CLI_DB_STSUPLOAD_TYPE.
 *
 * @retval ZOK Set the option successfully.
 * @retval ZFAILED Set the option option failed.
 *
 * @see @ref Mtc_CliDbGetStsUploadType
 */
MTCFUNC ZINT Mtc_CliDbSetStsUploadType(ZUINT iType);

/**
 * @brief Get get apply data async dns flag.
 *
 * @return async dns flag.
 *
 * @see @ref Mtc_CliDbSetAsyncDns
 */
MTCFUNC ZBOOL Mtc_CliDbGetAsyncDns(ZFUNC_VOID);

/**
 * @brief Set get apply data async dns flag.
 *
 * @retval ZOK Set async dns flag successfully.
 * @retval ZFAILED Set async dns flag failed.
 *
 * @see @ref Mtc_CliDbGetAsyncDns
 */
MTCFUNC ZINT Mtc_CliDbSetAsyncDns(ZBOOL bAsyncDns);

/**
 * @brief Get path select algo type.
 *
 * @return path select algo type.
 *
 * @see @ref Mtc_CliDbSetPathAlgoType
 */
MTCFUNC ZUINT Mtc_CliDbGetPathAlgoType(ZFUNC_VOID);

/**
 * @brief Set path select algo type.
 *
 * @param [in] iType The path select algo type.
 *
 * @retval ZOK Set type successfully.
 * @retval ZFAILED Set type failed.
 *
 * @see @ref Mtc_CliDbGetPathAlgoType
 */
MTCFUNC ZINT Mtc_CliDbSetPathAlgoType(ZUINT iType);

/**
 * @brief Get get always work mode flag.
 *
 * @return always work mode flag.
 *
 * @see @ref Mtc_CliDbSetAlwaysWorkMode
 */
MTCFUNC ZBOOL Mtc_CliDbGetAlwaysWorkMode(ZFUNC_VOID);

/**
 * @brief Set get always work mode flag.
 *
 * @retval ZOK Set always work mode flag successfully.
 * @retval ZFAILED Set always work mode flag failed.
 *
 * @see @ref Mtc_CliDbGetAlwaysWorkMode
 */
MTCFUNC ZINT Mtc_CliDbSetAlwaysWorkMode(ZBOOL bEnable);

/**
 * @brief Get force login session flag.
 *
 * @return force login session flag.
 *
 * @see @ref Mtc_CliDbSetForceLogin
 */
MTCFUNC ZBOOL Mtc_CliDbGetForceLogin(ZFUNC_VOID);

/**
 * @brief Set force login session flag realtime.
 *
 * @retval ZOK Set force login session flag successfully.
 * @retval ZFAILED Set force login session failed.
 *
 * @see @ref Mtc_CliDbGetForceLogin
 */
MTCFUNC ZINT Mtc_CliDbSetForceLogin(ZBOOL bEnable);

/**
 * @brief Get alwasys try registerAlive flag.
 *
 * @return alwasys try registerAlive flag.
 *
 * @see @ref Mtc_CliDbSetAlwaysTryAlive
 */
MTCFUNC ZBOOL Mtc_CliDbGetAlwaysTryAlive(ZFUNC_VOID);

/**
 * @brief Set alwasys try registerAlive realtime.
 *
 * @retval ZOK Set alwasys try registerAlive successfully.
 * @retval ZFAILED Set alwasys try registerAlive failed.
 *
 * @see @ref Mtc_CliDbGetAlwaysTryAlive
 */
MTCFUNC ZINT Mtc_CliDbSetAlwaysTryAlive(ZBOOL bEnable);

/**
 * @brief Get tls only flag.
 *
 * @return tls only flag.
 *
 * @see @ref Mtc_CliDbSetTlsOnly
 */
MTCFUNC ZBOOL Mtc_CliDbGetTlsOnly(ZFUNC_VOID);

/**
 * @brief Set tls only flag.
 *
 * @retval ZOK Set tls only successfully.
 * @retval ZFAILED Set tls only failed.
 *
 * @see @ref Mtc_CliDbGetTlsOnly
 */
MTCFUNC ZINT Mtc_CliDbSetTlsOnly(ZBOOL bEnable);

/**
 * @brief Get common mtu.
 *
 * @return common mtu.
 *
 * @see @ref Mtc_CliDbSetCommonMtuSize
 */
MTCFUNC ZBOOL Mtc_CliDbGetCommonMtuSize(ZFUNC_VOID);

/**
 * @brief Set common mtu.
 *
 * @retval ZOK Set value successfully.
 * @retval ZFAILED Set value failed.
 *
 * @see @ref Mtc_CliDbGetCommonMtuSize
 */
MTCFUNC ZINT Mtc_CliDbSetCommonMtuSize(ZUINT iMtu);

/*
 * @brief Set set root der data.
 *
 * @param [in] pcRootData The root data.
 *
 * @retval ZOK Set root data successfully.
 * @retval ZFAILED Set root data failed.
 *
 * @see @ref Mtc_CliDbGetRootDerData
 */
MTCFUNC ZINT Mtc_CliDbSetRootDerData(ZCONST ZCHAR *pcRootData);

/**
 * @brief Get root der data.
 *
 * @return Root der data.
 *
 * @see @ref Mtc_CliDbSetRootDerData
 */
MTCFUNC ZCONST ZCHAR * Mtc_CliDbGetRootDerData(ZFUNC_VOID);

/*
 * @brief Set set trust cert data.
 *
 * @param [in] pcCertName The cert name.
 * @param [in] pcCertData The cert data.
 *
 * @retval ZOK Set root data successfully.
 * @retval ZFAILED Set root data failed.
 *
 * @see @ref Mtc_CliDbGetTrustCert
 */
MTCFUNC ZINT Mtc_CliDbSetTrustCert(ZCONST ZCHAR *pcCertName, ZCONST ZCHAR * pcCertData);

/**
 * @brief Get root der data.
 * 
 * @param [in] pcCertName The cert name.
 *
 * @return Root der data.
 *
 * @see @ref Mtc_CliDbSetTrustCert
 */
MTCFUNC ZCONST ZCHAR * Mtc_CliDbGetTrustCert(ZCONST ZCHAR *pcCertName);

#ifdef __cplusplus
}
#endif

#endif /* _MTC_CLI_DB_H__ */
