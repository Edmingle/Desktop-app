const { app, BrowserWindow, ipcMain } = require("electron");
const path = require("path");
const url = require("url");
const { exec } = require("child_process");
const updater = require('./updater')

const createMainWindow = () => {
  // setTimeout(updater, 3000);
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

// app.dock.setIcon('./my-app/assets/images/aldineLogo.png')
app.whenReady().then(() => {
  createMainWindow();
  
});
ipcMain.on("request-running-apps", (event) => {
  getRunningApps(event.sender);
});
