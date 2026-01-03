#include <WiFi.h>
#include <HTTPClient.h>
#include "esp_camera.h"

// WiFi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// Render.com URL (replace with your actual URL)
const char* render_url = "https://your-app-name.onrender.com/detect/upload";

void setup() {
  Serial.begin(115200);
  
  // Initialize camera
  if(initCamera() != ESP_OK) {
    Serial.println("Camera init failed");
    return;
  }
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    // Capture image
    camera_fb_t * fb = esp_camera_fb_get();
    if (!fb) {
      Serial.println("Camera capture failed");
      return;
    }
    
    http.begin(render_url);
    http.addHeader("Content-Type", "image/jpeg");
    
    // Send image to Render
    int httpResponseCode = http.POST(fb->buf, fb->len);
    
    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Response: " + response);
    } else {
      Serial.println("Error in HTTP request");
    }
    
    http.end();
    esp_camera_fb_return(fb);
  }
  
  delay(5000); // Send every 5 seconds
}
