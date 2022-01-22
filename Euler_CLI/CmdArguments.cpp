#include "CmdArguments.h"

CmdArguments::CmdArguments(const int argc, const char* argv[])
{
	if (argc < 2) Usage{ argv[0] };

	this->index = 0;
	this->argc = argc;

	for (int a = 0; a < argc; a++)
		this->args.push_back(std::string{ argv[a] });
}

void CmdArguments::skip()
{
	this->index++;
}

bool CmdArguments::next(std::string& arg)
{
	if (this->index >= this->argc)
		return false;

	arg = this->args[this->index++];
	return true;
}