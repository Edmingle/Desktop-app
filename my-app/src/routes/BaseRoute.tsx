import { App as AntdApp } from "antd";
import { HashRouter, Navigate, Route, Routes } from "react-router-dom";
import { Layout } from "../component/Layout";
import { Dashboard } from "../pages/Dashboard";
import { Login } from "../pages/Login";
import { Splash } from "../pages/Splash";

export const BaseRoute = () => {
  const RequireAuth = ({ children }: { children: any }) => {
    const apiKey = localStorage.getItem("apikey");
    return apiKey ? children : <Navigate to={"/login"} />;
  };
  return (
    <AntdApp>
      <HashRouter>
        <Routes>
          <Route path="/" element={<Splash />} />
          <Route path="login" element={<Login />} />
          <Route
            path="home"
            element={
              <RequireAuth>
                <Layout />
              </RequireAuth>
            }
          >
            <Route path="dashboard" element={<Dashboard />} />
          </Route>
        </Routes>
      </HashRouter>
    </AntdApp>
  );
};
