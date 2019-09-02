
#include "fasta.h"

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
        FILE* file = open_file(*arguments++, "r");

        int current_character = 0;

        while ((current_character = fgetc(file)) != EOF) {
            fputc(current_character, stdout);
        }

        close_file(file);
    }

    return EXIT_SUCCESS;
}
