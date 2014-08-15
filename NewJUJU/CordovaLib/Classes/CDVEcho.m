/*
 
 */

#import "CDVEcho.h"
#import "CDV.h"

@implementation CDVEcho

- (void)echo:(CDVInvokedUrlCommand*)command
{
    id message = [command.arguments objectAtIndex:0];
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:message];

    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)echoAsyncHelper:(NSArray*)args
{
    [self.commandDelegate sendPluginResult:[args objectAtIndex:0] callbackId:[args objectAtIndex:1]];
}

- (void)echoAsync:(CDVInvokedUrlCommand*)command
{
    id message = [command.arguments objectAtIndex:0];
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:message];

    [self performSelector:@selector(echoAsyncHelper:) withObject:[NSArray arrayWithObjects:pluginResult, command.callbackId, nil] afterDelay:0];
}

- (void)echoArrayBuffer:(CDVInvokedUrlCommand*)command
{
    id message = [command.arguments objectAtIndex:0];
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsArrayBuffer:message];

    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)echoMultiPart:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsMultipart:command.arguments];

    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end
