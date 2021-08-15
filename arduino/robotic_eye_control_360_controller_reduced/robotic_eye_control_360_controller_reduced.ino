//#include <Event.h>
//#include <Timer.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
//#ifdef dobogusinclude
//#include <spi4teensy3.h>
//#endif
#include <SPI.h>
#include <XBOXUSB.h>

USB Usb;
XBOXUSB Xbox(&Usb);

#define stickMax 30000 //32767

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//servo information
#define MIN_PULSE_WIDTH       0.35
#define MAX_PULSE_WIDTH       2.15
#define FREQUENCY             50

//servo pins
#define H_EYE_R 0
#define V_EYE_R 1
#define T_LID_R 2
#define B_LID_R 3
#define BROW_1_R 4
#define BROW_2_R 5

#define V_EYE_L 8
#define H_EYE_L 9
#define T_LID_L 10
#define B_LID_L 11
#define BROW_1_L 6
#define BROW_2_L 7

//limits for movments
//------------------------------------right
#define H_EYE_R_MIN 125//210 //right
#define H_EYE_R_MAX 365//385 //left

#define V_EYE_R_MIN 150//140 //up
#define V_EYE_R_MAX 270//230 //down

#define T_LID_R_CENT 163//at center
#define T_LID_R_MIN 210//down
#define T_LID_R_MAX 71//up

#define B_LID_R_CENT 120//at center
#define B_LID_R_MIN 71//up
#define B_LID_R_MAX 193//down

#define BROW_1_R_MIN 320//top
#define BROW_1_R_MAX 440//bottom

#define BROW_2_R_MIN 440//top
#define BROW_2_R_MAX 355//bottom

//-----------------------------------left

#define H_EYE_L_MIN 220//160 //right
#define H_EYE_L_MAX 400//340 //left

#define V_EYE_L_MIN 140 //up
#define V_EYE_L_MAX 360 //down

#define T_LID_L_CENT 380//at center
#define T_LID_L_MIN 310//down
#define T_LID_L_MAX 440//up

#define B_LID_L_CENT 405//at center
#define B_LID_L_MIN 440//up
#define B_LID_L_MAX 340//down

#define BROW_1_L_MIN 440//top
#define BROW_1_L_MAX 310//bottom

#define BROW_2_L_MIN 71//top
#define BROW_2_L_MAX 200//bottom

#define LID_OFFSET_TOP 50+55
#define LID_OFFSET_BOTTOM 50+40

bool demoMode = false;
long blinkTime = 0;
long blinkRand = 0;
long moveTime = 0;
long moveRand = 0;

const int minPulse = (double)MIN_PULSE_WIDTH/((double)1/(double)FREQUENCY*(double)1000)*(double)4095;
const int maxPulse = (double)MAX_PULSE_WIDTH/((double)1/(double)FREQUENCY*(double)1000)*(double)4095;

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);



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
  
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);

  blinkTime = millis();
  blinkRand = random(-1830, 1000);
  moveTime = millis();
  moveRand = random(500, 1500);

  randomSeed(analogRead(0));
  
}


void loop() {
  // put your main code here, to run repeatedly:
  
  int LeftHatXVar = 0;
  int LeftHatYVar = 0;
  bool L3Var = false;
  int LeftTrigVar = 0;
  int RightTrigVar = 0;
  int RightHatXVar = 0;
  int RightHatYVar = 0;

  //int delayAmt = 10;
  
  Usb.Task();
  //delay(delayAmt);
  
  //Xbox.printReport();
  if (Xbox.Xbox360Connected) {
//    if (Xbox.getButtonClick(XBOX)) {
//      demoMode = !demoMode;
//        if(demoMode) Xbox.setLedMode(ROTATING);
//        else Xbox.setLedOn(LED1);
//    }
    
    LeftHatXVar = Xbox.getAnalogHat(LeftHatX);
    LeftHatYVar = Xbox.getAnalogHat(LeftHatY);
    RightHatXVar = Xbox.getAnalogHat(RightHatX);
    RightHatYVar = Xbox.getAnalogHat(RightHatY);
    L3Var = Xbox.getButtonPress(L3);
    LeftTrigVar = Xbox.getButtonPress(L2);
    RightTrigVar = Xbox.getButtonPress(R2);
    //Xbox.getButtonPress(R2);
  }
  else{
    Serial.println("controller fail");
    return;
  }
  
  if(0){//testing mouth movment
    double pulseL = map(LeftHatXVar,-stickMax,stickMax,minPulse,maxPulse);
    pulseL = constrain(pulseL,minPulse,maxPulse);
    
    double pulseR = map(RightHatXVar,-stickMax,stickMax,minPulse,maxPulse);
    pulseR = constrain(pulseR,minPulse,maxPulse);
    
    pwm.setPWM(8, 0, pulseL);
    pwm.setPWM(9, 0, pulseR);
  }
  else if(0){//testing angle limits
    double pulseL = map(LeftHatXVar,-stickMax,stickMax,minPulse,maxPulse);
    pulseL = constrain(pulseL,minPulse,maxPulse);
    
    Serial.println(pulseL);
    
    pwm.setPWM(15, 0, pulseL);
  }
//  else if(demoMode){//demo mode
//
//    if(millis()>moveTime+moveRand || millis() < moveTime){
//      moveTime = millis();
//      moveRand = random(500, 1500);
//      
//      horazontal = random(H_EYE_R_MIN, H_EYE_R_MAX);
//      horazontal = constrain(horazontal,H_EYE_R_MIN,H_EYE_R_MAX);
//      vertical = random(V_EYE_R_MIN, V_EYE_R_MAX);
//      vertical = constrain(vertical,V_EYE_R_MIN,V_EYE_R_MAX);
//    
//      pwm.setPWM(H_EYE_R, 0, horazontal);
//      pwm.setPWM(V_EYE_R, 0, vertical);
//    }
//    
//    //blink
//    if(millis()>blinkTime+5160+blinkRand || millis() < blinkTime){
//      blinkTime = millis();
//      blinkRand = random(-1830, 1000);
//      
//      pwm.setPWM(B_LID_R, 0, B_LID_R_CENT);//bottom
//      pwm.setPWM(T_LID_R, 0, T_LID_R_CENT);//top
//      delay(200);
//    }
//    else{
//      int bottom = map(vertical,((V_EYE_R_MAX-V_EYE_R_MIN)/2)+V_EYE_R_MIN,V_EYE_R_MAX,B_LID_R_MIN+LID_OFFSET_BOTTOM,B_LID_R_MAX);
//      bottom = constrain(bottom,B_LID_R_MIN,B_LID_R_MAX);
//      int top = map(vertical,(-(V_EYE_R_MAX-V_EYE_R_MIN)/2)+V_EYE_R_MAX,V_EYE_R_MIN,T_LID_R_MIN-LID_OFFSET_TOP,T_LID_R_MAX);
//      top = constrain(top,T_LID_R_MAX,T_LID_R_MIN);
//      pwm.setPWM(B_LID_R, 0, bottom);//bottom
//      pwm.setPWM(T_LID_R, 0, top);//top
//    }
//  }
  else {//normal mode
    
    //control eye position
    int horazontal_R = map(LeftHatXVar,stickMax,-stickMax,H_EYE_R_MIN,H_EYE_R_MAX);
    horazontal_R = constrain(horazontal_R,H_EYE_R_MIN,H_EYE_R_MAX);
    int vertical_R = map(LeftHatYVar,-stickMax,stickMax,V_EYE_R_MIN,V_EYE_R_MAX);
    vertical_R = constrain(vertical_R,V_EYE_R_MIN,V_EYE_R_MAX);

    int horazontal_L = map(LeftHatXVar,stickMax,-stickMax,H_EYE_L_MIN,H_EYE_L_MAX);
    horazontal_L = constrain(horazontal_L,H_EYE_L_MIN,H_EYE_L_MAX);
    int vertical_L = map(LeftHatYVar,-stickMax,stickMax,V_EYE_L_MIN,V_EYE_L_MAX);
    vertical_L = constrain(vertical_L,V_EYE_L_MIN,V_EYE_L_MAX);
  
    pwm.setPWM(H_EYE_R, 0, horazontal_R);
    pwm.setPWM(V_EYE_R, 0, vertical_R);

    pwm.setPWM(H_EYE_L, 0, horazontal_L);
    pwm.setPWM(V_EYE_L, 0, vertical_L);
  
    //control eye lid
    //bink every 5.16s +/-1.83
    int bottom_R = 0;
    int top_R = 0;

    int bottom_L = 0;
    int top_L = 0;
    
    if(L3Var){
      bottom_R = B_LID_R_CENT;//bottom
      top_R = T_LID_R_CENT;//top

      bottom_L = B_LID_L_CENT;//bottom
      top_L = T_LID_L_CENT;//top
    }
    else{
      int bottomOffset = map(LeftTrigVar,0,255,LID_OFFSET_BOTTOM,0);
      bottomOffset = bottomOffset + map(RightTrigVar,0,255,0,LID_OFFSET_BOTTOM*0.7);
      bottomOffset = constrain(bottomOffset,0,LID_OFFSET_BOTTOM);
      int topOffset = map(LeftTrigVar,0,255,LID_OFFSET_TOP,0);
      topOffset = topOffset + map(RightTrigVar,0,255,0,LID_OFFSET_TOP*0.7);
      topOffset = constrain(topOffset,0,LID_OFFSET_TOP);
      
      bottom_R = map(vertical_R,((V_EYE_R_MAX-V_EYE_R_MIN)/2)+V_EYE_R_MIN,V_EYE_R_MAX,B_LID_R_MIN+bottomOffset,B_LID_R_MAX);
      bottom_R = constrain(bottom_R,B_LID_R_MIN,B_LID_R_MAX);
      top_R = map(vertical_R,((V_EYE_R_MAX-V_EYE_R_MIN)/2)+V_EYE_R_MIN,V_EYE_R_MIN,T_LID_R_MIN-topOffset,T_LID_R_MAX);
      top_R = constrain(top_R,T_LID_R_MAX,T_LID_R_MIN);
      

      //bottomOffset = constrain(bottomOffset,0,LID_OFFSET_BOTTOM);
      bottom_L = map(vertical_L,((V_EYE_L_MAX-V_EYE_L_MIN)/2)+V_EYE_L_MIN,V_EYE_L_MAX,B_LID_L_MIN+bottomOffset,B_LID_L_MAX);
      bottom_L = constrain(bottom_L,B_LID_L_MIN,B_LID_L_MAX);
      top_L = map(vertical_L,((V_EYE_L_MAX-V_EYE_L_MIN)/2)+V_EYE_L_MIN,V_EYE_L_MIN,T_LID_L_MIN-topOffset,T_LID_L_MAX);
      top_L = constrain(top_L,T_LID_L_MAX,T_LID_L_MIN);
      
      
      int brow1_R = map(bottomOffset,LID_OFFSET_BOTTOM*0.3,LID_OFFSET_BOTTOM*1.7,BROW_1_R_MAX, BROW_1_R_MIN);
      brow1_R = constrain(brow1_R,BROW_1_R_MIN,BROW_1_R_MAX);
      int brow2_R = map(bottomOffset,LID_OFFSET_BOTTOM*0.3,LID_OFFSET_BOTTOM*1.7,BROW_2_R_MAX, BROW_2_R_MIN);
      brow2_R = constrain(brow2_R,BROW_2_R_MAX,BROW_2_R_MIN);

      int brow1_L = map(bottomOffset,LID_OFFSET_BOTTOM*0.3,LID_OFFSET_BOTTOM*1.7,BROW_1_L_MAX, BROW_1_L_MIN);
      brow1_L = constrain(brow1_L,BROW_1_L_MIN,BROW_1_L_MAX);
      int brow2_L = map(bottomOffset,LID_OFFSET_BOTTOM*0.3,LID_OFFSET_BOTTOM*1.7,BROW_2_L_MAX, BROW_2_L_MIN);
      brow2_L = constrain(brow2_L,BROW_2_L_MAX,BROW_2_L_MIN);
      
      pwm.setPWM(BROW_1_R, 0, brow1_R);
      pwm.setPWM(BROW_2_R, 0, brow2_R);
      
      pwm.setPWM(BROW_1_L, 0, brow1_L);
      pwm.setPWM(BROW_2_L, 0, brow2_L);
    }
    pwm.setPWM(B_LID_R, 0, bottom_R);//bottom
    pwm.setPWM(T_LID_R, 0, top_R);//top


  }

  delay(1);
  
}

