import { useContext, useEffect, useState } from "react";
import { AppContext } from "../root";
import { NetworkManager } from "../services/NetworkManager";
import { currentDate } from "../utils/dateTimeUtils";

export const Dashboard = () => {
  const ctx = useContext(AppContext);
  // console.log("ctx is: ", ctx);
  const getTodaysClass = async () => {
    try {
      const response = await NetworkManager.getTodaysClass({
        date: currentDate,
      });
      console.log("Response is: ", response);
    } catch (error) {
      console.log("Error is: ", error);
    }
  };
  useEffect(() => {
    getTodaysClass();
  }, []);

  return (
    <div>
      <p>Inside dashboard</p>
    </div>
  );
};
