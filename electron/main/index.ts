import { app, shell, BrowserWindow, ipcMain } from "electron";
import {
  initialize,
  enable as remoteEnable,
} from "@electron/remote/main/index.js";
import { join } from "path";
import { optimizer, is } from "@electron-toolkit/utils";

import { ZoomSDK } from "../../lib/zoom_sdk";
import icon from "../../resources/icon.png?asset";
import { ZoomSDKError } from "../../lib/settings";
import { checkScreenCaptureTools } from "./screen-capture";

const { platform, arch } = process;
const isDevelopment = process.env.NODE_ENV !== "production";

const getResultDesc = (
  api: string,
  value: any,
  compare = (a: number, b: number) => a == b
) => {
  const result = Object.keys(ZoomSDKError).find((k) =>
    compare(ZoomSDKError[k], value)
  );
  const tip = `${api}: ${result}`;
  if (value != ZoomSDKError.SDKERR_SUCCESS) {
    console.error(tip);
  }
  return result;
};

initialize();

const zoomSdk = ZoomSDK.getInstance();
(app as any).zoomSdk = zoomSdk;
const initPayload = zoomSdk.InitSDK();
const ret = getResultDesc("InitSDK", initPayload);
if (ret == "SDKERR_SUCCESS") {
  (app as any).zoomSdkModule = {
    Auth: zoomSdk.GetAuth(),
    Meeting: zoomSdk.GetMeeting(),
    Setting: zoomSdk.GetSetting(),
  };
}

(app as any).platform = platform;
(app as any).arch = arch;

// https://gist.github.com/fdlmdark/134dc069d09354bd808224ed9991c40c
(app as any).commandLine.appendSwitch(
  "disable-features",
  "IOSurfaceCapturer,DesktopCaptureMacV2"
);

let mainWindow: BrowserWindow;

if (platform === "win32") {
  const gotTheLock = app.requestSingleInstanceLock();
  if (!gotTheLock) {
    app.quit();
  } else {
    app.on("second-instance", () => {
      // Someone tried to run a second instance, we should focus our window.
      if (mainWindow) {
        if (mainWindow.isMinimized()) mainWindow.restore();
        mainWindow.focus();
      }
    });
  }
}

function createWindow(): void {
  // Create the browser window.
  mainWindow = new BrowserWindow({
    title: "Aldine CA",
    height: 600,
    width: 1000,
    fullscreen: true,
    minimizable: true,
    center: true,
    hasShadow: true,
    icon,
    webPreferences: {
      contextIsolation: false,
      nodeIntegration: true,
      devTools: true,
      preload: join(__dirname, "../preload/index.cjs"),
      sandbox: false,
    },
  });

  mainWindow.setContentProtection(false);
  // mainWindow.webContents.openDevTools();

  mainWindow.on("ready-to-show", () => {
    mainWindow.show();
  });

  mainWindow.on("minimize", (e) => {
    e.preventDefault();
    mainWindow.webContents.send("on-window-minimize");
  });

  mainWindow.webContents.setWindowOpenHandler((details) => {
    shell.openExternal(details.url);
    return { action: "deny" };
  });

  // HMR for renderer base on electron-vite cli.
  // Load the remote URL for development or the local html file for production.
  if (is.dev && process.env["ELECTRON_RENDERER_URL"]) {
    mainWindow.loadURL(process.env["ELECTRON_RENDERER_URL"]);
  } else {
    mainWindow.loadFile(join(__dirname, "../renderer/index.html"));
  }

  mainWindow.on("close", () => {
    const zoomSdkModule = (app as any).zoomSdkModule;
    if (zoomSdkModule) {
      zoomSdkModule.Meeting.LeaveMeeting();
    }
  });

  (app as any).browserWindow = BrowserWindow.getAllWindows();
}

(global as any).platform = platform;

app.on("will-quit", () => {
  if (process.platform !== "darwin") {
    app.quit();
  }
});

app.on("browser-window-created", (_e, win) => {
  win.center();
});

app.on("web-contents-created", (_e, webContents) => {
  remoteEnable(webContents);
});

app.dock.setIcon(icon);
app.whenReady().then(() => {
  // Default open or close DevTools by F12 in development
  // and ignore CommandOrControl + R in production.
  // see https://github.com/alex8088/electron-toolkit/tree/master/packages/utils
  app.on("browser-window-created", (_, window) => {
    optimizer.watchWindowShortcuts(window);
  });

  createWindow();

  app.on("activate", function () {
    // On macOS it's common to re-create a window in the app when the
    // dock icon is clicked and there are no other windows open.
    if (BrowserWindow.getAllWindows().length === 0) createWindow();
  });
});

async function getRunningApps(win: Electron.WebContents) {
  const res = await checkScreenCaptureTools();
  win.send("running-apps-update", res);
}

ipcMain.on("request-running-apps", async (event) => {
  await getRunningApps(event.sender);
});

// Quit when all windows are closed, except on macOS. There, it's common
// for applications and their menu bar to stay active until the user quits
// explicitly with Cmd + Q.
app.on("window-all-closed", () => {
  if (process.platform !== "darwin") {
    app.quit();
  }
});

if (isDevelopment) {
  if (process.platform === "win32") {
    process.on("message", (data) => {
      if (data === "graceful-exit") {
        app.quit();
      }
    });
  } else {
    process.on("SIGTERM", () => {
      app.quit();
    });
  }
}
