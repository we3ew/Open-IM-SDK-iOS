//
//  OIMManager+Group.h
//  OpenIMSDK
//
//  Created by x on 2022/2/16.
//

#import "OIMManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface OIMManager (Group)

/*
 * 创建群
 *
 * @param list  创建群是选择的成员.
 */
- (void)createGroup:(OIMGroupCreateInfo *)groupBaseInfo
         memberList:(NSArray<OIMGroupMemberBaseInfo *> *)list
          onSuccess:(nullable OIMGroupInfoCallback)onSuccess
          onFailure:(nullable OIMFailureCallback)onFailure;

/*
 * 申请加入群组
 *
 * @param gid    群组ID
 * @param reqMsg 进群申请消息
 */
- (void)joinGroup:(NSString *)gid
           reqMsg:(NSString * _Nullable)reqMsg
        onSuccess:(nullable OIMSuccessCallback)onSuccess
        onFailure:(nullable OIMFailureCallback)onFailure;

/*
 * 退群
 *
 */
- (void)quitGroup:(NSString *)groupId
        onSuccess:(nullable OIMSuccessCallback)onSuccess
        onFailure:(nullable OIMFailureCallback)onFailure;

/*
 * 获取已加入的群列表
 *
 */
- (void)getJoinedGroupListWithOnSuccess:(nullable OIMGroupsInfoCallback)onSuccess
                                onFailure:(nullable OIMFailureCallback)onFailure;

/*
 * 批量获取群资料
 *
 * @param gids 群ID集合
 */
- (void)getGroupsInfo:(NSArray <NSString *> *)gids
            onSuccess:(nullable OIMGroupsInfoCallback)onSuccess
            onFailure:(nullable OIMFailureCallback)onFailure;

/*
 * 设置或更新群资料
 *
 */
- (void)setGroupInfo:(NSString *)groupID
           groupInfo:(OIMGroupBaseInfo *)info
           onSuccess:(nullable OIMSuccessCallback)onSuccess
           onFailure:(nullable OIMFailureCallback)onFailure;

/*
 * 获取群成员
 *
 * @param groupId 群组ID
 * @param filter  过滤成员，0不过滤，1群的创建者，2管理员；默认值0
 * @param offset  起始偏移
 * @param count   成员个数
 */
- (void)getGroupMemberList:(NSString *)groupId
                    filter:(NSInteger)filter
                    offset:(NSInteger)offset
                     count:(NSInteger)count
                 onSuccess:(nullable OIMGroupMembersInfoCallback)onSuccess
                 onFailure:(nullable OIMFailureCallback)onFailure;

/*
 * 获取指定群成员列表
 *
 * @param groupId 群组ID
 * @param uidList 群成员ID
 * 
 **/
- (void)getGroupMembersInfo:(NSString *)groupId
                       uids:(NSArray <NSString *> *)uids
                  onSuccess:(nullable OIMGroupMembersInfoCallback)onSuccess
                  onFailure:(nullable OIMFailureCallback)onFailure;

/*
 * 踢出群
 *
 * @param groupId 群组ID
 * @param reason  说明
 * @param uidList 被要踢出群的用户id列表
 */
- (void)kickGroupMember:(NSString *)groupId
                 reason:(NSString * _Nullable)reason
                   uids:(NSArray *)uids
              onSuccess:(nullable OIMSimpleResultsCallback)onSuccess
              onFailure:(nullable OIMFailureCallback)onFailure;

/*
 * 转让群主，只有群主能操作
 *
 * @param groupId  群组ID
 * @param uid  新群主用户ID
 */
- (void)transferGroupOwner:(NSString *)groupId
                  newOwner:(NSString *)uid
                 onSuccess:(nullable OIMSuccessCallback)onSuccess
                 onFailure:(nullable OIMFailureCallback)onFailure;

/*
 * 邀请某些人进群，群里所有成员可以操作
 *
 * @param groupId 群组ID
 * @param uids 被邀请用户id列表
 * @param reason  邀请说明
 */
- (void)inviteUserToGroup:(NSString *)groupId
                   reason:(NSString *)reason
                     uids:(NSArray <NSString *> *)uids
                onSuccess:(nullable OIMSimpleResultsCallback)onSuccess
                onFailure:(nullable OIMFailureCallback)onFailure;

/*
 * 作为群主或者管理员，获取收到的群成员申请进群列表。
 *
 */
- (void)getGroupApplicationListWithOnSuccess:(nullable OIMGroupsApplicationCallback)onSuccess
                                   onFailure:(nullable OIMFailureCallback)onFailure;

/*
 * 发出的入群申请
 *
 */
- (void)getSendGroupApplicationListWithOnSuccess:(nullable OIMGroupsApplicationCallback)onSuccess
                                       onFailure:(nullable OIMFailureCallback)onFailure;

/*
 * 管理员或者群主同意某人进入某群
 *
 * @param groupId   群ID
 * @param fromUserID 申请进群的用户ID
 * @param handleMsg   处理的消息
 */
- (void)acceptGroupApplication:(NSString *)groupId
                    fromUserId:(NSString *)fromUserID
                     handleMsg:(NSString * _Nullable)handleMsg
                     onSuccess:(nullable OIMSuccessCallback)onSuccess
                     onFailure:(nullable OIMFailureCallback)onFailure;

/*
 * 管理员或者群主拒绝某人进入某群
 *
 * @param groupId   群ID
 * @param fromUserID 申请进群的用户ID
 * @param handleMsg   处理的消息
 */
- (void)refuseGroupApplication:(NSString *)groupId
                    fromUserId:(NSString *)fromUserID
                     handleMsg:(NSString * _Nullable)handleMsg
                     onSuccess:(nullable OIMSuccessCallback)onSuccess
                     onFailure:(nullable OIMFailureCallback)onFailure;

/*
 * 解散群
 *
 * @param groupId   群ID
 */
- (void)dismissGroup:(NSString *)groupID
           onSuccess:(nullable OIMSuccessCallback)onSuccess
           onFailure:(nullable OIMFailureCallback)onFailure;

/*
 *  静音或取消禁言某群成员 mutedSeconds为0时取消禁言
 */
- (void)changeGroupMemberMute:(NSString *)groupID
                       userID:(NSString *)userID
                 mutedSeconds:(NSInteger)mutedSeconds
           onSuccess:(nullable OIMSuccessCallback)onSuccess
           onFailure:(nullable OIMFailureCallback)onFailure;

/*
 *  静音或取消禁言某群
 */
- (void)changeGroupMute:(NSString *)groupID
                 isMute:(BOOL)isMute
              onSuccess:(nullable OIMSuccessCallback)onSuccess
              onFailure:(nullable OIMFailureCallback)onFailure;
@end

NS_ASSUME_NONNULL_END
