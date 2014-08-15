/*

 */

#import "CDVTimer.h"

#pragma mark CDVTimerItem

@interface CDVTimerItem : NSObject

@property (nonatomic, strong) NSString* name;
@property (nonatomic, strong) NSDate* started;
@property (nonatomic, strong) NSDate* ended;

- (void)log;

@end

@implementation CDVTimerItem

- (void)log
{
    NSLog(@"[CDVTimer][%@] %fms", self.name, [self.ended timeIntervalSinceDate:self.started] * 1000.0);
}

@end

#pragma mark CDVTimer

@interface CDVTimer ()

@property (nonatomic, strong) NSMutableDictionary* items;

@end

@implementation CDVTimer

#pragma mark object methods

- (id)init
{
    if (self = [super init]) {
        self.items = [NSMutableDictionary dictionaryWithCapacity:6];
    }

    return self;
}

- (void)add:(NSString*)name
{
    if ([self.items objectForKey:[name lowercaseString]] == nil) {
        CDVTimerItem* item = [CDVTimerItem new];
        item.name = name;
        item.started = [NSDate new];
        [self.items setObject:item forKey:[name lowercaseString]];
    } else {
        NSLog(@"Timer called '%@' already exists.", name);
    }
}

- (void)remove:(NSString*)name
{
    CDVTimerItem* item = [self.items objectForKey:[name lowercaseString]];

    if (item != nil) {
        item.ended = [NSDate new];
        [item log];
        [self.items removeObjectForKey:[name lowercaseString]];
    } else {
        NSLog(@"Timer called '%@' does not exist.", name);
    }
}

- (void)removeAll
{
    [self.items removeAllObjects];
}

#pragma mark class methods

+ (void)start:(NSString*)name
{
    [[CDVTimer sharedInstance] add:name];
}

+ (void)stop:(NSString*)name
{
    [[CDVTimer sharedInstance] remove:name];
}

+ (void)clearAll
{
    [[CDVTimer sharedInstance] removeAll];
}

+ (CDVTimer*)sharedInstance
{
    static dispatch_once_t pred = 0;
    __strong static CDVTimer* _sharedObject = nil;

    dispatch_once(&pred, ^{
            _sharedObject = [[self alloc] init];
        });

    return _sharedObject;
}

@end
