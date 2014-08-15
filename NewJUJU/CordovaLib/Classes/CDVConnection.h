/*

 */

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"
#import "CDVReachability.h"

@interface CDVConnection : CDVPlugin {
    NSString* type;
    NSString* _callbackId;

    CDVReachability* internetReach;
}

@property (copy) NSString* connectionType;
@property (strong) CDVReachability* internetReach;

@end
