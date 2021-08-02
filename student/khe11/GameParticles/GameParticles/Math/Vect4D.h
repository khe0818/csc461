//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

// This is a 4 dimensional Vect4D class
#ifndef Vect4D_H
#define Vect4D_H

// includes
#include "Enum.h"
#include<xmmintrin.h>
#include<smmintrin.h>

// Foward Declarations
class Matrix;

// class
class Vect4D
{
public:
	friend class Matrix;

	Vect4D() {
		this->_m = _mm_set_ps(1.0f, 0.0f, 0.0f, 0.0f);
	}
	Vect4D(const __m128 & x):_m(x)
	{

	}
	Vect4D(const float tx, const float ty, const float tz, const float tw = 1.0f) {
		this->_m = _mm_set_ps(tw, tz, ty, tx);
	}
	~Vect4D() = default;
	
	void set(const float tx, const float ty, const float tz, const float tw = 1.0f) {
		this->_m = _mm_set_ps(tw, tz, ty, tx);
	}

	void operator += (const Vect4D &t) {
		this->_m = _mm_add_ps(this->_m, t._m);
	}
	Vect4D operator + (Vect4D t) {
		return Vect4D(_mm_add_ps(this->_m, t._m));
	}
	Vect4D operator - (Vect4D t) {
		return Vect4D(_mm_cvtss_f32(_mm_sub_ps(_mm_set1_ps(this->x), _mm_set1_ps(t.x))), _mm_cvtss_f32(_mm_sub_ps(_mm_set1_ps(this->y), _mm_set1_ps(t.y))), _mm_cvtss_f32(_mm_sub_ps(_mm_set1_ps(this->z), _mm_set1_ps(t.z))));
	}
	Vect4D operator * (float scale) {
		Vect4D tmp;

		tmp.x = this->x * scale;
		tmp.y = this->y * scale;
		tmp.z = this->z * scale;

		return tmp;
	}
	void Vect4D::Norm(Vect4D& out)
	{
		__m128 mag = _mm_sqrt_ps(_mm_dp_ps(_m, _m, 0X77));

		if (0.0f < _mm_cvtss_f32(mag))
		{
			out._m = _mm_div_ps(_m, mag);
			out.w = 1.0f;
		}
	}
	void Cross(Vect4D &vin, Vect4D &vout) {
		vout.x = (y*vin.z - z * vin.y);
		vout.y = (z*vin.x - x * vin.z);
		vout.z = (x*vin.y - y * vin.x);
		vout.w = 1.0f;
	}

	float &operator[](VECT_ENUM e) {
			switch (e)
			{
			case 0:
				return x;
				break;
			case 1:
				return y;
				break;
			case 2:
				return z;
				break;
			case 3:
				return w;
				break;
			default:
				assert(0);
				return x;
			}
	}

public:
	union
	{
		__m128 _m;

		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};
};

#endif  

// End of file

