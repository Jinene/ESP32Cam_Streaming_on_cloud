# ESP32-CAM Streaming on Cloud 📡🎥

Professional IoT project to stream **live video from ESP32-CAM** to a cloud server.  
Includes **C++ firmware** for ESP32 and a **Python Flask server** for live viewing.

---

## Features
- Capture JPEG frames using ESP32-CAM.
- Send frames to cloud server via Wi-Fi.
- Python Flask server stores frames and serves web interface.
- Simple web page for live video monitoring.

---

## Hardware Required
- ESP32-CAM board
- USB programmer (FTDI)
- Wi-Fi network

---

## Setup

### Firmware
1. Open `ESP32CamStreaming.ino` in Arduino IDE.
2. Edit `config.h` with your Wi-Fi and server info.
3. Upload to ESP32-CAM.

### Server
1. Install dependencies:
```bash
pip install -r requirements.txt
Run server:

bash
Copier le code
python app.py
Open browser at http://SERVER_IP:5000 to see live stream.
