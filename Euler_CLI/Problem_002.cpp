#include "Problems.h"

int64_t Problem_002::solve()
{
	int64_t sum = 0, first = 0, second = 1, fibonacci_number;

	while (true)
	{
		fibonacci_number = first + second;

		if (fibonacci_number > 4000000)
			return sum;

		first = second;
		second = fibonacci_number;

		if (second % 2 == 0)
			sum += second;
	}
}