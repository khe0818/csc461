//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef HOTDOG_H
#define HOTDOG_H

// Add files include as needed
#include "Condiments.h"

class HotDog
{
public:
	// add code here (add more methods if desired)

	 
	// Public Methods (Required)
	void Minus(Condiments condiment);
	void Add(Condiments condiment);

	// Methods for Testing and Internals (Required)
	int GetCondiments();
	HotDog *GetNext();
	HotDog *GetPrev();
	void SetNext(HotDog *pDog);
	void SetPrev(HotDog *pDog);


private:
	// Data: ---------------------------
	//        add code here


};

#endif

// ---  End of File ---------------
