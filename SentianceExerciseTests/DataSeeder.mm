//
//  DataSeeder.m
//  SentianceExerciseTests
//
//  Created by Apple on 7/29/18.
//  Copyright © 2018 Maliwan. All rights reserved.
//

#import "DataSeeder.h"
#include "SEAccelerometerData.h"
#include "Measurable.h"


DataSeeder::DataSeeder(long numberOfRecords, double minRange, double maxRange) {
    this->numberOfRecords = numberOfRecords;
    this->minRange = minRange;
    this->minRange = maxRange;
}


SEAccelerometerData<double> DataSeeder::randomEntry() {
    SEAccelerometerData<double> entry;
    
    entry.x = Measurable(randomDouble(minRange, maxRange));
    entry.y = Measurable(randomDouble(minRange, maxRange));
    entry.z = Measurable(randomDouble(minRange, maxRange));
    
    return entry;
}

SEAccelerometerData<Measurable> DataSeeder::randomMeasurableEntry() {
    SEAccelerometerData<Measurable> entry;
    
    entry.x = Measurable(randomDouble(minRange, maxRange));
    entry.y = Measurable(randomDouble(minRange, maxRange));
    entry.z = Measurable(randomDouble(minRange, maxRange));
    
    return entry;
}


double DataSeeder::randomDouble(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
