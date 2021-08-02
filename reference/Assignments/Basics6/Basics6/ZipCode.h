//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef ZIP_CODE_H
#define ZIP_CODE_H

// ----------------------------------
// DO NOT MODIFY this file
// ----------------------------------

struct ZipCode
{
	ZipCode();
	ZipCode(const ZipCode &r);
	ZipCode(const char *inS, const int inZip);
	~ZipCode();
	ZipCode & operator = (const ZipCode &in);

	// Ignore this... this is here to shut up warnings
	bool operator < (const ZipCode &) const;

	int  zip;
	char s[4];
};

#endif

// End of File
