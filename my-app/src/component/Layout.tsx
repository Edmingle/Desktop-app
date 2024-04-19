import React, { useContext, useEffect, useState } from "react";
import { Outlet, Link, useNavigate } from "react-router-dom";
import { NetworkManager, axiosInstance } from "../services/NetworkManager";
import { AppContext } from "../root";
import { IContextProps } from "../interfaces/initialApis";
export const Layout = () => {
  const ctx = useContext<IContextProps>(AppContext);
  const [isloading, setIsloading] = useState(true);
  const navigate = useNavigate();

  console.log("ctx is from Layout: ", ctx);

  const getUserMeta = async () => {
    try {
      // ctx.setUserMeta({ name: "vicky" });
      const response = await NetworkManager.getUserMeta();
      if (response.data.code === 200) {
        const user = response.data.user;
        localStorage.setItem("orgid", user.org_data[0].organization_id);
        setIsloading(false);
        localStorage.setItem("usermeta", JSON.stringify(user));
        axiosInstance.defaults.headers["APIKEY"] =
          localStorage.getItem("apikey");
        axiosInstance.defaults.headers["ORGID"] =
          user.org_data[0].organization_id;
        navigate("/home/dashboard");
      }
    } catch (error) {
      console.log("error is: ", error);
      setIsloading(false);
    }
  };

  useEffect(() => {
    getUserMeta();
  }, []);

  if (isloading) return <div>Loading...!!</div>;

  return <Outlet />;
};
