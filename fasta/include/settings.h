
#ifndef PROJECT_INCLUDES_SETTINGS_H
#define PROJECT_INCLUDES_SETTINGS_H

typedef enum {
    SETTING_NONE,
    SETTING_VERBOSE
} setting_t;

struct settings_t {
    setting_t verbose;
};

setting_t get_setting_verbose(void);

void set_setting_verbose(setting_t);

#endif // PROJECT_INCLUDES_SETTINGS_H
