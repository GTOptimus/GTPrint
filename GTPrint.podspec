Pod::Spec.new do |s|
  s.name             = "GTPrint"
  s.version          = "1.0.0"
  s.summary          = "A print function  used on iOS."
  s.description      = <<-DESC
                       It is a ptint function library used on iOS, which implement by Objective-C.
                       DESC
  s.homepage         = "https://github.com/GTOptimus/GTPrint.git"
  # s.screenshots      = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
  s.license          = 'MIT'
  s.author           = { "GTOptimusLCG" => "gtcompany@gtexpress.cn" }
  s.source           = { :git => "https://github.com/GTOptimus/GTPrint.git", :tag => s.version }
  # s.social_media_url = ''

  s.platform     = :ios
  # s.ios.deployment_target = '8.0'
  # s.osx.deployment_target = '10.7'
  s.requires_arc = true
  #s.source_files = "GTPrint"
  s.resources = "GTPrinterFramework.framework/SVProgressHUD.bundle"

  # s.ios.exclude_files = 'Classes/osx'
  # s.osx.exclude_files = 'Classes/ios'
  # s.public_header_files = 'Classes/**/*.h'
  s.vendored_frameworks ="QRPrinter.framework","GTPrinterFramework.framework"
  s.frameworks = 'Foundation','QuartzCore','UIKit'
end
