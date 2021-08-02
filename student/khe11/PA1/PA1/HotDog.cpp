//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"

#include "HotDog.h"

// place holder for compiling purposes
// In each method replace with your code
#define STUB_PLEASE_REPLACE(x) (x)

// Methods
HotDog::HotDog() {
	this->GetPrev = nullptr;
	this->GetNext = nullptr;
	this->GetCondiments = static_cast<unsigned char>(Condiments::Plain);
}

HotDog HotDog::operator = (const HotDog & m) {
	this->next = m.next;
	this->prev = m.prev;
	this->condiment = m.condiment;
	return *this;

}
HotDog::HotDog(const HotDog & m) {
	this->next = m.next;
	this->prev = m.prev;
	this->condiment = m.condiment;
}

HotDog::~HotDog() {
}
void HotDog::Minus(Condiments condiment)
{
	// Only use bit-wise operations
	STUB_PLEASE_REPLACE(condiment);
}

void HotDog::Add(Condiments condiment)
{
	// Only use bit-wise operations
	STUB_PLEASE_REPLACE(condiment);
}

int HotDog::GetCondiments()
{
	return (unsigned char) this->condiment;
}

HotDog *HotDog::GetNext()
{
	return this->next;
}

HotDog *HotDog::GetPrev()
{
	return this->prev;
}

void HotDog::SetNext(HotDog *pDog)
{
	this->next = pDog;
}

void HotDog::SetPrev(HotDog *pDog)
{
	this->prev = pDog;
}


// ---  End of File ---------------

