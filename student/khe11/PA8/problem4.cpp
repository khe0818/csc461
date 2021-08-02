//----------------------------------------------------------------------------
// Copyright 2019, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------
//
// NO HEADERS... do the problem in this CPP file
//
// Do Problem 4 here:
//
// ---------------------------------------------------------------------------

#include <math.h>
#include <cstdio>
typedef struct Vect  // Vector struct for positions
{
	float x;
	float y;
	float z;
} Vect_t; 
 
/***********************************************************************
*
*  Function: findMaxDistance()
*
*  Input:
*          int       nPlayers - number of players
*          Vect_t   *playerArray - the array of players
*  Output:
*          float     maxDist - the maxDistance between any two players 
*
***********************************************************************/
float minDist = 0.0f;
float findMaxDistance( int nPlayers, Vect_t *playerArray )
{
	int i,j;          // counter variables
	Vect_t tmpVect;   // temporary vector
	float tmpDist;    // temporary distance
	float maxDist;    // current max distance
	// case only one player
	if(playerArray == NULL || nPlayers == 1){
		printf(" maxdistance and mindistance are not exist");
	}
	tmpVect.x = playerArray[1].x;
	tmpVect.x  -= playerArray [0].x;
	tmpVect.y = playerArray[1].y;
	tmpVect.y -= playerArray [0].y;
	tmpVect.z = playerArray[1].z;
	tmpVect.z -= playerArray [0].z;

	tmpDist = tmpVect.x * tmpVect.x;
	tmpDist += tmpVect.y * tmpVect.y;
	tmpDist += tmpVect.z * tmpVect.z;
	tmpDist =(float)sqrt(tmpDist);
	minDist = tmpDist;
	maxDist = tmpDist;
	for( i = 0; i < nPlayers; i++ )
	{
		for( j = i + 1; j < nPlayers ; j++ )
		{
			// Find a vector between point i and j
			tmpVect.x = playerArray[i].x;
			tmpVect.x  -= playerArray [j].x;
			tmpVect.y = playerArray[i].y;
			tmpVect.y -= playerArray [j].y;
			tmpVect.z = playerArray[i].z;
			tmpVect.z -= playerArray[j].z;

			// Get its length
			tmpDist = tmpVect.x * tmpVect.x;
			tmpDist += tmpVect.y * tmpVect.y;
			tmpDist += tmpVect.z * tmpVect.z;
			tmpDist =(float)sqrt(tmpDist);
		
			// determine if it’s a new maximum length
			if( tmpDist > maxDist)
			{
			
				// yes so keep it
				maxDist = tmpDist;
			}
			if (minDist > tmpDist){

				minDist = tmpDist;

			}
			printf("tmpdist %f, maxDist %f, minDist %f\n", tmpDist, maxDist, minDist);
		} //for(j)
	} // for(i)

	return maxDist;

} 
// End of findMaxDistance()



int main(int argc, char* argv[])
{
	if(atoi(argv[1]) == 0.0 || argc != 2 ){
		printf("type in is not valid, please type in generated object file + a number which is vect total number\n");
	}
	else{
		Vect *v = new Vect[atoi(argv[1])];
		float random = 0;
		for ( int i=0; i<atoi(argv[1]); i++){
	        random = ((float) rand()) / (float) RAND_MAX;
		    v[i].x = random * 100;
		     random = ((float) rand()) / (float) RAND_MAX;
		    v[i].y = random * 100;
		     random = ((float) rand()) / (float) RAND_MAX;
		    v[i].z = random * 100;
	     }
		printf("\nMax distance %f",findMaxDistance(atoi(argv[1]), v));
		printf("\nMin distance %f\n ", minDist);
	}
	return 0;
}
// End of File
