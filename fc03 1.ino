#define LED1 13
#define M1_SENS 2
#define M1_INT 0

volatile int count1 = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Start");
  pinMode(LED1, OUTPUT);
  pinMode(M1_SENS, INPUT);
  attachInterrupt(M1_INT, motorStep1, RISING);
}  

void loop() {  
  /*if ( count1 >= 20 ) {
    digitalWrite(LED1, !digitalRead(LED1));
    count1 = 0;
  }*/
}

void motorStep1()
{
  count1++;
  Serial.println(count1);
}