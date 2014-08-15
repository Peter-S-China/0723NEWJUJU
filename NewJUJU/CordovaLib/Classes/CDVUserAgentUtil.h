/*
 */

#import <Foundation/Foundation.h>

@interface CDVUserAgentUtil : NSObject
+ (NSString*)originalUserAgent;
+ (void)acquireLock:(void (^)(NSInteger lockToken))block;
+ (void)releaseLock:(NSInteger*)lockToken;
+ (void)setUserAgent:(NSString*)value lockToken:(NSInteger)lockToken;
@end
