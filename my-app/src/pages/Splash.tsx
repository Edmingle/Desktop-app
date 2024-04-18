import { useEffect } from "react";
import { useNavigate } from "react-router-dom";

export const Splash = () => {
  const navigate = useNavigate();
  useEffect(() => {
    setTimeout(() => {
      navigate("home");
    }, 2000);
  }, []);
  return (
    <div style={{ flex: 1, justifyContent: "center", alignItems: "center" }}>
      <p>Spash screen goes here</p>
    </div>
  );
};
