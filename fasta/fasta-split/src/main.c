
#include "fasta.h"

static size_t current_fasta_sequence = 0;

static const char* derivative_filename(const char* original) {
    char* original_filename = strdup(basename(original));

    char* original_basename = strtok(original_filename, ".");

    if (original_basename == NULL) {
        fprintf(stderr, "[Error] %s\n", "Failed to get original file basename");
        exit(EXIT_FAILURE);
    }

    size_t length = strlen(original_basename) + strlen("-dddd.fasta");

    char* filename = malloc(sizeof (char) * length + 1);

    if (filename == NULL) {
        fprintf(stderr, "[Error] %s\n", "Memory allocation failure in derivative_filename");
        exit(EXIT_FAILURE);
    }

    sprintf(filename, "%s-%04lu.fasta", basename(original_basename), ++current_fasta_sequence);

    return filename;
}

int main(int argc, char **argv)
{
    /** If the user did not provide any arguments, don't bother calling the
     *  whole command-line argument processing apparatus; simply print the
     *  program help menu and exit with an error status.
     * 
     */
    if (argc == 1) {
        // TODO: Print program usage
        fprintf(stderr, "[Error] %s\n", "No input(s).");
        exit(EXIT_FAILURE);
    }

    /** This arguments vector pointer is where the parse_program_options
     *  function places the non-action/non-option arguments to be operated on
     *  by the actual function. For example, a program invocation of
     * 
     *      fasta split sample-file.fasta --verbose
     * 
     *  would result in an argument vector containing a single char* value,
     *  namely the "sample-file.fasta" string.
     * 
     */
    char **arguments = parse_program_options(argc, argv);

    while (*arguments) {
        FILE* input_file = open_file(*arguments, "r");
        FILE* output_file = open_file(derivative_filename(*arguments), "w");

        int started = FALSE;

        int current_character = 0;

        while ((current_character = fgetc(input_file)) != EOF) {
            if (current_character == '>') {
                if (started) {
                    close_file(output_file);
                    open_file(derivative_filename(*arguments), "w");
                } else {
                    started = TRUE;
                }
            }

            putc(current_character, output_file);
        }
        
        close_file(output_file);
        close_file(input_file);

        ++arguments;
    }

    return EXIT_SUCCESS;
}
