import { Navigate, Route, Routes, HashRouter } from "react-router-dom";
import { Layout } from "../component/Layout";
import { Work } from "../pages/Work";
import { Splash } from "../pages/Splash";
import { Login } from "../pages/Login";

export const BaseRoute = () => {
  const RequireAuth = ({ children }: { children: any }) => {
    const apiKey = localStorage.getItem("apikey");
    return apiKey ? children : <Navigate to={"/login"} />;
  };
  return (
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
          <Route path="dashboard" element={<Work />} />
        </Route>
      </Routes>
    </HashRouter>
  );
};
