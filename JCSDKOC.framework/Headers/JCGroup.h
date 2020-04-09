//
//  JCGroup.h
//  JCSDKOC
//
//  Created by maikireton on 2017/8/15.
//  Copyright © 2017年 juphoon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JCGroupCallback.h"
#import "JCGroupConstants.h"
#import "JCGroupItem.h"

/**
 *  群操作类
 */
@interface JCGroup : NSObject

/**
 *  @brief 创建 JCGroup 对象
 *  @param client JCClient 对象
 *  @param callback JCGroupCallback 回调接口，用于接收 JCGroup 相关通知
 *  @return 返回 JCGroup 对象
 */
+(JCGroup*)create:(JCClient*)client callback:(id<JCGroupCallback>)callback;

/**
 *  @brief 销毁接口
 */
+(void)destroy;

/**
 *  @brief 获取当前用户所有加入的群列表，结果通过 JCGroupCallback 中相应回调返回
 *  @param updateTime 最新一次记录的群列表服务器更新时间
 *  @return 返回操作id
 */
-(int)fetchGroups:(long long)updateTime;

/**
 *  @brief 刷新群组信息
 *  @param groupId 群标识
 *  @param updateTime 最新一次记录的该群服务器更新时间
 *  @return 返回操作id
 */
-(int)fetchGroupInfo:(NSString*)groupId updateTime:(long long)updateTime;

/**
 *  @brief 创建群
 *  @param members JCGroupMemeber 队列
 *  @param groupName 群名称
 *  @return 返回操作id
 */
-(int)createGroup:(NSArray*)members groupName:(NSString*)groupName;

/**
 *  @brief 更新群
 *  @param groupItem JCGroupItem 对象，其中 JCGroupItem 中 changeState 值不影响具体操作
 *  @return 返回操作id
 */
-(int)updateGroup:(JCGroupItem*)groupItem;

/**
 *  @brief 解散群组，Owner才能解散群组
 *  @param groupId 群标识
 *  @return 返回操作id
 */
-(int)dissolve:(NSString*)groupId;

/**
 *  @brief 离开群组
 *  @param groupId 群标识
 *  @return 返回操作id
 */
-(int)leave:(NSString*)groupId;

/**
 *  @brief 更新昵称
 *  @param selfInfo JCGroupMember 对象，请传入 groupId，displayName，memberType(保持不变)
 *  @return 返回操作id
 */
-(int)updateSelfInfo:(JCGroupMember*)selfInfo;

/**
 *  @brief 操作成员
 *  @param groupId 群标识
 *  @param members JCGroupMemeber 对象列表，通过 changeState 值来表明增加，更新，删除成员操作
 *  @return 返回操作id
 */
-(int)dealMembers:(NSString*)groupId members:(NSArray*)members;

@end
