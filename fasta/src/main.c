
#include "fasta.h"

typedef enum {
    OPTION_NONE,
    OPTION_HELP,
    OPTION_VERSION,
    OPTION_VERBOSE
} option_id_t;

struct option_t {
    option_id_t id;
    int takes_argument;
    int argument_optional;
    const char* short_option;
    const char* long_option;
    const char* description;
};

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

#if defined(NONE)
#undef NONE
#endif

#if defined(NA)
#undef NA
#endif

int main(int argc, char **argv)
{
    if (argc == 1) {
        fprintf(stderr, "[Error] %s\n", "No input(s).");
        exit(EXIT_FAILURE);
    }

    while (*++argv) {
        FILE* file = fopen(*argv, "r");

        if (file == NULL) {
            fprintf(stderr, "[Error] %s (%s)\n", "Could not open file", *argv);
            exit(EXIT_FAILURE);
        }

        int current_character = 0;

        while ((current_character = fgetc(file)) != EOF) {
            fputc(current_character, stdout);
        }

        fclose(file);
    }

    return EXIT_SUCCESS;
}
