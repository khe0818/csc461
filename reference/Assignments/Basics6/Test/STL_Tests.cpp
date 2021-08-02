//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include <vector>
#include <list>
#include <set>

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "ZipCode.h"
#include "Vect.h"

extern int A[];
extern std::vector<int> UnitTest_A_orig;
extern std::vector<int> UnitTest_A_insert;
extern std::vector<int> UnitTest_A_sort;

extern int B[];
extern std::vector<int> UnitTest_B_orig;
extern std::vector<int> UnitTest_B_insert;
extern std::vector<int> UnitTest_B_sort;

extern Vect V[];
extern std::vector< Vect > UnitTest_V_orig;
extern std::vector< Vect > UnitTest_V_sort;

extern ZipCode data[];
extern std::vector< ZipCode > UnitTest_ZipSort;
extern ZipCode UnitTest_Bee;
extern ZipCode UnitTest_Zip;

#if STL_Set_Test_Enable
TEST(Set, STL_Tests, STL_Set_Test_Enable)
{
	ZipCode *p = &data[0];

	CHECK(p != nullptr);

	CHECK(strcmp(p[0].s,"Bug") == 0 );
	CHECK(p[0].zip == 0xABCD);
	CHECK(strcmp(p[1].s, "Dog") == 0);
	CHECK(p[1].zip == 0x1331);
	CHECK(strcmp(p[2].s, "Cat") == 0);
	CHECK(p[2].zip == 0x8844);
	CHECK(strcmp(p[3].s, "Pig") == 0);
	CHECK(p[3].zip == 0xBB77);
	CHECK(strcmp(p[4].s, "Bee") == 0);
	CHECK(p[4].zip == 0xFFEE);
	CHECK(strcmp(p[5].s, "Nbt") == 0);
	CHECK(p[5].zip == 0xCC99);

	CHECK(strcmp(UnitTest_ZipSort[0].s, "Cat") == 0);
	CHECK(UnitTest_ZipSort[0].zip == 0x8844);
	CHECK(strcmp(UnitTest_ZipSort[1].s, "Nbt") == 0);
	CHECK(UnitTest_ZipSort[1].zip == 0xCC99);
	CHECK(strcmp(UnitTest_ZipSort[2].s, "Bee") == 0);
	CHECK(UnitTest_ZipSort[2].zip == 0xFFEE);
	CHECK(strcmp(UnitTest_ZipSort[3].s, "Pig") == 0);
	CHECK(UnitTest_ZipSort[3].zip == 0xBB77);
	CHECK(strcmp(UnitTest_ZipSort[4].s, "Dog") == 0);
	CHECK(UnitTest_ZipSort[4].zip == 0x1331);
	CHECK(strcmp(UnitTest_ZipSort[5].s, "Bug") == 0);
	CHECK(UnitTest_ZipSort[5].zip == 0xABCD);

	CHECK(UnitTest_Bee.zip == 0xFFEE);
	CHECK(strcmp(UnitTest_Bee.s, "Bee") == 0);
		  
	CHECK(UnitTest_Zip.zip == 0xBB77);
	CHECK(strcmp(UnitTest_Zip.s, "Pig") == 0);
} TEST_END
#endif

#if STL_Vector_Test_Enable
TEST(Vector, STL_Tests, STL_Vector_Test_Enable)
{
	CHECK(A[0] == 6);
	CHECK(A[1] == 7);
	CHECK(A[2] == 3);
	CHECK(A[3] == 2);
	CHECK(A[4] == 8);
	CHECK(A[5] == 1);
	CHECK(A[6] == 9);
	CHECK(A[7] == 4);

	CHECK(UnitTest_A_orig.size() == 8);
	CHECK(UnitTest_A_orig[0] == 6);
	CHECK(UnitTest_A_orig[1] == 7);
	CHECK(UnitTest_A_orig[2] == 3);
	CHECK(UnitTest_A_orig[3] == 2);
	CHECK(UnitTest_A_orig[4] == 8);
	CHECK(UnitTest_A_orig[5] == 1);
	CHECK(UnitTest_A_orig[6] == 9);
	CHECK(UnitTest_A_orig[7] == 4);

	CHECK(UnitTest_A_insert.size() == 9);
	CHECK(UnitTest_A_insert[0] == 6);
	CHECK(UnitTest_A_insert[1] == 7);
	CHECK(UnitTest_A_insert[2] == 3);
	CHECK(UnitTest_A_insert[3] == 2);
	CHECK(UnitTest_A_insert[4] == 5);
	CHECK(UnitTest_A_insert[5] == 8);
	CHECK(UnitTest_A_insert[6] == 1);
	CHECK(UnitTest_A_insert[7] == 9);
	CHECK(UnitTest_A_insert[8] == 4);

	CHECK(UnitTest_A_sort.size() == 9);
	CHECK(UnitTest_A_sort[0] == 1);
	CHECK(UnitTest_A_sort[1] == 2);
	CHECK(UnitTest_A_sort[2] == 3);
	CHECK(UnitTest_A_sort[3] == 4);
	CHECK(UnitTest_A_sort[4] == 5);
	CHECK(UnitTest_A_sort[5] == 6);
	CHECK(UnitTest_A_sort[6] == 7);
	CHECK(UnitTest_A_sort[7] == 8);
	CHECK(UnitTest_A_sort[8] == 9);
} TEST_END
#endif

#if STL_List_Test_Enable
TEST(List, STL_Tests, STL_List_Test_Enable)
{
	CHECK(B[0] == 66);
	CHECK(B[1] == 77);
	CHECK(B[2] == 33);
	CHECK(B[3] == 22);
	CHECK(B[4] == 88);
	CHECK(B[5] == 11);
	CHECK(B[6] == 99);
	CHECK(B[7] == 44);

	CHECK(UnitTest_B_orig.size() == 8);
	CHECK(UnitTest_B_orig[0] == 66);
	CHECK(UnitTest_B_orig[1] == 77);
	CHECK(UnitTest_B_orig[2] == 33);
	CHECK(UnitTest_B_orig[3] == 22);
	CHECK(UnitTest_B_orig[4] == 88);
	CHECK(UnitTest_B_orig[5] == 11);
	CHECK(UnitTest_B_orig[6] == 99);
	CHECK(UnitTest_B_orig[7] == 44);
		 
	CHECK(UnitTest_B_insert.size() == 9);
	CHECK(UnitTest_B_insert[0] == 66);
	CHECK(UnitTest_B_insert[1] == 77);
	CHECK(UnitTest_B_insert[2] == 33);
	CHECK(UnitTest_B_insert[3] == 22);
	CHECK(UnitTest_B_insert[4] == 55);
	CHECK(UnitTest_B_insert[5] == 88);
	CHECK(UnitTest_B_insert[6] == 11);
	CHECK(UnitTest_B_insert[7] == 99);
	CHECK(UnitTest_B_insert[8] == 44);
		  
	CHECK(UnitTest_B_sort.size() == 9);
	CHECK(UnitTest_B_sort[0] == 99);
	CHECK(UnitTest_B_sort[1] == 88);
	CHECK(UnitTest_B_sort[2] == 77);
	CHECK(UnitTest_B_sort[3] == 66);
	CHECK(UnitTest_B_sort[4] == 55);
	CHECK(UnitTest_B_sort[5] == 44);
	CHECK(UnitTest_B_sort[6] == 33);
	CHECK(UnitTest_B_sort[7] == 22);
	CHECK(UnitTest_B_sort[8] == 11);
} TEST_END
#endif

#if STL_Vect3D_Test_Enable
TEST(Vector_3D, STL_Tests, STL_Vect3D_Test_Enable)
{
	CHECK( V[0].a == 3 &&  V[0].b == 5 &&  V[0].c == 6);
	CHECK( V[1].a == 6 &&  V[1].b == 5 &&  V[1].c == 3);
	CHECK( V[2].a == 3 &&  V[2].b == 4 &&  V[2].c == 7);
	CHECK( V[3].a == 7 &&  V[3].b == 2 &&  V[3].c == 5);
	CHECK( V[4].a == 1 &&  V[4].b == 3 &&  V[4].c == 5);
	CHECK( V[5].a == 3 &&  V[5].b == 2 &&  V[5].c == 5);
	CHECK( V[6].a == 2 &&  V[6].b == 3 &&  V[6].c == 4);
	CHECK( V[7].a == 3 &&  V[7].b == 5 &&  V[7].c == 5);
	CHECK( V[8].a == 7 &&  V[8].b == 3 &&  V[8].c == 2);
	CHECK( V[9].a == 4 &&  V[9].b == 3 &&  V[9].c == 2);
	CHECK(V[10].a == 1 && V[10].b == 7 && V[10].c == 1);

	CHECK(UnitTest_V_orig.size() == 11);
	CHECK(UnitTest_V_orig[0].a == 3  && UnitTest_V_orig[0].b == 5  && UnitTest_V_orig[0].c == 6);
	CHECK(UnitTest_V_orig[1].a == 6  && UnitTest_V_orig[1].b == 5  && UnitTest_V_orig[1].c == 3);
	CHECK(UnitTest_V_orig[2].a == 3  && UnitTest_V_orig[2].b == 4  && UnitTest_V_orig[2].c == 7);
	CHECK(UnitTest_V_orig[3].a == 7  && UnitTest_V_orig[3].b == 2  && UnitTest_V_orig[3].c == 5);
	CHECK(UnitTest_V_orig[4].a == 1  && UnitTest_V_orig[4].b == 3  && UnitTest_V_orig[4].c == 5);
	CHECK(UnitTest_V_orig[5].a == 3  && UnitTest_V_orig[5].b == 2  && UnitTest_V_orig[5].c == 5);
	CHECK(UnitTest_V_orig[6].a == 2  && UnitTest_V_orig[6].b == 3  && UnitTest_V_orig[6].c == 4);
	CHECK(UnitTest_V_orig[7].a == 3  && UnitTest_V_orig[7].b == 5  && UnitTest_V_orig[7].c == 5);
	CHECK(UnitTest_V_orig[8].a == 7  && UnitTest_V_orig[8].b == 3  && UnitTest_V_orig[8].c == 2);
	CHECK(UnitTest_V_orig[9].a == 4  && UnitTest_V_orig[9].b == 3  && UnitTest_V_orig[9].c == 2);
	CHECK(UnitTest_V_orig[10].a == 1 && UnitTest_V_orig[10].b == 7 && UnitTest_V_orig[10].c == 1);
		 															
	CHECK(UnitTest_V_sort.size() == 11);							
	CHECK(UnitTest_V_sort[0].a == 1  && UnitTest_V_sort[0].b == 3  && UnitTest_V_sort[0].c == 5);
	CHECK(UnitTest_V_sort[1].a == 1  && UnitTest_V_sort[1].b == 7  && UnitTest_V_sort[1].c == 1);
	CHECK(UnitTest_V_sort[2].a == 2  && UnitTest_V_sort[2].b == 3  && UnitTest_V_sort[2].c == 4);
	CHECK(UnitTest_V_sort[3].a == 3  && UnitTest_V_sort[3].b == 2  && UnitTest_V_sort[3].c == 5);
	CHECK(UnitTest_V_sort[4].a == 3  && UnitTest_V_sort[4].b == 4  && UnitTest_V_sort[4].c == 7);
	CHECK(UnitTest_V_sort[5].a == 3  && UnitTest_V_sort[5].b == 5  && UnitTest_V_sort[5].c == 5);
	CHECK(UnitTest_V_sort[6].a == 3  && UnitTest_V_sort[6].b == 5  && UnitTest_V_sort[6].c == 6);
	CHECK(UnitTest_V_sort[7].a == 4  && UnitTest_V_sort[7].b == 3  && UnitTest_V_sort[7].c == 2);
	CHECK(UnitTest_V_sort[8].a == 6  && UnitTest_V_sort[8].b == 5  && UnitTest_V_sort[8].c == 3);
	CHECK(UnitTest_V_sort[9].a == 7  && UnitTest_V_sort[9].b == 2  && UnitTest_V_sort[9].c == 5);
	CHECK(UnitTest_V_sort[10].a == 7 && UnitTest_V_sort[10].b == 3 && UnitTest_V_sort[10].c == 2);
} TEST_END
#endif

// End of File
