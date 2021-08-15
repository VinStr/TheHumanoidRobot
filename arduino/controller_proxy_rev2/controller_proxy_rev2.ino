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
#define maxin                 1024
#define minin                 1

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

  bool up = false;
  bool down = false;
  bool left = false;
  bool right = false;

  bool start = false;
  bool back = false;
  bool xbox = false;

  bool a = false;
  bool b = false;
  bool x = false;
  bool y = false;

  bool change = false;

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
    setNsend(RightTrigVar, Xbox.getButtonPress(R2), 0, 255);
    setNsend(LeftTrigVar, Xbox.getButtonPress(L2), 0, 255);
    
    setNsend(LeftHatXVar, Xbox.getAnalogHat(LeftHatX), -stickMax, stickMax);
    setNsend(LeftHatYVar, Xbox.getAnalogHat(LeftHatY), -stickMax, stickMax);
    setNsend(RightHatXVar, Xbox.getAnalogHat(RightHatX), -stickMax, stickMax);
    setNsend(RightHatYVar, Xbox.getAnalogHat(RightHatY), -stickMax, stickMax);
    
    setNsend(up, Xbox.getButtonPress(UP));
    setNsend(down, Xbox.getButtonPress(DOWN));
    setNsend(left, Xbox.getButtonPress(LEFT));
    setNsend(right, Xbox.getButtonPress(RIGHT));

    setNsend(start, Xbox.getButtonPress(START));
    setNsend(back, Xbox.getButtonPress(BACK));
    setNsend(L3Var, Xbox.getButtonPress(L3));
    setNsend(R3Var, Xbox.getButtonPress(R3));

    setNsend(L1Var, Xbox.getButtonPress(L1));
    setNsend(R1Var, Xbox.getButtonPress(R1));
    setNsend(xbox, Xbox.getButtonPress(XBOX));

    setNsend(a, Xbox.getButtonPress(A));
    setNsend(b, Xbox.getButtonPress(B));
    setNsend(x, Xbox.getButtonPress(X));
    setNsend(y, Xbox.getButtonPress(Y));

    if (change){
      printNum(LeftHatXVar);
      printNum(LeftHatYVar);
      
      printNum(RightHatXVar);
      printNum(RightHatYVar);
      
      printNum(LeftTrigVar);
      printNum(RightTrigVar);

      int Expression = 0;
      if(a==1) Expression = 1;
      else if(b==1) Expression = 2;
      else if(x==1) Expression = 3;
      else if(y==1) Expression = 4;
      padding(Expression,2);

      printNumBool(L3Var);
      printNumBool(R3Var);

      printNumBool(L1Var);
      printNumBool(R1Var);

      printNumBool(up);
      printNumBool(down);
      printNumBool(left);
      printNumBool(right);

      printNumBool(start);
      printNumBool(back);
      printNumBool(xbox);

      
      
      Serial.println();
      change = false;
    }
  }
  delay(1);

}

void setNsend(int &var, int comp , int valMin, int valMax){
  int temp = map(comp,valMin,valMax,minin,maxin);
  temp = constrain(temp,minin,maxin);
  if ( temp != var) {
      var = temp;
      change = true;
      }
}

void setNsend(bool &var, int comp){
  if (comp != var) {
      var = comp;
      change = true;
      }
}

void printNum(int val){
      char temp[4];
      sprintf(temp,"%04d",val);
      Serial.print(temp);
}


void printNumShort(int val){
      char temp[4];
      sprintf(temp,"%04d",val);
      Serial.print(temp);
}

void padding( int number, byte width ) {
  int currentMax = 10;
  for (byte i=1; i<width; i++){
    if (number < currentMax) {
      Serial.print("0");
    }
    currentMax *= 10;
  }
  Serial.print(number);
}

void printNumBool(bool val){
      if(val==1) Serial.print(7);
      else Serial.print(3);
}

void serialFlush(){
  while(Serial.available() > 0) {
    char t = Serial.read();
  }
}
