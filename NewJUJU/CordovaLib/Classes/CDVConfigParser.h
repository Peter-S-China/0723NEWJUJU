/*
 
 */

@interface CDVConfigParser : NSObject <NSXMLParserDelegate>{}

@property (nonatomic, readonly, strong) NSMutableDictionary* pluginsDict;
@property (nonatomic, readonly, strong) NSMutableDictionary* settings;
@property (nonatomic, readonly, strong) NSMutableArray* whitelistHosts;
@property (nonatomic, readonly, strong) NSMutableArray* startupPluginNames;
@property (nonatomic, readonly, strong) NSString* startPage;

@end
