#define ENC 2 // Yellow
//#define ENCB 3 // White

void setup() {
  Serial.begin(9600);
  pinMode(ENC,INPUT);
  //pinMode(ENCB,INPUT);
}

void loop() {
  int a = digitalRead(ENC);
  //int b = digitalRead(ENCB);
  Serial.print(a*5); 
  //Serial.print(" ");
  //Serial.print(b*5);
  Serial.println();
}