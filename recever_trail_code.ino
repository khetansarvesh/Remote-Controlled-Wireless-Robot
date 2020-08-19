#include <SPI.h>

#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

const int mrp1=10;
const int mrp2=9;
const int mlp1=5;
const int mlp2=3;
int z,y;
int data[2];
RF24 radio(7,2);

const uint64_t pipe=0xE8E8F0F0E1B4;

void setup() {
  // put your setup code here, to run once:

pinMode(mrp1,OUTPUT);

pinMode(mrp2,OUTPUT);

pinMode(mlp1,OUTPUT);

pinMode(mlp2,OUTPUT);
Serial.begin(9600);
radio.begin();
radio.setChannel(76);
radio.openReadingPipe(1,pipe);
radio.startListening();
radio.setPALevel(RF24_PA_MIN);

}

void loop() {
  // put your main code here, to run repeatedly:
if(radio.available())
{
  radio.read(data, sizeof(data));
 /* Serial.print("data[0]=");
  Serial.println(data[0]);
  Serial.print("data[1]=");
  Serial.println(data[1]);
*/
  z=data[0];
  y=data[1];
  
}

if(y<370 && y>330 && z<380 && z>335) // netural for y
{
  Serial.println("speed 0");
  digitalWrite(mrp1,HIGH);
  digitalWrite(mrp2,HIGH);
  digitalWrite(mlp1,HIGH);
  digitalWrite(mlp2,HIGH);
  
  
}
if(y>370 && y<430) // upper for y
{
Serial.println(" speed +");
digitalWrite(mrp1,LOW);
  digitalWrite(mrp2,HIGH);
  digitalWrite(mlp1,HIGH);
  digitalWrite(mlp2,LOW);
 
}   
if(y>277 && y<330) // lower for y
{
 Serial.println(" speed -");
digitalWrite(mrp1,HIGH);
  digitalWrite(mrp2,LOW);
  digitalWrite(mlp1,LOW);
  digitalWrite(mlp2,HIGH);
  
  }

if(z>380)// left for z
{
  Serial.println("leftside ");
  digitalWrite(mrp1,LOW);
  digitalWrite(mrp2,HIGH);
  digitalWrite(mlp1,HIGH);
  digitalWrite(mlp2,HIGH);

}

if(z<335) // right for z 
{
 Serial.println("rightside");
digitalWrite(mrp1,HIGH);
  digitalWrite(mrp2,HIGH);
  digitalWrite(mlp1,HIGH);
  digitalWrite(mlp2,LOW);

}

  

}
