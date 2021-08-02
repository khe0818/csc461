//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef G_H
#define G_H

// Change this file
//
// There should be two classes defined in this header
//     Generalized Template class
//     Partial Specialization class
//
// Apppend to the bottom of file

template <typename R, typename S>
class container
{
public:
	const R getData0();
	const S getData1();
	void setData0(const R val);
	void setData1(const S val);

private:
	R rVal;
	S sVal;
};

template <typename R, typename S>
const R container<R, S>::getData0()
{
	return rVal;
}

template <typename R, typename S>
const S container<R, S>::getData1()
{
	return sVal;
}

template <typename R, typename S>
void container<R, S>::setData0(const R val)
{
	this->rVal = val;
}

template <typename R, typename S>
void container<R, S>::setData1(const S val)
{
	this->sVal = val;
}

template <typename R>
class container<R, int>
{
public:
	const R getData0() 
	{
		return rVal;
	}

	const int getData1() 
	{
		return sVal;
	}

	void setData0(const R val)
	{
		this->rVal = val;
	}

	void setData1(const int val);

private:
	R rVal;
	int sVal;
};

template <typename R>
void container<R, int>::setData1(const int val)
{
	this->sVal = val*3;
}

// Create a partial specializaton on S for second type is int
// In this partial specializaton, have the integer store 3x the input value
//
// ---> add partial specialization below:

// do your magic here:


#endif

// ---  End of File ---------------
