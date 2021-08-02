//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef ORDER_H
#define ORDER_H

// Add files include as needed
#include "HotDog.h"
#include "Names.h"

class Order 
{
public:
	// add code here (add more methods if desired)
	Order();

	// Public Methods (Required)
	Order(Name name);
	Name GetName();
	void SetName(Name name);
	void Add(HotDog *pDog);
	void Remove(HotDog *pDog);

	// Methods used for Testing and Internals (Required)
	HotDog *GetHead();
	Order *GetNext();
	Order *GetPrev();
	void SetNext(Order *pOrder);
	void SetPrev(Order *pOrder);


private:
	// Data: ---------------------------
	//        add code here

};

#endif

// ---  End of File ---------------
