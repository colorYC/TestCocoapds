//
//  JCMediaChannelQueryListItem.h
//  JCSDKOC
//
//  Created by Home on 2019/9/29.
//  Copyright © 2019 juphoon. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JCMediaChannelQueryListItem : NSObject

@property(nonatomic, readonly, copy) NSString *confUri;

@property(nonatomic) int number;

@property(nonatomic, readonly, copy) NSString *title;

@property(nonatomic, strong) NSMutableDictionary *data;

@property(nonatomic, readonly, copy) NSString *createUserId;

-(instancetype)init:(NSString *)confUri number:(int)number title:(NSString *)title creator:(NSString *)creator data:(NSMutableDictionary *)data;

@end
