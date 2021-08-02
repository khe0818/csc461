//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef A_H
#define A_H

// ---> Do NOT change this file <----

template <typename T>
inline T const minA(T const& a, T const& b)
{

	T val;

	if (a > b)
	{
		val = b;
	}
	else
	{
		val = a;
	}

	return  val;
}

double A();


#endif

// ---  End of File ---------------
