//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "answerRegistry.h"

#define QuestionAnswer(x,y)  Answer::registerAnswer(0,x,y)

unsigned char data[] =
{ 
  0xEB, 0xCD, 0x22, 0x4F,
  0x73, 0xB5, 0xF3, 0x35,
  0x23, 0x24, 0x01, 0xFE,
  0xCD, 0xE3, 0x44, 0x85,
  0x66, 0x43, 0x75, 0x33,
  0x39, 0x5C, 0x22, 0x11,
  0x56, 0xA8, 0xAA, 0x13,
  0x64, 0x82, 0x68, 0x26 
};


void Students_PointerWalk()
{
	unsigned char  *p;  // char are 8-bits long
	unsigned int   *r;  // ints are 32-bits long
	unsigned short *s;  // shorts are 16-bits long

	unsigned int val;   // answer value

	// Sample Question 1
	//
	// Follow the pattern for the whole walking pointer test
	//
	// I want you to type in the test, look at the memory window and variables
	// Until you understand what is actually going on.
	// PLEASE TYPE in the test...

	p = &data[0];       

	val = p[0];
	QuestionAnswer( 0 , val );

	// Now repeat for the pointer test
	// 0-23 question in total for this part

	// Make sure you look at the memory window 
	// and understand the test thoroughly

	// Replace as you type in the actual pointer test
	(void *)r;
	(void *)s;

	//
	// NOTE: you cannot hard code the answer or use magic numbers.
	//       If you do - 0 for the complete assigment
	//
	val = *(p+3);    
	QuestionAnswer( 1 , val );
}

// End of File
