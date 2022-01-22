#ifndef USAGE_H
#define USAGE_H

#include <iostream>

#include "Definitions.h"

class Usage
{
public:
	Usage(const char *exe) {
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
};

#endif // USAGE_H