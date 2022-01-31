#include <string>
#include <vector>

#include "Problems.h"
#include "Utils.h"

int64_t Problem_021::solve()
{
    int64_t sum = 0, num1, num2;

    for (int64_t i = 1; i <= 10000; i++) {
        num1 = num2 = 0;

        for (int64_t j = 1; j < i; j++)
            if (i % j == 0)
                num1 += j;

        for (int64_t j = 1; j < num1; j++)
            if (num1 % j == 0)
                num2 += j;

        if (num1 != num2 && i == num2)
            sum += num2;
    }

    return sum;
}

int64_t Problem_022::solve()
{
    std::string data = utils::file::read_single_line("../data/022.txt");
    utils::string::remove_char(data, '\"');

    std::vector<std::string> names;
    utils::string::split_by_char(data, ",", names);
    utils::vector::sort(names);

    int64_t value = 0;

    for (int64_t i = 0; i < names.size(); i++)
        for (char c : names[i])
            value += ((int64_t)c - '@') * (i + 1);

    return value;
}

int64_t Problem_023::solve()
{
    int64_t sum = 0;
    std::vector<bool> abundant(28124, false);

    for (int64_t i = 1; i < 28124; i++) {
        int64_t a_sum = 1, end = (int64_t) std::sqrt(i);

        for (int64_t j = 2; j <= end; j++)
            if (i % j == 0)
                a_sum += j + i / j;

        if (end * end == i)
            a_sum -= end;

        abundant[i] = a_sum > i;

        bool isSum = true;

        for (int64_t divisor = 0; isSum && divisor <= i; divisor++)
            isSum = !abundant[divisor] || !abundant[i - divisor];

        if (isSum)
            sum += i;
    }

    return sum;
}