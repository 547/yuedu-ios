//
//  DownloadService.h
//  YueduFM
//
//  Created by StarNet on 9/26/15.
//  Copyright (c) 2015 StarNet. All rights reserved.
//

#import "BaseService.h"

@class YDSDKArticleModelEx;

extern NSString* const DownloadSeriviceDidChangedNotification;

@interface NSURLSessionTask (DownloadService)

@property (nonatomic, strong) YDSDKArticleModelEx* articleModel;

@end

typedef NS_ENUM(NSUInteger, DownloadErrorCode) {
    DownloadErrorCodeAlreadyDownloading = 1000,
    DownloadErrorCodeAlreadyDownloaded,
};

@interface DownloadService : BaseService

@property (nonatomic, copy) void(^backgroundTransferCompletionHandler)();

- (void)state:(void(^)(BOOL downloading))completion;

- (void)download:(YDSDKArticleModelEx* )model
      preprocess:(void(^)(NSError* error))preprocess;

- (void)list:(void(^)(NSArray* tasks))completion;

- (void)deleteTask:(NSURLSessionTask* )task;

- (void)deleteAllTask:(void(^)())completion;

@end