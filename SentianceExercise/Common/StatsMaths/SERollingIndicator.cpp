//
//  SEStatsMath.m
//  SentianceExercise
//
//  Created by Apple on 7/28/18.
//  Copyright © 2018 Maliwan. All rights reserved.
//

#import "SERollingIndicator.h"
#include <numeric>

SERollingIndicator::SERollingIndicator(long dataFrame) {
    this->medianSkippedList = new OrderedStructs::SkipList::HeadNode<double>();
    this->allTimeVariance = new SEVariance();
    this->currentDataFrameVector = new std::vector<double>(dataFrame);
    
    this->dataFrame = dataFrame;
}

SERollingIndicator::~SERollingIndicator() {
    delete medianSkippedList;
    delete allTimeVariance;
    delete currentDataFrameVector;
}

void SERollingIndicator::processAccelerometerValue(const double &value) {
    medianSkippedList->insert(value);
    
    //start rolling forward
    if (medianSkippedList->size() > dataFrame) {
        medianSkippedList->remove(medianSkippedList->at(medianSkippedList->size() - dataFrame));
        currentDataFrameVector->erase(currentDataFrameVector->begin());
    }
    
    allTimeVariance->push(value);
    currentDataFrameVector->push_back(value);
}

double SERollingIndicator::getAllTimeStandardDeviation() {
    return allTimeVariance->standardDeviation();
}

double SERollingIndicator::getCurrentDataFrameDeviation() {
    double sum = std::accumulate(currentDataFrameVector->begin(), currentDataFrameVector->end(), 0.0);
    double mean = sum / currentDataFrameVector->size();
    
    double sq_sum = std::inner_product(currentDataFrameVector->begin(), currentDataFrameVector->end(), currentDataFrameVector->begin(), 0.0);
    return sqrt(sq_sum / currentDataFrameVector->size() - mean * mean);
}

double SERollingIndicator::getAllTimeMean() {
    return allTimeVariance->mean();
}

double SERollingIndicator::getCurrentDataFrameMean() {
    double sum = std::accumulate(currentDataFrameVector->begin(), currentDataFrameVector->end(), 0.0);
    return sum / currentDataFrameVector->size();
}

double SERollingIndicator::getAllTimeMax() {
    return allTimeVariance->allTimeMax();
}

double SERollingIndicator::getCurrentDataFrameMax() {
    return *std::max_element(currentDataFrameVector->begin(), currentDataFrameVector->end());
}

double SERollingIndicator::getAllTimeMin() {
    return allTimeVariance->allTimeMin();
}

double SERollingIndicator::getCurrentDataFrameMin() {
    return *std::min_element(currentDataFrameVector->begin(), currentDataFrameVector->end());
}

double SERollingIndicator::getCurrentDataFrameMedian() {
    double median;
    long middleElement = dataFrame / 2;
    
    if (medianSkippedList->size() % 2) {
        median = medianSkippedList->at(middleElement);
    }
    else {
        median = (medianSkippedList->at(middleElement) + medianSkippedList->at(middleElement - 1)) / 2;
    }
    
    return median;
}

