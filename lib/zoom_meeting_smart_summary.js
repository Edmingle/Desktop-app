import { ZoomSDKError } from "./settings";

export const ZoomMeetingSmartSummary = (function () {
  var instance;
  /**
   * Zoom Meeting Smart Summary
   * @module zoom_meeting_smart_summary
   * @param {Function} onSmartSummaryStatusChange Callback event when smart summary status changes.
   * @param {Function} onSmartSummaryPrivilegeRequested Callback event when a user requests host to start smart summary.
   * @param {Function} onSmartSummaryStartReqResponse Callback event when the host handle the smart summary request.
   * @param {Function} onEnableSmartSummary Callback event when the user need to go to web to enable the smart summary feature.
   * @return {ZoomMeetingSmartSummary}
   */
  function init(opts) {
    let clientOpts = opts || {};
    // Private methods and variables
    let _addon = clientOpts.addon.GetMeetingSmartSummaryCtrl() || null;
    let _onSmartSummaryStatusChange =
      clientOpts.onSmartSummaryStatusChange || null;
    let _onSmartSummaryPrivilegeRequested =
      clientOpts.onSmartSummaryPrivilegeRequested || null;
    let _onSmartSummaryStartReqResponse =
      clientOpts.onSmartSummaryStartReqResponse || null;
    let _onEnableSmartSummary = clientOpts.onEnableSmartSummary || null;

    /**
      Callback event when smart summary status changes.
      @event onSmartSummaryStatusChange
      @param {Boolean} isStarted true means smart summary is started, false means not.
    */
    function onSmartSummaryStatusChange(isStarted) {
      if (_onSmartSummaryStatusChange) {
        _onSmartSummaryStatusChange(isStarted);
      }
    }

    /**
      Callback event when a user requests host to start smart summary.
      @event onSmartSummaryPrivilegeRequested
      @param {Number} senderId The user who requests host to start smart summary.
    */
    function onSmartSummaryPrivilegeRequested(senderId) {
      if (_onSmartSummaryPrivilegeRequested) {
        _onSmartSummaryPrivilegeRequested(senderId);
      }
    }

    /**
      Callback event when the host handle the smart summary request.
      @event onSmartSummaryStartReqResponse
      @param {Boolean} timeout True means the host not handle the request until timeout.
      @param {Boolean} decline True means the host decline the request, false means the host agree the request.
    */
    function onSmartSummaryStartReqResponse(timeout, decline) {
      if (_onSmartSummaryStartReqResponse) {
        _onSmartSummaryStartReqResponse(timeout, decline);
      }
    }

    /**
      Callback event when the user need to go to web to enable the smart summary feature.
      The callback will only be triggered for Business account. And the smart summary feature will be enabled for the future meeting, but not enable the current meeting if the user enables the setting in web.
      @event onEnableSmartSummary
    */
    function onEnableSmartSummary() {
      if (_onEnableSmartSummary) {
        _onEnableSmartSummary();
      }
    }

    if (_addon) {
      _addon.SetOnSmartSummaryStatusChangeCB(onSmartSummaryStatusChange);
      _addon.SetOnSmartSummaryPrivilegeRequestedCB(
        onSmartSummaryPrivilegeRequested,
      );
      _addon.SetOnSmartSummaryStartReqResponseCB(
        onSmartSummaryStartReqResponse,
      );
      _addon.SetOnEnableSmartSummaryCB(onEnableSmartSummary);
    }

    return {
      // Public methods and variables
      /**
       * Set notification smart summary status changes callback.
       * @method SetOnSmartSummaryStatusChangeCB
       * @param {Function} onSmartSummaryStatusChange
       * @return {Boolean}
       */
      SetOnSmartSummaryStatusChangeCB: function (onSmartSummaryStatusChange) {
        if (
          _addon &&
          onSmartSummaryStatusChange &&
          onSmartSummaryStatusChange instanceof Function
        ) {
          _onSmartSummaryStatusChange = onSmartSummaryStatusChange;
          return true;
        }
        return false;
      },
      /**
       * Set notification user requests host to start smart summary callback.
       * @method SetOnSmartSummaryPrivilegeRequestedCB
       * @param {Function} onSmartSummaryPrivilegeRequested
       * @return {Boolean}
       */
      SetOnSmartSummaryPrivilegeRequestedCB: function (
        onSmartSummaryPrivilegeRequested,
      ) {
        if (
          _addon &&
          onSmartSummaryPrivilegeRequested &&
          onSmartSummaryPrivilegeRequested instanceof Function
        ) {
          _onSmartSummaryPrivilegeRequested = onSmartSummaryPrivilegeRequested;
          return true;
        }
        return false;
      },
      /**
       * Set host handle the smart summary request callback.
       * @method SetOnSmartSummaryStartReqResponseCB
       * @param {Function} onSmartSummaryStartReqResponse
       * @return {Boolean}
       */
      SetOnSmartSummaryStartReqResponseCB: function (
        onSmartSummaryStartReqResponse,
      ) {
        if (
          _addon &&
          onSmartSummaryStartReqResponse &&
          onSmartSummaryStartReqResponse instanceof Function
        ) {
          _onSmartSummaryStartReqResponse = onSmartSummaryStartReqResponse;
          return true;
        }
        return false;
      },
      /**
       * Set notification user need to go to web to enable the smart summary feature callback.
       * @method SetOnEnableSmartSummaryCB
       * @param {Function} onEnableSmartSummary
       * @return {Boolean}
       */
      SetOnEnableSmartSummaryCB: function (onEnableSmartSummary) {
        if (
          _addon &&
          onEnableSmartSummary &&
          onEnableSmartSummary instanceof Function
        ) {
          _onEnableSmartSummary = onEnableSmartSummary;
          return true;
        }
        return false;
      },
      /**
       * Determine if current meeting support smart summary feature.
       * @method IsSmartSummarySupported
       * @return {Boolean} True means the current meeting support smart summary feature, False means not supported.
       */
      IsSmartSummarySupported: function () {
        if (_addon) {
          return _addon.IsSmartSummarySupported();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Determine if smart summary feature is enabled in the meeting.
       * @method IsSmartSummaryEnabled
       * @return {Boolean} True means smart summary feature is enabled.
       */
      IsSmartSummaryEnabled: function () {
        if (_addon) {
          return _addon.IsSmartSummaryEnabled();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * Whether the current user can enable the smart summary feature for the account.
      * @method CanEnableSmartSummaryFeature
      * @return {Number} If the function succeeds, the return value is SDKErr_Success.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      CanEnableSmartSummaryFeature: function () {
        if (_addon) {
          return _addon.CanEnableSmartSummaryFeature();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * Enable the smart summary feature for the account.
      * @method EnableSmartSummaryFeature
      * @return {Number} If the function succeeds, the return value is SDKErr_Success.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      EnableSmartSummaryFeature: function () {
        if (_addon) {
          return _addon.EnableSmartSummaryFeature();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * Whether the current user is able to start smart summary.
      * @method CanStartSmartSummary
      * @return {Number} If the function succeeds, the return value is SDKErr_Success.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      CanStartSmartSummary: function () {
        if (_addon) {
          return _addon.CanStartSmartSummary();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * Start smart summary.
      * @method StartSmartSummary
      * @return {Number} If the function succeeds, the return value is SDKErr_Success.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      StartSmartSummary: function () {
        if (_addon) {
          return _addon.StartSmartSummary();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * Stop smart summary.
      * @method StopSmartSummary
      * @return {Number} If the function succeeds, the return value is SDKErr_Success.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      StopSmartSummary: function () {
        if (_addon) {
          return _addon.StopSmartSummary();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Query whether smart summary is started.
       * @method IsSmartSummaryStarted
       * @return {Boolean} True means smart summary is started, false means not.
       */
      IsSmartSummaryStarted: function () {
        if (_addon) {
          return _addon.IsSmartSummaryStarted();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * Whether the current user can request the admin to enable the smart summary feature for the account.
      * @method CanRequestEnableSmartSummaryFeature
      * @return {Number} If the function succeeds, the return value is SDKErr_Success.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      CanRequestEnableSmartSummaryFeature: function () {
        if (_addon) {
          return _addon.CanRequestEnableSmartSummaryFeature();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * Request the admin to enable the smart summary feature for the account.
      * @method RequestEnableSmartSummaryFeature
      * @return {Number} If the function succeeds, the return value is SDKErr_Success.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      RequestEnableSmartSummaryFeature: function () {
        if (_addon) {
          return _addon.RequestEnableSmartSummaryFeature();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * Whether the current user can request host to start the smart summary for the current meeting.
      * @method CanRequestStartSmartSummary
      * @return {Number} If the function succeeds, the return value is SDKErr_Success.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      CanRequestStartSmartSummary: function () {
        if (_addon) {
          return _addon.CanRequestStartSmartSummary();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * Request the host to start the smart summary for the current meeting.
      * @method RequestStartSmartSummary
      * @return {Number} If the function succeeds, the return value is SDKErr_Success.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      RequestStartSmartSummary: function () {
        if (_addon) {
          return _addon.RequestStartSmartSummary();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * Agree the start smart summary request.
      * @method Accept
      * @return {Number} If the function succeed, the return value is SDKERR_SUCCESS.
        Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      Accept: function () {
        if (_addon) {
          return _addon.Accept();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * Decline the start smart summary request.
      * @method Decline
      * @return {Number} If the function succeed, the return value is SDKERR_SUCCESS.
        Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      Decline: function () {
        if (_addon) {
          return _addon.Decline();
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
      * Ignore the start smart summary request.
      * @method Ignore
      * @return {Number} If the function succeed, the return value is SDKERR_SUCCESS.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      Ignore: function () {
        if (_addon) {
          return _addon.Ignore();
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
