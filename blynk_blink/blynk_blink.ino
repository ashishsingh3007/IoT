void setup() {
  pinMode(D0,OUTPUT);
  pinMode(D7,OUTPUT);
  
}

void loop() {
  digitalWrite(D0,1);
  delay(100);
 
   digitalWrite(D7,1);
  delay(300);
  digitalWrite(D7,0);
  delay(300);
   digitalWrite(D0,0);
  delay(100);
}
