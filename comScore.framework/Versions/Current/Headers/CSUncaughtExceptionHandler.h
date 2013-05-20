#import <UIKit/UIKit.h>

@interface CSUncaughtExceptionHandler : NSObject
{
	BOOL dismissed;
}

+ (NSString *)parseCall:(NSString *)call;

@end

void InstallUncaughtExceptionHandler();
