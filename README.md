# WebServer (on wifi) Communication - ESP32 (Or any MCU support wifi) and React

This repository demonstrates a simple communication setup between an ESP32 (Or any MCU support wifi) and web application with React. The communication is achieved through the web server

## Prerequisites

Make sure you have the following installed on your machine:

- Node.js
- npm (Node Package Manager)
- Arduino IDE (for uploading the sketch to your MCU board)

## Getting Started

1. **Clone the repository:**

   ```bash
   git clone https://github.com/AyubTouba/webserver-communication-mcu.git
   cd webserver-communication-mcu

   ```

1. **Update ESP32 Wifi connexion :**
   To use the communication, modify the `ssid` and `password` in `sketch_rgb`

1. **Update Ip adress in front/App.jsx :**
   ```javascript
   const ipEsp32 = "192.168.1.24"; // Change to IP adresse shows in arduino IDE after connecting to the WIFI
   ```
1. **Upload ESP32 Sketch:**
   Open the Arduino IDE and upload the provided sketch (sketch_rgb.ino) to your Arduino board.
1. **Start the web application:**
   In the front folder, run:

   ```
   npm run dev

   ```

## Usage

Visit [http://localhost:5173](http://localhost:5173) in your web browser to interact with the React application. The application allows you to send data to the ESP32, changing the color of an RGB LED connected to the ESP32.

## Contributing

Feel free to contribute by opening issues or submitting pull requests. Your feedback and improvements are highly appreciated!

## License

This project is licensed under the MIT License.
