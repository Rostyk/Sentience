//
//  SentianceExerciseTests.m
//  SentianceExerciseTests
//
//  Created by Apple on 7/29/18.
//  Copyright © 2018 Maliwan. All rights reserved.
//

#import <XCTest/XCTest.h>
#import "SERollingStats.h"
#import "DataSeeder.h"
#import "OperatorCallsCountHolder.h"
#include "Measurable.h"
#import "NSArray+Stats.h"

@interface SentianceExerciseTests : XCTestCase {
    SERollingStats<double> *doubleStats;
    SERollingStats<Measurable> *measurableStats;
    DataSeeder *seeder;
}

@property (nonatomic) NSUInteger MAX_ENTRIES;
@property (nonatomic) NSUInteger EXPECTATION_TIMEOUT;

@end

@implementation SentianceExerciseTests

- (void)setUp {
    [super setUp];

    _EXPECTATION_TIMEOUT = 10;
    _MAX_ENTRIES = 10000;
    
    //Range same as in accelerometer G
    seeder = new DataSeeder(_MAX_ENTRIES, 1.0, 10.0);
    doubleStats = new SERollingStats<double>(_MAX_ENTRIES);
    measurableStats = new SERollingStats<Measurable>(_MAX_ENTRIES);
    
    [self testMedianMetricOnDouble];
    [self testMedianMetricOnMeasurable];
    
    [self testMeanMetricOnDouble];
    [self testMeanMetricOnMeasurable];
    
    //[self testDeviationMetricOnDouble];
    //[self testDeviationMetricOnMeasurable];
}

- (void)testMedianMetricOnDouble {
    doubleStats->reset();
    
    NSMutableArray *arrayX = [[NSMutableArray alloc] init];
    NSMutableArray *arrayY = [[NSMutableArray alloc] init];
    NSMutableArray *arrayZ = [[NSMutableArray alloc] init];
    
    for (int i=0; i<_MAX_ENTRIES+2; i++) {
        SEAccelerometerData<double> entry = seeder->randomEntry();
        doubleStats->processAccelerometerData(entry);
        
        [arrayX addObject:@(entry.x)];
        [arrayY addObject:@(entry.y)];
        [arrayZ addObject:@(entry.z)];
    }
    
    SEAccelerometerData<double> median = doubleStats->getCurrentDataFrameMedian();
    
    if (fabs(median.x - [arrayX median]) > 0.01) {
        XCTFail(@"Median for X incorrect");
    }
    if (fabs(median.y - [arrayY median]) > 0.01) {
        XCTFail(@"Median for Y incorrect");
    }
    
    if (fabs(median.z - [arrayZ median]) > 0.01) {
        XCTFail(@"Median for Z incorrect");
    }
}

- (void)testMedianMetricOnMeasurable {
    measurableStats->reset();
    
    NSMutableArray *arrayX = [[NSMutableArray alloc] init];
    NSMutableArray *arrayY = [[NSMutableArray alloc] init];
    NSMutableArray *arrayZ = [[NSMutableArray alloc] init];
    
    for (int i=0; i<_MAX_ENTRIES+2; i++) {
        SEAccelerometerData<Measurable> entry = seeder->randomMeasurableEntry();
        measurableStats->processAccelerometerData(entry);
        
        [arrayX addObject:@(entry.x.value)];
        [arrayY addObject:@(entry.y.value)];
        [arrayZ addObject:@(entry.z.value)];
    }
    
    SEAccelerometerData<Measurable> median = measurableStats->getCurrentDataFrameMedian();
    
    if (fabs(median.x.value - [arrayX median]) > 0.01) {
        XCTFail(@"Median for X incorrect");
    }
    if (fabs(median.y.value - [arrayY median]) > 0.01) {
        XCTFail(@"Median for Y incorrect");
    }
    
    if (fabs(median.z.value - [arrayZ median]) > 0.01) {
        XCTFail(@"Median for Z incorrect");
    }
}


- (void)testMeanMetricOnDouble {
    doubleStats->reset();
    
    NSMutableArray *arrayX = [[NSMutableArray alloc] init];
    NSMutableArray *arrayY = [[NSMutableArray alloc] init];
    NSMutableArray *arrayZ = [[NSMutableArray alloc] init];
    
    for (int i=0; i<_MAX_ENTRIES+1; i++) {
        SEAccelerometerData<double> entry = seeder->randomEntry();
        doubleStats->processAccelerometerData(entry);
        
        [arrayX addObject:@(entry.x)];
        [arrayY addObject:@(entry.y)];
        [arrayZ addObject:@(entry.z)];
    }
    
    SEAccelerometerData<double> mean = doubleStats->getCurrentDataFrameMean();
    
    double XXX = [arrayX mean];
    double YYY = [arrayY mean];
    double ZZZ = [arrayZ mean];
    
    if (fabs(mean.x - [arrayX mean]) > 0.01) {
        XCTFail(@"Mean for X incorrect");
    }
    if (fabs(mean.y - [arrayY mean]) > 0.01) {
        XCTFail(@"Mean for Y incorrect");
    }
    
    if (fabs(mean.z - [arrayZ mean]) > 0.01) {
        XCTFail(@"Mean for Z incorrect");
    }
}

- (void)testMeanMetricOnMeasurable {
    measurableStats->reset();
    
    NSMutableArray *arrayX = [[NSMutableArray alloc] init];
    NSMutableArray *arrayY = [[NSMutableArray alloc] init];
    NSMutableArray *arrayZ = [[NSMutableArray alloc] init];
    
    for (int i=0; i<_MAX_ENTRIES+2; i++) {
        SEAccelerometerData<Measurable> entry = seeder->randomMeasurableEntry();
        measurableStats->processAccelerometerData(entry);
        
        [arrayX addObject:@(entry.x.value)];
        [arrayY addObject:@(entry.y.value)];
        [arrayZ addObject:@(entry.z.value)];
    }
    
    SEAccelerometerData<Measurable> mean = measurableStats->getCurrentDataFrameMean();
    
    if (fabs(mean.x.value - [arrayX mean]) > 0.01) {
        XCTFail(@"Mean for X incorrect");
    }
    if (fabs(mean.y.value - [arrayY mean]) > 0.01) {
        XCTFail(@"Mean for Y incorrect");
    }
    
    if (fabs(mean.z.value - [arrayZ mean]) > 0.01) {
        XCTFail(@"Mean for Z incorrect");
    }
}

- (void)tearDown {
    delete seeder;
    //delete stats;
    [super tearDown];
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
