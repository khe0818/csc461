//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "RVO.h"

// Modify This File

Vect2D::Vect2D()
	: x(0.0f), y(0.0f)
{
};

Vect2D::Vect2D(const float inX, const float inY)
{
	this->x = inX;
	this->y = inY;
};

Vect2D::~Vect2D()
{
};

void Vect2D::setX(const float inX)
{
	this->x = inX;
};

void Vect2D::setY(const float inY)
{
	this->y = inY;
};

void Vect2D::set(const float inX, const float inY)
{
	this->x = inX;
	this->y = inY;
};

float Vect2D::getX() const
{
	return this->x;
};

float Vect2D::getY() const
{
	return this->y;
};

Vect2D Vect2D::operator + (const Vect2D &tmp) const
{
	Vect2D sum;

	sum.x = this->x + tmp.x;
	sum.y = this->y + tmp.y;

	return (sum);
};

Vect2D Vect2D::operator - (const Vect2D &tmp) const
{
	Vect2D sum;

	sum.x = this->x - tmp.x;
	sum.y = this->y - tmp.y;

	return (sum);
};

Vect2D Vect2D::operator * (const float scale) const
{
	Vect2D tmp;

	tmp.x = this->x * scale;
	tmp.y = this->y * scale;

	return (tmp);
};

// Assume scale != 0.0f
Vect2D Vect2D::operator / (const float scale) const
{
	Vect2D tmp;

	tmp.x = this->x / scale;
	tmp.y = this->y / scale;

	return (tmp);
};

// ---  End of File ---------------
