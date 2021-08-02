//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include <stdio.h>
#include <string.h>

#include "Framework.h"

#include "CopyToBuffer.h"

#define STUBBED_VAR(x) (void *)x

// retrieve the message
char * Dog::GetMessage()
{
	return this->buff;
}
	
// user sets the message
void Dog::SetMessage( const char * const inMessage )
{
	// Do the copy to internal variable buff
	// make sure it's safe
	// ----> do work here
	unsigned int len = 0;
	if (inMessage != 0)
	{
		
		if (BUFF_SIZE < strlen(inMessage) + 1) {
			len = BUFF_SIZE - 1;
		}
		else {
			len = strlen(inMessage);
		}
		memcpy(this->buff, inMessage, len);
	}
	this->buff[len] = '\0';
	
}

// prints the mesage
void Dog::Print()
{
	Trace::out("message: %s\n",this->buff);
}

Dog::Dog()
{
	memset( this->buff, 0xaa, BUFF_SIZE );
}

Dog::~Dog()
{
	memset( this->buff, 0xaa, BUFF_SIZE );
}


// ---  End of File ---------------
