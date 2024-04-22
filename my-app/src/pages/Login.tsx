import { useContext, useEffect, useState } from "react";
import { useNavigate } from "react-router-dom";
import { NetworkManager } from "../services/NetworkManager";
import { AppContext } from "../root";
import useFingerprint from "../deviceKey";
import "../css/Login.css";
import type { FormProps } from "antd";
import { Button, Form, Input } from "antd";

type FieldType = {
  username?: string;
  password?: string;
  remember?: string;
};

export const Login = () => {
  const navigate = useNavigate();
  const [visitorId, setVisitorId] = useState("");

  const [userName, setUserName] = useState("");
  const [showPassword, setShowPassword] = useState(false);
  const [password, setPassword] = useState("");

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
      const response = await NetworkManager.checkIfUserExsist({
        userName: userName,
        instituteId: instInfo.institution_id,
      });
      if (response.data.code === 200) {
        if (response.data.payload.is_user_exists === 1) {
          setShowPassword(true);
        } else {
          setShowPassword(false);
        }
      }
    } catch (error) {
      console.log("Error is: ", error);
      setShowPassword(false);
    }
  };
  const verifyOtp = async () => {
    try {
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
        navigate("/home");
      }
    } catch (error) {
      console.log("Error is: ", error);
    }
  };

  const onFinish: FormProps<FieldType>["onFinish"] = (values) => {
    showPassword ? verifyOtp() : checkifUserExsist();
  };

  const onFinishFailed: FormProps<FieldType>["onFinishFailed"] = (
    errorInfo
  ) => {
    console.log("Failed:", errorInfo);
  };

  return (
    <div className="background-image">
      <Form
        name="basic"
        style={{ width: 300 }}
        layout={"vertical"}
        onFinish={onFinish}
        onFinishFailed={onFinishFailed}
        autoComplete="off"
      >
        <Form.Item<FieldType>
          label="Username"
          name="username"
          rules={[
            {
              required: true,
              message: "Please input your username!",
            },
          ]}
        >
          <Input
            onChange={(e) => setUserName(e.target.value)}
            disabled={showPassword}
            value={userName}
            style={{ width: 300 }}
            id="error"
            suffix={
              showPassword && (
                <Button
                  type="text"
                  onClick={() => setShowPassword(!showPassword)}
                >
                  Edit
                </Button>
              )
            }
          />
        </Form.Item>
        {showPassword && (
          <Form.Item<FieldType>
            label="Password"
            name="password"
            rules={[{ required: true, message: "Please input your password!" }]}
          >
            <Input.Password
              onChange={(e) => {
                setPassword(e.target.value);
              }}
            />
          </Form.Item>
        )}

        <Form.Item>
          <Button type="primary" htmlType="submit" style={{ width: 300 }}>
            {showPassword ? "Login" : "Confirm"}
          </Button>
        </Form.Item>
      </Form>
    </div>
  );
};
