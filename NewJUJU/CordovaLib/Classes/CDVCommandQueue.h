/*
  */

#import <Foundation/Foundation.h>

@class CDVInvokedUrlCommand;
@class CDVViewController;

@interface CDVCommandQueue : NSObject

@property (nonatomic, readonly) BOOL currentlyExecuting;

- (id)initWithViewController:(CDVViewController*)viewController;
- (void)dispose;

- (void)resetRequestId;
- (void)enqueCommandBatch:(NSString*)batchJSON;

- (void)maybeFetchCommandsFromJs:(NSNumber*)requestId;
- (void)fetchCommandsFromJs;
- (void)executePending;
- (BOOL)execute:(CDVInvokedUrlCommand*)command;

@end
