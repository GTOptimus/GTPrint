//
//  GTPrinterInterface.h
//  GTPrinterFramework
//
//  Created by erics on 2018/6/19.
//  Copyright © 2018年 EricsYinGroup. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface GTPrinterInterface : NSObject
//! Project version number for GTPrinterFramework.
FOUNDATION_EXPORT double GTPrinterFrameworkVersionNumber;

//! Project version string for GTPrinterFramework.
FOUNDATION_EXPORT const unsigned char GTPrinterFrameworkVersionString[];


/**
 基础调用打印快递单号API

 @param target 跳转打印的viewController (必填字段)
 @param expressCode 快递单号(必填字段)
 @param companyName 快递公司名称(必填字段)
 @param tripleCode 大头笔/三联码(必填字段)
 @param receiverName 收件人姓名(必填字段)
 @param receiverPhone 收件人电话(必填字段)
 @param receiverProvinceName 收点人地址所在省份
 @param receiverCityName 收件人地址所在城市
 @param receiverDistrictName 收件人地址所在地区/乡镇
 @param receiverAddressContent 收件人详细地址(必填字段)
 @param senderName 寄件人姓名(必填字段)
 @param senderPhone 寄件人电话(必填字段)
 @param senderProvinceName 寄件人地址所在省份
 @param sendercityName 寄件人地址所在城市
 @param senderDistrictName 寄件人地址所在地区/乡镇
 @param senderAddressContent 寄件人详细地址(必填字段)
 @param remarkContent 快件信息备注
 @param shownQRCode 需要额外展示的二维码
 */
- (void)gt_printWithExpressInfomationWithTarget:(UIViewController *)target
                                    expressCode:(NSString *)expressCode
                                 expressCompany:(NSString *)companyName
                              expressTripleCode:(NSString *)tripleCode
                                   receiverName:(NSString *)receiverName
                                  receiverPhone:(NSString *)receiverPhone
                           receiverProvinceName:(NSString *)receiverProvinceName
                               receiverCityName:(NSString *)receiverCityName
                           receiverDistrictName:(NSString *)receiverDistrictName
                         receiverAddressContent:(NSString *)receiverAddressContent
                                     senderName:(NSString *)senderName
                                    senderPhone:(NSString *)senderPhone
                             senderProvinceName:(NSString *)senderProvinceName
                                 senderCityName:(NSString *)sendercityName
                             senderDistrictName:(NSString *)senderDistrictName
                           senderAddressContent:(NSString *)senderAddressContent
                           expressRemarkContent:(NSString *)remarkContent
                                    shownQRCode:(NSString *)shownQRCode;


/**
 打印快件信息基础


 @param target 跳转打印的viewController (必填字段)
 
 @param infoDictionary 快件信息字典，具体拼接形式见详情:
 
 expressCode 快递单号(必填字段)
 companyName 快递公司名称(必填字段)
 tripleCode 大头笔/三联码(必填字段)
 receiverName 收件人姓名(必填字段)
 receiverPhone 收件人电话(必填字段)
 receiverProvinceName 收点人地址所在省份
 receiverCityName 收件人地址所在城市
 receiverDistrictName 收件人地址所在地区/乡镇
 receiverAddressContent 收件人详细地址(必填字段)
 senderName 寄件人姓名(必填字段)
 senderPhone 寄件人电话(必填字段)
 senderProvinceName 寄件人地址所在省份
 sendercityName 寄件人地址所在城市
 senderDistrictName 寄件人地址所在地区/乡镇
 senderAddressContent 寄件人详细地址(必填字段)
 remarkContent 快件信息备注
 shownQRCode 需要额外展示的二维码
 */
- (void)gt_printWithExpressInfomationWithTarget:(UIViewController *)target infoDictionary:(NSDictionary *)infoDictionary;




@end
