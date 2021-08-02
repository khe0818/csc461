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
	Trace::out("%s:\n", pString);
	//int lines = 0;
	unsigned char *p = (unsigned char *)pData;
	//memset()
	//unsigned char *iterator = (unsigned char*)pData;
	//Trace::out("  size of %d:", StructSize);
	//Trace::out("  iterator%s:\n ", iterator);
	//Trace::out("  %d: ", sizeof(iterator));
	//Trace::out("  %x: ", iterator[0]);
	//int i;

	
	int pads = 0;
	for (int i = 0; i < StructSize; i++) {



		if (i % 4 == 0) {
			Trace::out("  0x%02x:", i);
		}
		unsigned char *temp = p + i;
		
		if (*temp == 0xaa) {
			pads++;
			Trace::out(" %x ", *temp);
		}
		else {
			Trace::out(" %02x ", *temp);
		}
		if ((i + 1) % 4 == 0) {
			Trace::out("\n");
		}
	}
	Trace::out("------------------------\n");
	Trace::out("size : %d  padding : %d\n", StructSize, pads);
	//STUB_PLEASE_REPLACE(pData);
	//STUB_PLEASE_REPLACE(StructSize);
	//STUB_PLEASE_REPLACE(pString);

	Info info;
	info.NumBytesOfPadding = pads;
	info.NumTotalBytes = StructSize;

	return info;
}

// ---  End of File ---------------
