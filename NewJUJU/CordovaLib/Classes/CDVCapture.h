/*

 */

#import <Foundation/Foundation.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import <AVFoundation/AVFoundation.h>
#import "CDVPlugin.h"
#import "CDVFile.h"

enum CDVCaptureError {
    CAPTURE_INTERNAL_ERR = 0,
    CAPTURE_APPLICATION_BUSY = 1,
    CAPTURE_INVALID_ARGUMENT = 2,
    CAPTURE_NO_MEDIA_FILES = 3,
    CAPTURE_NOT_SUPPORTED = 20
};
typedef NSUInteger CDVCaptureError;

@interface CDVImagePicker : UIImagePickerController
{
    NSString* callbackid;
    NSInteger quality;
    NSString* mimeType;
}
@property (assign) NSInteger quality;
@property (copy)   NSString* callbackId;
@property (copy)   NSString* mimeType;

@end

@interface CDVCapture : CDVPlugin <UIImagePickerControllerDelegate, UINavigationControllerDelegate>
{
    CDVImagePicker* pickerController;
    BOOL inUse;
}
@property BOOL inUse;
- (void)captureAudio:(CDVInvokedUrlCommand*)command;
- (void)captureImage:(CDVInvokedUrlCommand*)command;
- (CDVPluginResult*)processImage:(UIImage*)image type:(NSString*)mimeType forCallbackId:(NSString*)callbackId;
- (void)captureVideo:(CDVInvokedUrlCommand*)command;
- (CDVPluginResult*)processVideo:(NSString*)moviePath forCallbackId:(NSString*)callbackId;
- (void)getMediaModes:(CDVInvokedUrlCommand*)command;
- (void)getFormatData:(CDVInvokedUrlCommand*)command;
- (NSDictionary*)getMediaDictionaryFromPath:(NSString*)fullPath ofType:(NSString*)type;
- (void)imagePickerController:(UIImagePickerController*)picker didFinishPickingMediaWithInfo:(NSDictionary*)info;
- (void)imagePickerController:(UIImagePickerController*)picker didFinishPickingImage:(UIImage*)image editingInfo:(NSDictionary*)editingInfo;
- (void)imagePickerControllerDidCancel:(UIImagePickerController*)picker;

@end

@interface CDVAudioNavigationController : UINavigationController

@end

/* AudioRecorderViewController is used to create a simple view for audio recording.
 *  It is created from [Capture captureAudio].  It creates a very simple interface for
 *  recording by presenting just a record/stop button and a Done button to close the view.
 *  The recording time is displayed and recording for a specified duration is supported. When duration
 *  is specified there is no UI to the user - recording just stops when the specified
 *  duration is reached.  The UI has been minimized to avoid localization.
 */
@interface CDVAudioRecorderViewController : UIViewController <AVAudioRecorderDelegate>
{
    CDVCaptureError errorCode;
    NSString* callbackId;
    NSNumber* duration;
    CDVCapture* captureCommand;
    UIBarButtonItem* doneButton;
    UIView* recordingView;
    UIButton* recordButton;
    UIImage* recordImage;
    UIImage* stopRecordImage;
    UILabel* timerLabel;
    AVAudioRecorder* avRecorder;
    AVAudioSession* avSession;
    CDVPluginResult* pluginResult;
    NSTimer* timer;
    BOOL isTimed;
}
@property (nonatomic) CDVCaptureError errorCode;
@property (nonatomic, copy) NSString* callbackId;
@property (nonatomic, copy) NSNumber* duration;
@property (nonatomic, strong) CDVCapture* captureCommand;
@property (nonatomic, strong) UIBarButtonItem* doneButton;
@property (nonatomic, strong) UIView* recordingView;
@property (nonatomic, strong) UIButton* recordButton;
@property (nonatomic, strong) UIImage* recordImage;
@property (nonatomic, strong) UIImage* stopRecordImage;
@property (nonatomic, strong) UILabel* timerLabel;
@property (nonatomic, strong) AVAudioRecorder* avRecorder;
@property (nonatomic, strong) AVAudioSession* avSession;
@property (nonatomic, strong) CDVPluginResult* pluginResult;
@property (nonatomic, strong) NSTimer* timer;
@property (nonatomic) BOOL isTimed;

- (id)initWithCommand:(CDVPlugin*)theCommand duration:(NSNumber*)theDuration callbackId:(NSString*)theCallbackId;
- (void)processButton:(id)sender;
- (void)stopRecordingCleanup;
- (void)dismissAudioView:(id)sender;
- (NSString*)formatTime:(int)interval;
- (void)updateTime;
@end
