
#include "fasta.h"

#ifndef NONE
#define NONE ""
#endif

#ifndef NA
#define NA (-1)
#endif

static const struct option_t options[] = {
    { OPTION_HELP   , FALSE, NA, "-h", "--help"   , "Display this help menu and exit"                },
    { OPTION_VERSION, FALSE, NA, NONE, "--version", "Display program version info and exit"          },
    { OPTION_VERBOSE, FALSE, NA, "-v", "--verbose", "Display detailed info during program execution" }
};

static const size_t number_of_program_options = sizeof (options) / sizeof (options[0]);

char **parse_program_options(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        printf("%s\n", argv[i]);
    }

    return NULL;
}

#if defined(NONE)
#undef NONE
#endif

#if defined(NA)
#undef NA
#endif
