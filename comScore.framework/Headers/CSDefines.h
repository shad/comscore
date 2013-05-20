//
//  CSDefines.h
//  comScore
//
//  Created by Agustín Prats on 2/14/12.
//  Copyright (c) 2012 comScore. All rights reserved.
//

#ifndef comScore_CSDefines_h
#define comScore_CSDefines_h

#define kSDKVersion @"2.1301.28"

#define kHashMask @"JetportGotAMaskOfThe%@S.D_K-"

#define kGCDMinVersion @"4.0"

#define kCSAsyncDispatch YES
#define kCSComScoreDispatchQueue "com.comScore.eventQ"
#define INITIAL_SETTINGS_FILENAME @"comScore"

#define kCensusURL @"http://b.scorecardresearch.com/p2?"

#define kSecureCensusURL @"https://sb.scorecardresearch.com/p2?"

#define kSESSION_INACTIVE_PERIOD 20*60*1000
#define kKeepAlivePeriod 60 /* Seconds in a minute */ * 60 /* Minutes in hour */ * 24 /* Hours in a day */
#define kKeepAlivePeriodAfterForeground 3 /* Seconds */

#define kAdvertiserIDSuffix @"-cs22"
#define kGeneratedIDSuffix @"-cs72"
#define kMACAddressSuffix @"-cs31"
#define kNOTrackingID @"none"

/**
 *
 * CACHE --------------
 *
 **/
#define kCacheFileName @"dax_cache_"
#define kCacheMaxSize 2000
#define kCacheMaxBatchSize 100
#define kCacheMaxPosts 10
#define kCacheWaitMinutes 30
#define kCacheMinSecsOnline 30
#define kCacheMaxFlushesInARow 10
#define kCacheExpiricyDays 31
#define kCacheFlushingInterval 0
#define kOfflineReceiverURL @"http://udm.scorecardresearch.com/offline"
#define kSecureOfflineReceiverURL @"https://udm.scorecardresearch.com/offline"


#define kEventsLimitPerSecond 20
#define kEventsLimitPerDay 6000

/**
 *
 * LABELS --------------
 *
 **/
// the c1 labels indicates the type of measurement, 19 indicates is an application measurement
#define kC1Value @"19"

// The c10 is a mnemonic for the platform
#define kC10Value @"ios"

// ns_nc = 1 indicates that the server should'nt proccess the cookie
#define kNs_ncValue @"1"

#define kPageNameLabelName @"name"


// Encryption
#define kPublicKeyTag @"com.comscore.rsa.publickey"
#define kPublicKey @"-----BEGIN PUBLIC KEY-----\nMIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQD0+fCVxGq3Bk24jUKO1PzsiUs3\nvqww6zR4n2e3AweVLUAgsrDRbAWJ/EjZm1WBLBVNMiTLpSAkV6sjOIrUs03xdUEj\nQZJHwOGK+MfzFaZukoo0qAsEMPwQ5posv0JdkBdUGhKchPk6+NYmD6Hb44Lkp7/a\nQnVeWzvfAPQyTJR5wQIDAQAB\n-----END PUBLIC KEY-----"


#endif
