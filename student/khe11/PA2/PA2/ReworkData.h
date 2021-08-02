//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#ifndef REWORK_DATA_H
#define REWORK_DATA_H

struct DataA
{
	double r;
	char a;
	char b;
	char pad0;
};

struct DataB
{
	DataA da;
	int i;
	char a;
	char b;
	
};

struct DataC
{
	double r;
	int i;
	char a;
	bool f;
	char pad0;
};

struct DataD
{
	double r;
	int i;
	char b;
	char a;
	char pad0;
};

struct DataE
{
	double r;
	char name[12];
	int x;
	int *p;
	char a;
	char c;
};

struct Vect
{
	float vx;
	float vy;
	float vz;
	float vw;
	char b;
	char a;
};

struct DataF
{
	Vect v;
	int i;
	int j;
	char b;
	char c;
};


#endif

// ---  End of File ---------------
