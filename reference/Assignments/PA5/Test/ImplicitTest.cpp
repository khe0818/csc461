//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "No_Implicit.h"

#if NDEBUG
#define COUNT 84333330
#else
#define COUNT 2433333
#endif

Vect_No_Protection  Implicit_No_Conversion()
{
	volatile float I_ValueX(2.0f/10.0f);
	volatile float I_ValueY(3.0f/10.0f);
	volatile float I_ValueZ(4.0f/10.0f);
	volatile float C_ValueX(6.0f/10.0f);
	volatile float C_ValueY(8.0f/10.0f);
	volatile float C_ValueZ(9.0f/10.0f);
	volatile float D_ValueX(11.0f/10.0f);
	volatile float D_ValueY(12.0f/10.0f);
	volatile float D_ValueZ(13.0f/10.0f);

	Vect_No_Protection A;

	A.setX(I_ValueX);
	A.setY(I_ValueY);
	A.setZ(I_ValueZ);

	Vect_No_Protection B(D_ValueX, I_ValueY, D_ValueZ);

	Vect_No_Protection C(C_ValueX, C_ValueY, C_ValueZ);

	C = A + B;

	Vect_No_Protection D(C);

	D.setX(D_ValueZ);

	C.setZ(I_ValueX);

	Vect_No_Protection E = A + B;

	A.set(I_ValueX, D_ValueY, C_ValueX);

	B = A + B + C + D;
	C = B + E;

	E.setZ(I_ValueX);

	Vect_No_Protection F;

	F.setX(C_ValueY);

	Vect_No_Protection G(F.getX(), A.getY(), B.getZ());
	Vect_No_Protection H;
	H.set(C.getZ(), C_ValueZ, F.getX());

	Vect_No_Protection I;
	I.set(D_ValueX, D_ValueY, D_ValueZ);
	I = G + H + F + E + C;

	return I;
}

Vect_No_Protection Implicit_With_Conversion()
{
// Disable warning message (simulating bad users)
#pragma warning( push )
#pragma warning( disable : 4244 )

	volatile int I_ValueX(2.0f/10.0f);
	volatile int I_ValueY(3.0f/10.0f);
	volatile int I_ValueZ(4.0f/10.0f);
	volatile char C_ValueX(6.0f/10.0f);
	volatile char C_ValueY(8.0f/10.0f);
	volatile char C_ValueZ(9.0f/10.0f);
	volatile double D_ValueX(11.0f/10.0f);
	volatile double D_ValueY(12.0f/10.0f);
	volatile double D_ValueZ(13.0f/10.0f);

	// Disable warning message (simulating bad users)
	#pragma warning( disable : 4244 )

	Vect_No_Protection A;

	A.setX(I_ValueX);
	A.setY(I_ValueY);
	A.setZ(I_ValueZ);

	Vect_No_Protection B(D_ValueX, I_ValueY, D_ValueZ);

	Vect_No_Protection C(C_ValueX, C_ValueY, C_ValueZ);

	C = A + B;

	Vect_No_Protection D(C);

	D.setX(D_ValueZ);

	C.setZ(I_ValueX);

	Vect_No_Protection E = A + B;

	A.set(I_ValueX, D_ValueY, C_ValueX);

	B = A + B + C + D;
	C = B + E;

	E.setZ(I_ValueX);

	Vect_No_Protection F;

	F.setX(C_ValueY);

	Vect_No_Protection G(F.getX(), A.getY(), B.getZ());
	Vect_No_Protection H;
	H.set(C.getZ(), C_ValueZ, F.getX());

	Vect_No_Protection I;
	I.set(D_ValueX, D_ValueY, D_ValueZ);
	I = G + H + F + E + C;

#pragma warning( pop ) 
	return I;

}

#if Implicit_Timing_Test_Enable
TEST(Timing, Implicit, Implicit_Timing_Test_Enable)
{
	
	CHECK(true);
	
	// Create a timer objects
	Timer t2;

	Vect_No_Protection AA;

	// start timer
	t2.Tic();

	for (int i = 0; i < COUNT; i++)
	{
		Vect_No_Protection BB = Implicit_With_Conversion();
		AA = AA + BB;
	}

	// stop timer
	t2.Toc();


	// Create a timer objects
	Timer t1;

	Vect_No_Protection A;

	// start timer
	t1.Tic();

	for (int i = 0; i < COUNT; i++)
	{
		Vect_No_Protection B = Implicit_No_Conversion();
		A = A + B;
	}

	// stop timer
	t1.Toc();


	Trace::out("\n");
	Trace::out("  A: %f %f %f\n", A.getX(), A.getY(), A.getZ());
	Trace::out(" AA: %f %f %f\n", AA.getX(), AA.getY(), AA.getZ());
	Trace::out("\n");
	Trace::out("Implicit_With_Conversion: %f s  (should be slower)\n", t2.TimeInSeconds());
	Trace::out("  Implicit_No_Conversion: %f s\n", t1.TimeInSeconds());
	Trace::out("                   Ratio: %f    (faster than implict conversion)\n", (t2.TimeInSeconds() / t1.TimeInSeconds()));

} TEST_END

#endif
// ---  End of File ---------------
