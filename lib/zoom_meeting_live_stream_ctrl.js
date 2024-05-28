import { ZoomSDKError } from "./settings";
import pb from "./electron_sdk_pb";

export const ZoomMeetingLiveStreamCtrl = (function () {
  let instance;
  /**
   * Zoom Meeting Live Stream Ctrl
   * @module zoom_meeting_live_stream_ctrl
   * @return {ZoomMeetingLiveStreamCtrl}
   */
  function init(opts) {
    let clientOpts = opts || {};

    // Private methods and variables
    let _addon = clientOpts.addon.GetMeetingLiveStreamCtrl() || null;
    let _onLiveStreamStatusChange = clientOpts.onLiveStreamStatusChange || null;
    let _onRawLiveStreamPrivilegeChanged =
      clientOpts.onRawLiveStreamPrivilegeChanged || null;
    let _onUserRawLiveStreamPrivilegeChanged =
      clientOpts.onUserRawLiveStreamPrivilegeChanged || null;
    let _onRawLiveStreamPrivilegeRequested =
      clientOpts.onRawLiveStreamPrivilegeRequested || null;
    let _onUserRawLiveStreamingStatusChanged =
      clientOpts.onUserRawLiveStreamingStatusChanged || null;
    let _onRawLiveStreamPrivilegeRequestTimeout =
      clientOpts.onRawLiveStreamPrivilegeRequestTimeout || null;

    /**
      The callback of liveStreamStatusChange.
      @event onLiveStreamStatusChange
      @param {String} status
    */
    function onLiveStreamStatusChange(status) {
      if (_onLiveStreamStatusChange) {
        _onLiveStreamStatusChange(status);
      }
    }

    /**
      The callback of rawLiveStreamPrivilegeChanged.
      @event onRawLiveStreamPrivilegeChanged
      @param {Boolean} hasPrivilege
    */
    function onRawLiveStreamPrivilegeChanged(hasPrivilege) {
      if (_onRawLiveStreamPrivilegeChanged) {
        _onRawLiveStreamPrivilegeChanged(hasPrivilege);
      }
    }

    /**
      The callback of userRawLiveStreamPrivilegeChanged.
      @event onUserRawLiveStreamPrivilegeChanged
      @param {Number} userid
      @param {Boolean} hasPrivilege
    */
    function onUserRawLiveStreamPrivilegeChanged(userid, hasPrivilege) {
      if (_onUserRawLiveStreamPrivilegeChanged) {
        _onUserRawLiveStreamPrivilegeChanged(userid, hasPrivilege);
      }
    }

    /**
      The callback of rawLiveStreamPrivilegeRequested.
      @event onRawLiveStreamPrivilegeRequested
    */
    function onRawLiveStreamPrivilegeRequested() {
      if (_onRawLiveStreamPrivilegeRequested) {
        _onRawLiveStreamPrivilegeRequested();
      }
    }

    /**
      The callback of userRawLiveStreamingStatusChanged.
      @event onUserRawLiveStreamingStatusChanged
      @param {Array} livingList contains object with broadcastUrl and userId
    */
    function onUserRawLiveStreamingStatusChanged(livingList) {
      if (_onUserRawLiveStreamingStatusChanged) {
        _onUserRawLiveStreamingStatusChanged(livingList);
      }
    }

    /**
      The callback of rawLiveStreamPrivilegeRequestTimeout.
      @event onRawLiveStreamPrivilegeRequestTimeout
    */
    function onRawLiveStreamPrivilegeRequestTimeout() {
      if (_onRawLiveStreamPrivilegeRequestTimeout) {
        _onRawLiveStreamPrivilegeRequestTimeout();
      }
    }

    if (_addon) {
      _addon.SetOnLiveStreamStatusChangeCB(onLiveStreamStatusChange);
      _addon.SetOnRawLiveStreamPrivilegeChangedCB(
        onRawLiveStreamPrivilegeChanged,
      );
      _addon.SetOnUserRawLiveStreamPrivilegeChangedCB(
        onUserRawLiveStreamPrivilegeChanged,
      );
      _addon.SetOnRawLiveStreamPrivilegeRequestedCB(
        onRawLiveStreamPrivilegeRequested,
      );
      _addon.SetOnUserRawLiveStreamingStatusChangedCB(
        onUserRawLiveStreamingStatusChanged,
      );
      _addon.SetOnRawLiveStreamPrivilegeRequestTimeoutCB(
        onRawLiveStreamPrivilegeRequestTimeout,
      );
    }

    return {
      /**
       * Set the callback of live stream status change.
       * @method SetOnLiveStreamStatusChangeCB
       * @param {Function} onLiveStreamStatusChange
       * @return {Boolean}
       */
      SetOnLiveStreamStatusChangeCB: function (onLiveStreamStatusChange) {
        if (
          _addon &&
          onLiveStreamStatusChange &&
          onLiveStreamStatusChange instanceof Function
        ) {
          _onLiveStreamStatusChange = onLiveStreamStatusChange;
          return true;
        }
        return false;
      },
      /**
       * Set the callback of raw live stream privilege changed.
       * @method SetOnRawLiveStreamPrivilegeChangedCB
       * @param {Function} onRawLiveStreamPrivilegeChanged
       * @return {Boolean}
       */
      SetOnRawLiveStreamPrivilegeChangedCB: function (
        onRawLiveStreamPrivilegeChanged,
      ) {
        if (
          _addon &&
          onRawLiveStreamPrivilegeChanged &&
          onRawLiveStreamPrivilegeChanged instanceof Function
        ) {
          _onRawLiveStreamPrivilegeChanged = onRawLiveStreamPrivilegeChanged;
          return true;
        }
        return false;
      },
      /**
       * Set the callback of user raw live stream privilege changed.
       * @method SetOnUserRawLiveStreamPrivilegeChangedCB
       * @param {Function} onUserRawLiveStreamPrivilegeChanged
       * @return {Boolean}
       */
      SetOnUserRawLiveStreamPrivilegeChangedCB: function (
        onUserRawLiveStreamPrivilegeChanged,
      ) {
        if (
          _addon &&
          onUserRawLiveStreamPrivilegeChanged &&
          onUserRawLiveStreamPrivilegeChanged instanceof Function
        ) {
          _onRawLiveStreamPrivilegeChanged =
            onUserRawLiveStreamPrivilegeChanged;
          return true;
        }
        return false;
      },
      /**
       * Set the callback of raw live stream privilege requested.
       * @method SetOnRawLiveStreamPrivilegeRequestedCB
       * @param {Function} onRawLiveStreamPrivilegeRequested
       * @return {Boolean}
       */
      SetOnRawLiveStreamPrivilegeRequestedCB: function (
        onRawLiveStreamPrivilegeRequested,
      ) {
        if (
          _addon &&
          onRawLiveStreamPrivilegeRequested &&
          onRawLiveStreamPrivilegeRequested instanceof Function
        ) {
          _onRawLiveStreamPrivilegeRequested =
            onRawLiveStreamPrivilegeRequested;
          return true;
        }
        return false;
      },
      /**
       * Set the callback of user raw live streaming status changed.
       * @method SetOnUserRawLiveStreamingStatusChangedCB
       * @param {Function} onUserRawLiveStreamingStatusChanged
       * @return {Boolean}
       */
      SetOnUserRawLiveStreamingStatusChangedCB: function (
        onUserRawLiveStreamingStatusChanged,
      ) {
        if (
          _addon &&
          onUserRawLiveStreamingStatusChanged &&
          onUserRawLiveStreamingStatusChanged instanceof Function
        ) {
          _onUserRawLiveStreamingStatusChanged =
            onUserRawLiveStreamingStatusChanged;
          return true;
        }
        return false;
      },
      /**
       * Set the callback of raw live stream privilege request timeout.
       * @method SetOnRawLiveStreamPrivilegeRequestTimeoutCB
       * @param {Function} onRawLiveStreamPrivilegeRequestTimeout
       * @return {Boolean}
       */
      SetOnRawLiveStreamPrivilegeRequestTimeoutCB: function (
        onRawLiveStreamPrivilegeRequestTimeout,
      ) {
        if (
          _addon &&
          onRawLiveStreamPrivilegeRequestTimeout &&
          onRawLiveStreamPrivilegeRequestTimeout instanceof Function
        ) {
          _onRawLiveStreamPrivilegeRequestTimeout =
            onRawLiveStreamPrivilegeRequestTimeout;
          return true;
        }
        return false;
      },
      /** 
      * Determine if it is able to start live streaming.
      * @method CanStartLiveStream
      * @return {Number} If it is enabled to start the live streaming, the return value is SDKERR_SUCCESS.
        Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      CanStartLiveStream: function () {
        if (_addon) {
          return _addon.CanStartLiveStream();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * Start live streaming.
      * @method StartLiveStream
      * @param {Number} liveStreamHandle the handle of live stream item
      * @return {Number} If the function succeed, the return value is SDKERR_SUCCESS.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      StartLiveStream: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let liveStreamHandle = clientOpts.liveStreamHandle;
          if (!liveStreamHandle) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
          try {
            let StartLiveStreamParams = new pb.StartLiveStreamParams();
            StartLiveStreamParams.setLivestreamhandle(Number(liveStreamHandle));
            let bytes = StartLiveStreamParams.serializeBinary();
            return _addon.StartLiveStream(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * Start live streaming. Get the parameters from the third party of live stream service
      * @method StartLiveStreamWithSteamingURL
      * @param {String} streamingURL The URL of live streaming.
      * @param {String} streamingKey The key of live streaming. 
      * @param {String} broadcastURL The broadcast URL of live-stream.
      * @return {Number} If the function succeed, the return value is SDKERR_SUCCESS.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      StartLiveStreamWithSteamingURL: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let streamingURL = clientOpts.streamingURL;
          let streamingKey = clientOpts.streamingKey;
          let broadcastURL = clientOpts.broadcastURL;
          try {
            let StartLiveStreamWithSteamingURLParams =
              new pb.StartLiveStreamWithSteamingURLParams();
            StartLiveStreamWithSteamingURLParams.setStreamingurl(streamingURL);
            StartLiveStreamWithSteamingURLParams.setStreamingkey(streamingKey);
            StartLiveStreamWithSteamingURLParams.setBroadcasturl(broadcastURL);
            let bytes = StartLiveStreamWithSteamingURLParams.serializeBinary();
            return _addon.StartLiveStreamWithSteamingURL(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * Stop live streaming.
      * @method StopLiveStream
      * @return {Number} If the function succeed, the return value is SDKERR_SUCCESS.
        Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      StopLiveStream: function () {
        if (_addon) {
          return _addon.StopLiveStream();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * Get the list of URL and associated information used by live streaming in the current meeting. 
      * @method GetSupportLiveStreamItems
      * @return {Array} If the function succeeds, the return value is the meeting information to be live streamed.
        Otherwise failed, the return value is NULL
      */
      GetSupportLiveStreamItems: function () {
        if (_addon) {
          return _addon.GetSupportLiveStreamItems();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * Get live stream status of current meeting.
      * @method GetCurrentLiveStreamStatus
      * @return {Number} If the function succeeds, the return value is the live stream status of current meeting.  
	      Otherwise failed. For more details, see {@link LiveStreamStatus}.
      */
      GetCurrentLiveStreamStatus: function () {
        if (_addon) {
          return _addon.GetCurrentLiveStreamStatus();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * Stop raw live streaming.
      * @method StopRawLiveStream
      * @return {Number} If the function succeed, the return value is SDKERR_SUCCESS.
        Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      StopRawLiveStream: function () {
        if (_addon) {
          return _addon.StopRawLiveStream();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * get the live stream item info.
      * @method GetLiveStreamItemInfo
      * @param {Number} liveStreamHandle the handle of live stream
      * @return {Number} If the function succeed, the return value is SDKERR_SUCCESS.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      GetLiveStreamItemInfo: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let liveStreamHandle = clientOpts.liveStreamHandle;
          if (!liveStreamHandle) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
          try {
            let GetLiveStreamItemInfoParams =
              new pb.GetLiveStreamItemInfoParams();
            GetLiveStreamItemInfoParams.setLivestreamhandle(
              Number(liveStreamHandle),
            );
            let bytes = GetLiveStreamItemInfoParams.serializeBinary();
            return _addon.GetLiveStreamItemInfo(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Query Whether the meeting supports raw live streams.
       * @method IsRawLiveStreamSupported
       * @return {Boolean} true if supported, false if not supported.
       */
      IsRawLiveStreamSupported: function () {
        if (_addon) {
          return _addon.IsRawLiveStreamSupported();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * Whether if the current user is able to start raw live streaming.
      * @method CanStartRawLiveStream
      * @return {Number} If the current user is able to start raw live streaming, the return value is SDKErr_Success.
	      Otherwise it fails,and returns NULL. To get extended error information, see {@link ZoomSDKError}.
      */
      CanStartRawLiveStream: function () {
        if (_addon) {
          return _addon.CanStartRawLiveStream();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /** 
      * Remove the raw live stream privilege.
      * @method RemoveRawLiveStreamPrivilege
      * @param {Number} userID Specify the ID of the user whose privilege will be removed.
      * @return {Number} If the function succeeds, the return value is SDKErr_Success. Otherwise it fails.
        To get extended error information, see {@link ZoomSDKError}.
      */
      RemoveRawLiveStreamPrivilege: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          let userID = clientOpts.userID;
          if (!userID) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
          try {
            let RemoveRawLiveStreamPrivilegeParams =
              new pb.RemoveRawLiveStreamPrivilegeParams();
            RemoveRawLiveStreamPrivilegeParams.setUserid(Number(userID));
            let bytes = RemoveRawLiveStreamPrivilegeParams.serializeBinary();
            return _addon.RemoveRawLiveStreamPrivilege(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Get a list of current active raw live streams.
       * @method GetRawLiveStreamingInfoList
       * @return {Array} If the function succeeds, the return value is a list of current active raw live streams.
       */
      GetRawLiveStreamingInfoList: function () {
        if (_addon) {
          return _addon.GetRawLiveStreamingInfoList();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Get the list of users'IDs who have raw live stream privileges.
       * @method GetRawLiveStreamPrivilegeUserList
       * @return {Array} If the function succeeds, the return value is a list of users'IDs who have raw live stream privileges.
       */
      GetRawLiveStreamPrivilegeUserList: function () {
        if (_addon) {
          return _addon.GetRawLiveStreamPrivilegeUserList();
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
