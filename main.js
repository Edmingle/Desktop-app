const { app, BrowserWindow, ipcMain } = require("electron");
const path = require("path");
const url = require("url");
const { exec } = require("child_process");

const createMainWindow = () => {
  const mainWindow = new BrowserWindow({
    title: "First App",
    height: 600,
    width: 1000,
    fullscreen: true,
    webPreferences: {
      contextIsolation: true,
      nodeIntegration: true,
      preload: path.join(__dirname, "preload.js"),
    },
  });
  mainWindow.setContentProtection(true);
  mainWindow.webContents.openDevTools();

  const startUrl = url.format({
    pathname: path.join(__dirname, "./my-app/build/index.html"),
    protocol: "file",
  });

  mainWindow.loadURL(startUrl);
};

const getRunningApps = (win) => {
  exec(
    `osascript -e 'tell application "System Events" to get name of every process whose background only is false' && osascript -e 'if application "screencaptureui" is running then return "screencaptureui"'`,
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

app.whenReady().then(() => {
  createMainWindow();
  app.setAsDefaultProtocolClient("edmingleDesktopPoc");
});
ipcMain.on("request-running-apps", (event) => {
  getRunningApps(event.sender);
});

// {
//   "ancestorOrigins": {},
//   "href": "file:///Users/vickykeshri/Desktop/Electron%20App/my-app/build/index.html#/home/dashboard",
//   "origin": "file://",
//   "protocol": "file:",
//   "host": "",
//   "hostname": "",
//   "port": "",
//   "pathname": "/Users/vickykeshri/Desktop/Electron%20App/my-app/build/index.html",
//   "search": "",
//   "hash": "#/home/dashboard"
// }
