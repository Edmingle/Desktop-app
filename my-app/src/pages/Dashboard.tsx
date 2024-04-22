import { useContext, useEffect, useState } from "react";
import { AppContext } from "../root";
import { NetworkManager } from "../services/NetworkManager";
import { currentDate, getClassDate, parseTime } from "../utils/dateTimeUtils";
import { ZoomMtg } from "@zoom/meetingsdk";
import { useNavigate } from "react-router-dom";
import { Button, Card, Col, Row, notification } from "antd";
import SVGComponent from "../component/Svgs";
import "../css/Login.css";

export const Dashboard = () => {
  const ctx = useContext(AppContext);
  const navigate = useNavigate();
  const [classData, setClassData] = useState([]);
  const [zoomSecret, setZoomsecret] = useState("");
  const [runningAppname, setRunningAppname] = useState<string[]>([]);
  const [api, contextHolder] = notification.useNotification();
  const [isMeetingRunning, setIsMeetingRunning] = useState(false);

  const openNotification = ({ isEmpty = false }) => {
    api.info({
      message: `Notification`,
      description: isEmpty
        ? `Please enable system event permission from your settings`
        : `Please close this apps to join the live class: ${runningAppname.toString()}`,
      placement: "topRight",
    });
  };

  const getZoomKeys = async () => {
    try {
      const response = await NetworkManager.getKeys();
      if (response.data.code === 200) {
        setZoomsecret(response.data.zoom_keys.secret);
      }
    } catch (error) {
      setZoomsecret("");
    }
  };

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

  const checkBackgroundRunningApps = (item) => {
    if (runningAppname.length === 0) {
      openNotification({ isEmpty: true });
    } else if (runningAppname.length > 1) {
      openNotification({ isEmpty: false });
    } else {
      joinClass(item);
    }
  };

  const joinClass = async (item) => {
    try {
      const response = await NetworkManager.joinClass({ classId: item[0] });
      if (response.data.code === 200) {
        ZoomMtg.preLoadWasm();
        ZoomMtg.prepareWebSDK();
        document.getElementById("zmmtg-root").style.display = "block";
        ZoomMtg.generateSDKSignature({
          sdkKey: response.data.sdk_key,
          sdkSecret: zoomSecret,
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
    ZoomMtg.init({
      leaveUrl: "",
      patchJsMedia: true,
      success: (success) => {
        ZoomMtg.join({
          signature: signature,
          sdkKey: response.data.sdk_key,
          meetingNumber: response.data.join_id,
          passWord: response.data.meeting_password,
          userName: "Vicky Keshri",
          userEmail: "saketh@edmingle.com",
          success: (success) => {
            setIsMeetingRunning(true);
            // ZoomMtg.inMeetingServiceListener("onUserLeave", (data) => {
            //   console.log("leave meeting data: ", data);
            //   // navigate("/login");
            //   // window.close();
            // });
          },
          error: (error) => {
            console.log("join error is: ", error);
            setIsMeetingRunning(false);
          },
        });
      },
      error: (error) => {
        setIsMeetingRunning(false);
      },
    });
  };

  useEffect(() => {
    // console.log("current url is: ", window.webContents.getURL());
    getZoomKeys();
    getTodaysClass();
  }, []);

  useEffect(() => {
    if (isMeetingRunning && runningAppname.length > 7) {
      ZoomMtg.leaveMeeting({});
    }
  }, [isMeetingRunning, runningAppname]);

  useEffect(() => {
    const handleAppsUpdate = (data: any) => {
      const runningApps = data.split(",");
      setRunningAppname(runningApps);
    };

    (window as any).api.onRunningAppsUpdate(handleAppsUpdate);

    const intervalId = setInterval(() => {
      (window as any).api.requestRunningApps();
    }, 4000);
    return () => {
      clearInterval(intervalId);
    };
  }, []);

  if (classData.length === 0) {
    return <div>Loading...!!</div>;
  }

  return (
    <div
      className="background-image1"
      style={{
        height: "100vh",
        display: "flex",
        alignItems: "center",
        justifyContent: "center",
      }}
    >
      {contextHolder}
      <Row
        gutter={16}
        style={{
          display: "flex",
          justifyContent: "flex-start",
          width: "100%",
          flexWrap: "wrap",
        }}
      >
        {classData.map((item, index) => {
          const clasName = item[10];
          const courseName = item[32] !== null ? item[32] : "";
          const cardTitle =
            item[17] === 3 ? clasName : `${courseName} (${clasName})`;

          const classDate = getClassDate(item[3]);
          const classTime = parseTime(item[4]) + " - " + parseTime(item[5]);
          const tutorName = item[2];

          let btnText = "";
          if (item[6] !== 3) {
            if (item[29] === 0) {
              btnText = "OFFLINE";
            } else if (item[29] === 1) {
              btnText = "NOT STARTED";
            } else if (item[29] === 2) {
              btnText = "JOIN NOW";
              //btn clolur blue
            } else if (item[29] === 3) {
              btnText = "CLASS ENDED";
            }
          } else {
            btnText = "CANCELLED";
          }

          return (
            <Col key={index} span={8}>
              <Card
                title={cardTitle}
                bordered={false}
                style={{ marginBottom: 20 }}
              >
                <div style={{ display: "flex" }}>
                  <div style={{ display: "flex", alignItems: "center" }}>
                    <SVGComponent src={"calendar"} />
                    <p style={{ marginLeft: 10 }}>{classDate}</p>
                  </div>
                  <div
                    style={{
                      display: "flex",
                      alignItems: "center",
                      marginLeft: 10,
                    }}
                  >
                    <SVGComponent src={"clock"} />
                    <p style={{ marginLeft: 10 }}>{classTime}</p>
                  </div>
                </div>

                <div style={{ display: "flex", alignItems: "center" }}>
                  <SVGComponent src={"single_user"} />
                  <p style={{ marginLeft: 10 }}>By {tutorName}</p>
                </div>
                <Button
                  style={{
                    position: "absolute",
                    right: 0,
                    bottom: 0,
                    padding: 5,
                    borderRadius: 0,
                    borderBottomRightRadius: 10,
                    borderTopLeftRadius: 10,
                    minWidth: 30,
                  }}
                  // disabled={btnText === "JOIN NOW" ? false : true}
                  // color="#b2bbc6"
                  onClick={() => checkBackgroundRunningApps(item)}
                  // onClick={() => joinClass(item)}
                  type="primary"
                >
                  {btnText}
                </Button>
              </Card>
            </Col>
          );
        })}
      </Row>
    </div>
  );

  // <button onClick={() => joinClass(item)}>Join now</button>
  // Refused to frame 'https://enterpriseplanportal.edmingle.com/'
  //  because an ancestor violates the following
  //  Content Security Policy directive: "frame-ancestors 'self'".
};
