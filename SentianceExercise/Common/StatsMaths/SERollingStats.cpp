//
//  SEStatsMath.m
//  SentianceExercise
//
//  Created by Apple on 7/28/18.
//  Copyright © 2018 Maliwan. All rights reserved.
//

#import "SERollingStats.h"

SERollingStats::SERollingStats(long dataFrame) {
    this->indicatorX = new SERollingIndicator(dataFrame);
    this->indicatorY = new SERollingIndicator(dataFrame);
    this->indicatorZ = new SERollingIndicator(dataFrame);
}

SERollingStats::~SERollingStats() {
    delete indicatorX;
    delete indicatorY;
    delete indicatorY;
}

void SERollingStats::processAccelerometerData(const SEAccelerometerData &data) {
    indicatorX->processAccelerometerValue(data.x);
    indicatorY->processAccelerometerValue(data.y);
    indicatorZ->processAccelerometerValue(data.z);
}

SEAccelerometerData SERollingStats::getCurrentDataFrameStandartDeviation() {
    SEAccelerometerData deviationData;
    deviationData.x = indicatorX->getCurrentDataFrameDeviation();
    deviationData.y = indicatorY->getCurrentDataFrameDeviation();
    deviationData.z = indicatorZ->getCurrentDataFrameDeviation();
    
    return deviationData;
}

SEAccelerometerData SERollingStats::getCurrentDataFrameMean() {
    SEAccelerometerData meanData;
    meanData.x = indicatorX->getCurrentDataFrameMean();
    meanData.y = indicatorY->getCurrentDataFrameMean();
    meanData.z = indicatorZ->getCurrentDataFrameMean();
    
    return meanData;
}

SEAccelerometerData SERollingStats::getCurrentDataFrameMedian() {
    SEAccelerometerData median;
    
    median.x = indicatorX->getCurrentDataFrameMedian();
    median.y = indicatorY->getCurrentDataFrameMedian();
    median.z = indicatorZ->getCurrentDataFrameMedian();
    
    return median;
}

SEAccelerometerData SERollingStats::getCurrentDataFrameMax() {
    SEAccelerometerData max;
    
    max.x = indicatorX->getCurrentDataFrameMax();
    max.y = indicatorY->getCurrentDataFrameMax();
    max.z = indicatorZ->getCurrentDataFrameMax();
    return max;
}

SEAccelerometerData SERollingStats::getCurrentDataFrameMin() {
    SEAccelerometerData min;
    
    min.x = indicatorX->getCurrentDataFrameMin();
    min.y = indicatorY->getCurrentDataFrameMin();
    min.z = indicatorZ->getCurrentDataFrameMin();
    return min;
}

SEAccelerometerData SERollingStats::getAllTimeStandardDeviation() {
    SEAccelerometerData deviation;
    
    deviation.x = indicatorX->getAllTimeStandardDeviation();
    deviation.y = indicatorY->getAllTimeStandardDeviation();
    deviation.z = indicatorZ->getAllTimeStandardDeviation();
    return deviation;
}

SEAccelerometerData SERollingStats::getAllTimeMean() {
    SEAccelerometerData mean;
    
    mean.x = indicatorX->getAllTimeMean();
    mean.y = indicatorY->getAllTimeMean();
    mean.z = indicatorZ->getAllTimeMean();
    return mean;
}

SEAccelerometerData SERollingStats::getAllTimeMedian() {
    SEAccelerometerData median;
    return median;
}

SEAccelerometerData SERollingStats::getAllTimeMax() {
    SEAccelerometerData max;
    
    max.x = indicatorX->getAllTimeMax();
    max.y = indicatorY->getAllTimeMax();
    max.z = indicatorZ->getAllTimeMax();
    return max;
}

SEAccelerometerData SERollingStats::getAllTimeMin() {
    SEAccelerometerData min;
    
    min.x = indicatorX->getAllTimeMin();
    min.y = indicatorY->getAllTimeMin();
    min.z = indicatorZ->getAllTimeMin();
    return min;
}
