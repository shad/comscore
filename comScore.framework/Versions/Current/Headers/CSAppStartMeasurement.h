//
//  CSAppStartMeasurement.h
//  comScore
//

// Copyright 2011 comScore, Inc. All right reserved.
//

#import <Foundation/Foundation.h>
#import "CSApplicationMeasurement.h"


@interface CSAppStartMeasurement : CSApplicationMeasurement {

}

-(id) initWithDax:(CSComScore *)dax withApplicationEventType:(CSApplicationEventType) type withDictionary:(NSDictionary *) details withPixelURL:(NSString *) pixelURL;

@end
