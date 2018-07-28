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
        rollignStats = new SERollingStats(5);
    }

    return self;
}

- (void)test {
    
    SEAccelerometerData data0 = {100.0, 200.0, 300.0};
    SEAccelerometerData data1 = {1.0, 2.0, 3.0};
    SEAccelerometerData data2 = {2.0, 6.0, 17.0};
    SEAccelerometerData data3 = {4.0, 8.0, 18.0};
    SEAccelerometerData data4 = {6.0, 11.0, 12.0};
    SEAccelerometerData data5 = {10.0, 12.0, 16.0};
    
    //{1, 2, 4, 6, 10};
    //{2, 6, 8, 11, 12};
    //{3, 12, 16, 17, 18};
    
    rollignStats->processAccelerometerData(data0);
    rollignStats->processAccelerometerData(data1);
    rollignStats->processAccelerometerData(data2);
    rollignStats->processAccelerometerData(data3);
    rollignStats->processAccelerometerData(data4);
    rollignStats->processAccelerometerData(data5);
    
    SEAccelerometerData last5SecMedian = rollignStats->getCurrentDataFrameMedian();
    SEAccelerometerData last5SecMean = rollignStats->getCurrentDataFrameMean();
    SEAccelerometerData last5SecDeviation = rollignStats->getCurrentDataFrameStandartDeviation();
    SEAccelerometerData last5SecMax = rollignStats->getCurrentDataFrameMax();
    SEAccelerometerData last5SecMin = rollignStats->getCurrentDataFrameMin();
    
    //SEAccelerometerData allTimeMedian = rollignStats->getAllTimeMedian();
    SEAccelerometerData allTimeMean = rollignStats->getAllTimeMean();
    SEAccelerometerData allTimeDeviation = rollignStats->getAllTimeStandardDeviation();
    SEAccelerometerData allTimeMax = rollignStats->getAllTimeMax();
    SEAccelerometerData alLTimeMin = rollignStats->getAllTimeMean();
    
    int I = 0;
    
}

- (void)dealloc {
    delete rollignStats;
}

@end
