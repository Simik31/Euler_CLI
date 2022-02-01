#include "BigNumber.h"

BigNumber::BigNumber()
{
	this->buffer_pointer = 1;
	this->buffer[0] = 0;
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
		this->buffer[buffer_pointer++] = other.buffer[buffer_offset];
}

BigNumber BigNumber::operator+(const BigNumber& other)
{
	while (this->buffer_pointer < other.buffer_pointer) this->buffer[this->buffer_pointer++] = 0;

	BigNumber new_number(*this);

	uint64_t carry = 0;

	for (int64_t buffer_offset = 0; buffer_offset < new_number.buffer_pointer; buffer_offset++)
	{
		uint64_t product = new_number.buffer[buffer_offset] + other.buffer[buffer_offset];
		new_number.buffer[buffer_offset] = product % 10;
		carry = product / 10;

		if (carry > 0)
		{
			new_number.buffer[buffer_offset + 1] += carry;

			if (new_number.buffer_pointer <= buffer_offset + 1) new_number.buffer_pointer++;
		
			if (new_number.buffer_pointer >= BigNumber::buffer_size)
			{
				utils::print::error("BigNumber buffer_size overflow: " + std::to_string(new_number.buffer_pointer) + " >= " + std::to_string(buffer_size));
				exit(EXIT_FAILURE);
			}
		}
	}

	return new_number;
}

BigNumber BigNumber::operator*(const BigNumber& other)
{
	while (this->buffer_pointer < other.buffer_pointer) this->buffer[this->buffer_pointer++] = 0;

	BigNumber new_number(*this);

	uint64_t carry = 0;

	for (int64_t mult_buffer_offset = 0; mult_buffer_offset < other.buffer_pointer; mult_buffer_offset++)
	{
		for (int64_t buffer_offset = 0; buffer_offset < this->buffer_pointer; buffer_offset++)
		{
			uint64_t product = new_number.buffer[buffer_offset] * other.buffer[mult_buffer_offset];
			new_number.buffer[buffer_offset + mult_buffer_offset] = product % 10;
			carry = product / 10;

			while (carry > 0)
			{
				new_number.buffer[buffer_offset + mult_buffer_offset + 1] += carry % 10;
				carry /= 10;

				while (new_number.buffer_pointer <= buffer_offset + mult_buffer_offset + 1) new_number.buffer_pointer++;

				if (new_number.buffer_pointer >= BigNumber::buffer_size)
				{
					utils::print::error("BigNumber buffer_size overflow: " + std::to_string(new_number.buffer_pointer) + " >= " + std::to_string(buffer_size));
					exit(EXIT_FAILURE);
				}
			}
		}
	}

	return new_number;
}

void BigNumber::echo()
{
	printf("BigNumber::echo | buffer_size = %zu, buffer_pointer = %zu, value: ", buffer_size, buffer_pointer);

	for (int64_t buffer_offset = this->buffer_pointer - 1; buffer_offset >= 0; buffer_offset--)
		printf("%zu", this->buffer[buffer_offset]);

	printf("\n");
}