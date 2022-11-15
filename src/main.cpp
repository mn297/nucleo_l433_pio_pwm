/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include <Arduino.h>
#include <RoverArmMotor.h>

#ifndef LED_BUILTIN
  #define LED_BUILTIN P13
#endif



//TEST MOTOR
#define WR_PWM PA0
#define WR_ENCODER PC3 //ADC pin
#define WR_DIR PC12
RoverArmMotor Wrist_Roll(WR_PWM, WR_ENCODER, CYTRON, 5.0, 141.0, WR_DIR, 0);
double aggKp=0.025, aggKi=0.019,  aggKd=0, elbaggKp=0.025, elbaggKi=0.019,  elbaggKd=0;
double regKp=0.025, regKi=0.014, regKd=0, elbregKp=0.025, elbregKi=0.014,  elbregKd=0;
uint8_t buffer[100];
void setup()
{
  // initialize LED digital pin as an output.
  Serial.begin(115200);
  while (!Serial);
  pinMode(LED_BUILTIN, OUTPUT);

  Wrist_Roll.begin(aggKp, aggKi, aggKd, regKp, regKi, regKd);
  

  Wrist_Roll.newSetpoint((double) 170); // test angle 170 deg
  

}

void loop()
{
  // Wrist_Roll.adcResult = Wrist_Roll.internalAveragerInstance.reading(analogRead(Wrist_Roll.encoder));
  // Wrist_Roll.currentAngle = Wrist_Roll.mapFloat((float) Wrist_Roll.adcResult, MIN_ADC_VALUE, MAX_ADC_VALUE, 0, 359.0f);
  Serial.printf("adc result is %d\n", Wrist_Roll.adcResult);
  Serial.print("current angle is ");
  Serial.println(Wrist_Roll.currentAngle, 4); 
  Serial.print("current setpoint is ");
  Serial.println(Wrist_Roll.setpoint, 4); 
  Wrist_Roll.tick();
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  delay(50);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  delay(50);
}