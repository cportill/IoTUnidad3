#include <IRremote.h>
#include <Servo.h>
int receptor = 13;
int led1 = 12;
int led2 = 10;
int led3 = 9;
int cortina = 8;
Servo myservo;
 
IRrecv irrecv(receptor);
decode_results codigo; //OBJETO CODIGO DE CLASE decode_result, oriundo de IRremote.h
 
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // INICIA LA RECEPCIÓN
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(cortina, OUTPUT);
  myservo.attach(7);
}
 
void loop()
{
 if (irrecv.decode(&codigo))
 {
Serial.println(codigo.value, HEX);

      if (codigo.value==0x7070807F)//1
      {
         digitalWrite(led1,HIGH);
      }

      if (codigo.value==0x707040BF)//2
      {
         digitalWrite(led1,LOW);
      }
////////////////////////////
      if (codigo.value==0x7070C03F)//3
      {
         digitalWrite(led2,HIGH);
      }

      if (codigo.value==0x707020DF)//4
      {
         digitalWrite(led2,LOW);
      }
 /////////////////////////////
      if (codigo.value==0x7070A05F)//5
      {
         digitalWrite(led3,HIGH);
      }

      if (codigo.value==0x7070609F)//6
      {
         digitalWrite(led3,LOW);
      }
///////////////////////
      if (codigo.value==0x7070E01F)//7
      {
         digitalWrite(cortina,HIGH);
      }

      if (codigo.value==0x707010EF)//8
      {
         digitalWrite(cortina,LOW);
      }
/////////////////
      if (codigo.value==0x7070906F)//9
      {
        myservo.write(0);
        delay(15);
      }

      if (codigo.value==0x707000FF)//0
      {
        myservo.write(90);
      }
delay(500);
irrecv.resume();

 }
}
