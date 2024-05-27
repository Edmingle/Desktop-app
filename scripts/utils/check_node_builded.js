import { existsSync } from "fs";
import { execSync } from "child_process";

const { platform, arch } = process;

const sdkPathMap = {
  "darwin:x64": "./sdk/mac",
  "darwin:arm64": "./sdk/mac",
  "win32:ia32": "./sdk/win32",
  "win32:x64": "./sdk/win64",
};
const sdkNodePath = sdkPathMap[`${platform}:${arch}`];

const existsNodeFiles =
  existsSync(`${sdkNodePath}/zoomsdk.node`) &&
  existsSync(`${sdkNodePath}/zoomsdk_render.node`) &&
  existsSync(`${sdkNodePath}/zoomsdk_napi_util.node`);
console.log(".node files exist", existsNodeFiles);
if (!existsNodeFiles) {
  console.log("rebuilding .node files...");
  execSync("node scripts/electron_sdk_buildNode.js", { stdio: [0, 1, 2] });
}
