Pod::Spec.new do |s|
s.name         = "sdk"
s.version      = "1.3.0"
s.summary      = "Useage of sdk."
s.description  = "sdfdf"
s.source       = { :git => "https://github.com/colorYC/TestCocoapds.git", :tag => "#{s.version}" }
s.source_files  = "include/**/*"
s.homepage     = "https://github.com/colorYC/TestCocoapds.git"
s.license      = "MIT"
s.author             = { "于彩彩" => "color.yu@juphoon.com.cn" }
s.platform     = :ios, "9.0"
s.vendored_frameworks  = "JCSDKOC.framework"
s.vendored_libraries = "lib/ios/libzmf.a"

end
