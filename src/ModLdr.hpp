#pragma once

#include "ModManager.hpp"

namespace ModLdr {
    bool init();
    void unload(HMODULE);
    void awaitUnload();
}