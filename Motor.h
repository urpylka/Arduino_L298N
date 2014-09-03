/*
	Motor.h - заголовочный файл класса для управления
	контроллером двигателей на микросхеме L298N
	Created by Smirnov Artem, September 2, 2014.
*/
#ifndef Motor_h
#define Motor_h
#include <Arduino.h>
class Motor
{
public:
	Motor(int PWM, int IN1, int IN2);
	void setDirection (bool direction); //true - left; false - right
	void setSpeed (int speed);
private:
	int _PWM;
	int _IN1;
	int _IN2;
};
#endif
