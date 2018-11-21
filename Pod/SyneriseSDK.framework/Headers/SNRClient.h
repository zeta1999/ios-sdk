//
//  SNRClient.h
//  SyneriseSDK
//
//  Created by Synerise
//  Copyright © 2018 Synerise. All rights reserved.
//

@class SNRClientRegisterAccountContext;
@class SNRClientAccountInformation;
@class SNRClientUpdateAccountContext;
@class SNRClientPasswordResetRequestContext;
@class SNRClientPasswordResetConfirmationContext;

NS_ASSUME_NONNULL_BEGIN

/**
 * @class SNRClient
 */

NS_SWIFT_NAME(Client)
@interface SNRClient : NSObject

- (instancetype)init __unavailable;
+ (instancetype)new __unavailable;

/**
 * This method enables/disables console logs from Client SDK.
 * It is not recommended to use debug mode in release version of your application.
 *
 * @param enabled Specifies that console logs are enabled/disabled.
 */
+ (void)setLoggingEnabled:(BOOL)enabled;

/**
 * Register new Client with email with activation, with email without activation or with phone (depending on context model), password and optional data.
 * Please note that you should NOT allow to sign in again (or sign up) when a user is already signed in. Please sign out user first.
 * Moreover, please do not create multiple instances nor call this method multiple times before execution.
 *
 * @param context SNRClientRegisterAccountContext object with client's email, password, and other optional data. Not provided fields are not modified.
 * @param success A block when operation is success.
 * @param failure A block when operation is failure.
 */
+ (void)registerAccount:(SNRClientRegisterAccountContext *)context
                success:(nullable void (^)(BOOL isSuccess))success
                failure:(nullable void (^)(NSError *error))failure NS_SWIFT_NAME(registerAccount(context:success:failure:));

/*
 * Activates client's account.
 *
 * @param email Client’s email.
 * @param success A block when operation is success.
 * @param failure A block when operation is failure.
 */
+ (void)activateAccount:(NSString *)email
                success:(nullable void (^)(BOOL isSuccess))success
                failure:(nullable void (^)(NSError *error))failure NS_SWIFT_NAME(activateAccount(email:success:failure:));

/**
 * Log in a client in order to obtain the JWT token, which could be used in subsequent requests. The token is valid for 1 hour.
 * This SDK will refresh token before each call if it is expiring (but not expired).
 * Please note that you should not allow to sign in again (or sign up) when a user is already signed in. Please sign out user first.
 * Moreover, please do not create multiple instances nor call this method multiple times before execution.
 *
 * @param email Client's email.
 * @param password Client's password.
 * @param deviceId Device identificator.
 * @param success A block when operation is success.
 * @param failure A block when operation is failure.
 */
+ (void)signInWithEmail:(NSString *)email
               password:(NSString *)password
               deviceId:(nullable NSString *)deviceId
                success:(nullable void (^)(BOOL isSuccess))success
                failure:(nullable void (^)(NSError *error))failure NS_SWIFT_NAME(signIn(email:password:deviceId:success:failure:));

/**
 * Use this method to obtain client's authorization token by Facebook.
 *
 * @param facebookToken Token from Facebook active session.
 * @param success A block when operation is success.
 * @param failure A block when operation is failure.
 */
+ (void)authenticateByFacebookToken:(NSString *)facebookToken
                            success:(nullable void (^)(BOOL isSuccess))success
                            failure:(nullable void (^)(NSError *error))failure NS_SWIFT_NAME(authenticate(facebookToken:success:failure:));

/**
 * Retrieve whether client is signed in (is client's token not expired).
 */
+ (BOOL)isSignedIn;

/**
 * Logs out client.
 */
+ (void)signOut NS_SWIFT_NAME(signOut());

/**
 * Retrieves current client authentication token. This method provides valid token if client is logged in and current token is not expired.
 *
 * @param success A block when operation is success.
 * @param failure A block when operation is failure.
 */
+ (void)getTokenWithSuccess:(nullable void (^)(NSString *token))success
                    failure:(nullable void (^)(NSError *error))failure NS_SWIFT_NAME(getToken(success:failure:));

/**
 * Retrieve current client's UUID.
 */
+ (NSString *)getUUID;

/**
 * Get client's account information.
 *
 * @param success A block when operation is success.
 * @param failure A block when operation is failure.
 */
+ (void)getAccountWithSuccess:(nullable void (^)(SNRClientAccountInformation *accountInformation))success
                      failure:(nullable void (^)(NSError *error))failure NS_SWIFT_NAME(getAccount(success:failure:));

/**
 * Update client's account information with optional data.
 *
 * @param context SNRClientUpdateAccountContext object with client's account information to be modified. Not provided fields are not modified.
 * @param success A block when operation is success.
 * @param failure A block when operation is failure.
 */
+ (void)updateAccount:(SNRClientUpdateAccountContext *)context
              success:(nullable void (^)(BOOL isSuccess))success
              failure:(nullable void (^)(NSError *error))failure NS_SWIFT_NAME(updateAccount(context:success:failure:));

/**
 * Requests client's password reset with email. A client will receive a token on the provided email address in order to use.
 *
 * @param context SNRClientPasswordResetRequestContext object with client's email.
 * @param success A block when operation is success.
 * @param failure A block when operation is failure.
 */
+ (void)requestPasswordReset:(SNRClientPasswordResetRequestContext *)context
                     success:(nullable void (^)(BOOL isSuccess))success
                     failure:(nullable void (^)(NSError *error))failure NS_SWIFT_NAME(requestPasswordReset(context:success:failure:));

/**
 * Confirms client's password reset with new password and token provided.
 *
 * @param context SNRClientPasswordResetConfirmationContext object with client's password and token.
 * @param success A block when operation is success.
 * @param failure A block when operation is failure.
 */
+ (void)confirmResetPassword:(SNRClientPasswordResetConfirmationContext *)context
                     success:(nullable void (^)(BOOL isSuccess))success
                     failure:(nullable void (^)(NSError *error))failure NS_SWIFT_NAME(confirmResetPassword(context:success:failure:));

/**
 * Change client's password.
 *
 * @param password Client's new password.
 * @param oldPassword Client's old password.
 * @param success A block when operation is success.
 * @param failure A block when operation is failure.
 */
+ (void)changePassword:(NSString *)password
           oldPassword:(NSString *)oldPassword
               success:(nullable void (^)(BOOL isSuccess))success
               failure:(nullable void (^)(NSError *error))failure NS_SWIFT_NAME(changePassword(password:oldPassword:success:failure:));

/**
 * Update client's phone number request.
 *
 * @param phone Client's phone number.
 * @param success A block when operation is success.
 * @param failure A block when operation is failure.
 */
+ (void)requestPhoneUpdate:(NSString *)phone
                   success:(nullable void (^)(BOOL isSuccess))success
                   failure:(nullable void (^)(NSError *error))failure NS_SWIFT_NAME(requestPhoneUpdate(phone:success:failure:));

/**
 * Confirm client's phone number update.
 *
 * @param phone Client's phone number.
 * @param confirmationCode Client's confirmation code received by phone.
 * @param success A block when operation is success.
 * @param failure A block when operation is failure.
 */
+ (void)confirmPhoneUpdate:(NSString *)phone
          confirmationCode:(NSString *)confirmationCode
                   success:(nullable void (^)(BOOL isSuccess))success
                   failure:(nullable void (^)(NSError *error))failure NS_SWIFT_NAME(confirmPhoneUpdate(phone:confirmationCode:success:failure:));

/**
 * Delete client's account information.
 *
 * @param success A block when operation is success.
 * @param failure A block when operation is failure.
 */
+ (void)deleteAccountWithSuccess:(nullable void (^)(BOOL isSuccess))success
                         failure:(nullable void (^)(NSError *error))failure NS_SWIFT_NAME(deleteAccount(success:failure:));

/**
 * Registers user for push notifications.
 *
 * @param registrationToken Firebase FCM Token returned after successful push notifications registration from Firebase.
 * @param success A block when operation is success.
 * @param failure A block when operation is failure.
 */
+ (void)registerForPush:(NSString *)registrationToken
                success:(nullable void (^)(BOOL isSuccess))success
                failure:(nullable void (^)(NSError *error))failure NS_SWIFT_NAME(registerForPush(registrationToken:success:failure:));

@end

NS_ASSUME_NONNULL_END








