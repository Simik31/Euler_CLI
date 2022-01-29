#include "Problems.h"

int64_t Problem_009::solve()
{
    for (int64_t a = 1; a < 1000; a++)
        for (int64_t b = a + 1; b < 1000 - a + 1; b++)
            for (int64_t c = b + 1; c < 1000 - a - b + 1; c++)
                if (a + b + c == 1000 && a*a + b*b == c*c)
                    return a * b * c;
}