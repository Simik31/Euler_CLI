#include "Problems.h"

int64_t Problem_001::solve()
{
	int64_t sum = 0;
	for (int num = 1; num < 1000; num++)
		if (num % 5 == 0 || num % 3 == 0)
			sum += num;

	return sum;
}