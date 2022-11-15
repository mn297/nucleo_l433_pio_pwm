/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include <Arduino.h>

#ifndef LED_BUILTIN
  #define LED_BUILTIN P13
#endif
TIM_TypeDef *Instance;
HardwareTimer *MyTim;
uint32_t channel;
void setup()
{
  // initialize LED digital pin as an output.
  Serial.begin(115200);
  while (!Serial);
  pinMode(LED_BUILTIN, OUTPUT);

  // TIMER CONFIG
  pinMode(PA0, OUTPUT);
  digitalWrite(PA0, LOW);
  PinName pinNameToUse = digitalPinToPinName(PA0);
  Instance = (TIM_TypeDef *)pinmap_peripheral(pinNameToUse, PinMap_PWM); // returns TIM2
  MyTim = new HardwareTimer(Instance);
  if (Instance != nullptr)
  {
    uint8_t timerIndex = get_timer_index(Instance);
    // pin => 0, 1, etc
    channel = STM_PIN_CHANNEL(pinmap_function( pinNameToUse, PinMap_PWM)); // returns 1 (CH1)
  
    Serial.print(", Instance = 0x"); Serial.print( (uint32_t) Instance, HEX);
    Serial.print(", channel = "); Serial.print(channel);
    Serial.print(", TimerIndex = "); Serial.print(get_timer_index(Instance));
    Serial.print(", PinName = "); Serial.println( pinNameToUse );
    HardwareTimer *MyTim = new HardwareTimer(Instance);
    MyTim->setPWM(channel, PA0, 1000, 20, nullptr, nullptr);
    MyTim->resume();


    //MANUAL setting
    // MyTim->setMode(channel, TIMER_OUTPUT_COMPARE_PWM1, PA0);
    // Serial.print(", Timer clock is ");Serial.print(MyTim->getTimerClkFreq()); // returns 80MHz
    
    // MyTim->setPrescaleFactor(1000);
    
    // // MyTim->setOverflow(5, HERTZ_FORMAT);
    // MyTim->setCaptureCompare(channel, 20, PERCENT_COMPARE_FORMAT);
  }

  

}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  MyTim->setCaptureCompare(channel, 20, PERCENT_COMPARE_FORMAT);
  delay(2000);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  MyTim->setCaptureCompare(channel, 40, PERCENT_COMPARE_FORMAT);
  delay(2000);
}