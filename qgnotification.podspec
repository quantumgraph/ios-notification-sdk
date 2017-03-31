Pod::Spec.new do |s|

    s.name              = 'qgnotification'
    s.version           = '3.2.0'
    s.documentation_url = 'http://docs.qgraph.io'
    s.summary		= 'This sdk creates Carousel/Slider, Image, Video, Audio and GIF push notifications.'
    s.homepage          = 'https://github.com/quantumgraph/ios-notification-sdk'
    s.license           = {
        :type => 'MIT',
        :file => 'LICENSE'
    }
    s.author            = {
        'QUANTUMGRAPH' => 'vivek@quantumgraph.com'
    }
    s.source            = {
        :git => 'https://github.com/quantumgraph/ios-notification-sdk.git',
        :tag => "v#{s.version}"
    }
    s.platform     = :ios, '10.0'
    s.source_files      = '*.{m,h}'
    s.requires_arc      = true
    s.default_subspec   = 'QGNotificationSdk'

    s.subspec 'QGNotificationSdk' do |ss|
      ss.source_files = '*.{h,m}'
      ss.vendored_library = 'libQGNotificationSdk.a'
    end

end
