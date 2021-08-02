//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef PROXY_H
#define PROXY_H

// Modify This File

class Vect2D
{
public:
	Vect2D()
		: x(0.0f), y(0.0f)
	{
	};

	~Vect2D()
	{
	};

	float getX() const
	{
		return this->x;
	};

	float getY() const
	{
		return this->y;
	};

	void setX(const float inX)
	{
		this->x = inX;
	};

	void setY(const float inY)
	{
		this->y = inY;
	};

	void set(const float inX, const float inY)
	{
		this->x = inX;
		this->y = inY;
	};


	//-----------------------------------------------
	// Rules... this function cannot be inlined
	//-----------------------------------------------

	Vect2D operator + ( const Vect2D &tmp ) const;

private:
	float x;
	float y;
};

#endif

// ---  End of File ---------------