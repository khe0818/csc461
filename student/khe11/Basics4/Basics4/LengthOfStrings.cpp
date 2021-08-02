//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include <stdio.h>
#include <string.h>

#include"LengthOfStrings.h"

#define STUBBED_VAR(x) (void *)x


size_t LengthOfString_1( const char  * const input)
{
	// using strlen()
	
	return (size_t)strlen(input);
}

size_t LengthOfString_2( const char  * const input)
{
	// using char by char
	
	int size = 0;
	const char*tmp = input;
	while (tmp[size] != '\0') {
		size++;
	}
	return (size_t)size;
}

// ---  End of File ---------------

