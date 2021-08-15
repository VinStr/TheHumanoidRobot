#include <XBOXUSB.h>
// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
XBOXUSB Xbox(&Usb);

#define baudRate              115200
#define stickMax              30000 //32767
#define maxin                 1000

  int LeftHatXVar = 0;
  int LeftHatYVar = 0;
  int RightHatXVar = 0;
  int RightHatYVar = 0;
  
  int LeftTrigVar = 0;
  int RightTrigVar = 0;
  
  bool L3Var = false;
  bool R3Var = false;

  bool L1Var = false;
  bool R1Var = false;



void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(baudRate);

  while (!Serial); 
  if (Usb.Init() == -1) {
    while (1); //halt
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));

   Usb.Task();
  if (Xbox.Xbox360Connected) {
    setNsend(RightTrigVar, Xbox.getButtonPress(R2), 0, 255, 'T');
    setNsend(LeftTrigVar, Xbox.getButtonPress(L2), 0, 255, 't');
    
    setNsend(LeftHatXVar, Xbox.getAnalogHat(LeftHatX), -stickMax, stickMax, 'l');
    setNsend(LeftHatYVar, Xbox.getAnalogHat(LeftHatY), -stickMax, stickMax, 'L');
    setNsend(RightHatXVar, Xbox.getAnalogHat(RightHatX), -stickMax, stickMax, 'r');
    setNsend(RightHatYVar, Xbox.getAnalogHat(RightHatY), -stickMax, stickMax, 'R');
    
    if (Xbox.getButtonClick(UP)) {}
    if (Xbox.getButtonClick(DOWN)) {}
    if (Xbox.getButtonClick(LEFT)) {}
    if (Xbox.getButtonClick(RIGHT)) {}

    if (Xbox.getButtonClick(START)) {}
    if (Xbox.getButtonClick(BACK)) {}
    setNsend(L3Var, Xbox.getButtonPress(L3), '3');
    setNsend(R3Var, Xbox.getButtonPress(R3), '£');

    setNsend(L1Var, Xbox.getButtonPress(L1), '1');
    setNsend(R1Var, Xbox.getButtonPress(R1), '!');
    if (Xbox.getButtonClick(XBOX)) {}

    if (Xbox.getButtonClick(A)){}
    if (Xbox.getButtonClick(B)){}
    if (Xbox.getButtonClick(X)){}
    if (Xbox.getButtonClick(Y)){}
  }
  delay(1);

}

void setNsend(int &var, int comp , int valMin, int valMax, char ident){
  if (map(comp,valMin,valMax,0,maxin) != var) {
      var = map(comp,valMin,valMax,0,maxin);
      var = constrain(var,0,maxin);
      Serial.print(ident);
      Serial.println(var);
      }
}

void setNsend(bool &var, int comp, char ident){
  if (comp != var) {
      var = comp;
      Serial.print(ident);
      Serial.println(var);
      }
}

void serialFlush(){
  while(Serial.available() > 0) {
    char t = Serial.read();
  }
}
