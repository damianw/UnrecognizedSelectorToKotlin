#import <Foundation/Foundation.h>

@protocol USTKSampleInterface;

NS_ASSUME_NONNULL_BEGIN

@interface KotlinBase : NSObject
-(instancetype) init __attribute__((unavailable));
+(instancetype) new __attribute__((unavailable));
+(void)initialize __attribute__((objc_requires_super));
@end;

@interface KotlinBase (KotlinBaseCopying) <NSCopying>
@end;

__attribute__((objc_runtime_name("KotlinMutableSet")))
@interface USTKMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end;

__attribute__((objc_runtime_name("KotlinMutableDictionary")))
@interface USTKMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end;

@interface NSError (NSErrorKotlinException)
@property (readonly) id _Nullable kotlinException;
@end;

@protocol USTKSampleInterface
@required
@property (readonly) NSArray<NSString *> *someStrings;
@end;

__attribute__((objc_subclassing_restricted))
@interface USTK : KotlinBase
+(NSString *)join:(id<USTKSampleInterface>)receiver NS_SWIFT_NAME(join(_:));
@end;

NS_ASSUME_NONNULL_END
