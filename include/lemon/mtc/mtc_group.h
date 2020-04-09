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
  File name     : mtc_group.h
  Module        : multimedia talk client
  Author        : Junjie Wang
  Created on    : 2016-08-23
*************************************************/
#ifndef _MTC_GROUP_H__
#define _MTC_GROUP_H__

#include "mtc_def.h"

/**
 * @file mtc_group.h
 * @brief MTC Group Interface Functions
 *
 * This file includes group interface function.
 */

/** @brief Failure reasons. */
typedef enum EN_MTC_GROUP_REASON_TYPE
{
    EN_MTC_GROUP_REASON_BASE = 2000,                  /**< @brief Base of reason number. */
    EN_MTC_GROUP_REASON_GET_AGENT,                    /**< @brief Internal error get agent failed. */
    EN_MTC_GROUP_REASON_SERVER,                       /**< @brief Server error. */
    EN_MTC_GROUP_REASON_SERVER_UPDATE_TIME_INVALID,   /**< @brief Server error update time invalid. */
    EN_MTC_GROUP_REASON_SERVER_PERMISSION_DENIED,     /**< @brief Server error permission denied. */
    EN_MTC_GROUP_REASON_SERVER_UID_NOT_FOUND,         /**< @brief Server error uid is not found. */
    EN_MTC_GROUP_REASON_SERVER_CHANGE_NOT_EXISTS,     /**< @brief Server error change relation that not exists. */
    EN_MTC_GROUP_REASON_SERVER_ADD_ALREADY_EXISTS,    /**< @brief Server error add relation that already exists. */
    EN_MTC_GROUP_REASON_SERVER_ADD_SELF,              /**< @brief Server error add self. */
    EN_MTC_GROUP_REASON_SERVER_RELATION_TYPE_INVALID, /**< @brief Server error relation type invalid. */
    EN_MTC_GROUP_REASON_SERVER_REMOVE_NOT_EXIST,      /**< @brief Server error remove relation that not exists. */
    EN_MTC_GROUP_REASON_SERVER_STATUS_TYPE_INVALID,   /**< @brief Server error status type invalid. */
    EN_MTC_GROUP_REASON_SERVER_WRITE_OWNER_ERROR,     /**< @brief Server error only one owner in group. */
    EN_MTC_GROUP_REASON_SERVER_SET_WRITE_PROP,        /**< @brief Server error try to set write only prop. */
    EN_MTC_GROUP_REASON_SERVER_APPLY_TYPE_GRANTED,    /**< @brief Server error apply type granted. */
    EN_MTC_GROUP_REASON_SERVER_LACK_OF_ORG_NAME,      /**< @brief Server error lack of org name. */
    EN_MTC_GROUP_REASON_SERVER_UNKNOW_ORG_TYPE,       /**< @brief Server error unknow org type. */
    EN_MTC_GROUP_REASON_SERVER_OWNER_NOT_INVOKER,     /**< @brief Server error not assign self as owner. */
    EN_MTC_GROUP_REASON_SERVER_NOT_IN_GROUP,     /**< @brief Server error not in relation list of target. */
    EN_MTC_GROUP_REASON_SERVER_BLACKLIST,        /**< @brief Server error block by blacklist. */
    EN_MTC_GROUP_REASON_SERVER_CAPACITY_FULL,     /**< @brief Server error capacity of the group is full. */
    EN_MTC_GROUP_REASON_SERVER_NOT_BELOG_OT_ORG,     /**< @brief Server error caller not belong to the group. */
    EN_MTC_GROUP_REASON_SERVER_WRITE_EXCEED_RIGHT,     /**< @brief Server error try to change the member who has higher level . */
    EN_MTC_GROUP_REASON_QUERY_UID,         /**< @brief Query UID failed. */
} EN_MTC_GROUP_REASON_TYPE;

/** @brief Group type. */
typedef enum EN_MTC_GROUP_TYPE
{
    EN_MTC_GROUP_DISCUSSION = 0,            /**< @brief Discussion group. */
    EN_MTC_GROUP_NORMAL,                    /**< @brief Normal group. */
    EN_MTC_GROUP_LARGE,                     /**< @brief Group contains large number of members. */
    EN_MTC_GROUP_ROOM,                      /**< @brief Temporary group. */
    EN_MTC_GROUP_LARGE_ROOM                 /**< @brief Temporary group contains large number of members. */
} EN_MTC_GROUP_TYPE;

/** @brief Type of how to get updated information of group. */
typedef enum EN_MTC_GROUP_UPATE_METHOD_TYPE
{
    EN_MTC_GROUP_NOTIFICATION = 0,   /**< @brief Server initiates a notification when changed. */
    EN_MTC_GROUP_FETCH,              /**< @brief Client fetch information. */
    EN_MTC_GROUP_MIXED               /**< @brief Use mixing methods. */
} EN_MTC_GROUP_UPATE_METHOD_TYPE;

/** @brief Permission control type of join into the group. */
typedef enum EN_MTC_GROUP_PERMISSION_TYPE
{
    EN_MTC_GROUP_ADMIN_AUTHORIZATION = 0,   /**< @brief Requires authorization by manager or owner of group. */
    EN_MTC_GROUP_MEMBER_AUTHORIZATION,      /**< @brief Requires authorization by member of group. */
    EN_MTC_GROUP_NO_CONTROL,                /**< @brief No permission control. */
    EN_MTC_GROUP_PASSWORD                   /**< @brief Requires password. */
} EN_MTC_GROUP_PERMISSION_TYPE;

/** @brief Relation type. */
typedef enum EN_MTC_GROUP_RELATION_TYPE
{
    EN_MTC_GROUP_RELATION_IN_GROUP = 0x100,
    EN_MTC_GROUP_RELATION_OWNER,            /**< @brief Owner. */
    EN_MTC_GROUP_RELATION_MANAGER,          /**< @brief Manager. */
    EN_MTC_GROUP_RELATION_MEMBER,           /**< @brief Member. */

    EN_MTC_GROUP_RELATION_WITH_GROUP = 0x1000,
    EN_MTC_GROUP_RELATION_BELONGS_TO,       /**< @brief Belongs to group. */
} EN_MTC_GROUP_RELATION_TYPE;

/** @brief Resource ID type. */
typedef enum EN_MTC_GROUP_RESOURCE_ID_TYPE
{
    EN_MTC_GROUP_RESOURCE_ID_GROUP = 0,     /**< @brief Type for Group ID. */
    EN_MTC_GROUP_RESOURCE_ID_URI,           /**< @brief Type for User ID. */
    EN_MTC_GROUP_RESOURCE_ID_OTHER = 100,   /**< @brief Type for other id. */
} EN_MTC_GROUP_RESOURCE_ID_TYPE;

/** @brief Property permission type. */
typedef enum EN_MTC_GROUP_PROPERTY_CONTROL_TYPE
{
    EN_MTC_GROUP_PROPERTY_CONTROL_OWNER = 0,     /**< @brief Only writeable to owner. */
    EN_MTC_GROUP_PROPERTY_CONTROL_MANAGER,       /**< @brief Writeable to manager and owner. */
    EN_MTC_GROUP_PROPERTY_CONTROL_MEMBER,        /**< @brief Writeable to all members. */
} EN_MTC_GROUP_PROPERTY_CONTROL_TYPE;

/**
 * @defgroup MtcGroupPropKey Keys for property of group.
 * @{
 */

/**
 * @brief A key whose value is string object reflecting
 * the name of group.
 */
#define MtcGroupPropNameKey "Name"

/**
 * @brief A key whose value is number object reflecting
 * the type of group, @ref EN_MTC_GROUP_TYPE.
 */
#define MtcGroupPropTypeKey "Type"

/**
 * @brief A key whose value is number object reflecting
 * the type of how to get updated information of group,
 * @ref EN_MTC_GROUP_UPATE_METHOD_TYPE.
 */
#define MtcGroupPropUpdateMethodKey "UpdateMethod"

/**
 * @brief A key whose value is number object reflecting
 * the permission control type of join into the group,
 * @ref EN_MTC_GROUP_PERMISSION_TYPE.
 */
#define MtcGroupPropPermissionKey "Permission"

/**
 * @brief A key whose value is number object reflecting
 * the write permission level of group property,
 * @ref EN_MTC_GROUP_PROPERTY_CONTROL_TYPE.
 */
#define MtcGroupPropControlKey "PropertyControl"

/**
 * @}
 */

/**
 * @defgroup MtcGroupKey MTC notification key for group.
 * @{
 */

/**
 * @brief A key whose value is a number object reflecting
 * the failure reason, @ref EN_MTC_GROUP_REASON_TYPE.
 */
#define MtcGroupReasonCodeKey "ReasonCode"

/**
 * @brief A key whose value is a string object reflecting
 * the failure details.
 */
#define MtcGroupReasonDetailKey "ReasonDetail"

/**
 * @brief A key whose value is a object contains
 * the properties of group, @ref MtcGroupPropKey.
 */
#define MtcGroupPropertiesKey "Properties"

/**
 * @brief A key whose value is number object indicates
 * the type of resource ID @ref EN_MTC_GROUP_RESOURCE_ID_TYPE.
 */
#define MtcGroupRidTypeKey "RidType"

/**
 * @brief A key whose value is a string object reflecting
 * the id of a group.
 */
#define MtcGroupRidKey "Rid"

/**
 * @brief A key whose value is a string object reflecting
 * the UID of a user.
 */
#define MtcGroupUserUidKey "UserUid"

/**
 * @brief A key whose value is a string object reflecting
 * the user uri.
 */
#define MtcGroupUserUriKey "UserUri"

/**
 * @brief A key whose value is a list of relation objects
 * that representing relations.
 * Each object contains several fields:
 * Required: @ref MtcGroupRelationTypeKey, @ref MtcGroupRidTypeKey, @ref MtcGroupRidKey, @ref MtcGroupDisplayNameKey.
 * Optional: @ref MtcGroupTagKey.
 */
#define MtcGroupRelationListKey "RelationList"

/**
 * @brief A key whose value is a list of relation objects
 * that representing new added relations.
 * Each object contains several fields:
 * Required: @ref MtcGroupRelationTypeKey, @ref MtcGroupRidTypeKey, @ref MtcGroupRidKey, @ref MtcGroupDisplayNameKey.
 * Optional: @ref MtcGroupTagKey.
 */
#define MtcGroupAddedRelationListKey "AddedRelationList"

/**
 * @brief A key whose value is a list of relation objects
 * that representing changed relations.
 * Each object contains several fields:
 * Required: @ref MtcGroupRelationTypeKey, @ref MtcGroupRidTypeKey, @ref MtcGroupRidKey, @ref MtcGroupDisplayNameKey.
 * Optional: @ref MtcGroupTagKey.
 */
#define MtcGroupUpdatedRelationListKey "UpdatedRelationList"

/**
 * @brief A key whose value is a list of string objects
 * that representing removed uids
 */
#define MtcGroupRemovedRelationListKey "RemovedRelationList"

/**
 * @brief A key whose value is a relation objects
 * that representing changed relations.
 * Required: @ref MtcGroupRelationTypeKey, @ref MtcGroupRidTypeKey, @ref MtcGroupRidKey, @ref MtcGroupDisplayNameKey.
 * Optional: @ref MtcGroupTagKey.
 */
#define MtcGroupUpdatedRelationKey "MtcGroupUpdatedRelationKey"

/**
 * @brief A key whose value is a array of relation objects
 * that representing new added relations.
 * Each object contains several fields:
 * @ref MtcGroupRelationTypeKey, @ref MtcGroupUserUriKey, @ref MtcGroupDisplayNameKey, @ref MtcGroupTagKey.
 */
#define MtcGroupListToAddKey "ListToAdd"

/**
 * @brief A key whose value is a array of relation objects
 * that representing changed relations.
 * Each object contains several fields:
 * @ref MtcGroupRelationTypeKey, @ref MtcGroupUriKey, @ref MtcGroupDisplayNameKey, @ref MtcGroupTagKey.
 */
#define MtcGroupListToUpdateKey "ListToUpdate"

/**
 * @brief A key whose value is a array of string objects
 * that representing removed URIs.
 */
#define MtcGroupListToRemoveKey "ListToRemove"

/**
 * @brief A key whose value is a list of relation objects
 * that representing relations.
 * Each object contains several fields:
 * @ref MtcGroupRidTypeKey, @ref MtcGroupRidKey,
 * and other key value set by Mtc_GroupSetRelationStatus.
 */
#define MtcGroupStatusListKey "StatusList"

/**
 * @brief A key whose value is an integer reflecting
 * the relation type of a relation, @ref EN_MTC_GROUP_RELATION_TYPE
 */
#define MtcGroupRelationTypeKey "RelationType"

/**
 * @brief A key whose value is an integer object reflecting
 * the update time of server change.
 */
#define MtcGroupUpdateTimeKey "UpdateTime"

/**
 * @brief A key whose value is an string object reflecting
 * the system message invoker uid.
 */
#define MtcGroupInvokerUidKey "InvokerUid"

/**
 * @brief A key whose value is an integer object reflecting
 * the base time of server change.
 */
#define MtcGroupBaseTimeKey "BaseTime"

/**
 * @brief A key whose value is an integer object reflecting
 * the  time of server change.
 */
#define MtcGroupServerTimeKey "ServerTime"

/**
 * @brief A key whose value is an boolean object reflecting
 * the update information is full or partial.
 */
#define MtcGroupIsPartialUpdateKey "IsPartialUpdate"

/**
 * @brief A key whose value is a string object reflecting
 * the display name of a relation.
 */
#define MtcGroupDisplayNameKey "DisplayName"

/**
 * @brief A key whose value is a string object reflecting
 * the id of inviter.
 */
#define MtcGroupInviterIdKey "InviterId"

/**
 * @brief A key whose value is a string object reflecting
 * the name of inviter.
 */
#define MtcGroupInviterNameKey "InviterName"

/**
 * @brief A key whose value is a string object reflecting
 * the tag of a relation.
 */
#define MtcGroupTagKey "Tag"

/**
 * @brief A key whose value is a string object reflecting
 * the ImPush of a relation, "T"/"F".
 */
#define MtcGroupImPushKey "ImPush"

/**
 * @brief A key whose value is a number object reflecting
 * the unique ID of a group apply.
 */
#define MtcGroupApplyIdKey "ApplyId"

/**
 * @brief A key whose value is a bool object reflecting
 * the result of a group apply.
 */
#define MtcGroupApplyResultKey "ApplyResult"

/**
 * @brief A key whose value is a string object reflecting
 * the description of a group apply.
 */
#define MtcGroupApplyDescriptionKey "Description"

/** @} */

/**
 * @defgroup MtcGroupNotification MTC notification names for group.
 * @{
 */

/**
 * @brief Posted when create successfully.
 *
 * The pcInfo of this notification contains @ref MtcGroupRidTypeKey, @ref MtcGroupRidKey,
 * @ref MtcGroupPropertiesKey @ref MtcGroupBaseTimeKey, @ref MtcGroupUpdateTimeKey.
 */
#define MtcGroupCreateOkNotification "MtcGroupCreateOkNotification"

/**
 * @brief Posted when failed to create.
 *
 * The pcInfo of this notification contains @ref MtcGroupRidTypeKey, @ref MtcGroupRidKey,
 * @ref MtcGroupReasonCodeKey, @ref MtcGroupReasonDetailKey.
 */
#define MtcGroupCreateDidFailNotification "MtcGroupCreateDidFailNotification"

/**
 * @brief Posted when remove successfully.
 *
 * The pcInfo of this notification contains @ref MtcGroupRidTypeKey, @ref MtcGroupRidKey.
 */
#define MtcGroupRemoveOkNotification "MtcGroupRemoveOkNotification"

/**
 * @brief Posted when failed to remove.
 *
 * The pcInfo of this notification contains @ref MtcGroupRidTypeKey, @ref MtcGroupRidKey,
 * @ref MtcGroupReasonCodeKey, @ref MtcGroupReasonDetailKey.
 */
#define MtcGroupRemoveDidFailNotification "MtcGroupRemoveDidFailNotification"

/**
 * @brief Posted when set properties successfully.
 *
 * The pcInfo of this notification contains @ref MtcGroupRidTypeKey, @ref MtcGroupRidKey.
 */
#define MtcGroupSetPropertiesOkNotification "MtcGroupSetPropertiesOkNotification"

/**
 * @brief Posted when failed to set properties.
 *
 * The pcInfo of this notification contains @ref MtcGroupRidTypeKey, @ref MtcGroupRidKey,
 * @ref MtcGroupReasonCodeKey, @ref MtcGroupReasonDetailKey.
 */
#define MtcGroupSetPropertiesDidFailNotification "MtcGroupSetPropertiesDidFailNotification"

/**
 * @brief Posted when get properties successfully.
 *
 * The pcInfo of this notification contains @ref MtcGroupRidTypeKey, @ref MtcGroupRidKey.
 */
#define MtcGroupGetPropertiesOkNotification "MtcGroupGetPropertiesOkNotification"

/**
 * @brief Posted when failed to get properties.
 *
 * The pcInfo of this notification contains @ref MtcGroupRidTypeKey, @ref MtcGroupRidKey,
 * @ref MtcGroupReasonCodeKey, @ref MtcGroupReasonDetailKey.
 */
#define MtcGroupGetPropertiesDidFailNotification "MtcGroupGetPropertiesDidFailNotification"

/**
 * @brief Posted when refresh successfully.
 *
 * The pcInfo of this notification contains @ref MtcGroupUpdateTimeKey,
 * @ref MtcGroupRidTypeKey, @ref MtcGroupRidKey, @ref MtcGroupAddedRelationListKey,
 * @ref MtcGroupUpdatedRelationListKey, @ref MtcGroupRemovedRelationListKey.
 */
#define MtcGroupRefreshOkNotification "MtcGroupRefreshOkNotification"

/**
 * @brief Posted when failed to refresh.
 *
 * The pcInfo of this notification contains @ref MtcGroupRidTypeKey, @ref MtcGroupRidKey,
 * @ref MtcGroupReasonCodeKey, @ref MtcGroupReasonDetailKey.
 */
#define MtcGroupRefreshDidFailNotification "MtcGroupRefreshDidFailNotification"

/**
 * @brief Posted when group list changed.
 *
 * The pcInfo of this notification contains @ref MtcGroupUpdateTimeKey, @ref MtcGroupBaseTimeKey,
 * @ref MtcGroupRidTypeKey, @ref MtcGroupRidKey, @ref MtcGroupAddedRelationListKey,
 * @ref MtcGroupUpdatedRelationListKey, @ref MtcGroupRemovedRelationListKey.
 */
#define MtcGroupChangedNotification "MtcGroupChangedNotification"

/**
 * @brief Posted when add relation successfully.
 *
 * The pcInfo of this notification contains @ref MtcGroupUpdateTimeKey.
 */
#define MtcGroupAddRelationOkNotification "MtcGroupAddRelationOkNotification"

/**
 * @brief Posted when failed to add relation.
 *
 * The pcInfo of this notification contains @ref MtcGroupReasonCodeKey, @ref MtcGroupReasonDetailKey.
 */
#define MtcGroupAddRelationDidFailNotification "MtcGroupAddRelationDidFailNotification"

/**
 * @brief Posted when update relation successfully.
 *
 * The pcInfo of this notification contains @ref MtcGroupUpdateTimeKey.
 */
#define MtcGroupUpdateRelationOkNotification "MtcGroupUpdateRelationOkNotification"

/**
 * @brief Posted when failed to update relation.
 *
 * The pcInfo of this notification contains @ref MtcGroupReasonCodeKey, @ref MtcGroupReasonDetailKey.
 */
#define MtcGroupUpdateRelationDidFailNotification "MtcGroupUpdateRelationDidFailNotification"

/**
 * @brief Posted when remove relation successfully.
 *
 * The pcInfo of this notification contains @ref MtcGroupUpdateTimeKey.
 */
#define MtcGroupRemoveRelationOkNotification "MtcGroupRemoveRelationOkNotification"

/**
 * @brief Posted when failed to remove relation.
 *
 * The pcInfo of this notification contains @ref MtcGroupReasonCodeKey, @ref MtcGroupReasonDetailKey.
 */
#define MtcGroupRemoveRelationDidFailNotification "MtcGroupRemoveRelationDidFailNotification"

/**
 * @brief Posted when set relations successfully.
 *
 * The pcInfo of this notification contains @ref MtcGroupUpdateTimeKey, @ref MtcGroupBaseTimeKey.
 */
#define MtcGroupSetRelationsOkNotification "MtcGroupSetRelationsOkNotification"

/**
 * @brief Posted when failed to set relations.
 *
 * The pcInfo of this notification contains @ref MtcGroupReasonCodeKey, @ref MtcGroupReasonDetailKey.
 */
#define MtcGroupSetRelationsDidFailNotification "MtcGroupSetRelationsDidFailNotification"

/**
 * @brief Posted when set relation status successfully.
 *
 * The pcInfo of this notification contains
 * @ref MtcGroupRidTypeKey,
 * @ref MtcGroupRidKey,
 * @ref MtcGroupUserUidKey.
 */
#define MtcGroupSetRelationStatusOkNotification "MtcGroupSetRelationStatusOkNotification"

/**
 * @brief Posted when failed to set relation status.
 *
 * The pcInfo of this notification contains
 * @ref MtcGroupReasonCodeKey,
 * @ref MtcGroupReasonDetailKey.
 */
#define MtcGroupSetRelationStatusDidFailNotification "MtcGroupSetRelationStatusDidFailNotification"

/**
 * @brief Posted when get relation status successfully.
 *
 * The pcInfo of this notification contains
 * @ref MtcGroupRidTypeKey,
 * @ref MtcGroupRidKey,
 * @ref MtcGroupRelationListKey.
 */
#define MtcGroupGetRelationStatusOkNotification "MtcGroupGetRelationStatusOkNotification"

/**
 * @brief Posted when failed to get relation status.
 *
 * The pcInfo of this notification contains
 * @ref MtcGroupReasonCodeKey,
 * @ref MtcGroupReasonDetailKey.
 */
#define MtcGroupGetRelationStatusDidFailNotification "MtcGroupGetRelationStatusDidFailNotification"

/**
 * @brief Posted when update individual relation successfully.
 *
 * The pcInfo of this notification contains
 * @ref MtcGroupRidTypeKey, @ref MtcGroupRidKey,
 * @ref MtcGroupBaseTimeKey, @ref MtcGroupUpdateTimeKey.
 */
#define MtcGroupUpdateIndividualRelationOkNotification "MtcGroupUpdateIndividualRelationOkNotification"

/**
 * @brief Posted when failed to update individual relation.
 *
 * The pcInfo of this notification contains
 * @ref MtcGroupReasonCodeKey,
 * @ref MtcGroupReasonDetailKey.
**/
#define MtcGroupUpdateIndividualRelationDidFailNotification "MtcGroupUpdateIndividualRelationDidFailNotification"

/**
 * @brief Posted when apply relation successfully.
 *
 * The pcInfo of this notification is ZNULL.
 */
#define MtcGroupApplyRelationOkNotification "MtcGroupApplyRelationOkNotification"

/**
 * @brief Posted when failed to apply relation.
 *
 * The pcInfo of this notification contains
 * @ref MtcGroupReasonCodeKey,
 * @ref MtcGroupReasonDetailKey.
 */
#define MtcGroupApplyRelationDidFailNotification "MtcGroupApplyRelationDidFailNotification"

/**
 * @brief Posted when apply invite successfully.
 *
 * The pcInfo of this notification is ZNULL.
 */
#define MtcGroupInviteRelationOkNotification "MtcGroupInviteRelationOkNotification"

/**
 * @brief Posted when failed to invite relation.
 *
 * The pcInfo of this notification contains
 * @ref MtcGroupReasonCodeKey,
 * @ref MtcGroupReasonDetailKey.
 */
#define MtcGroupInviteRelationDidFailNotification "MtcGroupInviteRelationDidFailNotification"

/**
 * @brief Posted when accept relation successfully.
 *
 * The pcInfo of this notification is ZNULL.
 */
#define MtcGroupAcceptRelationOkNotification "MtcGroupAcceptRelationOkNotification"

/**
 * @brief Posted when failed to accept relation.
 *
 * The pcInfo of this notification contains
 * @ref MtcGroupReasonCodeKey,
 * @ref MtcGroupReasonDetailKey.
 */
#define MtcGroupAcceptRelationDidFailNotification "MtcGroupAcceptRelationDidFailNotification"

/**
 * @brief Posted when refuse relation successfully.
 *
 * The pcInfo of this notification is ZNULL.
 */
#define MtcGroupRefuseRelationOkNotification "MtcGroupRefuseRelationOkNotification"

/**
 * @brief Posted when failed to refuse relation.
 *
 * The pcInfo of this notification contains
 * @ref MtcGroupReasonCodeKey,
 * @ref MtcGroupReasonDetailKey.
 */
#define MtcGroupRefuseRelationDidFailNotification "MtcGroupRefuseRelationDidFailNotification"

/**
 * @brief Posted when receive group apply message.
 *
 * The pcInfo of this notification contains
 * @ref MtcGroupApplyIdKey,
 * @ref MtcGroupRidKey,
 * @ref MtcGroupUserUidKey,
 * @ref MtcGroupRelationTypeKey,
 * @ref MtcGroupDisplayNameKey,
 * @ref MtcGroupServerTimeKey,
 * @ref MtcGroupApplyDescriptionKey.
 */
#define MtcGroupApplyReceivedNotification "MtcGroupApplyReceivedNotification"

/**
 * @brief Posted when receive group apply complete message.
 *
 * The pcInfo of this notification contains
 * @ref MtcGroupApplyIdKey,
 * @ref MtcGroupApplyResultKey.
 * If apply success maybe also contain 
 * @ref MtcGroupUpdateTimeKey,
 * @ref MtcGroupBaseTimeKey,
 * @ref MtcGroupAddedRelationListKey,
 * @ref MtcGroupUpdatedRelationListKey,
 * @ref MtcGroupRemovedRelationListKey,
 * @ref MtcGroupIsPartialUpdateKey.
 */
#define MtcGroupApplyCompletedNotification "MtcGroupApplyCompletedNotification"

/**
 * @brief Posted when Im Push successfully.
 *
 * The pcInfo of this notification contains @ref MtcGroupUpdateTimeKey, @ref MtcGroupBaseTimeKey.
 */
#define MtcGroupImPushOkNotification "MtcGroupImPushOkNotification"

/**
 * @brief Posted when failed to Im Push.
 *
 * The pcInfo of this notification contains
 * @ref MtcGroupReasonCodeKey,
 * @ref MtcGroupReasonDetailKey.
 */
#define MtcGroupImPushDidFailNotification "MtcGroupImPushDidFailNotification"

/** @} */

#ifdef __cplusplus
EXPORT_FLAG {
#endif

/**
 * @brief Create group.
 *
 * @param  zCookie The cookie value.
 * @param  iType The group type, @ref EN_MTC_GROUP_TYPE.
 * @param  pcName The group name.
 * @param  pcInfo The properties information in JSON, @ref MtcGroupPropKey.
 * @param  pcRelationsToAdd The string in JSON, which is an array. Each item must contains
 *                 @ref MtcGroupUserUriKey, @ref MtcGroupRelationTypeKey
 *                 @ref MtcGroupDisplayNameKey, @ref MtcGroupTagKey.
 *
 * @retval ZOK on invoke this interface successfully. The result will notify
 * to user with @ref MtcGroupCreateOkNotification
 * or @ref MtcGroupCreateDidFailNotification.
 * @retval ZFAILED failed
 */
MTCFUNC ZINT Mtc_GroupCreate(ZCOOKIE zCookie, ZUINT iType, ZCONST ZCHAR *pcName,
    ZCONST ZCHAR *pcInfo, ZCONST ZCHAR *pcRelationsToAdd);

/**
 * @brief Remove group.
 *
 * @param  zCookie The cookie value.
 * @param  pcGroupId The group ID.
 *
 * @retval ZOK on invoke this interface successfully. The result will notify
 * to user with @ref MtcGroupRemoveOkNotification
 * or @ref MtcGroupRemoveDidFailNotification.
 * @retval ZFAILED failed
 */
MTCFUNC ZINT Mtc_GroupRemove(ZCOOKIE zCookie, ZCONST ZCHAR *pcGroupId);

/**
 * @brief Update group properties.
 *
 * @param  zCookie The cookie value.
 * @param  pcGroupId The group ID.
 * @param  pcInfo The properties information in JSON, contains
 * @ref MtcGroupPropNameKey, @ref MtcGroupPropPermissionKey
 *
 * @retval ZOK on invoke this interface successfully. The result will notify
 * to user with @ref MtcGroupSetPropertiesOkNotification
 * or @ref MtcGroupSetPropertiesDidFailNotification.
 * @retval ZFAILED failed
 */
MTCFUNC ZINT Mtc_GroupSetProperties(ZCOOKIE zCookie, ZCONST ZCHAR *pcGroupId,
    ZCONST ZCHAR *pcInfo);

/**
 * @brief Get group properties.
 *
 * @param  zCookie The cookie value.
 * @param  pcGroupId The group ID.
 *
 * @retval ZOK on invoke this interface successfully. The result will notify
 * to user with @ref MtcGroupGetPropertiesOkNotification
 * or @ref MtcGroupGetPropertiesDidFailNotification.
 * @retval ZFAILED failed
 */
MTCFUNC ZINT Mtc_GroupGetProperties(ZCOOKIE zCookie, ZCONST ZCHAR *pcGroupId);

/**
 * @brief Refresh all relations
 *
 * @param  zCookie The cookie value.
 * @param  pcGroupId The string of GroupID, ZNULL to refresh self group list.
 * @param  qwUpdateTime The start time point to refresh
 *
 * @retval ZOK on invoke this interface successfully. The result will notify
 * to user with @ref MtcGroupRefreshOkNotification
 * or @ref MtcGroupRefreshDidFailNotification.
 * @retval ZFAILED failed
 */
MTCFUNC ZINT Mtc_GroupRefresh(ZCOOKIE zCookie, ZCONST ZCHAR *pcGroupId,
    ZINT64 qwUpdateTime);

/**
 * @brief Add relation
 *
 * @param  zCookie The cookie value.
 * @param  pcGroupId The string of GroupID, ZNULL to operate on self group list.
 * @param  iRelationType The relation type, @ref EN_MTC_GROUP_RELATION_TYPE
 * @param  pcUri The uri or uid of the user
 * @param  pcDisplayName The display name of the relation
 * @param  pcTag The tag info of the relation that may contains
 *         @ref MtcGroupTagKey
 *
 * @retval ZOK on invoke this interface successfully. The result will notify
 * to user with @ref MtcGroupAddRelationOkNotification
 * or @ref MtcGroupAddRelationDidFailNotification.
 * @retval ZFAILED failed
 */
MTCFUNC ZINT Mtc_GroupAddRelation(ZCOOKIE zCookie, ZCONST ZCHAR *pcGroupId,
    ZUINT iRelationType, ZCONST ZCHAR *pcUri, ZCONST ZCHAR *pcDisplayName,
    ZCONST ZCHAR *pcTag);

/**
 * @brief Update relation
 *
 * @param  zCookie The cookie value.
 * @param  pcGroupId The string of GroupID, ZNULL to operate on self group list.
 * @param  iRelationType The relation type, @ref EN_MTC_GROUP_RELATION_TYPE
 * @param  pcUri The uri or uid of the user
 * @param  pcDisplayName The display name of the relation
 * @param  pcTag The tag info of the relation that may contains
 *         @ref MtcGroupTagKey
 *
 * @retval ZOK on invoke this interface successfully. The result will notify
 * to user with @ref MtcGroupUpdateRelationOkNotification
 * or @ref MtcGroupUpdateRelationDidFailNotification.
 * @retval ZFAILED failed
 */
MTCFUNC ZINT Mtc_GroupUpdateRelation(ZCOOKIE zCookie, ZCONST ZCHAR *pcGroupId,
    ZUINT iRelationType, ZCONST ZCHAR *pcUri, ZCONST ZCHAR *pcDisplayName,
    ZCONST ZCHAR *pcTag);

/**
 * @brief Remove relation
 *
 * @param  zCookie The cookie value.
 * @param  pcGroupId The string of GroupID, ZNULL to operate on self group list.
 * @param  pcUri The uri or uid of the user
 *
 * @retval ZOK on invoke this interface successfully. The result will notify
 * to user with @ref MtcGroupRemoveRelationOkNotification
 * or @ref MtcGroupRemoveRelationDidFailNotification.
 * @retval ZFAILED failed
 */
MTCFUNC ZINT Mtc_GroupRemoveRelation(ZCOOKIE zCookie, ZCONST ZCHAR *pcGroupId,
    ZCONST ZCHAR *pcUri);

/**
 * @brief Set batch relations
 *
 * @param  zCookie The cookie value.
 * @param  pcGroupId The string of GroupID, ZNULL to operate on self group list.
 * @param  pcInfo The string in JSON, which contains
    @ref MtcGroupListToAddKey, @ref MtcGroupListToUpdateKey, @ref MtcGroupListToRemoveKey.
 *
 * @retval ZOK on invoke this interface successfully. The result will notify
 * to user with @ref MtcGroupSetRelationsOkNotification
 * or @ref MtcGroupSetRelationsDidFailNotification.
 * @retval ZFAILED failed
 */
MTCFUNC ZINT Mtc_GroupSetRelations(ZCOOKIE zCookie,
    ZCONST ZCHAR *pcGroupId, ZCONST ZCHAR *pcInfo);

/**
 * @brief Set relation status.
 *
 * @param  zCookie The cookie value.
 * @param  pcGroupId The string of GroupID, ZNULL to operate on self group list.
 * @param  pcUid The uid of the user
 * @param  pcKey The status key
 * @param  pcValue The status value
 *
 * @retval ZOK on invoke this interface successfully. The result will notify
 * to user with @ref MtcGroupSetRelationStatusOkNotification
 * or @ref MtcGroupSetRelationStatusDidFailNotification.
 * @retval ZFAILED failed
 */
MTCFUNC ZINT Mtc_GroupSetRelationStatus(ZCOOKIE zCookie, ZCONST ZCHAR *pcGroupId,
    ZCONST ZCHAR *pcUid, ZCONST ZCHAR *pcKey, ZCONST ZCHAR *pcValue);

/**
 * @brief Get relation status.
 *
 * @param  zCookie The cookie value.
 * @param  pcGroupId The string of GroupID, ZNULL to operate on self group list.
 * @param  pcUids The uid of the user, or a string which is a JSON array, each item
 *              is the uid of the user.
 *
 * @retval ZOK on invoke this interface successfully. The result will notify
 * to user with @ref MtcGroupGetRelationStatusOkNotification
 * or @ref MtcGroupGetRelationStatusDidFailNotification.
 * @retval ZFAILED failed
 */
MTCFUNC ZINT Mtc_GroupGetRelationStatus(ZCOOKIE zCookie, ZCONST ZCHAR *pcGroupId,
    ZCONST ZCHAR *pcInfo);

/**
 * @brief Get self uid
 *
 * @retval The uid of the logined user
 */
MTCFUNC ZCONST ZCHAR * Mtc_GroupGetUid(ZFUNC_VOID);

/**
 * @brief Check is valid group ID.
 *
 * @return ZTRUE, the string is valid group ID.
 */
MTCFUNC ZBOOL Mtc_GroupIsValidGroupId(ZCONST ZCHAR *pcStr);

/**
 * @brief Update individual relation.
 *
 * @param  zCookie The cookie value.
 * @param  pcGroupId The string of GroupID to update.
 * @param  pcDisplayName The display name of the relation
 * @param  pcTag The tag info of the relation that may contains
 *         @ref MtcGroupTagKey
 * @param  pcInfo The properties information in JSON
 *
 * @retval ZOK on invoke this interface successfully. The result will notify
 * to user with @ref MtcGroupUpdateIndividualRelationOkNotification
 * or @ref MtcGroupUpdateIndividualRelationDidFailNotification.
 * @retval ZFAILED failed
 */
MTCFUNC ZINT Mtc_GroupUpdateIndividualRelation(ZCOOKIE zCookie, ZCONST ZCHAR *pcGroupId,
    ZCONST ZCHAR *pcDisplayName, ZCONST ZCHAR *pcTag, ZCONST ZCHAR *pcInfo);

/**
 * @brief Apply relation.
 *
 * @param  zCookie The cookie value.
 * @param  pcGroupId The string of GroupID.
 * @param  iRelationType The relation type, @ref EN_MTC_GROUP_RELATION_TYPE.
 * @param  pcDescription The description about how you find the relation.
 *
 * @retval ZOK on invoke this interface successfully. The result will notify
 * to user with @ref MtcGroupApplyRelationOkNotification
 * or @ref MtcGroupApplyRelationDidFailNotification.
 * @retval ZFAILED failed
 */
MTCFUNC ZINT Mtc_GroupApplyRelation(ZCOOKIE zCookie, ZCONST ZCHAR *pcGroupId,
    ZUINT iRelationType, ZCONST ZCHAR *pcDescription);

/**
 * @brief Invite relation.
 *
 * @param  zCookie The cookie value.
 * @param  pcGroupId The string of GroupID.
 * @param  pcUri The uri or uid of the target user.
 * @param  iRelationType The relation type, @ref EN_MTC_GROUP_RELATION_TYPE.
 * @param  pcDescription The description about invite message.
 *
 * @retval ZOK on invoke this interface successfully. The result will notify
 * to user with @ref MtcGroupInviteRelationOkNotification
 * or @ref MtcGroupInviteRelationDidFailNotification.
 * @retval ZFAILED failed
 */
MTCFUNC ZINT Mtc_GroupInviteRelation(ZCOOKIE zCookie, ZCONST ZCHAR *pcGroupId,
    ZCONST ZCHAR *pcTargetId, ZUINT iRelationType, ZCONST ZCHAR *pcDescription);

/**
 * @brief Accept relation.
 *
 * @param  zCookie The cookie value.
 * @param  dwMsgId The message id of apply request.
 * @param  pcDisplayName The display name of the relation.
 * @param  pcTag The tag info of the relation that may contains
 *         @ref MtcGroupTagKey.
 *
 * @retval ZOK on invoke this interface successfully. The result will notify
 * to user with @ref MtcGroupAcceptRelationOkNotification
 * or @ref MtcGroupAcceptRelationDidFailNotification.
 * @retval ZFAILED failed
 */
MTCFUNC ZINT Mtc_GroupAcceptRelation(ZCOOKIE zCookie, ZINT64 dwMsgId,
    ZCONST ZCHAR *pcDisplayName, ZCONST ZCHAR *pcTag);

/**
 * @brief Refuse relation.
 *
 * @param  zCookie The cookie value.
 * @param  dwMsgId The message id of apply request.
 * @param  pcDescription The description of refuse reason.
 *
 * @retval ZOK on invoke this interface successfully. The result will notify
 * to user with @ref MtcGroupRefuseRelationDidOkNotification
 * or @ref MtcGroupRefuseRelationDidFailNotification.
 * @retval ZFAILED failed
 */
MTCFUNC ZINT Mtc_GroupRefuseRelation(ZCOOKIE zCookie, ZINT64 dwMsgId, ZCONST ZCHAR *pcDescription);

/**
 * @brief Im Push.
 *
 * @param  zCookie The cookie value.
 * @param  pcGroupId The string of GroupID.
 * @param  bImPush is im push.
 * 
 * @retval ZOK on invoke this interface successfully. The result will notify
 * to user with @ref MtcGroupImPushOkNotification
 * or @ref MtcGroupImPushDidFailNotification.
 * @retval ZFAILED failed
 */
MTCFUNC ZINT Mtc_GroupImPush(ZCOOKIE zCookie,ZCONST ZCHAR *pcGroupId, ZBOOL bImPush);


#ifdef __cplusplus
}
#endif

#endif /* _MTC_GROUP_H__ */
