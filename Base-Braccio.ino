// diritti riservati a Zizou®

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


int potenziometroToangolo(int valore); //quaesta funzione serve per trasformare il valore letto dal potenziometro in un angolo comtreso tra 0 e 179 gradi.

void setup()
{
  pinMode(POTENZIOMETRO, INPUT); //imposto il pin A0 come input
  pinMode(POTENZIOMETRO2, INPUT); //imposto il pin A1 come input
  gomito1.attach( 9, 500, 2500); 
  gomito2.attach( 10, 500, 2500);
  base.attach( 11, 500, 2500);
  Serial.begin(9600);
}

void loop()
{
  
  val = analogRead(POTENZIOMETRO); //leggo il valore della tensione sul pin A0 e lo salvo in val
  val2 = analogRead(POTENZIOMETRO2); //leggo il valore della tensione sul pin A1 e lo salvo in val2
  
  aGomito = potenziometroToangolo(val); //il valore letto dal potenziometro1 viene trasformato in un angolo e salvato nella variabile aGomito
  //gomito1 e gomito2 si muovono in seno opposto
  gomito1.write(179-aGomito);
  gomito2.write(aGomito);
  
  aBase = potenziometroToangolo(val2); //il valore letto dal potenziometro2 viene trasformato in un angolo e salvato nella variabile aBase
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
