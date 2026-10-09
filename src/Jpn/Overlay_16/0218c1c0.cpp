#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_02029120(void* object);

struct Overlay16Context {
    SafeAllocator allocator;
    unsigned char child[0x80];
    int active;
};

// JPN: func_ov016_0218c1c0
extern "C" ARM void func_ov016_0218c1c0(Overlay16Context* context) {
    context->allocator.ResetAllocatorPointer();
    func_02029120(context->child);
    context->active = 1;
}

#endif

