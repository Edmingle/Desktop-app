import { useEffect } from "react";
import { useNavigate } from "react-router-dom";

export const Login = () => {
  const navigate = useNavigate();

  return (
    <div style={{ flex: 1, justifyContent: "center", alignItems: "center" }}>
      <button
        onClick={() => {
          navigate("/work");
        }}
      >
        Login
      </button>
    </div>
  );
};
