#include <Arduino.h>

HardwareSerial myS(PA15, PB6); //rx tx
void setup() {
  pinMode(PB0, INPUT); //GP4
  pinMode(PB1, INPUT); //GP5
  pinMode(PB7, INPUT); //GP6
  pinMode(PA12, INPUT);//GP7
  pinMode(PB4, OUTPUT); //RBG_R 
  pinMode(PA8, OUTPUT); //RGB_G
  pinMode(PA11, OUTPUT); //RGB_B
  pinMode(PA0, INPUT_ANALOG); //A1
  pinMode(PA1, INPUT_ANALOG); //A2
  pinMode(PA2, INPUT_ANALOG); //A3
  pinMode(PA3, INPUT_ANALOG); //A4
  myS.begin(115200);
}
long joy[4] = {0,0,0,0};

void loop() {
  myS.println("Hello");
  joy[0] = analogRead(PA0);
  joy[1] = analogRead(PA1);
  joy[2] = analogRead(PA2);
  joy[3] = analogRead(PA3);
  myS.printf("%d,%d,%d,%d\r\n",joy[0],joy[1],joy[2],joy[3]);
  delay(1000);
}

