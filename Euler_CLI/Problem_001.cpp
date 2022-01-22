#include "Problems.h"

ProblemResult Problem_001::solve()
{
	CLOCK::time_point start = CLOCK::now();

	size_t sum = 0;
	for (int num = 1; num < 1000; num++) if (num % 5 == 0 || num % 3 == 0) sum += num;

	return ProblemResult(1, CLOCK::now() - start, sum);
}