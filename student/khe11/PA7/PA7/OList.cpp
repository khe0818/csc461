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
int slows = 0;
bool flag = false;
void OList::SetCutoffLength()
{
	this->mCutoffLength = 13;
}

void OList::MergeSort()
{
	MergeSorts(this->pHead);
}

void OList::MergeSorts(Node * &head) {
	Node* a = nullptr;
	Node* b = nullptr;

	if (head == nullptr || head->pNext == nullptr) {
		return;
	}
	FrontBackSplit(head, a, b);
	MergeSorts(a);
	MergeSorts(b);

	head = SortedMerge(a, b);

}


Node* OList::SortedMerge(Node* a, Node* b)
{

	Node* headOfMerged;

	// If one of the node is nullptr, return the other node
	// No merging occurs this this case
	if (a == nullptr) {
		return b;
	}
	else if (b == nullptr) {
		return a;
	}

	// First element in list, a, is less than the first element in b
	if (a->key <= b->key) {
		headOfMerged = a;

		while (b != nullptr) {
			if (a->key <= b->key) {
				if (a->pNext == nullptr) {
					a->pNext = b;
					b->pPrev = a;
					break;
				}
				a = a->pNext;
			}
			else {
				Node* toAdd = b;
				b = b->pNext;
				toAdd->pPrev = a->pPrev;
				a->pPrev->pNext = toAdd;
				toAdd->pNext = a;
				a->pPrev = toAdd;
			}
		}
	}
	else {
		headOfMerged = b;

		while (a != nullptr) {
			if (b->key <= a->key) {
				if (b->pNext == nullptr) {
					b->pNext = a;
					a->pPrev = b;
					break;
				}
				b = b->pNext;
			}
			else {
				Node* toAdd = a;
				a = a->pNext;
				toAdd->pPrev = b->pPrev;
				b->pPrev->pNext = toAdd;
				toAdd->pNext = b;
				b->pPrev = toAdd;
			}
		}
	}

	return headOfMerged;
}

void OList::FrontBackSplit(Node* source, Node* &frontRef, Node*&backRef)
{
	Node* fast;
	Node* slow;
	slow = source;
	fast = source->pNext;
	if (source == nullptr || source->pNext == nullptr) {
		frontRef = source;
		backRef = nullptr;
	}
	else {
		slow = source;
		fast = source->pNext;

		while (fast != nullptr) {
			fast = fast->pNext;

			if (fast != nullptr) {
				slow = slow->pNext;
				slows++;
				fast = fast->pNext;
			}
		}

		frontRef = source;
		backRef = slow->pNext;
		backRef->pPrev = nullptr;
		slow->pNext = nullptr;
	}
}

void OList::sortedInsert(Node** head_ref, Node* new_node)
{
	Node* current;
	if (*head_ref == nullptr) 
	{
		*head_ref = new_node;
	}else if ((*head_ref)->key >= new_node->key)
	{
		new_node->pNext = *head_ref;
		new_node->pNext->pPrev = new_node;
		*head_ref = new_node;
	}
	else
	{
		current = *head_ref;
		while (current->pNext != NULL &&
			current->pNext->key < new_node->key)
		{
			current = current->pNext;
		}
		new_node->pNext = current->pNext;
		if (current->pNext != NULL)
			new_node->pNext->pPrev = new_node;

		current->pNext = new_node;
		new_node->pPrev = current;
	
	}
}

void OList::InsertionSort()
{
	Node *sorted = nullptr;

	// Traverse the given linked list and insert every
	// node to sorted
	Node *current = this->pHead;
	while (current != nullptr)
	{
		Node *next = current->pNext;
		current->pPrev = current->pNext = nullptr;
		sortedInsert(&sorted, current);
		current = next;
	}
	this->pHead = sorted;
	 




}


void OList::MergeComboSort(int CutoffLength)
{
	this->mCutoffLength = CutoffLength;
	mergeInsert(this->pHead);
	
	
}

void OList::mergeInsert(Node*& head)
{
	Node* a = nullptr;
	Node* b = nullptr;


	if (!flag) {
		FrontBackSplit(head, a, b);
	}
	
	
	

	if (slows > this->GetCutoffLength() && !flag)
	{
		
		slows = 0;
		mergeInsert(a);
		mergeInsert(b);
		head = SortedMerge(a, b);

	}
	else if (flag) {
		MergeSorts(head);
	}
	else
	{
		flag = true;
		Node *sorted = nullptr;
		Node *current = a;
		while (current != nullptr)
		{
			Node *next = current->pNext;
			current->pPrev = current->pNext = nullptr;
			sortedInsert(&sorted, current);
			current = next;
		}
		a = sorted;
		current = b;
		Node *sorted2 = nullptr;
		while (current != nullptr)
		{
			Node *next = current->pNext;
			current->pPrev = current->pNext = nullptr;
			sortedInsert(&sorted2, current);
			current = next;
		}
		b = sorted2;
		head = SortedMerge(a, b);
	}
	


	
	
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

 /*	FILE *pFileHandle = nullptr;
 
 	assert(pFileName);
 	pFileHandle = fopen(pFileName, "wb");
 
	int quickSample = 0xAABBCCDD;
 
	size_t numBytesWritten = fwrite(&quickSample, 1, sizeof(int), pFileHandle);
 
	assert(numBytesWritten == sizeof(int));
 
 	fclose(pFileHandle);*/
	FILE *f;
	char *BufferA;
	Node *pTmp = this->pHead;
	f = fopen(pFileName, "wb+");
	if (f != nullptr)
	{
		LoadInPlace* p1 = new LoadInPlace();
		while (pTmp != nullptr)
		{
			p1->ptr++;
			pTmp = pTmp->getNext();

		}
		p1->blockSize = (int)(p1->ptr * sizeof(Node));
		fwrite(p1, 1, (size_t)sizeof(p1), f);
		if (f != nullptr)
		{
			BufferA = (char*)malloc((size_t)p1->blockSize);

			pTmp = this->pHead;
			BufferA = (char*)pTmp;
			while (pTmp != nullptr)
			{
				BufferA += sizeof(Node);
				fwrite(pTmp, 1, (size_t)sizeof(Node), f);
				pTmp = pTmp->pNext;
			}
			fwrite(BufferA, 1, (size_t)p1->ptr, f);
			delete p1;
		}
		else
		{
			Trace::out("\n fail to open files");
		}

	}


	fclose(f);
}

OList::OList(const char * const pFileName, int numNodes)
{
	// Leave the next 5 lines...
	this->SetCutoffLength();
	this->pHead = nullptr;
	this->mCutoffLength = this->GetCutoffLength();
	this->NumNodes = numNodes;
	this->privFunctor = nullptr;
	//Trace::out(" NumNodes %d \n", NumNodes);
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

	//FILE *f;

	//f = fopen(pFileName, "rb");
	//LoadInPlace* p1 = new LoadInPlace();
	//fread(p1, 1, sizeof(LoadInPlace), f);
	//
	//int size = p1->ptr;
	//char* buffer = (char*)malloc((size_t)p1->blockSize);
	//if (buffer == nullptr)
	//{
	//	exit(2);
	//}

	//size_t result = fread(buffer, (size_t) sizeof(Node), (size_t)p1->ptr--, f);
	//Trace::out(" begin %d \n", result);
	//Node *last = 0;
	//Node *current = (Node*)buffer;
	//this->pHead = current;
	//current->setNext(nullptr);
	//for (int i = 1; i < NumNodes; i++) {
	//	Node* tmp = current;
	//	//Trace::out("%d ptr  %d size\n", p1->blockSize, size);
	//	buffer += sizeof(Node);
	//	fread(buffer, (size_t) sizeof(Node), (size_t)p1->ptr--, f);
	//	current = (Node*)buffer;
	//	this->pHead = tmp;
	//	current->setPrev(tmp);
	//}
	//fclose(f);
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
