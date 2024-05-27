import { ZoomSDKError } from "./settings";
import pb from "./electron_sdk_pb";

export const ZoomMeetingChat = (function () {
  var instance;
  /**
   * Zoom Meeting Chat
   * @module zoom_meeting_chat
   * @param {Function} onChatMsgNotifcation Callback event used to inform the user once received the message sent by others.
   * @param {Function} onChatStatusChangedNotification Callback event used to inform the user when the authority of chat changes in the meeting or webinar.
   * @param {Function} onChatMsgDeleteNotification Callback event used to inform the user host/myself the message be deleted.
   * @param {Function} onShareMeetingChatStatusChanged Callback event used to inform the user when share meeting chat status changed.
   * @return {ZoomMeetingChat}
   */
  function init(opts) {
    let clientOpts = opts || {};
    // Private methods and variables
    let _addon = clientOpts.addon.GetMeetingChatCtrl() || null;
    let _onChatMsgNotifcation = clientOpts.onChatMsgNotifcation || null;
    let _onChatStatusChangedNotification =
      clientOpts.onChatStatusChangedNotification || null;
    let _onChatMsgDeleteNotification =
      clientOpts.onChatMsgDeleteNotification || null;
    let _onShareMeetingChatStatusChanged =
      clientOpts.onShareMeetingChatStatusChanged || null;

    /**
      Callback event used to inform the user once received the message sent by others.
      @event onChatMsgNotifcation
      @param {Object} chatMsg Chat message object
      @param {String} content
    */
    function onChatMsgNotifcation(chatMsg, textStyleList, offsetList, content) {
      let textStyleItemList = [];
      if (textStyleList) {
        for (let i = 0; i < textStyleList.length; i++) {
          let obj = {
            textStyle: textStyleList[i],
            textStyleOffsetList: offsetList[i],
          };
          textStyleItemList.push(obj);
        }
      }
      let meeting_chat_msg = {
        messageID: chatMsg.messageID,
        senderUserId: chatMsg.senderUserId,
        senderDisplayName: chatMsg.senderDisplayName,
        receiverUserId: chatMsg.receiverUserId,
        receiverDisplayName: chatMsg.receiverDisplayName,
        content: chatMsg.content,
        timeStamp: chatMsg.timeStamp,
        isChatToAll: chatMsg.isChatToAll,
        isChatToAllPanelist: chatMsg.isChatToAllPanelist,
        isChatToWaitingroom: chatMsg.isChatToWaitingroom,
        chatMessageType: chatMsg.chatMessageType,
        isComment: chatMsg.isComment,
        isThread: chatMsg.isThread,
        textStyleItemList: textStyleItemList,
        threadID: chatMsg.threadID,
      };
      if (_onChatMsgNotifcation) {
        _onChatMsgNotifcation(meeting_chat_msg, content);
      }
    }

    /**
      Callback event used to inform the user when the authority of chat changes in the meeting or webinar.
      @event onChatStatusChangedNotification
      @param {Object} status The authority to chat in the specified meeting.
    */
    function onChatStatusChangedNotification(status) {
      if (_onChatStatusChangedNotification) {
        _onChatStatusChangedNotification(status);
      }
    }

    /**
      Callback event used to inform the user host/myself the message be deleted.
      @event onChatMsgDeleteNotification
      @param {String} msgID
      @param {Number} deleteBy chat message delete type, Defined in: {@link ChatMessageDeleteType}
    */
    function onChatMsgDeleteNotification(msgID, deleteBy) {
      if (_onChatMsgDeleteNotification) {
        _onChatMsgDeleteNotification(msgID, deleteBy);
      }
    }

    /**
      Callback event used to inform the user when share meeting chat status changed.
      @event onShareMeetingChatStatusChanged
      @param {Boolean} isStart
    */
    function onShareMeetingChatStatusChanged(isStart) {
      if (_onShareMeetingChatStatusChanged) {
        _onShareMeetingChatStatusChanged(isStart);
      }
    }

    if (_addon) {
      _addon.SetOnChatMsgNotifcationCB(onChatMsgNotifcation);
      _addon.SetOnChatStatusChangedNotificationCB(
        onChatStatusChangedNotification
      );
      _addon.SetOnChatMsgDeleteNotificationCB(onChatMsgDeleteNotification);
      _addon.SetOnShareMeetingChatStatusChangedCB(
        onShareMeetingChatStatusChanged
      );
    }

    return {
      // Public methods and variables
      /**
       * Set chat message callback.
       * @method SetOnChatMsgNotifcationCB
       * @param {Function} onChatMsgNotifcation
       * @return {Boolean}
       */
      SetOnChatMsgNotifcationCB: function (onChatMsgNotifcation) {
        if (
          _addon &&
          onChatMsgNotifcation &&
          onChatMsgNotifcation instanceof Function
        ) {
          _onChatMsgNotifcation = onChatMsgNotifcation;
          return true;
        }
        return false;
      },
      /**
       * Set the authority of chat changes callback.
       * @method SetOnChatStatusChangedNotificationCB
       * @param {Function} onChatStatusChangedNotification
       * @return {Boolean}
       */
      SetOnChatStatusChangedNotificationCB: function (
        onChatStatusChangedNotification
      ) {
        if (
          _addon &&
          onChatStatusChangedNotification &&
          onChatStatusChangedNotification instanceof Function
        ) {
          _onChatStatusChangedNotification = onChatStatusChangedNotification;
          return true;
        }
        return false;
      },
      /**
       * Set chat message be deleted callback.
       * @method SetOnChatMsgDeleteNotificationCB
       * @param {Function} onChatMsgDeleteNotification
       * @return {Boolean}
       */
      SetOnChatMsgDeleteNotificationCB: function (onChatMsgDeleteNotification) {
        if (
          _addon &&
          onChatMsgDeleteNotification &&
          onChatMsgDeleteNotification instanceof Function
        ) {
          _onChatMsgDeleteNotification = onChatMsgDeleteNotification;
          return true;
        }
        return false;
      },
      /**
       * Set share meeting chat status changed callback.
       * @method SetOnShareMeetingChatStatusChangedCB
       * @param {Function} onShareMeetingChatStatusChanged
       * @return {Boolean}
       */
      SetOnShareMeetingChatStatusChangedCB: function (
        onShareMeetingChatStatusChanged
      ) {
        if (
          _addon &&
          onShareMeetingChatStatusChanged &&
          onShareMeetingChatStatusChanged instanceof Function
        ) {
          _onShareMeetingChatStatusChanged = onShareMeetingChatStatusChanged;
          return true;
        }
        return false;
      },
      /**
      * Get the authority status to send current message. 
      * @method GetChatStatus
      * @return {Object} If the function succeeds, the return value is an object of ChatStatus.
	      Otherwise failed, the return value is null.
      */
      GetChatStatus: function () {
        if (_addon) {
          return _addon.GetChatStatus();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * Accept the chat.
      * @method SetParticipantsChatPrivilege
      * @param {Number} privilege The chat privilege of participants
      * @return {Number} If the function succeeds, the return value is SDKErr_Success.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      SetParticipantsChatPrivilege: function (opts) {
        if (_addon) {
          var clientOpts = opts || {};
          var privilege = clientOpts.privilege;
          try {
            let SetParticipantsChatPrivilegeParams =
              new pb.SetParticipantsChatPrivilegeParams();
            SetParticipantsChatPrivilegeParams.setPrivilege(privilege);
            let bytes = SetParticipantsChatPrivilegeParams.serializeBinary();
            return _addon.SetParticipantsChatPrivilege(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Determine whether the legal notice for chat is available.
       * @method IsMeetingChatLegalNoticeAvailable
       * @return {Boolean} True indicates the legal notice for chat is available. Otherwise False.
       */
      IsMeetingChatLegalNoticeAvailable: function () {
        if (_addon) {
          return _addon.IsMeetingChatLegalNoticeAvailable();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Get the chat legal notices prompt.
       * @method getChatLegalNoticesPrompt
       * @return {String}
       */
      GetChatLegalNoticesPrompt: function () {
        if (_addon) {
          return _addon.getChatLegalNoticesPrompt();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Get the chat legal notices explained.
       * @method getChatLegalNoticesExplained
       * @return {String}
       */
      GetChatLegalNoticesExplained: function () {
        if (_addon) {
          return _addon.getChatLegalNoticesExplained();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Determine whether the legal notice for sharing in meeting chat is available.
       * @method IsShareMeetingChatLegalNoticeAvailable
       * @return {Boolean} True indicates the legal notice for chat is available. Otherwise False.
       */
      IsShareMeetingChatLegalNoticeAvailable: function () {
        if (_addon) {
          return _addon.IsShareMeetingChatLegalNoticeAvailable();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Get the sharing in meeting chat started legal notices content.
       * @method GetShareMeetingChatStartedLegalNoticeContent
       * @return {String}
       */
      GetShareMeetingChatStartedLegalNoticeContent: function () {
        if (_addon) {
          return _addon.GetShareMeetingChatStartedLegalNoticeContent();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Get the sharing in meeting chat stopped legal notices content.
       * @method GetShareMeetingChatStoppedLegalNoticeContent
       * @return {String}
       */
      GetShareMeetingChatStoppedLegalNoticeContent: function () {
        if (_addon) {
          return _addon.GetShareMeetingChatStoppedLegalNoticeContent();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Determine whether the message can be delete.
       * @method IsChatMessageCanBeDeleted
       * @param {String} msgID is the message id.
       * @return {Boolean} True indicates the message can be delete. Otherwise False.
       */
      IsChatMessageCanBeDeleted: function (opts) {
        if (_addon) {
          var clientOpts = opts || {};
          var msgID = clientOpts.msgID;
          if (!msgID) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
          try {
            let ChatMessageIDParams = new pb.ChatMessageIDParams();
            ChatMessageIDParams.setMsgid(msgID);
            let bytes = ChatMessageIDParams.serializeBinary();
            return _addon.IsChatMessageCanBeDeleted(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * Delete chat message by message id.
      * @method DeleteChatMessage
      * @param {String} msgID is the message id.
      * @return {Number} If the function succeeds, the return value is SDKErr_Success.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      DeleteChatMessage: function (opts) {
        if (_addon) {
          var clientOpts = opts || {};
          var msgID = clientOpts.msgID;
          if (!msgID) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
          try {
            let ChatMessageIDParams = new _ChatMessageIDParams();
            ChatMessageIDParams.setMsgid(msgID);
            let bytes = ChatMessageIDParams.serializeBinary();
            return _addon.DeleteChatMessage(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Get all chat message id.
       * @method GetAllChatMessageID
       * @return {Array}
       */
      GetAllChatMessageID: function () {
        if (_addon) {
          return _addon.GetAllChatMessageID();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Get chat message by message ID.
       * @method GetChatMessageById
       * @param {String} msgID is the message id.
       * @return {Object}
       */
      GetChatMessageById: function (opts) {
        if (_addon) {
          var clientOpts = opts || {};
          var msgID = clientOpts.msgID;
          if (!msgID) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
          try {
            let ChatMessageIDParams = new _ChatMessageIDParams();
            ChatMessageIDParams.setMsgid(msgID);
            let bytes = ChatMessageIDParams.serializeBinary();
            let chatMessageList = _addon.GetChatMessageById(bytes),
              chatMessageObj = {};
            if (chatMessageList) {
              chatMessageObj = chatMessageList[0];
              let textStyleList = chatMessageList[1],
                offsetList = chatMessageList[2],
                textStyleItemList = [];
              for (let i = 0; i < textStyleList.length; i++) {
                let obj = {
                  textStyle: textStyleList[i],
                  textStyleOffsetList: offsetList[i],
                };
                textStyleItemList.push(obj);
              }
              chatMessageObj.textStyleItemList = textStyleItemList;
            }
            return chatMessageObj;
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * Set the chat message builder which can help construct the message entity
      * @method SetChatMessageBuilder
      * @param {String} content chat message content.
      * @param {Number} receiver who will receive the chat message.
      * @param {String} threadId the ID of the thread where the message will be posted.
      * @param {Number} type the chat message type.
      * @param {Number} positionStart the segment start position.
      * @param {Number} positionEnd the segment end position.
      * @param {Boolean} bClearStyles clear all set styles. not support for MAC platform
      * @param {Boolean} bClear clear all set properties. not support for MAC platform
      * @return {Number} If the function succeeds, the return value is SDKErr_Success.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      SetChatMessageBuilder: function (opts) {
        if (_addon) {
          var clientOpts = opts || {};
          var content = clientOpts.content;
          var receiver = clientOpts.receiver;
          var threadId = clientOpts.threadId;
          var type = clientOpts.type;
          var positionStart = clientOpts.positionStart;
          var positionEnd = clientOpts.positionEnd;
          var bClearStyles =
            clientOpts.bClearStyles === undefined
              ? false
              : clientOpts.bClearStyles;
          var bClear =
            clientOpts.bClear === undefined ? false : clientOpts.bClear;
          try {
            let SetChatMessageBuilderParams =
              new pb.SetChatMessageBuilderParams();
            SetChatMessageBuilderParams.setContent(content);
            SetChatMessageBuilderParams.setReceiver(receiver);
            SetChatMessageBuilderParams.setType(type);
            if (threadId) {
              SetChatMessageBuilderParams.setThreadid(threadId);
            }
            if (positionStart != undefined) {
              SetChatMessageBuilderParams.setPositionstart(positionStart);
            }
            if (positionEnd != undefined) {
              SetChatMessageBuilderParams.setPositionend(positionEnd);
            }
            SetChatMessageBuilderParams.setBclearstyles(bClearStyles);
            SetChatMessageBuilderParams.setBclear(bClear);
            let bytes = SetChatMessageBuilderParams.serializeBinary();
            return _addon.SetChatMessageBuilder(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * Send a chat message.
      * @method SendLastBuildChatMsgTo
      * @return {Number} If the function succeeds, the return value is SDKErr_Success.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      SendLastBuildChatMsgTo: function () {
        if (_addon) {
          return _addon.SendLastBuildChatMsgTo();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
    };
  }

  return {
    getInstance: function (opts) {
      if (!instance) {
        instance = init(opts);
      }
      return instance;
    },
  };
})();
