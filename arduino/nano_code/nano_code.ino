#define baudRate              115200

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
//servo information
#define MIN_PULSE_WIDTH       0.35
#define MAX_PULSE_WIDTH       2.15
#define FREQUENCY             50

#define maxin                 1000

String inputString = "";         // a String to hold incoming data
boolean stringComplete = false;  // whether the string is complete

const int minPulse = (double)MIN_PULSE_WIDTH/((double)1/(double)FREQUENCY*(double)1000)*(double)4095;
const int maxPulse = (double)MAX_PULSE_WIDTH/((double)1/(double)FREQUENCY*(double)1000)*(double)4095;
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

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
#define H_EYE_R_MIN 180//210 //right
#define H_EYE_R_MAX 360//385 //left

#define V_EYE_R_MIN 180//140 //up
#define V_EYE_R_MAX 370//230 //down

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

#define H_EYE_L_MIN 95//160 //right
#define H_EYE_L_MAX 215//340 //left

#define V_EYE_L_MIN 190 //up
#define V_EYE_L_MAX 340 //down

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

  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
  

    if (stringComplete) {
      //digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));

      char command = inputString.charAt(0);
      int value = inputString.substring(1,inputString.length()).toInt();

      if((char)command == 'l'){//LeftHatXVar
        LeftHatXVar = value;
      }
      else if((char)command == 'L'){//LeftHatYVar
        LeftHatYVar = value;
      }
      else if((char)command == '3'){//L3Var
        L3Var = value;
      }
      else if((char)command == '£'){//R3Var
        R3Var = value;
      }
      else if((char)command == '1'){//L1Var
        L1Var = value;
      }
      else if((char)command == '!'){//R1Var
        R1Var = value;
      }
      else if((char)command == 't'){//LeftTrigVar
        LeftTrigVar = value;
      }
      else if((char)command == 'T'){//RightTrigVar
        RightTrigVar = value;
      }
      else if((char)command == 'r'){//RightHatXVar
        RightHatXVar = value;
      }
      else if((char)command == 'R'){//RightHatYVar
        RightHatYVar = value;
      }

      //clear the string:
      inputString = "";
      stringComplete = false;

      driveServos();
    }

}

void driveServos(){
  if(0){//testing mouth movment
    double pulseL = map(LeftHatXVar,0,maxin,minPulse,maxPulse);
    pulseL = constrain(pulseL,minPulse,maxPulse);
    
    double pulseR = map(RightHatXVar,0,maxin,minPulse,maxPulse);
    pulseR = constrain(pulseR,minPulse,maxPulse);
    
    pwm.setPWM(8, 0, pulseL);
    pwm.setPWM(9, 0, pulseR);
  }
  else if(0){//testing angle limits
    double pulseL = map(LeftHatXVar,0,maxin,minPulse,maxPulse);
    pulseL = constrain(pulseL,minPulse,maxPulse);
    
    Serial.println(pulseL);
    
    pwm.setPWM(15, 0, pulseL);
  }
  else{
    //control eye position
    int horazontal_R = map(LeftHatXVar,maxin,0,H_EYE_R_MIN,H_EYE_R_MAX);
    horazontal_R = constrain(horazontal_R,H_EYE_R_MIN,H_EYE_R_MAX);
    int vertical_R = map(LeftHatYVar,0,maxin,V_EYE_R_MIN,V_EYE_R_MAX);
    vertical_R = constrain(vertical_R,V_EYE_R_MIN,V_EYE_R_MAX);

    int horazontal_L = map(LeftHatXVar,maxin,0,H_EYE_L_MIN,H_EYE_L_MAX);
    horazontal_L = constrain(horazontal_L,H_EYE_L_MIN,H_EYE_L_MAX);
    int vertical_L = map(LeftHatYVar,0,maxin,V_EYE_L_MIN,V_EYE_L_MAX);
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
      int bottomOffset = map(LeftTrigVar,0,maxin,LID_OFFSET_BOTTOM,0);
      bottomOffset = bottomOffset + map(RightTrigVar,0,maxin,0,LID_OFFSET_BOTTOM*0.7);
      bottomOffset = constrain(bottomOffset,0,LID_OFFSET_BOTTOM);
      
      int topOffset = map(LeftTrigVar,0,maxin,LID_OFFSET_TOP,0);
      topOffset = topOffset + map(RightTrigVar,0,maxin,0,LID_OFFSET_TOP*0.7);
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
      stringComplete = true;
    }
  }
}
