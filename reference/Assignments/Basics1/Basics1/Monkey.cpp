//----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include "Framework.h"

#include "Monkey.h"

int Monkey::getX()
{
	return this->x;
}

int Monkey::getY()
{
	return this->y;
}

char *Monkey::getStatus()
{
	return this->pStatus;
};

void Monkey::printStatus()
{
	Trace::out("Monkey (Status): %s\n", this->pStatus);
}


// END of File
