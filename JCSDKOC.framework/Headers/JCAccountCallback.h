//
//  JCAccountCallback.h
//  JCSDKOC
//
//  Created by Ginger on 2018/6/8.
//  Copyright © 2018年 juphoon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JCAccountItem.h"

/**
 *  @brief 代理事件
 */
@protocol JCAccountCallback <NSObject>

/**
 *  @brief                  查询账号状态结果回调
 *  @param operationId      操作ID，由queryUserStatus接口返回
 *  @param queryResult      查询是否成功
 *  @param accountItemList  查询结果
 */
- (void)onQueryUserStatusResult:(int)operationId result:(BOOL)queryResult accountItemList:(NSArray<JCAccountItem*>* __nullable)accountItemList;

@end
