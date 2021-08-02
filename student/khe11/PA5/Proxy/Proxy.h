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



	~Vect2D() = default;


	Vect2D(const float floatX,const float floatY) :x(floatX), y(floatY)
	{
		
	}

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

	// Vect2D operator + ( const Vect2D &tmp ) const;
private:
	float x;
	float y;
};
struct VaddV
{
	const Vect2D &v1;
	const Vect2D &v2;

	VaddV(const Vect2D &t1, const Vect2D &t2)
		: v1(t1), v2(t2)
	{
	};

	operator Vect2D()
	{
		return Vect2D(v1.getX() + v2.getX(),
			v1.getY() + v2.getY());
	}
	const VaddV & operator = (const VaddV &r) = delete;

};




struct VaddVaddV
{
	const Vect2D &v1;
	const Vect2D &v2;
	const Vect2D &v3;

	VaddVaddV(const VaddV &t1, const Vect2D &t2)
		: v1(t1.v1), v2(t1.v2), v3(t2)
	{
	};

	operator Vect2D()
	{
		return Vect2D(v1.getX() + v2.getX() + v3.getX(),
			v1.getY() + v2.getY() + v3.getY());
	}
	const VaddVaddV& operator = (const VaddVaddV & r) = delete;
};



struct VaddVaddVaddV
{
	const Vect2D &v1;
	const Vect2D &v2;
	const Vect2D &v3;
	const Vect2D &v4;

	VaddVaddVaddV(const VaddVaddV &t1, const Vect2D &t2)
		: v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t2)
	{
	};

	operator Vect2D()
	{
		return Vect2D(v1.getX() + v2.getX() + v3.getX() + v4.getX(),
			v1.getY() + v2.getY() + v3.getY() + v4.getY());
	}
	const VaddVaddVaddV& operator=(const VaddVaddVaddV &r) = delete;
};



struct VaddVaddVaddVaddV
{
	const Vect2D &v1;
	const Vect2D &v2;
	const Vect2D &v3;
	const Vect2D &v4;
	const Vect2D &v5;

	VaddVaddVaddVaddV(const VaddVaddVaddV &t1, const Vect2D &t2)
		: v1(t1.v1), v2(t1.v2), v3(t1.v3), v4(t1.v4), v5(t2)
	{
	};

	operator Vect2D()
	{
		return Vect2D(v1.getX() + v2.getX() + v3.getX() + v4.getX() + v5.getX(),
			v1.getY() + v2.getY() + v3.getY() + v4.getY() + v5.getY());
	}
	const VaddVaddVaddVaddV& operator=(const VaddVaddVaddVaddV &r) = delete;
};
inline VaddV operator + (const Vect2D &t1, const Vect2D &t2)
{
	return VaddV(t1, t2);
}
inline VaddVaddV operator + (const VaddV &t1, const Vect2D &t2)
{
	return VaddVaddV(t1, t2);
};
inline VaddVaddVaddV operator + (const VaddVaddV &t1, const Vect2D &t2)
{
	return VaddVaddVaddV(t1, t2);
};

inline VaddVaddVaddVaddV operator + (const VaddVaddVaddV &t1, const Vect2D &t2)
{
	return VaddVaddVaddVaddV(t1, t2);
};


#endif






// ---  End of File ---------------