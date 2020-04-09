//
//  JCLog.h
//  JCSDKOC
//
//  Created by maikireton on 2017/8/22.
//  Copyright © 2017年 juphoon. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JCLog : NSObject

/**
 * @brief 上传日志
 * @param reason 原因描述
 * @return
 */
+(bool)uploadLog:(NSString*)reason;

@end
