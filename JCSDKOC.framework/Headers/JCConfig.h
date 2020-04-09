//
//  JCConfig.h
//  JCSDKOC
//
//  Created by chendi on 2018/5/15.
//  Copyright © 2018 juphoon. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Call:NSObject

/**
 *  @brief 设置点对点视频通话动态码率
 */
- (bool)setVideoArs:(bool)enable;

/**
 *  @brief 获取点对点视频通话动态码率开启状态
 */
- (bool)getVideoArs;

/**
 *  @brief 设置视频流畅模式
 */
- (bool)setVideoSmoothMode:(bool)enable;

/**
 *  @brief 获取视频流畅模式开启状态
 */
- (bool)getVideoSmoothMode;

/**
 *  @brief 是否开启发送 Alert
 */
-(void)setSendAlert:(bool)enable;

@end

@interface JCConfig : NSObject

@property (nonatomic, strong) Call* call;

/**
 *  @brief 创建 JCConfig 对象
 */
+(JCConfig*)create;

/**
 * @brief 获取支持的音频编解码
 */
- (NSMutableArray*)getSupportAudioCodec;

/**
 * @brief 禁用或启用音频编解码
 *
 * @param codec 编解码类型
 * @param enable true 启用；false 禁用
 */
- (bool)setAudioCodecEnable:(NSString*)codec enable:(bool)enable;

/**
 * @brief 设置音频优先级
 *
 * @param codec 编解码类型
 * @param priority 优先级
 */
- (bool)setAudioCodecByPriority:(NSString*)codec priority:(short int)priority;

/**
 * @brief 获取支持的视频编解码
 */
- (NSMutableArray*)getSupportVideoCodec;

/**
 * @brief 禁用或启用的视频编解码
 *
 * @param codec 视频编解码类型
 * @param enable true 启用；false 禁用
 */
- (bool)setVideoCodecEnable:(NSString*)codec enable:(bool)enable;

/**
 * @brief 设置优先级
 *
 * @param codec 编解码类型
 * @param priority 优先级
 */
- (bool)setVideoCodecByPriority:(NSString*)codec priority:(short int)priority;

/**
 * @brief 获取开启的音频编解码
 */
- (NSMutableArray*)getEnableAudioCodec;

/**
 * @brief 获取开启的视频编解码
 */
- (NSMutableArray*)getEnableVideoCodec;

@end

