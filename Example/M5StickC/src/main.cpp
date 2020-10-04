/*
 ********************************************************************
  ESP32_PWM_Generator_Arduino
  Implement PWM generator for Espressif Systems ESP32 boards by Arduino framework  

  Github: https://github.com/walidamriou/ESP32_PWM_Generator_Arduino
  Copyright © 2020 Walid Amriou
  Last update: October 2020
 ********************************************************************
*/

#include <Arduino.h>
#include <M5StickC.h>

// 50 Hz (period of 20ms)
int PWM_FREQUENCY = 50; 
int PWM_CHANNEL = 0; 
// You can choose from 1 to 8 bits
int PWM_RESOLUTION = 8; 
int GPIO_PIN = 26 ; 
// Define the width of signal from PWM resoution
// When we have PWM Resolution of 8 bits so we have the dutyCycle valure between 0 to 255 (0 to 100%)
// from this value wa can choose the duty Cycle:
// - If we want duty cycle of 50% so (50 * 255 / 100) = 127.5 so 127 only because duty is uint32_t
// - If we want duty cycle of 20% so (20 * 255 / 100) = 51
int dutyCycle = 127;  

void setup(){
  M5.begin();
  ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION);
  ledcAttachPin(GPIO_PIN, PWM_CHANNEL);
}

void loop() {
  ledcWrite(PWM_CHANNEL, dutyCycle);
}