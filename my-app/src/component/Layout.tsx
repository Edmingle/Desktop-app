import React from "react";
import { Outlet, Link } from "react-router-dom";
export const Layout = () => {
  return (
    <div>
      <p>Inside layout</p>

      <ul>
        <li>
          <Link to={"dashboard"}>Works</Link>
        </li>
      </ul>
      <Outlet />
    </div>
  );
};
