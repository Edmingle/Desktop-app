import { useEffect, createContext, useState } from "react";
// import { callInstInfo, callUserMeta, hostName, DEVCONFIG } from "./utils/api";
import { NetworkManager, axiosInstance } from "./services/NetworkManager";
import {
  IOrgData,
  IUser,
  IContextProps,
  IObject,
} from "./interfaces/initialApis";

const defaultcontextValue = {
  instInfo: null,
  userMeta: null,
  currentOrg: null,
  setCurrentOrg: () => {},
  setUserMeta: () => {},
  planPermissions: null,
  institutionAddons: null,
  webViewsEndPoint: "",
  apiEndPoint: "",
};

export const AppContext = createContext<IContextProps>(defaultcontextValue);

export const useAppSelector = () => {
  const [contextData, setContextData] = useState(null);

  useEffect(() => {
    NetworkManager.getInstituteProfile()
      .then((response) => {
        setContextData({
          instInfo: response.data.institute,
        });
      })
      .catch((error) => {});
  }, []);

  return { contextData };
};
