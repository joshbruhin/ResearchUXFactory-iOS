//
//  SBAParticipantInfo.h
//  ResearchUXFactory
//
//  Copyright © 2017 Sage Bionetworks. All rights reserved.
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

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The `SBAParticipantInfo` protocol holds references to information that might
 either be stored locally only and/or pushed to the server.
 */
@protocol SBAParticipantInfo <NSObject>

/**
 This can either be the full name or the given name for the user. (First name in Western cultures)
 */
@property (nonatomic, copy, nullable) NSString *name;

/**
 Family name. If this field is used, then `name` is assumed to be the given name.
 */
@property (nonatomic, copy, nullable) NSString *familyName;

/**
 Birthdate can be used to verify eligibility and consent.
 */
@property (nonatomic, copy, nullable) NSDate *birthdate;

/**
 A list of data groups that can be assigned to a user to subcategorize them.
 */
@property (nonatomic, copy, nullable) NSArray<NSString *> *dataGroups;

/**
 Is this a test user?
 */
@property (nonatomic, readonly) BOOL isTestUser;

/**
 Set the value of the stored answer for the given key.
 
 @param storedAnswer    The value to store
 @param key             The key associated with the given value
 */
- (void)setStoredAnswer:(id _Nullable)storedAnswer forKey:(NSString *)key;

/**
 Get the stored answer for the given key.
 
 @param key             The key associated with the given value
 @return                The stored value (if any)
 */
- (id _Nullable)storedAnswerForKey:(NSString *)key NS_SWIFT_NAME(storedAnswer(for:));

@end

NS_ASSUME_NONNULL_END
