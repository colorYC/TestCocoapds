//
//  JCGroupConstants.h
//  JCSDKOC
//
//  Created by maikireton on 2017/8/15.
//  Copyright © 2017年 juphoon. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  群组错误枚举
 */
typedef NS_ENUM(NSInteger, JCGroupReason) {
    /// 正常
    JCGroupReasonNone,
    /// 未登陆
    JCGroupReasonNotLogin,
    /// 函数调用失败
    JCGroupReasonCallFunctionError,
    /// 超时
    JCGroupReasonTimeOut,
    /// 网络异常
    JCGroupReasonNetWork,
    /// 参考错误
    JCGroupResonInvalid,
    /// 其他错误
    JCGroupReasonOther = 100
};

/**
 *  群组状态
 */
/*typedef NS_ENUM(NSInteger, JCGroupState) {
    /// 创建中
    JCGroupStateInitiated,
    /// 被邀请中
    JCGroupStateInvited,
    /// 活跃中
    JCGroupStateStarted,
    /// 解散
    JCGroupStateDissolve,
    /// 离开
    JCGroupStateLeaved,
    /// 错误
    JCGroupStateError,
};*/

/**
 *  群组变化状态
 */
typedef NS_ENUM(NSInteger, JCGroupChangeState) {
    /// 无
    JCGroupChangeStateNone,
    /// 新增
    JCGroupChangeStateAdd,
    /// 更新
    JCGroupChangeStateUpdate,
    /// 删除
    JCGroupChangeStateRemove,
};

/**
 *  群成员角色类型
 */
typedef NS_ENUM(NSInteger, JCGroupMemberType) {
    /// 拥有者
    JCGroupMemberTypeOwner,
    /// 管理员
    JCGroupMemberTypeManager,
    /// 群成员
    JCGroupMemberTypeMember,
};



