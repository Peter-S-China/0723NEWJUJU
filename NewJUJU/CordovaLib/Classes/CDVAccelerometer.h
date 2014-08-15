/*
 
 */

#import <UIKit/UIKit.h>
#import "CDVPlugin.h"

@interface CDVAccelerometer : CDVPlugin <UIAccelerometerDelegate>
{
    double x;
    double y;
    double z;
    NSTimeInterval timestamp;
}

@property (readonly, assign) BOOL isRunning;
@property (nonatomic, strong) NSString* callbackId;

- (CDVAccelerometer*)init;

- (void)start:(CDVInvokedUrlCommand*)command;
- (void)stop:(CDVInvokedUrlCommand*)command;

@end
