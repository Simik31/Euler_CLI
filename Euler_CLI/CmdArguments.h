#ifndef CMDARGUMENTS_H
#define CMDARGUMENTS_H

#include <string>
#include <vector>

#include "Utils.h"

class CmdArguments
{
public:
	CmdArguments(const int argc, const char* argv[]);
	bool next(std::string& arg);
private:
	int index, argc;
	std::vector<std::string> args;
};

#endif // CMDARGUMENTS_H