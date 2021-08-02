//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "Vect4D.h"
#include "Matrix.h"

#include "Vect_Col_SIMD.h"
#include "Matrix_Col_SIMD.h"
#include "Vect_Row_SIMD.h"
#include "Matrix_Row_SIMD.h"
#include "Vect_M_SIMD.h"
#include "Matrix_M_SIMD.h"
#include "Vect_vM_SIMD.h"
#include "Matrix_vM_SIMD.h"
#include "Vect_Mv_SIMD.h"
#include "Matrix_Mv_SIMD.h"
#include "Vect_LERP_SIMD.h"

#define f_eq(A,B) (  fabs(A - B) < 0.001f)
#define V_EQ(A,B) ((f_eq(A.x,B.x) ) && ( f_eq(A.y, B.y)) && (f_eq(A.z,B.z)) && (f_eq(A.w,B.w) ))

#if Verify_Math_Test_Enable
TEST(Verify_Math, SIMD_Tests, Verify_Math_Test_Enable)
{
	// ---------------------------------------------------
	// Col major tests
	// ---------------------------------------------------
	{
		{
			Matrix Rx(Vect4D(1.000000f, 0.000000f, 0.000000f, 0.000000f),
					  Vect4D(0.000000f, -0.500000f, -0.866025f, 0.000000f),
					  Vect4D(0.000000f, 0.866025f, -0.500000f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix Ry(Vect4D(0.707107f, 0.000000f, 0.707107f, 0.000000f),
					  Vect4D(0.000000f, 1.000000f, 0.000000f, 0.000000f),
					  Vect4D(-0.707107f, 0.000000f, 0.707107f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix Rz(Vect4D(0.500000f, 0.866025f, 0.000000f, 0.000000f),
					  Vect4D(-0.866025f, 0.500000f, 0.000000f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 1.000000f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix  T(Vect4D(1.000000f, 0.000000f, 0.000000f, 4.000000f),
					  Vect4D(0.000000f, 1.000000f, 0.000000f, 5.000000f),
					  Vect4D(0.000000f, 0.000000f, 1.000000f, 6.000000f),
					  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix  S(Vect4D(1.000000f, 0.000000f, 0.000000f, 0.000000f),
					  Vect4D(0.000000f, 2.000000f, 0.000000f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 0.500000f, 0.000000f),
					  Vect4D(0.200000f, 0.300000f, 0.500000f, 0.130000f));

			Vect4D  v(0.500000f, 0.600000f, 0.700000f, 0.900000f);
			Vect4D vOut;

			vOut = T * Rz * Ry * Rx * S * v;

			CHECK(S.m0 == 1.0f);

			Vect4D Ans;
			Ans = Vect4D(2.688213f, 2.448028f, 4.739550f, 0.747000f);

			CHECK(V_EQ(vOut, Ans));
		}

		{
			Matrix_Col_SIMD Rx(Vect_Col_SIMD(1.000000f, 0.000000f, 0.000000f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, -0.500000f, -0.866025f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, 0.866025f, -0.500000f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix_Col_SIMD Ry(Vect_Col_SIMD(0.707107f, 0.000000f, 0.707107f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, 1.000000f, 0.000000f, 0.000000f),
							   Vect_Col_SIMD(-0.707107f, 0.000000f, 0.707107f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix_Col_SIMD Rz(Vect_Col_SIMD(0.500000f, 0.866025f, 0.000000f, 0.000000f),
							   Vect_Col_SIMD(-0.866025f, 0.500000f, 0.000000f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, 0.000000f, 1.000000f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix_Col_SIMD  T(Vect_Col_SIMD(1.000000f, 0.000000f, 0.000000f, 4.000000f),
							   Vect_Col_SIMD(0.000000f, 1.000000f, 0.000000f, 5.000000f),
							   Vect_Col_SIMD(0.000000f, 0.000000f, 1.000000f, 6.000000f),
							   Vect_Col_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix_Col_SIMD  S(Vect_Col_SIMD(1.000000f, 0.000000f, 0.000000f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, 2.000000f, 0.000000f, 0.000000f),
							   Vect_Col_SIMD(0.000000f, 0.000000f, 0.500000f, 0.000000f),
							   Vect_Col_SIMD(0.200000f, 0.300000f, 0.500000f, 0.130000f));

			Vect_Col_SIMD v(0.500000f, 0.600000f, 0.700000f, 0.900000f);
			Vect_Col_SIMD vOut;

			vOut = T * Rz * Ry * Rx * S * v;

			Vect_Col_SIMD Ans;
			Ans = Vect_Col_SIMD(2.688213f, 2.448028f, 4.739550f, 0.747000f);

			CHECK(V_EQ(vOut, Ans));
		}
	}

	// ---------------------------------------------------
	// Row major tests
	// ---------------------------------------------------
	{
		{
			Matrix Rx(Vect4D(1.000000f, 0.000000f, 0.000000f, 0.000000f),
					  Vect4D(0.000000f, -0.500000f, 0.866025f, 0.000000f),
					  Vect4D(0.000000f, -0.866025f, -0.500000f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix Ry(Vect4D(0.707107f, 0.000000f, -0.707107f, 0.000000f),
					  Vect4D(0.000000f, 1.000000f, 0.000000f, 0.000000f),
					  Vect4D(0.707107f, 0.000000f, 0.707107f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix Rz(Vect4D(0.500000f, -0.866025f, 0.000000f, 0.000000f),
					  Vect4D(0.866025f, 0.500000f, 0.000000f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 1.000000f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix  T(Vect4D(1.000000f, 0.000000f, 0.000000f, 0.000000f),
					  Vect4D(0.000000f, 1.000000f, 0.000000f, 0.000000f),
					  Vect4D(0.000000f, 0.000000f, 1.000000f, 0.000000f),
					  Vect4D(4.000000f, 5.000000f, 6.000000f, 1.000000f));

			Matrix  S(Vect4D(1.000000f, 0.000000f, 0.000000f, 0.200000f),
					  Vect4D(0.000000f, 2.000000f, 0.000000f, 0.300000f),
					  Vect4D(0.000000f, 0.000000f, 0.500000f, 0.500000f),
					  Vect4D(0.000000f, 0.000000f, 0.000000f, 0.130000f));

			Vect4D  v(0.500000f, 0.600000f, 0.700000f, 0.900000f);
			Vect4D  vOut;

			vOut = v * S * Rx *Ry * Rz * T;

			CHECK(S.m0 == 1.0f);

			Vect4D Ans;
			Ans = Vect4D(2.688213f, 2.448028f, 4.739550f, 0.747000f);

			CHECK(V_EQ(vOut, Ans));
		}
		{
			Matrix_Row_SIMD Rx(Vect_Row_SIMD(1.000000f, 0.000000f, 0.000000f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, -0.500000f, 0.866025f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, -0.866025f, -0.500000f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix_Row_SIMD Ry(Vect_Row_SIMD(0.707107f, 0.000000f, -0.707107f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, 1.000000f, 0.000000f, 0.000000f),
							   Vect_Row_SIMD(0.707107f, 0.000000f, 0.707107f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix_Row_SIMD Rz(Vect_Row_SIMD(0.500000f, -0.866025f, 0.000000f, 0.000000f),
							   Vect_Row_SIMD(0.866025f, 0.500000f, 0.000000f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, 0.000000f, 1.000000f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, 0.000000f, 0.000000f, 1.000000f));

			Matrix_Row_SIMD  T(Vect_Row_SIMD(1.000000f, 0.000000f, 0.000000f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, 1.000000f, 0.000000f, 0.000000f),
							   Vect_Row_SIMD(0.000000f, 0.000000f, 1.000000f, 0.000000f),
							   Vect_Row_SIMD(4.000000f, 5.000000f, 6.000000f, 1.000000f));

			Matrix_Row_SIMD  S(Vect_Row_SIMD(1.000000f, 0.000000f, 0.000000f, 0.200000f),
							   Vect_Row_SIMD(0.000000f, 2.000000f, 0.000000f, 0.300000f),
							   Vect_Row_SIMD(0.000000f, 0.000000f, 0.500000f, 0.500000f),
							   Vect_Row_SIMD(0.000000f, 0.000000f, 0.000000f, 0.130000f));

			Vect_Row_SIMD  v(0.500000f, 0.600000f, 0.700000f, 0.900000f);
			Vect_Row_SIMD  vOut;

			vOut = v * S * Rx *Ry * Rz * T;

			Vect_Row_SIMD Ans;
			Ans = Vect_Row_SIMD(2.688213f, 2.448028f, 4.739550f, 0.747000f);

			CHECK(V_EQ(vOut, Ans));
		}
	}

	// ---------------------------------------------------
	// Matrix * Matrix tests
	// ---------------------------------------------------
	{
		Vect4D VA0(-1.0f, -2.0f, -3.0f, -4.0f);
		Vect4D VA1(4.0f, 5.0f, 6.0f, 7.0f);
		Vect4D VA2(1.0f, 2.0f, 3.0f, 4.0f);
		Vect4D VA3(-4.0f, -3.0f, -2.0f, -1.0f);
		Vect4D VB0(-0.1f, -0.2f, -0.3f, -0.4f);
		Vect4D VB1(0.4f, 0.5f, 0.6f, 0.7f);
		Vect4D VB2(0.1f, 0.2f, 0.3f, 0.4f);
		Vect4D VB3(-0.4f, -0.3f, -0.2f, -0.1f);

		CHECK(VA0.x == -1.0f);
		CHECK(VA0.y == -2.0f);
		CHECK(VA0.z == -3.0f);
		CHECK(VA0.w == -4.0f);

		Matrix A(VA0, VA1, VA2, VA3);
		Matrix B(VB0, VB1, VB2, VB3);
		Matrix C;

		C = A * B;

		Vect_M_SIMD VA0_simd(-1.0f, -2.0f, -3.0f, -4.0f);
		Vect_M_SIMD VA1_simd(4.0f, 5.0f, 6.0f, 7.0f);
		Vect_M_SIMD VA2_simd(1.0f, 2.0f, 3.0f, 4.0f);
		Vect_M_SIMD VA3_simd(-4.0f, -3.0f, -2.0f, -1.0f);
		Vect_M_SIMD VB0_simd(-0.1f, -0.2f, -0.3f, -0.4f);
		Vect_M_SIMD VB1_simd(0.4f, 0.5f, 0.6f, 0.7f);
		Vect_M_SIMD VB2_simd(0.1f, 0.2f, 0.3f, 0.4f);
		Vect_M_SIMD VB3_simd(-0.4f, -0.3f, -0.2f, -0.1f);

		Matrix_M_SIMD A_simd(VA0_simd, VA1_simd, VA2_simd, VA3_simd);
		Matrix_M_SIMD B_simd(VB0_simd, VB1_simd, VB2_simd, VB3_simd);
		Matrix_M_SIMD C_simd;

		CHECK(VA0_simd.x == -1.0f);
		CHECK(VA0_simd.y == -2.0f);
		CHECK(VA0_simd.z == -3.0f);
		CHECK(VA0_simd.w == -4.0f);

		C_simd = A_simd * B_simd;

		CHECK(V_EQ(A.v0, A_simd.v0));
		CHECK(V_EQ(A.v1, A_simd.v1));
		CHECK(V_EQ(A.v2, A_simd.v2));
		CHECK(V_EQ(A.v3, A_simd.v3));

		CHECK(V_EQ(B.v0, B_simd.v0));
		CHECK(V_EQ(B.v1, B_simd.v1));
		CHECK(V_EQ(B.v2, B_simd.v2));
		CHECK(V_EQ(B.v3, B_simd.v3));

		CHECK(V_EQ(C.v0, C_simd.v0));
		CHECK(V_EQ(C.v1, C_simd.v1));
		CHECK(V_EQ(C.v2, C_simd.v2));
		CHECK(V_EQ(C.v3, C_simd.v3));
	}

	// ---------------------------------------------------
	// Vect * Matrix tests
	// ---------------------------------------------------
	{
		Vect4D A(1, 2, 3, 4);
		Vect4D B(11, 12, 13, 14);
		Vect4D C(21, 22, 23, 24);

		Vect4D MV0(1, 2, 3, 4);
		Vect4D MV1(5, 6, 7, 8);
		Vect4D MV2(9, 10, 11, 12);
		Vect4D MV3(13, 14, 15, 16);

		Matrix M(MV0, MV1, MV2, MV3);

		Vect4D vout1;
		Vect4D vout2;
		Vect4D vout3;

		vout1 = A * M;
		vout2 = B * M;
		vout3 = C * M;

		Vect_vM_SIMD A_simd;
		A_simd = Vect_vM_SIMD(1, 2, 3, 4);
		Vect_vM_SIMD B_simd;
		B_simd = Vect_vM_SIMD(11, 12, 13, 14);
		Vect_vM_SIMD C_simd;
		C_simd = Vect_vM_SIMD(21, 22, 23, 24);

		Vect_vM_SIMD MV0_simd(1, 2, 3, 4);
		Vect_vM_SIMD MV1_simd(5, 6, 7, 8);
		Vect_vM_SIMD MV2_simd(9, 10, 11, 12);
		Vect_vM_SIMD MV3_simd(13, 14, 15, 16);

		CHECK(M.v0.x == 1.0f);

		Matrix_vM_SIMD M_simd;
		M_simd = Matrix_vM_SIMD(MV0_simd, MV1_simd, MV2_simd, MV3_simd);

		Vect_vM_SIMD vout1_simd;
		Vect_vM_SIMD vout2_simd;
		Vect_vM_SIMD vout3_simd;

		vout1_simd = A_simd * M_simd;
		vout2_simd = B_simd * M_simd;
		vout3_simd = C_simd * M_simd;

		CHECK(V_EQ(M.v0, M_simd.v0));
		CHECK(V_EQ(M.v1, M_simd.v1));
		CHECK(V_EQ(M.v2, M_simd.v2));
		CHECK(V_EQ(M.v3, M_simd.v3));

		CHECK(V_EQ(A, A_simd));
		CHECK(V_EQ(B, B_simd));
		CHECK(V_EQ(C, C_simd));

		CHECK(V_EQ(vout1, vout1_simd));
		CHECK(V_EQ(vout2, vout2_simd));
		CHECK(V_EQ(vout3, vout3_simd));
	}

	// ---------------------------------------------------
	// Matrix * Vect tests
	// ---------------------------------------------------
	{
		Vect4D A(1, 2, 3, 4);
		Vect4D B(11, 12, 13, 14);
		Vect4D C(21, 22, 23, 24);

		Vect4D MV0(1, 5, 9, 13);
		Vect4D MV1(2, 6, 10, 14);
		Vect4D MV2(3, 7, 11, 15);
		Vect4D MV3(4, 8, 12, 16);

		Matrix M(MV0, MV1, MV2, MV3);

		Vect4D vout1;
		Vect4D vout2;
		Vect4D vout3;

		vout1 = M * A;
		vout2 = M * B;
		vout3 = M * C;

		Vect_Mv_SIMD A_simd;
		A_simd = Vect_Mv_SIMD(1, 2, 3, 4);
		Vect_Mv_SIMD B_simd;
		B_simd = Vect_Mv_SIMD(11, 12, 13, 14);
		Vect_Mv_SIMD C_simd;
		C_simd = Vect_Mv_SIMD(21, 22, 23, 24);

		Vect_Mv_SIMD MV0_simd(1, 5, 9, 13);
		Vect_Mv_SIMD MV1_simd(2, 6, 10, 14);
		Vect_Mv_SIMD MV2_simd(3, 7, 11, 15);
		Vect_Mv_SIMD MV3_simd(4, 8, 12, 16);

		CHECK(M.v0.x == 1.0f);

		Matrix_Mv_SIMD M_simd;
		M_simd = Matrix_Mv_SIMD(MV0_simd, MV1_simd, MV2_simd, MV3_simd);

		Vect_Mv_SIMD vout1_simd;
		Vect_Mv_SIMD vout2_simd;
		Vect_Mv_SIMD vout3_simd;

		vout1_simd = M_simd * A_simd;
		vout2_simd = M_simd * B_simd;
		vout3_simd = M_simd * C_simd;

		CHECK(V_EQ(M.v0, M_simd.v0));
		CHECK(V_EQ(M.v1, M_simd.v1));
		CHECK(V_EQ(M.v2, M_simd.v2));
		CHECK(V_EQ(M.v3, M_simd.v3));

		CHECK(V_EQ(A, A_simd));
		CHECK(V_EQ(B, B_simd));
		CHECK(V_EQ(C, C_simd));

		CHECK(V_EQ(vout1, vout1_simd));
		CHECK(V_EQ(vout2, vout2_simd));
		CHECK(V_EQ(vout3, vout3_simd));
	}

	// ---------------------------------------------------
	// LERP tests
	// ---------------------------------------------------
	{
		Vect4D va(0.0f, 0.0f, 0.0f, 0.0f);
		Vect4D vb(10.0f, 20.0f, 30.0f, 40.0f);
		Vect4D vout;

		vout = Vect4D::Lerp(va, vb, 0.0f);

		CHECK((vout.x == 0.0f));
		CHECK((vout.y == 0.0f));
		CHECK((vout.z == 0.0f));
		CHECK((vout.w == 0.0f));

		Vect4D vc(0.0f, 0.0f, 0.0f, 0.0f);
		Vect4D vd(10.0f, 20.0f, 30.0f, 40.0f);

		vout = Vect4D::Lerp(vc, vd, 0.5f);

		CHECK((vout.x == 5.0f));
		CHECK((vout.y == 10.0f));
		CHECK((vout.z == 15.0f));
		CHECK((vout.w == 20.0f));

		Vect4D ve(0.0f, 0.0f, 0.0f, 0.0f);
		Vect4D vf(10.0f, 20.0f, 30.0f, 40.0f);

		vout = Vect4D::Lerp(ve, vf, 0.25f);

		CHECK((vout.x == 2.5f));
		CHECK((vout.y == 5.0f));
		CHECK((vout.z == 7.50f));
		CHECK((vout.w == 10.0f));

		Vect4D vg(0.0f, 0.0f, 0.0f, 0.0f);
		Vect4D vh(10.0f, 20.0f, 30.0f, 40.0f);

		vout = Vect4D::Lerp(vg, vh, 1.0f);

		CHECK((vout.x == 10.0f));
		CHECK((vout.y == 20.0f));
		CHECK((vout.z == 30.0f));
		CHECK((vout.w == 40.0f));

		Vect_LERP_SIMD va_simd(0.0f, 0.0f, 0.0f, 0.0f);
		Vect_LERP_SIMD vb_simd(10.0f, 20.0f, 30.0f, 40.0f);
		Vect_LERP_SIMD vout_simd;

		vout_simd = Vect_LERP_SIMD::Lerp(va_simd, vb_simd, 0.0f);

		CHECK((vout_simd.x == 0.0f));
		CHECK((vout_simd.y == 0.0f));
		CHECK((vout_simd.z == 0.0f));
		CHECK((vout_simd.w == 0.0f));

		Vect_LERP_SIMD vc_simd(0.0f, 0.0f, 0.0f, 0.0f);
		Vect_LERP_SIMD vd_simd(10.0f, 20.0f, 30.0f, 40.0f);

		vout_simd = Vect_LERP_SIMD::Lerp(vc_simd, vd_simd, 0.5f);

		CHECK((vout_simd.x == 5.0f));
		CHECK((vout_simd.y == 10.0f));
		CHECK((vout_simd.z == 15.0f));
		CHECK((vout_simd.w == 20.0f));

		Vect_LERP_SIMD ve_simd(0.0f, 0.0f, 0.0f, 0.0f);
		Vect_LERP_SIMD vf_simd(10.0f, 20.0f, 30.0f, 40.0f);

		vout_simd = Vect_LERP_SIMD::Lerp(ve_simd, vf_simd, 0.25f);

		CHECK((vout_simd.x == 2.5f));
		CHECK((vout_simd.y == 5.0f));
		CHECK((vout_simd.z == 7.50f));
		CHECK((vout_simd.w == 10.0f));

		Vect_LERP_SIMD vg_simd(0.0f, 0.0f, 0.0f, 0.0f);
		Vect_LERP_SIMD vh_simd(10.0f, 20.0f, 30.0f, 40.0f);

		vout_simd = Vect_LERP_SIMD::Lerp(vg_simd, vh_simd, 1.0f);

		CHECK((vout_simd.x == 10.0f));
		CHECK((vout_simd.y == 20.0f));
		CHECK((vout_simd.z == 30.0f));
		CHECK((vout_simd.w == 40.0f));

		Vect_LERP_SIMD vOut;
		Vect_LERP_SIMD A(1.00f, 2.0f, 3.0f, 4.0f);
		Vect_LERP_SIMD B(21.00f, 12.0f, 23.0f, 40.0f);

		vOut = Vect_LERP_SIMD::Lerp(A, B, 0.5f);

		CHECK((vOut.x == 11.0f));
		CHECK((vOut.y == 7.0f));
		CHECK((vOut.z == 13.0f));
		CHECK((vOut.w == 22.0f));

		vOut = Vect_LERP_SIMD::Lerp(A, vOut, 0.5f);

		CHECK((vOut.x == 6.0f));
		CHECK((vOut.y == 4.5f));
		CHECK((vOut.z == 8.0f));
		CHECK((vOut.w == 13.0f));

		Vect_LERP_SIMD vOut_SIMD;
		Vect_LERP_SIMD A_SIMD(1.00f, 2.0f, 3.0f, 4.0f);
		Vect_LERP_SIMD B_SIMD(21.00f, 12.0f, 23.0f, 40.0f);

		vOut_SIMD = Vect_LERP_SIMD::Lerp(A_SIMD, B_SIMD, 0.5f);

		CHECK((vOut_SIMD.x == 11.0f));
		CHECK((vOut_SIMD.y == 7.0f));
		CHECK((vOut_SIMD.z == 13.0f));
		CHECK((vOut_SIMD.w == 22.0f))

		vOut_SIMD = Vect_LERP_SIMD::Lerp(A_SIMD, vOut_SIMD, 0.5f);

		CHECK((vOut_SIMD.x == 6.0f));
		CHECK((vOut_SIMD.y == 4.5f));
		CHECK((vOut_SIMD.z == 8.0f));
		CHECK((vOut_SIMD.w == 13.0f));
	}

} TEST_END
#endif

// ---  End of File ---------------
