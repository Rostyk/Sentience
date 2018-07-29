//
//  DataSeeder.h
//  SentianceExerciseTests
//
//  Created by Apple on 7/29/18.
//  Copyright © 2018 Maliwan. All rights reserved.
//

#include "SEAccelerometerData.h"
#include "Measurable.h"

class DataSeeder {
public:
    DataSeeder(long numberOfRecords, double minRange, double maxRange);
    SEAccelerometerData<double> randomEntry();
    SEAccelerometerData<Measurable> randomMeasurableEntry();

private:
    long numberOfRecords;
    double minRange;
    double maxRange;
    
    double randomDouble(double fMin, double fMax);
};
