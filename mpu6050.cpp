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
  delay(10);
}

float getTemperature(){
  loadMPUData();
	return (Tmp/340.00+36.53);
}

float[] getAccelVect(){
  float accVect = float[3];
  loadMPUData();
  accVect[0] = AcX;
  accVect[1] = AcY;
  accVect[2] = AcZ;
	return accVect;
}

float[] getGyroVect(){
  float gyroVect = float[3];
  loadMPUData();
  gyroVect[0] = GyX;
  gyroVect[1] = GyY;
  gyroVect[2] = GyZ;
	return gyroVect;
}

void logMPU(){
  char* MPUData;
  strcat(MPUData, AcX); strcat(MPUData",");
  strcat(MPUData, AcY); strcat(MPUData",");
  strcat(MPUData, AcZ); strcat(MPUData",");
  strcat(MPUData, Tmp); strcat(MPUData",");
  strcat(MPUData, GyX); strcat(MPUData",");
  strcat(MPUData, GyY); strcat(MPUData",");
  strcat(MPUData, GyZ);
  logMessage(0,"mpu.csv", MPUData);
}