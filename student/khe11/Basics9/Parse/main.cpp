//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

// Add functions and includes as needed

#include "Chunk.h"
#include <Trace.h>
#include "Framework.h"
#include "_UnitTestConfiguration.h"
#define UNUSED_VAR(v) ((void *)v)

bool typeCheck(char* input)
{
	bool result = false;
	if (strcmp("VERTS_TYPE", input) == 0)
	{
		result = true;
	}
	else if (strcmp("NORMS_TYPE", input) == 0)
	{
		result = true;
	}
	else if (strcmp("ANIM_TYPE", input) == 0)
	{
		result = true;
	}
	else if (strcmp("TEXTURE_TYPE", input) == 0)
	{
		result = true;
	}
	else if (strcmp("UV_TYPE", input) == 0)
	{
		result = true;
	}

	return result;
}

bool NameCheck(char* input)
{
	return (strlen(input) < 20);

}
Options checkOptions(char* input) {

	Options result = OTHERS;
	if (strcmp(input, "-N") == 0 || strcmp(input, "-n") == 0)
	{
		result = CHUNK_NAME;
	}
	if (strcmp(input, "-T") == 0 || strcmp(input, "-t") == 0)
	{
		result = CHUNK_TYPE;
	}
	return result;
}



int main(int argc, char *argv[])
{
	int result = -1;
	if (argc == 5) {
		if (strcmp(argv[0], "parse") == 0 && ((checkOptions(argv[1]) == Options::CHUNK_NAME && NameCheck(argv[2]) && checkOptions(argv[3]) == Options::CHUNK_TYPE && typeCheck(argv[4])) ||
			(checkOptions(argv[1]) == Options::CHUNK_TYPE && typeCheck(argv[2]) && checkOptions(argv[3]) == Options::CHUNK_NAME && NameCheck(argv[4]))))
		{
			result = 0;
		}
		
	}
	return result;
	// do your magic stuff here
}

// ---  End of File ---------------
