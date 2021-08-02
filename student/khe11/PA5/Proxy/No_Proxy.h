//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef NO_PROXY_H
#define NO_PRoxy_H

// DO NOT CHANGE THIS FILE

class Vect2D_No_Proxy
{
public:
	Vect2D_No_Proxy()
	: x(0.0f), y(0.0f)
	{
	};

	~Vect2D_No_Proxy()
	{
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

	float getX() const
	{
		return this->x;
	};

	float getY() const
	{
		return this->y;
	};

	Vect2D_No_Proxy operator + (const Vect2D_No_Proxy &tmp) const;

private:
	float x;
	float y;

};

#endif

// ---  End of File ---------------
