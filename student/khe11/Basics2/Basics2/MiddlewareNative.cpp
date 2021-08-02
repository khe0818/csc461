//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "MiddlewareNative.h"

// -----------------------------------------------------
// DO NOT MODIFY this FILE
// -----------------------------------------------------

Vect2D_Native::Vect2D_Native()
	: x(22.0f), y(33.0f)
{
	id++;
}

void Vect2D_Native::setX(float val)
{
	this->x = val;
}

void Vect2D_Native::setY(float val)
{
	this->y = val;
}

float Vect2D_Native::getX()
{
	return this->x;
}

float Vect2D_Native::getY()
{
	return this->y;
}

void Vect2D_Native::setID(int val)
{
	this->id = val;
}

int Vect2D_Native::getID()
{
	return this->id;
}

//-- End of File -------------------------------------------------------------- 