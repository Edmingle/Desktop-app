import FingerprintJS from "@fingerprintjs/fingerprintjs";

const useFingerprint = async () => {
  try {
    const fp = await FingerprintJS.load();
    const result = await fp.get();
    return result.visitorId;
  } catch (error) {
    console.error("Error loading FingerprintJS", error);
    return null;
  }
};

export default useFingerprint;
