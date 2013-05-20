//
//  CSEventArgs.h
//  comScore
//

// Copyright 2011 comScore, Inc. All right reserved.
//

#import <Foundation/Foundation.h>
#import "CSEvent.h"
#import "CSEventType.h"

@interface CSEventArgs : NSObject {

    NSString *pixelURL_; 
}

-(id) initWithEvent:(CSEvent *)e andDetails:(NSDictionary *)d withPixelURL:(NSString *) pixelURL; 
-(id) initWithEventType: (CSAnalyticsEventType) type withEvent: (CSEvent *) e andDetails: (NSDictionary *) d withPixelURL:(NSString *) pixelURL; 
-(id) initWithEventType: (CSAnalyticsEventType) type withEvent: (CSEvent *) e andDetails: (NSDictionary *) d;
-(id) initWithEvent: (CSEvent *) e andDetails: (NSDictionary *) d;
-(id) initWithEvent: (CSEvent *) e;
-(void) cancelEvent;

@property (assign) CSAnalyticsEventType eventType;
// Referred event.
@property (assign) CSEvent *event;
// NSTimeInterval containing a UNIX timestamp for the creation date.
@property (assign) NSTimeInterval created;
@property (assign) NSMutableDictionary *details;
@property (nonatomic, retain) NSString *pixelURL;

@end
