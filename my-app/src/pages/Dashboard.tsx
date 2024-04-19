import { useContext, useEffect, useState } from "react";
import { AppContext } from "../root";
import { NetworkManager } from "../services/NetworkManager";
import { currentDate } from "../utils/dateTimeUtils";

export const Dashboard = () => {
  const ctx = useContext(AppContext);
  const [classData, setClassData] = useState([]);
  const [joinclass, setJoinClass] = useState(false);

  // console.log("ctx is: ", ctx);
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
      console.log("join class response is: ", response);
      if (response.data.code === 200) {
        setJoinClass(true);
      }
    } catch (error) {
      console.log("Error is: ", error);
    }
  };

  useEffect(() => {
    getTodaysClass();
  }, []);

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
      {joinclass && (
        <iframe
          id="iframeTest"
          // src="../zoom.html"
          src="https://enterpriseplanportal.edmingle.com/liveClassZoomSDK.php"
          title="External Content"
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
      )}
    </div>
  );
};
