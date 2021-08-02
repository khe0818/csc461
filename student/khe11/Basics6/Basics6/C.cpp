//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

// Add headers as you see fit
#include <algorithm>
#include <set>
#include <vector>

#include "Framework.h"
#include "C.h"
#include "ZipCode.h"

// USED for Unit Tests
std::vector< ZipCode > UnitTest_ZipSort;
ZipCode UnitTest_Bee;
ZipCode UnitTest_Zip;

ZipCode data[] =
{
	ZipCode("Bug", 0xABCD),
	ZipCode("Dog", 0x1331),
	ZipCode("Cat", 0x8844),
	ZipCode("Pig", 0xBB77),
	ZipCode("Bee", 0xFFEE),
	ZipCode("Nbt", 0xCC99)
};

ZipCode JunkDataC{ "tmp", 0x0 };

// ADD CODE HERE:
struct cmpSecondLetter
{
	bool operator() (const ZipCode m, const ZipCode n) const
	{
		return m.s[1]  < n.s[1];
	}
};

bool flag(ZipCode m){
	return (m.zip == 0xBB77);
}


void Problem_3( )
{

	// ----------------------------------------------------
	// a) Insert the data into a stl:set in the order given.
	//    Use a compare function that sorts with the 2nd letter of the string 
	//          Smallest to largest
	//    Name the set: zippy
	// ----------------------------------------------------

		// ADD CODE HERE:
		std::set< ZipCode, cmpSecondLetter> zippy;
		for (int i = 0; i < sizeof(data)/ sizeof(ZipCode); i++) {
			zippy.insert(data[i]);
		}
	// <-- REPLACE this LINE... shuts up warnings, its 100% wrong
	 // <-- REPLACE this LINE... shuts up warnings, its 100% wrong

		// ---------------------------------------------------------------------
		// Copies STL to gobal for unit test (Do NOT Remove or modify next line)
		// ---------------------------------------------------------------------
		UnitTest_ZipSort.assign(zippy.begin(), zippy.end());
		
	// ----------------------------------------------------
	// b)  Find node {"Bee", 0xFFEE} in the set
	//     use the complete node in the search
	//     Initialize the iterator where it found the node
	//
	//     Name the set iterator: zippy_it
	// ----------------------------------------------------
		std::set< ZipCode, cmpSecondLetter>::iterator zippy_it = zippy.find({ "Bee", 0xFFEE });
		// ADD CODE HERE:


		// ---------------------------------------------------------------------
		// Copies STL to gobal for unit test (Do NOT Remove or modify next line)
		// ---------------------------------------------------------------------
		UnitTest_Bee = *zippy_it;

	// ----------------------------------------------------
	// c)  Find the the string name associated with this zip data '0xBB77'
	//     Do not use the complete node, only the zip data
	//     Print the node contents and iterator address
	//
	//     NOTE: you can only use STL: set  - no maps!
	//     hint:  use a custom predicate
	//
	//     Name the set iterator: zippy_it
	// ----------------------------------------------------

		// ADD CODE HERE:

		zippy_it = std::find_if(zippy.begin(), zippy.end(), flag);
	//	Trace::out("%s 0x%x %x \n", zippy_it->s, zippy_it->zip, &zippy_it);
		// ---------------------------------------------------------------------
		// Copies STL to gobal for unit test (Do NOT Remove or modify next line)
		// ---------------------------------------------------------------------
		UnitTest_Zip = *zippy_it;

}

// End of File
