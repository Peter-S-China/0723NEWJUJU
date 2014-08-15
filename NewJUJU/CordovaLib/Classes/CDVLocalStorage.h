/*
 */

#import "CDVPlugin.h"

#define kCDVLocalStorageErrorDomain @"kCDVLocalStorageErrorDomain"
#define kCDVLocalStorageFileOperationError 1

@interface CDVLocalStorage : CDVPlugin

@property (nonatomic, readonly, strong) NSMutableArray* backupInfo;

- (BOOL)shouldBackup;
- (BOOL)shouldRestore;
- (void)backup:(CDVInvokedUrlCommand*)command;
- (void)restore:(CDVInvokedUrlCommand*)command;

+ (void)__fixupDatabaseLocationsWithBackupType:(NSString*)backupType;
// Visible for testing.
+ (BOOL)__verifyAndFixDatabaseLocationsWithAppPlistDict:(NSMutableDictionary*)appPlistDict
                                             bundlePath:(NSString*)bundlePath
                                            fileManager:(NSFileManager*)fileManager;
@end

@interface CDVBackupInfo : NSObject

@property (nonatomic, copy) NSString* original;
@property (nonatomic, copy) NSString* backup;
@property (nonatomic, copy) NSString* label;

- (BOOL)shouldBackup;
- (BOOL)shouldRestore;

@end
