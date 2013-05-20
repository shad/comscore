//
//  CSEventType.h
//  comScore
//

// Copyright 2011 comScore, Inc. All right reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
	View,
	Hidden
} CSAnalyticsEventType;

typedef enum {
	BeforeDispatch,
	Dispatch
} CSDispatchingEventType;

typedef enum {
	Start,
	AppView,
	Close,
	Aggregate,
    AppHidden,
    AppKeepAlive
} CSApplicationEventType;

extern NSString* const AnalyticsEventType_toString[2];
extern NSString* const DispatchingEventType_toString[2];
extern NSString* const ApplicationEventType_toString[6];