# ios-notification-sdk
QGraph Rich Push Notification Sdk

This library is meant to be used with Service and Content Extension along with other relevant files available at our documentation.

It helps you create beautiful Slider, Carousel, Image, Video, Audio, GIF push for ios 10 and above. Read our documentation for more details.
http://docs.qgraph.io/en/latest/integrating-ios-sdk.html

Installation

If you are not using pod in your project: 
Do 'pod init' to initialise pod

Add Targets Service Extension and Content Extension as per our documentation

In the Podfile, you need to add qgnotification to these targets. 
NOTE: Don't add this to Main Target. Also Do not add QGSdk to these targets.

For example:
Your Podfile may look like:

# Uncomment the next line to define a global platform for your project
# platform :ios, '9.0'

target 'ContentExtensionTarget' do
  # Uncomment the next line if you're using Swift or would like to use dynamic frameworks
  # use_frameworks!

  pod 'qgnotification'
end

target 'ServiceExtensionTarget' do
  # Uncomment the next line if you're using Swift or would like to use dynamic frameworks
  # use_frameworks!

  pod 'qgnotification'
end

target 'MainTarget' do
  # Uncomment the next line if you're using Swift or would like to use dynamic frameworks
  # use_frameworks!

  #add QGSdk to main Target
  pod 'quantumgraph'
end

To install the pod run 'pod install'

To update to a specific version, you can add:
pod 'qgnotification', '3.2.0' #3.2.0 is the version no.
