//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef C_H
#define C_H

// ---> Do NOT change this file <----

#include "C_Interface.h"

#define UNUSED_VAR(x)	x

template <typename T>
ReturnType const minC(T const& a, T const& b)
{
	UNUSED_VAR(&a);
	UNUSED_VAR(&b);
	return  TEMPLATE_2_ARG;
}

ReturnType const minC(int const& a, int const& b)
{
	UNUSED_VAR(&a);
	UNUSED_VAR(&b);
	return NON_TEMPLATE_INT_ARG;
}

template <typename T>
ReturnType const minC(T const& a, T const& b, T const& c)
{
	UNUSED_VAR(&a);
	UNUSED_VAR(&b);
	UNUSED_VAR(&c);
	return  TEMPLATE_3_ARG;
}

#endif

// ---  End of File ---------------
