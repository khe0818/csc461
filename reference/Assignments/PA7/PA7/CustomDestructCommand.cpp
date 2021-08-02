//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Framework.h"

#include "CustomDestructCommand.h"
#include "OList.h"

CustomDestructCommand::CustomDestructCommand(OList *pInList)
{
	assert(pInList != nullptr);
	this->pList = pInList;
}

// This function is called in the destructor
// Use this as a reference when you create your own functor
void CustomDestructCommand::Command()
{
    // Delete the assert and add your code here
    assert(false);

}

// End of File
