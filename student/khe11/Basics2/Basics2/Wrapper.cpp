//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "Wrapper.h"

// Add code here if needed
GameVect::GameVect():Vect2D_Native() {
	this->x = Vect2D_Native::getX();
	this->y = Vect2D_Native::getY();
}
void GameVect::setX(float xVal) {
	this->x = xVal;
}
void GameVect::setY(float yVal){
	this->y = yVal;
}
void GameVect::getX(float & xVal) {
	xVal = this->x;
}
void GameVect::getY(float & yVal)
{
	yVal = this->y;
}


float GameVect::getX()
{
	return Vect2D_Native::getX();

}
float GameVect::getY()
{
	return Vect2D_Native::getY();
}
void GameVect::setID(int val)
{
	this->id = val;
}
int GameVect::getID()
{
	return this->id;

}
//-- End of File -------------------------------------------------------------- 