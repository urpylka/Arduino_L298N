/*
	Dynamic_control.cpp - Класс для плавного управления системой из двух двигателей.
	Created by Smirnov Artem, September 3, 2014.
*/
#include <Motor.h>
#include <Arduino.h>
Dynamic_control::Dynamic_control(Motor M1, Motor M2)
{
	_M1 = M1;
	_M2 = M2;
};
void Dynamic_control::_dSmooth(int lSpeed, int rSpeed, int time)
{
	//может быть надо оба сажать до определенной скорости, а не до нуля
	_lSpeed = lSpeed;
	_rSpeed = rSpeed;
	//надо бы добавить изначальное чтение значений в регистрах,
	//чтобы разгон делать на от постоянной величины (50),
	//либо задавать величину от которой будет вестись разгон
	int maxSpeed;
	if (_lSpeed < _rSpeed) maxSpeed = _rSpeed; else maxSpeed = _lSpeed;
	for (int i = 50; i<=maxSpeed; i++)
	{
		if (i<=_lSpeed) _M1.setSpeed(i);
		if (i<=_rSpeed) _M2.setSpeed(i);
		delay(time); //чем больше это значение, тем медленнее разгоняется двигатель и наоборот
	}
};
void Dynamic_control::dSmoothRun(bool direction, int lSpeed, int rSpeed)
{
	_lSpeed = lSpeed;
	_rSpeed = rSpeed;
	if (direction)
	{
		_M1.setDirection(1);
		_M2.setDirection(1);
	}
	else
	{
		_M1.setDirection(0);
		_M2.setDirection(0);
	}
	_dSmooth(_lSpeed, _rSpeed, 30);
};
void Dynamic_control::dReversal(bool direction, int lSpeed, int rSpeed)
{
	_lSpeed = lSpeed;
	_rSpeed = rSpeed;
	if (direction)
	{
		_M1.setDirection(1);
		_M2.setDirection(0);
	}
	else
	{
		_M1.setDirection(0);
		_M2.setDirection(1);
	}
	_dSmooth(_lSpeed, _rSpeed, 30);
};
void Dynamic_control::dSmoothStop(int time)
{
	int maxSpeed;
	if (_lSpeed < _rSpeed) maxSpeed = _rSpeed; else maxSpeed = _lSpeed;
	for (int i = maxSpeed; i>0; i--)
	{
		if (i<_lSpeed) _M1.setSpeed(i);
		if (i<_rSpeed) _M2.setSpeed(i);
		delay(time); //чем больше это значение, тем медленнее разгоняется двигатель и наоборот
	}
};
