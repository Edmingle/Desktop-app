const { contextBridge, ipcRenderer } = require("electron");
const os = require("os");

contextBridge.exposeInMainWorld("api", {
  getOs: () => os.platform(),
  // updatedMessage: (callback) => ipcRenderer.on('updatedMessage', (event, data) => 
  //   callback(data)
  // ),
  requestRunningApps: () => ipcRenderer.send("request-running-apps"),
  // checkForUpdate: () => ipcRenderer.send("check-for-update"),
  onRunningAppsUpdate: (callback) =>
    ipcRenderer.on("running-apps-update", (event, data) => callback(data)),
  deeplinks: (callback) =>
    ipcRenderer.on("deep-link-data", (event, data) => {
      callback(data);
    }),
});
