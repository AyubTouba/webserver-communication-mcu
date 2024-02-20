#include <WiFi.h>
#include <WebServer.h>

const byte PIN_LED_R = 23;
const byte PIN_LED_G = 22;
const byte PIN_LED_B = 21;
const char *ssid = "WifiName";
const char *password = "WifiPassword";

WebServer server(80); // Create a web server on port 80

void setup()
{
  Serial.begin(115200);
  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_G, OUTPUT);
  pinMode(PIN_LED_B, OUTPUT);
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Print ESP32 IP address
  Serial.println(WiFi.localIP());
  server.enableCORS();
  // Handle incoming requests
  server.on("/", handleRoot);
  server.on("/setColor", handleSetColor);
  server.begin();
}

void loop()
{
  server.handleClient();
}

void handleRoot()
{
  server.send(200, "text/plain", "Hello World! Call to ESP32");
}

void handleSetColor()
{
  String colorData = server.arg("color");
  Serial.println("Received color: " + colorData);
  parseAndDisplayColor("#" + colorData);
  server.send(200, "text/plain", "Color set!");
}

void displayColor(byte r, byte g, byte b)
{
  analogWrite(PIN_LED_R, r);
  analogWrite(PIN_LED_G, g);
  analogWrite(PIN_LED_B, b);
}

void parseAndDisplayColor(String data)
{
  if (data.length() == 7 && data[0] == '#')
  {
    // Extract hexadecimal values for R, G, and B
    long hexValue = strtol(data.substring(1).c_str(), NULL, 16);

    int r = (hexValue >> 16) & 0xFF;
    int g = (hexValue >> 8) & 0xFF;
    int b = hexValue & 0xFF;

    // Display the color
    displayColor(r, g, b);
  }
}
