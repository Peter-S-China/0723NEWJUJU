/*
  */

#import <UIKit/UIKit.h>
#import "CDVPlugin.h"

@interface CDVDevice : CDVPlugin
{}

+ (NSString*)cordovaVersion;

- (void)getDeviceInfo:(CDVInvokedUrlCommand*)command;

@end
