//
//  JCGroupItem.h
//  JCSDKOC
//
//  Created by maikireton on 2017/8/15.
//  Copyright © 2017年 juphoon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JCGroupConstants.h"

/**
 *  群组对象类
 */
@interface JCGroupItem : NSObject

/**
 *  @brief 群组标识
 */
@property (nonatomic, copy, readonly) NSString* groupId;

/**
 *  @brief 群组名称
 */
@property (nonatomic, copy, readonly) NSString* name;

/**
 *  @brief 群组类型
 */
//@property (nonatomic, readonly) JCGroupType type;

/**
 *  @brief 群组改变状态
 */
@property (nonatomic, readonly) JCGroupChangeState changeState;

/**
 *  @return 最新一次更新时间
 */
//@property (nonatomic, readonly) long long updateTime;

/**
 *  @brief 构造 JCGroupItem
 *  @param groupId 群组唯一标识
 *  @param name 群名称
 *  @param changeState 群组变化状态
 *  @return 返回 JCGroupItem 对象
 */
-(instancetype)init:(NSString*)groupId name:(NSString*)name changeState:(JCGroupChangeState)changeState;

@end
