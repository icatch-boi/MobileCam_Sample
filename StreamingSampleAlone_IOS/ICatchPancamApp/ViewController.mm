//
//  ViewController.m
//  ICatchPancamApp
//
//  Created by linux1 on 9/29/16.
//  Copyright © 2016 linux1. All rights reserved.
//

#import <GLKit/GLKit.h>

#include <atomic>

#import "type/ICatchCodec.h"
#import "type/ICatchH264StreamParam.h"
#import "type/transport/ICatchINETTransport.h"

#import "type/ICatchGLColor.h"
#import "type/ICatchGLPoint.h"
#import "type/ICatchGLRotation.h"
#import "type/ICatchGLDisplayPPI.h"
#import "type/ICatchGLSurfaceType.h"
#import "type/ICatchGLPanoramaType.h"

#import "surface/ICatchSurfaceContext.h"
#import "surface/ICatchSurfaceContext_IOS.h"

#import "ICatchPancamSession.h"
#import "ICatchIPancamImage.h"
#import "ICatchIPancamPreview.h"
#import "gl/ICatchIPancamGL.h"
#import "gl/ICatchIPancamGLTransform.h"

using namespace std;
using namespace com::icatchtek::reliant;
using namespace com::icatchtek::pancam;

#import "FileUtil.h"
#import "CRawImageUtil.h"
#import "ViewController.h"

@interface ViewController () <GLKViewDelegate>
{
    bool                                    needSetup;
    shared_ptr<ICatchSurfaceContext>        surfaceContext;
    shared_ptr<ICatchIPancamGL>             pancamGL;
    shared_ptr<ICatchIPancamGLTransform>    pancamGLTransform;
    
    
    bool                                    streamingrun;
    shared_ptr<ICatchIPancamImage>          pancamImage;
    shared_ptr<ICatchIPancamPreview>        pancamPreview;
    shared_ptr<ICatchPancamSession>         pancamSession;
}
@property (strong, nonatomic) EAGLContext* context;
@property (strong, nonatomic) GLKBaseEffect* baseEffect;
@end

@implementation ViewController

- (void)viewDidLoad {
    
    NSLog(@"viewDidLoad in\n");
    [super viewDidLoad];


    self.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
    if (!self.context) {
        NSLog(@"Failed to create ES context");
    }
    
    GLKView* view = (GLKView*)self.view;

    view.context = self.context;
    view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
    
    _motionManager = [[CMMotionManager alloc] init];
    _queue = [[NSOperationQueue alloc]init];
    streamingrun = false;
    
    [self initialSession];
}

- (void)dealloc
{
    [self stopPreview];
    [self uninitSession];
    
    if ([EAGLContext currentContext] == self.context) {
        [EAGLContext setCurrentContext:nil];
    }
    NSLog(@"dealloc out\n");
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void) viewDidDisappear:(BOOL)animated
{
    [_motionManager stopGyroUpdates];
}

//-------------- GL Functions(UI sys override) -----------------
//--------------------------------------------------------------
- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
    int windowW = (int)view.drawableWidth;
    int windowH = (int)view.drawableHeight;
    
    if (surfaceContext && surfaceContext->needSetup()) {
        surfaceContext->setup();
        surfaceContext->setViewPort(0,0, windowW, windowH);
    }
    
    if (surfaceContext && surfaceContext->needRender()) {
        surfaceContext->setViewPort(0,0, windowW, windowH);
        surfaceContext->render();
        NSLog(@"call render");
    }
}

//-------------------- UI Events -------------------------------
//--------------------------------------------------------------
static double __timestampA = 0;

- (void) configureGyro
{
    if (([_motionManager isGyroAvailable])) {
        [self.motionManager startGyroUpdatesToQueue:_queue withHandler:^(CMGyroData* gyroData, NSError* error){
            
            if (__timestampA == 0) {
                __timestampA = gyroData.timestamp;
            }
#if 1
            long timestamp = (gyroData.timestamp - __timestampA) * 1000 * 1000 * 1000;
            if (pancamGL != NULL) {
                //NSLog(@"%.2f, %.2f, %.2f, %ld", gyroData.rotationRate.x, gyroData.rotationRate.y, gyroData.rotationRate.z, timestamp);

                switch ([[UIApplication sharedApplication] statusBarOrientation]) {
                    case UIInterfaceOrientationPortrait:
                        pancamGLTransform->rotate(ICH_GL_ROTATION_0, gyroData.rotationRate.x, gyroData.rotationRate.y, gyroData.rotationRate.z, timestamp);
                        break;
                    case UIInterfaceOrientationLandscapeLeft:
                        pancamGLTransform->rotate(ICH_GL_ROTATION_90, gyroData.rotationRate.x, gyroData.rotationRate.y, gyroData.rotationRate.z, timestamp);
                        break;
                    case UIInterfaceOrientationPortraitUpsideDown:
                        pancamGLTransform->rotate(ICH_GL_ROTATION_180, gyroData.rotationRate.x, gyroData.rotationRate.y, gyroData.rotationRate.z, timestamp);
                        break;
                    case UIInterfaceOrientationLandscapeRight:
                        pancamGLTransform->rotate(ICH_GL_ROTATION_270, gyroData.rotationRate.x, gyroData.rotationRate.y, gyroData.rotationRate.z, timestamp);
                        break;
                    case UIInterfaceOrientationUnknown:
                        break;
                }
            }
#endif
        }];
    }
    else {
        NSLog(@"Gyro not abaliable");
    }
}

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    for(UITouch *touch in event.allTouches) {
        CGPoint pointC = [touch locationInView:nil];
        pointP.x = pointC.x;
        pointP.y = pointC.y;
    }
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
    for(UITouch *touch in event.allTouches) {
        
        // Create ICatch GL point
        CGPoint pointC = [touch locationInView:nil];
        auto pointGLC = make_shared<ICatchGLPoint>(pointC.x, pointC.y);
        auto pointGLP = make_shared<ICatchGLPoint>(pointP.x, pointP.y);
        NSLog(@"px %f py %f ex %f ey %f", pointGLP->getX(), pointGLP->getY(), pointGLC->getX(), pointGLC->getY());
        // Rotate
        if (pancamGL != NULL) {
            pancamGLTransform->rotate(pointGLP, pointGLC);
        }
        
        // Update Prev point
        pointP.x = pointC.x;
        pointP.y = pointC.y;
    }
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    // Nothing to do
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
    // Nothing to do
}

//---Session(SDK) realted features, and on click functions -----
//--------------------------------------------------------------
atomic<int> sessionID(1); // for multi-session app, the sessionID should not be the same.

- (void)initialSession
{
    needSetup = true;
    pancamSession = make_shared<ICatchPancamSession>(sessionID);
    
    auto defaultColor  = make_shared<ICatchGLColor>(0.0f, 0.0f, 0.0f, 1.0f);
    auto displayPPI    = make_shared<ICatchGLDisplayPPI>(800, 800);
    auto inetTransport = make_shared<ICatchINETTransport>("192.168.1.1");
    pancamSession->prepareSession(inetTransport, defaultColor, displayPPI);
    
    pancamPreview = pancamSession->getPreview();
}

- (void)uninitSession
{
    pancamSession->destroySession();
}

- (void)startPrevew
{
    if(streamingrun) return;
    
    NSLog(@"preview: %p", pancamPreview.get());
    pancamPreview->enableGLRender(pancamGL);
    
    /* use the panorama mode, we also support some other modes such as asteroid mode */
    pancamGL->init(ICH_GL_PANORAMA_TYPE_SPHERE);   
	
    /* transform interface */
    pancamGL->getPancamGLTransform(pancamGLTransform);

    /* set surface */
    surfaceContext = make_shared<ICatchSurfaceContext_IosEAGL>();
    pancamGL->setSurface(ICH_GL_SURFACE_TYPE_SPHERE, surfaceContext);   
    
    /* set up the gl context(render) */
    [EAGLContext setCurrentContext:self.context];
    int ret = surfaceContext->setup();
    NSLog(@"setupGL with surfaceContext: %p, ret %d\n", surfaceContext.get(), ret);

    /* No gl related work done, we start the stream. */.    
    auto streamParam = make_shared<ICatchH264StreamParam>();
    pancamPreview->start(streamParam, false);
    streamingrun = true;
    NSLog(@"viewDidLoad out\n");
}

- (void)stopPreview
{
    if(!streamingrun) return;
    
    pancamPreview->stop();
    streamingrun = false;
    
    NSLog(@"tear down gl in\n");
    [EAGLContext setCurrentContext:self.context];
    if (surfaceContext != nil)
        surfaceContext->tearDown();
  
    pancamGL->clearFormat();
    pancamGL->release();
}

- (IBAction)startPreview:(id)sender {
    [self startPrevew];
}

- (IBAction)Stop:(id)sender {
    [self stopPreview];
}

@end
