#include "Problems.h"

ProblemResult Problem_002::solve()
{
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	size_t sum = 0, first = 0, second = 1, fibonacci_number;

	while (true)
	{
		fibonacci_number = first + second;

		if (fibonacci_number > 4000000)
			return ProblemResult(2, std::chrono::high_resolution_clock::now() - start, sum);

		first = second;
		second = fibonacci_number;

		if (second % 2 == 0)
			sum += second;
	}
}