

#import "NSMutableArray+QueueAdditions.h"

@implementation NSMutableArray (QueueAdditions)

- (id)queueHead
{
    if ([self count] == 0) {
        return nil;
    }

    return [self objectAtIndex:0];
}

- (__autoreleasing id)dequeue
{
    if ([self count] == 0) {
        return nil;
    }

    id head = [self objectAtIndex:0];
    if (head != nil) {
        // [[head retain] autorelease]; ARC - the __autoreleasing on the return value should so the same thing
        [self removeObjectAtIndex:0];
    }

    return head;
}

- (id)pop
{
    return [self dequeue];
}

- (void)enqueue:(id)object
{
    [self addObject:object];
}

@end
