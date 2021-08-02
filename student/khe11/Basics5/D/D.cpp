//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include "D.h"

// ----------------------------------------------------------------------
//
// D - Project
//
// Rules: Fix the code below to have the correct number of components in Car
//
// ----------------------------------------------------------------------

Volkswagon::Volkswagon()
{
	wheelDrive = 2;
	numDoors = 4;
	wings = 0;
}

Audi::Audi()
{
	color = Color::Black;
	wheelDrive += 2;
}

// End of File