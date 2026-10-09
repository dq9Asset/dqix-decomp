#if defined(jpn)
#include <globaldefs.h>

extern "C" void func_020cbeb8(int value, void* dst, int size);
extern "C" int func_ov031_02213a10(int mask, void* arg);
extern "C" int func_ov031_0221b5b4(int v);
extern "C" int InitializeWifiConnectionManager(void* p, int size);
extern "C" void ReleaseWifiConnectionResources(void);

struct WifiConnectionOptions {
    void* allocateCallback;
    void* releaseCallback;
    unsigned char unknown8;
    unsigned char unknown9;
    unsigned char unknownA;
    unsigned char unknownB;
};

struct WifiConnectionResources {
    void* managerWork;
    void* unknown4;
    void* callbackPair;
    void* callbackState;
    void* connectionState;
};

extern WifiConnectionResources data_ov031_0224f1c4;

// JPN: func_ov031_02213520
// Allocates the Wi-Fi connection subsystem's resource blocks and initializes its manager.
// Allocation and release are delegated to the supplied callbacks.
extern "C" ARM int AllocateWifiConnectionResources(WifiConnectionOptions* options) {
    WifiConnectionResources* resources = &data_ov031_0224f1c4;
    void* callbackState = (void*)((int (*)(int, int))options->allocateCallback)(1, 0x24);
    resources->callbackState = callbackState;
    func_020cbeb8(0, callbackState, 0x24);

    void* callbackStateBytes = resources->callbackState;
    *(void**)callbackStateBytes = options->allocateCallback;
    *(void**)((char*)callbackStateBytes + 4) = options->releaseCallback;
    *((unsigned char*)callbackStateBytes + 9) = 1;
    *((unsigned char*)callbackStateBytes + 0x16) = 1;
    *((unsigned char*)callbackStateBytes + 8) = 1;

    resources->connectionState = (void*)func_ov031_02213a10(0x10, (void*)0xd18);
    resources->managerWork  = (void*)func_ov031_02213a10(2, (void*)0x2300);
    resources->unknown4  = (void*)func_ov031_02213a10(4, (void*)0x58);
    resources->callbackPair  = (void*)func_ov031_02213a10(8, (void*)0xc);

    func_020cbeb8(0, resources->connectionState, 0xd18);
    func_020cbeb8(0, resources->managerWork, 0x2300);
    func_020cbeb8(0, resources->unknown4, 0x58);
    func_020cbeb8(0, resources->callbackPair, 0xc);

    unsigned char* connectionState = (unsigned char*)resources->connectionState;
    connectionState[0xd0a] = options->unknown8;
    connectionState[0xd0b] = (connectionState[0xd0b] & ~0x3) | (options->unknown9 & 0x3);

    void* allocatorCallbacks = resources->callbackPair;
    *(void**)allocatorCallbacks = options->allocateCallback;
    *(void**)((char*)allocatorCallbacks + 4) = options->releaseCallback;
    *(int*)((char*)allocatorCallbacks + 8) = 0;

    connectionState[0xd0c] = (connectionState[0xd0c] & ~0xf) | (options->unknownA & 0xf);
    connectionState[0xd0c] = (connectionState[0xd0c] & ~0x30) | ((options->unknownB & 3) << 4);

    func_ov031_0221b5b4((int)connectionState);

    int initializeResult = InitializeWifiConnectionManager(resources->managerWork, 0x2300);
    if (initializeResult == 1 || initializeResult > 4) {
        ReleaseWifiConnectionResources();
        return 0;
    }
    return 1;
}

#endif
