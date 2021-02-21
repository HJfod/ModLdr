#pragma once

#include <cstdint>
#include <Windows.h>

#define offset_type inline const uintptr_t

namespace ModLdr {
    offset_type base = (uintptr_t)GetModuleHandleA(0);

    namespace offsets {
        offset_type MenuLayerInit           = base + 0x1907b0;
        offset_type SettingsLayerInit       = base + 0x1DD420;
        offset_type HelpLayerInit           = base + 0x25C7B0;

        offset_type ButtonSpriteCreate      = base + 0x137D0;
        offset_type ButtonCreate            = base + 0x18EE0;

        offset_type FLAlertLayerCreate      = base + 0x227E0;
    }
}