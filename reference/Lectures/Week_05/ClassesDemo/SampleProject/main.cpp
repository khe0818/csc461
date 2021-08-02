//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2017
// Optimized C++
//----------------------------------------------------------------------------- 

#include <stdio.h>
#include "Trace.h"

class A
{
public:
	A()
		: a0(5)
	{
		Trace::out("A: default constructor()\n");
	}

	A(const A & tmp)
		: a0(tmp.a0)
	{
		Trace::out("A: copy constructor() \n");
	}

	A(int v0)
		:a0(v0)
	{
		Trace::out("A: specialized constructor() \n");
	}

	A & operator = (const A &tmp)
	{
		this->a0 = tmp.a0;
		Trace::out("A: assignment operator = n");
		return *this;
	}

	~A()
	{
		Trace::out("A: ~A() destructor \n");
	}

	A operator + (const A &tmp)
	{
		A result;
		result.a0 = this->a0 + tmp.a0;
		Trace::out("A: addition operator \n");
		return result;
	}

	// data
	int a0;
};

class B : public A
{
public:
	B()
		: b0(55)
	{
		Trace::out("B: default constructor () \n");
	}

	B(const B & tmp)
		: b0(tmp.b0)
	{
		Trace::out("B: copy constructor () \n");
	}

	B(int v0, int v2)
		:A(v0), b0(v2)
	{
		Trace::out("B: specialized constructor B(int,int) \n");
	}

	B & operator = (const B &tmp)
	{
		this->b0 = tmp.b0;
		// a is handled in base class
		Trace::out("B: assignment operator = \n");
		return *this;
	}

	~B()
	{
		Trace::out("B: ~B() destructor \n");
	}

	B operator + (const B &tmp)
	{
		B result;
		result.b0 = this->b0 + tmp.b0;
		// a is handled in base class
		Trace::out("B: addition operator\n");
		return result;
	}

	B operator - (const B &tmp)
	{
		Trace::out("B: subtraction operator\n");
		return B(this->a0 - tmp.a0,
				 this->b0 - tmp.b0);
	}

	// data
	int b0;
};


int main()
{
	A *pA = new B(1, 2);
	delete pA;

}