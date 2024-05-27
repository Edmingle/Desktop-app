import { readFileSync, writeFileSync, writeFile, close } from "fs";
const pkgPath = "./package.json";

const { arch } = process;
const pkg = readFileSync(pkgPath);
const pkgObject = JSON.parse(pkg);

console.log(`arch is ${arch}`);
pkgObject.config = { arch: `${arch}` };
writeFileSync(pkgPath, JSON.stringify(pkgObject, null, 2));

writeFile(".npmrc", `arch=${arch}`, "utf8", function (error) {
  if (error) {
    console.log(error);
    return false;
  }
  close(0, function () {
    console.log("write .npmrc file success");
  });
});
