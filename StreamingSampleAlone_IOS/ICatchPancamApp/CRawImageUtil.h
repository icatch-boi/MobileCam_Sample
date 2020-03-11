//
//  Header.h
//  ICatchPancamApp
//
//  Created by linux1 on 10/10/16.
//  Copyright © 2016 linux1. All rights reserved.
//

#ifndef CRawImageUtil_h
#define CRawImageUtil_h

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface CRawImageUtil : NSObject
{
    NSString*   imagePath;
    
    Byte*       imageData;
    int         imageWidth;
    int         imageHeight;
    int         imageSize;
}

- (bool)  initUIImage : (UIImage*)image;
- (bool)  initImage : (NSString*)imageName;
- (bool)  uninitImage;

- (Byte*) getImageData;
- (int)   getImageWidth;
- (int)   getImageHeight;
- (int)   getImageSize;

@end

#endif /* CRawImageUtil_h */
