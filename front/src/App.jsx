import { useState } from "react";
import "./App.css";
import Lamp from "./Lamp";
import axios from "axios";

function App() {
  const [lampColor, setLampColor] = useState("#f1c40f");
  const [isFinished, setIsFinished] = useState(true);
  const ipEsp32 = "192.168.1.24"; // Change to the Esp ip adress
  const handleColorChange = (e) => {
    setLampColor(e.target.value);
    sendDataToArduino();
  };

  const sendDataToArduino = () => {
    setIsFinished(false);
    axios
      .get(`http://${ipEsp32}/setColor?color=${lampColor.slice(1)}`)
      .then((response) => {
        console.log(response.data);
        setIsFinished(true);
      })
      .catch((error) => {
        console.error("Error sending data to Arduino:", error);
        setIsFinished(true);
      });
  };
  return (
    <div className="flex h-screen items-center justify-center">
      <Lamp color={lampColor} />

      <div className="ml-4">
        <label htmlFor="colorInput" className="text-gray-700">
          Lamp Color:
        </label>
        <input
          disabled={!isFinished}
          type="color"
          id="colorInput"
          value={lampColor}
          onChange={handleColorChange}
          className="ml-2"
        />
      </div>
    </div>
  );
}

export default App;
