

#import <Foundation/Foundation.h>

@interface UIDevice (org_apache_cordova_UIDevice_Extension)

/*
    Get the unique identifier from the app bundle's folder, which is already a GUID
    Upgrading and/or deleting the app and re-installing will get you a new GUID, so
    this is only unique per install per device.
 */
- (NSString*)uniqueAppInstanceIdentifier;

@end
