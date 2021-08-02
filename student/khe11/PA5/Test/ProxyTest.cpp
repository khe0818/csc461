//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "_UnitTestConfiguration.h"

#include "Proxy.h"
#include "No_Proxy.h"

#if NDEBUG
#define COUNT 30000000
#else
#define COUNT 3000000
#endif

Vect2D_No_Proxy NoProxyStress(void)
{
	volatile float v1 = 2.0f;
	volatile float v2 = 3.0f;
	volatile float v3 = 7.0f;
	volatile float v4 = -5.3f;
	volatile float v5 = 9.0f;
	volatile float v6 = 4.0f;
	volatile float v7 = 22.23f;
	volatile float v8 = 0.234f;

	Vect2D_No_Proxy A;

	Vect2D_No_Proxy B;
	B.setX(v1);
	B.setY(v2);

	Vect2D_No_Proxy C;
	C.set(v3, v4);

	Vect2D_No_Proxy D;
	D.set(v5, v6);

	Vect2D_No_Proxy E;
	E.set(v3, -v5);

	Vect2D_No_Proxy sum;
	sum.set(0.0f, 0.0f);

	sum = A + B + C + D + E;

	Vect2D_No_Proxy A1;

	Vect2D_No_Proxy B1;
	B1.setX(v4);
	B1.setY(v5);

	Vect2D_No_Proxy C1;
	C1.set(v2, v7);

	Vect2D_No_Proxy D1;
	D1.set(v3, v8);

	Vect2D_No_Proxy E1;
	E1.set(v5, -v2);

	Vect2D_No_Proxy sum2;
	sum2.set(0.0f, 0.0f);

	sum2 = A1 + B1 + C1 + D1 + E1;

	return sum2 + sum;
}

Vect2D ProxyStress(void)
{
	volatile float v1 = 2.0f;
	volatile float v2 = 3.0f;
	volatile float v3 = 7.0f;
	volatile float v4 = -5.3f;
	volatile float v5 = 9.0f;
	volatile float v6 = 4.0f;
	volatile float v7 = 22.23f;
	volatile float v8 = 0.234f;

	Vect2D A;

	Vect2D B;
	B.setX(v1);
	B.setY(v2);

	Vect2D C;
	C.set(v3, v4);

	Vect2D D;
	D.set(v5, v6);

	Vect2D E;
	E.set(v3, -v5);

	Vect2D sum;
	sum.set(0.0f, 0.0f);

	sum = A + B + C + D + E;

	Vect2D A1;

	Vect2D B1;
	B1.setX(v4);
	B1.setY(v5);

	Vect2D C1;
	C1.set(v2, v7);

	Vect2D D1;
	D1.set(v3, v8);

	Vect2D E1;
	E1.set(v5, -v2);

	Vect2D sum2;
	sum2.set(0.0f, 0.0f);

	sum2 = A1 + B1 + C1 + D1 + E1;

	return sum2+sum;
}

#if Proxy_Timing_Test_Enable
TEST(Timing, Proxy, Proxy_Timing_Test_Enable)
{
	
	CHECK(true);
	
	// Create a timer objects
	Timer t1;

	Vect2D A;
	// start timer
	t1.Tic();

	for (int i = 0; i < COUNT; i++)
	{
		Vect2D B = ProxyStress();
		A = A + B;
	}

	// stop timer
	t1.Toc();

	// Create a timer objects
	Timer t2;

	Vect2D_No_Proxy AA;

	// start timer
	t2.Tic();

	for (int i = 0; i < COUNT; i++)
	{
		Vect2D_No_Proxy BB = NoProxyStress();
		AA = AA + BB;
	}

	// stop timer
	t2.Toc();

	Trace::out("\n");
	Trace::out(" A: %f %f \n", A.getX(), A.getY() );
	Trace::out("AA: %f %f \n", AA.getX(), AA.getY());
	Trace::out("\n");
	Trace::out("   No_Proxy: %f s\n", t2.TimeInSeconds());
	Trace::out("using_Proxy: %f s\n", t1.TimeInSeconds());
	Trace::out("      Ratio: %f \n", (t2.TimeInSeconds() / t1.TimeInSeconds()));

} TEST_END
#endif

// ---  End of File ---------------
