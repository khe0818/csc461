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
	//
	// NOTE: you cannot hard code the answer or use magic numbers.
	//       If you do - 0 for the complete assigment
	// test one
	//val = *(p+3)  
	val = p[3];
	QuestionAnswer( 1 , val );
	//val = *(p + 5);
	val = p[5];
	QuestionAnswer(2, val);
	p = p + 12;
	val = p[0];
	QuestionAnswer(3, val);
	val = p[2];
	QuestionAnswer(4, val);
	val = p[0];
	QuestionAnswer(5, val);
	p = p + 1;
	p = p + 6;
	p = p - 1;
	val = p[0];
	QuestionAnswer(6, val);
	val = p[5];
	QuestionAnswer(7, val);
	p = p + 2;
	val = p[0];
	QuestionAnswer(8, val);
	p = p + 1;
	val = p[3];
	QuestionAnswer(9, val);
	p = 5 + p;
	val = p[0];
	QuestionAnswer(10, val);
	p = p + 1;
	p = p - 1;
	val = p[0];
	QuestionAnswer(11, val);

	// test two
	r = (unsigned int*)&data[0];
	val = *r;
	QuestionAnswer(12, val);
	val = *(r + 5);
	QuestionAnswer(13, val);
	r = r + 1;
	val = *r;
	QuestionAnswer(14, val);
	r = r + 1;
	r = r + 2;
	val = *(r + 2);
	QuestionAnswer(15, val);
	r = r + 1;
	val = *r;
	QuestionAnswer(16, val);

	//test three
	s = (unsigned short*)r;
	val = *(s - 2);
	QuestionAnswer(17, val);
	s = s - 3;
	val = *(s + 2);
	QuestionAnswer(18, val);
	s = s + 5;
	val = *(s + 3);
	QuestionAnswer(19, val);
	val = *s;
	QuestionAnswer(20, val);
	p = (unsigned char *)s;
	val = *(p + 3);
	QuestionAnswer(21, val);
	p = p + 5;
	val = *(p - 9);
	QuestionAnswer(22, val);
	p = p - 1;
	val = *p;
	QuestionAnswer(23, val);

}

// End of File
