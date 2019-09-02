
#ifndef PROJECT_INCLUDES_PROGRAM_OPTIONS_H
#define PROJECT_INCLUDES_PROGRAM_OPTIONS_H

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

char **parse_program_options(int argc, char **argv);

#endif // PROJECT_INCLUDES_PROGRAM_OPTIONS_H
