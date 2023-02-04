#include <WiFi.h>
#include <HTTPClient.h>

void wifiSetup()
{
  WiFi.mode(WIFI_STA);
  const char *ssid = "HACK";
  const char *password = "Goanteaters!";

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

void setup()
{
  Serial.begin(115200);
  wifiSetup();
}

void loop()
{
  // put your main code here, to run repeatedly:
}
