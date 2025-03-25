void setup() {
  // put your setup code here, to run once:
  pinMode(A0, OUTPUT); 
  pinMode(A1, OUTPUT); 

  pinMode(13, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(A0, 1);
   digitalWrite(A1, 1);
  digitalWrite(13, 1);
  delay(1000); 
  digitalWrite(A0, 0); 
   digitalWrite(A1, 0);
  digitalWrite(13, 0);
  delay(1000); 
}
