//
//  ZMRichFormatConstants.h
//  ZoomMsgUI
//
//  Created by Yong Zhou on 4/21/22.
//

#ifndef ZMRichFormatConstants_h
#define ZMRichFormatConstants_h

static NSString* const ZMQuoteSymbolString = @"\u2033";
static NSString* const ZMDefaultServerTextColor = @"222230";
static NSString* const ZMDefaultServerTextDarkColor = @"FFFFFF";
static NSString* const ZMDefaultServerTextBgColor = @"FFFFFF";
static NSString* const ZMDefaultServerTextBgDarkColor = @"222230";
static inline NSColor * ZMInputTextViewDefaultTextColor(void)   { return ZMHexColor(0x222230, 0xFFFFFF); }
static inline NSColor * ZMInputTextViewDefaultTextBgColor(void) { return ZMHexColor(0xFFFFFF, 0x222230); }
static inline NSColor * ZMTextFormatQuoteTextColor(void)        { return ZMHexColor(0x676C7A, 0x9A9A9A); }
static inline NSColor * ZMTextFormatQuoteSymbolColor(void)      { return NSColorFromHex(0x1C7EF6); }

static inline NSString *ZMTextFormatDefaultTextColor(void)
{
    if (NSApp.isDarkMode) {
        return ZMDefaultServerTextDarkColor;
    }
    return ZMDefaultServerTextColor;
}

static inline NSString *ZMTextFormatDefaultTextBgColor(void)
{
    if (NSApp.isDarkMode) {
        return ZMDefaultServerTextBgDarkColor;
    }
    return ZMDefaultServerTextBgColor;
}

static NSString* const ZMInsertLinkAttributeName = @"ZMInsertLinkAttributeName";
// ZOOM-628330:
// This attribute contributes a virtual link that cannot be clicked directly. However,
// menu items and smart selection are still preserved. Clients should combine it with
// other style attributes to make the text look like a link.
static NSString* const ZMPhantomLinkAttributeName = @"ZMPhantomLinkAttributeName";

static CGFloat  const   ZMInputTextViewBasicReferenceFontSize = 13.0;
static inline CGFloat   ZMInputTextViewDefaultFontSize(void)    { return (NSInteger)(ZMInputTextViewBasicReferenceFontSize * NSApp.fontSizeRate / 100);}
static inline CGFloat   ZMBulletListDefaultIndent(void)    { return (2.0 * ZMInputTextViewDefaultFontSize());}
static inline CGFloat   ZMNumberListDefaultIndent(void)    { return (2.0 * ZMInputTextViewDefaultFontSize());}
static inline CGFloat   ZMQuoteListDefaultIndent(void)     { return (1.0 * ZMInputTextViewDefaultFontSize());}

static const CGFloat  ZMFormatParagraphSpacing = 5.0f;
static const CGFloat  ZMFormatPerIndent = 40.0f;
static const CGFloat  ZMFormatMaxParagraphIndent = 400.0f;
static const CGFloat  ZMQuoteEndSpacing = 5;

typedef NS_OPTIONS(NSUInteger, ZMTextFormatStyle)
{
    ZMTextFormatStyle_None                = 0,
    ZMTextFormatStyle_Bold                = 1<<0,
    ZMTextFormatStyle_Italic              = 1<<1,
    ZMTextFormatStyle_Underline           = 1<<2,
    ZMTextFormatStyle_Strikethrough       = 1<<3,
    ZMTextFormatStyle_Color               = 1<<4,
    ZMTextFormatStyle_Size                = 1<<5,
    ZMTextFormatStyle_AddLink             = 1<<6,
    ZMTextFormatStyle_Paragraph           = 1<<7,
    ZMTextFormatStyle_BulletList          = 1<<8,
    ZMTextFormatStyle_NumberList          = 1<<9,
    ZMTextFormatStyle_IncreaseIndent      = 1<<10,
    ZMTextFormatStyle_DecreaseIndent      = 1<<11,
    ZMTextFormatStyle_Quote               = 1<<12,
    ZMTextFormatStyle_ClearStyle          = 1<<13,
    ZMTextFormatStyle_Reserved            = 1<<14,
};

typedef NS_ENUM (NSInteger, ZMTextFormatSizeType) {
    ZMTextFormatSize_Small = 0,
    ZMTextFormatSize_Medium,
    ZMTextFormatSize_Large
};

typedef NS_ENUM (NSInteger, ZMTextFormatParagraphType) {
    ZMTextFormatParagraph_Heading1 = 0,
    ZMTextFormatParagraph_Heading2,
    ZMTextFormatParagraph_Heading3,
    ZMTextFormatParagraph_Paragraph
};

typedef NS_ENUM (NSInteger, ZMTextFormatListType) {
    ZMTextFormatList_BulletList = 0,
    ZMTextFormatList_NumberList,
    ZMTextFormatList_QuoteList
};

typedef NS_ENUM (NSInteger, ZMTextFormatShowLinkViewType) {
    ZMTextFormatShowLinkView_AddLink = 0,
    ZMTextFormatShowLinkView_EditLink,
    ZMTextFormatShowLinkView_EditToAddLink,
};

typedef NS_ENUM (NSInteger, ZMTextFormatTextColorType) {
    ZMTextFormatTextColor_Foreground = 0,
    ZMTextFormatTextColor_Background,
};

#endif /* ZMRichFormatConstants_h */
