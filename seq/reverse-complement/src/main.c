
#include "reverse-complement.h"

enum {
    UNKNOWN_BASE_PAIR = '?',
    ADENINE  = 'A',
    CYTOSINE = 'C',
    GUANINE  = 'G',
    THYMINE  = 'T',
    URASIL   = 'U'
};

__attribute__((pure))
static inline char complement_base(char base) {
    switch (base) {
        case ADENINE:  return THYMINE;
        case CYTOSINE: return GUANINE;
        case GUANINE:  return CYTOSINE;
        case THYMINE:  return ADENINE;

        default: return UNKNOWN_BASE_PAIR;
    }
}

__attribute__((nonnull(1)))
static inline void reverse_complement(const char* sequence) {
    while (*sequence)
        putc(complement_base(toupper(*sequence++)), stdout);
}

int main(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i) {
        reverse_complement(argv[i]);
        putchar('\n');
    }

    return EXIT_SUCCESS;
}
