import { exec } from "child_process";

// Function to check for screen capture tools
export function checkScreenCaptureTools(): Promise<{
  status: boolean;
  data?: any;
}> {
  const macOSApps = [
    "ScreenFlow",
    "Snagit",
    `Snagit ${new Date().getFullYear()}`,
    `Camtasia ${new Date().getFullYear()}`,
    "Camtasia",
    "obs",
    "OBS",
    "QuickTime Player",
    "screencapture",
    "screencaptureui",
    "Screenflick",
    "Kap",
    "Loom",
    "Monosnap",
    "VLC",
    "AnyDesk",
    "Slack",
    "teams",
    "Skype",
    "Movavi Screen Recorder",
    "Movavi",
    "TechSmith Capture",
    "Debut",
    // Browsers
    "Google Chrome",
    "Firefox",
    "Safari",
    "Microsoft Edge",
    "Opera",
    "Brave Browser",
    // Messaging Apps
    "Slack",
    "Microsoft Teams",
    "Skype",
    "zoom.us",
    "Discord",
    "Google Meet",
    "WhatsApp",
    "Telegram",
  ];

  const windowsApps = [
    "SnippingTool.exe",
    "ScreenSketch.exe",
    "obs64.exe",
    "OBS.exe",
    "SnagitEditor.exe",
    "Snagit32.exe",
    "Snagit64.exe",
    "CamtasiaStudio.exe",
    "CamRecorder.exe",
    "Screenpresso.exe",
    "ShareX.exe",
    "Icecream Screen Recorder.exe",
    "bdcam.exe",
    "Bandicam.exe",
    "Debut.exe",
    "Loom.exe",
    "Greenshot.exe",
    "Captura.exe",
    "GameBar.exe",
    // Browsers
    "chrome.exe",
    "firefox.exe",
    "msedge.exe",
    "opera.exe",
    "brave.exe",
    // Messaging Apps
    "slack.exe",
    "Teams.exe",
    "Skype.exe",
    "Zoom.exe",
    "Discord.exe",
    "Meet.exe",
    "WhatsApp.exe",
    "Telegram.exe",
  ];

  const linuxApps = [
    "obs",
    "kazam",
    "simplescreenrecorder",
    "vlc",
    "ffmpeg",
    "vokoscreenNG",
    "peek",
    "vokoscreen-ng",
    "recordmydesktop",
    "shutter",
    "byzanz",
    "byzanz-record",
    "green-recorder",
    "kdenlive",
    "screenstudio",
    "flameshot",
    "gnome-screenshot",
    "spectacle",
    // Browsers
    "chrome",
    "firefox",
    "microsoft-edge",
    "opera",
    "brave",
    // Messaging Apps
    "slack",
    "teams",
    "skype",
    "zoom",
    "discord",
    "meet",
    "whatsapp",
    "telegram",
  ];

  return new Promise((resolve) => {
    if (process.platform === "darwin") {
      // macOS specific command
      const command = `pgrep -l ${macOSApps.join("\\|")}`;

      exec(command, (_err, stdout) => {
        const runningApps = stdout
          .split("\n")
          .filter(Boolean)
          .map((line) => line.split(" ")[1]);
        if (runningApps.length > 0) {
          // console.log("Screen capture tool detected on macOS:", runningApps);
          resolve({ status: true, data: runningApps });
        }

        resolve({ status: false });
      });
    } else if (process.platform === "win32") {
      // Windows specific command
      const commands = windowsApps
        .map((app) => `tasklist /FI "IMAGENAME eq ${app}"`)
        .join(" & ");

      exec(commands, (_err, stdout) => {
        if (stdout && !stdout.includes("No tasks are running")) {
          console.log("Screen capture tool detected on Windows:", stdout);
          resolve({ status: true });
        }

        resolve({ status: false });
      });
    } else if (process.platform === "linux") {
      // Linux specific command
      const command = `ps aux | grep -i '${linuxApps.join("\\|")}' | grep -v grep`;
      exec(command, (_err, stdout) => {
        if (stdout) {
          console.log("Screen capture tool detected on Linux:", stdout);
          resolve({ status: true });
        }

        resolve({ status: false });
      });
    } else {
      resolve({ status: false });
    }
  });
}
