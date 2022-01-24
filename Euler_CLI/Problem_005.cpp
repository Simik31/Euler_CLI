#include "Problems.h"

ProblemResult Problem_005::solve()
{
    CLOCK::time_point start = CLOCK::now(); 
    
    for (long number = 20;; number += 20)
        if (number % 19 == 0 && number % 17 == 0 && number % 13 == 0 && number % 11 == 0 && number % 9 == 0
            && number % 18 == 0 && number % 7 == 0 && number % 16 == 0 && number % 15 == 0 && number % 8 == 0)
            return ProblemResult(5, CLOCK::now() - start, number);
}