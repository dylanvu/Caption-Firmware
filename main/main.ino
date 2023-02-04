#include <WiFi.h>
#include <HTTPClient.h>

// Your Domain name with URL path or IP address with path
//String serverName = "https://2ec9-128-195-97-245.ngrok.io/";
//String serverName = "https://www.google.com/";


void createGetReq()
{
    Serial.print("Sending Request: \n");
  // followed this tutorial: https://randomnerdtutorials.com/esp32-http-get-post-arduino/
  HTTPClient http;

  String serverPath = serverName;

  http.begin(serverPath.c_str());

  // add headers
  http.addHeader("ngrok-skip-browser-warning", "123");

  // Send HTTP GET request
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0)
  {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.println(payload);
  }
  else
  {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();
  return;
}

void wifiSetup()
{
  WiFi.mode(WIFI_STA);
  const char *ssid = "Dylan-iPhone";
  const char *password = "Goanteaters!";

  Serial.print("ESP32 Mac Address: \n");
  Serial.println(WiFi.macAddress());

  WiFi.begin(ssid, password);
  Serial.println("\nConnecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(100);
  }

  Serial.println("\nConnected to the WiFi network");
  Serial.print("Local ESP32 IP: ");
  Serial.println(WiFi.localIP());
}

// <----- main arduino code ------>
void setup()
{
  Serial.begin(115200);
  wifiSetup();
}

void loop()
{
  createGetReq();
  delay(1000);
  // put your main code here, to run repeatedly:
}
