#include "Problems.h"

ProblemResult Problem_002::solve()
{
	CLOCK::time_point start = CLOCK::now();

	size_t sum = 0, first = 0, second = 1, fibonacci_number;

	while (true)
	{
		fibonacci_number = first + second;

		if (fibonacci_number > 4000000)
			return ProblemResult(2, CLOCK::now() - start, sum);

		first = second;
		second = fibonacci_number;

		if (second % 2 == 0)
			sum += second;
	}
}