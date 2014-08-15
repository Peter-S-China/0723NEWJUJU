

#import <Foundation/Foundation.h>

@interface NSMutableArray (QueueAdditions)

- (id)pop;
- (id)queueHead;
- (id)dequeue;
- (void)enqueue:(id)obj;

@end
