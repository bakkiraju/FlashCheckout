// Generated by Apple Swift version 1.2 (swiftlang-602.0.49.6 clang-602.0.49)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__has_include) && __has_include(<uchar.h>)
# include <uchar.h>
#elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
#endif

typedef struct _NSZone NSZone;

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted) 
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
#endif
#if __has_feature(nullability)
#  define SWIFT_NULLABILITY(X) X
#else
# if !defined(__nonnull)
#  define __nonnull
# endif
# if !defined(__nullable)
#  define __nullable
# endif
# if !defined(__null_unspecified)
#  define __null_unspecified
# endif
#  define SWIFT_NULLABILITY(X)
#endif
#if defined(__has_feature) && __has_feature(modules)
@import QuartzCore;
@import CoreGraphics;
@import UIKit;
@import AVFoundation;
@import CoreFoundation;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class NSCoder;

SWIFT_CLASS("_TtC10RSBarcodes11RSCodeLayer")
@interface RSCodeLayer : CALayer
- (void)drawInContext:(CGContextRef __null_unspecified)ctx;
- (SWIFT_NULLABILITY(null_unspecified) instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(null_unspecified) instancetype)initWithLayer:(id __null_unspecified)layer OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class AVCaptureDevice;
@class AVCaptureMetadataOutput;
@class AVCaptureSession;
@class RSFocusMarkLayer;
@class RSCornersLayer;
@class AVMetadataMachineReadableCodeObject;
@protocol UIViewControllerTransitionCoordinator;
@class AVCaptureOutput;
@class AVCaptureConnection;
@class NSBundle;

SWIFT_CLASS("_TtC10RSBarcodes26RSCodeReaderViewController")
@interface RSCodeReaderViewController : UIViewController <AVCaptureMetadataOutputObjectsDelegate>
@property (nonatomic) AVCaptureDevice * __null_unspecified device;
@property (nonatomic) AVCaptureMetadataOutput * __nonnull output;
@property (nonatomic) AVCaptureSession * __nonnull session;
@property (nonatomic) RSFocusMarkLayer * __null_unspecified focusMarkLayer;
@property (nonatomic) RSCornersLayer * __null_unspecified cornersLayer;
@property (nonatomic, copy) void (^ __nullable tapHandler)(CGPoint);
@property (nonatomic, copy) void (^ __nullable barcodesHandler)(NSArray * __nonnull);
@property (nonatomic) BOOL isCrazyMode;
- (BOOL)hasFlash;
- (BOOL)hasTorch;
- (void)toggleTorch;
- (void)viewDidLayoutSubviews;
- (void)viewWillTransitionToSize:(CGSize)size withTransitionCoordinator:(id <UIViewControllerTransitionCoordinator> __nonnull)coordinator;
- (void)viewDidLoad;
- (void)viewWillAppear:(BOOL)animated;
- (void)viewDidDisappear:(BOOL)animated;
- (void)captureOutput:(AVCaptureOutput * __null_unspecified)captureOutput didOutputMetadataObjects:(NSArray * __null_unspecified)metadataObjects fromConnection:(AVCaptureConnection * __null_unspecified)connection;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithNibName:(NSString * __nullable)nibNameOrNil bundle:(NSBundle * __nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC10RSBarcodes14RSCornersLayer")
@interface RSCornersLayer : CALayer
@property (nonatomic) CGColorRef __null_unspecified strokeColor;
@property (nonatomic) CGFloat strokeWidth;
@property (nonatomic, copy) NSArray * __nonnull cornersArray;
- (void)drawInContext:(CGContextRef __null_unspecified)ctx;
- (SWIFT_NULLABILITY(null_unspecified) instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(null_unspecified) instancetype)initWithLayer:(id __null_unspecified)layer OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC10RSBarcodes16RSFocusMarkLayer")
@interface RSFocusMarkLayer : CALayer
@property (nonatomic) CGSize size;
@property (nonatomic) CGFloat sight;
@property (nonatomic) CGColorRef __null_unspecified strokeColor;
@property (nonatomic) CGFloat strokeWidth;
@property (nonatomic) CFTimeInterval delay;
@property (nonatomic) BOOL canDraw;
@property (nonatomic) CGPoint point;
- (void)drawInContext:(CGContextRef __null_unspecified)ctx;
- (SWIFT_NULLABILITY(null_unspecified) instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(null_unspecified) instancetype)initWithLayer:(id __null_unspecified)layer OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


@interface UIColor (SWIFT_EXTENSION(RSBarcodes))
@end

#pragma clang diagnostic pop
