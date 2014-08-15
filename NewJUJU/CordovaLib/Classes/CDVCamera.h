/*
 */

#import <Foundation/Foundation.h>
#import "CDVPlugin.h"

enum CDVDestinationType {
    DestinationTypeDataUrl = 0,
    DestinationTypeFileUri,
    DestinationTypeNativeUri
};
typedef NSUInteger CDVDestinationType;

enum CDVEncodingType {
    EncodingTypeJPEG = 0,
    EncodingTypePNG
};
typedef NSUInteger CDVEncodingType;

enum CDVMediaType {
    MediaTypePicture = 0,
    MediaTypeVideo,
    MediaTypeAll
};
typedef NSUInteger CDVMediaType;

@interface CDVCameraPicker : UIImagePickerController
{}

@property (assign) NSInteger quality;
@property (copy)   NSString* callbackId;
@property (copy)   NSString* postUrl;
@property (nonatomic) enum CDVDestinationType returnType;
@property (nonatomic) enum CDVEncodingType encodingType;
@property (strong) UIPopoverController* popoverController;
@property (assign) CGSize targetSize;
@property (assign) bool correctOrientation;
@property (assign) bool saveToPhotoAlbum;
@property (assign) bool cropToSize;
@property (strong) UIWebView* webView;
@property (assign) BOOL popoverSupported;

@end

// ======================================================================= //

@interface CDVCamera : CDVPlugin <UIImagePickerControllerDelegate,
                       UINavigationControllerDelegate,
                       UIPopoverControllerDelegate>
{}

@property (strong) CDVCameraPicker* pickerController;

/*
 * getPicture
 *
 * arguments:
 *	1: this is the javascript function that will be called with the results, the first parameter passed to the
 *		javascript function is the picture as a Base64 encoded string
 *  2: this is the javascript function to be called if there was an error
 * options:
 *	quality: integer between 1 and 100
 */
- (void)takePicture:(CDVInvokedUrlCommand*)command;
- (void)postImage:(UIImage*)anImage withFilename:(NSString*)filename toUrl:(NSURL*)url;
- (void)cleanup:(CDVInvokedUrlCommand*)command;
- (void)repositionPopover:(CDVInvokedUrlCommand*)command;

- (void)imagePickerController:(UIImagePickerController*)picker didFinishPickingMediaWithInfo:(NSDictionary*)info;
- (void)imagePickerController:(UIImagePickerController*)picker didFinishPickingImage:(UIImage*)image editingInfo:(NSDictionary*)editingInfo;
- (void)imagePickerControllerDidCancel:(UIImagePickerController*)picker;
- (UIImage*)imageByScalingAndCroppingForSize:(UIImage*)anImage toSize:(CGSize)targetSize;
- (UIImage*)imageByScalingNotCroppingForSize:(UIImage*)anImage toSize:(CGSize)frameSize;
- (UIImage*)imageCorrectedForCaptureOrientation:(UIImage*)anImage;

@end
