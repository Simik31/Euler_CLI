#include "Problems.h"
#include "Utils.h"

ProblemResult Problem_007::solve()
{
	CLOCK::time_point start = CLOCK::now(); 
	
	size_t result = utils::prime::get_nth(10001);

	return ProblemResult(7, CLOCK::now() - start, result);
}