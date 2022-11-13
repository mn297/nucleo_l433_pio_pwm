#include "RoverMotorDC.h"

// RoverMotorDC::RoverMotorDC(TIM_HandleTypeDef *htim, uint32_t Channel){
//    _timer_handle = htim;
//    switch(Channel){
//     case 1:
//        _channel = TIM_CHANNEL_1;
//        _CCR =  (uint32_t*)&(_timer_handle->Instance->CCR1);
//        break;
//     case 2:
//        _channel = TIM_CHANNEL_2;
//        _CCR =  (uint32_t*)&(_timer_handle->Instance->CCR2);
//        break;
//     case 3:
//        _channel = TIM_CHANNEL_3;
//        _CCR =  (uint32_t*)&(_timer_handle->Instance->CCR3);
//        break;
//     case 4:
//        _channel = TIM_CHANNEL_4;
//        _CCR =  (uint32_t*)(&(_timer_handle->Instance->CCR4));
//        break;  
//     }
//   HAL_TIM_PWM_Start(_timer_handle, _channel);
// }; 


// void RoverMotorDC::setSpeed(uint32_t speed, uint32_t msDuration) {
//     _speed = speed; // save current speed
//     *(_CCR) = speed;
//     HAL_Delay(msDuration);
// }
// void RoverMotorDC::pause(uint32_t msDuration) {
//     *(_CCR) = 0;
//     HAL_Delay(msDuration);
//     *(_CCR) = _speed; //restart again
// }
// void RoverMotorDC::stop() {
//     HAL_TIM_PWM_Stop(_timer_handle, _channel);
// }