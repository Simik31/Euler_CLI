#pragma once

#include <stdint.h>

#include "Utils.h"

class BigNumber
{
public:
	BigNumber();
	BigNumber(const uint64_t& value);
	BigNumber(const BigNumber& other);

	inline uint64_t get_buffer_pointer() { return this->buffer_pointer; }

	BigNumber operator+(const BigNumber& to_add);
	BigNumber operator*(const BigNumber& to_add);

	void echo();

private:
	static const uint64_t buffer_size = 1024;
	uint64_t buffer_pointer = 0;
	uint64_t buffer[buffer_size];
};

