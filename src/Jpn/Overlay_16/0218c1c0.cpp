#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_02029120(void* viewerChild);

struct MovieViewer {
    SafeAllocator allocator;
    unsigned char unknown14[0x80];
    int unknown94;
};

// JPN: func_ov016_0218c1c0
// Initializes the movie viewer context before the movie selection list is built.
// The embedded child's precise type is not yet established.
extern "C" ARM void InitializeMovieViewer(MovieViewer* viewer) {
    viewer->allocator.ResetAllocatorPointer();
    func_02029120(viewer->unknown14);
    viewer->unknown94 = 1;
}

#endif

