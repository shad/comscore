//
//  CSMeasurement.h
//  comScore
//

// Copyright 2011 comScore, Inc. All right reserved.
//

#import <Foundation/Foundation.h>
#import "CSEventArgs.h"
#import "CSLabel.h"
#import "CSPrivilegedLabel.h"

@class CSComScore;

// Base class for the different available Measurements.
@interface CSMeasurement : NSObject {
	NSMutableDictionary *labelsMap;
	double created;
}

// Measurement constructors.
-(id) initWithDax:(CSComScore *)dax;
-(id) initWithDax:(CSComScore *)dax withDictionary: (NSDictionary *) list;
-(id) initWithEventArgs: (CSEventArgs *) e;

-(void) setLabel: (NSString *) name value:(NSString *) val aggregate:(BOOL) aggr;
-(void) setLabel: (NSString *) name value:(NSString *) val;
-(CSLabel *) getLabel: (NSString *) name;
-(BOOL) hasLabel: (NSString *) name;
-(NSString *) package;
-(NSDictionary *)getLabels;

@property (nonatomic, retain) NSString *pixelURL;

//Custom methods
-(NSString *) retrieveLabelsAsString;
-(void) appendLabel: (CSLabel *) label;
-(void) appendLabel: (NSString *) name value: (NSString *) val aggregate: (BOOL) aggr nedstatPrivilege: (BOOL) np;
-(void) removeLabel: (NSString *) name aggregate: (BOOL) aggr nedstatPrivilege: (BOOL) nedstatPrivilege;
-(void) setLabel: (NSString *) name value:(NSString *) val aggregate:(BOOL) aggr nedstatPrivilege:(BOOL) np;
-(void) setLabel: (CSLabel *) label;
-(NSString *) getLabelValue: (NSString *) name;

@end
