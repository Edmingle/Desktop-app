import moment from "moment";

export const currentDate = moment().format("DD MMM YYYY");

export const getClassDate = (timestampInSeconds) => {
  return moment(timestampInSeconds * 1000).format("DD MMM YY");
};

export const parseTime = (time) => {
  try {
    let hours: number | string = Math.floor(time / 60);
    let minutes: number | string = time % 60;

    // Format hours and minutes to ensure they are always two digits
    hours = hours.toString().padStart(2, "0");
    minutes = minutes.toString().padStart(2, "0");

    // Concatenate the hours and minutes with a colon
    const timeString = `${hours}:${minutes}`;

    // Use moment to format to 12-hour time, including AM or PM
    return moment(timeString, "HH:mm").format("hh:mm A");
  } catch (e) {
    return "";
  }
};
