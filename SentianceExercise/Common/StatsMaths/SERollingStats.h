//
//  SEStatsMath.h
//  SentianceExercise
//
//  Created by Apple on 7/28/18.
//  Copyright © 2018 Maliwan. All rights reserved.
//

#include <vector>
#include "SkipList.h"
#include "SEAccelerometerData.h"
#include "SEVariance.h"

class SERollingStats {
public:
    
    SERollingStats(const long medianDataFrame);
    ~SERollingStats();
    void processAccelerometerData(const SEAccelerometerData &data);
    
    SEAccelerometerData getAllTimeMedian();
    SEAccelerometerData getCurrentDataFrameMedian();
    
    SEAccelerometerData getStandartDeviation();
    SEAccelerometerData getMean();
    
private:
    OrderedStructs::SkipList::HeadNode<double> *skippedListX;
    OrderedStructs::SkipList::HeadNode<double> *skippedListY;
    OrderedStructs::SkipList::HeadNode<double> *skippedListZ;
    
    SEVariance *varianceX;
    SEVariance *varianceY;
    SEVariance *varianceZ;
    
    long medianDataFrame;
};

