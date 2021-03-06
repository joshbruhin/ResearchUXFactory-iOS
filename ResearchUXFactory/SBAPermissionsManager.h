// 
//  SBAPermissionsManager.h 
//  ResearchUXFactory
//
//  Copyright © 2016 Sage Bionetworks. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
// 1.  Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
//
// 2.  Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation and/or
// other materials provided with the distribution.
//
// 3.  Neither the name of the copyright holder(s) nor the names of any contributors
// may be used to endorse or promote products derived from this software without
// specific prior written permission. No license is granted to the trademarks of
// the copyright holders even if such marks are included in this software.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
 
#import <UIKit/UIKit.h>
#import <HealthKit/HealthKit.h>
#import "SBADefines.h"

NS_ASSUME_NONNULL_BEGIN

@class SBAPermissionObjectType;
@class SBAPermissionObjectTypeFactory;

typedef NS_OPTIONS(NSUInteger, SBAPermissionsType) {
    SBAPermissionsTypeNone                      = 0,
    SBAPermissionsTypeHealthKit __attribute__((deprecated("Not supported. Use SBAHealthKitPermissionObjectType."))) = 1 << 1,
    SBAPermissionsTypeLocation                  = 1 << 2,
    SBAPermissionsTypeLocalNotifications        = 1 << 3,
    SBAPermissionsTypeCoremotion                = 1 << 4,
    SBAPermissionsTypeMicrophone                = 1 << 5,
    SBAPermissionsTypeCamera                    = 1 << 6,
    SBAPermissionsTypePhotoLibrary              = 1 << 7,
};

typedef NSString * SBAPermissionTypeIdentifier NS_STRING_ENUM;

ENUM_EXTERN SBAPermissionTypeIdentifier const SBAPermissionTypeIdentifierHealthKit;
ENUM_EXTERN SBAPermissionTypeIdentifier const SBAPermissionTypeIdentifierLocation;
ENUM_EXTERN SBAPermissionTypeIdentifier const SBAPermissionTypeIdentifierNotifications;
ENUM_EXTERN SBAPermissionTypeIdentifier const SBAPermissionTypeIdentifierCoremotion;
ENUM_EXTERN SBAPermissionTypeIdentifier const SBAPermissionTypeIdentifierMicrophone;
ENUM_EXTERN SBAPermissionTypeIdentifier const SBAPermissionTypeIdentifierCamera;
ENUM_EXTERN SBAPermissionTypeIdentifier const SBAPermissionTypeIdentifierPhotoLibrary;

typedef NS_ENUM(NSUInteger, SBAPermissionStatus) {
    SBAPermissionStatusNotDetermined = 0,
    SBAPermissionStatusDenied,
    SBAPermissionStatusAuthorized,
};

typedef NS_ENUM(NSUInteger, SBAPermissionsErrorCode) {
    SBAPermissionsErrorCodeAccessDenied = -100,
};

typedef void(^SBAPermissionsBlock)(BOOL granted, NSError * _Nullable error);

@interface SBAPermissionsManager : NSObject

+ (instancetype)sharedManager NS_REFINED_FOR_SWIFT;

/**
 Shared healthstore object
 */
@property (nonatomic, readonly) HKHealthStore * _Nullable healthStore;

/**
 Factory to use for creating permissions type objects. By default, this uses the base class factorty.
 */
@property (nonatomic, readwrite, strong) SBAPermissionObjectTypeFactory *permissionsTypeFactory;

/**
 Default permission types to display on startup.
 */
@property (nonatomic, readwrite, strong) NSArray<SBAPermissionObjectType *> *defaultPermissionTypes;

/**
 Callback from the app delegate that the user has registered for notifications.
 */
- (void)appDidRegisterForNotifications:(UIUserNotificationSettings *)settings;

/**
 Is permission granted for the given permission object type?
 
 @param  permissionType   Model object with the type of permission to request
 @return                  `YES` if granted, `NO` if not granted
 */
- (BOOL)isPermissionGrantedForType:(SBAPermissionObjectType *)permissionType;

/**
 Request permission for the given permission type.
 
 @param permissionType   Model object with the type of permission to request
 @param completion       Completion handler
 */
- (void)requestPermissionForType:(SBAPermissionObjectType *)permissionType
                      completion:(SBAPermissionsBlock _Nullable)completion;


// Deprecated methods included for reverse-compatibility

- (SBAPermissionsType)permissionsTypeForPermissionObjectTypes:(NSArray<SBAPermissionObjectType *> *)objectTypes __attribute__((deprecated));

- (SBAPermissionTypeIdentifier _Nullable)typeIdentifierForForType:(SBAPermissionsType)type __attribute__((deprecated));

- (NSArray<SBAPermissionObjectType *> *)typeObjectsForForType:(SBAPermissionsType)type __attribute__((deprecated));

- (BOOL)isPermissionsGrantedForType:(SBAPermissionsType)type __attribute__((deprecated));

- (void)requestPermissionForType:(SBAPermissionsType)type
                  withCompletion:(SBAPermissionsBlock _Nullable)completion __attribute__((deprecated));

@end

NS_ASSUME_NONNULL_END
