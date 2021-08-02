//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "OList.h"
#include "Node.h"
#include "Trace.h"

#define UNUSED_VAR(x) (void *)x

// ----------------------------------
// -----> MODIFY This FILE <---------
// ----------------------------------

void OList::SetCutoffLength()
{
	// Yes HARD code your cutoff
	// CHANGE this number, by running experiments to find best value
	this->mCutoffLength = -1;
}

void OList::MergeSort()
{
	// Do your magic
}

void OList::InsertionSort()
{
	// Do your magic
}

void OList::MergeComboSort(int CutoffLength)
{
	UNUSED_VAR(CutoffLength);
	// Do your magic
}

void OList::WriteToFile(const char * const pFileName)
{
	// Do your magic

	// Make sure you close the file after you fill it
	// Use fopen,fwrite,ftell,...,fclose

	// Hint: Open the file, write the nodes into the file 

	// Grads - You need to do the Load-In-Place technique
	//         You cannot have more than 2 new functions in this method

	// Ungrads - You need to store the data and reconstruct the linked list
	//           You can use as many new/deletes as needed

	// Everyone - Fill in your CustomDestructCommand::Command() that will be used 
	//            in the destructor..

	// Quick sample code... remove this code and replace with your own

 	FILE *pFileHandle = nullptr;
 
 	assert(pFileName);
 	pFileHandle = fopen(pFileName, "wb");
 
	int quickSample = 0xAABBCCDD;
 
	size_t numBytesWritten = fwrite(&quickSample, 1, sizeof(int), pFileHandle);
 
	assert(numBytesWritten == sizeof(int));
 
 	fclose(pFileHandle);
}

OList::OList(const char * const pFileName, int numNodes)
{
	// Leave the next 5 lines...
	this->SetCutoffLength();
	this->pHead = nullptr;
	this->mCutoffLength = this->GetCutoffLength();
	this->NumNodes = numNodes;
	this->privFunctor = nullptr;
	
	// Do your magic here:

	// Create the Linked List... You cannot use the original code
	// The input file, and numNodes is all you need to recreate the OList
	
	// Hint: Open the file, read and create new nodes, 
	//       fill them with the data from the file

	// Grads - You need to do the Load-In-Place technique
	//         You cannot have more than 2 new functions in this method
	     
	// Ungrads - You need to store the data and reconstruct the linked list
	//           You can use as many new/deletes as needed

	// Everyone - Fill in your CustomDestructCommand::Command() that will be used 
	//            in the destructor.

	// Quick sample code... remove this code and replace with your own

 	FILE *pFileHandle;
 
 	assert(pFileName);
 	pFileHandle = fopen(pFileName, "rb");
 
	int data;
 
	size_t numBytesRead = fread(&data, 1, sizeof(int), pFileHandle);
	assert(numBytesRead == sizeof(int));
 
 	fclose(pFileHandle);
 
	assert(data == 0xAABBCCDD);
 
}

// ---  End of File ---------------
