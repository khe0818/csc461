//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef WINDOWS_WRAPPER_H
#define WINDOWS_WRAPPER_H

// Needs to be included because Window.h sucks for advanced warnings
#pragma warning( push )
#pragma warning( disable : 4820 )
#pragma warning( disable : 4668 )
#pragma warning( disable : 5039 )
#include <Windows.h>
#pragma warning( pop ) 

#endif

// End of File
