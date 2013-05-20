//
//  CSEvent.h
//  comScore
//

// Copyright 2011 comScore, Inc. All right reserved.
//

#import <Foundation/Foundation.h>

@interface CSEvent : NSNotification {

}

-(id) initWithType: (NSString *) t;
// Analytics Event type.
@property (nonatomic, retain) NSString *type;

@end
