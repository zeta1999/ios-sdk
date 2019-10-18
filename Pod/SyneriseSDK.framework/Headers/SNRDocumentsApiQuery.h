//
//  SNRDocumentsApiQuery.h
//  SyneriseSDK
//
//  Created by Synerise
//  Copyright (c) 2019 Synerise. All rights reserved.
//

/**
 * @enum SNRDocumentsApiQueryType
 */

typedef NS_ENUM(NSInteger, SNRDocumentsApiQueryType) {
    SNRDocumentsApiQueryTypeBySchema
} NS_SWIFT_NAME(DocumentsApiQueryType);

NS_ASSUME_NONNULL_BEGIN

/**
 * @class SNRDocumentsApiQuery
 */

NS_SWIFT_NAME(DocumentsApiQuery)
@interface SNRDocumentsApiQuery : NSObject

@property (assign, nonatomic, readwrite) SNRDocumentsApiQueryType type;
@property (copy, nonatomic, nullable, readwrite) NSString *typeValue;

@property (copy, nonatomic, nullable, readwrite) NSString *version;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithType:(SNRDocumentsApiQueryType)type typeValue:(NSString *)typeValue NS_SWIFT_NAME(init(type:typeValue:));

@end

NS_ASSUME_NONNULL_END