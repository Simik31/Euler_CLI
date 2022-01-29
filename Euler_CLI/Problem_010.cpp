#include "Problems.h"
#include "Utils.h"

ProblemResult Problem_010::solve()
{
    size_t prime_sum = 0;

    CLOCK::time_point start = CLOCK::now();

    for (size_t prime : utils::prime::get_bellow(2000000))
        prime_sum += prime;

    return ProblemResult(10, CLOCK::now() - start, prime_sum);
}