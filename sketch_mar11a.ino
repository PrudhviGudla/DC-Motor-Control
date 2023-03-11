
#include <util/atomic.h> // For the ATOMIC_BLOCK macro

#define ENC 2 // YELLOW
//#define ENCB 3 // WHITE
//#define PWM 5
#define IN2 5
#define IN1 6

volatile int posi = 0; // specify posi as volatile: https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/

void setup() {
  Serial.begin(9600);
  pinMode(ENC,INPUT);
  //pinMode(ENCB,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENC),readEncoder,RISING);
  
  //pinMode(PWM,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
}

void loop() {
  
  // Read the position in an atomic block to avoid a potential
  // misread if the interrupt coincides with this code running
  // see: https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/
  int pos = 0; 
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    pos = posi;
  }

  setMotor(1, 100, IN1, IN2);
  delay(200);
  Serial.println(pos);
  /*setMotor(-1, 25, IN1, IN2);
  delay(200);
  Serial.println(pos);
  setMotor(0, 25, IN1, IN2);
  delay(20);
  Serial.println(pos);*/
}

void setMotor(int dir, int pwmVal, int in1, int in2){
  /*analogWrite(pwm,pwmVal);
  if(dir == 1){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }
  else if(dir == -1){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
  }
  else{
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
  }*/
  if(dir == 1)
  {
    analogWrite(in1,pwmVal);
    digitalWrite(in2,LOW);
  }
  else if(dir ==-1)
  {
    analogWrite(in2,pwmVal);
    digitalWrite(in1,LOW);
  }
  else
  {
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
  }
}

void readEncoder(){
  /*int b = digitalRead(ENCB);
  if(b > 0){
    posi++;
  }
  else{
    posi--;
  }*/
  posi++;
}