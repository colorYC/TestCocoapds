//
//  JCGroupCallback.h
//  JCSDKOC
//
//  Created by maikireton on 2017/8/15.
//  Copyright © 2017年 juphoon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JCGroupItem.h"
#import "JCGroupMember.h"
#import "JCGroupConstants.h"

/**
 *  JCGroup 回调代理
 */
@protocol JCGroupCallback <NSObject>

/**
 *  @brief 拉取群列表结果回调
 *  @param operationId 操作表示，由 fetchGroups 接口返回
 *  @param result true 表示获取成功，false 表示获取失败
 *  @param reason 当 result 为 false 时该值有效
 *  @param groups 群列表
 *  @param updateTime 服务器更新时间
 *  @param fullUpdate 是否全更新
 *  @see JCGroupReason
 */
-(void)onFetchGroups:(int)operationId result:(bool)result reason:(JCGroupReason)reason groups:(NSArray*)groups updateTime:(long long)updateTime fullUpdate:(bool)fullUpdate;

/**
 *  @brief 拉取群详情结果回调
 *  @param operationId 操作表示，由 fetchGroupInfo 接口返回
 *  @param result true 表示获取成功，false 表示获取失败
 *  @param reason 当 result 为 false 时该值有效
 *  @param groupItem JCGroupItem 对象
 *  @param members 成员列表
 *  @param updateTime 服务器更新时间
 *  @param fullUpdate 是否全更新
 *  @see JCGroupReason
 */
-(void)onFetchGroupInfo:(int)operationId result:(bool)result reason:(JCGroupReason)reason groupItem:(JCGroupItem*)groupItem members:(NSArray*)members updateTime:(long long)updateTime fullUpdate:(bool)fullUpdate;

/**
 *  @brief 群列表更新，调用 JCGroup fetchGroups 获取更新
 */
-(void)onGroupListChange;

/**
 *  @brief 群信息更新，调用 JCGroup fetchGroupInfo 获取更新
 *  @param groupId 群标识
 */
-(void)onGroupInfoChange:(NSString*)groupId;

/**
 *  @brief 创建群回调
 *  @param operationId 操作表示，由 createGroup 接口返回
 *  @param result true 表示登陆成功，false 表示登陆失败
 *  @param reason 当 result 为 false 时该值有效
 *  @param groupItem JCGroupItem 对象
 *  @see JCGroupReason
 */
-(void)onCreateGroup:(int)operationId result:(bool)result reason:(JCGroupReason)reason groupItem:(JCGroupItem*)groupItem;

/**
 *  @brief 更新群信息调用回调
 *  @param operationId 操作表示，由 updateGroup 接口返回
 *  @param result true 表示登陆成功，false 表示登陆失败
 *  @param reason 当 result 为 false 时该值有效
 *  @param groupId 群标识
 *  @see JCGroupReason
 */
-(void)onUpdateGroup:(int)operationId result:(bool)result reason:(JCGroupReason)reason groupId:(NSString*)groupId;

/**
 *  @brief 解散群组回调
 *  @param operationId 操作表示，由 dissolve 接口返回
 *  @param result true 表示成功，false 表示失败
 *  @param reason 当 result 为 false 时该值有效，参见 JCGroupReason
 *  @param groupId 群标识
 */
-(void)onDissolve:(int)operationId result:(bool)result reason:(JCGroupReason)reason groupId:(NSString*)groupId;

/**
 *  @brief 离开群组回调
 *  @param operationId 操作表示，由 leave 接口返回
 *  @param result true 表示成功，false 表示失败
 *  @param reason 当 result 为 false 时该值有效，参见 JCGroupReason
 *  @param groupId 群标识
 */
-(void)onLeave:(int)operationId result:(bool)result reason:(JCGroupReason)reason groupId:(NSString*)groupId;

/**
 *  @brief dealMembers 结果回调
 *  @param operationId 操作表示，由 dealMembers 接口返回
 *  @param result true 表示成功，false 表示失败
 *  @param reason 当 result 为 false 时该值有效，参见 JCGroupReason
 */
-(void)onDealMembers:(int)operationId result:(bool)result reason:(JCGroupReason)reason;

@end
