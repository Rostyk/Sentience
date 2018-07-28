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

class SEStatsMath {
public:
    
    SEStatsMath(long medianDataFrame);
    ~SEStatsMath();
    void processAccelerometerData(SEAccelerometerData data);
    
    SEAccelerometerData getAllTimeMedian();
    SEAccelerometerData getCurrentDataFrameMedian();
    
private:
    OrderedStructs::SkipList::HeadNode<double> *skippedListX;
    OrderedStructs::SkipList::HeadNode<double> *skippedListY;
    OrderedStructs::SkipList::HeadNode<double> *skippedListZ;
    
    long medianDataFrame;
};

