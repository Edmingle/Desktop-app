import type { FormProps } from "antd";
import { App, Button, Form, Input } from "antd";
import { useContext, useEffect, useState } from "react";
import { useNavigate } from "react-router-dom";
import "../css/Login.css";
import useFingerprint from "../deviceKey";
import { AppContext } from "../root";
import { NetworkManager } from "../services/NetworkManager";

type FieldType = {
  username?: string;
  password?: string;
  remember?: string;
};

export const Login = () => {
  const navigate = useNavigate();
  const { message } = App.useApp();
  const [visitorId, setVisitorId] = useState("");

  const [userName, setUserName] = useState("");
  const [showPassword, setShowPassword] = useState(false);
  const [password, setPassword] = useState("");
  const [loading, setLoading] = useState(false);

  const ctx = useContext(AppContext);
  const { instInfo } = ctx || {};

  useEffect(() => {
    const fetchFingerprint = async () => {
      // eslint-disable-next-line react-hooks/rules-of-hooks
      const id = await useFingerprint();
      setVisitorId(id);
    };

    fetchFingerprint();
  }, []);

  const checkifUserExsist = async () => {
    try {
      setLoading(true);
      const response = await NetworkManager.checkIfUserExsist({
        userName: userName,
        instituteId: instInfo.institution_id,
      });
      if (response.data.code === 200) {
        if (response.data.payload.is_user_exists === 1) {
          setShowPassword(true);
        } else {
          setShowPassword(false);
          message.error("Sorry! User does not exist.");
        }
      }
    } catch (error) {
      console.log("Error is: ", error);
      setShowPassword(false);
      message.error("Sorry! User does not exist.");
    } finally {
      setLoading(false);
    }
  };
  const verifyOtp = async () => {
    try {
      setLoading(true);
      const data = {
        username: userName,
        password: password,
        persistent_login: true,
        device_type: 4,
        device_key: visitorId,
      };
      const response = await NetworkManager.verifyOtp({ data });
      if (response.data.code === 200) {
        const user = response.data.user;
        const { apikey = "" } = user || {};
        localStorage.setItem("apikey", apikey);
        message.success("Login successful!");
        navigate("/home");
      }
    } catch (error) {
      console.log("Error is: ", error);
      message.error(error?.response?.data?.message);
    } finally {
      setLoading(false);
    }
  };

  const onFinish: FormProps<FieldType>["onFinish"] = (values) => {
    console.log(values);
    showPassword ? verifyOtp() : checkifUserExsist();
  };

  const onFinishFailed: FormProps<FieldType>["onFinishFailed"] = (
    errorInfo
  ) => {
    console.log("Failed:", errorInfo);
  };

  return (
    <div className="background_image_container">
      <div className="background-image">
        <div className="login_container">
          <Form
            name="basic"
            style={{ width: 300 }}
            layout={"vertical"}
            onFinish={onFinish}
            onFinishFailed={onFinishFailed}
            autoComplete="off"
          >
            <div>
              <span className="login_username">Username</span>
              <Form.Item<FieldType>
                name="username"
                rules={[
                  {
                    required: true,
                    message: "Please input your username!",
                  },
                ]}
              >
                {/* <ConfigProvider
                theme={{
                  token: {
                    colorBgContainerDisabled: "#e4e9f1",
                  },
                }}
              > */}
                <Input
                  onChange={(e) => setUserName(e.target.value)}
                  disabled={showPassword}
                  value={userName}
                  style={{ width: 300, marginTop: "8px" }}
                  id="error"
                  placeholder="Enter username"
                  suffix={
                    showPassword && (
                      <Button
                        className="edit_button"
                        type="text"
                        onClick={() => setShowPassword(!showPassword)}
                      >
                        Edit
                      </Button>
                    )
                  }
                />
                {/* </ConfigProvider> */}
              </Form.Item>
            </div>
            {showPassword && (
              <Form.Item<FieldType>
                label="Password"
                name="password"
                rules={[
                  { required: true, message: "Please input your password!" },
                ]}
              >
                <Input.Password
                  onChange={(e) => {
                    setPassword(e.target.value);
                  }}
                />
              </Form.Item>
            )}

            <Form.Item>
              <Button
                type="primary"
                htmlType="submit"
                style={{ width: 300 }}
                className="login_button"
                loading={loading}
              >
                {showPassword ? "Login" : "Proceed"}
                <svg
                  width="12"
                  height="12"
                  viewBox="0 0 12 12"
                  fill="none"
                  xmlns="http://www.w3.org/2000/svg"
                >
                  <g clipPath="url(#clip0_8_167)">
                    <path
                      d="M4.5 2.25L8.25 6L4.5 9.75"
                      stroke="white"
                      strokeWidth="1.5"
                      strokeLinecap="round"
                      strokeLinejoin="round"
                    />
                  </g>
                  <defs>
                    <clipPath id="clip0_8_167">
                      <rect width="12" height="12" fill="white" />
                    </clipPath>
                  </defs>
                </svg>
              </Button>
            </Form.Item>
          </Form>
        </div>
      </div>
    </div>
  );
};
