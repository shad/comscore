//
//  CSKeepAlive.h
//  comScore
//
//  Created by Agustín Prats on 7/23/12.
//  Copyright (c) 2012 comScore. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CSComScore;

@interface CSKeepAlive : NSObject {
    
    NSTimer *timer_;
    CSComScore *dax;
}

-(id) initWithDax:(CSComScore *)aDax;
- (void) sendAfter:(NSTimeInterval)millis;
- (void) cancel;
- (void) sendKeepAlive;
- (void) processKeepAlive:(BOOL) saveInCache;

@end
