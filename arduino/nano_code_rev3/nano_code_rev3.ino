#include "Definitions.h"

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define MIN_PULSE_WIDTH       0.35
#define MAX_PULSE_WIDTH       2.15
#define FREQUENCY             50
#define maxin                 1000
#define minin                 1

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

  int Expression = 0;
  
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

//Last values
  int LastLeftHatXVar = 500;
  int LastLeftHatYVar = 500;
  
  int LastJawSlide = RightHatYVar-RightHatXVar;
  
  int LastLeftTrigVar = 1;
  int LastRightTrigVar = 1;
  
  bool LastL3Var = false;
  bool LastR3Var = false;

  bool LastL1Var = false;
  bool LastR1Var = false;

  int LastExpression  = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(baudRate);
  
  while (!Serial);

  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);
  pwm1.begin();
  pwm1.setPWMFreq(FREQUENCY);

  driveServos();

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
  
    if (stringComplete) {
      
        errorFlag = false;
        
        //050005000500050000010001003333
        
        LeftHatXVar = inputString.substring(0,4).toInt();//eye x
        if(LeftHatXVar==0 || LeftHatXVar>maxin)errorFlag = true;
        if(!errorFlag)LeftHatYVar = inputString.substring(4,8).toInt();//eye y
        if(LeftHatYVar==0 || LeftHatYVar>maxin)errorFlag = true;
        
        
        if(!errorFlag)RightHatXVar = inputString.substring(8,12).toInt();//jaw x
        if(RightHatXVar==0 || RightHatXVar>maxin)errorFlag = true;
        if(!errorFlag)RightHatYVar = inputString.substring(12,16).toInt();//jaw y
        if(RightHatYVar==0 || RightHatYVar>maxin)errorFlag = true;
        
        if(!errorFlag)LeftTrigVar = inputString.substring(16,20).toInt();//eye skwint
        if(LeftTrigVar==0 || LeftTrigVar>maxin)errorFlag = true;
        if(!errorFlag)RightTrigVar = inputString.substring(20,24).toInt();//yaw z
        if(RightTrigVar==0 || RightTrigVar>maxin)errorFlag = true;

        if(!errorFlag)Expression = inputString.substring(24,26).toInt();//expression
        if(Expression>20)errorFlag = true;
        
        decodeBool(inputString.charAt(26),L3Var);//blink
        decodeBool(inputString.charAt(27),L1Var);//supprise

        decodeBool(inputString.charAt(28),R3Var);//nose left
        decodeBool(inputString.charAt(29),R1Var);//nose right

        //clear the string:
        inputString = "";
        stringComplete = false;
        Serial.println("OK");
        
        driveServos();
    }
}

void printNum(int val){
      char temp[4];
      sprintf(temp,"%04d",val);
      Serial.print(temp);
}

void decodeBool(char val, bool &var){
  if(errorFlag)return;
  else if(val == '7')var = true;
  else if(val == '3') var = false;
  else errorFlag = true;
  return;
}

void serialEvent() {
  //digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    //Serial.println(inChar);
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      if(stringComplete || inputString.length() < 30){
        inputString = "";
      }
      else{
        stringComplete = true;
      }
    }
  }
}

double getTuningValue(int index, double minTune, double maxTune){
  switch(index){
    case 0:
      return map(analogRead(A0),0,1024,minTune,maxTune);
    case 1:
      return map(analogRead(A1),0,1024,minTune,maxTune);
    case 2:
      return map(analogRead(A2),0,1024,minTune,maxTune);
    case 3:
      return map(analogRead(A3),0,1024,minTune,maxTune);
    case 4:
      return map(analogRead(A6),0,1024,minTune,maxTune);
    case 5:
      return map(analogRead(A7),0,1024,minTune,maxTune);
    default:
      return 0;
  }
}

void servoPWM(int board, int servo, int pwmVal, int &lastpwmVal){
  int diff = 0;
  if(abs(lastpwmVal-pwmVal)>diff){
    lastpwmVal = pwmVal;
    switch (board){
      case 0:
        pwm.setPWM(servo, 0, pwmVal);
        return;
      case 1:
        pwm1.setPWM(servo, 0, pwmVal);
        return;
    }
  }
}

int lasthorazontal_R = 0;
int lastvertical_R = 0;
int lasthorazontal_L = 0;
int lastvertical_L = 0;
int lastbottom_R = 0;
int lasttop_R = 0;
int lastbottom_L = 0;
int lasttop_L = 0;
int lastbrow1_R = 0;
int lastbrow2_R = 0;
int lastbrow1_L = 0;
int lastbrow2_L = 0;
int lastcheekUpperRight = 0;
int lastcheekLowerRight = 0;
int lastcheekUpperLeft = 0;
int lastcheekLowerLeft = 0;
int lastlipLowRight = 0;
int lastlipLowLeft = 0;
int lastlipUpRight = 0;
int lastlipUpLeft = 0;
int lastslideLeft = 0;
int lastslideRight = 0;
int lastjaw = 0;
int lastnoseright = 0;
int lastnoseleft = 0;

//------------------------------------------------------------------------
void driveServos(){
  //digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
  
  if(0){//testing mouth movment
    double pulseL = map(LeftHatXVar,minin,maxin,minPulse,500);
    pulseL = constrain(pulseL,minPulse,500);
    
    double pulseR = map(RightHatXVar,minin,maxin,minPulse,500);
    pulseR = constrain(pulseR,minPulse,500);

    Serial.print("up: ");
    Serial.println(pulseL);
    Serial.print("low: ");
    Serial.println(pulseR);
    Serial.println();
    
    pwm.setPWM(CHEEK_UP_L, 0, pulseL);
    pwm.setPWM(CHEEK_LOW_L, 0, pulseR);
  }
  else if(0){//testing jaw movment

    
    //-----------jaw slide
    int temp = RightHatYVar-RightHatXVar+500;
    double pulseL = map(temp,minin,maxin,JAW_SLIDE_L_BAK,JAW_SLIDE_L_FOR);
    pulseL = constrain(pulseL,JAW_SLIDE_L_BAK,JAW_SLIDE_L_FOR);
    
    temp = RightHatYVar+RightHatXVar-500;
    double pulseR = map(temp,minin,maxin,JAW_SLIDE_R_BAK,JAW_SLIDE_R_FOR);
    pulseR = constrain(pulseR,JAW_SLIDE_R_FOR,JAW_SLIDE_R_BAK);
    
    pwm1.setPWM(JAW_SLIDE_L, 0, pulseL);
    pwm1.setPWM(JAW_SLIDE_R, 0, pulseR);

    //-----------jaw piviot  
    double jawClosed = map(pulseR,JAW_SLIDE_R_BAK,JAW_SLIDE_R_FOR,JAW_PIVOT_R_CLOS_SLD_BAK,JAW_PIVOT_R_CLOS_SLD_FOR);
    double jawOpen = map(pulseR,JAW_SLIDE_R_BAK,JAW_SLIDE_R_FOR,JAW_PIVOT_R_OPN_SLD_BAK,JAW_PIVOT_R_OPN_SLD_FOR);
    double jaw = map(RightTrigVar,minin,maxin,jawClosed,jawOpen);
    jaw = constrain(jaw,jawOpen,jawClosed);
    
    pwm1.setPWM(JAW_PIVOT_R, 0, jaw);
  }
  else if(0){//testing angle limits
    double pulseL = map(LeftHatXVar,minin,maxin,minPulse,460);
    pulseL = constrain(pulseL,minPulse,460);
    
    //Serial.print(LeftHatXVar);
    //Serial.print(", ");
    Serial.println(pulseL);
    
    pwm1.setPWM(V_EYE_R, 0, pulseL);
  }
  else{    

    //control eye position
    int vertical_R = 0;
    int vertical_L = 0;
    
    bool LeftHatXFlag = false;
    bool LeftHatYFlag = false;
    
    bool LeftTrigVarFlag = false;
    
    if(abs(LastLeftHatXVar - LeftHatXVar) > 5){ LeftHatXFlag = true; LastLeftHatXVar = LeftHatXVar;}
    if(abs(LastLeftHatYVar - LeftHatYVar) > 5){ LeftHatYFlag = true; LastLeftHatYVar = LeftHatYVar;}
    
    if(abs(LastLeftTrigVar - LeftTrigVar) > 9){ LeftTrigVarFlag = true; LastLeftTrigVar = LeftTrigVar;}
    
    if(LeftHatXFlag || LeftHatYFlag){
      int horazontal_R = map(LeftHatXVar,maxin,minin,H_EYE_R_MIN,H_EYE_R_MAX);
      horazontal_R = constrain(horazontal_R,H_EYE_R_MIN,H_EYE_R_MAX);
      vertical_R = map(LeftHatYVar,minin,maxin,V_EYE_R_MIN,V_EYE_R_MAX);
      vertical_R = constrain(vertical_R,V_EYE_R_MIN,V_EYE_R_MAX);
  
      int horazontal_L = map(LeftHatXVar,maxin,minin,H_EYE_L_MIN,H_EYE_L_MAX);
      horazontal_L = constrain(horazontal_L+getTuningValue(3,-50,50),H_EYE_L_MIN,H_EYE_L_MAX);
      vertical_L = map(LeftHatYVar,minin,maxin,V_EYE_L_MIN,V_EYE_L_MAX);
      vertical_L = constrain(vertical_L+getTuningValue(4,-50,50),V_EYE_L_MIN,V_EYE_L_MAX);
    
      
      servoPWM(1,H_EYE_R,horazontal_R,lasthorazontal_R);//pwm1.setPWM(H_EYE_R, 0, horazontal_R);
      servoPWM(1,V_EYE_R,vertical_R,lastvertical_R);//pwm1.setPWM(V_EYE_R, 0, vertical_R);
  
      servoPWM(1,H_EYE_L,horazontal_L,lasthorazontal_L);//pwm1.setPWM(H_EYE_L, 0, horazontal_L);
      servoPWM(1,V_EYE_L,vertical_L,lastvertical_L);//pwm1.setPWM(V_EYE_L, 0, vertical_L);
    }
  
    //control eye lid
    //bink every 5.16s +/-1.83
    int bottom_R = 0;
    int top_R = 0;

    int bottom_L = 0;
    int top_L = 0;
    if(L3Var != LastL3Var && L3Var){//manual blink
      LastL3Var = L3Var;
      bottom_R = B_LID_R_CENT;//bottom
      top_R = T_LID_R_CENT;//top
  
      bottom_L = B_LID_L_CENT+getTuningValue(5,-50,50);//bottom
      top_L = T_LID_L_CENT+getTuningValue(5,-50,50)*0.7;//top
  
      servoPWM(0,B_LID_R,bottom_R,lastbottom_R);//pwm.setPWM(B_LID_R, 0, bottom_R);//bottom
      servoPWM(0,T_LID_R,top_R,lasttop_R);//pwm.setPWM(T_LID_R, 0, top_R);//top
    
      servoPWM(0,B_LID_L,bottom_L,lastbottom_L);//pwm.setPWM(B_LID_L, 0, bottom_L);//bottom
      servoPWM(0,T_LID_L,top_L,lasttop_L);//pwm.setPWM(T_LID_L, 0, top_L);//top
    }
    else if (LeftHatYFlag || (L1Var != LastL1Var) || LeftTrigVarFlag || (L3Var != LastL3Var && !L3Var)){
      LastL1Var = L1Var;
      LastL3Var = L3Var;
      
      double bottomOffsetR = map(LeftTrigVar,minin,maxin,getTuningValue(2,0,150),0);
      if(L1Var) bottomOffsetR = bottomOffsetR + getTuningValue(2,0,150)*0.7;
      double topOffsetR = map(LeftTrigVar,minin,maxin,getTuningValue(2,0,150),0);
      if(L1Var) topOffsetR = topOffsetR + getTuningValue(2,0,150)*0.7;
      
      bottom_R = map(lastvertical_R,((V_EYE_R_MAX-V_EYE_R_MIN)/2)+V_EYE_R_MIN, V_EYE_R_MAX, B_LID_R_MIN+bottomOffsetR, B_LID_R_MAX);
      bottom_R = constrain(bottom_R,B_LID_R_MIN,B_LID_R_MAX);
      top_R = map(lastvertical_R,((V_EYE_R_MAX-V_EYE_R_MIN)/2)+V_EYE_R_MIN, V_EYE_R_MIN, T_LID_R_MIN-topOffsetR, T_LID_R_MAX);
      top_R = constrain(top_R,T_LID_R_MAX,T_LID_R_MIN);
  
      double bottomOffsetL = map(LeftTrigVar,minin,maxin,getTuningValue(1,0,150),0);
      if(L1Var) bottomOffsetL = bottomOffsetL + getTuningValue(1,0,150)*0.7;
      double topOffsetL = map(LeftTrigVar,minin,maxin,getTuningValue(1,0,150),0);
      if(L1Var) topOffsetL = topOffsetL + getTuningValue(1,0,150)*0.7;
  
      bottom_L = map(lastvertical_L,((V_EYE_L_MAX-V_EYE_L_MIN)/2)+V_EYE_L_MIN, V_EYE_L_MAX, B_LID_L_MIN-bottomOffsetL, B_LID_L_MAX)+getTuningValue(0,-50,50);//-bottomOffsetL
      bottom_L = constrain(bottom_L,B_LID_L_MAX,B_LID_L_MIN);
      top_L = map(lastvertical_L,((V_EYE_L_MAX-V_EYE_L_MIN)/2)+V_EYE_L_MIN, V_EYE_L_MIN, T_LID_L_MIN+topOffsetL, T_LID_L_MAX)+getTuningValue(0,-50,50);//+topOffsetL
      top_L = constrain(top_L,T_LID_L_MIN,T_LID_L_MAX);
        
      int brow1_R = map(bottomOffsetR,LID_OFFSET_BOTTOM_R*0.3,LID_OFFSET_BOTTOM_R*1.7,BROW_1_R_MAX, BROW_1_R_MIN);
      brow1_R = constrain(brow1_R,BROW_1_R_MIN,BROW_1_R_MAX);
      int brow2_R = map(bottomOffsetR,LID_OFFSET_BOTTOM_R*0.3,LID_OFFSET_BOTTOM_R*1.7,BROW_2_R_MAX, BROW_2_R_MIN);
      brow2_R = constrain(brow2_R,BROW_2_R_MIN,BROW_2_R_MAX);
  
      servoPWM(0,BROW_1_R,brow1_R,lastbrow1_R);//pwm.setPWM(BROW_1_R, 0, brow1_R);
      servoPWM(0,BROW_2_R,brow2_R,lastbrow2_R);//pwm.setPWM(BROW_2_R, 0, brow2_R);
  
      int brow1_L = map(bottomOffsetL,LID_OFFSET_BOTTOM_L*0.3,LID_OFFSET_BOTTOM_L*1.7,BROW_1_L_MAX, BROW_1_L_MIN);
      brow1_L = constrain(brow1_L,BROW_1_L_MAX,BROW_1_L_MIN);
      int brow2_L = map(bottomOffsetL,LID_OFFSET_BOTTOM_L*0.3,LID_OFFSET_BOTTOM_L*1.7,BROW_2_L_MAX, BROW_2_L_MIN);
      brow2_L = constrain(brow2_L,BROW_2_L_MIN,BROW_2_L_MAX);
        
      servoPWM(0,BROW_1_L,brow1_L,lastbrow1_L);//pwm.setPWM(BROW_1_L, 0, brow1_L);
      servoPWM(0,BROW_2_L,brow2_L,lastbrow2_L);//pwm.setPWM(BROW_2_L, 0, brow2_L);
  
      if(!L3Var){
        servoPWM(0,B_LID_R,bottom_R,lastbottom_R);//pwm.setPWM(B_LID_R, 0, bottom_R);//bottom
        servoPWM(0,T_LID_R,top_R,lasttop_R);//pwm.setPWM(T_LID_R, 0, top_R);//top
        
        servoPWM(0,B_LID_L,bottom_L,lastbottom_L);//pwm.setPWM(B_LID_L, 0, bottom_L);//bottom
        servoPWM(0,T_LID_L,top_L,lasttop_L);//pwm.setPWM(T_LID_L, 0, top_L);//top
      }
    }

    //-------------------------------expression to placemnt
    int cheek = 0;
    int upperLip = 0;
    int lowerLip = 0;
      
    switch (Expression) {
      case 1:
        cheek = 4;
        upperLip = 1;
        lowerLip = 3;
        RightHatXVar = 500;
        RightHatYVar = 500;
        RightTrigVar = 600;
        break;
      case 2:
        cheek = 2;
        upperLip = 1;
        lowerLip = 3;
        RightHatXVar = 500;
        RightHatYVar = 500;
        RightTrigVar = 400;
        break;
      case 3:
        cheek = 3;
        upperLip = 3;
        lowerLip = 3;
        RightHatXVar = 500;
        RightHatYVar = 500;
        RightTrigVar = 0;
        break;
      case 4:
        cheek = 3;
        upperLip = 3;
        lowerLip = 3;
        RightHatXVar = 500;
        RightHatYVar = 0;
        RightTrigVar = 0;
        break;
      case 5:
        cheek = 1;
        upperLip = 2;
        lowerLip = 2;
        RightHatXVar = 500;
        RightHatYVar = 0;
        RightTrigVar = 300;
        break;
      case 6:
        cheek = 2;
        upperLip = 1;
        lowerLip = 3;
        RightHatXVar = 500;
        RightHatYVar = 0;
        RightTrigVar = 300;
        break;
      case 7:
        cheek = 5;
        upperLip = 2;
        lowerLip = 2;
        RightHatXVar = 500;
        RightHatYVar = 500;
        RightTrigVar = 400;
        break;
      case 8:
        cheek = 2;
        upperLip = 2;
        lowerLip = 2;
        RightHatXVar = 500;
        RightHatYVar = 500;
        RightTrigVar = 300;
        break;
      case 9:
        cheek = 3;
        upperLip = 2;
        lowerLip = 3;
        RightHatXVar = 500;
        RightHatYVar = 500;
        RightTrigVar = 0;
        break;
      case 10:
        cheek = 2;
        upperLip = 2;
        lowerLip = 2;
        RightHatXVar = 500;
        RightHatYVar = 0;
        RightTrigVar = 300;
        break;
      case 11:
        cheek = 1;
        upperLip = 1;
        lowerLip = 3;
        RightHatXVar = 500;
        RightHatYVar = 500;
        RightTrigVar = 400;
        break;
      case 12:
        cheek = 2;
        upperLip = 2;
        lowerLip = 3;
        RightHatXVar = 500;
        RightHatYVar = 500;
        RightTrigVar = 0;
        break;
      case 13:
        cheek = 1;
        upperLip = 2;
        lowerLip = 2;
        RightHatXVar = 500;
        RightHatYVar = 500;
        RightTrigVar = 300;
        break;
      case 14:
        cheek = 1;
        upperLip = 2;
        lowerLip = 3;
        RightHatXVar = 500;
        RightHatYVar = 500;
        RightTrigVar = 400;
        break;
      case 15://smile
        cheek = 4;
        upperLip = 1;
        lowerLip = 1;
        break;
      case 16://frown
        cheek = 5;
        upperLip = 1;
        lowerLip = 1;
        break;
      case 17://puker
        cheek = 1;
        upperLip = 1;
        lowerLip = 1;
        break;
      case 18://wide
        cheek = 2;
        upperLip = 1;
        lowerLip = 1;
        break;
      default:
        cheek = 3;
        upperLip = 2;
        lowerLip = 2;
        break;
    }
      
    if(Expression != LastExpression){
      LastExpression = Expression;
      
      //cheek
      int cheekUpperRight = 0;
      int cheekLowerRight = 0;
      int cheekUpperLeft = 0;
      int cheekLowerLeft = 0;
      switch(cheek){//upper lip
        case 1://forward
          cheekUpperRight = CHEEK_UP_R_FOR;
          cheekLowerRight = CHEEK_LOW_R_FOR;
          cheekUpperLeft = CHEEK_UP_L_FOR;
          cheekLowerLeft = CHEEK_LOW_L_FOR;
          break;
        case 2://back
          cheekUpperRight = CHEEK_UP_R_BAK;
          cheekLowerRight = CHEEK_LOW_R_BAK;
          cheekUpperLeft = CHEEK_UP_L_BAK;
          cheekLowerLeft = CHEEK_LOW_L_BAK;
          break;
        case 3://mid
          cheekUpperRight = CHEEK_UP_R_DEF;
          cheekLowerRight = CHEEK_LOW_R_DEF;
          cheekUpperLeft = CHEEK_UP_L_DEF;
          cheekLowerLeft = CHEEK_LOW_L_DEF;
          break;
        case 4://back up
          cheekUpperRight = CHEEK_UP_R_UP;
          cheekLowerRight = CHEEK_LOW_R_UP;
          cheekUpperLeft = CHEEK_UP_L_UP;
          cheekLowerLeft = CHEEK_LOW_L_UP;
          break;
        case 5://back down
          cheekUpperRight = CHEEK_UP_R_DWN;
          cheekLowerRight = CHEEK_LOW_R_DWN;
          cheekUpperLeft = CHEEK_UP_L_DWN;
          cheekLowerLeft = CHEEK_LOW_L_DWN;
          break;
        default:
          cheekUpperRight = CHEEK_UP_R_DEF;
          cheekLowerRight = CHEEK_LOW_R_DEF;
          cheekUpperLeft = CHEEK_UP_L_DEF;
          cheekLowerLeft = CHEEK_LOW_L_DEF;
          break;
      }
      servoPWM(0,CHEEK_UP_R,cheekUpperRight,lastcheekUpperRight);//pwm.setPWM(CHEEK_UP_R, 0, cheekUpperRight);
      servoPWM(0,CHEEK_LOW_R,cheekLowerRight,lastcheekLowerRight);//pwm.setPWM(CHEEK_LOW_R, 0, cheekLowerRight);
    
      servoPWM(0,CHEEK_UP_L,cheekUpperLeft,lastcheekUpperLeft);//pwm.setPWM(CHEEK_UP_L, 0, cheekUpperLeft);
      servoPWM(0,CHEEK_LOW_L,cheekLowerLeft,lastcheekLowerLeft);//pwm.setPWM(CHEEK_LOW_L, 0, cheekLowerLeft);
      
      //lips
      int lipUpRight = 0;
      int lipUpLeft = 0;
      int lipLowRight = 0;
      int lipLowLeft = 0; //max-in min-out
      switch(upperLip){//upper lip
        case 1://in
          lipUpRight = LIP_UP_R_IN;
          lipUpLeft = LIP_UP_L_IN;
          break;
        case 2://mid
          lipLowRight = int(((LIP_LOW_R_OUT-LIP_LOW_R_IN)/2)+LIP_LOW_R_IN);
          lipLowLeft = int(((LIP_LOW_L_OUT-LIP_LOW_L_IN)/2)+LIP_LOW_L_IN);
          break;
        case 3://out
          lipUpRight = LIP_UP_R_OUT;
          lipUpLeft = LIP_UP_L_OUT;
          break;
        default:
          lipLowRight = int(((LIP_LOW_R_OUT-LIP_LOW_R_IN)/2)+LIP_LOW_R_IN);
          lipLowLeft = int(((LIP_LOW_L_OUT-LIP_LOW_L_IN)/2)+LIP_LOW_L_IN);
          break;
      }
      switch(lowerLip){//lower lip
        case 1://in
          lipLowRight = LIP_LOW_R_IN;
          lipLowLeft = LIP_LOW_L_IN;
          break;
        case 2://mid
          lipUpRight = int(((LIP_UP_R_OUT-LIP_UP_R_IN)/2)+LIP_UP_R_IN);
          lipUpLeft = int(((LIP_UP_L_OUT-LIP_UP_L_IN)/2)+LIP_UP_L_IN);
          break;
        case 3://out
          lipLowRight = LIP_LOW_R_OUT;
          lipLowLeft = LIP_LOW_L_OUT;
          break;
        default:
          lipUpRight = int(((LIP_UP_R_OUT-LIP_UP_R_IN)/2)+LIP_UP_R_IN);
          lipUpLeft = int(((LIP_UP_L_OUT-LIP_UP_L_IN)/2)+LIP_UP_L_IN);
          break;
      }
      servoPWM(0,LIP_LOW_R,lipLowRight,lastlipLowRight);//pwm.setPWM(LIP_LOW_R, 0, lipLowRight);
      servoPWM(0,LIP_LOW_L,lipLowLeft,lastlipLowLeft);//pwm.setPWM(LIP_LOW_L, 0, lipLowLeft);
      servoPWM(0,LIP_UP_R,lipUpRight,lastlipUpRight);//pwm.setPWM(LIP_UP_R, 0, lipUpRight);
      servoPWM(0,LIP_UP_L,lipUpLeft,lastlipUpLeft);//pwm.setPWM(LIP_UP_L, 0, lipUpLeft);
    }

      
    //------------------------------------------------------jaw
    //-----------jaw slide
    int JawSlide = RightHatYVar-RightHatXVar+500;
    bool jawSlideFlag = false;
    if(abs(LastJawSlide - JawSlide) > 6){jawSlideFlag = true; LastLeftHatXVar = LeftHatXVar;}
    if(jawSlideFlag){   
      double slideLeft = map(JawSlide,minin,maxin,JAW_SLIDE_L_BAK,JAW_SLIDE_L_FOR);
      slideLeft = constrain(slideLeft,JAW_SLIDE_L_BAK,JAW_SLIDE_L_FOR);
      
      JawSlide = RightHatYVar+RightHatXVar-500;
      double slideRight = map(JawSlide,minin,maxin,JAW_SLIDE_R_BAK,JAW_SLIDE_R_FOR);
      slideRight = constrain(slideRight,JAW_SLIDE_R_FOR,JAW_SLIDE_R_BAK);
      
      servoPWM(1,JAW_SLIDE_L,slideLeft,lastslideLeft);//pwm1.setPWM(JAW_SLIDE_L, 0, slideLeft);
      servoPWM(1,JAW_SLIDE_R,slideRight,lastslideRight);//pwm1.setPWM(JAW_SLIDE_R, 0, slideRight);
    }

    //-----------jaw piviot
    if(abs(LastRightTrigVar - RightTrigVar) > 3 || jawSlideFlag){
      LastRightTrigVar = RightTrigVar;
      
      double slideRight = map(JawSlide,minin,maxin,JAW_SLIDE_R_BAK,JAW_SLIDE_R_FOR);
      double jawClosed = map(slideRight,JAW_SLIDE_R_BAK,JAW_SLIDE_R_FOR,JAW_PIVOT_R_CLOS_SLD_BAK,JAW_PIVOT_R_CLOS_SLD_FOR);
      double jawOpen = map(slideRight,JAW_SLIDE_R_BAK,JAW_SLIDE_R_FOR,JAW_PIVOT_R_OPN_SLD_BAK,JAW_PIVOT_R_OPN_SLD_FOR);
      double jaw = map(RightTrigVar,minin,maxin,jawClosed,jawOpen);
      jaw = constrain(jaw,jawOpen,jawClosed);
      
      servoPWM(1,JAW_PIVOT_R,jaw,lastjaw);//pwm1.setPWM(JAW_PIVOT_R, 0, jaw);
    }

    //-----------nose
    int noseright = 0;
    int noseleft = 0;
    if (R1Var != LastR1Var || R3Var != LastR3Var){
      LastR1Var = R1Var;
      LastR3Var = R3Var;
      if(R1Var)noseright = NOSE_R_UP;
      else noseright = NOSE_R_DWN; //noseleft = int(((NOSE_L_DWN-NOSE_L_UP)/2)+NOSE_L_UP);
      if(R3Var)noseleft = NOSE_L_UP;
      else noseleft = NOSE_L_DWN;
      
      servoPWM(1,NOSE_R,noseright,lastnoseright);//pwm1.setPWM(NOSE_R, 0, noseright);
      servoPWM(1,NOSE_L,noseleft,lastnoseleft);//pwm1.setPWM(NOSE_L, 0, noseleft);
    }
  }
}
