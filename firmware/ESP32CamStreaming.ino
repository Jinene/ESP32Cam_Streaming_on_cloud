#include "config.h"
#include "esp_camera.h"
#include <WiFi.h>
#include <HTTPClient.h>

// Define camera model
#define CAMERA_MODEL_AI_THINKER
#include "camera_pins.h"

// Connect to Wi-Fi
void connectWiFi() {
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ Wi-Fi connected!");
  Serial.print("IP address: "); Serial.println(WiFi.localIP());
}

// Initialize camera
void initCamera() {
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_QVGA;
  config.jpeg_quality = FRAME_QUALITY;
  config.fb_count = 2;

  if (esp_camera_init(&config) != ESP_OK) {
    Serial.println("❌ Camera init failed");
    while(true);
  }
  Serial.println("✅ Camera initialized");
}

void setup() {
  Serial.begin(115200);
  connectWiFi();
  initCamera();
}

void loop() {
  camera_fb_t * fb = esp_camera_fb_get();
  if(!fb) {
    Serial.println("❌ Camera capture failed");
    delay(1000);
    return;
  }

  if(WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = String("http://") + SERVER_IP + ":" + String(SERVER_PORT) + "/upload_frame";
    http.begin(url);
    http.addHeader("Content-Type", "image/jpeg");
    int httpResponseCode = http.POST(fb->buf, fb->len);
    if(httpResponseCode>0){
      Serial.print("✅ Frame sent. Response: "); Serial.println(httpResponseCode);
    } else {
      Serial.print("❌ Error sending frame: "); Serial.println(httpResponseCode);
    }
    http.end();
  }

  esp_camera_fb_return(fb);
  delay(FRAME_INTERVAL);
}
