//
//  CarouselNotificationViewController.m
//  SampleAppSwift
//
// Created by Synerise
// Copyright (c) 2020 Synerise. All rights reserved.
//

#import "CarouselNotificationViewController.h"

@implementation CarouselNotificationViewController

- (void)didReceiveNotification:(UNNotification *)notification{
    SNRSynerise.settings.sdk.appGroupIdentifier = @"YOUR_APP_GROUP_IDENTIFIER";
    [self setSyneriseNotification:notification];
}
- (void)didReceiveNotificationResponse:(UNNotificationResponse *)response completionHandler:(void (^)(UNNotificationContentExtensionResponseOption))completion{
    [self setSyneriseNotificationResponse:response completionHandler:completion];
}

@end
