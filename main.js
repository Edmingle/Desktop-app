const { app, BrowserWindow, ipcMain } = require("electron");
const path = require("path");
const url = require("url");
const { exec } = require("child_process");
// const {autoUpdater, AppUpdater} = require('electron-updater');

// autoUpdater.autoDownload = false;
// autoUpdater.autoInstallOnAppQuit = true;

const createMainWindow = () => {
  const mainWindow = new BrowserWindow({
    title: "Aldine CA",
    height: 600,
    width: 1000,
    fullscreen: true,
    icon: path.join(__dirname, "./my-app/assets/images/aldineLogo.png"),
    webPreferences: {
      contextIsolation: true,
      nodeIntegration: true,
      devTools:false,
      preload: path.join(__dirname, "preload.js"),
    },
  });
  mainWindow.setContentProtection(true);
  // mainWindow.webContents.openDevTools();
  // showMessage("checking for updated..!!", mainWindow)
  

  const startUrl = url.format({
    pathname: path.join(__dirname, "./my-app/build/index.html"),
    protocol: "file",
  });

  mainWindow.loadURL(startUrl);
};

const getRunningApps = (win) => {
  exec(
    `osascript -e 'tell application "System Events" to get name of every process whose background only is false' && osascript -e 'if application "screencaptureui" is running then return ",screencaptureui"'`,
    (err, stdout, stderr) => {
      if (err) {
        console.error(`Access denied Error: ${err}`, stderr);
        return;
      }
      console.log(stdout);
      win.send("running-apps-update", stdout);
    }
  );
};

// const showMessage = (message, win) => {
//   console.log('I am logged..!!', message);
//   win.send("updatedMessage", message)

// }
const checkForUpdate = async () => {
  await autoUpdater.checkForUpdates()
}
app.whenReady().then(() => {
  createMainWindow();
  // checkForUpdate();
  
});
ipcMain.on("request-running-apps", (event) => {
  getRunningApps(event.sender);
});

// ipcMain.on('check-for-update',(event) => {
//   showMessage("new message", event.sender)
// })

// autoUpdater.on('update-available', (info) => {
//   console.log('AM I called..1');
//   showMessage("update available", info.sender);
//  autoUpdater.downloadUpdate();
//   // showMessage(path, info.sender);
// });

// autoUpdater.on('update-not-available', (info) => {
//   console.log('AM I called.2');
//   showMessage("no update available", info.sender);
// });


// autoUpdater.on('update-downloaded', (info) => {
//   console.log('AM I called..3');
//   showMessage("update downloaded", info.sender);
// });