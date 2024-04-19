import { useContext, useEffect, useState } from "react";
import { useNavigate } from "react-router-dom";
import { NetworkManager } from "../services/NetworkManager";
import { AppContext } from "../root";
import useFingerprint from "../deviceKey";

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

  return (
    <div style={{ flex: 1, justifyContent: "center", alignItems: "center" }}>
      <input
        type="text"
        disabled={showPassword ? true : false}
        required
        onChange={(e) => {
          setUserName(e.target.value);
        }}
      />
      {showPassword && (
        <input
          type="password"
          required
          onChange={(e) => {
            setPassword(e.target.value);
          }}
        />
      )}
      <button onClick={showPassword ? verifyOtp : checkifUserExsist}>
        {showPassword ? "Verify" : "Continue"}
      </button>
    </div>
  );
};
