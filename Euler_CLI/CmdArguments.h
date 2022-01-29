#ifndef CMDARGUMENTS_H
#define CMDARGUMENTS_H

#include <string>
#include <vector>

#include "Utils.h"

class CmdArguments
{
public:
	CmdArguments(const int argc, const char* argv[])
	{
		if (argc < 2) utils::print::usage(std::string(argv[0]));

		this->index = 0;
		this->argc = argc;

		for (int a = 0; a < argc; a++)
			this->args.push_back(std::string(argv[a]));
	}

	bool next(std::string& arg)
	{
		if (this->index >= this->argc)
			return false;

		arg = this->args[this->index++];
		return true;
	}

private:
	int index, argc;
	std::vector<std::string> args;
};

#endif // CMDARGUMENTS_H