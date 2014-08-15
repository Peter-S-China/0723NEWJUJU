/*
*/

#import <Foundation/Foundation.h>

@interface CDVInvokedUrlCommand : NSObject {
    NSString* _callbackId;
    NSString* _className;
    NSString* _methodName;
    NSArray* _arguments;
}

@property (nonatomic, readonly) NSArray* arguments;
@property (nonatomic, readonly) NSString* callbackId;
@property (nonatomic, readonly) NSString* className;
@property (nonatomic, readonly) NSString* methodName;

+ (CDVInvokedUrlCommand*)commandFromJson:(NSArray*)jsonEntry;

- (id)initWithArguments:(NSArray*)arguments
             callbackId:(NSString*)callbackId
              className:(NSString*)className
             methodName:(NSString*)methodName;

- (id)initFromJson:(NSArray*)jsonEntry;

// The first NSDictionary found in the arguments will be returned in legacyDict.
// The arguments array with be prepended with the callbackId and have the first
// dict removed from it.
- (void)legacyArguments:(NSMutableArray**)legacyArguments andDict:(NSMutableDictionary**)legacyDict;

// Returns the argument at the given index.
// If index >= the number of arguments, returns nil.
// If the argument at the given index is NSNull, returns nil.
- (id)argumentAtIndex:(NSUInteger)index;
// Same as above, but returns defaultValue instead of nil.
- (id)argumentAtIndex:(NSUInteger)index withDefault:(id)defaultValue;
// Same as above, but returns defaultValue instead of nil, and if the argument is not of the expected class, returns defaultValue
- (id)argumentAtIndex:(NSUInteger)index withDefault:(id)defaultValue andClass:(Class)aClass;

@end
