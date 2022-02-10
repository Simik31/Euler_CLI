#include <set>
#include <string>
#include <vector>

#include "BigNumber.h"
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
    utils::string::split_by_char(data, ',', names);
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

int64_t Problem_024::solve()
{
    int64_t counter = 0;
    std::vector<int64_t> d1 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, d2, d3, d4, d5, d6, d7, d8;

    for (int64_t i1 = 0; i1 <= 9; i1++) {
        d2 = std::vector<int64_t>(d1);
        d2.erase(d2.begin() + i1);

        for (int64_t i2 = 0; i2 <= 8; i2++) {
            d3 = std::vector<int64_t>(d2);
            d3.erase(d3.begin() + i2);

            for (int64_t i3 = 0; i3 <= 7; i3++) {
                d4 = std::vector<int64_t>(d3);
                d4.erase(d4.begin() + i3);

                for (int64_t i4 = 0; i4 <= 6; i4++) {
                    d5 = std::vector<int64_t>(d4);
                    d5.erase(d5.begin() + i4);

                    for (int64_t i5 = 0; i5 <= 5; i5++) {
                        d6 = std::vector<int64_t>(d5);
                        d6.erase(d6.begin() + i5);

                        for (int64_t i6 = 0; i6 <= 4; i6++) {
                            d7 = std::vector<int64_t>(d6);
                            d7.erase(d7.begin() + i6);

                            for (int64_t i7 = 0; i7 <= 3; i7++) {
                                d8 = std::vector<int64_t>(d7);
                                d8.erase(d8.begin() + i7);

                                for (int64_t i8 = 0; i8 <= 2; i8++) {
                                    counter += 2;

                                    if (counter == 1000000)
                                        return d1[i1]              * 1000000000 +
                                               d2[i2]              * 100000000 +
                                               d3[i3]              * 10000000 + 
                                               d4[i4]              * 1000000 +
                                               d5[i5]              * 100000 +
                                               d6[i6]              * 10000 +
                                               d7[i7]              * 1000 +
                                               d8[i8]              * 100 +
                                               d8[i8 == 2 ? 1 : 2] * 10 +
                                               d8[i8 == 0 ? 1 : 0];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int64_t Problem_025::solve()
{
    BigNumber first, second(1), new_num;
    
    for (int64_t index = 2; ; index++) 
    {
        new_num = first + second;
    
        if (new_num.get_buffer_pointer() == 1000)
            return index;
    
        first = second;
        second = new_num;
    }
}

int64_t Problem_026::solve()
{
    int64_t result = 0, longest = 0;
    std::vector<int64_t> arr;

    for (int64_t i = 2; i < 1000; i++) {
        arr = std::vector<int64_t>(i + 1, 0);

        int64_t index = 1, mod = 1;

        while (mod != 0 && arr[mod] == 0) {
            arr[mod] = index++;
            mod = mod * 10 % i;
        }

        if (index - arr[mod] > longest) {
            longest = index - arr[mod];
            result = i;
        }
    }

    return result;
}

int64_t Problem_027::solve()
{
    int64_t result = -1, max_n = 0, n;

    for (int64_t a = -999; a < 1000; a += 2) {
        for (int64_t b = -1000; b <= 1000; b++) {
            n = 0;

            while (utils::number::is_prime(std::abs(n * n + a * n + b)))
                n++;

            if (n > max_n) {
                result = a * b;
                max_n = n;
            }
        }
    }

    return result;
}

int64_t Problem_028::solve()
{
    int64_t total = 0, layer = 0, counter = 3;

    for (int64_t number = 1; number <= 1002001; number += 2 * layer) {
        total += number;

        if (++counter == 4) {
            counter = 0;
            layer++;
        }
    }

    return total;
}

int64_t Problem_029::solve()
{
    std::set<double> powers;

    for (uint64_t a = 2; a <= 100; a++)
        for (uint64_t b = 2; b <= 100; b++)
            powers.insert(std::pow(a, b));

    return powers.size();
}

int64_t Problem_030::solve()
{
    int64_t total = 0, num_tot, num_copy;

    for (int64_t number = 2; number < 200000; number++) {
        num_copy = number;
        num_tot = 0;

        while (num_copy)
        {
            num_tot += std::pow(num_copy % 10, 5);
            num_copy /= 10;
        }

        if (num_tot == number)
            total += number;
    }

    return total;
}