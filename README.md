ESP32-CAM Streaming on Cloud

A complete project to stream live video from an ESP32-CAM module to a web browser over Wi-Fi, with optional cloud access using ngrok. This project can be extended to IoT dashboards using Node-RED or MQTT.

Table of Contents

Project Overview

Features

Hardware Requirements

Software Requirements

Wiring Diagram

Setup Instructions

Usage

Optional: Cloud Access

Troubleshooting

Future Enhancements

License

Project Overview

This project demonstrates how to stream live video from an ESP32-CAM to a web browser. It uses Arduino IDE for programming and Wi-Fi to connect to your local network. By using ngrok, the stream can be accessed from anywhere, making it suitable for remote monitoring, IoT projects, or security applications.

Features

Live MJPEG video streaming via ESP32-CAM.

Simple HTML interface with embedded video.

Cloud-accessible stream using ngrok.

Supports AI-Thinker ESP32-CAM module.

Lightweight, low-latency streaming.

Can be extended to dashboards (Node-RED, MQTT, etc.).

Hardware Requirements

ESP32-CAM module (AI-Thinker)

USB to TTL programmer (for programming ESP32-CAM)

Jumper wires

Micro-USB cable (or FTDI programmer)

5V power supply (optional for stable streaming)

Software Requirements

Arduino IDE (version 1.8.x or 2.x)

ESP32 Board Support:

https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json


Libraries:

WiFi

ESP32WebServer (usually included)

Optional: ngrok for cloud access

Wiring Diagram

For programming the ESP32-CAM:

ESP32-CAM      USB-TTL
GND       →    GND
5V        →    VCC (5V)
U0R       →    TX
U0T       →    RX
IO0       →    GND (for flash mode)


Note: Connect a 5V external supply if using high-resolution streaming to avoid unstable resets.

Setup Instructions

Install ESP32 Board in Arduino IDE

Go to File → Preferences → Additional Boards URL.

Paste:

https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json


Open Tools → Board → Board Manager → Search esp32 → Install.

Select Board

Tools → Board → AI Thinker ESP32-CAM

Tools → Flash Mode → QIO

Tools → Upload Speed → 115200

Upload the Code

Open the ESP32-CAM Streaming code.

Replace Wi-Fi credentials:

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";


Connect IO0 to GND for flashing.

Press Upload.

Serial Monitor

Set baud rate: 115200

Press the RESET button after uploading.

Wait for Wi-Fi connected! and note the ESP32 IP address.

Usage

Open your browser.

Enter the ESP32-CAM IP address, e.g.:

http://192.168.1.105/


You will see a live video stream from your ESP32-CAM.

Optional: Cloud Access

Install ngrok: https://ngrok.com/

Run:

ngrok http 80


Ngrok will generate a public URL like:

http://abc123.ngrok.io


Open this URL in any device to access the live stream remotely.

Troubleshooting

Camera init failed

Check wiring and board selection.

Ensure correct camera module (AI-Thinker).

ESP32-CAM keeps restarting

Provide stable 5V power supply.

Lower frame size to QVGA for testing.

Cannot access stream

Ensure ESP32 and PC are on the same Wi-Fi.

Check Serial Monitor for correct IP.

Future Enhancements

Integrate MQTT to send alerts on motion detection.

Stream directly to Node-RED dashboard.

Add face/vehicle detection using TinyML models.

Record and store streams in cloud storage.

License

This project is released under the MIT License. Feel free to use, modify, and share.
