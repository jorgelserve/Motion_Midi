// MPU-6050 Short Example Sketch
// By Arduino User JohnChi
// August 17, 2014
// Public Domain
#include<Wire.h>
#include "notas.h"
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t x,y;

void setup(){
  Wire.begin();   //habre la comunicacion con el giroscopio
  Wire.beginTransmission(MPU_addr);   //inicia la comunicacion con el giroscopio
  Wire.write(0x6B);  // PWR_MGMT_1 pide datos (giroscopio)
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(31250);

}
void loop(){
  
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  x=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  y=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)

  int val = map(x,0,6000,0,13);
  
  int nota;
  switch(val) {
    
    case 0:
    nota=DO;
    noteOn(0x90,nota,0x45);
    delay(500);
    noteOn(0x90,nota,0x00);
    break;
    
    case 1:
    nota=DO#;
    noteOn(0x90,nota,0x45);
    delay(500);
    noteOn(0x90,nota,0x00);
    break;

    case 2:
    nota=RE;
    noteOn(0x90,nota,0x45);
    delay(500);
    noteOn(0x90,nota,0x00);
    break;

    case 3:
    nota=RE#;
    noteOn(0x90,nota,0x45);
    delay(500);
    noteOn(0x90,nota,0x00);
    break;

    case 4:
    nota=MI;
    noteOn(0x90,nota,0x45);
    delay(500);
    noteOn(0x90,nota,0x00);
    break;

    case 5:
    nota=FA;
    noteOn(0x90,nota,0x45);
    delay(500);
    noteOn(0x90,nota,0x00);
    break;
    
    case 6:
    nota=FA#;
    noteOn(0x90,nota,0x45);
    delay(500);
    noteOn(0x90,nota,0x00);
    break;

    case 7:
    nota=SOL;
    noteOn(0x90,nota,0x45);
    delay(500);
    noteOn(0x90,nota,0x00);
    break;

    case 8:
    nota=SOL#;
    noteOn(0x90,nota,0x45);
    delay(500);
    noteOn(0x90,nota,0x00);
    break;

    case 10:
    nota=LA;
    noteOn(0x90,nota,0x45);
    delay(500);
    noteOn(0x90,nota,0x00);
    break;

    case 11:
    nota=LA#;
    noteOn(0x90,nota,0x45);
    delay(500);
    noteOn(0x90,nota,0x00);
    break;

    case 12:
    nota=SI;
    noteOn(0x90,nota,0x45);
    delay(500);
    noteOn(0x90,nota,0x00);
    break;

    case 13:
    nota=DO1;
    noteOn(0x90,nota,0x45);
    delay(500);
    noteOn(0x90,nota,0x00);
    break;
  }
  noteOn(0x00,nota,0x00);
}

void noteOn(int cmd, int pitch, int velocity) {
    Serial.write(cmd);
    Serial.write(pitch);
    Serial.write(velocity);
  }
