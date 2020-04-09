//
//  JCAccountConstants.h
//  JCSDKOC
//
//  Created by chendi on 2018/6/21.
//  Copyright © 2018 juphoon. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  用户状态
 */
typedef NS_ENUM(NSInteger, JCAccountUserStatus) {
    /// 查询异常
    JCAccountUserStatusError,
    /// 用户未注册
    JCAccountUserStatusNotFount,
    /// 用户离线
    JCAccountUserStatusOffline,
    /// 用户推送状态
    JCAccountUserStatusPush,
    /// 用户在线
    JCAccountUserStatusOnline
};
