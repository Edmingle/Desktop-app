import {
  ZoomSDK_LANGUAGE_ID,
  ZoomSDKError,
  CustomizedLanguageType,
  ZoomAPPLocale,
  ZoomSDKVideoRenderMode,
  SDKRawDataMemoryMode,
  ZoomSDKVideoCaptureMethod,
  ZoomSDKRenderPostProcessing,
} from "./settings";
import { ZoomAuth } from "./zoom_auth";
import { ZoomMeeting } from "./zoom_meeting";
import { ZoomSetting } from "./zoom_setting";
import { ZoomCustomizedResource } from "./zoom_customized_resource";
import { ZoomRawData } from "./zoom_rawdata";
import { ZoomSMSHelper } from "./zoom_sms_helper";

import pb from "./electron_sdk_pb";

const { platform, arch } = process;

export const ZoomSDK = (() => {
  let instance;
  /**
   * Zoom Electron Sdk
   * @module zoom_electron_sdk
   * @param {String} path zoomsdk.node path on win os or mac os
   * @return {ZoomSDK}
   */
  function init(opts) {
    // Private methods and variables
    let clientOpts = opts || {};
    let nativeSdkPath, addon;
    try {
      switch (`${platform}:${arch}`) {
        case "darwin:x64":
        case "darwin:arm64":
          nativeSdkPath = "sdk/mac";
          break;
        case "win32:ia32":
          nativeSdkPath = "sdk/win32";
          break;
        case "win32:x64":
          nativeSdkPath = "sdk/win64";
          break;
      }
      require(`../../${nativeSdkPath}/zoomsdk_napi_util.node`);
      addon = require(`../../${nativeSdkPath}/zoomsdk.node`).exports();
    } catch (error) {
      console.log(error);
    }
    let _isSDKInitialized = false;

    return {
      // Public methods and variables
      /**
       * Initialize Zoom SDK.
       * @method InitSDK
       * @param {String} path [Required] sdk.dll path on win os or mac os.
       * @param {String} domain [Required]
       * @param {String} langname [Optional]
       * @param {String} langinfo [Optional]
       * @param {Number} langtype [Optional] CustomizedLanguageType
       * @param {String} strSupportUrl [Optional]
       * @param {Number} langid [Optional] ZoomSDK_LANGUAGE_ID,
       * @param {Boolean} enable_log [Optional]
       * @param {Number} locale [Optional] see ZoomAPPLocale in setings.js
       * @param {Number} logfilesize [Optional] Size of a log file in M(megabyte). The default size is 5M. There are 5 log files in total and the file size varies from 1M to 50M.
       * @param {Boolean} enableGenerateDump [Optional]
       * @param {Boolean} permonitorAwarenessMode [Optional]
       * @param {Number} videoRenderMode [Optional]
       * @param {Number} videoRawdataMemoryMode [Optional]
       * @param {Number} shareRawdataMemoryMode [Optional]
       * @param {Number} audioRawdataMemoryMode [Optional]
       * @param {Boolean} enableRawdataIntermediateMode [Optional]
       * @param {Number} renderPostProcessing [Optional]
       * @param {Number} videoCaptureMethod [Optional]
       * @param {String} customLocalizationFilePath [Optional] Set custom localizable string file path. only support for MAC platform
       * @param {Number} useCustomUI [Optional] whether to use the custom UI mode
       * @param {Number} strBrandingName [Optional] Branding name
       * @return {Number} If the function succeed, the return value is SDKERR_SUCCESS.
	        Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
       */
      InitSDK: function (opts) {
        let clientOpts = opts || {};
        let path = clientOpts.path || "../../sdk/win64/sdk.dll";
        let domain = clientOpts.domain || "https://www.zoom.us";
        let langname = clientOpts.langname || "";
        let langinfo = clientOpts.langinfo || "";
        let langtype =
          Number(clientOpts.langtype) ||
          CustomizedLanguageType.CustomizedLanguage_None;
        let strSupportUrl = clientOpts.strSupportUrl || "https://zoom.us";
        let langid = clientOpts.langid || ZoomSDK_LANGUAGE_ID.LANGUAGE_English;
        let enable_log =
          clientOpts.enable_log == undefined ? true : clientOpts.enable_log;
        let locale =
          Number(clientOpts.locale) || ZoomAPPLocale.SDK_APP_Locale_Default;
        let logfilesize = Number(clientOpts.logfilesize) || 5;
        let enableGenerateDump =
          clientOpts.enableGenerateDump == undefined
            ? false
            : clientOpts.enableGenerateDump;
        let permonitorAwarenessMode =
          clientOpts.permonitorAwarenessMode == undefined
            ? true
            : clientOpts.permonitorAwarenessMode;
        let videoRenderMode =
          clientOpts.videoRenderMode ||
          ZoomSDKVideoRenderMode.SDKVideoRenderMode_None;
        let videoRawdataMemoryMode =
          clientOpts.videoRawdataMemoryMode ||
          SDKRawDataMemoryMode.SDKRawDataMemoryModeStack;
        let shareRawdataMemoryMode =
          clientOpts.shareRawdataMemoryMode ||
          SDKRawDataMemoryMode.SDKRawDataMemoryModeStack;
        let audioRawdataMemoryMode =
          clientOpts.audioRawdataMemoryMode ||
          SDKRawDataMemoryMode.SDKRawDataMemoryModeStack;
        let enableRawdataIntermediateMode =
          clientOpts.enableRawdataIntermediateMode || platform == "darwin"
            ? false
            : true;
        let renderPostProcessing =
          clientOpts.renderPostProcessing ||
          ZoomSDKVideoCaptureMethod.ZoomSDKVideoCaptureMethod_Auto;
        let videoCaptureMethod =
          clientOpts.videoCaptureMethod ||
          ZoomSDKRenderPostProcessing.ZoomSDKRenderPostProcessing_Auto;
        let customLocalizationFilePath = clientOpts.customLocalizationFilePath;
        let useCustomUI = clientOpts.useCustomUI || false;
        let strBrandingName = clientOpts.strBrandingName;
        if (platform == "darwin" && customLocalizationFilePath) {
          langid = ZoomSDK_LANGUAGE_ID.LANGUAGE_Unknow;
        }
        try {
          let InitSDKParams = new pb.InitSDKParams();
          InitSDKParams.setPath(path);
          InitSDKParams.setDomain(domain);
          InitSDKParams.setCustomizedlanguagename(langname);
          InitSDKParams.setCustomizedlanguageinfo(langinfo);
          InitSDKParams.setCustomizedlanguagetype(langtype);
          InitSDKParams.setStrsupporturl(strSupportUrl);
          InitSDKParams.setLangid(langid);
          InitSDKParams.setEnablelog(enable_log);
          InitSDKParams.setApplocale(locale);
          InitSDKParams.setLogfilesize(logfilesize);
          InitSDKParams.setEnablegeneraldump(enableGenerateDump);
          InitSDKParams.setPermonitorawarenessmode(permonitorAwarenessMode);
          InitSDKParams.setVideorendermode(videoRenderMode);
          InitSDKParams.setVideorawdatamemorymode(videoRawdataMemoryMode);
          InitSDKParams.setSharerawdatamemorymode(shareRawdataMemoryMode);
          InitSDKParams.setAudiorawdatamemorymode(audioRawdataMemoryMode);
          InitSDKParams.setEnablerawdataintermediatemode(
            enableRawdataIntermediateMode
          );
          InitSDKParams.setRenderpostprocessing(renderPostProcessing);
          InitSDKParams.setVideocapturemethod(videoCaptureMethod);
          InitSDKParams.setCustomlocalizationfilepath(
            customLocalizationFilePath
          );
          InitSDKParams.setUsecustomui(useCustomUI);
          InitSDKParams.setStrbrandingname(strBrandingName);
          let bytes = InitSDKParams.serializeBinary();
          let ret = addon.InitSDK(bytes);
          if (ZoomSDKError.SDKERR_SUCCESS == ret) {
            _isSDKInitialized = true;
          } else {
            _isSDKInitialized = false;
          }
          return ret;
        } catch (error) {
          return ZoomSDKError.SDKERR_INVALID_PARAMETER;
        }
      },
      /**
       * Get the version of Zoom SDK
       * @method GetZoomSDKVersion
       * @return {String} The version of Zoom SDK
       */
      GetZoomSDKVersion: () => {
        return addon.GetZoomSDKVersion();
      },
      /**
       * Clean up Zoom SDK.
       * @method CleanUPSDK
       * @return {Number} If the function succeed, the return value is SDKERR_SUCCESS.
	        Otherwise failed. To get extended error information, Defined in: {@link ZoomSDKError}
       */
      CleanUPSDK: function () {
        return addon.CleanUPSDK();
      },
      /**
       * Set Support Dark Mode, only for MAC platform, this interface is deprecated.
       * @method SetSupportDarkMode
       * @param {Boolean} support
       * @return {Number} Defined in: {@link ZoomSDKError}
       */
      SetSupportDarkMode: function (opts) {
        if (addon) {
          if (platform != "darwin") {
            return ZoomSDKError.SDKERR_SETTING_OS_DONT_SUPPORT;
          }
          let clientOpts = opts || {};
          let support = clientOpts.support;
          try {
            let SetSupportDarkModeParams = new pb.SetSupportDarkModeParams();
            SetSupportDarkModeParams.setSupport(support);
            let bytes = SetSupportDarkModeParams.serializeBinary();
            return addon.SetSupportDarkMode(bytes);
          } catch (error) {
            return ZoomSDKError.SDKERR_INVALID_PARAMETER;
          }
        }
        return ZoomSDKError.SDKERR_UNINITIALIZE;
      },
      GetAuth: (opts) => {
        if (_isSDKInitialized) {
          let clientOpts = opts || {};
          clientOpts.addon = addon;
          return ZoomAuth.getInstance(clientOpts);
        }
        return null;
      },
      GetMeeting: (opts) => {
        if (_isSDKInitialized) {
          let clientOpts = opts || {};
          clientOpts.addon = addon;
          return ZoomMeeting.getInstance(clientOpts);
        }
        return null;
      },
      GetSetting: (opts) => {
        if (_isSDKInitialized) {
          let clientOpts = opts || {};
          clientOpts.addon = addon;
          return ZoomSetting.getInstance(clientOpts);
        }
        return null;
      },
      GetCustomizedResource: (opts) => {
        let clientOpts = opts || {};
        clientOpts.addon = addon;
        return ZoomCustomizedResource.getInstance(clientOpts);
      },
      RawData: (opts) => {
        if (_isSDKInitialized) {
          let clientOpts = opts || {};
          clientOpts.addon = addon;
          return ZoomRawData.getInstance(clientOpts);
        }
        return null;
      },
      SMSHelper: (opts) => {
        if (_isSDKInitialized) {
          let clientOpts = opts || {};
          clientOpts.addon = addon;
          return ZoomSMSHelper.getInstance(clientOpts);
        }
        return null;
      },
    };
  }

  return {
    getInstance: (opts) => {
      if (!instance) {
        instance = init(opts);
      }
      return instance;
    },
  };
})();
