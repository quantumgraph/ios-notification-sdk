//
//  QGNotificationSdk.h
//  QGNotificationSdk
//
//  Created by qgraph on 05/08/16.
//  Copyright © 2016 QuantumGraph. All rights reserved.
//
//  NOTE:
//  Add all the files associated with QGNotificationSdk to Targets UNNotification Content Extension and
//  UNNotification Service Extension only.
//
//  Do not add QGSdk to these Targets. For logging any event, use the api in QGNotificationSdk.
//  QGSdk should not used any extension. Should be used in Main Project Target only.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>
#import <UserNotificationsUI/UserNotificationsUI.h>
#import "iCarousel.h"

@interface QGNotificationSdk : NSObject

/*!
 @method
 
 @abstract
 Returns the previously instantiated singleton instance of the the SDK API.
 
 @discussion
 The SDK API must be initialized with <code>sharedInstanceWithAppGroup:</code> before
 calling this class method.
 */
+ (QGNotificationSdk *)sharedInstance;

/*!
 @method
 
 @abstract
 Initializes and Returns a singleton instance of the SDK API.
 
 @discussion
 This must be called first to initialise the API with APP GROUP.
 APP GROUP is required to talk to the QGSDK and logging any events through this API.
 
 Before using @code sharedInstance @endcode approach
 @code sharedInstanceWithAppGroup: @endcode <b>must be the first call</b> to the
 @code QGNotificationSdk @endcode class, since it performs important initialization to the API.
 
 @param appGroup        Your project APP GROUP
 
 */
+ (QGNotificationSdk *)sharedInstanceWithAppGroup:(NSString *)appGroup;

/*!
 @method
 
 @abstract
 Returns handler with UNNotificationContent for the UNNotification Service Extension.
 
 @discussion
 This downloads and returns the content to be shown in the push notification.
 Works for remote notification with <b>mutable-content: 1</b> in iOS 10 and above.
 
 Before using this API must be initialized with APP GROUP.
 
 Handles notifications only sent through QGraph else returns payload
 without modication.
 
 @param request         UNNotificationRequest received in the notification
 
 */
- (void)didReceiveNotificationRequest:(UNNotificationRequest *)request withContentHandler:(void (^)(UNNotificationContent *))contentHandler;

/*!
 @method
 
 @abstract
 Returns the default standard notification if time out
 
 @discussion
 Will return default notification content without any attachment if time out occured while downloading the content for notification

 */
- (void)serviceExtensionTimeWillExpire;


/*!
 @method
 
 @abstract
 Initializes Carousel in the UNNotification Content Extension.
 
 @discussion
 To be called in <code>viewDidLoad</code> of the NotificationViewController of the content extension.
 Setup the carousel to be shown in the custom notification.
 
 Before calling this method, <code>sharedInstanceWithAppGroup</code> must be
 called to initialize the <code>QGNotificationSdk</code> class.
 
 @param carousel        Instance of the carousel outlet
 */
- (void)viewDidLoadWithCarousel:(iCarousel *)carousel;

/*!
 @method
 
 @abstract
 Handles the Custom Notification when received and loads the Carousel.
 
 @discussion
 This method is required to reload the Carousel with appropriate content when the notification is received.
 
 Should be called in <code>didReceiveNotification:</code> method of the
 Content Extension Notification View Controller.
 
 @param notification     UNNotification object received
 
 */
- (void)didReceiveNotification:(UNNotification *)notification;

/*!
 @method
 
 @abstract
 Handles the Action Buttons in the Custom Carousel Notification.
 
 @discussion
 Handles actions in Category <b>QGCAROUSEL</b> and returns handler with
 UNNotificationContentExtensionResponseOption and NSURL (deepLink).
 
 While setting up the sdk, register action category QGCAROUSEL with actions
 <b>next</b> and <b>openApp</b> in your APP DELEGATE.
 next refreshes the carousel index and openApp handles deepLinking passed in the Payload, if any.
 
 API Will pass the deepLink only and not handle it. To handle your deepLink in your
 APP DELEGATE, implement <code>application:openURL:options:</code>.
 
 @param response        UNNotificaitonResponse object
 
 */
- (void)didReceiveNotificationResponse:(UNNotificationResponse *)response completionHandler:(void (^)(UNNotificationContentExtensionResponseOption, NSURL *))completion;

/*!
 @method
 
 @abstract
 Returns the number of items in the carousel.
 
 @discussion
 Returns number of items to be shown in the carosuel based on the
 number of attachments in the notification payload.
 
 Before using this method make to add <b>iCarouselDelegate</b> in your
 NotificationViewController class.
 
 @code
 [[QGNotificationSdk sharedInstance] numberOfItemsInCarousel:carousel]
 @endcode
 
 */
- (NSInteger)numberOfItemsInCarousel:(iCarousel *)carousel;

/*!
 @method
 
 @abstract
 Returns View to be shown at a particular index of the carousel.
 
 @discussion
 Creates or reuses a view to be shown at the index of the carousel.
 
 Before using this method, make sure to add <b>iCarouselDataSource</b> in
 your NotificationViewController class.
 
 @code
 [[QGNotificationSdk sharedInstance] carousel:carousel viewForItemAtIndex:index reusingView:view]
 @endcode
 
 */
- (UIView *)carousel:(iCarousel *)carousel viewForItemAtIndex:(NSInteger)index reusingView:(UIView *)view;

/*!
 @method
 
 @abstract
 Returns value for iCarouselOption as per the carousel type.
 
 @discussion
 Calculates and returns the value for the desired layout of the carousel type.
 May return default value for some iCarouselOption.
 
 @note
 <b>Do not</b> alter these values for options or carousel layout may disallign
 
 @code
 [[QGNotificationSdk sharedInstance] carousel:carousel valueForOption:option withDefault:value]
 @endcode
 
 */
- (CGFloat)carousel:(iCarousel *)carousel valueForOption:(iCarouselOption)option withDefault:(CGFloat)value;

/*!
 @method
 
 @abstract
 Returns the width of the card in the carousel
 
 @discussion
 Calculates the width of the card in the carousel based on the type of the push.
 
 @code
 [[QGNotificationSdk sharedInstance] carouselItemWidth:carousel]
 @endcode
 */
- (CGFloat)carouselItemWidth:(iCarousel *)carousel;

/*!
 @method
 
 @abstract
 Logs any event from the Service extension or Content Extension
 
 @discussion
 Used to log event with some parameter and value associated with it.
 SDK automatically logs defaults system events, eg: notification_clicked
 
 @note
 Event logging through extension (UNNotification Service Extension and UNNotification Content Extension)
 should be done by this api.
 @code logEvent: @endcode api and related apis in QGSdk should not be used in extensions
 
 @param name        name of the event
 @param parameters  parameters as dictionary
 @param valueToSum  monetary value asscoiated with the event
 
 */
- (void)logEvent:(NSString *)name withParameters:(NSDictionary *)parameters withValueToSum:(NSNumber *)valueToSum;

@end
