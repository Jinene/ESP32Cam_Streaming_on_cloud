#ifndef CONFIG_H
#define CONFIG_H

// Wi-Fi credentials
#define WIFI_SSID "YOUR_WIFI_SSID"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

// Server IP and port to stream frames
#define SERVER_IP "YOUR_SERVER_IP"
#define SERVER_PORT 5000

// Camera settings
#define FRAME_WIDTH 320
#define FRAME_HEIGHT 240
#define FRAME_QUALITY 10  // 0-63, lower is better quality
#define FRAME_INTERVAL 100  // milliseconds between frames

#endif
