# GTPrint

### 概述

- SDK简介：**gtexpress**内部使用打印SDK，Object-C语言编写，需要打印硬件设备支持

### 如何使用

- 1.**cocoapod**集成

  - cocoapod 集成简介，在项目的xcodeproj同级目录下，新建Podfile文件，推荐使用vim,尽量不用新建文本。至于podfile 文件如何编写，详情见:https://guides.cocoapods.org/syntax/podfile.ht

  以下给出的podfile内容可直接复制，使用

  ```
  platform :ios, '9.0'
  inhibit_all_warnings!

  target 'MyApp' do
    pod 'GTPrint'
  end
  ```

  vim 保存Podfile文件之后，pod install or pod install GTPrint.成功后，会提示使用workspace 打开项目。

  - 具体使用：

    - 设置项目 Enable Bitcode = No；
    - 在需要使用打印的类文件中，导入header

    ```objective-c
    #import <GTPrint/GTDataFormatter.h>
    #import <GTPrint/GTPrinterInterface.h>
    ```

    ​

    .m具体实现例子如下：

     为了方便实现传入参数，写了一个链式调用的语法糖，具体使用见代码

  ```
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
      	
      //在试用期间，registerId 可为@""
      //具体使用可见demo
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
  ```