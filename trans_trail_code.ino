#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

const int zout = A5; // communication with ADXL
const int yout = A7;
int out1=0;
int out2=0;
int data[2];
int z,y;// packet for data from x and y

RF24 radio(7,8);

const uint64_t pipe = 0xE8E8F0F0E1B4;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
radio.begin();
radio.openWritingPipe(pipe);
radio.setChannel(76);
radio.setPALevel(RF24_PA_MIN);

//pinMode(A5,INPUT);
//pinMode(A7,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
z= analogRead(zout);
y= analogRead(yout);
Serial.print("z=");
Serial.println(z);
Serial.print("y=");
Serial.println(y);
data[0]= z;
data[1]= y;
radio.write(data,sizeof(data));





}
