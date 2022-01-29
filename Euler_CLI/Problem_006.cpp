#include "Problems.h"

int64_t Problem_006::solve()
{
    int64_t sum_of_squares = 0, sum = 0;

    for (int64_t number = 1; number <= 100; number++) {
        sum_of_squares += number * number;
        sum += number;
    }

    return sum * sum - sum_of_squares;
}