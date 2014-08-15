/*
  */

@interface NSArray (CDVJSONSerializing)
- (NSString*)JSONString;
@end

@interface NSDictionary (CDVJSONSerializing)
- (NSString*)JSONString;
@end

@interface NSString (CDVJSONSerializing)
- (id)JSONObject;
@end
