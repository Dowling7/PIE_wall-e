#define BLYNK_TEMPLATE_ID           "TMPL7_Sb4KxM"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "ZQdMLgYjtbbW9l2bxyGGxyto7fuZJHjv"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "OLIN-DEVICES";
char pass[] = "Design&Fabric8";
const int forward = 4;
const int backward = 5;
const int left = 13;
const int right = 14;
const int THRESHOLD_LOW = 37; 
const int THRESHOLD_HIGH = 218;  




BLYNK_WRITE(V3) {
      
  int x_position = param[0].asInt();  
  int y_position = param[1].asInt();  
  int x_direction;  
  int y_direction;  
  Serial.print("x_position: ");
  Serial.print(x_position);
  Serial.print("  y_position: ");
  Serial.println(y_position);


  x_direction = 0;
  y_direction = 0;
  if (x_position > THRESHOLD_HIGH ) {
    x_direction = 1;

  }else if (x_position < THRESHOLD_LOW) {
    x_direction = -1;

  }
  if (y_position > THRESHOLD_HIGH) {
    y_direction = 1;

  }else if (y_position < THRESHOLD_LOW) {
    y_direction = -1;

  } 
  
  Serial.print(x_direction);
  Serial.println(y_direction);
  if(x_direction==0 && y_direction==0){
    //stop
    digitalWrite(forward,LOW);
    digitalWrite(backward,LOW);
    digitalWrite(left,LOW);
    digitalWrite(right,LOW); 
  }else if (x_direction==0 && y_direction>0){
    //forward
    digitalWrite(forward,HIGH);
    digitalWrite(backward,LOW);
    digitalWrite(left,LOW);
    digitalWrite(right,LOW); 
  }else if (x_direction==0 && y_direction<0){
    //backward
    digitalWrite(forward,LOW);
    digitalWrite(backward,HIGH);
    digitalWrite(left,LOW);
    digitalWrite(right,LOW); 
  }else if (x_direction<0 && y_direction==0){
    //left
    digitalWrite(forward,LOW);
    digitalWrite(backward,LOW);
    digitalWrite(left,HIGH);
    digitalWrite(right,LOW); 
  }else if (x_direction>0 && y_direction==0){
    //right
    digitalWrite(forward,LOW);
    digitalWrite(backward,LOW);
    digitalWrite(left,LOW);
    digitalWrite(right,HIGH); 
  }
  
}


void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(right, OUTPUT);
  
}

void loop()
{
  Blynk.run();
}
