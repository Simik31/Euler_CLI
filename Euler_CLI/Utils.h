#pragma once

#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <Windows.h>

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

	// Source: https://www.geeksforgeeks.org/factorial-large-number/ | Edited
	namespace factorial
	{
		static std::vector<int64_t> get_digits(int64_t n)
		{
			int64_t buffer_size = 1, buffer[FACTORIAL_MAX_DIGITS] = { 1 };

			for (int64_t multiplicand = 2; multiplicand <= n; multiplicand++)
			{
				int64_t carry = 0;

				for (int64_t buffer_offset = 0; buffer_offset < buffer_size; buffer_offset++)
				{
					int64_t product = buffer[buffer_offset] * multiplicand + carry;
					buffer[buffer_offset] = product % 10;
					carry = product / 10;
				}

				while (carry > 0)
				{
					buffer[buffer_size] = carry % 10;
					carry = carry / 10;
					buffer_size++;

					if (buffer_size >= FACTORIAL_MAX_DIGITS)
					{
						print::error("Factorial digit count overflow");
						exit(EXIT_FAILURE);
					}
				}
			}

			std::vector<int64_t> digits;
			for (int64_t buffer_offset = buffer_size - 1; buffer_offset >= 0; buffer_offset--)
				digits.push_back(buffer[buffer_offset]);

			return digits;
		}

		static std::string get_string(int64_t n)
		{
			std::string factorial;
			for (int digit : get_digits(n))
				factorial.append(std::to_string(digit));

			return factorial;
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
	}
}
