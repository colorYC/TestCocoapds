//
//  JCCall.h
//  JCSDK-OC
//
//  Created by maikireton on 2017/8/11.
//  Copyright © 2017年 juphoon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JCCallCallback.h"
#import "JCCallItem.h"

/**
 *  一对一通话类
 *  @warning 扬声器通过 JCMediaDevice 类中 enableSpeaker 进行开关
 */
@interface JCCall : NSObject

/**
 *  @brief 通话对象列表
 */
@property (nonatomic, readonly, strong) NSArray* __nullable callItems;

/**
 *  @brief 最大通话数，当通话超过最大数呼出会失败，收到来电会自动拒绝
 */
@property (nonatomic) int maxCallNum;

/**
 *  @brief 当 JCCallItem 网络状态为 disconnected 时是否挂断，默认为 false
 */
@property (nonatomic) bool termWhenNetDisconnected;

/**
 *  @brief                  创建 JCCall 实例
 *  @param client           JCClient 实例
 *  @param mediaDevice      JCMediaDevice 实例
 *  @param callback         JCCallCallback 回调接口，用于接收 JCCall 相关回调事件
 *  @return                 返回 JCCall 实例
 */
+(JCCall* __nullable)create:(JCClient* __nonnull)client mediaDevice:(JCMediaDevice* __nonnull)mediaDevice callback:(id<JCCallCallback> __nonnull)callback;
 
/**
 *  @brief 销毁接口
 */
+(void)destroy;

/**
 *  @brief                  一对一呼叫
 *  @param userId           用户标识
 *  @param video            是否为视频呼叫
 *  @param extraParam       透传参数，被叫方可获取透传参数
 *  @return                 返回 true 表示正常执行调用流程，false 表示调用异常
 */
-(bool)call:(NSString* __nonnull)userId video:(bool)video extraParam:(NSString * __nullable)extraParam;

/**
 *  @brief                  挂断
 *  @param item             JCCallItem 对象
 *  @param reason           挂断原因
 *  @param description      挂断描述
 *  @return                 返回 true 表示正常执行调用流程，false 表示调用异常
 *  @see JCCallReason
 */
-(bool)term:(JCCallItem* __nonnull)item reason:(JCCallReason)reason description:(NSString* __nullable)description;

/**
 *  @brief                  接听
 *  @param item             JCCallItem 对象
 *  @param video            针对视频呼入可以选择以视频接听还是音频接听
 *  @return                 返回 true 表示正常执行调用流程，false 表示调用异常
 */
-(bool)answer:(JCCallItem* __nonnull)item video:(bool)video;

/**
 *  @brief 静音，通过 JCCallItem 对象中的静音状态来决定开启关闭静音
 *  @param item JCCallItem 对象
 *  @return 返回 true 表示正常执行调用流程，false 表示调用异常
 */
-(bool)mute:(JCCallItem* __nonnull)item;

/**
 *  @brief                  呼叫保持，通过 JCCallItem 对象中的呼叫保持状态来决定开启关闭呼叫保持
 *  @param item             JCCallItem 对象
 *  @return                 返回 true 表示正常执行调用流程，false 表示调用异常
 */
-(bool)hold:(JCCallItem* __nonnull)item;

/**
 * 语音通话录音，通过 JCCallItem 对象中的audioRecord状态来决定开启关闭录音
 *
 * @param item              JCCallItem 对象
 * @param enable            开启关闭录音
 * @param filePath          录音文件路径
 * @return                  返回 true 表示正常执行调用流程，false 表示调用异常
 */
-(bool)audioRecord:(JCCallItem* __nonnull)item enable:(bool)enable filePath:(NSString* __nullable)filePath;

/**
 * 视频通话录制，通过 JCCallItem 对象中的 localVideoRecord 状态来决定开启关闭录制
 *
 * @param item              JCCallItem 对象
 * @param enable            开启关闭录制
 * @param remote            是否为远端视频源
 * @param width             录制视频宽像素
 * @param height            录制视频高像素
 * @param filePath          录制视频文件存储路径
 * @param bothAudio         是否录制两端音频，false 表示只录制视频端音频
 * @return                  返回 true 表示正常执行调用流程，false 表示调用异常
 */
-(bool)videoRecord:(JCCallItem* __nonnull)item enable:(bool)enable remote:(bool)remote width:(int)width height:(int)height filePath:(NSString* __nullable)filePath bothAudio:(bool)bothAudio;

/**
 *  @brief 切换活跃通话
 *  @param item 需要变为活跃状态的 JCCallItem 对象
 *  @return 返回 true 表示正常执行调用流程，false 表示调用异常
 */
-(bool)becomeActive:(JCCallItem* __nonnull)item;

/**
 *  @brief 开启关闭视频流发送，用于视频通话中
 *  @param item JCCallItem 对象
 *  @return 返回 true 表示正常执行调用流程，false 表示调用异常
 */
-(bool)enableUploadVideoStream:(JCCallItem* __nonnull)item;

/**
 *  @brief 通过通话建立的通道发送数据
 *  @param item 需要发送数据的 JCCallItem 对象
 *  @param type 文本消息类型，用户可以自定义，例如text、xml等
 *  @param content 消息内容
 *  @return 返回 true 表示正常执行调用流程，false 表示调用异常
 */
-(bool)sendMessage:(JCCallItem * __nonnull)item type:(NSString * __nonnull)type content:(NSString * __nonnull)content;

/**
 * @brief 获得当前通话统计信息，以Json字符串形式返回，其中包含 "Audio" 和 "Video" 两个节点
 *
 * @return 当前通话统计信息
 */
-(NSString * __nullable)getStatistics;

/**
 * @brief 获得当前活跃通话
 *
 * @return 当前活跃通话，没有则返回nil
 */
-(JCCallItem* __nullable)getActiveCallItem;

@end
