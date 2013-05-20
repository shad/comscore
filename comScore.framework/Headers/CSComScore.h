//
//  CScomScore.h
//  comScore
//

// Copyright 2011 comScore, Inc. All right reserved.
//

#ifndef CSCOMSCORE_H
#define CSCOMSCORE_H

#import <Foundation/Foundation.h>
#import "CSEventType.h"
#import "CSReachability.h"
#import "CSTransmissionMode.h"
#import "CSAnalytics.h"
#import "CSCacheFlusher.h"

@class CSCensus, CSNotificationsObserver, CSOfflineMeasurementsCache, CSDispatchQueue, CSStorage, CSKeepAlive;

/**
 Nedstat ComScore analytics interface
 */
@interface CSComScore : NSObject {
    
    long long previousUsage_;
	NSString *customerID;
	NSString *visitorID;
	NSString *salt;
	NSString *appName;
	NSString *devModel;
	NSTimeInterval genesis;
	BOOL anonymous;
    NSMutableDictionary *customLabels;
    CSReachability *internetReachable_;
    BOOL keepAliveEnabled_;
    NSTimeInterval prevInactiveTime_;
    CSTransmissionMode liveTransmissionMode_;
    CSTransmissionMode offlineTransmissionMode_;
    long cacheFlushingInterval;
    BOOL sessionRestored_;
    BOOL secure_;
    NSString *crossPublisherId_;
    
    CSStorage *storage;
    CSDispatchQueue *requestQueue;
    CSOfflineMeasurementsCache *offlineCache;
    CSNotificationsObserver *observer;
    CSKeepAlive *keepAlive;
    CSCacheFlusher *cacheFlusher;
}

/**
 Returns CSComScore instance.
 */
+ (CSComScore *)comScore;

/**
 Returns CSCensus instance.
 */
+ (CSCensus *)census;

/**
 PixelURL setter.
 
 Parameters:
 
 - value: A NSString that contains the PixelURL.
 */
-(NSString *) setPixelURL: (NSString *) value;

/**
 Notify Analytics View event with custom PixelURL.
 
 Parameters:
 
 - pixelUrl: A NSString that contains the PixelURL.
 */
-(void) notifyWithPixelURL: (NSString *) pixelUrl;

/**
 Notify Analytics View event with custom labels
 
 Parameters:
 
 - labels: A NSDictionary that contains a set of custom labels with key-value pairs.
 */
-(void) notifyWithLabels: (NSDictionary *) labels;

/**
 Notify Analytics View event with custom PixelURL and labels
 
 Parameters:
 
 - pixelUrl: A NSString that contains the PixelURL.
 - labels: A NSDictionary that contains a set of custom labels with key-value pairs.
 */
-(void) notifyWithPixelURL: (NSString *) pixelUrl andLabels: (NSDictionary *) labels;

/**
 Notify Analytics event (View / Hidden) with custom labels
 
 Parameters:
 
 - type: A CSAnalyticsEventType enum that value must be View or Hidden.
 - labels: A NSDictionary that contains a set of custom labels with key-value pairs.
 */
-(void) notifyWithEventType: (CSAnalyticsEventType) type andLabels: (NSDictionary *) labels;

/**
 Notify Analytics event (View / Hidden) with custom PixelURL and labels
 
 Parameters:
 
 - pixelUrl: A NSString that contains the PixelURL.
 - type: A CSAnalyticsEventType enum that value must be View or Hidden.
 - labels: A NSDictionary that contains a set of custom labels with key-value pairs.
 */
-(void) notifyWithPixelURL: (NSString *) pixelUrl eventType: (CSAnalyticsEventType) type andLabels: (NSDictionary *) labels;

/**
 Notify Application event (Start / Close / Aggregate) with custom labels
 
 Parameters:
 
 - type: A CSApplicationEventType enum that value must be Start, Close or Aggregate.
 - labels: A NSDictionary that contains a set of custom labels with key-value pairs.
 */
-(void) notifyWithApplicationEventType: (CSApplicationEventType) type andLabels: (NSDictionary *) labels;

/**
 Notify Application event (Start / Close / Aggregate) with custom labels
 
 Parameters:
 
 - type: A CSApplicationEventType enum that value must be Start, Close or Aggregate.
 - labels: A NSDictionary that contains a set of custom labels with key-value pairs.
 */
-(void) notifyWithApplicationEventType: (CSApplicationEventType) type andLabels: (NSDictionary *) labels withPixelURL:(NSString *)pixelUrl;

/**
 Notify Application event (Start / Close / Aggregate) with custom labels and pixelURL
 
 Parameters:
 
 - px: PixelURL
 - type: A CSApplicationEventType enum that value must be Start, Close or Aggregate.
 - labels: A NSDictionary that contains a set of custom labels with key-value pairs.
 */
-(void) notifyWithPixelURL:(NSString *) px withApplicationEventType: (CSApplicationEventType) type andLabels: (NSDictionary *) labels;


-(id) init;
-(CSDispatchQueue *) queue;
-(CSStorage *) storage;
-(CSOfflineMeasurementsCache *) offlineCache;
-(CSNotificationsObserver *) observer;
-(CSKeepAlive *) keepAlive;
-(CSCacheFlusher *) cacheFlusher;
-(void) setVisitorId: (NSString *) value;
-(NSString *) getVisitorId;
-(void) setSalt: (NSString *) value;
-(NSString *) getSalt;
-(void) setAppName: (NSString *) value;
-(NSString *) getAppName;
-(NSString *) getDevModel;
-(void) setAnonymous: (BOOL) value;
-(BOOL) getAnonymous;
-(NSString *) getVersion;
-(NSTimeInterval) getGenesis;
-(NSTimeInterval) getPreviousGenesis;
-(NSTimeInterval) getInstallTime;
-(NSString *) md5:(NSString *)str;
- (NSString *) macaddress;
-(void) setCustomLabel:(NSString *)name andValue:(NSString *)value;
-(void) setCustomLabels:(NSDictionary *)labels;
-(NSMutableDictionary *)getCustomLabels;
- (NSString *)getPageName;
- (BOOL) isKeepAliveEnabled;
- (void) setKeepAliveEnabled:(BOOL)enabled;
- (void) setCustomerC2:(NSString *)c2;
- (NSString *)getCustomerC2;
- (long long) getPreviousUsage;
- (void) validateCurrentSession;
- (void) setSecure:(BOOL)secure;
- (BOOL) isSecure;
- (NSString *) getCrossPublisherId;

/** 
 Enables or disables live events (GETs) dispatched one by one when connectivity is available
 */
- (void) allowLiveTransmission:(CSTransmissionMode) mode;

/**
 Enables or disables automatic offline cache flushes (POSTS). The cache can always be manually 
 flushed using the public api comScore.FlushOfflineCache()
 */
- (void) allowOfflineTransmission:(CSTransmissionMode) mode;

// New in 2.0 API
// ******************************************************************************************

/**
 Notify Application event Start
 */
+ (void) Start;

/**
 Notify Application event Start with custom page name
 
 Parameters:
 
 - pageName: A NSString that contains the custom page name
 */
+ (void) StartWithPageName:(NSString *)pageName;

/**
 Notify Application event Start with custom labels
 
 Parameters:
 
 - labels: A NSDictionary that contains the custom labels
 */
+ (void) StartWithLabels:(NSDictionary *)labels;

/**
 Notify Application event Start with custom page name and with custom labels
 
 Parameters:
 
 - pageName: A NSString that contains the custom page name
 - labels: A NSDictionary that contains the custom labels
 */
+ (void) StartWithPageName:(NSString *)pageName andLabels:(NSDictionary *)labels;

/**
 Notify Application event View
 */
+ (void) View;

/**
 Notify Application event View with custom page name
 
 Parameters:
 
 - pageName: A NSString that contains the custom page name
 */
+ (void) ViewWithPageName:(NSString *)pageName;

/**
 Notify Application event View with custom labels
 
 Parameters:
 
 - labels: A NSDictionary that contains the custom labels
 */
+ (void) ViewWithLabels:(NSDictionary *)labels;

/**
 Notify Application event View with custom page name and with custom labels
 
 Parameters:
 
 - pageName: A NSString that contains the custom page name
 - labels: A NSDictionary that contains the custom labels
 */
+ (void) ViewWithPageName:(NSString *)pageName andLabels:(NSDictionary *)labels;

/**
 Notify Application event Hidden
 */
+ (void) Hidden;

/**
 Notify Application event Hidden with custom labels
 
 Parameters:
 
 - labels: A NSDictionary that contains the custom labels
 */
+ (void) HiddenWithLabels:(NSDictionary *)labels;

/**
 Notify Application event Hidden with custom page name
 
 Parameters:
 
 - pageName: A NSString that contains the custompage name
 */
+ (void) HiddenWithPageName:(NSString *)pageName;

/**
 Notify Application event Hidden with custom page name and with custom labels
 
 Parameters:
 
 - pageName: A NSString that contains the custompage name
 - labels: A NSDictionary that contains the custom labels
 */
+ (void) HiddenWithPageName:(NSString *) pageName andLabels:(NSDictionary *)labels;

/**
 Notify Application event Aggregate with custom labels
 
 Parameters:
 
 - labels: A NSDictionary that contains the custom labels
 */
+ (void) AggregateWithLabels:(NSDictionary *)labels;

/**
 Returns the pixel url
 */
+ (NSString *)PixelURL;

/**
 Sets a new pixel url
 
 Parameters:
 
 - pixelURL: A NSString that contains the new pixel url
 */
+ (NSString *) setPixelURL:(NSString *)pixelURL;

/**
 Returns the customer c2
 */
+ (NSString *)CustomerC2;

/**
 Sets a new customer c2
 
 Parameters:
 
 - customerC2: A NSString that contains the new customer c2
 */
+ (void) setCustomerC2:(NSString *)c2;

/**
 Returns the anonymous attribute
 */
+ (BOOL) Anonymous;

/**
 Sets the anonymous attribute
 
 Parameters:
 
 - anonymous: A BOOL containing the new anonymous attribute
 */
+ (void) setAnonymous:(BOOL) anonymous;

/**
 Returns the app name
 */
+ (NSString *) AppName;

/**
 Sets a new app name
 
 Parameters:
 
 - appName: A NSString that contains the new app name
 */
+ (void) setAppName:(NSString *)appName;

/**
 Returns the current device model
 */
+ (NSString *)DevModel;

/**
 Returns the time in that the current instance was created
 */
+ (NSTimeInterval) Genesis;

+ (NSTimeInterval) PreviousGenesis;

/**
 Returns the dictionary with the custom labels
 */
+ (NSMutableDictionary *)CustomLabels;

/**
 Returns the publisher secret
 */
+ (NSString *)PublisherSecret;

/**
 Sets a new publisher secret
 
 Parameters:
 
 - publisherSecret: A NSString that contains the new publisher secret
 */
+ (void) setPublisherSecret:(NSString *)publisherSecret;

/**
 Returns the visitor ID
 */
+ (NSString *)VisitorID;

/**
 Sets a new publisher secret
 
 Parameters:
 
 - publisherSecret: A NSString that contains the new publisher secret
 */
+ (void) setVisitorID:(NSString *) visitorID;

/**
 Sends all the cached offline measurements if any
 */
+ (void) FlushOfflineMeasurementsCache;

/**
 Returns the pageName from the pixel url
 */
+ (NSString *)PageName;

/**
 Sets a persitent custom label that will be sent in every measurement
 
 Parameters:
 
 - name: A String with the name of the label to set
 - value: A String with the value of the label to set
 */
+(void) setCustomLabel:(NSString *)name andValue:(NSString *)value;

/**
 Adds to the persistent custom labels dictionary all the labels from a dictionary
 
 Parameters:
 
 - labels: A Dictionary with labels
 */
+(void) setCustomLabels:(NSDictionary *)labels;

/** Returns the dictionary with the persistent custom labels */
+(NSMutableDictionary *)getCustomLabels;

/** Returns if the keep alive is enabled */
+ (BOOL) isKeepAliveEnabled;

/**
 Allows to enable/disable the keep alive
 */
+ (void) setKeepAliveEnabled:(BOOL)enabled;

/**
 * This mode will add use https for the automatically
 * generated pixelURL
 */
+ (void) setSecure:(BOOL)secure;

/**
 * Returns if the secure mode is enabled
 */
+ (BOOL) isSecure;

/** 
 Enables or disables live events (GETs) dispatched one by one when connectivity is available
 */
+ (void) allowLiveTransmission:(CSTransmissionMode) mode;

/**
 Enables or disables automatic offline cache flushes (POSTS). The cache can always be manually 
 flushed using the public api comScore.FlushOfflineCache()
*/
+ (void) allowOfflineTransmission:(CSTransmissionMode) mode;

/**
 Returns the live transmission mode
 */
+ (CSTransmissionMode) getLiveTransmissionMode;

/**
 Returns the offline transmission mode
 */
+ (CSTransmissionMode) getOfflineTransmissionMode;

/**
 Returns the live transmission mode
 */
- (CSTransmissionMode) getLiveTransmissionMode;

/**
 Returns the offline transmission mode
 */
- (CSTransmissionMode) getOfflineTransmissionMode;

- (long) getCacheFlushingInterval;
- (void) setCacheFlushingInterval:(long) seconds;


// Cache parameters
+ (void) setCacheMaxSize:(int) maxSize;
+ (int) getCacheMaxSize;
+ (void) setCacheMaxBatchSize:(int)maxBatchSize;
+ (int) getCacheMaxBatchSize;
+ (void) setCacheMaxFlushesInARow:(int)maxFlushesInARow;
+ (int) getCacheMaxFlushesInARow;
+ (void) setCacheMinutesToRetry:(int)minutesToRetry;
+ (int) getCacheMinutesToRetry;
+ (void) setCacheExpiricyInDays:(int)expiricyInDays;
+ (int) getCacheExpiricyInDays;
+ (long) getCacheFlushingInterval;
+ (void) setCacheFlushingInterval:(long) seconds;

@property (readonly, nonatomic, assign) NSString *pixelURL;
@property (readonly, nonatomic, assign) BOOL isSessionRestored;
@property (readwrite,assign) BOOL enabled;

@end

#endif // ifndef CSCOMSCORE_H