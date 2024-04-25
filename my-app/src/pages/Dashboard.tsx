import { ZoomMtg } from "@zoom/meetingsdk";
import { Button, Card, Col, Row, notification } from "antd";
import { useEffect, useState } from "react";
import SVGComponent from "../component/Svgs";
import "../css/Login.css";
import "../css/dashboard.css";
import { NetworkManager } from "../services/NetworkManager";
import { currentDate, getClassDate, parseTime } from "../utils/dateTimeUtils";

export const Dashboard = () => {
  const [classData, setClassData] = useState([]);
  const [zoomSecret, setZoomsecret] = useState("");
  const [platform, setPlatform] = useState("");
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
    } catch (error) {}
  };

  const checkBackgroundRunningApps = (item) => {
    if (platform === "darwin" && runningAppname.length === 0) {
      openNotification({ isEmpty: true });
    } else if (platform === "darwin" && runningAppname.length > 5) {
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
      leaveUrl: "https://enterpriseplanportal.edmingle.com/home/dashboard",
      patchJsMedia: true,
      success: (success) => {
        ZoomMtg.join({
          signature: signature,
          sdkKey: response.data.sdk_key,
          meetingNumber: response.data.join_id,
          passWord: response.data.meeting_password,
          userName: localStorage.getItem("user_name") || "",
          userEmail: localStorage.getItem("user_email") || "",
          success: (success) => {
            setIsMeetingRunning(true);
          },
          error: (error) => {
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
    getZoomKeys();
    getTodaysClass();
  }, []);

  useEffect(() => {
    if (
      platform === "darwin" &&
      isMeetingRunning &&
      (runningAppname.length > 5 || runningAppname.includes("screencaptureui"))
    ) {
      ZoomMtg.leaveMeeting({});
    }
  }, [isMeetingRunning, runningAppname]);

  // useEffect(() => {
  //   const os = (window as any).api.getOS();
  //   setPlatform(os);
  //   if (os === "darwin") {
  //     const handleAppsUpdate = (data: any) => {
  //       const runningApps = data.split(",");
  //       setRunningAppname(runningApps);
  //     };

  //     (window as any).api.onRunningAppsUpdate(handleAppsUpdate);

  //     const intervalId = setInterval(() => {
  //       (window as any).api.requestRunningApps();
  //     }, 4000);
  //     return () => {
  //       clearInterval(intervalId);
  //     };
  //   }
  // }, []);

  // if (classData.length === 0) {
  //   return <div>Loading...!!</div>;
  // }

  return (
    <div className="dashboard_container">
      <div className="dashboard_top_header">
        <svg
          width="100"
          height="32"
          viewBox="0 0 100 32"
          fill="none"
          xmlns="http://www.w3.org/2000/svg"
          xmlnsXlink="http://www.w3.org/1999/xlink"
        >
          <rect
            y="0.117645"
            width="100"
            height="31.7647"
            fill="url(#pattern0_10_174)"
          />
          <defs>
            <pattern
              id="pattern0_10_174"
              patternContentUnits="objectBoundingBox"
              width="1"
              height="1"
            >
              <use
                xlinkHref="#image0_10_174"
                transform="scale(0.00392157 0.0123457)"
              />
            </pattern>
            <image
              id="image0_10_174"
              width="255"
              height="104"
              xlinkHref="data:image/png;base64,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"
            />
          </defs>
        </svg>

        <div
          style={{ display: "flex", alignItems: "center", columnGap: "8px" }}
        >
          <svg
            width="32"
            height="32"
            viewBox="0 0 32 32"
            fill="none"
            xmlns="http://www.w3.org/2000/svg"
            xmlnsXlink="http://www.w3.org/1999/xlink"
          >
            <rect
              width="32"
              height="32"
              rx="16"
              fill="url(#pattern0_10_1106)"
            />
            <defs>
              <pattern
                id="pattern0_10_1106"
                patternContentUnits="objectBoundingBox"
                width="1"
                height="1"
              >
                <use xlinkHref="#image0_10_1106" transform="scale(0.0015625)" />
              </pattern>
              <image
                id="image0_10_1106"
                width="640"
                height="640"
                xlinkHref="data:image/jpeg;base64,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"
              />
            </defs>
          </svg>
          <span className="dashboard_student_name">Hemal Patel</span>
        </div>
      </div>

      <div className="dashboard_info_div">
        <div className="dashboard_info_div_left">
          <div>
            <svg
              width="46"
              height="50"
              viewBox="0 0 46 50"
              fill="none"
              xmlns="http://www.w3.org/2000/svg"
            >
              <circle cx="23" cy="26.1111" r="23" fill="#F1E8FF" />
              <path
                d="M8.94434 40.0233H37.0554V11.9122H8.94434V40.0233Z"
                fill="#8C8C8C"
              />
            </svg>
          </div>
          <div>
            <span className="dashboard_info_title">
              Welcome Rishabh,{" "}
              {classData.length === 0
                ? "you do not have any classes today!"
                : "you have 3 classes today!"}
            </span>
            <span className="dashboard_info_subtitle">
              This app can only be used to join classes. To access more
              features, please use the mobile application or the website.
            </span>
          </div>
        </div>
        <div className="dashboard_info_div_right">
          <Button
            className="dashboard_refresh_class_btn"
            type="primary"
            // onClick={() => setShowPassword(!showPassword)}
          >
            <svg
              width="17"
              height="18"
              viewBox="0 0 17 18"
              fill="none"
              xmlns="http://www.w3.org/2000/svg"
            >
              <g clipPath="url(#clip0_10_1179)">
                <path
                  d="M11.1562 6.875H14.3438V3.6875"
                  stroke="white"
                  strokeWidth="1.5"
                  strokeLinecap="round"
                  strokeLinejoin="round"
                />
                <path
                  d="M14.3438 6.87501L12.4658 4.99704C11.3782 3.9095 9.90573 3.29457 8.36771 3.28562C6.8297 3.27667 5.35016 3.87442 4.25 4.94923"
                  stroke="white"
                  strokeWidth="1.5"
                  strokeLinecap="round"
                  strokeLinejoin="round"
                />
                <path
                  d="M5.84375 11.125H2.65625V14.3125"
                  stroke="white"
                  strokeWidth="1.5"
                  strokeLinecap="round"
                  strokeLinejoin="round"
                />
                <path
                  d="M2.65625 11.125L4.53422 13.003C5.6218 14.0905 7.09427 14.7054 8.63229 14.7144C10.1703 14.7233 11.6498 14.1256 12.75 13.0508"
                  stroke="white"
                  strokeWidth="1.5"
                  strokeLinecap="round"
                  strokeLinejoin="round"
                />
              </g>
              <defs>
                <clipPath id="clip0_10_1179">
                  <rect
                    width="17"
                    height="17"
                    fill="white"
                    transform="translate(0 0.5)"
                  />
                </clipPath>
              </defs>
            </svg>
            <span>Refresh classes</span>
          </Button>
        </div>
      </div>

      <div>
        {contextHolder}
        <div className="dashboard_classes_container">
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
              <div className="dashboard_classes_indi">
                <span className="dashboard_classes_name">{cardTitle}</span>
                <div
                  style={{
                    display: "flex",
                    alignItems: "center",
                    columnGap: "20px",
                  }}
                >
                  <div
                    style={{
                      display: "flex",
                      alignItems: "center",
                      columnGap: "6px",
                    }}
                  >
                    <svg
                      width="21"
                      height="22"
                      viewBox="0 0 21 22"
                      fill="none"
                      xmlns="http://www.w3.org/2000/svg"
                    >
                      <path
                        fillRule="evenodd"
                        clipRule="evenodd"
                        d="M13.8091 1.70389C14.171 1.70389 14.4648 1.99762 14.4648 2.35953L14.4652 3.10068C15.7416 3.18819 16.8017 3.6254 17.552 4.37725C18.3711 5.19986 18.802 6.38264 18.7977 7.80145V15.7767C18.7977 18.6895 16.9479 20.499 13.9713 20.499H6.57738C3.60076 20.499 1.75098 18.6641 1.75098 15.7102V7.7997C1.75098 5.05229 3.40062 3.28874 6.09105 3.10098L6.09159 2.35953C6.09159 1.99762 6.38532 1.70389 6.74723 1.70389C7.10915 1.70389 7.40287 1.99762 7.40287 2.35953L7.40261 3.08423H13.153L13.1535 2.35953C13.1535 1.99762 13.4472 1.70389 13.8091 1.70389ZM17.4864 9.48767H3.06226V15.7102C3.06226 17.9534 4.3106 19.1878 6.57738 19.1878H13.9713C16.238 19.1878 17.4864 17.9761 17.4864 15.7767L17.4864 9.48767ZM14.1655 14.9883C14.5274 14.9883 14.8212 15.2821 14.8212 15.644C14.8212 16.0059 14.5274 16.2996 14.1655 16.2996C13.8036 16.2996 13.5064 16.0059 13.5064 15.644C13.5064 15.2821 13.7957 14.9883 14.1576 14.9883H14.1655ZM10.2863 14.9883C10.6482 14.9883 10.9419 15.2821 10.9419 15.644C10.9419 16.0059 10.6482 16.2996 10.2863 16.2996C9.92439 16.2996 9.62716 16.0059 9.62716 15.644C9.62716 15.2821 9.91652 14.9883 10.2784 14.9883H10.2863ZM6.39895 14.9883C6.76087 14.9883 7.0546 15.2821 7.0546 15.644C7.0546 16.0059 6.76087 16.2996 6.39895 16.2996C6.03704 16.2996 5.73894 16.0059 5.73894 15.644C5.73894 15.2821 6.02917 14.9883 6.39109 14.9883H6.39895ZM14.1655 11.5906C14.5274 11.5906 14.8212 11.8843 14.8212 12.2463C14.8212 12.6082 14.5274 12.9019 14.1655 12.9019C13.8036 12.9019 13.5064 12.6082 13.5064 12.2463C13.5064 11.8843 13.7957 11.5906 14.1576 11.5906H14.1655ZM10.2863 11.5906C10.6482 11.5906 10.9419 11.8843 10.9419 12.2463C10.9419 12.6082 10.6482 12.9019 10.2863 12.9019C9.92439 12.9019 9.62716 12.6082 9.62716 12.2463C9.62716 11.8843 9.91652 11.5906 10.2784 11.5906H10.2863ZM6.39895 11.5906C6.76087 11.5906 7.0546 11.8843 7.0546 12.2463C7.0546 12.6082 6.76087 12.9019 6.39895 12.9019C6.03704 12.9019 5.73894 12.6082 5.73894 12.2463C5.73894 11.8843 6.02917 11.5906 6.39109 11.5906H6.39895ZM13.153 4.39552H7.40261L7.40287 5.23649C7.40287 5.5984 7.10915 5.89213 6.74723 5.89213C6.38532 5.89213 6.09159 5.5984 6.09159 5.23649L6.09112 4.41536C4.13274 4.57988 3.06226 5.76699 3.06226 7.7997V8.17639H17.4864L17.4864 7.7997C17.4899 6.72007 17.1997 5.88085 16.6236 5.30389C16.1179 4.79669 15.3786 4.49378 14.4655 4.41578L14.4648 5.23649C14.4648 5.5984 14.171 5.89213 13.8091 5.89213C13.4472 5.89213 13.1535 5.5984 13.1535 5.23649L13.153 4.39552Z"
                        fill="#7B8C9F"
                      />
                    </svg>
                    <span className="dashboard_classes_grey_text">
                      {classDate}
                    </span>
                  </div>

                  <div
                    style={{
                      display: "flex",
                      alignItems: "center",
                      columnGap: "6px",
                    }}
                  >
                    <svg
                      width="22"
                      height="22"
                      viewBox="0 0 22 22"
                      fill="none"
                      xmlns="http://www.w3.org/2000/svg"
                    >
                      <path
                        d="M10.6963 6.07394V11.3191H15.9414"
                        stroke="#7B8C9F"
                        strokeWidth="1.31128"
                        strokeLinecap="round"
                        strokeLinejoin="round"
                      />
                      <path
                        d="M10.6972 20.0605C15.5252 20.0605 19.4391 16.1465 19.4391 11.3186C19.4391 6.49055 15.5252 2.57668 10.6972 2.57668C5.8692 2.57668 1.95532 6.49055 1.95532 11.3186C1.95532 16.1465 5.8692 20.0605 10.6972 20.0605Z"
                        stroke="#7B8C9F"
                        strokeWidth="1.31128"
                        strokeLinecap="round"
                        strokeLinejoin="round"
                      />
                    </svg>

                    <span className="dashboard_classes_grey_text">
                      {classTime}
                    </span>
                  </div>
                </div>
                <div>
                  <span className="dashboard_classes_grey_text">
                    By {tutorName}
                  </span>
                </div>
                {true ? (
                  <div className="dashboard_live_div">
                    <svg
                      width="8"
                      height="8"
                      viewBox="0 0 8 8"
                      fill="none"
                      xmlns="http://www.w3.org/2000/svg"
                    >
                      <circle
                        cx="4.14287"
                        cy="3.66646"
                        r="3.42857"
                        fill="#FF4D4F"
                      />
                    </svg>
                    <span>LIVE</span>
                  </div>
                ) : (
                  <></>
                )}
                <Button
                  className="dashboard_join_class_btn"
                  disabled={btnText === "JOIN NOW" ? false : true}
                  onClick={() => checkBackgroundRunningApps(item)}
                  type="primary"
                >
                  {btnText}
                </Button>
              </div>
            );
          })}
        </div>
      </div>
    </div>
  );
};
