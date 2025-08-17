#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "Kali";
const char* password = "123456789";
const char* apiKey = "AIzaSyBm2P2nLdQvK_Vth4LdA-y55JUL9UGE0qo";

String endpoint = "https://generativelanguage.googleapis.com/v1beta/models/gemini-2.0-flash:generateContent";

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");
}

void loop() {
  if (Serial.available()) {
    String userInput = Serial.readStringUntil('\n');
    userInput.trim();

    if (userInput.length() > 0) {
      Serial.println("\nSending to Gemini API: " + userInput);
      sendToGemini(userInput);
    }
  }
}

void sendToGemini(String prompt) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String url = endpoint + "?key=" + apiKey;
    http.begin(url);
    http.addHeader("Content-Type", "application/json");

    // Build JSON payload
    String jsonPayload = "{ \"contents\": [ { \"parts\": [ { \"text\": \"" + prompt + "\" } ] } ] }";

    int httpResponseCode = http.POST(jsonPayload);

    if (httpResponseCode > 0) {
      String payload = http.getString();
      Serial.println("\nRaw Response:");
      Serial.println(payload);

      // Parse JSON response
      DynamicJsonDocument doc(4096);  // Adjust size if response is larger
      DeserializationError error = deserializeJson(doc, payload);
      if (!error) {
        // Navigate JSON (Gemini response)
        const char* text = doc["candidates"][0]["content"]["parts"][0]["text"];
        if (text) {
          Serial.println("\nGemini Says:");
          Serial.println(text);
        } else {
          Serial.println("\nNo valid text response found!");
        }
      } else {
        Serial.print("JSON Parse Error: ");
        Serial.println(error.c_str());
      }

    } else {
      Serial.print("HTTP Request failed, code: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
}
