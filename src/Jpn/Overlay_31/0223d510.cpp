#if defined(jpn)
#include <globaldefs.h>

// JPN: func_ov031_0223d510
// Sets visible layers and colour effects for a Wi-Fi display window region.
// Regions 0 and 1 are WIN0/WIN1, 2 is the object window, and 3 is outside the windows.
extern "C" ARM void SetWifiDisplayWindowLayerMask(int displayEngine, int windowRegion, unsigned short layerMask, int enableColorEffects) {
    switch (windowRegion) {
    case 0: {
        if (displayEngine == 1) {
            unsigned windowMask = *(volatile unsigned short*)0x4001048;
            windowMask = (windowMask & ~0x3f) | layerMask;
            if (enableColorEffects) windowMask |= 0x20;
            *(volatile unsigned short*)0x4001048 = windowMask;
        } else {
            unsigned windowMask = *(volatile unsigned short*)0x4000048;
            windowMask = (windowMask & ~0x3f) | layerMask;
            if (enableColorEffects) windowMask |= 0x20;
            *(volatile unsigned short*)0x4000048 = windowMask;
        }
        break;
    }
    case 1: {
        if (displayEngine == 1) {
            unsigned windowMask = *(volatile unsigned short*)0x4001048;
            windowMask = (windowMask & ~0x3f00) | (layerMask << 8);
            if (enableColorEffects) windowMask |= 0x2000;
            *(volatile unsigned short*)0x4001048 = windowMask;
        } else {
            unsigned windowMask = *(volatile unsigned short*)0x4000048;
            windowMask = (windowMask & ~0x3f00) | (layerMask << 8);
            if (enableColorEffects) windowMask |= 0x2000;
            *(volatile unsigned short*)0x4000048 = windowMask;
        }
        break;
    }
    case 2: {
        if (displayEngine == 1) {
            unsigned windowMask = *(volatile unsigned short*)0x400104a;
            windowMask = (windowMask & ~0x3f00) | (layerMask << 8);
            if (enableColorEffects) windowMask |= 0x2000;
            *(volatile unsigned short*)0x400104a = windowMask;
        } else {
            unsigned windowMask = *(volatile unsigned short*)0x400004a;
            windowMask = (windowMask & ~0x3f00) | (layerMask << 8);
            if (enableColorEffects) windowMask |= 0x2000;
            *(volatile unsigned short*)0x400004a = windowMask;
        }
        break;
    }
    case 3: {
        if (displayEngine == 1) {
            unsigned windowMask = *(volatile unsigned short*)0x400104a;
            windowMask = (windowMask & ~0x3f) | layerMask;
            if (enableColorEffects) windowMask |= 0x20;
            *(volatile unsigned short*)0x400104a = windowMask;
        } else {
            unsigned windowMask = *(volatile unsigned short*)0x400004a;
            windowMask = (windowMask & ~0x3f) | layerMask;
            if (enableColorEffects) windowMask |= 0x20;
            *(volatile unsigned short*)0x400004a = windowMask;
        }
        break;
    }
    }
}

#endif
