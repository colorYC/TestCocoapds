//
//  JCMessageChannelConstants.h
//  JCSDKOC
//
//  Created by maikireton on 2017/8/11.
//  Copyright © 2017年 juphoon. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  消息归属类型
 */
typedef NS_ENUM(NSInteger, JCMessageChannelType) {
    /// 一对一消息
    JCMessageChannelType1To1,
    /// 群组消息
    JCMessageChannelTypeGroup,
};

/**
 *  消息错误枚举
 */
typedef NS_ENUM(NSInteger, JCMessageChannelReason) {
    /// 正常
    JCMessageChannelReasonNone,
    /// 未登陆
    JCMessageChannelReasonNotLogin,
    /// 消息内容太长
    JCMessageChannelReasonTooLong,
    /// 其他错误
    JCMessageChannelReasonOther,
};

/**
 * 消息状态
 */
typedef NS_ENUM(NSInteger, JCMessageChannelItemState) {
    /// 消息初始状态
    JCMessageChannelItemStateInit,
    /// 消息发送中状态
    JCMessageChannelItemStateSending,
    /// 消息发送成功状态
    JCMessageChannelItemStateSendOK,
    /// 消息发送失败状态
    JCMessageChannelItemStateSendFail,
    /// 收到消息
    JCMessageChannelItemStateRecveived,
};

/**
 *  消息传输方向
 */
typedef NS_ENUM(NSInteger, JCMessageChannelItemDirection) {
    /// 发送
    JCMessageChannelItemDirectionSend,
    /// 接收
    JCMessageChannelItemDirectionReceive,
};

/**
 *  消息关键字
 */
extern NSString* const JCMessageChannelItemMessageId;
extern NSString* const JCMessageChannelItemFileUri;
extern NSString* const JCMessageChannelItemThumbData;
extern NSString* const JCMessageChannelItemFileSize;
extern NSString* const JCMessageChannelItemDuration;
extern NSString* const JCMessageChannelItemExtraData;

/// 缩略图限制大小，单位字节
extern const int JCMessageChannelItemMaxThumbSize;
