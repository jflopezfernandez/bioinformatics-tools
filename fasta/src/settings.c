
#include "fasta.h"

static struct settings_t settings;

setting_t get_setting_verbose(void) {
    return settings.verbose;
}

void set_setting_verbose(setting_t) {
    settings.verbose = TRUE;
}
