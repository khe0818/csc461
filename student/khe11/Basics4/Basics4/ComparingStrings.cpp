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
	return strcmp(s1,s2);
}

int StringCompare_2( const char  * const s1, const char * const s2)
{
	// using memcmp() & strlen()

	return memcmp(s1,s2, strlen(s1));
}

int StringCompare_3( const char  * const s1, const char * const s2)
{
	// using char by char comparisions
	int results = 0;
	for (unsigned int i = 0; i < strlen(s1); i++) {
		if (s1[i] < s2[i]) {
			results = -1;
			break;
		}
		else if (s1[i] == s2[i]) {
			results = 0;
		}
		else {
			results = 1;
			break;
		}
	}
	return results;
}

// ---  End of File ---------------
