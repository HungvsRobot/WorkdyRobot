/*===========================================================
- Update 23/Mar/2025 by HungĐK :u
- Copyright belongs to HungĐK - User-customizable open source.
- Functions to configure I/O, Control robot, Receiver process.
- Social Links: https://www.facebook.com/hung.tola.52/
- Github: https://www.github.com/HungvsRobot
===========================================================*/
// Workdy.cpp

#include "Workdy.h"
#include <Arduino.h>

SoftwareSerial BTrobot(A2, A3);


// Motor_pwm //============================================================//
Motor_pwm::Motor_pwm(int _m_1, int _m_2) : m_1(_m_1), m_2(_m_2) {
    pinMode(m_1, OUTPUT);
    pinMode(m_2, OUTPUT);
}

void Motor_pwm::forward(int speed){
    digitalWrite(m_2, LOW); 
    analogWrite(m_1, speed);
}

void Motor_pwm::reverse(int speed){
    digitalWrite(m_1, LOW); 
    analogWrite(m_2, speed);
}

void Motor_pwm::Motor_run(int speed, int dir){
    if(dir){
        forward(speed);
    }else{
        reverse(speed);
    }
} 

void Motor_pwm::stop(){
    analogWrite(m_1, 0);
    analogWrite(m_2, 0);
}


// Motor_basic //============================================================//
Motor_basic::Motor_basic( int _m_1, int _m_2){
    m_1 = _m_1; 
    m_2 = _m_2; 
    pinMode(m_1, OUTPUT);
    pinMode(m_2, OUTPUT);
}

void Motor_basic::forward(int speed){
  digitalWrite(m_2, 0); 
  digitalWrite(m_1, 1);
} 

void Motor_basic::reverse(int speed){
  digitalWrite(m_1, 0); 
  digitalWrite(m_2, 1);
}  

void Motor_basic::Motor_run(int speed, int dir){
  speed = 0;
  if(dir){
    digitalWrite(m_2, 0); 
    digitalWrite(m_1, 1); 
  }else{
    digitalWrite(m_1, 0); 
    digitalWrite(m_2, 1); 
  }
}

void Motor_basic::stop(){
  digitalWrite(m_1, 0);
  digitalWrite(m_2, 0);
}

// ROBOT //============================================================//
void Robot::begin(){\
  BTrobot.begin(9600);
}

// Motor 1 - PWM Control
void Robot::M1_forward(int speed) { M1.forward(speed); }
void Robot::M1_reverse(int speed) { M1.reverse(speed); }
void Robot::M1_run(int speed, int dir) { M1.Motor_run(speed, dir); }
void Robot::M1_stop() { M1.stop(); }

// Motor 2 - PWM Control
void Robot::M2_forward(int speed) { M2.forward(speed); }
void Robot::M2_reverse(int speed) { M2.reverse(speed); }
void Robot::M2_run(int speed, int dir) { M2.Motor_run(speed, dir); }
void Robot::M2_stop() { M2.stop(); }

// Motor 3 - Basic Control (Max speed only)
void Robot::M3_forward(int speed) { M3.forward(speed); }
void Robot::M3_reverse(int speed) { M3.reverse(speed); }
void Robot::M3_run(int speed, int dir) { M3.Motor_run(speed, dir); }
void Robot::M3_stop() { M3.stop(); }

// Motor 4 - Basic Control (Max speed only)
void Robot::M4_forward(int speed) { M4.forward(speed); }
void Robot::M4_reverse(int speed) { M4.reverse(speed); }
void Robot::M4_run(int speed, int dir) { M4.Motor_run(speed, dir); }
void Robot::M4_stop() { M4.stop(); }

// Buzzer
void Robot::Buzzer(uint8_t stt_buz){pinMode(A0, OUTPUT); digitalWrite(A0, stt_buz);}
// Led
void Robot::Led(uint8_t stt_led){pinMode(A1, OUTPUT); digitalWrite(A1, stt_led);}



// Bluetooth process
void Robot::GetData(){
  if(BTrobot.available()){
    for(int i = 0; i < 10; i++){
      rx_frame[i] = BTrobot.read(); 
    }
  }
  if (rx_frame[0] == 0xFF && rx_frame[1] == 0xFF) { 
      uint32_t rxdata = (uint32_t(rx_frame[2]) << 24) | 
                        (uint32_t(rx_frame[3]) << 16) | 
                        (uint32_t(rx_frame[4]) << 8)  | 
                        (uint32_t(rx_frame[5]));

      Serial.print("Valid frame, rxdata = 0x");
      Serial.println(rxdata, HEX); 
  } 
}

void Robot::PushData(int stt, int val){
  
}








