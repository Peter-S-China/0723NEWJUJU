/*
  */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CDVPluginResult.h"
#import "NSMutableArray+QueueAdditions.h"
#import "CDVCommandDelegate.h"

extern NSString* const CDVPageDidLoadNotification;
extern NSString* const CDVPluginHandleOpenURLNotification;
extern NSString* const CDVPluginResetNotification;
extern NSString* const CDVLocalNotification;

@interface CDVPlugin : NSObject {}

@property (nonatomic, weak) UIWebView* webView;
@property (nonatomic, weak) UIViewController* viewController;
@property (nonatomic, weak) id <CDVCommandDelegate> commandDelegate;

@property (readonly, assign) BOOL hasPendingOperation;

- (CDVPlugin*)initWithWebView:(UIWebView*)theWebView;
- (void)pluginInitialize;

- (void)handleOpenURL:(NSNotification*)notification;
- (void)onAppTerminate;
- (void)onMemoryWarning;
- (void)onReset;
- (void)dispose;

/*
 // see initWithWebView implementation
 - (void) onPause {}
 - (void) onResume {}
 - (void) onOrientationWillChange {}
 - (void) onOrientationDidChange {}
 - (void)didReceiveLocalNotification:(NSNotification *)notification;
 */

- (id)appDelegate;

// TODO(agrieve): Deprecate these in favour of using CDVCommandDelegate directly.
- (NSString*)writeJavascript:(NSString*)javascript;
- (NSString*)success:(CDVPluginResult*)pluginResult callbackId:(NSString*)callbackId;
- (NSString*)error:(CDVPluginResult*)pluginResult callbackId:(NSString*)callbackId;

@end
