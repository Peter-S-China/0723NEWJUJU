/*
 
 */

#import "CDVConfigParser.h"

@interface CDVConfigParser ()

@property (nonatomic, readwrite, strong) NSMutableDictionary* pluginsDict;
@property (nonatomic, readwrite, strong) NSMutableDictionary* settings;
@property (nonatomic, readwrite, strong) NSMutableArray* whitelistHosts;
@property (nonatomic, readwrite, strong) NSMutableArray* startupPluginNames;
@property (nonatomic, readwrite, strong) NSString* startPage;

@end

@implementation CDVConfigParser

@synthesize pluginsDict, settings, whitelistHosts, startPage, startupPluginNames;

- (id)init
{
    self = [super init];
    if (self != nil) {
        self.pluginsDict = [[NSMutableDictionary alloc] initWithCapacity:30];
        self.settings = [[NSMutableDictionary alloc] initWithCapacity:30];
        self.whitelistHosts = [[NSMutableArray alloc] initWithCapacity:30];
        self.startupPluginNames = [[NSMutableArray alloc] initWithCapacity:8];
    }
    return self;
}

- (void)parser:(NSXMLParser*)parser didStartElement:(NSString*)elementName namespaceURI:(NSString*)namespaceURI qualifiedName:(NSString*)qualifiedName attributes:(NSDictionary*)attributeDict
{
    if ([elementName isEqualToString:@"preference"]) {
        settings[attributeDict[@"name"]] = attributeDict[@"value"];
    } else if ([elementName isEqualToString:@"plugin"]) {
        NSString* name = [attributeDict[@"name"] lowercaseString];
        pluginsDict[name] = attributeDict[@"value"];
        if ([@"true" isEqualToString : attributeDict[@"onload"]]) {
            [self.startupPluginNames addObject:name];
        }
    } else if ([elementName isEqualToString:@"access"]) {
        [whitelistHosts addObject:attributeDict[@"origin"]];
    } else if ([elementName isEqualToString:@"content"]) {
        self.startPage = attributeDict[@"src"];
    }
}

- (void)parser:(NSXMLParser*)parser parseErrorOccurred:(NSError*)parseError
{
    NSAssert(NO, @"config.xml parse error line %d col %d", [parser lineNumber], [parser columnNumber]);
}

@end
