#include<FirebaseArduino.h>
#include<ESP8266WiFi.h>

#define WIFI_SSID "Ashish"
#define WIFI_PASSWORD "12345678"
#define FIREBASE_HOST "nodemcu-d2c8b.firebaseio.com"
#define FIREBASE_AUTH "u47kS858cHAjp3Xu7qu8WyyAAY5gfre3jyHojKUI"

int ledPower=5;

void setup() {
  // put your setup code here, to run once:
 
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
    }
    Serial.println();
    Serial.print("Connected");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(ledPower,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ledStatus= Firebase.getInt("ledStatus");
  Serial.println(ledStatus);
  if(ledStatus == 1){
    digitalWrite(ledPower, HIGH);
    }
    else{
      digitalWrite(ledPower, LOW);
      }
}
