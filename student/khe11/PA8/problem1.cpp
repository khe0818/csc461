//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------
//b
// NO HEADERS... do the problem in this CPP file
//
// Do Problem 1 here:b
//
// ---------------------------------------------------------------------------
#include<stdio.h>
#include <stdlib.h>
#include <float.h>

float calculatEquation(float x)
{
	float a0 = 1;
	float a1 = 1;
	float a2 = 2;
	float a3 = 3;
	float a4 = 4;
	float a5 = 5;
	a0 += a1*x;
	a0 += a2*x*x;
	a0 += a3*x*x*x;
	a0 += a4*x*x*x*x;
	a0 += a5*x*x*x*x*x;
	if(a0 <= FLT_MAX){
	//	printf("the max a0 %f\n", a0);
		return a0;
	}
	else{
		printf("the result is out of range for float");
		exit(0);
	}
}

int main(int argc, char *argv[])
{
	float x, y;
	if(argc == 2 && (atof(argv[1])!= 0.0 || argv[1][0] - '0' == 0) && argv[1][1] == NULL ){
		x = atof(argv[1]);
		y = calculatEquation(x);
		printf(" \n output y = %f\n", y);
	}
	else
	{
		printf("Error, please do the required format, object + input x where x must be a float number, your argv number is %d\n", argc);
	}
	
	
}



// End of File

