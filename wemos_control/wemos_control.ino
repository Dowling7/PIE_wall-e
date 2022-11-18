
#define BLYNK_TEMPLATE_ID           "TMPL7_Sb4KxM"
#define BLYNK_DEVICE_NAME           "wifi_control"
#define BLYNK_AUTH_TOKEN            "OCQj4aHTANhMiWt_kaUlWbGlN3D4dSGL"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "OLIN-DEVICES";
char pass[] = "Design&Fabric8";
//char ssid[] = "Verizon_S9YC9F";
//char pass[] = "hearth-gig3-row";


// Joystick Values - Start at 128 (middle position)
int joyposVert = 128;
int joyposHorz = 128;

#define forward D4
#define backward D5
#define left D6
#define right D7


// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V1, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V1, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V1, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

BLYNK_WRITE(V3) {
  const int X_THRESHOLD_LOW = 37; 
  const int X_THRESHOLD_HIGH = 218; 

  const int Y_THRESHOLD_LOW = 37;
  const int Y_THRESHOLD_HIGH = 218;
      
  int x_position = param[0].asInt();  //Read the Blynk Joystick x Position 0-255
  int y_position = param[1].asInt();  //Read the Blynk Joystick y Position 0-255

  int x_direction;  //Variable for Direction of Joystick Movement: x= -1, 0, 1
  int y_direction;  //Variable for Direction of Joystick Movement: y= -1, 0, 1
 
  Serial.print("x_position: ");
  Serial.print(x_position);
  Serial.print("  y_position: ");
  Serial.println(y_position);

//Determine the direction of the Joystick Movement

  x_direction = 0;
  y_direction = 0;
  if (x_position > X_THRESHOLD_HIGH ) {
    x_direction = 1;

  }else if (x_position < X_THRESHOLD_LOW) {
    x_direction = -1;

  }
  if (y_position > Y_THRESHOLD_HIGH) {
    y_direction = 1;

  }else if (y_position < Y_THRESHOLD_LOW) {
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

void loop(){
  Blynk.run();
}
