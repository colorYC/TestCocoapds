//
//  JCCallConstants.h
//  JCSDK-OC
//
//  Created by maikireton on 2017/8/11.
//  Copyright © 2017年 juphoon. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  通话方向
 */
typedef NS_ENUM(NSInteger, JCCallDirection) {
    /// 呼入
    JCCallDirectionIn,
    /// 呼出
    JCCallDirectionOut,
};

/**
 *  通话结束错误原因
 */
typedef NS_ENUM(NSInteger, JCCallReason) {
    /// 无异常
    JCCallReasonNone,
    /// 未登录
    JCCallReasonNotLogin,
    /// 函数调用失败
    JCCallReasonCallFunctionError,
    /// 超时
    JCCallReasonTimeOut,
    /// 网络异常
    JCCallReasonNetWork,
    /// 超过通话数限制
    JCCallReasonCallOverLimit,
    /// 自己挂断
    JCCallReasonTermBySelf,
    /// 应答失败
    JCCallReasonAnswerFail,
    /// 忙
    JCCallReasonBusy,
    /// 拒接
    JCCallReasonDecline,
    /// 用户不在线
    JCCallReasonUserOffline,
    /// 无此用户
    JCCallReasonNotFound,
    /// 已有通话拒绝视频来电
    JCCallReasonRejectVideoWhenHasCall,
    /// 已有视频通话拒绝来电
    JCCallReasonRejectCallWhenHasVideoCall,
    /// 其他错误
    JCCallReasonOther = 100,
};

/**
 *  通话状态
 */
typedef NS_ENUM(NSInteger, JCCallState) {
    /// 初始
    JCCallStateInit,
    /// 振铃
    JCCallStatePending,
    /// 连接中
    JCCallStateConnecting,
    /// 通话中
    JCCallStateTalking,
    /// 通话正常结束
    JCCallStateOk,
    /// 未接通挂断
    JCCallStateCancel,
    /// 未接通被挂断
    JCCallStateCanceled,
    /// 未接
    JCCallStateMissed,
    /// 异常
    JCCallStateError,
};

/**
 *  通话网络状态
 */
typedef NS_ENUM(NSInteger, JCCallNetWork) {
    /// 未知状态
    JCCallNetWorkNA = -100,
    /// 无网络
    JCCallNetWorkDisconnected = -3,
    /// 很差
    JCCallNetWorkVeryBad,
    /// 差
    JCCallNetWorkBad,
    /// 一般
    JCCallNetWorkNormal,
    /// 好
    JCCallNetWorkGood,
    /// 很好
    JCCallNetWorkVeryGood,
};

/**
 *  通话类型
 */
/*typedef NS_ENUM(NSInteger, JCCallSwitchMediaState) {
    /// 空闲状态
    JCCallSwitchMediaStateIdle,
    /// 收到降级音频邀请
    JCCallSwitchMediaStateAudioInvited,
    /// 收到升级视频邀请
    JCCallSwitchMediaStateVideoInvited,
    /// 降级音频中
    JCCallSwitchMediaStateAudioDegrading,
    /// 升级视频中
    JCCallSwitchMediaStateVideoUpgrading,
};*/

/**
 *  通话通知类型
 */
/*typedef NS_ENUM(NSInteger, JCCallUpdateType) {
    /// 活跃状态变化
    JCCallUpdateTypeActiveChange,
    /// 通话状态变化
    JCCallUpdateTypeCallStateChange,
    /// 通话音视频类型变化
    JCCallUpdateTypeMediaTypeChange,
    /// 呼叫保持变化
    JCCallUpdateTypeHoldChange,
    /// 静音状态变化
    JCCallUpdateTypeMuteChange,
    /// 扬声器状态变化
    JCCallUpdateTypeSpeakerChange,
};*/
