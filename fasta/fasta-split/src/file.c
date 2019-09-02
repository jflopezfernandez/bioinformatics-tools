
#include "fasta.h"

FILE* open_file(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);

    if (file == NULL) {
        fprintf(stderr, "[Error] %s (%s)\n", "Failed to open file", filename);
        exit(EXIT_FAILURE);
    }

    return file;
}

void close_file(FILE* file) {
    if (fclose(file) == EOF) {
        fprintf(stderr, "[Error] Fatal error while attempting to close file\n");
        exit(EXIT_FAILURE);
    }
}
