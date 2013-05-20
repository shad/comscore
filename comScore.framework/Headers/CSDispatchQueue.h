//
//  CSQueue.h
//  comScore
//
//  Created by Agustín Prats on 4/11/12.
//  Copyright (c) 2012 comScore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSAggregateMeasurement.h"
#import "CSQueue.h"

#define DAY_CHECK_OFFSET @"q_dcf"
#define DAY_CHECK_COUNTER @"q_dcc"
#define MILLIS_PER_SECOND 1000
#define MILLIS_PER_DAY 1000L * 60L * 60L * 24L

@interface CSDispatchQueue : CSQueue {
    
    dispatch_queue_t dispatchQueue_;
    CSAggregateMeasurement *aggregateData_;
    int eventCounter_;
    CSComScore *dax;
}

@property double secondEventCheckOffset;
@property int secondEventCheckCounter;
@property double dayEventCheckOffset;
@property int dayEventCheckCounter;

- (id) initWithDax:(CSComScore *)aDax;
- (void) loadEventData;
- (BOOL) checkCounters;
- (void) enqueueMeasurement:(CSMeasurement *)measurement;
- (void) enqueueCacheFlush;
- (void) processAggregateDataIn:(CSMeasurement *)measurement;
- (void) processEventCounter:(CSMeasurement *)measurement;

@end
