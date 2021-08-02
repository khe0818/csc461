//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------
//
// NO HEADERS... do the problem in this CPP file
//
// Do Problem 2 here:
//
// ---------------------------------------------------------------------------

#include<math.h>
#include<stdio.h>

struct Vect 
{
	double x;
	double y;
	double z;

	Vect()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
	}

	Vect(double x,double y,double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}


	bool Normalize()
	{
		double result = 0;

		result = x*x;
		result += (y*y);
		result += (z*z);
		result = sqrtf(result);
		if(result == 0.0){		
			return false;
		}
		else{
			// if x, y, z is 0 can't user factor
			if(x != 0){
				x /= result;
			}
			if(y != 0){
				y /= result;
			}	
			if(z != 0){
				z /= result;
			}
			return true;
		}
	}
} Vect_v;

bool is_valid(char* input){
	bool result;

    if (atof(input)!=0.0 || input[0] - '0' == 0){
        printf("%f: valid\n", atof(input));
        result = true;
    }
    else
    {
        printf("%s: is not valid\n", input);
        result = false;
    }
    return result;
}

int main(int argc, char *argv[])
{
	
	printf("argc: arguments number is %d\n", argc);
	int i;
	printf("type in vector is (");
	for(i = 1; i < argc; i++){
		printf("%s ", argv[i]);
	}
	printf(")\n");
	if(argc != 4){
		printf("the type is not valid for 3 dimental vector");
	}
	else{
		if(is_valid(argv[1]) && is_valid(argv[2]) && is_valid(argv[3]))
		{
			Vect v(atof(argv[1]), atof(argv[2]), atof(argv[3]));
			printf("original vector is (%f, %f, %f) \n",v.x, v.y, v.z);
			if(v.Normalize()){
				printf("normalized vector is (%f, %f, %f) \n",v.x, v.y, v.z);
			}
			else{
				printf(" vector 0 can't be normalized");
			}
		}	
		else{
			printf("input data is not a vector");
		}
	}

}




// End of File
