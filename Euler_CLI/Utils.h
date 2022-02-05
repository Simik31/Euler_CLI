#pragma once

#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stack>
#include <Windows.h>

#include "BigNumber.h"
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
		static void set_color(int foreground, int background)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), foreground + 16 * background);
		}

		static void reset_color()
		{
			utils::console::set_color(COLOR_DARK_WHITE, COLOR_BLACK);
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

	namespace prime
	{
		static bool is_prime(int64_t number)
		{
			if (number == 1)
				return false;

			if (number == 2)
				return true;

			for (int i = 2; i <= std::sqrt(number) + 1; i++)
				if (number % i == 0)
					return false;

			return true;
		}

		static int64_t get_biggest_prime_divisor(int64_t n)
		{
			for (int64_t number = 2; number < std::sqrt(n); number++)
				if (n % number == 0)
					n /= number;
			return n;
		}

		static int64_t get_nth(int64_t n)
		{
			int64_t counter = 0;

			for (int64_t i = 2;; i++)
				if (is_prime(i) && ++counter == n)
					return i;
		}

		static std::vector<int64_t> get_bellow(int64_t max)
		{
			std::vector<int64_t> primes;

			for (int64_t number = 2; number <= max; number++)
				if (is_prime(number))
					primes.push_back(number);

			return primes;
		}
	}

	namespace string
	{
		static void split_by_char(const std::string& str, const char* sep, std::vector<std::string>& strings)
		{
			std::string separator{ sep };
			uint64_t initialPos = 0;
			uint64_t pos;

			strings.clear();

			while ((pos = str.find(separator, initialPos)) != std::string::npos)
			{
				strings.push_back(str.substr(initialPos, pos - initialPos));
				initialPos = pos + separator.size();
			}

			strings.push_back(str.substr(initialPos, min(pos, str.size()) - initialPos + 1));
		}

		static void remove_char(std::string& str, const char to_remove)
		{
			str.erase(std::remove(str.begin(), str.end(), to_remove), str.end());
		}
	}

	namespace vector
	{
		static void sort(std::vector<std::string>& vec)
		{
			std::sort(vec.begin(), vec.end());
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

			return line;
		}
	}

	namespace factorial
	{
		static BigNumber get_BigNumber(uint64_t value)
		{
			BigNumber fact(1);

			for (int64_t multiplicand = 2; multiplicand <= value; multiplicand++)
				fact = fact * multiplicand;

			return fact;
		}

		static uint64_t get_uint64(uint64_t value)
		{
			return get_BigNumber(value).get_value();
		}
	}

	namespace bin
	{
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
	}

	namespace palindrom
	{
		static bool is_palindromic(std::string number)
		{
			for (int64_t i = 0; i < number.length() / 2; i++)
				if (number[i] != number[number.length() - i - 1])
					return false;
			return true;
		}
	}
}
