
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

static option_id_t argument_is_valid_option(const char* arg) {
    for (size_t i = 0; i < number_of_program_options; ++i) {
        if (strings_match(arg, options[i].short_option) || strings_match(arg, options[i].long_option)) {
            return options[i].id;
        }
    }

    return OPTION_NONE;
}

static char **arguments_vector = NULL;

static size_t arguments = 0;

static void add_argument(const char* argument) {
    arguments_vector = reallocarray(arguments_vector, ++arguments, sizeof (char *));

    if (arguments_vector == NULL) {
        fprintf(stderr, "[Error] %s\n", "Memory reallocation failure in parse_program_options");
        exit(EXIT_FAILURE);
    }

    if (argument) {
        arguments_vector[arguments - 1] = strdup(argv[i]);

        if (arguments_vector[arguments - 1] == NULL) {
            fprintf(stderr, "[Error] %s\n", "Memory allocation failure in parse_program_options");
        }
    } else {
        arguments_vector[arguments - 1] = NULL;
    }
}

char **parse_program_options(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        option_id_t option_id = argument_is_valid_option(argv[i]);

        /** If the string did not match any valid options, assume it's an
         *  argument. Short circuit right away, incrementing the number of
         *  arguments and reallocating the arguments vector to the appropriate
         *  size.
         * 
         */
        if (option_id == OPTION_NONE) {
            add_argument(argv[i]);
            continue;
        }

        switch (option_id) {
            case OPTION_HELP: {
                // TODO: Print help
                printf("<This is the help menu>\n");
                exit(EXIT_SUCCESS);
            } break;

            case OPTION_VERSION: {
                // TODO: Print version info
                printf("<This is the version info>\n");
                exit(EXIT_SUCCESS);
            } break;

            case OPTION_VERBOSE: {
                // TODO: Handle verbose option
                printf("-- verbose information output enabled --\n");
            } break;

            default: {
                fprintf(stderr, "[Error] Option id not recognized: %d\n", option_id);
            }
        }
    }

    add_argument(NULL);

    return arguments_vector;
}

#if defined(NONE)
#undef NONE
#endif

#if defined(NA)
#undef NA
#endif
