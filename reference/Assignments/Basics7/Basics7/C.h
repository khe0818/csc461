//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef C_H
#define C_H

// Do not change these classes,
// Feel free to add debug information, 
// but do not rearrange!

class C
{
public:
	C()
	: x(5), y(6)
	{
		// Label:  0xc001
	}

	virtual int weight()
	{
		// Label:  0xc002
		int sum = this->x + this->y;
		return (sum);
	}

	int getX()
	{
		// Label:  0xc003
		return this->x;
	}

	int getY()
	{
		// Label:  0xc004
		return this->y;
	}

	~C()
	{
		// Label:  0xc005
	}

protected:
	int x;
	int y;
};

class D : public C
{
public:
	D()
	: z(7)
	{
		// Label:  0xc006
	}

	int weight( )
	{
		// Label:  0xc007
		int sum = this->x + this->y + this->z;
		return (sum);
	}

	int getZ()
	{
		// Label:  0xc008
		return this->z;
	}

	~D()
	{
		// Label:  0xc009
	}


private:
	int z;

};

#endif

// ---  End of File ---------------
