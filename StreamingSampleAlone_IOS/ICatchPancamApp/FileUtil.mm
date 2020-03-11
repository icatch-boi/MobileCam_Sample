//
//  FileUtil.m
//  ICatchPancamApp
//
//  Created by linux1 on 10/10/16.
//  Copyright © 2016 linux1. All rights reserved.
//

#import <stdio.h>
#import <Foundation/Foundation.h>

#import "FileUtil.h"

/* Convert a given fileName to a path that can be used to open from the mainBundle
 * which can be opened using c API.
 */
static const char* __get_bundle_file_name(const char* fileName)
{
    //NSString* fileNameNS = [NSString stringWithUTF8String:fileName];
    //NSString* baseName   = [fileNameNS stringByDeletingPathExtension];
    //NSString* extension  = [fileNameNS pathExtension];
    ///Users/linux1/workspace/pancamapp/ICatchPancamApp/ICatchPancamApp/imageARGB.raw
    NSString* path = [[NSBundle mainBundle] pathForResource: @"quito1_s" ofType: @"jpg"];
    //NSString* path = @"/Users/linux1/Desktop/imageARGB.raw";
    NSLog(@"path: %@", path);
    //NSAssert(false, @"just print path");
    fileName = [path UTF8String];
    fileName = NULL;
    return fileName;
}

static FILE* __open_file(const char *fileName)
{
    fileName = __get_bundle_file_name(fileName);
    NSLog(@"fileName B: %s", fileName);
    
    FILE* file = fopen(fileName, "rw");
    NSLog(@"file handle: %p", file);
    
    return file;
}

static void __close_file(FILE* file)
{
    if (file != NULL)
    {
        fclose(file);
    }
}

static int __read_file(FILE* file, int bytesToRead, void *buffer)
{
    if (file == NULL)
    {
        return 0;
    }
    
    return (int)fread(buffer, bytesToRead, 1, file);
}

static int __get_file_length(FILE* file)
{
    if (file == NULL)
    {
        return 0;
    }
    
    int currentPosition = (int)ftell(file);
    
    fseek(file, 0, SEEK_END);
    int fileLength = (int)ftell(file);
    
    fseek(file, 0, currentPosition);
    return fileLength;
}

uint8_t* loadRawImageFile(const char *fileName, int bytesToRead)
{
    uint8_t*    buffer;
    FILE*      file;
    int        bytesRead;
    
    NSLog(@"Opening file: %s", fileName);
    file = __open_file(fileName);
    if (file == NULL)
    {
        NSLog(@"This raw image file FAILED to load: %s\n", fileName);
        return NULL;
    }
    
    int length = __get_file_length(file);
    if (length <= 0) {
        NSLog(@"This raw image contains no data: %s\n", fileName);
    }
    if (length != bytesToRead) {
        NSLog(@"This raw image size does not match the specified size: %s\n", fileName);
    }
    
    NSLog(@"The char contains %d bytes.\n", (int)sizeof(char));
    buffer = (uint8_t*)malloc(bytesToRead);
    
    bytesRead = __read_file (file, bytesToRead, buffer);
    if (bytesRead != bytesToRead || bytesRead <= 0) {
        NSLog(@"Reading error: %s, retVal: %d.\n", fileName, bytesRead);
    }
    
    __close_file(file);
    return buffer;
}
