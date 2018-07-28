//
//  SEStatsMath.m
//  SentianceExercise
//
//  Created by Apple on 7/28/18.
//  Copyright © 2018 Maliwan. All rights reserved.
//

#import "SEStatsMath.h"

SEStatsMath::SEStatsMath(long medianDataFrame) {
    this->skippedListX = new OrderedStructs::SkipList::HeadNode<double>();
    this->skippedListY = new OrderedStructs::SkipList::HeadNode<double>();
    this->skippedListZ = new OrderedStructs::SkipList::HeadNode<double>();
    
    this->medianDataFrame = medianDataFrame;
}

SEStatsMath::~SEStatsMath() {
    delete skippedListX;
    delete skippedListY;
    delete skippedListZ;
}

void SEStatsMath::processAccelerometerData(SEAccelerometerData data) {
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
    
    skippedListZ->lacksIntegrity();
}

SEAccelerometerData SEStatsMath::getCurrentDataFrameMedian() {
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

