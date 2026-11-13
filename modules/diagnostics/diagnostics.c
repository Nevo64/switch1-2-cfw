#include "diagnostics.h"

static const cfw_host_api_t *g_host;

static bool diagnostics_init(const cfw_host_api_t *host) {
    if (!host || !host->log) return false;
    g_host = host;
    g_host->log("diagnostics module initialized (host simulation)");
    g_host->log("no console hardware or protected interfaces accessed");
    return true;
}

static void diagnostics_shutdown(void) {
    if (g_host && g_host->log) {
        g_host->log("diagnostics module stopped");
    }
    g_host = 0;
}

const cfw_module_t diagnostics_module = {
    .info = {
        .name = "diagnostics",
        .version = "0.1.0",
        .description = "Host-only lifecycle demonstration"
    },
    .init = diagnostics_init,
    .shutdown = diagnostics_shutdown
};
