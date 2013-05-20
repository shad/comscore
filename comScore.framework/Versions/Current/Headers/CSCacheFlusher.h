//
//  CSCacheFlusher.h
//  comScore
//
//  Created by Szymon Ulewicz on 11/22/12.
//  Copyright (c) 2012 comScore. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CSComScore;

@interface CSCacheFlusher : NSObject {
    CSComScore *dax;
    NSTimer *timer;
    bool isForeground;
}

-(id) initWithDax:(CSComScore *)aDax;
-(void) start;
-(void) stop;
-(void) reset;
@end