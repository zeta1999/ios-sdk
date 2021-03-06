//
//  SNRSettings.h
//  SyneriseSDK
//
//  Created by Synerise
//  Copyright (c) 2020 Synerise. All rights reserved.
//

#import "SNRNotificationsSettings.h"
#import "SNRGeneralSettings.h"
#import "SNRNotificationsSettings.h"
#import "SNRTrackerSettings.h"
#import "SNRInjectorSettings.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @class SNRSettings
 */

NS_SWIFT_NAME(Settings)
@interface SNRSettings : NSObject

@property (strong, nonatomic, nonnull, readonly) SNRGeneralSettings *sdk;
@property (strong, nonatomic, nonnull, readonly) SNRNotificationsSettings *notifications;
@property (strong, nonatomic, nonnull, readonly) SNRTrackerSettings *tracker;
@property (strong, nonatomic, nonnull, readonly) SNRInjectorSettings *injector;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
