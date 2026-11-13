#include <stdio.h>
#include "cfw_module.h"
#include "diagnostics.h"

static void host_log(const char *message) {
    printf("[host] %s\n", message ? message : "(null)");
}

int main(void) {
    const cfw_host_api_t host = { .log = host_log };

    puts("Horizon CFW scaffold — host demo only; not console firmware.");
    if (!cfw_module_start(&diagnostics_module, &host)) {
        fputs("Diagnostics module failed to start.\n", stderr);
        return 1;
    }
    cfw_module_stop(&diagnostics_module);
    return 0;
}
