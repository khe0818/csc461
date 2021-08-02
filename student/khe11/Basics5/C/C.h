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
	static char *greeting;
	virtual	~Student();
	
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