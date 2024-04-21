import { useContext, useEffect, useState } from "react";
import { AppContext } from "../root";
import { NetworkManager } from "../services/NetworkManager";
import { currentDate } from "../utils/dateTimeUtils";
import { ZoomMtg } from "@zoom/meetingsdk";

export const Dashboard = () => {
  const ctx = useContext(AppContext);
  const [classData, setClassData] = useState([]);
  const [joinclass, setJoinClass] = useState(false);

  const getTodaysClass = async () => {
    try {
      const response = await NetworkManager.getTodaysClass({
        date: currentDate,
      });
      if (response.data.code === 200) {
        setClassData(response.data.payload.classes);
      }
      console.log("Response is: ", response);
    } catch (error) {
      console.log("Error is: ", error);
    }
  };

  const joinClass = async (item) => {
    try {
      const response = await NetworkManager.joinClass({ classId: item[0] });
      if (response.data.code === 200) {
        console.log("join response is: ", response);

        setJoinClass(true);
        ZoomMtg.preLoadWasm();
        ZoomMtg.prepareWebSDK();
        document.getElementById("zmmtg-root").style.display = "block";
        ZoomMtg.generateSDKSignature({
          sdkKey: "",
          sdkSecret: "",
          meetingNumber: response.data.join_id,
          role: "0",
          success: (signature) => joinZoom({ response, signature }),
          error: (error) => {
            console.log(error);
          },
        });
      }
    } catch (error) {}
  };

  const joinZoom = ({ response, signature }) => {
    console.log("signature is: ", response);

    ZoomMtg.init({
      leaveUrl: "https://google.com",
      patchJsMedia: true,
      success: (success) => {
        console.log(success);

        ZoomMtg.join({
          signature: signature,
          sdkKey: response.data.sdk_key,
          meetingNumber: response.data.join_id,
          passWord: response.data.meeting_password,
          userName: "Vicky Keshri",
          userEmail: "saketh@edmingle.com",
          success: (success) => {
            console.log(success);
          },
          error: (error) => {
            console.log("join error is: ", error);
          },
        });
      },
      error: (error) => {
        console.log("another join error: ", error);
      },
    });
  };

  useEffect(() => {
    getTodaysClass();
  }, []);

  //   useEffect(() => {
  //     if (joinclass) {
  //       const iframe = document.getElementById("iframeTest").contentWindow;
  //       iframe.postMessage("something", "*");
  //     }
  //   }, [joinclass]);

  if (classData.length === 0) {
    return <div>Loading...!!</div>;
  }

  return (
    <div>
      {classData.map((item) => {
        return (
          <div>
            <p>I am here</p>
            <button onClick={() => joinClass(item)}>Join now</button>
          </div>
        );
      })}
      {/* {joinclass && (
        <iframe
          id="iframeTest"
          //   src="../../zoom.html"
          src="https://enterpriseplanportal.edmingle.com/liveClassZoomSDK.php"
          title="External Content"
          allow="camera; microphone"
          style={{
            position: "fixed",
            width: "100%",
            height: "100%",
            zIndex: 100,
            marginRight: 20,
            marginTop: 20,
            top: 10,
            border: "none",
          }}
        ></iframe>
      )} */}
    </div>
    // Refused to frame 'https://enterpriseplanportal.edmingle.com/'
    //  because an ancestor violates the following
    //  Content Security Policy directive: "frame-ancestors 'self'".
  );
};
