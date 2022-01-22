#include "Problems.h"

ProblemResult Problem_001::solve()
{
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	size_t sum = 0;
	for (int num = 1; num < 1000; num++) if (num % 5 == 0 || num % 3 == 0) sum += num;

	return ProblemResult(1, std::chrono::high_resolution_clock::now() - start, sum);
}