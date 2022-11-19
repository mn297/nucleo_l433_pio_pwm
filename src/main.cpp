/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include <Arduino.h>
#include <RoverArmMotor.h>
#include <Servo.h>
#include <SPI.h>
#include <AMT22_lib.h>
// #include <encoder.h>

#ifndef LED_BUILTIN
  #define LED_BUILTIN P13
#endif



//TEST MOTOR
#define WR_PWM PA0      //ARD_A0
#define WR_ENCODER PC3  //ARD_A2 ADC pin
#define WR_DIR PC7      //ARD_D7

#define WAIST_PWM PA9  //ARD_D1
#define WAIST_ENCODER PC3 // ARD_A2 pin

#define SPI1_MOSI PB15  //ARD_D11
#define SPI1_MISO PB14  //ARD_D12
#define SPI1_SCLK PB3   //ARD_D3
#define SPI1_SSEL PA15  //ARD_D5

RoverArmMotor Wrist_Roll(WR_PWM, WR_ENCODER, CYTRON, 5.0, 141.0, WR_DIR, 0);  //mn297 setpoint always 73 cause 146/2
RoverArmMotor Waist(WAIST_PWM, WAIST_ENCODER, BLUE_ROBOTICS, 5.0, 141.0, 0, 0);
double aggKp=0.025, aggKi=0.019,  aggKd=0, elbaggKp=0.025, elbaggKi=0.019,  elbaggKd=0;
double regKp=0.025, regKi=0.014, regKd=0, elbregKp=0.025, elbregKi=0.014,  elbregKd=0;
uint8_t buffer[100];

Servo WaistServo;

AMT22 Wrist_Roll_Encoder(SPI1_SSEL, 14);
// Encoder Wrist_Roll_Encoder((uint8_t)SPI1_SSEL);




void setup()
{
  // initialize LED digital pin as an output.
  Serial.begin(115200);
  while (!Serial);
  pinMode(LED_BUILTIN, OUTPUT);

  Wrist_Roll.begin(aggKp, aggKi, aggKd, regKp, regKi, regKd);
  Wrist_Roll.newSetpoint((double) 170); // test angle 170 deg
  
  Waist.begin(aggKp, aggKi, aggKd, regKp, regKi, regKd);
  Waist.newSetpoint((double) 170); // test angle 170 deg

  WaistServo.attach(PA15);  // only needed if using servo


}

void loop()
{
  // Wrist_Roll.adcResult = Wrist_Roll.internalAveragerInstance.reading(analogRead(Wrist_Roll.encoder));
  // Wrist_Roll.currentAngle = Wrist_Roll.mapFloat((float) Wrist_Roll.adcResult, MIN_ADC_VALUE, MAX_ADC_VALUE, 0, 359.0f);
  // Serial.printf("Wrist_Roll adc result is %d\n", Wrist_Roll.adcResult);
  // Serial.print("Wrist_Roll current angle is ");
  // Serial.println(Wrist_Roll.currentAngle, 4); 
  // Serial.print("Wrist_Roll current setpoint is ");
  // Serial.println(Wrist_Roll.setpoint, 4); 
  // Wrist_Roll.tick();

  // Serial.printf("Waist adc result is %d\n", Waist.adcResult);
  // Serial.print("Waist current angle is ");
  // Serial.println(Waist.currentAngle, 4); 
  // Serial.print("Waist current setpoint is ");
  // Serial.println(Waist.setpoint, 4); 
  // Waist.tick();

//TEST Encoder
  Serial.println(Wrist_Roll_Encoder.getPositionSPI());

//TEST DC Motor
  analogWrite(Wrist_Roll.pwm, 50);
  delay(1500);
  analogWrite(Wrist_Roll.pwm, 0);
  delay(1500);
  



//TEST BLUE_ROBOTICS
      // Waist.internalServoInstance.writeMicroseconds(1500);
      // delay(3000);
      // Waist.internalServoInstance.writeMicroseconds(1600);
      // delay(1000);


        // WaistServo.writeMicroseconds(1500);
        // delay(3000);
        // WaistServo.writeMicroseconds(1750);
        // delay(1000);



  // // turn the LED on (HIGH is the voltage level)
  // digitalWrite(LED_BUILTIN, HIGH);
  // delay(50);
  // // turn the LED off by making the voltage LOW
  // digitalWrite(LED_BUILTIN, LOW);
  // delay(50);
}