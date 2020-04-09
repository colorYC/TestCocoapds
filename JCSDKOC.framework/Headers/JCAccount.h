//
//  JCAccount.h
//  JCSDKOC
//
//  Created by Ginger on 2018/6/8.
//  Copyright © 2018年 juphoon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JCAccountCallback.h"
#import "JCAccountItem.h"

/**
 * @brief  账号类
 */
@interface JCAccount : NSObject

/**
 * @brief 创建 JCAccount 实例
 * @param callback    回调接口，用于接收 JCAccount 相关回调事件
 * @return JCAccount  实例
 */
+ (JCAccount* __nullable)create:(id<JCAccountCallback> __nonnull)callback;

/**
 * @brief 销毁 JCAccount 实例
 */
+ (void)destroy;

/**
 * @brief 查询账号状态
 * @param userIdArray 查询的账号
 * @return 返回操作id
 */
- (int)queryUserStatus:(NSArray<NSString*>* __nonnull)userIdArray;

/**
 * @brief 添加回调
 * @param callback JCAccountCallback 接口对象
 */
- (void)addCallback:(id<JCAccountCallback> __nonnull)callback;

/**
 * @brief 删除回调
 * @param callback JCAccountCallback 接口对象
 */
- (void)removeCallback:(id<JCAccountCallback> __nonnull)callback;

@end
