#include "cfw_module.h"

bool cfw_module_start(const cfw_module_t *module,
                      const cfw_host_api_t *host) {
    if (!module || !module->info.name || !module->init || !host) {
        return false;
    }
    return module->init(host);
}

void cfw_module_stop(const cfw_module_t *module) {
    if (module && module->shutdown) {
        module->shutdown();
    }
}
