/*
  */

#import <Foundation/Foundation.h>
#import "CDVAvailability.h"

@class CDVViewController;

@interface CDVURLProtocol : NSURLProtocol {}

+ (void)registerViewController:(CDVViewController*)viewController;
+ (void)unregisterViewController:(CDVViewController*)viewController;
@end
