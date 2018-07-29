//
//  NSArray+Stats.m
//  SentianceExercise
//
//  Created by Apple on 7/29/18.
//  Copyright © 2018 Maliwan. All rights reserved.
//

#import "NSArray+Stats.h"



@implementation NSArray (Statistics)

- (double)median
{
    if (self.count == 1) return [self[0] floatValue];
    
    float result = 0;
    NSUInteger middle;
    
    NSArray * sorted = [self sortedArrayUsingSelector:@selector(compare:)];
    if (self.count % 2 != 0) {  //odd number of members
        middle = (sorted.count / 2);
        result = [[sorted objectAtIndex:middle] floatValue];
    }
    else {
        middle = (sorted.count / 2) - 1;
        result = [[@[[sorted objectAtIndex:middle], [sorted objectAtIndex:middle + 1]] valueForKeyPath:@"@avg.self"] doubleValue];
    }
    return result;
}

- (double)mean {
    __block double total = 0.0;
    
    [self enumerateObjectsUsingBlock:^(NSNumber *number, NSUInteger idx, BOOL *stop) {
        total += [number doubleValue];
    }];
    
    return total / (self.count * 1.0);
}

@end
