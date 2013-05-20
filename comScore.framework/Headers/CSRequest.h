//
//  CSRequest.h
//  comScore
//

// Copyright 2011 comScore, Inc. All right reserved.
//

#import <Foundation/Foundation.h>
#import "CSMeasurement.h"


@interface CSRequest : NSObject {
	NSURLRequest *req;
	NSURLConnection *conn;
	NSMutableData *receivedData;
    CSComScore *dax;
}

-(id) initWithDax:(CSComScore *)aDax andMeasurement:(CSMeasurement *) m;
-(NSURL *) process: (NSString *) basePixelURL;
-(NSURL *) process;
-(BOOL) send;
-(BOOL) availableConnection;

@property (nonatomic, retain) CSMeasurement *measurement;

@end
