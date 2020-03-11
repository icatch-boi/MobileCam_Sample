//
//  ViewController.h
//  ICatchPancamApp
//
//  Created by linux1 on 9/29/16.
//  Copyright © 2016 linux1. All rights reserved.
//

#import <GLKit/GLKit.h>
#import <CoreMotion/CoreMotion.h>

@interface ViewController : GLKViewController
{
    CGPoint pointP;
}

@property (nonatomic, strong) CMMotionManager* motionManager;
@property (nonatomic, strong) NSOperationQueue* queue;
@property (weak, nonatomic) IBOutlet GLKView *viewShow;

- (void) configureGyro;

@end

