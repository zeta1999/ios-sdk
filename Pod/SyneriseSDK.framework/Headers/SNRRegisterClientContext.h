//
//  SNRClientRegisterContext.h
//  SyneriseSDK
//
//  Copyright © 2018 Synerise. All rights reserved.
//

#import "SNRBaseContext.h"
#import "SNRClientSex.h"
#import "SNRClientAgreements.h"

/**
 * @enum SNRRegisterClientContextRegistrationType
 */
typedef NS_ENUM(NSInteger, SNRRegisterClientContextRegistrationType) {
    SNRRegisterClientContextRegistrationTypeByEmailWithoutActivation,
    SNRRegisterClientContextRegistrationTypeByEmail,
    SNRRegisterClientContextRegistrationTypeByPhone
} NS_SWIFT_NAME(RegistrationType);

/**
 Register context to @c [SNRClient registerClient] method
 */

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(RegisterClientContext)
@interface SNRRegisterClientContext : SNRBaseContext

/**
 * @attention Setters can throw exception.
 *
 * @note Email should be valid email address.
 * @note Phone number should match ^(\\+[0-9]{6,19})|([0-9]{6,20})$ regex pattern.
 *
 * @throws SNRInvalidEmailException for Obj-C and SNRInvalidEmailError for Swift if an email is invalid.
 * @throws SNRInvalidPhoneNumberException for Obj-C and SNRInvalidPhoneNumberError for Swift if a phone number is invalid.
 */

@property (copy, nonatomic, nullable, readwrite) NSString *address;
@property (copy, nonatomic, nullable, readwrite) SNRClientAgreements *agreements;
@property (copy, nonatomic, nullable, readwrite) NSDictionary *attributes;
@property (copy, nonatomic, nullable, readwrite) NSString *city;
@property (copy, nonatomic, nullable, readwrite) NSString *company;

// Country code, e.g. "pl" (ISO  nullable,3166-1 alpha-2)
@property (copy, nonatomic, nullable, readwrite) NSString *countryCode;
@property (copy, nonatomic, nullable, readwrite) NSString *customId;
@property (copy, nonatomic, nullable, readwrite) NSString *email;
@property (copy, nonatomic, nullable, readwrite) NSString *firstName;
@property (copy, nonatomic, nullable, readwrite) NSString *lastName;
@property (copy, nonatomic, nonnull, readwrite) NSString *password;
@property (copy, nonatomic, nullable, readwrite) NSString *phone;
@property (copy, nonatomic, nullable, readwrite) NSString *province;
@property (assign, nonatomic, readwrite) SNRClientSex sex;
@property (copy, nonatomic, nullable, readwrite) NSString *tags;
@property (copy, nonatomic, nullable, readwrite) NSString *zipCode;

@property (assign, nonatomic, readwrite) SNRRegisterClientContextRegistrationType registrationType;

- (instancetype)init __unavailable;
+ (instancetype)new __unavailable;

/**
 * @note Email should be valid email address.
 *
 * @throws SNRInvalidEmailException for Obj-C and SNRInvalidEmailError for Swift if an email is invalid.
 */
- (instancetype)init:(NSString *)email
            password:(NSString *)password;


/**
 * @note Email should be valid email address.
 *
 * @throws SNRInvalidEmailException for Obj-C and SNRInvalidEmailError for Swift if an email is invalid.
 */
- (instancetype)initWithEmailWithoutActivation:(NSString *)email
                                      password:(NSString *)password;

/**
 * @note Phone number should match ^(\\+[0-9]{6,19})|([0-9]{6,20})$ regex pattern.
 *
 * @throws SNRInvalidPhoneNumberException for Obj-C and SNRInvalidPhoneNumberError for Swift if a phone number is invalid.
 */
- (instancetype)initWithPhoneNumber:(NSString *)phoneNumber
                           password:(NSString *)password;

@end

NS_ASSUME_NONNULL_END
