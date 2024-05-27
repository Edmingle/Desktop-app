import { contextBridge, ipcRenderer } from "electron";
import { electronAPI } from "@electron-toolkit/preload";
import os from "os";

// Custom APIs for renderer
const api = {
  getOs: () => os.platform(),
  requestRunningApps: () => ipcRenderer.send("request-running-apps"),
  onRunningAppsUpdate: (callback) =>
    ipcRenderer.on("running-apps-update", (event, data) => callback(data)),
  deeplinks: (callback) =>
    ipcRenderer.on("deep-link-data", (event, data) => {
      callback(data);
    }),
};

// Use `contextBridge` APIs to expose Electron APIs to
// renderer only if context isolation is enabled, otherwise
// just add to the DOM global.
if (process.contextIsolated) {
  try {
    contextBridge.exposeInMainWorld("electron", electronAPI);
    contextBridge.exposeInMainWorld("api", api);
  } catch (error) {
    console.error(error);
  }
} else {
  // @ts-ignore (define in dts)
  window.electron = electronAPI;
  // @ts-ignore (define in dts)
  window.api = api;
}
