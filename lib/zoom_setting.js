import { ZoomGeneralSetting as _ZoomGeneralSetting } from "./zoom_setting_general";
import { ZoomRecordingSetting as _ZoomRecordingSetting } from "./zoom_setting_recording";
import { ZoomVideoSetting as _ZoomVideoSetting } from "./zoom_setting_video";
import { ZoomAudioSetting as _ZoomAudioSetting } from "./zoom_setting_audio";
import { ZoomShareSetting as _ZoomShareSetting } from "./zoom_setting_share";
import { ZoomSettingUICtrl as _ZoomSettingUICtrl } from "./zoom_setting_ui_ctrl";
import { ZoomSettingStatisticCtrl as _ZoomSettingStatisticCtrl } from "./zoom_setting_statistic_ctrl";
import { ZoomSettingAccessibilityCtrl as _ZoomSettingAccessibilityCtrl } from "./zoom_setting_accessibility_ctrl";
import { ZoomSDKError } from "./settings";

import pb from "./electron_sdk_pb";

let ZoomGeneralSetting;
let ZoomVideoSetting;
let ZoomAudioSetting;
let ZoomShareSetting;
let ZoomRecordingSetting;
let ZoomSettingUICtrl;
let ZoomSettingStatisticCtrl;
let ZoomSettingAccessibilityCtrl;

export const ZoomSetting = (function () {
  var instance;
  /**
   * Zoom Setting
   * @module zoom_setting
   * @return {ZoomSetting}
   */
  function init(opts) {
    var clientOpts = opts || {};

    // Private methods and variables
    var _addon = clientOpts.addon.GetSetObj() || null;
    return {
      /**
      * Display Meeting Setting dialog.
      * @method SettingUI_ShowTheSettingDlg
      * @param {String} hParent parent setting handle (require hexadecimal)
      * @param {String} left setting dlg left pos
      * @param {String} top setting dlg top pos
      * @param {String} hSettingWnd Setting Wnd (require hexadecimal)
      * @param {Boolean} bShow show or not
      * @return {Number} If the function succeed, the return value is SDKERR_SUCCESS.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      SettingUI_ShowTheSettingDlg: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          let hParent = clientOpts.hParent || "0";
          let top = clientOpts.top || "0";
          let left = clientOpts.left || "0";
          let hSettingWnd = clientOpts.hSettingWnd || "0";
          let bShow = clientOpts.bShow == undefined ? true : clientOpts.bShow;
          try {
            let ShowSettingDlgParams = new pb.ShowSettingDlgParams();
            ShowSettingDlgParams.setHparent(hParent);
            ShowSettingDlgParams.setLeft(left);
            ShowSettingDlgParams.setTop(top);
            ShowSettingDlgParams.setHsettingwnd(hSettingWnd);
            ShowSettingDlgParams.setBshow(bShow);
            let bytes = ShowSettingDlgParams.serializeBinary();
            return _addon.ShowSettingDlg(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZOOMSDKMOD_4Setting.ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      /**
       * Hide meeting setting dialog.
       * @method SettingUI_HideSettingDlg
       * @return {Number} If the function succeed, the return value is SDKERR_SUCCESS.
	      Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
      */
      SettingUI_HideSettingDlg: function () {
        if (_addon) {
          return _addon.HideSettingDlg();
        }
        return ZOOMSDKMOD_4Setting.ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      GetGeneralSetting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          if (!ZoomGeneralSetting) {
            ZoomGeneralSetting = _ZoomGeneralSetting.getInstance(clientOpts);
          }
          return ZoomGeneralSetting;
        }
        return null;
      },
      GetVideoSetting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          if (!ZoomVideoSetting) {
            ZoomVideoSetting = _ZoomVideoSetting.getInstance(clientOpts);
          }
          return ZoomVideoSetting;
        }
        return null;
      },
      GetAudioSetting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          if (!ZoomAudioSetting) {
            ZoomAudioSetting = _ZoomAudioSetting.getInstance(clientOpts);
          }
          return ZoomAudioSetting;
        }
        return null;
      },
      GetShareSetting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          if (!ZoomShareSetting) {
            ZoomShareSetting = _ZoomShareSetting.getInstance(clientOpts);
          }
          return ZoomShareSetting;
        }
        return null;
      },
      GetRecordingSetting: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          if (!ZoomRecordingSetting) {
            ZoomRecordingSetting =
              _ZoomRecordingSetting.getInstance(clientOpts);
          }
          return ZoomRecordingSetting;
        }
        return null;
      },
      GetSettingUICtrl: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          if (!ZoomSettingUICtrl) {
            ZoomSettingUICtrl = _ZoomSettingUICtrl.getInstance(clientOpts);
          }
          return ZoomSettingUICtrl;
        }
        return null;
      },
      GetSettingStatisticCtrl: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          if (!ZoomSettingStatisticCtrl) {
            ZoomSettingStatisticCtrl =
              _ZoomSettingStatisticCtrl.getInstance(clientOpts);
          }
          return ZoomSettingStatisticCtrl;
        }
        return null;
      },
      GetSettingAccessibilityCtrl: function (opts) {
        if (_addon) {
          let clientOpts = opts || {};
          clientOpts.addon = _addon;
          if (!ZoomSettingAccessibilityCtrl) {
            ZoomSettingAccessibilityCtrl =
              _ZoomSettingAccessibilityCtrl.getInstance(clientOpts);
          }
          return ZoomSettingAccessibilityCtrl;
        }
        return null;
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
