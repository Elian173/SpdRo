void setup() {
  serial.begin(9600)
  pinMode(A0, INPUT)
  
}
int n=0;
void loop() {

  n = analogRead(A0);
  Serial.println(n);
  
}
