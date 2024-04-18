import { useEffect, useState } from "react";
import "./App.css";
import { Navigate, Outlet, Route, Routes, HashRouter } from "react-router-dom";
import { Layout } from "./component/Layout";
import { Work } from "./pages/Work";
import { Splash } from "./pages/Splash";
import { Login } from "./pages/Login";

const App = () => {
  const [runningAppname, setRunningAppname] = useState<string[]>([]);
  const [deeplinkData, setDeeplinksData] = useState("");
  useEffect(() => {
    const handleAppsUpdate = (data: any) => {
      console.log("apps name: ", data);
      const runningApps = data.split(",");
      setRunningAppname(runningApps);
    };
    const deeplinksPayload = (data: any) => {
      console.log("deeplinksPayload ", data);
      setDeeplinksData(data);
    };

    (window as any).api.onRunningAppsUpdate(handleAppsUpdate);
    (window as any).api.deeplinks(deeplinksPayload);

    const intervalId = setInterval(() => {
      (window as any).api.requestRunningApps();
    }, 4000);
    return () => {
      clearInterval(intervalId);
    };
  }, []);

  // if (deeplinkData.length === 0) {
  //   return (
  //     <div>
  //       App is open without deeplinks. Please quit and reopen it from web
  //       portal.
  //     </div>
  //   );
  // }

  // if (runningAppname.length > 3) {
  //   // TODO: too many apps are running in the background.
  //   // Please close other and reopen the app
  //   console.log("len: ", runningAppname.length);

  //   return (
  //     <div>
  //       {runningAppname} are the apps which are running in background, Please
  //       close them and again join from web portal
  //     </div>
  //   );
  // }

  // console.log("runningAppname: 0", runningAppname);
  // console.log("runningAppname: 1", runningAppname.length);
  // console.log("runningAppname: 2", runningAppname.includes(" Electron"));
  // console.log("runningAppname: 3", deeplinkData.length);

  // if (
  //   runningAppname.length === 6 &&
  //   runningAppname.includes(" Electron") &&
  //   deeplinkData.length > 0
  // ) {
  //   return <div>Wola.., let them join the meeting</div>;
  // }
  const RequireAuth = ({ children }: { children: any }) => {
    // const ctx = useContext<IContextProps>(AppContext);
    // const { userMeta = {}, currentOrg, instInfo } = ctx || {};
    // const user = userMeta.user;
    // const auth =
    //   user?.user_id && user?.org_data.length && currentOrg?.role != "student";

    return false ? <Navigate to={"/login"} /> : children;
    // return !auth ? <Navigate to={"/login"} /> : children;
  };

  return (
    <HashRouter>
      <Routes>
        <Route path="/" element={<Splash />} />
        <Route path="login" element={<Login />} />
        <Route
          path="home"
          element={
            <RequireAuth>
              <Layout />
            </RequireAuth>
          }
        >
          <Route path="dashboard" element={<Work />} />
        </Route>
      </Routes>
    </HashRouter>
  );

  // return (
  //   <div>
  //     {/* <div>Running apps are: {runningAppname.split(",").toString()}</div> */}

  //     <button
  //       id="close"
  //       style={{ position: "absolute", top: 0, right: 0 }}
  //       onClick={() => {
  //         const iframe = document.getElementById("iframeTest");
  //         iframe?.parentNode?.removeChild(iframe);
  //       }}
  //     >
  //       Close
  //     </button>
  //     {/* <button
  //       onClick={() => {
  //         setShouldJoinMeeting(true);
  //       }}
  //     >
  //       Join Meeting
  //     </button> */}
  //     {true && (
  //       <iframe
  //         id="iframeTest"
  //         // src="../zoom.html"
  //         src="../../zoom.html"
  //         title="External Content"
  //         style={{
  //           position: "fixed",
  //           width: "100%",
  //           height: "100%",
  //           zIndex: 100,
  //           marginRight: 20,
  //           marginTop: 20,
  //           top: 10,
  //           border: "none",
  //         }}
  //       ></iframe>
  //     )}
  //   </div>
  // );
};

export default App;

// The push operation includes a file which exceeds GitHub's file size restriction of 100MB. Please remove the file from history and try again.

// File causing error:

// node_modules/electron/dist/Electron.app/Contents/Frameworks/Electron Framework.framework/Versions/A/Electron Framework (141.60 MB)
