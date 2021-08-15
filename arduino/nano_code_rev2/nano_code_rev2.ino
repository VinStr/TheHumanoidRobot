
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "Definitions.h"

#define MIN_PULSE_WIDTH       0.35
#define MAX_PULSE_WIDTH       2.15
#define FREQUENCY             50
#define maxin                 1000
#define minin                 0

const int minPulse = (double)MIN_PULSE_WIDTH/((double)1/(double)FREQUENCY*(double)1000)*(double)4095;
const int maxPulse = (double)MAX_PULSE_WIDTH/((double)1/(double)FREQUENCY*(double)1000)*(double)4095;
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDriver(0x41);

long blinkTime = 0;
long blinkRand = 0;
long moveTime = 0;
long moveRand = 0;

#define baudRate              115200

String inputString = "";         // a String to hold incoming data
boolean stringComplete = false;  // whether the string is complete

  int LeftHatXVar = 500;
  int LeftHatYVar = 500;
  int RightHatXVar = 500;
  int RightHatYVar = 500;
  
  int LeftTrigVar = 1;
  int RightTrigVar = 1;
  
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

void setup() {
  // put your setup code here, to run once:

  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(baudRate);
  
  while (!Serial);

  pwm.begin();
  delay(100);
  //pwm.setPWMFreq(FREQUENCY);
  //pwm1.begin();
  //pwm1.setPWMFreq(FREQUENCY);
  

  //blinkTime = millis();
  //blinkRand = random(-1830, 1000);
  //moveTime = millis();
  //moveRand = random(500, 1500);

  //randomSeed(analogRead(0));

}

bool errorFlag = false;

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
  //Servos.update();
  
    if (stringComplete) {
      
        errorFlag = false;
        
        LeftHatXVar = inputString.substring(0,4).toInt();
        if(LeftHatXVar==0 || LeftHatXVar>maxin)errorFlag = true;
        if(!errorFlag)LeftHatYVar = inputString.substring(4,8).toInt();
        if(LeftHatYVar==0 || LeftHatYVar>maxin)errorFlag = true;
        
        if(!errorFlag)RightHatXVar = inputString.substring(8,12).toInt();
        if(RightHatXVar==0 || RightHatXVar>maxin)errorFlag = true;
        if(!errorFlag)RightHatYVar = inputString.substring(12,16).toInt();
        if(RightHatYVar==0 || RightHatYVar>maxin)errorFlag = true;
        
        if(!errorFlag)LeftTrigVar = inputString.substring(16,20).toInt();
        if(LeftTrigVar==0 || LeftTrigVar>maxin)errorFlag = true;
        if(!errorFlag)RightTrigVar = inputString.substring(20,24).toInt();
        if(RightTrigVar==0 || RightTrigVar>maxin)errorFlag = true;

        

        decodeBool(inputString.charAt(24) - '0',L3Var);
        decodeBool(inputString.charAt(25) - '0',R3Var);

        decodeBool(inputString.charAt(26) - '0',L1Var);
        decodeBool(inputString.charAt(27) - '0',R1Var);

        decodeBool(inputString.charAt(28) - '0',up);
        decodeBool(inputString.charAt(29) - '0',down);
        decodeBool(inputString.charAt(30) - '0',left);
        decodeBool(inputString.charAt(31) - '0',right);

        decodeBool(inputString.charAt(32) - '0',start);
        decodeBool(inputString.charAt(33) - '0',back);
        decodeBool(inputString.charAt(34) - '0',xbox);

        decodeBool(inputString.charAt(35) - '0',a);
        decodeBool(inputString.charAt(36) - '0',b);
        decodeBool(inputString.charAt(37) - '0',x);
        decodeBool(inputString.charAt(38) - '0',y);
        
        //clear the string:
        inputString = "";
        stringComplete = false;
        
        driveServos();
    }
}

void printNum(int val){
      char temp[4];
      sprintf(temp,"%04d",val);
      Serial.print(temp);
}

void decodeBool(int val, bool &var){
  if(errorFlag)return;
  else if(val == 7)var = true;
  else if(val == 3) var = false;
  else errorFlag = true;
  return;
}

void serialEvent() {
  //digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      if(stringComplete || inputString.length() < 40){
        inputString = "";
      }
      else{
        stringComplete = true;
      }
    }
  }
}


//------------------------------------------------------------------------
void driveServos(){
  //digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
  
  if(0){//testing mouth movment
    double pulseL = map(LeftHatXVar,minin,maxin,minPulse,maxPulse);
    pulseL = constrain(pulseL,minPulse,maxPulse);
    
    double pulseR = map(RightHatXVar,minin,maxin,minPulse,maxPulse);
    pulseR = constrain(pulseR,minPulse,maxPulse);

    Serial.print("up: ");
    Serial.println(pulseL);
    Serial.print("low: ");
    Serial.println(pulseR);
    Serial.println();
    
    pwm.setPWM(CHEEK_UP_R, 0, pulseL);
    pwm.setPWM(CHEEK_LOW_R, 0, pulseR);
  }
  else if(1){//testing angle limits
    double pulseL = map(LeftHatXVar,minin,maxin,minPulse,maxPulse);
    pulseL = constrain(pulseL,minPulse,maxPulse);
    
    //Serial.print(LeftHatXVar);
    //Serial.print(", ");
    Serial.println(pulseL);
    
    pwm1.setPWM(15, 0, pulseL);
  }
  else{    

    //control eye position
    int LazyOffset = 25;// more means more to left on left eye (more right on right eye)
    int horazontal_R = map(LeftHatXVar,maxin,minin,H_EYE_R_MIN-LazyOffset,H_EYE_R_MAX-LazyOffset);
    horazontal_R = constrain(horazontal_R,H_EYE_R_MIN,H_EYE_R_MAX);
    int vertical_R = map(LeftHatYVar,minin,maxin,V_EYE_R_MIN,V_EYE_R_MAX);
    vertical_R = constrain(vertical_R,V_EYE_R_MIN,V_EYE_R_MAX);

    int horazontal_L = map(LeftHatXVar,maxin,minin,H_EYE_L_MIN,H_EYE_L_MAX);
    horazontal_L = constrain(horazontal_L,H_EYE_L_MIN,H_EYE_L_MAX);
    int vertical_L = map(LeftHatYVar,minin,maxin,V_EYE_L_MIN,V_EYE_L_MAX);
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
//    if(millis() > blinkTime+5160+blinkRand && millis() < blinkTime+5160+blinkRand+200){//auto blink
//      bottom_R = B_LID_R_CENT;//bottom
//      top_R = T_LID_R_CENT;//top
//
//      bottom_L = B_LID_L_CENT;//bottom
//      top_L = T_LID_L_CENT;//top
//    }
//    else if(millis()>blinkTime+5160+blinkRand || millis() < blinkTime){
//      blinkTime = millis();
//      blinkRand = random(-1830, 1000);
//    }
    if(L3Var){//manual blink
      blinkTime = millis();
      
      bottom_R = B_LID_R_CENT;//bottom
      top_R = T_LID_R_CENT;//top

      bottom_L = B_LID_L_CENT;//bottom
      top_L = T_LID_L_CENT;//top
    }
    else{
      int bottomOffset = map(LeftTrigVar,minin,maxin,LID_OFFSET_BOTTOM,0);
      bottomOffset = bottomOffset + map(RightTrigVar,minin,maxin,0,LID_OFFSET_BOTTOM*0.7);
      //bottomOffset = constrain(bottomOffset,0,LID_OFFSET_BOTTOM);
      
      int topOffset = map(LeftTrigVar,minin,maxin,LID_OFFSET_TOP,0);
      topOffset = topOffset + map(RightTrigVar,minin,maxin,0,LID_OFFSET_TOP*0.7);
      //topOffset = constrain(topOffset,0,LID_OFFSET_TOP);
      
      bottom_R = map(vertical_R,((V_EYE_R_MAX-V_EYE_R_MIN)/2)+V_EYE_R_MIN, V_EYE_R_MAX, B_LID_R_MIN+bottomOffset, B_LID_R_MAX);
      bottom_R = constrain(bottom_R,B_LID_R_MIN,B_LID_R_MAX);
      top_R = map(vertical_R,((V_EYE_R_MAX-V_EYE_R_MIN)/2)+V_EYE_R_MIN, V_EYE_R_MIN, T_LID_R_MIN-topOffset, T_LID_R_MAX);
      top_R = constrain(top_R,T_LID_R_MAX,T_LID_R_MIN);

      bottom_L = map(vertical_L,((V_EYE_L_MAX-V_EYE_L_MIN)/2)+V_EYE_L_MIN, V_EYE_L_MAX, B_LID_L_MIN-bottomOffset*0.8, B_LID_L_MAX);//+bottomOffset
      bottom_L = constrain(bottom_L,B_LID_L_MAX,B_LID_L_MIN);
      top_L = map(vertical_L,((V_EYE_L_MAX-V_EYE_L_MIN)/2)+V_EYE_L_MIN, V_EYE_L_MIN, T_LID_L_MIN+topOffset*1.2, T_LID_L_MAX+topOffset*0.3);//-topOffset
      top_L = constrain(top_L,T_LID_L_MIN,T_LID_L_MAX);
      
      int brow1_R = map(bottomOffset,LID_OFFSET_BOTTOM*0.3,LID_OFFSET_BOTTOM*1.7,BROW_1_R_MAX, BROW_1_R_MIN);
      brow1_R = constrain(brow1_R,BROW_1_R_MIN,BROW_1_R_MAX);
      int brow2_R = map(bottomOffset,LID_OFFSET_BOTTOM*0.3,LID_OFFSET_BOTTOM*1.7,BROW_2_R_MAX, BROW_2_R_MIN);
      brow2_R = constrain(brow2_R,BROW_2_R_MAX,BROW_2_R_MIN);

      pwm.setPWM(BROW_1_R, 0, brow1_R);
      pwm.setPWM(BROW_2_R, 0, brow2_R);
      

      int brow1_L = map(bottomOffset,LID_OFFSET_BOTTOM*0.3,LID_OFFSET_BOTTOM*1.7,BROW_1_L_MAX, BROW_1_L_MIN);
      brow1_L = constrain(brow1_L,BROW_1_L_MAX,BROW_1_L_MIN);
      int brow2_L = map(bottomOffset,LID_OFFSET_BOTTOM*0.3,LID_OFFSET_BOTTOM*1.7,BROW_2_L_MAX, BROW_2_L_MIN);
      brow2_L = constrain(brow2_L,BROW_2_L_MIN,BROW_2_L_MAX);
      
      pwm.setPWM(BROW_1_L, 0, brow1_L);
      pwm.setPWM(BROW_2_L, 0, brow2_L);
    }
    pwm.setPWM(B_LID_R, 0, bottom_R);//bottom
    pwm.setPWM(T_LID_R, 0, top_R);//top
    
    pwm.setPWM(B_LID_L, 0, bottom_L);//bottom
    pwm.setPWM(T_LID_L, 0, top_L);//top

    int cheekUpperRight = 0;
    int cheekLowerRight = 0;
    int cheekUpperLeft = 0;
    int cheekLowerLeft = 0;
    if(a==1){//up(happy)
      cheekUpperRight = CHEEK_UP_R_UP;
      cheekLowerRight = CHEEK_LOW_R_UP;
      cheekUpperLeft = CHEEK_UP_L_UP;
      cheekLowerLeft = CHEEK_LOW_L_UP;
    }
    else if(b==1){//down(sad)
      cheekUpperRight = CHEEK_UP_R_DWN;
      cheekLowerRight = CHEEK_LOW_R_DWN;
      cheekUpperLeft = CHEEK_UP_L_DWN;
      cheekLowerLeft = CHEEK_LOW_L_DWN;
    }
    else if(x==1){//forward
      cheekUpperRight = CHEEK_UP_R_FOR;
      cheekLowerRight = CHEEK_LOW_R_FOR;
      cheekUpperLeft = CHEEK_UP_L_FOR;
      cheekLowerLeft = CHEEK_LOW_L_FOR;
    }
    else if(y==1){//back
      cheekUpperRight = CHEEK_UP_R_BAK;
      cheekLowerRight = CHEEK_LOW_R_BAK;
      cheekUpperLeft = CHEEK_UP_L_BAK;
      cheekLowerLeft = CHEEK_LOW_L_BAK;
    }
    else{ //defult
      cheekUpperRight = CHEEK_UP_R_DEF;
      cheekLowerRight = CHEEK_LOW_R_DEF;
      cheekUpperLeft = CHEEK_UP_L_DEF;
      cheekLowerLeft = CHEEK_LOW_L_DEF;
    }
    pwm.setPWM(CHEEK_UP_R, 0, cheekUpperRight);
    pwm.setPWM(CHEEK_LOW_R, 0, cheekLowerRight);
    
    pwm.setPWM(CHEEK_UP_L, 0, cheekUpperLeft);
    pwm.setPWM(CHEEK_LOW_L, 0, cheekLowerLeft);
  }
}
