//credit 
//  https://github.com/mobizt/Firebase-ESP8266
//  https://akexorcist.dev/firebase-and-esp8266-with-arduino/

#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

FirebaseData firebaseData;

double X = 0;
double Y = 1;
double Z = 2;
double RX = 3;
double RY = 4;
double RZ = 5;
bool Light = false ;

void setup(){
    WiFiConnection();
}

void loop(){

  FirebaseJson data;
  data.set("Read/X", X);
  data.set("Write/X", X+1);
  data.set("Light", Light);
  
  if(Firebase.set(firebaseData,"/number", data)){
    Serial.println("Added"); 
  } else {
    Serial.println("Error : " + firebaseData.errorReason());
  }
  delay(10000);
}

void WiFiConnection(){
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("connect : ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
