//
//  JCMessageChannelCallback.h
//  JCSDKOC
//
//  Created by maikireton on 2017/8/11.
//  Copyright © 2017年 juphoon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JCMessageChannelItem.h"

/**
 *  JCIM 回调代理
 */
@protocol JCMessageChannelCallback <NSObject>

/**
 *  @brief 消息发送状态更新
 *  @param message IM消息对象，通过该对象可以获得消息的属性及状态
 *  @see JCMessageChannelItem
 */
-(void)onMessageSendUpdate:(JCMessageChannelItem*)message;

/**
 *  @brief 收到消息通知
 *  @param message IM消息对象，通过该对象可以获得消息的属性及状态
 *  @see JCMessageChannelItem
 */
-(void)onMessageRecv:(JCMessageChannelItem*)message;

@end
