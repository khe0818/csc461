//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include "Framework.h"

#include "Align.h"

#define STUB_PLEASE_REPLACE(x) (x)

//-------------------------------------------------------------
// PrintME()
//
// Write your alignment printing function here
//-------------------------------------------------------------

Align::Info Align::PrintME(void *pData, int StructSize, char *pString)
{
	// Use Trace::out(...) to display the data layout and padding
	// Mimic the KeenanSampleOutput_Debug.txt

        // EXACtLY or the grading system will give a 0
	
	STUB_PLEASE_REPLACE(pData);
	STUB_PLEASE_REPLACE(StructSize);
	STUB_PLEASE_REPLACE(pString);

	Info info;
	info.NumBytesOfPadding = 0;
	info.NumTotalBytes = 0;

	return info;
}

// ---  End of File ---------------
