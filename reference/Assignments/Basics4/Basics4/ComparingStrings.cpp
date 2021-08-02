//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include <stdio.h>
#include <string.h>

#include "ComparingStrings.h"

#define STUBBED_VAR(x) (void *)x

int StringCompare_1( const char  * const s1, const char * const s2)
{
	// using strcmp()
	STUBBED_VAR(s1);
	STUBBED_VAR(s2);
	return -33;
}

int StringCompare_2( const char  * const s1, const char * const s2)
{
	// using memcmp() & strlen()
	STUBBED_VAR(s1);
	STUBBED_VAR(s2);
	return -33;
}

int StringCompare_3( const char  * const s1, const char * const s2)
{
	// using char by char comparisions
	STUBBED_VAR(s1);
	STUBBED_VAR(s2);
	return -33;
}

// ---  End of File ---------------
