//
//  GTDataFormatter.h
//  GTPrinterFramework
//
//  Created by erics on 2018/6/19.
//  Copyright © 2018年 EricsYinGroup. All rights reserved.
//

#import <Foundation/Foundation.h>
@class GTDataFormatter;

GTDataFormatter * gtRegisterId(NSString * registerId);

typedef GTDataFormatter *(^GTDataFormatterType)(NSString *, id);
typedef GTDataFormatter *(^OPDictFormatterType)(NSDictionary *);

@interface GTDataFormatter : NSObject

- (GTDataFormatterType)makeDataParameter;

- (GTDataFormatter *)addParameterKey:(NSString *)key value:(id)value;

- (NSDictionary *)requestBody;

@end
