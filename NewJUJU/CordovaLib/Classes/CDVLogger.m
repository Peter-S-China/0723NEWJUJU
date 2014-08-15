/*
  */

#import "CDVLogger.h"
#import "CDV.h"

@implementation CDVLogger

/* log a message */
- (void)logLevel:(CDVInvokedUrlCommand*)command
{
    id level = [command.arguments objectAtIndex:0];
    id message = [command.arguments objectAtIndex:1];

    if ([level isEqualToString:@"LOG"]) {
        NSLog(@"%@", message);
    } else {
        NSLog(@"%@: %@", level, message);
    }
}

@end
