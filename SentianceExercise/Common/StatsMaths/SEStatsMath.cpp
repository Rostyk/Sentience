//
//  SEStatsMath.m
//  SentianceExercise
//
//  Created by Apple on 7/28/18.
//  Copyright © 2018 Maliwan. All rights reserved.
//

#import "SEStatsMath.h"

SEStatsMath::SEStatsMath(long medianWindowSize) {
    this->skippedListX = new OrderedStructs::SkipList::HeadNode<double>();
    this->skippedListY = new OrderedStructs::SkipList::HeadNode<double>();
    this->skippedListZ = new OrderedStructs::SkipList::HeadNode<double>();
    
    this->medianWindowSize = medianWindowSize;
}

SEStatsMath::~SEStatsMath() {
    delete skippedListX;
    delete skippedListY;
    delete skippedListZ;
}

void SEStatsMath::processAccelerometerData(SEAccelerometerData data) {
    skippedListX->insert(data.x);
    if (skippedListX->size() > medianWindowSize) {
        skippedListX->remove(skippedListX->at(skippedListX->size() - medianWindowSize));
    }
    
    skippedListY->insert(data.y);
    if (skippedListY->size() > medianWindowSize) {
        skippedListY->remove(skippedListY->at(skippedListY->size() - medianWindowSize));
    }
    
    skippedListZ->insert(data.z);
    if (skippedListZ->size() > medianWindowSize) {
        skippedListZ->remove(skippedListZ->at(skippedListZ->size() - medianWindowSize));
    }
    
    skippedListZ->lacksIntegrity();
}

SEAccelerometerData SEStatsMath::getMedian(long secondsTillNow) {
    SEAccelerometerData median;
    long middleElement = medianWindowSize / 2;
    
    long aaaa = skippedListX->size();
    
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
    
    /*
    for (size_t i = 0; i < data.size(); ++i) {
        sl.insert(data[i]);
        if (i  >= win_length) {
            result.push_back(sl.at(win_length / 2));
            sl.remove(data[i - win_length]);
        }
    }*/
    
}

