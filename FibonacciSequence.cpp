#include "FibonacciSequence.h"
#include "FibonacciSequenceIterator.h"

#include <stdexcept>

using namespace std;

FibonacciSequence::FibonacciSequence(uint64_t aLimit)
{
	fCurrent = 1;
	fLimit = aLimit;
	fPosition = 1;
	fPrevious = 0;
}

const uint64_t& FibonacciSequence::current() const
{
	return fCurrent;
}

const uint64_t& FibonacciSequence::getLimit() const
{
	return fLimit;	
}

void FibonacciSequence::advance()
{	
	if (fPosition <= fLimit || fLimit == 0)
	{
		uint64_t lNext = fCurrent + fPrevious;
		fPrevious = fCurrent;
		fCurrent = lNext;
		fPosition++;
	}
	else
	{
		throw out_of_range("Out of Limit");
	}
}


void FibonacciSequence::reset()
{
	fCurrent = 1;
	fPosition = 1;
	fPrevious = 0;
}


FibonacciSequenceIterator FibonacciSequence::begin() const
{
	FibonacciSequenceIterator Result = *this;
	return Result.begin();
}

FibonacciSequenceIterator FibonacciSequence::end() const
{
	FibonacciSequenceIterator Result = *this;
	return Result.end();
}