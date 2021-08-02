//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef E_H
#define E_H

// MODIFY this file
//
// Write the methods missing in the class template
//     You cannot change the private data
//     Writing a basic stack in terms of STL Vector 

#include "VectorWrapper.h"

#define UNUSED_VAR(x)	((void *)x)

template <typename T>
class StackE
{

public:
	// Write the following functions

	// push element
	void push(T const & data)
	{
		elems.push_back(data);
	}

	// pop element
	void pop()
	{
		elems.pop_back();

	}

	// return top element
	T top() const
	{
		return elems.back();
	}

	// return whether the stack is empty
	bool empty() const
	{
		return elems.empty();
	}

private:
	std::vector<T> elems;     // elements
};


#endif

// ---  End of File ---------------
