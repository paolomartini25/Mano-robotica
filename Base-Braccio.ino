// diritti riservati a Zizou.tm

#include <Servo.h>
#define POTENZIOMETRO A0
#define POTENZIOMETRO2 A1

int aGomito = 0; //angolatura motore
int aBase = 0; //angolatura motore
int aPollice = 0; //angolatura motore
int val; //valore in input del potenziometro
int val2; //valore in input del potenziometro

Servo gomito1;
Servo gomito2;
Servo base;


int potenziometroToangolo(int valore);

void setup()
{
  pinMode(POTENZIOMETRO, INPUT);
  pinMode(POTENZIOMETRO2, INPUT);
  gomito1.attach( 9, 500, 2500);
  gomito2.attach( 10, 500, 2500);
  base.attach( 11, 500, 2500);
  Serial.begin(9600);
}

void loop()
{
  
  val = analogRead(POTENZIOMETRO);
  val2 = analogRead(POTENZIOMETRO2);
  aGomito = potenziometroToangolo(val);
  gomito1.write(179-aGomito);
  gomito2.write(aGomito);
  aBase = potenziometroToangolo(val2);
  base.write(aBase);
  
}

int potenziometroToangolo(int valore){
  int angolo = map(valore, 0, 1023, 0, 179);
  Serial.print("analog: ");
  Serial.println(valore);
  Serial.print("angolo: ");
  Serial.println(angolo);
  return angolo;
  
}
