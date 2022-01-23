#include "Problems.h"
#include "Utils.h"

ProblemResult Problem_003::solve()
{
	CLOCK::time_point start = CLOCK::now();

	size_t result = utils::prime::biggestPrimeDivisor(600851475143);

	return ProblemResult(3, CLOCK::now() - start, result);
}