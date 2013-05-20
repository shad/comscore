//
//  CSOfflineMeasurementFileCache.h
//  comScore
//
//  Created by Agustín Prats on 2/6/12.
//  Copyright (c) 2012 comScore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSApplicationMeasurement.h"
#import "CSMeasurement.h"

@interface CSOfflineMeasurementsCache : NSObject {
    
    NSURLConnection *connection_;
    
    NSMutableArray *arrayOfCacheFiles_;
    
    NSURLRequest *request_;
    
    int flushesInARow_;
    NSTimeInterval lastFlushDate_;
    NSTimeInterval lastFailDate_;
    
    // Common labels to be aggrupped in the header of the xml
    NSString *c12_;
    NSString *c1_;
    NSString *c4_;
    NSString *c10_;
    NSString *ns_ap_device_;
    NSString *ns_ak_;
    NSMutableString *concatedProcessedEvents_;
    
    CSComScore *dax;
}

-(id) initWithDax:(CSComScore *)aDax;
- (void) saveEvent:(NSString *)event;
- (int) getEventCount;
- (BOOL) isEmpty;
- (NSArray *)getNewestEventBatch;
- (BOOL) removeAllEvents;
- (BOOL) flush;
- (void) saveMeasurement:(CSMeasurement *)m;
- (void) saveMeasurementWithApplicationType:(CSApplicationEventType) type withLabels:(NSDictionary *)labels;
- (BOOL) isAutomaticFlushAllowed;

@property (nonatomic, assign) int maxSize;
@property (nonatomic, assign) int maxBatchSize;
@property (nonatomic, assign) int maxFlushesInARow;
@property (nonatomic, assign) int minutesToRetry;
@property (nonatomic, assign) int expiricyInDays;

@end
