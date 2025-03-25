/*===========================================================
- Update 23/Mar/2025 by HungĐK :u
- Copyright belongs to HungĐK - User-customizable open source.
- Functions to configure I/O, Control robot, Receiver process.
- Social Links: https://www.facebook.com/hung.tola.52/
- Github: https://www.github.com/HungvsRobot
===========================================================*/

#ifndef Workdy_H
#define Workdy_H
#include <Arduino.h>
#include "String.h"
#include <SoftwareSerial.h>


class Motor_pwm {
    private: 
      int m_1; 
      int m_2; 

    public: 
      Motor_pwm( int _m_1, int _m_2);
      void forward(int speed); 
      void reverse(int speed); 
      void Motor_run(int speed, int dir); 
      void stop();
};

class Motor_basic {
    private: 
      int m_1; 
      int m_2; 

    public: 
      Motor_basic(int _m_1, int _m_2);
      void forward(int speed); 
      void reverse(int speed); 
      void Motor_run(int speed, int dir); 
      void stop();
};

class Robot {
    private:
      String mac_id; 
      char key; 
      Motor_pwm M1; 
      Motor_pwm M2; 
      Motor_basic M3; 
      Motor_basic M4; 

      uint8_t rx_byte; 
      uint8_t rx_frame[10]; 
      uint32_t rx_data; 

    
    public: 
      //Robot(); 

      // Activate robot and setting
      void begin();   // Setup pinmode and setup bluetooth 
      void begin(int level);   // Setup your level code of you
      void beginUSS();
      void beginCP();
      void beginLCD();
      void beginOLED();
      void beginLINE();

      void Set_key(char key);

      // Motor 1
      void M1_forward(int speed); 
      void M1_reverse(int speed); 
      void M1_run(int speed, int dir); 
      void M1_stop();

      // Motor 2
      void M2_forward(int speed);
      void M2_reverse(int speed);
      void M2_run(int speed, int dir);
      void M2_stop();

      // Motor 3 ( cannot control Speed, speed fix MAX )
      void M3_forward(int speed);
      void M3_reverse(int speed);
      void M3_run(int speed, int dir);
      void M3_stop();

      // Motor 4 ( cannot control Speed, speed fix MAX )
      void M4_forward(int speed);
      void M4_reverse(int speed);
      void M4_run(int speed, int dir);
      void M4_stop();

      // Receiver
      void GetData();                  // Get data from Receiver. 
      void PushData(int stt, int val); // Position and val of data. Don't usualy call this function!

      // Detail control Servo motor very simple.
      void Servo_D4(int angle); 
      void Servo_D3(int angle); 
      void Servo_A3(int angle); 
      void Servo_A2(int angle); 

      // Coltrol Led & Buzzer
      void Led(uint8_t stt_led); 
      void Buzzer(uint8_t stt_buz); 

      // Ultrasolic sensor
      void UsDistance();



};

#endif
