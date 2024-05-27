import { execSync } from "child_process";

execSync("node scripts/utils/check_node_modules_installed.js", {
  stdio: [0, 1, 2],
});
execSync("node scripts/utils/check_node_builded.js", { stdio: [0, 1, 2] });

execSync("electron-vite preview", { stdio: [0, 1, 2] });
