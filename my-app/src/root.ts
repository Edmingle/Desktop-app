import { useEffect, createContext, useState } from "react";
import { NetworkManager } from "./services/NetworkManager";
import { IContextProps } from "./interfaces/initialApis";

const defaultcontextValue = {
  instInfo: null,
  userMeta: null,
  setUserMeta: () => {},
};

export const AppContext = createContext<IContextProps>(defaultcontextValue);

export const useAppSelector = () => {
  const [contextData, setContextData] =
    useState<IContextProps>(defaultcontextValue);
  const [userMeta, setUserMeta] = useState(null);
  useEffect(() => {
    getInstituteProfile();
  }, []);

  const getInstituteProfile = async () => {
    try {
      const response = await NetworkManager.getInstituteProfile();
      if (response.data.code === 200) {
        console.log("response is: ", response.data.institute.institution_id);
        localStorage.setItem("orgid", response.data.institute.institution_id);
        setContextData({
          instInfo: response.data.institute,
          setUserMeta: setUserMeta,
          userMeta: userMeta,
        });
      }
    } catch (error) {}
  };

  return { contextData };
};
