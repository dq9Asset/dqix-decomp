#include <globaldefs.h>

#if defined(jpn)
namespace { enum { kCoordinateOffset = 0x7e4, kDeltaOffset = 0x104 }; }
// JPN: func_0206cfd4
extern "C" ARM void func_0206cfd4(char* base) {
#else
namespace { enum { kCoordinateOffset = 0x914, kDeltaOffset = 0x144 }; }
// USA: func_0206b7b0
ARM void StoreClampedDeltas_0206b7b0(char* base) {
#endif
    short a = *(short*)(base + kCoordinateOffset);
    short b = *(short*)(base + kCoordinateOffset + 4);
    short c = *(short*)(base + kDeltaOffset + 4);
    short d = *(short*)(base + kDeltaOffset + 6);
    short e = *(short*)(base + kCoordinateOffset + 2);
    short v2 = a + b - c;
    if (v2 < 0) v2 = 0;
    short v1 = e - d;
    if (v1 < 0) v1 = 0;
    *(short*)(base + kDeltaOffset) = v2;
    *(short*)(base + kDeltaOffset + 2) = v1;
}
