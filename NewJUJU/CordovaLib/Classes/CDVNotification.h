/*
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AudioToolbox/AudioServices.h>
#import "CDVPlugin.h"

@interface CDVNotification : CDVPlugin <UIAlertViewDelegate>{}

- (void)alert:(CDVInvokedUrlCommand*)command;
- (void)confirm:(CDVInvokedUrlCommand*)command;
- (void)prompt:(CDVInvokedUrlCommand*)command;
- (void)vibrate:(CDVInvokedUrlCommand*)command;

@end

@interface CDVAlertView : UIAlertView {}
@property (nonatomic, copy) NSString* callbackId;

@end
