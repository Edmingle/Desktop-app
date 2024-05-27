//
//  ZMPersonalFolderItemMode.h
//  zChatUI
//
//  Created by Jed Zheng on 19/2/2022.
//  Copyright © 2022 Zoom. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZMPersonalFolderItemMode : NSObject
@property (nonatomic, copy) NSString *folderId;
@property (nonatomic, copy) NSString *folderName;
@property(nonatomic, assign) NSInteger sortIndex;
@property(nonatomic, assign) NSInteger membersSortType;
@end


@interface ZMPersonalFolderMemberMode : NSObject
@property (nonatomic, copy) NSString *sessionId;
@property(nonatomic, assign) NSInteger sortIndex;
@end


@interface ZMPersonalFolderMapMode : NSObject
@property (nonatomic, copy) NSString *folderId;
@property (nonatomic, retain) NSArray *changeMembers;
@end
