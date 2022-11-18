int forward = 4;    
int backward = 5;    
int left = 6;    
int right = 7;    

int val1 = 0;      // variable to store the read value
int val2 = 0;
int val3 = 0;
int val4 = 0;



void setup() {
  pinMode(forward, INPUT);    // sets the digital pin 7 as input
  pinMode(backward, INPUT);
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  Serial.begin(9600);
}

void loop() {
  val1 = digitalRead(forward);   // read the input pin
  val2 = digitalRead(backward);
  val3 = digitalRead(left);
  val4 = digitalRead(right);
  Serial.print(val1);
  Serial.print(val2);
  Serial.print(val3);
  Serial.println(val4);

}
