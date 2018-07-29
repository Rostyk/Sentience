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

template <class T>
class SERollingStats {
public:
    
    SERollingStats(const long dataFrame);
    ~SERollingStats();
    void processAccelerometerData(const SEAccelerometerData<T> &data);
    
    SEAccelerometerData<T> getAllTimeMedian();
    SEAccelerometerData<T> getCurrentDataFrameMedian();
    
    SEAccelerometerData<T> getAllTimeStandardDeviation();
    SEAccelerometerData<T> getCurrentDataFrameStandartDeviation();
    
    SEAccelerometerData<T> getAllTimeMean();
    SEAccelerometerData<T> getCurrentDataFrameMean();
    
    SEAccelerometerData<T> getAllTimeMax();
    SEAccelerometerData<T> getCurrentDataFrameMax();
    
    SEAccelerometerData<T> getAllTimeMin();
    SEAccelerometerData<T> getCurrentDataFrameMin();
    
    void reset();
    
private:
    SERollingIndicator<T> *indicatorX;
    SERollingIndicator<T> *indicatorY;
    SERollingIndicator<T> *indicatorZ;
};

template <class T>
SERollingStats<T>::SERollingStats(long dataFrame) {
    this->indicatorX = new SERollingIndicator<T>(dataFrame);
    this->indicatorY = new SERollingIndicator<T>(dataFrame);
    this->indicatorZ = new SERollingIndicator<T>(dataFrame);
}

template <class T>
SERollingStats<T>::~SERollingStats() {
    delete indicatorX;
    delete indicatorY;
    delete indicatorZ;
}

template <class T>
void SERollingStats<T>::reset() {
    indicatorX->reset();
    indicatorY->reset();
    indicatorZ->reset();
}

template <class T>
void SERollingStats<T>::processAccelerometerData(const SEAccelerometerData<T> &data) {
    indicatorX->processAccelerometerValue(data.x);
    indicatorY->processAccelerometerValue(data.y);
    indicatorZ->processAccelerometerValue(data.z);
}

template <class T>
SEAccelerometerData<T> SERollingStats<T>::getCurrentDataFrameStandartDeviation() {
    SEAccelerometerData<T> deviationData;
    deviationData.x = indicatorX->getCurrentDataFrameDeviation();
    deviationData.y = indicatorY->getCurrentDataFrameDeviation();
    deviationData.z = indicatorZ->getCurrentDataFrameDeviation();
    
    return deviationData;
}

template <class T>
SEAccelerometerData<T> SERollingStats<T>::getCurrentDataFrameMean() {
    SEAccelerometerData<T> meanData;
    meanData.x = indicatorX->getCurrentDataFrameMean();
    meanData.y = indicatorY->getCurrentDataFrameMean();
    meanData.z = indicatorZ->getCurrentDataFrameMean();
    
    return meanData;
}

template <class T>
SEAccelerometerData<T> SERollingStats<T>::getCurrentDataFrameMedian() {
    SEAccelerometerData<T> median;
    
    median.x = indicatorX->getCurrentDataFrameMedian();
    median.y = indicatorY->getCurrentDataFrameMedian();
    median.z = indicatorZ->getCurrentDataFrameMedian();
    
    return median;
}

template <class T>
SEAccelerometerData<T> SERollingStats<T>::getCurrentDataFrameMax() {
    SEAccelerometerData<T> max;
    
    max.x = indicatorX->getCurrentDataFrameMax();
    max.y = indicatorY->getCurrentDataFrameMax();
    max.z = indicatorZ->getCurrentDataFrameMax();
    return max;
}

template <class T>
SEAccelerometerData<T> SERollingStats<T>::getCurrentDataFrameMin() {
    SEAccelerometerData<T> min;
    
    min.x = indicatorX->getCurrentDataFrameMin();
    min.y = indicatorY->getCurrentDataFrameMin();
    min.z = indicatorZ->getCurrentDataFrameMin();
    return min;
}

template <class T>
SEAccelerometerData<T> SERollingStats<T>::getAllTimeStandardDeviation() {
    SEAccelerometerData<T> deviation;
    
    deviation.x = indicatorX->getAllTimeStandardDeviation();
    deviation.y = indicatorY->getAllTimeStandardDeviation();
    deviation.z = indicatorZ->getAllTimeStandardDeviation();
    return deviation;
}

template <class T>
SEAccelerometerData<T> SERollingStats<T>::getAllTimeMean() {
    SEAccelerometerData<T> mean;
    
    mean.x = indicatorX->getAllTimeMean();
    mean.y = indicatorY->getAllTimeMean();
    mean.z = indicatorZ->getAllTimeMean();
    return mean;
}

template <class T>
SEAccelerometerData<T> SERollingStats<T>::getAllTimeMedian() {
    SEAccelerometerData<T> median;
    return median;
}

template <class T>
SEAccelerometerData<T> SERollingStats<T>::getAllTimeMax() {
    SEAccelerometerData<T> max;
    
    max.x = indicatorX->getAllTimeMax();
    max.y = indicatorY->getAllTimeMax();
    max.z = indicatorZ->getAllTimeMax();
    return max;
}

template <class T>
SEAccelerometerData<T> SERollingStats<T>::getAllTimeMin() {
    SEAccelerometerData<T> min;
    
    min.x = indicatorX->getAllTimeMin();
    min.y = indicatorY->getAllTimeMin();
    min.z = indicatorZ->getAllTimeMin();
    return min;
}
