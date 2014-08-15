/*

 */

#import <UIKit/UIKit.h>
#import "CDVCommandDelegate.h"

@class CDVViewController;
@class CDVCommandQueue;

@interface CDVCommandDelegateImpl : NSObject <CDVCommandDelegate>{
    @private
    __weak CDVViewController* _viewController;
    @protected
    __weak CDVCommandQueue* _commandQueue;
}
- (id)initWithViewController:(CDVViewController*)viewController;
@end
