//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "SortStrings.h"

#define STUBBED_VAR(x) (void *)x



void ReorderAlphabetical(const char * const inString, char * const outString )
{
	// 1) reorder the words in the string, words are separated with spaces
	// 2) sort words on alphabetical order, (a begin, z end)
	// 3) you don't know how many words 
	// 4) if dynamically create any buffers inside this routine, clean them up
	// 5) use strtok and strcat in your answer
	// 6) hint: qsort() - might be a good function to know

	STUBBED_VAR(outString);
	STUBBED_VAR(inString);
}



void ReorderWordLength(const char * const inString, char * const outString )
{
	// 1) reorder the words in the string, words are separated with spaces
	// 2) sort words on their word length order, (short, longest)
	// 3) you don't know how many words 
	// 4) if dynamically create any buffers inside this routine, clean them up
	// 5) use strtok and strcat in your answer
	// 6) hint: qsort() - might be a good function to know

	STUBBED_VAR(outString);
	STUBBED_VAR(inString);
}



// ---  End of File ---------------
