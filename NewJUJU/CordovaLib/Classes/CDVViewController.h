/*

 */

#import <UIKit/UIKit.h>
#import <Foundation/NSJSONSerialization.h>
#import "CDVAvailability.h"
#import "CDVInvokedUrlCommand.h"
#import "CDVCommandDelegate.h"
#import "CDVCommandQueue.h"
#import "CDVWhitelist.h"
#import "CDVScreenOrientationDelegate.h"
#import "CDVPlugin.h"

@interface CDVViewController : UIViewController <UIWebViewDelegate, CDVScreenOrientationDelegate>{
    @protected
    id <CDVCommandDelegate> _commandDelegate;
    @protected
    CDVCommandQueue* _commandQueue;
    NSString* _userAgent;
}

@property (nonatomic, strong) IBOutlet UIWebView* webView;

@property (nonatomic, readonly, strong) NSMutableDictionary* pluginObjects;
@property (nonatomic, readonly, strong) NSDictionary* pluginsMap;
@property (nonatomic, readonly, strong) NSMutableDictionary* settings;
@property (nonatomic, readonly, strong) NSXMLParser* configParser;
@property (nonatomic, readonly, strong) CDVWhitelist* whitelist; // readonly for public
@property (nonatomic, readonly, assign) BOOL loadFromString;
@property (nonatomic, readwrite, assign) BOOL useSplashScreen CDV_DEPRECATED(2.5, "Add/Remove the SplashScreen plugin instead of setting this property.");

@property (nonatomic, readwrite, copy) NSString* wwwFolderName;
@property (nonatomic, readwrite, copy) NSString* startPage;
@property (nonatomic, readonly, strong) CDVCommandQueue* commandQueue;
@property (nonatomic, readonly, strong) id <CDVCommandDelegate> commandDelegate;
@property (nonatomic, readonly) NSString* userAgent;

+ (NSDictionary*)getBundlePlist:(NSString*)plistName;
+ (NSString*)applicationDocumentsDirectory;

- (void)printMultitaskingInfo;
- (void)createGapView;
- (UIWebView*)newCordovaViewWithFrame:(CGRect)bounds;

- (void)javascriptAlert:(NSString*)text;
- (NSString*)appURLScheme;

- (NSArray*)parseInterfaceOrientations:(NSArray*)orientations;
- (BOOL)supportsOrientation:(UIInterfaceOrientation)orientation;

- (id)getCommandInstance:(NSString*)pluginName;
- (void)registerPlugin:(CDVPlugin*)plugin withClassName:(NSString*)className;
- (void)registerPlugin:(CDVPlugin*)plugin withPluginName:(NSString*)pluginName;

- (BOOL)URLisAllowed:(NSURL*)url;

@end
