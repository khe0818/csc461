//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef STAND_H
#define STAND_H

// Add files include as needed
#include "Names.h"
#include "Order.h"

class Stand
{
public:
	// add code here (add more methods if desired)


	// Public Methods (Required)
	void Remove(Name name);
	void Add(Order *pOrder);
	int GetCurrOrders();
	int GetPeakOrders();
	
	// Methods used for Testing and Internals (Required)
	Order *GetHead();


private:
	// Data: ---------------------------
	//        add code here


};

#endif

// ---  End of File ---------------
