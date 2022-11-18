int forward = 4;    
int backward = 4;    
int left = 4;    
int right = 4;    

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
  Serial.print(val4);

}
