#import <Foundation/Foundation.h>

#import "SpectacleShortcut.h"

#define LocalizedString(string) NSLocalizedString(string, string)

#pragma mark -

#define FlipVerticalOriginOfRectInRect(a, b) (b.size.height - (a.origin.y + a.size.height) + ([[[NSScreen screens] objectAtIndex:0] frame].size.height - b.size.height))

#pragma mark -

#define RectCenteredWithinRect(a, b) (CGRectContainsRect(a, b) && (fabs(CGRectGetMidX(b) - CGRectGetMidX(a)) <= 1.0f && fabs(CGRectGetMidY(b) - CGRectGetMidY(a)) <= 1.0f))

#pragma mark -

#define AreaOfRect(a) (CGFloat)(a.size.width * a.size.height)

#pragma mark -

#define RectIsLeftOfRect(a, b) ((b.origin.x - a.size.width) == a.origin.x)
#define RectIsRightOfRect(a, b) ((b.origin.x + b.size.width) == a.origin.x)
#define RectIsAboveRect(a, b) ((b.origin.y + b.size.height) == a.origin.y)
#define RectIsBelowRect(a, b) ((b.origin.y - a.size.height) == a.origin.y)

#pragma mark -

#define RectFitsInRect(a, b) ((a.size.width <= b.size.width) && (a.size.height <= b.size.height))

#pragma mark -

#define MovingToNextOrPreviousDisplay(action) ((action == SpectacleWindowActionNextDisplay) || (action == SpectacleWindowActionPreviousDisplay))

#pragma mark -

#define RectToString(windowRect) [NSString stringWithFormat:@"(%.1f, %.1f) %.1fx%.1f", windowRect.origin.x, windowRect.origin.y, windowRect.size.width, windowRect.size.height]


typedef NS_ENUM(NSInteger, SpectacleApplicationTrust) {
  SpectacleIsTrusted,
  SpectacleIsNotTrusted
};

#pragma mark -

@interface SpectacleUtilities : NSObject

#pragma mark -

+ (NSString *)applicationVersion;

#pragma mark -

+ (void)registerDefaultsForBundle:(NSBundle *)bundle;

#pragma mark -

+ (void)displayRunningInBackgroundAlertWithCallback:(void (^)(BOOL, BOOL))callback;

+ (void)displayRestoreDefaultsAlertWithCallback:(void (^)(BOOL))callback;

#pragma mark -

+ (SpectacleApplicationTrust)spectacleTrust;

#pragma mark -

+ (NSArray *)shortcutNames;

#pragma mark -

+ (NSArray *)shortcutsFromDictionary:(NSDictionary *)dictionary action:(SpectacleShortcutAction)action;

#pragma mark -

+ (void)restoreDefaultShortcuts;

#pragma mark -

+ (NSString *)pathForPreferencePaneNamed:(NSString *)preferencePaneName;

#pragma mark -

+ (BOOL)isLoginItemEnabledForBundle:(NSBundle *)bundle;

#pragma mark -

+ (void)enableLoginItemForBundle:(NSBundle *)bundle;

+ (void)disableLoginItemForBundle:(NSBundle *)bundle;

#pragma mark -

+ (NSMutableDictionary *)stringAttributesWithShadow;

@end
