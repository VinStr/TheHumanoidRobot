#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define MIN_PULSE_WIDTH       0.5
#define MAX_PULSE_WIDTH       2
#define FREQUENCY             50


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

int minPulse = 0;
int maxPulse = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);

  minPulse = (double)MIN_PULSE_WIDTH/((double)1/(double)FREQUENCY*(double)1000)*(double)4095;
  maxPulse = (double)MAX_PULSE_WIDTH/((double)1/(double)FREQUENCY*(double)1000)*(double)4095;
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int horazontal = map(analogRead(A0),0,1000,215,270);
  //horazontal = constrain(horazontal,215,270);
  int vertical = map(analogRead(A1),0,1000,150,230);
  //vertical = constrain(vertical,150,230);

  pwm.setPWM(0, 0, horazontal);
  pwm.setPWM(1, 0, vertical);

  if(digitalRead(2)){
    pwm.setPWM(2, 0, 365);//bottom
    pwm.setPWM(3, 0, 170);//top
  }
  else{
    int bottom = map(vertical,((230-150)/2)+150,230,365+30,407);
    bottom = constrain(bottom,365,407);
      
    int top = map(vertical,((230-150)/2)+150,150,170+40,233);
    top = constrain(top,170,233);
    
    pwm.setPWM(2, 0, bottom);//bottom
    pwm.setPWM(3, 0, top);//top
  }

  //int value = map(analogRead(A0),0,1000,minPulse,maxPulse);
  //pwm.setPWM(15, 0, value);
  
  delay(10);
}
