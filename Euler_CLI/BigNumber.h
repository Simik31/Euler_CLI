#pragma once

#include <stdint.h>
#include <string>
#include <vector>

class BigNumber
{
public:
	BigNumber();
	BigNumber(const std::string& value);
	BigNumber(const uint64_t& value);
	BigNumber(const BigNumber& other);

	uint64_t get_buffer_pointer() { return this->buffer_pointer; }

	BigNumber operator+(const BigNumber& to_add);
	BigNumber operator*(const BigNumber& to_add);
	BigNumber operator*(const uint64_t& other);

	std::vector<uint64_t> get_buffer() const noexcept;
	std::uint64_t get_value() const noexcept;
	void echo() const noexcept;

	static BigNumber pow(const uint64_t& base, const uint64_t& power);

private:
	static const uint64_t buffer_size = 1024;
	uint64_t buffer_pointer = 0;
	uint64_t buffer[buffer_size] = {};

	bool is_valid_uint64() const noexcept;
};

