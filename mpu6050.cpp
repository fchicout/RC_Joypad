#include "mpu6050.h"


const int MPU=0x68; 
int AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

void configureMPU6050(){
    Wire.begin();
    Wire.beginTransmission(MPU);
    Wire.write(0x6B); 
    Wire.write(0); 
    Wire.endTransmission(true);
}

void loadMPUData(){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  //Solicita os dados do sensor
  Wire.requestFrom(MPU,14,true);  
  //Armazena o valor dos sensores nas variaveis correspondentes
  AcX=Wire.read()<<8|Wire.read();  //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  AcY=Wire.read()<<8|Wire.read();  //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  //0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  //0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  //0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  delay(20);
}

float getTemperature(){
  loadMPUData();
	return (Tmp/340.00+36.53);
}

float* getAccelVect(){
  float accVect[3];
  loadMPUData();
  accVect[0] = AcX;
  accVect[1] = AcY;
  accVect[2] = AcZ;
	return accVect;
}

float* getGyroVect(){
  float gyroVect[3];
  loadMPUData();
  gyroVect[0] = GyX;
  gyroVect[1] = GyY;
  gyroVect[2] = GyZ;
	return gyroVect;
}

void logMPU(){
  char MPUData[40];
  char tempstring[10];
  loadMPUData();
  float temperature = (Tmp/340.00+36.53);
  dtostrf(temperature,3,2, tempstring);
  sprintf(MPUData, "%d, %d, %d, %s, %d, %d, %d", AcX, AcY, AcZ, tempstring, GyX, GyY, GyZ);
  logMessage(0,"mpu.csv", MPUData);
}