//
//  main.m
//  ICatchPancamApp
//
//  Created by linux1 on 9/29/16.
//  Copyright © 2016 linux1. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

#import "type/ICatchGLLogType.h"
#import "type/ICatchGLLogLevel.h"
#import "ICatchPancamLog.h"

using namespace com::icatchtek::pancam;

int main(int argc, char * argv[]) {
    
    @autoreleasepool {
        
        ICatchPancamLog::getInstance()->setFileLogOutput(false);
        ICatchPancamLog::getInstance()->setSystemLogOutput(true);
        ICatchPancamLog::getInstance()->setLog(ICH_GL_LOG_TYPE_OPENGL, true);
        ICatchPancamLog::getInstance()->setLog(ICH_GL_LOG_TYPE_STREAM, false);
        ICatchPancamLog::getInstance()->setLog(ICH_GL_LOG_TYPE_COMMON, false);
        ICatchPancamLog::getInstance()->setLog(ICH_GL_LOG_TYPE_DEVELOP, false);
        ICatchPancamLog::getInstance()->setLogLevel(ICH_GL_LOG_TYPE_OPENGL, ICH_GL_LOG_LEVEL_INFO);
        ICatchPancamLog::getInstance()->setLogLevel(ICH_GL_LOG_TYPE_STREAM, ICH_GL_LOG_LEVEL_INFO);
        ICatchPancamLog::getInstance()->setLogLevel(ICH_GL_LOG_TYPE_COMMON, ICH_GL_LOG_LEVEL_INFO);
        ICatchPancamLog::getInstance()->setLogLevel(ICH_GL_LOG_TYPE_DEVELOP, ICH_GL_LOG_LEVEL_INFO);

        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
