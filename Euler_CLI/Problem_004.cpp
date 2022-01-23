#include "Problems.h"

ProblemResult Problem_004::solve()
{
    int multiple, highest_palindrome = -1;
    bool isPalindrome;

    CLOCK::time_point start = CLOCK::now();

    for (int number_1 = 999; number_1 >= 100; number_1--) {
        for (int number_2 = number_1; number_2 >= 100; number_2--) {

            multiple = number_1 * number_2;

            if (multiple <= highest_palindrome)
                break;

            isPalindrome = true;

            std::string temp = std::to_string(multiple);

            for (int i = 0; isPalindrome && i < temp.length() / 2; i++)
                isPalindrome = temp[i] == temp[temp.length() - i - 1];

            if (isPalindrome)
                highest_palindrome = multiple;
        }
    }
    return ProblemResult(4, CLOCK::now() - start, highest_palindrome);
}