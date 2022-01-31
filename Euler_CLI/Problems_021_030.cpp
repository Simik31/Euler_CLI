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
    std::vector<std::string> lines;
    std::vector<std::string> names;

    utils::file::read_lines("../data/022.txt", lines);

    std::string data = lines[0];

    utils::string::remove_char(data, '\"');
    utils::string::split_by_char(data, ",", names);
    utils::vector::sort(names);

    int64_t value = 0;

    for (int64_t i = 0; i < names.size(); i++)
        for (char c : names[i])
            value += ((int64_t)c - '@') * (i + 1);

    return value;
}