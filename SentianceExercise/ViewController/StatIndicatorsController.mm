//
//  StatIndicatorsController.m
//  SentianceExercise
//
//  Created by Apple on 7/28/18.
//  Copyright © 2018 Maliwan. All rights reserved.
//

#import "StatIndicatorsController.h"
#import "SERollingStats.h"

@implementation StatIndicatorsController {
    SERollingStats *rollignStats;
}

- (id)init {
    self = [super init];
    
    if (self) {
        rollignStats = new SERollingStats(4);
    }

    return self;
}

- (void)test {
    SEAccelerometerData data1 = {1.0, 2.0, 3.0};
    SEAccelerometerData data2 = {2.0, 6.0, 17.0};
    SEAccelerometerData data3 = {4.0, 8.0, 18.0};
    SEAccelerometerData data4 = {6.0, 11.0, 12.0};
    SEAccelerometerData data5 = {10.0, 12.0, 16.0};
    
    //{1, 2, 4, 6, 10};
    //{2, 6, 8, 11, 12};
    //{3, 12, 16, 17, 18};
    
    rollignStats->processAccelerometerData(data1);
    rollignStats->processAccelerometerData(data2);
    rollignStats->processAccelerometerData(data3);
    rollignStats->processAccelerometerData(data4);
    rollignStats->processAccelerometerData(data5);
    
    SEAccelerometerData median = rollignStats->getCurrentDataFrameMedian();
    
    SEAccelerometerData mean = rollignStats->getMean();
    SEAccelerometerData deviation = rollignStats->getStandartDeviation();
    
}

- (void)dealloc {
    delete rollignStats;
}

@end
