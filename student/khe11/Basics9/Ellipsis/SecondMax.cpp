//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <vector>
#include <algorithm>
#include <trace.h>
// Add functions and includes as needed
#define UNUSED_VAR(v) ((void *)v)

int SecondMax(int count, ...)
{
	va_list args;
	va_start(args, count);
	int i;
	int max = 0;
	int secMax = 0;
	int val;
	for (i = 0; i < count; i++)
	{
		val = va_arg(args, int);
		if (max < val) {
			secMax = max;
			max = val;
		}
		if (secMax < val && val < max) {
			secMax = val;
		}

	}
	// Do your magic here:
	

	return secMax;
}

// ---  End of File ---------------
