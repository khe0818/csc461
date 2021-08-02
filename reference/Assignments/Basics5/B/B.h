//----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------

#ifndef B_H
#define B_H

class BankHoliday
{
public:
	BankHoliday();
	virtual void init();
};

class StPatricks : public BankHoliday
{
public:
	const char *GetDay();

private:
	virtual void init() override;
	const char *day;
};

#endif

// End of File