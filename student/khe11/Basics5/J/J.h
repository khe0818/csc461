//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#ifndef J_H
#define J_H

class Dog
{
public:
	int *pVal;
	Dog(int val);
	~Dog();

	static int GetVal(Dog d);
};

#endif

// End of File
