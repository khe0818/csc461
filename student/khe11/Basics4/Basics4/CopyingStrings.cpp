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
	strcpy_s(dest, strlen(input) + 1, input);
	return dest;
}

char *StringCopy_2( char  * const dest, const char * const input)
{
	// using memcpy() and strlen()
	memcpy(dest, input, strlen(input) + 1);
	return dest;
}

char *StringCopy_3( char  * const dest, const char * const input)
{
	// using char by char copies
	int i;
	for (i = 0; i < (int)strlen(input); i++) {
		dest[i] = input[i];
	}
	dest[i] = '\0';


	return dest;
}

// ---  End of File ---------------
