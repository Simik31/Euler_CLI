#include "Problems.h"

ProblemResult Problem_009::solve()
{
    CLOCK::time_point start = CLOCK::now();

    for (int a = 1; a < 1000; a++)
        for (int b = a + 1; b < 1000 - a + 1; b++)
            for (int c = b + 1; c < 1000 - a - b + 1; c++)
                if (a + b + c == 1000 && a*a + b*b == c*c)
                    return ProblemResult(9, CLOCK::now() - start, a * b * c);
}