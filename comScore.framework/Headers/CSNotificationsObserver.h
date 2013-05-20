//
//  CSNotificationsObserver.h
//  comScore
//
//  Created by Agustín Prats on 4/19/12.
//  Copyright (c) 2012 comScore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSComScore.h"

@interface CSNotificationsObserver : NSObject {
    @protected
    NSTimeInterval activeTimestamp_;
    NSTimeInterval foregroundTimestamp_;
    NSTimeInterval inactiveTimestamp_;
    CSComScore *dax;
}

-(id) initWithDax:(CSComScore *)aDax;
- (void) applicationWillCrash:(NSException *)exception;

@property (nonatomic, assign) NSTimeInterval foregroundTimestamp;
@property (nonatomic, assign) NSTimeInterval activeTimestamp;

@end
