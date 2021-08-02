//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include "Framework.h"

#include "PerformanceTest.h"

#ifdef _DEBUG
#define FACTOR 1
#else
#define FACTOR 10
#endif

void PerformanceTest()
{
	// Performance tests
	printf("\nPerformance tests: \n    Begin()\n");

	if (TestRegistry::GetStats().testPass != 1)
	{
		Trace::out("\n  ERROR---> didn't pass unit tests\n");
		Trace::out("\n    Cannot run performance tests\n\n\n");
	}
	else
	{
		//Trace::out("\n");
		Timer tA;
		Timer tB;

		// --------------- MATRIX ----------------------------------------------

		Trace::out("\n---------- Matrix ----------------\n");
		printf("           : Matrix\n");
		tA.Tic();

			Matrix B = matrix_test();

		tA.Toc();

		// --------------- Matrix SIMD ----------------------------------------------

		printf("           : Matrix_SIMD\n");
		tB.Tic();

			Matrix_M_SIMD B_SIMD = matrix_SIMD_test();

		tB.Toc();

		Trace::out("         Matrix Orig: %2.5f s    :%f %f %f %f\n", tA.TimeInSeconds(), B.v0.x, B.v0.y, B.v0.z, B.v0.w);
		Trace::out("                                 :%f %f %f %f\n", B.v1.x, B.v1.y, B.v1.z, B.v1.w);
		Trace::out("                                 :%f %f %f %f\n", B.v2.x, B.v2.y, B.v2.z, B.v2.w);
		Trace::out("                                 :%f %f %f %f\n", B.v3.x, B.v3.y, B.v3.z, B.v3.w);

		Trace::out("                SIMD: %2.5f s    :%f %f %f %f\n", tB.TimeInSeconds(), B_SIMD.v0.x, B_SIMD.v0.y, B_SIMD.v0.z, B_SIMD.v0.w);
		Trace::out("                                 :%f %f %f %f\n", B_SIMD.v1.x, B_SIMD.v1.y, B_SIMD.v1.z, B_SIMD.v1.w);
		Trace::out("                                 :%f %f %f %f\n", B_SIMD.v2.x, B_SIMD.v2.y, B_SIMD.v2.z, B_SIMD.v2.w);
		Trace::out("                                 :%f %f %f %f\n", B_SIMD.v3.x, B_SIMD.v3.y, B_SIMD.v3.z, B_SIMD.v3.w);
	
		Trace::out("         Matrix SIMD: %f s \n", tB.TimeInSeconds());

		if (tB.TimeInSeconds() < 0.3f)
		{
			Trace::out("\n");
			Trace::out("----> ERROR make sure there is no implementation in header \n");
		}
		else
		{
			Trace::out("               Ratio: %f\n", tA.TimeInSeconds() / tB.TimeInSeconds());
		}

		// --------------- Vect * Matrix ----------------------------------------------

		Trace::out("\n---------- Vect * Matrix ----------------\n");
		printf("           : Vect * Matrix\n");
		tA.Tic();

			Vect4D C = vectMultMatrix_test();
	
		tA.Toc();

		// --------------- Vect * Matrix (SIMD) ----------------------------------------------

		printf("           : Vect * Matrix (SIMD)\n");
		tB.Tic();

			Vect_vM_SIMD C_SIMD = vectMultMatrix_SIMD_test();

		tB.Toc();

		Trace::out("  Vect * Matrix Orig: %f s   :%f %f %f %f\n", tA.TimeInSeconds(), C.x, C.y, C.z, C.w);
		Trace::out("                SIMD: %f s   :%f %f %f %f\n", tB.TimeInSeconds(), C_SIMD.x, C_SIMD.y, C_SIMD.z, C_SIMD.w);
		Trace::out("             vM SIMD: %f s \n", tB.TimeInSeconds());

		if (tB.TimeInSeconds() < 0.3f)
		{
			Trace::out("\n");
			Trace::out("----> ERROR make sure there is no implementation in header \n");
		}
		else
		{
			Trace::out("               Ratio: %f\n", tA.TimeInSeconds() / tB.TimeInSeconds());
		}

		// --------------- Matrix * Vector ----------------------------------------------

		Trace::out("\n---------- Matrix * Vect ----------------\n");
		printf("           : Matrix * Vect\n");
		tA.Tic();

			Vect4D D = matrixMultVect_test();
		
		tA.Toc();

		// --------------- Matrix * Vector (SIMD) ----------------------------------------------

		printf("           : Matrix * Vect (SIMD)\n");
		tB.Tic();

			Vect_Mv_SIMD D_SIMD = matrixMultVect_SIMD_test();
		
		tB.Toc();
		Trace::out("  Matrix * Vect Orig: %f s   :%f %f %f %f\n", tA.TimeInSeconds(), D.x, D.y, D.z, D.w);
		Trace::out("                SIMD: %f s   :%f %f %f %f\n", tB.TimeInSeconds(), D_SIMD.x, D_SIMD.y, D_SIMD.z, D_SIMD.w);
		Trace::out("             Mv SIMD: %f s\n", tB.TimeInSeconds());

		if (tB.TimeInSeconds() < 0.3f)
		{
			Trace::out("\n");
			Trace::out("----> ERROR make sure there is no implementation in header \n");
		}
		else
		{
			Trace::out("               Ratio: %f\n", tA.TimeInSeconds() / tB.TimeInSeconds());
		}

		// --------------- LERP ----------------------------------------------

		Trace::out("\n---------- LERP ----------------\n");
		printf("           : LERP\n");
		Vect4D LERP_C;
		tA.Tic();

			LERP_C = LERP_Tests();
		
		tA.Toc();

		// --------------- LERP SIMD ----------------------------------------------

		printf("           : LERP SIMD\n");
		Vect_LERP_SIMD LERP_SIMD_C;
		tB.Tic();

			LERP_SIMD_C = LERP_SIMD_Tests();

		tB.Toc();

		Trace::out("           LERP Orig: %f s   :%f %f %f %f\n", tA.TimeInSeconds(), LERP_C.x, LERP_C.y, LERP_C.z, LERP_C.w);
		Trace::out("                SIMD: %f s   :%f %f %f %f\n", tB.TimeInSeconds(), LERP_SIMD_C.x, LERP_SIMD_C.y, LERP_SIMD_C.z, LERP_SIMD_C.w);
		Trace::out("           LERP SIMD: %f s  \n", tB.TimeInSeconds());

		if (tB.TimeInSeconds() < 0.3f)
		{
			Trace::out("\n");
			Trace::out("----> ERROR make sure there is no implementation in header \n");
		}
		else
		{
			Trace::out("               Ratio: %f\n", tA.TimeInSeconds() / tB.TimeInSeconds());
		}

		// --------------- RowMajor ----------------------------------------------

		Trace::out("\n---------- rowMajor ----------------\n");
		printf("           : rowMajor\n");
		Vect4D Row_C;
		tA.Tic();

			Row_C = rowMajor_test();
		
		tA.Toc();

		// --------------- RowMajor SIMD ----------------------------------------------

		printf("           : rowMajor SIMD\n");
		Vect_Row_SIMD Row_SIMD_C;
		tB.Tic();

			Row_SIMD_C = rowMajor_SIMD_test();
	
		tB.Toc();

		Trace::out("       rowMajor Orig: %f s   :%f %f %f %f\n", tA.TimeInSeconds(), Row_C.x, Row_C.y, Row_C.z, Row_C.w);
		Trace::out("                SIMD: %f s   :%f %f %f %f\n", tB.TimeInSeconds(), Row_SIMD_C.x, Row_SIMD_C.y, Row_SIMD_C.z, Row_SIMD_C.w);
		Trace::out("       rowMajor SIMD: %f s \n", tB.TimeInSeconds());

		if( tB.TimeInSeconds() < 0.3f)
		{
			Trace::out("\n");
			Trace::out("----> ERROR make sure there is no implementation in header \n");
		}
		else
		{
			Trace::out("               Ratio: %f\n", tA.TimeInSeconds() / tB.TimeInSeconds());
		}

		// --------------- ColMajor ----------------------------------------------

		Trace::out("\n---------- colMajor ----------------\n");
		printf("           : colMajor\n");
		Vect4D Col_C;
		tA.Tic();

			Col_C = colMajor_test();
		
		tA.Toc();

		// --------------- colMajor SIMD ----------------------------------------------

		printf("           : colMajor SIMD\n");
		Vect_Col_SIMD Col_SIMD_C;
		tB.Tic();

			Col_SIMD_C = colMajor_SIMD_test();
		
		tB.Toc();

		Trace::out("       colMajor Orig: %f s    :%f %f %f %f\n", tA.TimeInSeconds(), Col_C.x, Col_C.y, Col_C.z, Col_C.w);
		Trace::out("                SIMD: %f s    :%f %f %f %f\n", tB.TimeInSeconds(), Col_SIMD_C.x, Col_SIMD_C.y, Col_SIMD_C.z, Col_SIMD_C.w);
		Trace::out("       colMajor SIMD: %f s\n", tB.TimeInSeconds());

		if (tB.TimeInSeconds() < 0.3f)
		{
			Trace::out("\n");
			Trace::out("----> ERROR make sure there is no implementation in header \n");
		}
		else
		{
			Trace::out("               Ratio: %f\n", tA.TimeInSeconds() / tB.TimeInSeconds());
		}

		// Tests done
		Trace::out("\nPerformance tests: done() \n\n");
		printf("\n    done() \n\n");

	}
}

// ---  End of File ---------------
