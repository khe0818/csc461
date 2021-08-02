//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef IMPLICIT_H
#define IMPLICIT_H

// ------------------------------------------------------------------------
//   Modify This File - to generate Errors to prevent implicit conversions
// ------------------------------------------------------------------------

class Vect
{
public:
	Vect();
	Vect(const Vect &tmp);
	const Vect & operator = (const Vect &tmp);
	~Vect();

	Vect(const float inX, const float inY, const float inZ);

	void setX(const float inX);
	void setY(const float inY);
	void setZ(const float inZ);

	void set(const float inX, const float inY, const float inZ);

	float getX() const;
	float getY() const;
	float getZ() const;

	Vect operator + (const Vect tmp) const;


private:
	float x;
	float y;
	float z;
	template<typename T, typename O, typename P> Vect(const T inX, const O inY, const P inZ);
	template <typename T, typename O, typename P> void set(T, O, P);
	template<typename T > void setX(const T inX);
	template<typename T > void setY(const T inY);
	template<typename T > void setZ(const T inZ);
	template<typename T > void getX() const;
	template<typename T > void getY() const;
	template<typename T > void getZ() const;

};

#endif

// ---  End of File ---------------
