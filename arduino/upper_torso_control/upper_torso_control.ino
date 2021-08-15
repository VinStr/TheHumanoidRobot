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

//variables
String inputString = "";         // a String to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String outputString = "";

//musle position variables
int HeadPitch = 500;
int HeadRoll = 500;
int NeckTurnPos = 500;
int ToungeExpression = 0;

//accelerometer
const int MPU=0x68; 
double pitch, roll;

//to slow movement of neck servos
#define slowStep 10
#define neckWindow 5
int leftPos = 0;
int rightPos = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(MTR1ENB,OUTPUT);
  pinMode(MTR1_1,OUTPUT);
  pinMode(MTR1_2,OUTPUT);

  digitalWrite(MTR1ENB,0);
  digitalWrite(MTR1_1,0);
  digitalWrite(MTR1_2,0);
  
  pinMode(MTR2ENB,OUTPUT);
  pinMode(MTR2_1,OUTPUT);
  pinMode(MTR2_2,OUTPUT);

  digitalWrite(MTR2ENB,0);
  digitalWrite(MTR2_1,0);
  digitalWrite(MTR2_2,0);

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  inputString.reserve(200);

  digitalWrite(LED_BUILTIN, HIGH);

  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);

  //setup I2C
  Wire.begin();
  Wire.beginTransmission(MPU);
  //setup accelerometer
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  
  //initalize servo position
  leftPos = neck_top_left_def;
  rightPos = neck_top_left_def;
}

bool errorFlag = false;

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
  
  if (stringComplete) {

    errorFlag = false;
        
    NeckTurnPos = inputString.substring(0,4).toInt();// neck position
    if(NeckTurnPos==0 || NeckTurnPos>maxin)errorFlag = true;

    if(!errorFlag)HeadPitch = inputString.substring(4,8).toInt();//pitch of head
    if(HeadPitch==0 || HeadPitch>maxin)errorFlag = true;
    if(!errorFlag)HeadRoll = inputString.substring(8,12).toInt();//roll of head
    if(HeadRoll==0 || HeadRoll>maxin)errorFlag = true;

    if(!errorFlag)ToungeExpression = inputString.substring(12,14).toInt();//Tounge expression
    if(ToungeExpression>20)errorFlag = true;
        
    // clear the string:
    inputString = "";
    stringComplete = false;
    Serial.print("OK");
    Serial.print("~");
    getAccel();
    Serial.print("~");
    driveServos();
    DriveNeck();

    Serial.println();
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

void driveServos(){
  if(0){//testing neck servos
    double pulseL = map(HeadPitch,minin,maxin,minPulse,500);
    pulseL = constrain(pulseL,minPulse,500);
    
    double pulseR = map(HeadRoll,minin,maxin,minPulse,500);
    pulseR = constrain(pulseR,minPulse,500);

    Serial.print("L");
    Serial.print(pulseL);
    Serial.print("R");
    Serial.print(pulseR);
    
    pwm.setPWM(neck_top_left, 0, pulseL);
    pwm.setPWM(neck_top_right, 0, pulseR);
  }
  else{

    double NeckL = HeadPitch-HeadRoll+500;
    NeckL = map(NeckL,minin,maxin,neck_top_left_min,neck_top_left_max);
    NeckL = constrain(NeckL,minPulse,500);

    double NeckR = HeadPitch+HeadRoll-500;
    NeckR = map(NeckR,minin,maxin,neck_top_right_max,neck_top_right_min);
    NeckR = constrain(NeckR,minPulse,500);

    //pwm.setPWM(neck_top_left, 0, NeckL);
    //pwm.setPWM(neck_top_right, 0, NeckR);
    driveNeckServo(NeckR,NeckL);
  }
}

void setNeckAngle(int left, int right){
  int leftpwm = map(left,0,1000,neck_top_left_min,neck_top_left_max);
  int rightpwm = map(right,0,1000,neck_top_right_min,neck_top_right_max);
  
  pwm.setPWM(neck_top_left, 0, leftpwm);
  pwm.setPWM(neck_top_right, 0, rightpwm);
}

void driveNeckServo(int pulseR, int pulseL){
  if(rightPos != pulseR){
    if(pulseR > rightPos-neckWindow && pulseR < rightPos+neckWindow) rightPos = pulseR;
    else if(pulseR > rightPos)rightPos = rightPos + slowStep;
    else if(pulseR < rightPos)rightPos = rightPos - slowStep;
    pwm.setPWM(neck_top_right, 0, rightPos);
  }

  if(leftPos != pulseL){
    if(pulseL > leftPos-neckWindow && pulseL < leftPos+neckWindow) leftPos = pulseL;
    else if(pulseL > leftPos)leftPos = leftPos + slowStep;
    else if(pulseL < leftPos)leftPos = leftPos - slowStep;
    pwm.setPWM(neck_top_left, 0, leftPos);
  }
}

void DriveNeck(){

  double pv_pos = getNeckTurn();
  
  double e_pos = -(NeckTurnPos - pv_pos);
  int pwm_pulse = (int)(e_pos * KP + KO);

  //reached target range
  if (NeckTurnPos > pv_pos - NECKDEAD && NeckTurnPos < pv_pos + NECKDEAD) pwm_pulse = 0;
  //outside of limits
  if(pv_pos>=1000 && pwm_pulse<0) pwm_pulse = 0;
  else if(pv_pos<=0 && pwm_pulse>0) pwm_pulse = 0;
  
  driveMotor(pwm_pulse, 1);
}

int getNeckTurn(){
  int pos = analogRead(TRN_POT);
  pos = map(pos,trn_pot_min,trn_pot_max,0,1000);
  return pos;
}

void driveMotor(int speed, int motor){
  speed = constrain(speed,-255,255);
  if(motor == 1){
    if(speed == 0){
      digitalWrite(MTR1_1,false);
      digitalWrite(MTR1_2,false);
    }
    else if(speed < 0){
      digitalWrite(MTR1_2,false);
      digitalWrite(MTR1_1,true);
    }
    else if(speed > 0){
      digitalWrite(MTR1_1,false);
      digitalWrite(MTR1_2,true);
    }
    analogWrite(MTR1ENB,abs(speed));
  }
  else if(motor == 2){
    if(speed == 0){
      digitalWrite(MTR2_1,false);
      digitalWrite(MTR2_2,false);
    }
    else if(speed < 0){
      digitalWrite(MTR2_2,false);
      digitalWrite(MTR2_1,true);
    }
    else if(speed > 0){
      digitalWrite(MTR2_1,false);
      digitalWrite(MTR2_2,true);
    }
    analogWrite(MTR2ENB,abs(speed));
  }
}

void serialEvent() {
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

void getAccel(){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true);  
  int16_t AcX=Wire.read()<<8|Wire.read();    
  int16_t AcY=Wire.read()<<8|Wire.read();  
  int16_t AcZ=Wire.read()<<8|Wire.read();  
  int16_t GyX=Wire.read()<<8|Wire.read();  
  int16_t GyY=Wire.read()<<8|Wire.read();  
  int16_t GyZ=Wire.read()<<8|Wire.read(); 

  roll = atan2(AcY , AcZ) * 57.3 - ORIG_ROLL;
  pitch = atan2(AcX , AcZ) * 57.3 - ORIG_PITCH;

  Serial.print(pitch);
  Serial.print(",");
  Serial.print(roll);
}
