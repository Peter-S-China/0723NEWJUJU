/*

 */

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

@interface CDVSplashScreen : CDVPlugin {
    UIActivityIndicatorView* _activityView;
    UIImageView* _imageView;
    NSString* _curImageName;
    BOOL _visible;
}

- (void)show:(CDVInvokedUrlCommand*)command;
- (void)hide:(CDVInvokedUrlCommand*)command;

@end
