Pod::Spec.new do |s|

    s.name              = 'qgnotification'
    s.version           = '3.2.0'
    s.summary           = 'iOS Notification Sdk provides unique way to show Image, video, GIF, Audio push in ios 10 and above. It also supports Carousel and Slider Notifications.'
    s.homepage          = 'https://github.com/quantumgraph/ios-notification-sdk'
    s.license           = {
        :type => 'MIT',
        :file => 'LICENSE'
    }
    s.author            = {
        'Vivek Pandey' => 'vivek@quantumgraph.com'
    }
    s.source            = {
        :git => 'https://github.com/quantumgraph/ios-notification-sdk.git',
        :tag => v#{s.version}
    }
    s.platform     = :ios, '10.0'
    s.source_files      = 'ios-notification-sdk/*.{m,h}'
    s.requires_arc      = true

end
