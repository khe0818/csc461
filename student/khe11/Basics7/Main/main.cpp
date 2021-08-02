//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Framework.h"

// prototypes
void vTableQuestions_A();
void vTableQuestions_B();
void vTableQuestions_C();
void vTableQuestions_D();
void vTableQuestions_E();
void vTableQuestions_F();
void vTableQuestions_G();
void vTableQuestions_M();
void vTableQuestions_N();
void vTableQuestions_O();

int main()
{
	// Answers all questions in these functions (follow the instructions provided):
	// NOTE: they are all defaulted to fail, so please change them.

	vTableQuestions_A();
	vTableQuestions_B();
	vTableQuestions_C();
	vTableQuestions_D();
	vTableQuestions_E();
	vTableQuestions_F();
	vTableQuestions_G();
	vTableQuestions_M();
	vTableQuestions_N();
	vTableQuestions_O();

	// Leave the following functions allow
	// DO NOT reorder them
	TestRegistry::RunTests();
}

// ---  End of File ---------------
