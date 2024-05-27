//
//  IZMThemeMgr.h
//  ZoomSetting
//
//  Created by Francis Zhuo on 2024/2/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ZMThemeName){
    ZMThemeName_Bloom,
    ZMThemeName_Rose,
    ZMThemeName_Agave,
    ZMThemeName_Classic,
    ZMThemeName_Dark,//only for IM
    ZMThemeName_Custom,//only for meeting
    ZMThemeName_Backstage,//only for meeting
};

@protocol ZMThemeObject <ZMRoutableObject>
@property(assign) ZMThemeName name;
@property(strong) NSColor* color;
@property(strong) NSImage* image;
@property(strong) NSImage* selectedImage;
@property(strong) NSString* nameString;
@end

@protocol IZMThemeMgr <ZMRoutableObject>
- (ZMThemeName)selectedThemeName;
- (void)selectThemeWithName:(ZMThemeName)name;
- (void)setNeedsDisplay:(BOOL)needs;

- (NSArray<id<ZMThemeObject>>*)themeArray;
@end

@protocol ZMThemeProtocol <NSObject>
- (void)themeDidChanged;
@end

NS_ASSUME_NONNULL_END
