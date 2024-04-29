const {autoUpdater} = require('electron-updater')

autoUpdater.logger = require("electron-log")
autoUpdater.logger.transports.file.level = "info"


module.exports = () => {
    //check for update (github releases)
    // autoUpdater.checkForUpdates()
}