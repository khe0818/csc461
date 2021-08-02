//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include <stdio.h>
#include <string.h>

#include "CopyingStrings.h"

#define STUBBED_VAR(x) (void *)x
 

char *StringCopy_1( char * const dest, const char * const input)
{
	// using strcpy()
	STUBBED_VAR(dest);
	STUBBED_VAR(input);
	return 0;
}

char *StringCopy_2( char  * const dest, const char * const input)
{
	// using memcpy() and strlen()
	STUBBED_VAR(dest);
	STUBBED_VAR(input);
	return 0;
}

char *StringCopy_3( char  * const dest, const char * const input)
{
	// using char by char copies
	STUBBED_VAR(dest);
	STUBBED_VAR(input);
	return 0;
}

// ---  End of File ---------------
