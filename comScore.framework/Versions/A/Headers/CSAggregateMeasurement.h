//
//  CSAggregateMeasurement.h
//  comScore
//

// Copyright 2011 comScore, Inc. All right reserved.
//

#import <Foundation/Foundation.h>
#import "CSApplicationMeasurement.h"


@interface CSAggregateMeasurement : CSApplicationMeasurement {

}

-(id) initWithDax:(CSComScore *)dax withApplicationEventType:(CSApplicationEventType) type withDictionary:(NSDictionary *) details withPixelURL:(NSString *) pixelURL;
-(NSArray *) getAggregateLabels;
-(void) aggregateLabels: (NSArray *) labelList;
-(void) formatLists;

@end
