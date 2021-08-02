//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "answerRegistry.h"
#include "A.h"

void vTableQuestions_A()
{
	// Class A:  Question 0-9
	
	// Only consider this class for this answer

	// Is there a vTable for this class?
	// (1 - true, 0 - false)

	QuestionAnswer( 0 , WRONG_ANSWER );

	// How many jump vectors(pointers to functions) are in the vTable?
	//  (0 - no table, 1-N - number of jump vectors)?

	QuestionAnswer( 1 , WRONG_ANSWER );

	// Next 8 questions, fill in the jump vector
	// Add the function label number 
	// Order is important, do not reorder the classes

	// 1st jump vector ?
    // (label number, 0xFFFF - purecall, 0 - does not exist)

	QuestionAnswer( 2 , WRONG_ANSWER );

	// 2nd jump vector ?
	// (label number, 0xFFFF - purecall, 0 - does not exist)

	QuestionAnswer( 3 , WRONG_ANSWER );

	// 3rd jump vector ?
	// (label number, 0xFFFF - purecall, 0 - does not exist)

	QuestionAnswer( 4 , WRONG_ANSWER );

	// 4th jump vector ?
	// (label number, 0xFFFF - purecall, 0 - does not exist)

	QuestionAnswer( 5 , WRONG_ANSWER );

	// 5th jump vector ?
	// (label number, 0xFFFF - purecall, 0 - does not exist)

	QuestionAnswer( 6 , WRONG_ANSWER );

	// 6th jump vector ?
	// (label number, 0xFFFF - purecall, 0 - does not exist)

	QuestionAnswer( 7 , WRONG_ANSWER );

	// 7th jump vector ?
	// (label number, 0xFFFF - purecall, 0 - does not exist)

	QuestionAnswer( 8 , WRONG_ANSWER );

	// 8th jump vector ?
	// (label number, 0xFFFF - purecall, 0 - does not exist)

	QuestionAnswer( 9 , WRONG_ANSWER );

}

// ---  End of File ---------------
