/*
	Dynamic_control.h - заголовочный файл класса для управления
	двумя двигателями с через функции задания скорости и направления вращения
	Created by Smirnov Artem, September 3, 2014.
*/
#ifndef Dynamic_control_h
#define Dynamic_control_h
#include <Arduino.h>
class Dynamic_control
{
public:
	Dynamic_control(Motor M1, Motor M2);
	void dSmoothRun(bool direction, int lSpeed, int rSpeed); //моторы вращаются в одном направлении
	void dReversal(bool direction, int lSpeed, int rSpeed); //моторы вращаются в одном направлении
	void dSmoothStop(int delay); //плавная остановка (доступна при использовании класса Dynamic_control)
	//delay - задержка в цикле в милисекундах (чем больше, тем медленнее)
private:
	void _dSmooth(int lSpeed, int rSpeed, int delay);
	Motor _M1;
	Motor _M2;
	int _lSpeed;
	int _rSpeed;
};
#endif
