// 
//  SNRSingleMediaContentExtensionViewController.h
//  SyneriseSDK
//
//  Created by Synerise
//  Copyright (c) 2020 Synerise. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>
#import <UserNotificationsUI/UserNotificationsUI.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const SNRSingleMediaContentExtensionViewControllerCategoryIdentifier;

/**
 * @class SNRSingleMediaContentExtensionViewController
 */

API_AVAILABLE(ios(10.0))
NS_SWIFT_NAME(SingleMediaContentExtensionViewController)
@interface SNRSingleMediaContentExtensionViewController : UIViewController

@property (assign, nonatomic, readwrite) BOOL automaticallyAdjustContentViewSize;
@property (assign, nonatomic, readwrite) UIViewContentMode imageContentMode;


- (void)setSyneriseNotification:(UNNotification *)notification API_AVAILABLE(ios(10.0));
- (void)setSyneriseNotificationResponse:(UNNotificationResponse *)response completionHandler:(void (^)(UNNotificationContentExtensionResponseOption))completion API_AVAILABLE(ios(10.0));

@end

NS_ASSUME_NONNULL_END
