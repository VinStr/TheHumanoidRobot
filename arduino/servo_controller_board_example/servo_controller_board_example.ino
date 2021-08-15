#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define MIN_PULSE_WIDTH       0.35
#define MAX_PULSE_WIDTH       2.15
#define FREQUENCY             50


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);  // This is the maximum PWM frequency

  int minPulse = (double)MIN_PULSE_WIDTH/((double)1/(double)FREQUENCY*(double)1000)*(double)4095;
  Serial.println(minPulse);
  int maxPulse = (double)MAX_PULSE_WIDTH/((double)1/(double)FREQUENCY*(double)1000)*(double)4095;
  Serial.println(maxPulse);
  Serial.println(maxPulse-minPulse);

  for(int i=minPulse;i<maxPulse+1;i++){
    pwm.setPWM(15, 0, i);
    Serial.println(i);
    delay(20);
  }
  pwm.setPWM(15, 0, minPulse);
  

}

void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println("high");
//  pwm.setPWM(15, 4095, 0);
//  delay(500);
//  Serial.println("low");
//  pwm.setPWM(15, 0, 4095);
//  delay(500);
}
