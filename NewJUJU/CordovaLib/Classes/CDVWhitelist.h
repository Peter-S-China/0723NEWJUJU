/*
  */

#import <Foundation/Foundation.h>

extern NSString* const kCDVDefaultWhitelistRejectionString;

@interface CDVWhitelist : NSObject

@property (nonatomic, copy) NSString* whitelistRejectionFormatString;

- (id)initWithArray:(NSArray*)array;
- (BOOL)schemeIsAllowed:(NSString*)scheme;
- (BOOL)URLIsAllowed:(NSURL*)url;
- (NSString*)errorStringForURL:(NSURL*)url;

@end
