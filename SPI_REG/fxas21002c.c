#include "stm32f10x.h"
#include "fxas21002c.h"
#include "spi.h"

raw_data raw;
float angle_new;
float R0;
float post_z;
int16_t cal_x, cal_y, cal_z;
angular_data angle ,x_pri, x_post, v_pri, v_post, alfa, beta;

void GyroReadData(void){
		//uint8_t Data[6];
		post_z = angle.z;
	//for(int i =0; i < 4; i++){
		SpiTransmit(FXAS21002C_H_OUT_X_MSB, 6);
		raw.x = (int16_t)(SpiRxBuffer[0] << 8 | SpiRxBuffer[1]) >> 2;
		raw.y = (int16_t)(SpiRxBuffer[2] << 8 | SpiRxBuffer[3]) >> 2;
		raw.z = (int16_t)(SpiRxBuffer[4] << 8 | SpiRxBuffer[5]) >> 2;
		// zero te gyro and get angular velocity 15.625
		angle.z = (float)((raw.z-cal_z)*0.0078125); //31.25
	//}
}

void GyroCalibrate(void){
	for(uint8_t i = 0; i < 100; i++){
		GyroReadData();
		cal_x += raw.x;
		cal_y += raw.y;
		cal_z += raw.z;
		//delay
	}
	cal_x = cal_x/100;
	cal_y = cal_y/100;
	cal_z = cal_z/100;
}

float GetAngle(float dt, float a, float b){
	float angle2;
	angle2 = (((a+b)/2.0)*dt);
	angle_new +=angle2;
	//gyroRate = (a - 1) * 7.8125;
	//angle += gyroRate / 100.0;
	// sensitivity 7.8125
	return angle_new;
}
