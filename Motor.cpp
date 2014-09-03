/*
	Motor.cpp - Класс для управления каждым из двигателем через контроллер на микросхеме L298N.
	Created by Smirnov Artem, September 3, 2014.
*/
#include <Motor.h>
#include <Arduino.h>
Motor::Motor(int PWM, int IN1, int IN2)
{
	pinMode(IN1, OUTPUT);
	pinMode(IN2, OUTPUT);
	_PWM = PWM;
	_IN1 = IN1;
	_IN2 = IN2;
};
void Motor::setDirection(bool direction)
{
	if (direction)
	{
		digitalWrite(_IN1, HIGH);
		digitalWrite(_IN2, LOW);
	}
	else
	{
		digitalWrite(_IN1, LOW);
		digitalWrite(_IN2, HIGH);
	}
};
void Motor::setSpeed(int speed)
{
	analogWrite(_PWM, speed);
};
