//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <assert.h>
#include <stdio.h>
#include <Framework.h>
#include "Boustrophedonic.h"

#define UNUSED_VAR(v) ((void *)v)

void Remove(Node *&pHead, int row, int col)
{
	Node* pTmp = pHead;
	int rowNum = 0;
	int colNum = 0;
	bool ToEast = true;
	//bool ToWest = false;
	// get col number
	while (pTmp != nullptr) {
			pTmp = pTmp->pEast;
			colNum++;
	}

	//
	pTmp = pHead;
	while (pTmp != nullptr)
	{
		if (ToEast) {
			if (pTmp->pEast != 0)
			{
				pTmp = pTmp->pEast;
			}
			else {
				pTmp = pTmp->pSouth;
				ToEast = false;
				rowNum++;
			}
		}
		else {
			if (pTmp->pWest != 0) {
				pTmp = pTmp->pWest;
			}
			else {
				pTmp = pTmp->pSouth;
				ToEast = true;
				rowNum++;
			}
		}
	}
	pTmp = pHead;
	int currentRowNum = 0;
	int currentColNum = 0;
	Node* pickedNode = nullptr;
	Node* norths = nullptr;
	Node* souths = nullptr;
	Node* wests = nullptr;
	Node* easts = nullptr;
	ToEast = true;
	while (pTmp != nullptr) 
	{
	//	Trace::out("currentRowNum, currentColNum %d %d\n ", currentRowNum, currentColNum);
		//Trace::out(" times\n");
		if (currentRowNum == row && currentColNum == col)
		{
				pickedNode = pTmp;
			//	Trace::out(" east %d\n", pickedNode->pEast);
		}
		if (currentRowNum == row - 1 && currentColNum == col && row >=1)
		{
			norths = pTmp;
		}
		if (currentRowNum == row + 1 && currentColNum == col && row <= rowNum - 1)
		{
			souths = pTmp;
		}
		if (currentRowNum == row && currentColNum == col - 1 && col >= 1)
		{
			wests = pTmp;
	//		Trace::out("sdsd\n");
		}
		if (currentRowNum == row && currentColNum == col + 1 && col <= colNum - 1)
		{
			//	Trace::out("sdsd");
			easts = pTmp;
		}


		if (ToEast) {
			if (pTmp->pEast != 0)
			{
				pTmp = pTmp->pEast;
				currentColNum++;
			}
			else {
				pTmp = pTmp->pSouth;
				ToEast = false;
				currentRowNum++;
			}
		}
		else {
			if (pTmp->pWest != 0) {
				pTmp = pTmp->pWest;
				currentColNum--;
			}
			else {
				pTmp = pTmp->pSouth;
				ToEast = true;
				currentRowNum++;
			}
		}
		

	}

	if (row == 0 && col == 0 && pHead != nullptr)
	{
		pHead = pHead->pEast;
	}
	if (row < 0 || row >= rowNum || col < 0 || col >= colNum)
	{
		assert(0);
	}

	//p(0,0)
	bool rowEvens = false;
	bool colEvens = false;
	int reminder = col % 2;
	if (reminder == 0)
	{
		colEvens = true;
	}
	reminder = row % 2;
	if (reminder == 0)
	{
		rowEvens = true;
	}
	delete(pickedNode);
	//fix round node, evens numb like 00 or 02
	if (rowEvens && colEvens) {
	    // (0, 0) 
		if (row == 0 && col == 0)
		{
			//if exist 7 
			if (souths) {
				souths->pNorth = 0;
			}
			
		}
		// first line with col is not 0 like (0,2)
		else if(row == 0 && col != 0){
			wests->pEast = easts;
			// if south exists
			if (souths)
			{
				souths->pNorth = 0;
			}
		}
		else if (row != rowNum - 1 && col == 0)
		{
			if (souths) {
				souths->pNorth = norths;
				norths->pSouth = souths;
			}
			else {
				norths->pSouth = 0;
			}
			

		}
		else if (row != rowNum - 1 && col != 0)
		{
			if (souths) {
				wests->pEast = easts;
				norths->pSouth = souths;
				souths->pNorth = norths;
			}
			else {
				wests->pEast = easts;
				norths->pSouth = 0;
			}



		}
		else if (row == rowNum - 1 && col == 0)
		{
			norths->pSouth = 0;

		}
		else if (row == rowNum - 1 && col != 0)
		{
			if (easts) {
				wests->pEast = easts;
				norths->pSouth = 0;
			}
			else {
				wests->pEast = 0;
				norths->pSouth = 0;
			}
			

		}
	}
	else if (rowEvens && !colEvens)
	{
		// (0,1)
		if (row == 0 && col != colNum - 1)
		{	
				wests->pEast = easts;		
		}
		//(0,3)
		else if (row == 0 && col == colNum - 1)
		{
			wests->pEast = 0;
		}
		else if (row != rowNum - 1 && col == colNum - 1)
		{
			wests->pEast = 0;

		}
		else if (row != rowNum - 1 && col != colNum - 1)
		{
			
			wests->pEast = easts;

		}
		else if (row == rowNum - 1 && col == colNum - 1)
		{
			wests->pEast = 0;

		}
		else if (row == rowNum - 1 && col != colNum - 1)
		{
			if (easts) {
				wests->pEast = easts;
			}
			else
			{
				wests->pEast = 0;
			}

		}

	}
	else if (!rowEvens && colEvens)
	{
	   // (1,0) or (3,0)
		if (col == 0)
		{
			easts->pWest = 0;
		}
		//(1,2)
		else {
			//if has 1,1
			if (wests) {
				easts->pWest = wests;
			}
			// if there is no 1,1
			else {
				easts->pWest = 0;
			}
			
		}
	}
	else {
		if (col != colNum - 1 && row != rowNum - 1)
		{
			if (souths) {
				easts->pWest = wests;
				norths->pSouth = souths;
				souths->pNorth = norths;
			}
			else {
				easts->pWest = wests;
				norths->pSouth = 0;
			}
		
		}
		else if (col != colNum - 1 && row == rowNum - 1)
		{
			if (souths) {
				souths->pNorth = norths;
				norths->pSouth = souths;
				easts->pWest = wests;
			}
			else {
				easts->pWest = wests;
				norths->pSouth = 0;
			}
		}
		else if (col == colNum - 1 && row != rowNum - 1)
		{
			if (souths) {
				norths->pSouth = souths;
				souths->pNorth = norths;
			}
			else {
				norths->pSouth = 0;
			}
			easts->pWest = wests;
		}
		else if (col == colNum - 1 && row == rowNum - 1)
		{
			norths->pSouth = 0;
		}
	}

	



	
}


// ---  End of File ---------------
