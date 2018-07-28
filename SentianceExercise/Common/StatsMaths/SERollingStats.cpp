//
//  SEStatsMath.m
//  SentianceExercise
//
//  Created by Apple on 7/28/18.
//  Copyright © 2018 Maliwan. All rights reserved.
//

#import "SERollingStats.h"

SERollingStats::SERollingStats(long medianDataFrame) {
    this->skippedListX = new OrderedStructs::SkipList::HeadNode<double>();
    this->skippedListY = new OrderedStructs::SkipList::HeadNode<double>();
    this->skippedListZ = new OrderedStructs::SkipList::HeadNode<double>();
    
    this->varianceX = new SEVariance();
    this->varianceY = new SEVariance();
    this->varianceZ = new SEVariance();
    this->medianDataFrame = medianDataFrame;
}

SERollingStats::~SERollingStats() {
    delete skippedListX;
    delete skippedListY;
    delete skippedListZ;
    delete varianceX;
    delete varianceY;
    delete varianceZ;
}

void SERollingStats::processAccelerometerData(const SEAccelerometerData &data) {
    skippedListX->insert(data.x);
    if (skippedListX->size() > medianDataFrame) {
        skippedListX->remove(skippedListX->at(skippedListX->size() - medianDataFrame));
    }
    
    skippedListY->insert(data.y);
    if (skippedListY->size() > medianDataFrame) {
        skippedListY->remove(skippedListY->at(skippedListY->size() - medianDataFrame));
    }
    
    skippedListZ->insert(data.z);
    if (skippedListZ->size() > medianDataFrame) {
        skippedListZ->remove(skippedListZ->at(skippedListZ->size() - medianDataFrame));
    }
    
    varianceX->push(data.x);
    varianceY->push(data.y);
    varianceZ->push(data.z);
}

SEAccelerometerData SERollingStats::getStandartDeviation() {
    double deviationX = varianceX->standardDeviation();
    double deviationY = varianceY->standardDeviation();
    double deviationZ = varianceZ->standardDeviation();
    
    SEAccelerometerData deviationData;
    deviationData.x = deviationX;
    deviationData.y = deviationY;
    deviationData.z = deviationZ;
    
    return deviationData;
}

SEAccelerometerData SERollingStats::getMean() {
    double meanX = varianceX->mean();
    double meanY = varianceY->mean();
    double meanZ = varianceZ->mean();
    
    SEAccelerometerData meanData;
    meanData.x = meanX;
    meanData.y = meanY;
    meanData.z = meanZ;
    
    return meanData;
}

SEAccelerometerData SERollingStats::getCurrentDataFrameMedian() {
    SEAccelerometerData median;
    long middleElement = medianDataFrame / 2;
    
    if (skippedListX->size() % 2) {
        median.x = skippedListX->at(middleElement);
    }
    else {
        median.x = (skippedListX->at(middleElement) + skippedListX->at(middleElement - 1)) / 2;
    }
    
    if (skippedListY->size() % 2) {
        median.y = skippedListY->at(middleElement);
    }
    else {
        median.y = (skippedListY->at(middleElement) + skippedListY->at(middleElement - 1)) / 2;
    }
    
    if (skippedListZ->size() % 2) {
        median.z = skippedListZ->at(middleElement);
    }
    else {
        median.z = (skippedListZ->at(middleElement) + skippedListZ->at(middleElement - 1)) / 2;
    }
    
    return median;
}

