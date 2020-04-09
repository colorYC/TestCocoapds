//
//  JCMessageChannel.h
//  JCSDKOC
//
//  Created by maikireton on 2017/8/11.
//  Copyright © 2017年 juphoon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JCMessageChannelItem.h"
#import "JCMessageChannelCallback.h"

/**
 *  消息通道类，包括一对一消息和群组消息
 */
@interface JCMessageChannel : NSObject

/**
 *  @brief 缩率图保存路径，初始化会默认设置，同时用户可以自己设置
 */
@property (nonatomic, copy) NSString* thumbDir;

/**
 *  @brief 创建 JCMessageChannel 对象
 *  @param client JCClient 对象
 *  @param callback JCMessageChannelCallback 回调接口，用于接收 JCMessageChannel 相关通知
 *  @return 返回 JCMessageChannel 对象
 */
+(JCMessageChannel*)create:(JCClient*)client callback:(id<JCMessageChannelCallback>)callback;

/**
 *  @brief 销毁接口
 */
+(void)destroy;

/**
 *  @brief 发送文本消息
 *  @param type 类型，参见 JCMessageChannelType
 *  @param keyId 对方唯一标识，当 type 为 JCMessageChannelType1To1 时为用户标识，当 type 为 JCMessageChannelTypeGroup 时为群组标识
 *  @param messageType 文本消息类型，用户可以自定义，例如text，xml等
 *  @param text 文本内容
 *  @param extraParams 自定义参数集
 *  @return 返回 JCMessageChannelItem 对象，异常返回 nil
 *  @warning 文本内容不要超过10KB
 */
-(JCMessageChannelItem*)sendMessage:(JCMessageChannelType)type keyId:(NSString*)keyId messageType:(NSString*)messageType text:(NSString*)text extraParams:(NSDictionary*)extraParams;

/**
 *  @brief 发送文件消息
 *  @param type 类型，参见 JCMessageChannelType
 *  @param keyId 对方唯一标识，当 type 为 JCMessageChannelType1To1 时为用户标识，当 type 为 JCMessageChannelTypeGroup 时为群组标识
 *  @param messageType 文件消息类型，用户可以自定义，例如image，video等
 *  @param fileUri 文件链接地址
 *  @param thumbPath 缩略图路径，针对视频，图片等消息
 *  @param size 文件大小(字节)
 *  @param duration 文件时长，针对语音，视频等消息
 *  @param extraParams 自定义参数集
 *  @return 返回 JCMessageChannelItem 对象，异常返回 nil
 */
-(JCMessageChannelItem*)sendFile:(JCMessageChannelType)type keyId:(NSString*)keyId messageType:(NSString*)messageType fileUri:(NSString*)fileUri thumbPath:(NSString*)thumbPath size:(int)size duration:(int)duration extraParams:(NSDictionary*)extraParams;

@end
