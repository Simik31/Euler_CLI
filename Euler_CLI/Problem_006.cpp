#include "Problems.h"

ProblemResult Problem_006::solve()
{
    long sum_of_squares = 0, sum = 0;

    CLOCK::time_point start = CLOCK::now();

    for (int number = 1; number <= 100; number++) {
        sum_of_squares += number * number;
        sum += number;
    }

    long result = sum * sum - sum_of_squares;

    return ProblemResult(6, CLOCK::now() - start, result);
}