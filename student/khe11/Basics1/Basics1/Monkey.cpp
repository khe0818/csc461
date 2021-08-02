//----------------------------------------------------------------------------
// Copyright Ed Keenan 2018
// Optimized C++
//----------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include "Framework.h"

#include "Monkey.h"
// big four
using namespace std;
Monkey::Monkey():x(222),y(333), pStatus(new char[strlen("Initialized with default!") + 1])
{
	//memset(pStatus, '\0', strlen("Initialized with default!") + 1);
	strcpy_s(this->pStatus, strlen("Initialized with default!") + 1, "Initialized with default!");
	numStringsCreated++;
}

Monkey::Monkey(const Monkey & R):x(R.x),y(R.y)
{
	if (this != &R) {
		this->pStatus = new char[strlen(R.pStatus) + 1];
		strcpy_s(this->pStatus, strlen(R.pStatus) + 1, R.pStatus);
		numStringsCreated++;
	}

}

 Monkey Monkey::operator = (const Monkey & R){
	 if (this != &R) {
		 this->x = R.x;
		 this->y = R.y;
		 delete this->pStatus;
		 this->pStatus = new char[strlen(R.pStatus) + 1];
		 strcpy_s(this->pStatus, strlen(R.pStatus) + 1,  R.pStatus);
		 numStringsCreated++;
	 }
	return *this;
}
Monkey::~Monkey()
{	
	delete this->pStatus;
	numStringsDestroyed++;
	//Trace::out("Monkey (numStringsDestroyed): %d\n", this->numStringsDestroyed);
}


//speical constructor
Monkey::Monkey(int x):y(666)
{
	this->x = x;
	this->pStatus = new char[strlen("Initialized by user!") + 1];
	strcpy_s(this->pStatus, strlen("Initialized by user!") + 1, "Initialized by user!");
	numStringsCreated++;
	//delete(pStatus);
	Trace::out("Monkey (numStringsCreated): %d\n", this->numStringsCreated);
}

// special constructor
Monkey::Monkey(int x, int y):x(x), y(666), pStatus(new char[strlen("Initialized by user!") + 1])
{
	this->y = y;
	//memset(pStatus, '\0', strlen("Initialized by user!") + 1);
	strcpy_s(this->pStatus, strlen("Initialized by user!") + 1 , "Initialized by user!");
	numStringsCreated++;
	Trace::out("Monkey (numStringsCreated): %d\n", this->numStringsCreated);
}
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
