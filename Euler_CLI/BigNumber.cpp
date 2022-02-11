#include "BigNumber.h"
#include "Utils.h"

BigNumber::BigNumber()
{
	this->buffer_pointer = 1;
	this->buffer[0] = 0;
}

BigNumber::BigNumber(const std::string& value)
{
	for (int64_t index = value.size() - 1; index >= 0; index--)
		this->buffer[buffer_pointer++] = (uint64_t) value[index] - '0';
}

BigNumber::BigNumber(const uint64_t& value)
{
	uint64_t v = value;

	do
	{
		this->buffer[buffer_pointer++] = v % 10;
		v = v / 10;
	} while (v);
}

BigNumber::BigNumber(const BigNumber& other)
{
	for (int64_t buffer_offset = 0; buffer_offset < other.buffer_pointer; buffer_offset++)
		this->buffer[this->buffer_pointer++] = other.buffer[buffer_offset];
}

BigNumber BigNumber::operator+(const BigNumber& other)
{
	BigNumber new_number;

	while (this->buffer_pointer < other.buffer_pointer) this->buffer[this->buffer_pointer++] = 0;

	uint64_t carry = 0;

	for (int64_t buffer_offset = 0; buffer_offset < this->buffer_pointer; buffer_offset++)
	{
		uint64_t product = this->buffer[buffer_offset] + other.buffer[buffer_offset] + carry;
		new_number.buffer[buffer_offset] = product % 10;
		carry = product / 10;
	}

	new_number.buffer_pointer = this->buffer_pointer;

	while (carry > 0)
	{
		new_number.buffer[new_number.buffer_pointer] = carry % 10;
		carry = carry / 10;
		new_number.buffer_pointer++;

		if (new_number.buffer_pointer >= BigNumber::buffer_size)
		{
			utils::print::error("BigNumber buffer_size overflow: " + std::to_string(new_number.buffer_pointer) + " >= " + std::to_string(buffer_size));
			exit(EXIT_FAILURE);
		}
	}

	return new_number;
}

BigNumber BigNumber::operator*(const BigNumber& other)
{
	BigNumber new_number(*this), original(*this);

	for (int64_t multiplicant = 1; multiplicant < other.get_value(); multiplicant++)
		new_number = new_number + original;

	return new_number;
}

BigNumber BigNumber::operator*(const uint64_t& other)
{
	BigNumber new_number(*this), original(*this);

	for (int64_t multiplicant = 1; multiplicant < other; multiplicant++)
		new_number = new_number + original;

	return new_number;
}

bool BigNumber::operator==(const BigNumber& other)
{
	if (this->buffer_pointer != other.buffer_pointer)
		return false;

	for (int64_t buffer_offset = 0; buffer_offset < this->buffer_pointer; buffer_offset++)
		if (this->buffer[buffer_offset] != other.buffer[buffer_offset])
			return false;

	return true;
}

std::vector<uint64_t> BigNumber::get_buffer() const noexcept
{
	std::vector<uint64_t> buf;

	for (int64_t buffer_offset = this->buffer_pointer - 1; buffer_offset >= 0; buffer_offset--)
		buf.push_back(this->buffer[buffer_offset]);

	return buf;
}

uint64_t BigNumber::get_value() const noexcept
{
	if (this->is_valid_uint64() == false)
	{
		utils::print::error("BigNumber::get_value can not return value of number bigger than uint64_t max size");
		exit(EXIT_FAILURE);
	}

	int64_t value = 0;
	for (int64_t buffer_offset = this->buffer_pointer - 1; buffer_offset >= 0; buffer_offset--)
		value = value * 10 + this->buffer[buffer_offset];

	return value;
}

void BigNumber::echo() const noexcept
{
	printf("BigNumber::echo | buffer_size = %4zu, buffer_pointer = %4zu, value: ", buffer_size, buffer_pointer);

	for (int64_t buffer_offset = this->buffer_pointer - 1; buffer_offset >= 0; buffer_offset--)
		printf("%zu", this->buffer[buffer_offset]);

	printf("\n");
}

BigNumber BigNumber::pow(const uint64_t& base, const uint64_t& power)
{
	if (power == 0) return BigNumber(1);

	BigNumber original(base), new_number(base);

	for (uint64_t p = 1; p < power; p++)
		new_number = new_number * original;

	return new_number;
}

bool BigNumber::is_valid_uint64() const noexcept
{
	if (this->buffer_pointer < 20) return true;
	if (this->buffer_pointer > 20) return false;
	
	double value = 0;
	for (int64_t buffer_offset = this->buffer_pointer - 1; buffer_offset >= 0; buffer_offset--)
		value = value * 10 + this->buffer[buffer_offset];

	return value <= UINT64_MAX;
}