import { useContext, useEffect } from "react";
import { useNavigate } from "react-router-dom";
import { AppContext } from "../root";

export const Splash = () => {
  const navigate = useNavigate();
  const ctx = useContext(AppContext);
  const { instInfo = {} } = ctx || {};

  useEffect(() => {
    let timeout = null;
    if (Object.keys(instInfo).length > 0) {
      timeout = setTimeout(() => {
        const apikey = localStorage.getItem("apikey");
        if (apikey) {
          navigate("/home");
        } else {
          navigate("/login");
        }
      }, 2000);
    } else {
      navigate("/login");
    }

    return () => {
      clearTimeout(timeout);
    };
  }, []);

  return (
    <div style={{ flex: 1, justifyContent: "center", alignItems: "center" }}>
      <p>Spash screen goes here</p>
    </div>
  );
};
