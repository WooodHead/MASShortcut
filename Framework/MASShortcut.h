#import "MASKeyCodes.h"
#import <AppKit/AppKit.h>

#define MASShortcutChar(char) [NSString stringWithFormat:@"%C", (unsigned short)(char)]
#define MASShortcutClear(flags) (flags & (NSControlKeyMask | NSShiftKeyMask | NSAlternateKeyMask | NSCommandKeyMask))
#define MASShortcutCarbonFlags(cocoaFlags) (\
    (cocoaFlags & NSCommandKeyMask ? cmdKey : 0) | \
    (cocoaFlags & NSAlternateKeyMask ? optionKey : 0) | \
    (cocoaFlags & NSControlKeyMask ? controlKey : 0) | \
    (cocoaFlags & NSShiftKeyMask ? shiftKey : 0))


@interface MASShortcut : NSObject <NSSecureCoding>

@property (nonatomic) NSUInteger keyCode;
@property (nonatomic) NSUInteger modifierFlags;
@property (nonatomic, readonly) UInt32 carbonKeyCode;
@property (nonatomic, readonly) UInt32 carbonFlags;
@property (nonatomic, readonly) NSString *keyCodeString;
@property (nonatomic, readonly) NSString *keyCodeStringForKeyEquivalent;
@property (nonatomic, readonly) NSString *modifierFlagsString;
@property (nonatomic, readonly) NSData *data;
@property (nonatomic, readonly) BOOL shouldBypass;
@property (nonatomic, readonly, getter = isValid) BOOL valid;

- (id)initWithKeyCode:(NSUInteger)code modifierFlags:(NSUInteger)flags;

+ (MASShortcut *)shortcutWithKeyCode:(NSUInteger)code modifierFlags:(NSUInteger)flags;
+ (MASShortcut *)shortcutWithEvent:(NSEvent *)anEvent;
+ (MASShortcut *)shortcutWithData:(NSData *)aData;

- (BOOL)isTakenError:(NSError **)error;

// The following API enable hotkeys with the Option key as the only modifier
// For example, Option-G will not generate © and Option-R will not paste ®
+ (void)setAllowsAnyHotkeyWithOptionModifier:(BOOL)allow;
+ (BOOL)allowsAnyHotkeyWithOptionModifier;

@end
