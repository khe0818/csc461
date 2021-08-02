//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#ifndef REWORK_DATA_H
#define REWORK_DATA_H

struct DataA
{
	char a;
	double r;
	char b;
};

struct DataB
{
	int i;
	char a;
	DataA da;
	char b;
};

struct DataC
{
	double r;
	char a;
	int i;
	bool f;
};

struct DataD
{
	int i;
	char a;
	double r;
	char b;
};

struct DataE
{
	char name[12];
	int x;
	char a;
	double r;
	int *p;
	char c;
};

struct Vect
{
	float vx;
	float vy;
	char a;
	float vz;
	float vw;
	char b;
};

struct DataF
{
	int i;
	Vect v;
	char c;
	int j;
	char b;
};


#endif

// ---  End of File ---------------
