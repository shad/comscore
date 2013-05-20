//
//  CSComScoreMeasurement.h
//  comScore
//

// Copyright 2011 comScore, Inc. All right reserved.
//

#import <Foundation/Foundation.h>
#import "CSMeasurement.h"
#import "CSEventType.h"


@interface CSComScoreMeasurement : CSMeasurement {

}

-(id) initWithDax:(CSComScore *)dax;
-(id) initWithDax:(CSComScore *)dax withEventType:(CSAnalyticsEventType) type withDictionary:(NSDictionary *) details withPixelURL:(NSString *) pixelURL;

+ (CSComScoreMeasurement *) newAnalyticsMeasurement:(CSComScore *)dax withType:(CSAnalyticsEventType) type withDictionary:(NSDictionary *) details withPixelURL:(NSString *)pixelURL;
- (CSAnalyticsEventType)getAnalyticsEventType;

@end
