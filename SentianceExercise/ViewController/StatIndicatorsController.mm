//
//  StatIndicatorsController.m
//  SentianceExercise
//
//  Created by Apple on 7/28/18.
//  Copyright © 2018 Maliwan. All rights reserved.
//

#import "StatIndicatorsController.h"
#include "SERollingStats.h"
#include "Measurable.h"

@implementation StatIndicatorsController {
    SERollingStats<Measurable> *rollignStats;
}

- (id)init {
    self = [super init];
    
    if (self) {
        rollignStats = new SERollingStats<Measurable>(3);
    }

    return self;
}

- (void)test {
    
    SEAccelerometerData<Measurable> data0 = {Measurable(1.0), Measurable(2.0), Measurable(3.0)};
    SEAccelerometerData<Measurable> data1 = {Measurable(100.0), Measurable(200.0), Measurable(300.0)};
    SEAccelerometerData<Measurable> data2 = {Measurable(2.0), Measurable(6.0), Measurable(17.0)};
    SEAccelerometerData<Measurable> data3 = {Measurable(4.0), Measurable(8.0), Measurable(18.0)};

    
    rollignStats->processAccelerometerData(data0);
    rollignStats->processAccelerometerData(data1);
    rollignStats->processAccelerometerData(data2);
    rollignStats->processAccelerometerData(data3);
    
    /*rollignStats->processAccelerometerData(data3);
    rollignStats->processAccelerometerData(data4);
    rollignStats->processAccelerometerData(data5);*/
    
    SEAccelerometerData<Measurable> last5SecMedian = rollignStats->getCurrentDataFrameMedian();
    SEAccelerometerData<Measurable> last5SecMean = rollignStats->getCurrentDataFrameMean();
    SEAccelerometerData<Measurable> last5SecDeviation = rollignStats->getCurrentDataFrameStandartDeviation();
    SEAccelerometerData<Measurable> last5SecMax = rollignStats->getCurrentDataFrameMax();
    SEAccelerometerData<Measurable> last5SecMin = rollignStats->getCurrentDataFrameMin();
    
    //SEAccelerometerData allTimeMedian = rollignStats->getAllTimeMedian();
    SEAccelerometerData<Measurable> allTimeMean = rollignStats->getAllTimeMean();
    SEAccelerometerData<Measurable> allTimeDeviation = rollignStats->getAllTimeStandardDeviation();
    SEAccelerometerData<Measurable> allTimeMax = rollignStats->getAllTimeMax();
    SEAccelerometerData<Measurable> alLTimeMin = rollignStats->getAllTimeMean();
    
    int I = 0;
    
}

- (void)dealloc {
    delete rollignStats;
}

@end
