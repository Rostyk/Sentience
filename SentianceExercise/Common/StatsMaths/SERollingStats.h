//
//  SEStatsMath.h
//  SentianceExercise
//
//  Created by Apple on 7/28/18.
//  Copyright © 2018 Maliwan. All rights reserved.
//

#include "SkipList.h"
#include "SEAccelerometerData.h"
#include "SEVariance.h"
#include "SERollingIndicator.h"

class SERollingStats {
public:
    
    SERollingStats(const long dataFrame);
    ~SERollingStats();
    void processAccelerometerData(const SEAccelerometerData &data);
    
    SEAccelerometerData getAllTimeMedian();
    SEAccelerometerData getCurrentDataFrameMedian();
    
    SEAccelerometerData getAllTimeStandardDeviation();
    SEAccelerometerData getCurrentDataFrameStandartDeviation();
    
    SEAccelerometerData getAllTimeMean();
    SEAccelerometerData getCurrentDataFrameMean();
    
    SEAccelerometerData getAllTimeMax();
    SEAccelerometerData getCurrentDataFrameMax();
    
    SEAccelerometerData getAllTimeMin();
    SEAccelerometerData getCurrentDataFrameMin();
    
private:
    SERollingIndicator *indicatorX;
    SERollingIndicator *indicatorY;
    SERollingIndicator *indicatorZ;
};

