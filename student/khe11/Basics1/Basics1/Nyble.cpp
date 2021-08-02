//----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------

#include "Nyble.h"
#include <stdio.h>
#include <string.h>

Nyble::Nyble() 
{
	this->data = 0;
}
Nyble::~Nyble() {
	this->data = 0;
}
Nyble::Nyble(unsigned int m) {
	this->data = (unsigned char)(m & 0x0f) ;
}
Nyble Nyble::operator = (const Nyble & m) {
	this->data = m.data;
	return *this;
}
Nyble::Nyble(const Nyble &m) {
	this->data = m.data;
}


// nyble  + Nyble
 Nyble Nyble::operator+(const Nyble & m) {
	
		return Nyble(this->data + m.data);
}
// nyble + constant
 Nyble Nyble::operator+(int m) {
		this->data = (this->data + (unsigned int)m) ;

	return Nyble(this ->data);
}
// constant + Nyble
Nyble operator+(int m, const Nyble & n) {
	
		return Nyble((unsigned char)((n.data + (unsigned char)m) & 0x0f));

	
}
Nyble Nyble::operator +=(const Nyble & m) {
	
		this->data = (unsigned char)((this->data + m.data) & 0x0f);
	return *this;
}


// ones complement
Nyble Nyble::operator~() {
	Nyble temp((~(this->data)) & 0x0f);

	return temp;
}


// unary +
Nyble operator+(const Nyble & m) {
	return Nyble((unsigned char)(m.data + 2));
}
Nyble::operator unsigned int() {
	return (unsigned char)this->data + 3;
}

//pre-increment
Nyble Nyble::operator ++() {

	char tmp = this->data + 1;
	this->data = tmp & 0x0f;
	return Nyble(tmp);
}
//post-increment
Nyble Nyble::operator++(int n) {
	char tmp = this->data;
	this->data = (this->data + 1) & 0x0f;
	n = n;
	return Nyble(tmp & 0x0f);
}


// << operator
Nyble operator<<(const Nyble & m, int n)
{	char temp = m.data << n;
	char falloff = temp & 0xf0;
	falloff = falloff >> 4;
	temp = temp & 0x0f;

	
	return Nyble((unsigned char)(temp | falloff));
}
unsigned char Nyble::getData()
{
	return this->data;
}


// End of file
