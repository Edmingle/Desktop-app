import axios, { AxiosInstance } from "axios";
const axiosInstance: AxiosInstance = axios.create({
  baseURL: "https://enterpriseplanportal-api.edmingle.com/nuSource/api/v1/",
  // headers: {
  //   APIKEY: localStorage.getItem("apikey"),
  //   ORGID: localStorage.getItem("orgid"),
  // },
});

axiosInstance.interceptors.request.use(async function (config) {
  /**
   * More option headers needs to added here
   * @example config.headers.TOKEN = token;
   */
  if (config.method === "post") {
    config.headers["Content-Type"] = "multipart/form-data";
  }

  return config;
});

axiosInstance.interceptors.response.use(
  (response) => {
    return new Promise((resolve) => {
      /**
       * Global success response can be parsed here
       * @example resolve(response.data.data);
       * This will ensure to pass only needs response on the component level
       */
      resolve(response);
    });
  },

  (error) => {
    /**
     * This will ensure any manipulation of
     * error on the global level and then pass on the component
     */
    if (!error.response) {
      return new Promise((_, reject) => {
        reject(error);
      });
    }

    if (error.response === undefined) {
      //Session timeout
    } else if (error.response.status === 401 || error.response.status === 400) {
      return new Promise((_, reject) => {
        reject(error.response);
      });
    } else {
      return new Promise((_, reject) => {
        reject(error.response);
      });
    }
  }
);

export { axiosInstance };

export const convertToFormData = (payload, name = "JSONString") => {
  const data = new FormData();
  data.append(name, JSON.stringify(payload));
  return data;
};

export const NetworkManager = {
  getInstituteProfile: () => {
    return axios.get(
      "https://enterpriseplanportal-api.edmingle.com/nuSource/api/v1/institute/profile?portal_name=enterpriseplanportal"
    );
  },
  checkIfUserExsist: ({ userName = "", instituteId = 0 }) => {
    return axios.get(
      `https://enterpriseplanportal-api.edmingle.com/nuSource/api/v1/user/checkifexists?institution_id=${instituteId}&user=${userName}&calling_modal=login`
    );
  },
  verifyOtp: ({ data = {} }) => {
    const payload = convertToFormData(data);
    return axios.post(
      `https://enterpriseplanportal-api.edmingle.com/nuSource/api/v1/login`,
      payload,
      { headers: { APIKEY: localStorage.getItem("apikey") } }
    );
  },
  getUserMeta: () => {
    return axios.get(
      `https://enterpriseplanportal-api.edmingle.com/nuSource/api/v1/user/usermeta`,
      {
        headers: {
          APIKEY: localStorage.getItem("apikey"),
          ORGID: localStorage.getItem("orgid"),
        },
      }
    );
  },
  getTodaysClass: ({ date = "0" }) => {
    return axiosInstance.get(`student/classes/period?date=${date}`);
  },
};
