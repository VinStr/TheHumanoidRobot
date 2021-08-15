#include <Event.h>
#include <Timer.h>

#include <XBOXUSB.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
XBOXUSB Xbox(&Usb);

#define stickMax 30000 //32767

int LeftHatXVar = 0;
int LeftHatYVar = 0;
bool L3Var = false;

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//servo information
#define MIN_PULSE_WIDTH       0.35
#define MAX_PULSE_WIDTH       2.15
#define FREQUENCY             50

//servo pins
#define H_EYE 0
#define V_EYE 1
#define T_LID 3
#define B_LID 2

//limits for movments
#define H_EYE_MIN 75 //left
#define H_EYE_MAX 139 //right
#define V_EYE_MIN 35 //up
#define V_EYE_MAX 108 //down
#define T_LID_MIN 146//at center
#define T_LID_MAX 180
#define B_LID_MIN 46//at center
#define B_LID_MAX 75

#define LID_OFFSET_TOP 55
#define LID_OFFSET_BOTTOM 40

bool demoMode = false;
long blinkTime = 0;
long blinkRand = 0;
long moveTime = 0;
long moveRand = 0;

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

Timer Controllers;
Timer Servos;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  #if !defined(__MIPSEL__)
    while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
  #endif
  if (Usb.Init() == -1) {
    Serial.println(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.println(F("\r\nXBOX USB Library Started"));
  //while(!Xbox.Xbox360Connected){
   // Usb.Task();
    //Serial.println("not connected");
  //}
  
  //pwm.begin();
  //pwm.setPWMFreq(FREQUENCY);

  blinkTime = millis();
  blinkRand = random(-1830, 1000);
  moveTime = millis();
  moveRand = random(500, 1500);

  randomSeed(analogRead(0));
  
  Controllers.every(20, ControllerGet);
  //Servos.every(20, ServoGet);

}

int horazontal = 0;
int vertical = 0;
void loop() {
  // put your main code here, to run repeatedly:
  Controllers.update();
  //Servos.update();
  
}

void ControllerGet(){
  //Xbox.Poll();
  Usb.Task();
  //Xbox.printReport();
  if (Xbox.Xbox360Connected) {
//    if (Xbox.getButtonClick(XBOX)) {
//      demoMode = !demoMode;
//        if(demoMode) Xbox.setLedMode(ROTATING);
//        else Xbox.setLedOn(LED1);
//    }
//    
    LeftHatXVar = Xbox.getAnalogHat(LeftHatX);
//    LeftHatYVar = Xbox.getAnalogHat(LeftHatY);
//    L3Var = Xbox.getButtonPress(L3);
    Serial.println(LeftHatXVar);
  }
  

}

  
void ServoGet(){
  
  if(demoMode){//demo mode

    if(millis()>moveTime+moveRand || millis() < moveTime){
      moveTime = millis();
      moveRand = random(500, 1500);
      
      horazontal = random(H_EYE_MIN, H_EYE_MAX);
      horazontal = constrain(horazontal,H_EYE_MIN,H_EYE_MAX);
      vertical = random(V_EYE_MIN, V_EYE_MAX);
      vertical = constrain(vertical,V_EYE_MIN,V_EYE_MAX);
    
      pwm.setPWM(H_EYE, 0, horazontal);
      pwm.setPWM(V_EYE, 0, vertical);
    }
    
    //blink
    if(millis()>blinkTime+5160+blinkRand || millis() < blinkTime){
      blinkTime = millis();
      blinkRand = random(-1830, 1000);
      
      pwm.setPWM(B_LID, 0, B_LID_MIN);//bottom
      pwm.setPWM(T_LID, 0, T_LID_MIN);//top
      delay(200);
    }
    else{
      int bottom = doubleMap(vertical,((V_EYE_MAX-V_EYE_MIN)/2)+V_EYE_MIN,V_EYE_MAX,B_LID_MIN+LID_OFFSET_BOTTOM,B_LID_MAX);
      bottom = constrain(bottom,B_LID_MIN,B_LID_MAX);
      int top = doubleMap(vertical,((V_EYE_MAX-V_EYE_MIN)/2)+V_EYE_MIN,V_EYE_MIN,T_LID_MIN+LID_OFFSET_TOP,T_LID_MAX);
      top = constrain(top,T_LID_MIN,T_LID_MAX);
      pwm.setPWM(B_LID, 0, Angle2Pulse(bottom));//bottom
      pwm.setPWM(T_LID, 0, Angle2Pulse(top));//top
    }
  }
  
  else if(1){//testing angle limits
    //double angle = doubleMap(LeftHatXVar,-stickMax,stickMax,0,180);
    //angle = constrain(angle,0,180);
    //Serial.println(LeftHatXVar);
    //pwm.setPWM(2, 0, Angle2Pulse(angle));
  }
  
  else if(0){//normal mode
    
    //control eye position
    horazontal = doubleMap(LeftHatXVar,-stickMax,stickMax,H_EYE_MIN,H_EYE_MAX);
    horazontal = constrain(horazontal,H_EYE_MIN,H_EYE_MAX);
    vertical = doubleMap(LeftHatYVar,-stickMax,stickMax,V_EYE_MIN,V_EYE_MAX);
    vertical = constrain(vertical,V_EYE_MIN,V_EYE_MAX);
  
    pwm.setPWM(H_EYE, 0, Angle2Pulse(horazontal));
    pwm.setPWM(V_EYE, 0, Angle2Pulse(vertical));
  
    //control eye lid
    //bink every 5.16s +/-1.83
    int bottom = 0;
    int top = 0;
    if(L3Var){
      bottom = B_LID_MIN;//bottom
      top = T_LID_MIN;//top
    }
    else{
      bottom = map(vertical,((V_EYE_MAX-V_EYE_MIN)/2)+V_EYE_MIN,V_EYE_MAX,B_LID_MIN+LID_OFFSET_BOTTOM,B_LID_MAX);
      bottom = constrain(bottom,B_LID_MIN,B_LID_MAX);
      top = map(vertical,((V_EYE_MAX-V_EYE_MIN)/2)+V_EYE_MIN,V_EYE_MIN,T_LID_MIN+LID_OFFSET_TOP,T_LID_MAX);
      top = constrain(top,T_LID_MIN,T_LID_MAX);
    }
    pwm.setPWM(B_LID, 0, bottom);//bottom
    pwm.setPWM(T_LID, 0, top);//top
  }

  delay(10);
  
}

//convert angle to intager pulse length
int Angle2Pulse(double Angle){
  double minPulse = (double)MIN_PULSE_WIDTH/((double)1/(double)FREQUENCY*(double)1000)*(double)4095;
  double maxPulse = (double)MAX_PULSE_WIDTH/((double)1/(double)FREQUENCY*(double)1000)*(double)4095;

  int Pulse = doubleMap(Angle,0,180,minPulse,maxPulse);
  Pulse = constrain(Pulse,minPulse,maxPulse);
  
  return Pulse;
}

//map function that works with doubles
double doubleMap(double x, double in_min, double in_max, double out_min, double out_max){
  double temp = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
 
  return (double) temp;
}

