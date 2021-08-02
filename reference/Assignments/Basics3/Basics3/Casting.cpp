//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"	
#include "answerRegistry.h"

#define QuestionAnswer(x,y)  Answer::registerAnswer(1,x,(unsigned int)y)
#define REPLACE_ME (0)


struct Cat
{
	Cat()
	:c0( 0xC9 ), c1(0xCA), c2(0xCB)
	{}

	unsigned char c0;
	unsigned char c1;
	unsigned char c2;
};

struct Dog
{
	Dog()
	: d0(0xDDAA), d1(0xDDBB), d2(0xDDCC)
	{}

	unsigned short d0;
	unsigned short d1;
	unsigned short d2;
};

struct Bird
{
	Bird()
	: b0(0xBB000111), b1(0xBB000222), b2(0xBB000333)
	{}

	unsigned int b0;
	unsigned int b1;
	unsigned int b2;
};

struct petStore
{
	Cat		morris;
	char	pad0;
	Dog		fido;
	char    pad1;
	char    pad2;
	Bird	poly;
};


void Students_Casting()
{
	petStore		ps;
	unsigned int	*r;
	unsigned short	*s;
	unsigned char	*p;

	// HERE's the rules
	// Only ps - the petStore is instantiated
	// Everything is stubbed out... just replace and follow the instructions

	// Example:
	// Using only:  
	//             unsigned char *p
	//             initialize p with ps

	p = &ps.morris.c0;

	// Using only p, find the values: 
	//      question 0) morris.c1

	QuestionAnswer(0, p[1]);

	// Now repeat the pattern above { use the QuestionAnswer( index, val ) macro } 

	// Using only:  
	//             unsigned int *r
	//             initialize r with ps

	// REPLACE THIS LINE:
	r = &ps.poly.b0;

	// Using __only r__, find the values: 
	//
	// NOTE: you cannot hard code the answer or use magic numbers.
	//       If you do - 0 for the complete assigment
	//
	//      question 1)  b0 
	//      question 2)  b1
	//      question 3)  b2 

	QuestionAnswer(1, r[0]);
	QuestionAnswer(2, REPLACE_ME);
	QuestionAnswer(3, REPLACE_ME);

	// Using only:  
	//             unsigned short *s
	//             initialize s with ps

	// REPLACE THIS LINE:
	s = REPLACE_ME;

	// Using __only s__, find the values: 
	//
	// NOTE: you cannot hard code the answer or use magic numbers.
	//       If you do - 0 for the complete assigment
	//
	//      question 4)  d0 
	//      question 5)  d1
	//      question 6)  d2 

	QuestionAnswer(4, REPLACE_ME);
	QuestionAnswer(5, REPLACE_ME);
	QuestionAnswer(6, REPLACE_ME);

	// Using only:  
	//             unsigned char *p
	//             initialize p with ps

	// REPLACE THIS LINE:
	p = REPLACE_ME;

	// Using __only p__, find the values: 
	//
	// NOTE: you cannot hard code the answer or use magic numbers.
	//       If you do - 0 for the complete assigment
	//
	//      question 7)  c0 
	//      question 8)  c1
	//      question 9)  c2 

	QuestionAnswer(7, REPLACE_ME);
	QuestionAnswer(8, REPLACE_ME);
	QuestionAnswer(9, REPLACE_ME);

	// For the next set of questions
	//
	// You can cast and create temp variables to help you answer questions correctly.
	//          p <- the starting address of ps
	//          s <- the starting address of ps
	//          r <- the starting address of ps

	p = (unsigned char *)&ps;
	s = (unsigned short *)&ps;
	r = (unsigned int *)&ps;

	//      question 10)  addr of ps

	QuestionAnswer(10, p);

	//
	// NOTE: you cannot hard code the answer or use magic numbers.
	//       If you do - 0 for the complete assigment
	//
	//      question 11)  number of unsigned chars to d0
	//      question 12)  number of unsigned chars to c1
	//      question 13)  number of unsigned chars to b2;

	int val;
	val = REPLACE_ME;
	QuestionAnswer(11, val);

	val = REPLACE_ME;
	QuestionAnswer(12, val);

	val = REPLACE_ME;
	QuestionAnswer(13, val);

	//
	// NOTE: you cannot hard code the answer or use magic numbers.
	//       If you do - 0 for the complete assigment
	//
	//      question 14)  number of unsigned shorts to the first d2
	//      question 15)  number of unsigned shorts to the first c2
	//      question 16)  number of unsigned shorts to b1;

	val = REPLACE_ME;
	QuestionAnswer(14, val);

	val = REPLACE_ME;
	QuestionAnswer(15, val);

	val = REPLACE_ME;
	QuestionAnswer(16, val);

	//
	// NOTE: you cannot hard code the answer or use magic numbers.
	//       If you do - 0 for the complete assigment
	//
	//      question 17)  number of unsigned ints to the first d0
	//      question 18)  number of unsigned ints to the first c0
	//      question 19)  number of unsigned ints to the first b0;

	val = REPLACE_ME;
	QuestionAnswer(17, val);

	val = REPLACE_ME;
	QuestionAnswer(18, val);

	val = REPLACE_ME;
	QuestionAnswer(19, val);

}


// End of File
