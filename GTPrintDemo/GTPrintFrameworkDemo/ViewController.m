//
//  ViewController.m
//  GTPrintFrameworkDemo
//
//  Created by erics on 2018/6/21.
//  Copyright © 2018年 EricsYinGroup. All rights reserved.
//

#import "ViewController.h"
#import <GTPrint/GTDataFormatter.h>
#import <GTPrint/GTPrinterInterface.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.view.backgroundColor = [UIColor whiteColor];
    UIButton * button = [UIButton buttonWithType:UIButtonTypeCustom];
    button.frame = CGRectMake(20, 100, 100, 40);
    button.backgroundColor = [UIColor blueColor];
    [button setTitle:@"打印" forState:UIControlStateNormal];
    [self.view addSubview:button];
    [button addTarget:self action:@selector(clickPrint) forControlEvents:UIControlEventTouchUpInside];
}

- (void)clickPrint{
    //    @param expressCode 快递单号(必填字段)
    //    @param companyName 快递公司名称(必填字段)
    //    @param tripleCode 大头笔/三联码(必填字段)
    //    @param receiverName 收件人姓名(必填字段)
    //    @param receiverPhone 收件人电话(必填字段)
    //    @param receiverProvinceName 收点人地址所在省份
    //    @param receiverCityName 收件人地址所在城市
    //    @param receiverDistrictName 收件人地址所在地区/乡镇
    //    @param receiverAddressContent 收件人详细地址(必填字段)
    //    @param senderName 寄件人姓名(必填字段)
    //    @param senderPhone 寄件人电话(必填字段)
    //    @param senderProvinceName 寄件人地址所在省份
    //    @param sendercityName 寄件人地址所在城市
    //    @param senderDistrictName 寄件人地址所在地区/乡镇
    //    @param senderAddressContent 寄件人详细地址(必填字段)
    //    @param remarkContent 快件信息备注
    //    @param shownQRCode 需要额外展示的二维码
    NSDictionary * dict =
    gtRegisterId(@"12344")
    .makeDataParameter(@"expressCode",@"578084903")
    .makeDataParameter(@"companyName",@"申通快递")
    .makeDataParameter(@"tripleCode",@"123-456-789")
    .makeDataParameter(@"receiverName",@"李四")
    .makeDataParameter(@"receiverPhone",@"15201497292")
    .makeDataParameter(@"receiverAddressContent",@"北京市")
    .makeDataParameter(@"senderName",@"张三")
    .makeDataParameter(@"senderPhone",@"18816382821")
    .makeDataParameter(@"senderAddressContent",@"海淀区")
    .makeDataParameter(@"remarkContent",@"别动")
    .makeDataParameter(@"shownQRCode",@"www.gtexpress.cn")
    .requestBody;
    
    
    GTPrinterInterface * interface = [[GTPrinterInterface alloc]init];
    __weak typeof(self)weakSelf = self;
    [interface gt_printWithExpressInfomationWithTarget:weakSelf infoDictionary:dict];
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
