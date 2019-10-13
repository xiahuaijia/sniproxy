#include <ev.h>
#include "config.h"

int main(int argc, char **argv) {
    const char *config_file = "../sniproxy.conf";
    struct Config *config;

    if (argc >= 2)
        config_file = argv[1];

    config = init_config(config_file, EV_DEFAULT);
    if (config == NULL) {
        fprintf(stderr, "Failed to parse config\n");
        return 1;
    }

    print_config(stdout, config);

    free_config(config, EV_DEFAULT);

    return 0;
}
