/*
 
 */

#import "NSArray+Comparisons.h"

@implementation NSArray (Comparisons)

- (id)objectAtIndex:(NSUInteger)index withDefault:(id)aDefault
{
    id obj = nil;

    @try {
        obj = [self objectAtIndex:index];
        if ((obj == [NSNull null]) || (obj == nil)) {
            return aDefault;
        }
    }
    @catch(NSException* exception) {
        NSLog(@"Exception - Name: %@ Reason: %@", [exception name], [exception reason]);
    }

    return obj;
}

@end
