
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
 
#define FIREBASE_HOST "" // Firebase host
#define FIREBASE_AUTH "" //Firebase Auth code
#define WIFI_SSID "" //Enter your wifi Name
#define WIFI_PASSWORD "" // Enter your password
int ledPin= 16;
int ledPin1=04;
int ledPin2=14;
int fireStatus0 = 0;
int fireStatus1 = 0;
int fireStatus2 = 0;



 
void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println();
  Serial.println("Connected.");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  //Firebase.set("LED_STATUS", 0);
  //Firebase.set("LED_STATUS1",0);
 
}
 
void loop() {
  

  fireStatus0 = Firebase.getInt("LED_STATUS");
    if (fireStatus0 == 1) {
      Serial.println("Led 1 Turned ON");
      digitalWrite(ledPin,HIGH);
      
      
    }
    else if (fireStatus0 == 0) {
      Serial.println("Led 1 Turned OFF");
      digitalWrite(ledPin,LOW);
     
    }
    else {
      Serial.println("Command Error! Please send 0/1");
    }
  
  
  fireStatus1 = Firebase.getInt("LED_STATUS1");
    if(fireStatus1 == 1){
        Serial.println("LED 2 TURNED ON");
        digitalWrite(ledPin1,HIGH);
        
    }
    else if(fireStatus1 == 0){
        Serial.println("LED 2 TURNED OFF");
        digitalWrite(ledPin1,LOW);
       
    }
    else {
      Serial.println("Command Error! Please send 0/1");
    }

    fireStatus2 = Firebase.getInt("LED_STATUS2");
    if(fireStatus2 == 1){
        Serial.println("LED 3 TURNED ON");
        digitalWrite(ledPin2,HIGH);
        
    }
    else if(fireStatus2 == 0){
        Serial.println("LED 3 TURNED OFF");
        digitalWrite(ledPin2,LOW);
        
    }
    else {
      Serial.println("Command Error! Please send 0/1");
    }
  
  delay(500);
} 
