#include <set>
#include <string>

#include "Problems.h"
#include "Utils.h"

int64_t Problem_041::solve()
{
    for (int64_t num = 7654321;; num--)
    {
        if (utils::number::is_prime(num) == false)
            continue;

        std::vector<int64_t> digits = utils::number::get_digits(num);

        if (utils::vector::contains(digits, 0i64) == true)
            continue;

        std::set<int64_t> seen;

        for (int64_t digit : digits)
        {
            if (digit > digits.size())
                break;

            seen.insert(digit);
        }

        if (seen.size() == digits.size())
            return num;
    }
}

int64_t Problem_042::solve()
{
    std::vector<int64_t> triangle_numbers;
    int64_t counter = 0;

    for (int64_t n = 1; n <= 26; n++)
        triangle_numbers.push_back(utils::number::get_triangle_number(n));

    std::vector<std::string> words;
    utils::string::split_by_char(utils::file::read_single_line("../data/042.txt"), ',', words);

    for (std::string word : words)
    {
        utils::string::remove_char(word, '"');

        int64_t word_sum = 0;

        for (int64_t i = 0; i < word.length(); i++)
            word_sum += word[i] - '@';

        if (utils::vector::contains(triangle_numbers, word_sum))
            counter++;
    }

    return counter;
}