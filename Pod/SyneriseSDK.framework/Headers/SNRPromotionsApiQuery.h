//
//  SNRPromotionsApiQuery.h
//  SyneriseSDK
//
//  Created by Synerise
//  Copyright (c) 2019 Synerise. All rights reserved.
//

#import "SNRPromotion.h"
#import "SNRPromotionStatus.h"
#import "SNRPromotionType.h"
#import "SNRApiQuerySortingOrder.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @class SNRPromotionsApiQuery
 */

NS_SWIFT_NAME(PromotionsApiQuery)
@interface SNRPromotionsApiQuery : NSObject

@property (copy, nonatomic, nonnull, readwrite) NSArray<SNRPromotionStatusString> *statuses;
@property (copy, nonatomic, nonnull, readwrite) NSArray<SNRPromotionTypeString> *types;

@property (copy, nonatomic, nonnull, readwrite) NSArray<NSDictionary<SNRPromotionSortingKey, SNRApiQuerySortingOrderString> *> *sorting;

@property (assign, nonatomic, readwrite) NSInteger limit;
@property (assign, nonatomic, readwrite) NSInteger page;

@property (assign, nonatomic, readwrite) BOOL includeMeta;

@end

NS_ASSUME_NONNULL_END
