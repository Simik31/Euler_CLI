#include "CmdArguments.h"

CmdArguments::CmdArguments(const int argc, const char* argv[])
{
	if (argc < 2) utils::print::usage(std::string(argv[0]));

	this->index = 0;
	this->argc = argc;

	for (int a = 0; a < argc; a++)
		this->args.push_back(std::string(argv[a]));
}

bool CmdArguments::next(std::string& arg)
{
	if (this->index >= this->argc)
		return false;

	arg = this->args[this->index++];
	return true;
}