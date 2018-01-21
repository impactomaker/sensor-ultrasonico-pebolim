
#include <Ultrasonic.h>

#define TRIGGER_PIN_A  4
#define ECHO_PIN_A     5

#define TRIGGER_PIN_B  10
#define ECHO_PIN_B     11

int led_A=7;
int led_B=9;

Ultrasonic ultrasonicGol_A(TRIGGER_PIN_A, ECHO_PIN_A);
Ultrasonic ultrasonicGol_B(TRIGGER_PIN_B, ECHO_PIN_B);

void setup()
{
  Serial.begin(9600);
  pinMode(led_A, OUTPUT);
  pinMode(led_B, OUTPUT);
}

float getGol_B(){
  float cmMsec;
  long microsec = ultrasonicGol_B.timing();

  cmMsec = ultrasonicGol_B.convert(microsec, Ultrasonic::CM);

  return cmMsec;
}

float getGol_A(){
  float cmMsec;
  long microsec = ultrasonicGol_A.timing();

  cmMsec = ultrasonicGol_A.convert(microsec, Ultrasonic::CM);

  return cmMsec;
}

void Gol_A(){
  Serial.println("A->");
  Serial.println(getGol_A());
  if(getGol_A()>7){
    digitalWrite(led_A, HIGH);  

  }
  else{
    digitalWrite(led_A, LOW);
  }

}

void Gol_B(){
  Serial.println("B->");
  Serial.println(getGol_B());
  if(getGol_B()>7){
    digitalWrite(led_B, HIGH);  

  }
  else{
    digitalWrite(led_B, LOW);
  }

}

void loop()
{

  Gol_A();
  Gol_B();

}
