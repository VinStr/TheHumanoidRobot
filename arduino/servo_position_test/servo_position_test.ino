#include <XBOXUSB.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB Usb;
XBOXUSB Xbox(&Usb);

#define stickMax 30000 //32767

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//servo information
#define MIN_PULSE_WIDTH       0.35
#define MAX_PULSE_WIDTH       2.15
#define FREQUENCY             50

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  #if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nXBOX USB Library Started"));

  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);

}

void loop() {
  // put your main code here, to run repeatedly:

  Usb.Task();

  double angle = modifiedMap(Xbox.getAnalogHat(LeftHatX),-stickMax,stickMax,0,180);
  angle = constrain(angle,0,180);
  Serial.println(angle);
  pwm.setPWM(15, 0, Angle2Pulse(angle));
  
//  pwm.setPWM(15, 0, Angle2Pulse(0));
//  Serial.println("0");
//  delay(2000);
//  pwm.setPWM(15, 0, Angle2Pulse(90));
//  Serial.println("90");
//  delay(2000);
//  pwm.setPWM(15, 0, Angle2Pulse(180));
//  Serial.println("180");
//  delay(2000);
}

int Angle2Pulse(double Angle){
  double minPulse = (double)MIN_PULSE_WIDTH/((double)1/(double)FREQUENCY*(double)1000)*(double)4095;
  double maxPulse = (double)MAX_PULSE_WIDTH/((double)1/(double)FREQUENCY*(double)1000)*(double)4095;

  int Pulse = modifiedMap(Angle,0,180,minPulse,maxPulse);
  Pulse = constrain(Pulse,minPulse,maxPulse);
  
  return Pulse;
}

double modifiedMap(double x, double in_min, double in_max, double out_min, double out_max){
 double temp = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
 
 return (double) temp;
}
