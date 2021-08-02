//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#ifndef C_H
#define C_H

class Student
{
public:
	Student();
	~Student();

	static char *greeting;
};

class Italian : public Student
{
public:
	Italian();
	virtual ~Italian();
};

class French : public Student
{
public:
	French();
	virtual ~French();
};

class Spanish : public Student
{
public:
	Spanish();
	virtual ~Spanish();
};

#endif

// End of File