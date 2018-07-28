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
#include <vector>

class SERollingIndicator {
public:
    SERollingIndicator(const long dataFrame);
    ~SERollingIndicator();
    void processAccelerometerValue(const double &value);
    
    //double getAllTimeMedian();
    double getAllTimeMean();
    double getAllTimeStandardDeviation();
    double getAllTimeMax();
    double getAllTimeMin();
    
    double getCurrentDataFrameMedian();
    double getCurrentDataFrameMean();
    double getCurrentDataFrameDeviation();
    double getCurrentDataFrameMax();
    double getCurrentDataFrameMin();
    
private:
    OrderedStructs::SkipList::HeadNode<double> *medianSkippedList;
    SEVariance *allTimeVariance;
    std::vector<double > *currentDataFrameVector;
    long dataFrame;
};

