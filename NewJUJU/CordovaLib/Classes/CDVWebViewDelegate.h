/*
 
 */

#import <UIKit/UIKit.h>

/**
 * Distinguishes top-level navigations from sub-frame navigations.
 * shouldStartLoadWithRequest is called for every request, but didStartLoad
 * and didFinishLoad is called only for top-level navigations.
 * Relevant bug: CB-2389
 */
@interface CDVWebViewDelegate : NSObject <UIWebViewDelegate>{
    __weak NSObject <UIWebViewDelegate>* _delegate;
    NSInteger _loadCount;
    NSInteger _state;
    NSInteger _curLoadToken;
    NSInteger _loadStartPollCount;
}

- (id)initWithDelegate:(NSObject <UIWebViewDelegate>*)delegate;

@end
