//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef MIDDLEWARE_NATIVE_H
#define MIDDLEWARE_NATIVE_H

// ----------------------------------------------------------------------
//
// Problem 5
//
// Related files:  MiddlewareNative.h, Wrapper.h
//
// Rules: 
//     For this problem, you are wrapping a poor interface provided by a middleware vendors
//
//     This is a mockup of a middleware class
//         Too many functions and/or incorrect were provided to the End User
//
// The GameVect class needs to derive privately from Vect2D_Native
//
// Requirements:
//
//     1) variables:  x, y should be private
//     2) prevent methods setID() and getID() from being called
//     3) Rework getX() and getY() to take float references
//     4) prevent the original getX() and getY() from being called
//     5) allow setX() and setY() to be called as is.
//
// The unit test has a section that is #if 0 - toggle it to make sure your code is producing the correct errors
//
// Rules:
//
//     1) Do NOT modify class Vect2D_Native
//     2) GameVect class in Wrapper.h must derive privately from Vect2D_Native
//     3) Refactor GameVect class to meet the above requirements
//
// ----------------------------------------------------------------------

// -----------------------------------------------------
// DO NOT MODIFY this FILE
// -----------------------------------------------------

class Vect2D_Native
{
public:
	Vect2D_Native();

	void setX(float val);
	void setY(float val);

	float getX();
	float getY();

	void setID(int val);
	int getID();

	// Data:
	//       - Yes its public (that's the problem)
	float x;
	float y;
	static int id;
};

#endif

// End of File
