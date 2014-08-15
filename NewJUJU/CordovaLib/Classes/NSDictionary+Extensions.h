/*
  */

#import <Foundation/Foundation.h>

@interface NSDictionary (org_apache_cordova_NSDictionary_Extension)

- (bool)existsValue:(NSString*)expectedValue forKey:(NSString*)key;
- (NSInteger)integerValueForKey:(NSString*)key defaultValue:(NSInteger)defaultValue withRange:(NSRange)range;
- (NSInteger)integerValueForKey:(NSString*)key defaultValue:(NSInteger)defaultValue;
- (BOOL)typeValueForKey:(NSString*)key isArray:(BOOL*)bArray isNull:(BOOL*)bNull isNumber:(BOOL*)bNumber isString:(BOOL*)bString;
- (BOOL)valueForKeyIsArray:(NSString*)key;
- (BOOL)valueForKeyIsNull:(NSString*)key;
- (BOOL)valueForKeyIsString:(NSString*)key;
- (BOOL)valueForKeyIsNumber:(NSString*)key;

- (NSDictionary*)dictionaryWithLowercaseKeys;

@end
