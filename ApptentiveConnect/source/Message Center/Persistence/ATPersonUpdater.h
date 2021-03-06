//
//  ATPersonUpdater.h
//  ApptentiveConnect
//
//  Created by Andrew Wooster on 10/2/12.
//  Copyright (c) 2012 Apptentive, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ATAPIRequest.h"
#import "ATPersonInfo.h"

extern NSString *const ATPersonLastUpdateValuePreferenceKey;

@protocol ATPersonUpdaterDelegate;

@interface ATPersonUpdater : NSObject <ATAPIRequestDelegate>@property (nonatomic, weak) NSObject<ATPersonUpdaterDelegate> *delegate;

+ (BOOL)shouldUpdate;
+ (NSDictionary *)lastSavedVersion;

- (id)initWithDelegate:(NSObject<ATPersonUpdaterDelegate> *)delegate;
- (void)update;
- (void)cancel;
- (float)percentageComplete;
@end

@protocol ATPersonUpdaterDelegate <NSObject>
- (void)personUpdater:(ATPersonUpdater *)personUpdater didFinish:(BOOL)success;
@end
