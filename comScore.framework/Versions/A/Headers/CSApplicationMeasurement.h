//
//  CSApplicationMeasurement.h
//  comScore
//

// Copyright 2011 comScore, Inc. All right reserved.
//

#import <Foundation/Foundation.h>
#import "CSComScoreMeasurement.h"


@interface CSApplicationMeasurement : CSComScoreMeasurement {

}

-(id) initWithDax:(CSComScore *)dax;
-(id) initWithDax:(CSComScore *)dax withApplicationEventType:(CSApplicationEventType) type withDictionary:(NSDictionary *) details withPixelURL:(NSString *) pixelURL;

+ (CSApplicationMeasurement *) newApplicationMeasurement:(CSComScore *) dax withType:(CSApplicationEventType) type withDictionary:(NSDictionary *) details withPixelURL:(NSString *) pixelURL;

@end
