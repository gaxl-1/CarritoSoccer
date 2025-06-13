#include <SoftwareSerial.h>
#include <LEANTEC_ControlMotor.h>

SoftwareSerial mySerial(0,1);

char command;

const int ENA = 7;
const int IN1 = 6;
const int IN2 = 5;

const int ENB = 2;
const int IN3 = 4;
const int IN4 = 3;

void setup(){
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("Conectado con Bluetooth");

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop(){
  if(mySerial.available())
  {
    command=(mySerial.read());

    if(command=='B')
    {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(ENA, 255);

      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      digitalWrite(ENB, 255);
    }
    else if(command=='F')
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(ENA, 255);

      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      digitalWrite(ENB, 255);
    }
    else if(command=='L')
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(ENA, 255);

      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      digitalWrite(ENB, 255);  
    }
    else if(command=='R')
    {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(ENA, 255);

      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      digitalWrite(ENB, 255);  
    }
    else if(command=='S')
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);

      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW); 
    }
  }
}
