#include<TimerOne.h>

unsigned int counter=0;

int in1 =5;
int in2 = 6;

void docount()
{
  counter++;
}

void timerIsr()
{
    Timer1.detachInterrupt();
    Serial.print("Motor Speed: ");
    int rotation = (counter/20);
    Serial.print(rotation,DEC);
    Serial.println("Rotation per seconds");
    counter=0;
    Timer1.attachInterrupt(timerIsr);
}

void setup()
{
  Serial.begin(9600);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  Timer1.initialize(1000000);
  attachInterrupt(0, docount, RISING);
  Timer1.attachInterrupt(timerIsr);
}

void loop()
{
  int potvalue = analogRead(1);
  int motorspeed = map(potvalue,0,680,255,0);
  analogWrite(in1,motorspeed);
  digitalWrite(in2,LOW);
}
