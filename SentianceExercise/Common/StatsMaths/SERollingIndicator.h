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
#include <numeric>

template <class T>
class SERollingIndicator {
public:
    SERollingIndicator(const long dataFrame);
    ~SERollingIndicator();
    void processAccelerometerValue(const T &value);
    
    //double getAllTimeMedian();
    T getAllTimeMean();
    T getAllTimeStandardDeviation();
    T getAllTimeMax();
    T getAllTimeMin();
    
    T getCurrentDataFrameMedian();
    T getCurrentDataFrameMean();
    T getCurrentDataFrameDeviation();
    T getCurrentDataFrameMax();
    T getCurrentDataFrameMin();
    
    void reset();
    
private:
    OrderedStructs::SkipList::HeadNode<T> *medianSkippedList;
    SEVariance<T> *allTimeVariance;
    std::vector<T> *currentDataFrameVector;
    long dataFrame;
};

template <class T>
SERollingIndicator<T>::SERollingIndicator(long dataFrame) {
    this->medianSkippedList = new OrderedStructs::SkipList::HeadNode<T>();
    this->allTimeVariance = new SEVariance<T>();
    this->currentDataFrameVector = new std::vector<T>();
    
    this->dataFrame = dataFrame;
}

template <class T>
SERollingIndicator<T>::~SERollingIndicator() {
    delete medianSkippedList;
    delete allTimeVariance;
    delete currentDataFrameVector;
}

template <class T>
void SERollingIndicator<T>::reset() {
    delete medianSkippedList;
    this->medianSkippedList = new OrderedStructs::SkipList::HeadNode<T>();
    
    allTimeVariance->clear();
    currentDataFrameVector->clear();
}

template <class T>
void SERollingIndicator<T>::processAccelerometerValue(const T &value) {
    medianSkippedList->insert(value);
    allTimeVariance->push(value);
    currentDataFrameVector->push_back(value);
    
    //start rolling forward
    if (medianSkippedList->size() > dataFrame) {
        medianSkippedList->remove(medianSkippedList->at(medianSkippedList->size() - dataFrame));
        currentDataFrameVector->erase(currentDataFrameVector->begin());
    }
}

template <class T>
T SERollingIndicator<T>::getAllTimeStandardDeviation() {
    return allTimeVariance->standardDeviation();
}

template <class T>
T SERollingIndicator<T>::getCurrentDataFrameDeviation() {
    T sum = std::accumulate(currentDataFrameVector->begin(), currentDataFrameVector->end(), 0.0);
    T mean = sum / T(currentDataFrameVector->size());
    T sq_sum = std::inner_product(currentDataFrameVector->begin(), currentDataFrameVector->end(), currentDataFrameVector->begin(), 0.0);
    return sqrt( double(sq_sum / T(currentDataFrameVector->size()) - mean * mean));
}

template <class T>
T SERollingIndicator<T>::getAllTimeMean() {
    return allTimeVariance->mean();
}

template <class T>
T SERollingIndicator<T>::getCurrentDataFrameMean() {
    T sum = std::accumulate(currentDataFrameVector->begin(), currentDataFrameVector->end(), 0.0);
    return sum / T(currentDataFrameVector->size());
}

template <class T>
T SERollingIndicator<T>::getAllTimeMax() {
    return allTimeVariance->allTimeMax();
}

template <class T>
T SERollingIndicator<T>::getCurrentDataFrameMax() {
    return *std::max_element(currentDataFrameVector->begin(), currentDataFrameVector->end());
}

template <class T>
T SERollingIndicator<T>::getAllTimeMin() {
    return allTimeVariance->allTimeMin();
}

template <class T>
T SERollingIndicator<T>::getCurrentDataFrameMin() {
    return *std::min_element(currentDataFrameVector->begin(), currentDataFrameVector->end());
}

template <class T>
T SERollingIndicator<T>::getCurrentDataFrameMedian() {
    T median;
    long middleElement = dataFrame / 2;
    
    if (medianSkippedList->size() % 2) {
        median = medianSkippedList->at(middleElement);
    }
    else {
        median = (medianSkippedList->at(middleElement) + medianSkippedList->at(middleElement - 1)) / T(2.0);
    }
    
    return median;
}

