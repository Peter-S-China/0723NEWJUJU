/*
 
 */

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

@interface CDVBattery : CDVPlugin {
    UIDeviceBatteryState state;
    float level;
    bool isPlugged;
    NSString* callbackId;
}

@property (nonatomic) UIDeviceBatteryState state;
@property (nonatomic) float level;
@property (nonatomic) bool isPlugged;
@property (strong) NSString* callbackId;

- (void)updateBatteryStatus:(NSNotification*)notification;
- (NSDictionary*)getBatteryStatus;
- (void)start:(CDVInvokedUrlCommand*)command;
- (void)stop:(CDVInvokedUrlCommand*)command;
- (void)dealloc;
@end
