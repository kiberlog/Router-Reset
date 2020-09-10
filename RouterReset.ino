#include <ESP8266Ping.h>
const int output4 = 14;
const char* ssid         = "ssid";
const char* password     = "password";
const char* remote_host  = "www.yandex.ru";

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(output4, OUTPUT);
  Serial.begin(115200);
}

void loop() 
{ 
  digitalWrite(output4, LOW);
  Serial.println();
  Serial.println("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
    {
    Serial.print(".");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    }
 Serial.println();
 Serial.print("WiFi connected with ip ");  
 Serial.println(WiFi.localIP());
 Serial.print("Pinging host ");
 Serial.println(remote_host);
 delay(50000);
 if(Ping.ping(remote_host)) //пингуем хост
  {
  Serial.println("Success!!");
  digitalWrite(output4, LOW);
  delay(300000);
  }
  else {
   Serial.println("Error :("); 
   digitalWrite(output4, HIGH);
   delay(5000);
       }
}
