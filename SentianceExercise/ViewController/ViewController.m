//
//  ViewController.m
//  SentianceExercise
//
//  Created by Apple on 7/28/18.
//  Copyright © 2018 Maliwan. All rights reserved.
//

#import "ViewController.h"
#import <CoreMotion/CoreMotion.h>
#import "StatIndicatorsController.h"

@interface ViewController ()
@property (nonatomic, weak) IBOutlet UILabel *label;
@property (nonatomic, strong) CMMotionManager *motionManager;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self performSelector:@selector(aaa) withObject:nil afterDelay:1.0];
    
    // user acceleration
    //deviceMotion.userAcceleration.x;
    
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)aaa {
    StatIndicatorsController *controller = [StatIndicatorsController new];
    [controller test];
    /*
    self.motionManager = [[CMMotionManager alloc] init];
    //self.motionManager.gyroUpdateInterval = 0.1;
    //[self.motionManager startGyroUpdates];
    //CMDeviceMotion *deviceMotion = motionManager.deviceMotion;
    
    
    __weak typeof(self) weakSelf = self;
    if (self.motionManager.accelerometerAvailable) {
        self.motionManager.accelerometerUpdateInterval = 0.1f;
        [self.motionManager startAccelerometerUpdatesToQueue:[NSOperationQueue mainQueue]
                                            withHandler:^(CMAccelerometerData *data, NSError *error) {
                                                
                                                weakSelf.label.text = [NSString stringWithFormat:@"X acceleration: %.3f. Y: %.3f. Z: %.3f", data.acceleration.x, data.acceleration.x, data.acceleration.x];
                                                
                                            }];
        //[self.motionManager startAccelerometerUpdates];
    }*/
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
