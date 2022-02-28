#pragma once

#include <algorithm>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stack>
#include <Windows.h>

#include "vendor/bigint/BigIntegerLibrary.hh"

#include "Definitions.h"
#include "Problems.h"

namespace utils
{
	namespace convert
	{
		static double ns_to_s(CLOCK::duration ns)
		{
			return ns.count() / NANOSECONDS_IN_SECOND;
		}
	}

	namespace console
	{
		static void set_color(const int64_t& foreground, const int64_t& background)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foreground + 16 * background);
		}

		static void reset_color()
		{
			set_color(COLOR_DARK_WHITE, COLOR_BLACK);
		}
	}

	namespace print
	{
		static void error(const std::string& message)
		{
			utils::console::set_color(COLOR_RED, COLOR_BLACK);
			std::cerr << "--- ERROR ---" << std::endl;
			std::cerr << message << std::endl;
			std::cerr << "--- ERROR ---" << std::endl;
			utils::console::reset_color();
		}

		static void usage(const std::string& exe) {
			std::cerr <<
				"NAME:\n" <<
				"    " << NAME << " by " << ME << " / " << GITHUB_BASE_URL << ME << " / " << ME << EMAIL_DOMAIN << "\n" <<
				"\n" <<
				"USAGE:\n" <<
				"    " << exe << " COMMAND [subcommand]\n" <<
				"\n" <<
				"COMMANDS:\n" <<
				"    " << COMMAND_RUN_LONG << ", " << COMMAND_RUN_SHORT << "\n" <<
				"        Run project euler problem solver\n" <<
				"\n" <<
				"        subcommands:\n" <<
				"            " << SUBCOMMAND_RUN_ALL_LONG << ", " << SUBCOMMAND_RUN_ALL_SHORT << "    Solve all prolbems\n" <<
				"            " << SUBCOMMAND_RUN_ID << " <id>    Solve problem with ID <id> (<id> must de valid integer)\n" <<
				"    " << COMMAND_TEST_LONG << ", " << COMMAND_TEST_SHORT << "\n" <<
				"        Test UTILS class for incorrect results" << std::endl;
			exit(EXIT_FAILURE);
		}
	}

	namespace string
	{
		static void split_by_char(const std::string& str, const char& sep, std::vector<std::string>& strings)
		{
			uint64_t offset_pos = 0, pos;

			strings.clear();

			while ((pos = str.find(sep, offset_pos)) != std::string::npos)
			{
				strings.push_back(str.substr(offset_pos, pos - offset_pos));
				offset_pos = pos + 1;
			}

			strings.push_back(str.substr(offset_pos, min(pos, str.size()) - offset_pos + 1));
		}

		static void remove_char(std::string& str, const char& to_remove)
		{
			str.erase(std::remove(str.begin(), str.end(), to_remove), str.end());
		}
	}

	namespace vector
	{
		template<typename T>
		static void sort(std::vector<T>& vec)
		{
			std::sort(vec.begin(), vec.end());
		}

		template<typename T>
		static bool contains(const std::vector<T>& vec, const T& find)
		{
			return std::find(vec.begin(), vec.end(), find) != vec.end();
		}

		template<typename T>
		static std::vector<std::vector<T>> get_all_combinations(std::vector<T> vec)
		{
			std::vector<std::vector<T>> permutations;

			permutations.push_back(vec);
			while (std::next_permutation(vec.begin(), vec.end()))
				permutations.push_back(std::vector<T>(vec));

			return permutations;
		}
	}

	namespace file
	{
		static void read_lines(const std::string& file_path, std::vector<std::string>& lines)
		{
			std::ifstream file{ file_path };

			if (!file.is_open())
			{
				print::error("File not found or not accessible: " + std::filesystem::absolute(file_path).generic_string());
				exit(EXIT_FAILURE);
			}

			lines.clear();

			std::string line;
			while (getline(file, line))
				lines.push_back(line);

			file.close();
		}

		static std::string read_single_line(const std::string& file_path)
		{
			std::ifstream file{ file_path };

			if (!file.is_open())
			{
				print::error("File not found or not accessible: " + std::filesystem::absolute(file_path).generic_string());
				exit(EXIT_FAILURE);
			}

			std::string line;
			getline(file, line);

			file.close();

			return line;
		}
	}

	namespace number
	{
		static std::vector<int64_t> get_digits(int64_t number)
		{
			std::vector<int64_t> digits;

			while (number)
			{
				digits.push_back(number % 10);
				number /= 10;
			}

			return digits;
		}

		static bool is_palindromic(const std::string& num_str)
		{
			for (int64_t i = 0; i < num_str.length() / 2; i++)
				if (num_str[i] != num_str[num_str.length() - i - 1])
					return false;

			return true;
		}

		static bool is_prime(const int64_t& number)
		{
			if (number <= 1)
				return false;

			if (number == 2)
				return true;

			for (int i = 2; i <= std::sqrt(number) + 1; i++)
				if (number % i == 0)
					return false;

			return true;
		}

		static bool is_pandigital(int64_t number, const int64_t& range_min, const int64_t& range_max)
		{
			std::vector<int64_t> digits = get_digits(number);

			for (int64_t to_find = range_min; to_find <= range_max; to_find++)
				if (vector::contains(digits, to_find) == false) return false;

			return true;
		}

		static std::string dec_to_bin(uint64_t decimal)
		{
			std::stack<char> buffer;

			while (decimal)
			{
				buffer.push(decimal % 2 + '0');
				decimal /= 2;
			}

			std::string result;
			while (buffer.empty() == false)
			{
				result += buffer.top();
				buffer.pop();
			}

			return result;
		}

		static BigInteger get_factorial(const uint64_t& value)
		{
			BigInteger fact = 1;

			for (unsigned long multiplicand = 2; multiplicand <= value; multiplicand++)
				fact *= BigInteger(multiplicand);

			return fact;
		}

		static int64_t get_triangle_number(const int64_t& number)
		{
			return number * (number + 1) / 2;
		}

		static int64_t get_pentagonal_number(const int64_t& number)
		{
			return number * (3 * number - 1) / 2;
		}

		static int64_t get_hexagonal_number(const int64_t& number)
		{
			return number * (2 * number - 1);
		}

		static int64_t get_biggest_prime_divisor(int64_t num)
		{
			for (int64_t number = 2; number < std::sqrt(num); number++)
				if (num % number == 0)
					num /= number;

			return num;
		}

		static std::vector<int64_t> get_primes_divisors(int64_t number)
		{
			std::vector<int64_t> divs;

			for (int64_t num = 2; num < number; num++) 
			{
				if (number % num == 0)
				{
					if (is_prime(num))
					{
						divs.push_back(num);
						number /= num;
					}
				}
			}

			if (vector::contains(divs, number) == false && is_prime(number))
				divs.push_back(number);

			return divs;
		}


		static int64_t get_nth_prime(const int64_t& n)
		{
			int64_t counter = 0;

			for (int64_t num = 2;; num++)
				if (is_prime(num) && ++counter == n)
					return num;
		}

		static std::vector<int64_t> get_primes_in_range(const int64_t& min, const int64_t& max)
		{
			std::vector<int64_t> primes;

			for (int64_t number = min; number <= max; number++)
				if (is_prime(number))
					primes.push_back(number);

			return primes;
		}

		static std::vector<int64_t> get_primes_bellow(const int64_t& max)
		{
			std::vector<int64_t> primes;

			for (int64_t number = 2; number <= max; number++)
				if (is_prime(number))
					primes.push_back(number);

			return primes;
		}
	}

	namespace bigint
	{
		static inline const std::vector<int> get_digits(const BigInteger& big_int) noexcept
		{
			std::vector<int> digits;

			BigInteger modint = 1, ten = 10;

			while (big_int / modint > BigInteger::zero)
			{
				digits.insert(digits.begin(), 1, ((big_int % (modint * ten)) / modint).toInt());
				modint *= ten;
			}

			return digits;
		}

		static inline const std::vector<int> get_first_n_digits(const BigInteger& big_int, const int& n) noexcept
		{
			std::vector<int> digits = get_digits(big_int);
			return std::vector<int>(digits.begin(), digits.begin() + n);
		}

		static inline const std::vector<int> get_last_n_digits(const BigInteger& big_int, const int& n) noexcept
		{
			std::vector<int> digits = get_digits(big_int);
			return std::vector<int>(digits.end() - n, digits.end());
		}

		static inline const BigInteger pow(const int& base, const uint64_t& power) noexcept
		{
			if (power == 0) return BigInteger(1);

			BigInteger original(base), new_number(base);

			for (uint64_t p = 1; p < power; p++)
				new_number *= original;

			return new_number;
		}

		static inline const int get_length(const BigInteger& big_int) noexcept
		{
			int len = 0;
			for (BigInteger modint = 1, ten = 10; big_int / modint > BigInteger::zero; len++, modint *= ten) {}
			return len;
		}
	}
}
