#include <globaldefs.h>

struct PackedField017 {
    unsigned int low : 12;
    unsigned int f12  : 4;
    unsigned int f16  : 5;
    unsigned int f21  : 5;
    unsigned int top  : 6;
};

// USA: func_ov017_021b2090  (semantic: ComparePackedField_021b2090)
// JPN: func_ov017_021b27b0
extern "C" ARM int func_ov017_021b2090(PackedField017 a, PackedField017 b) {
    if (a.low < b.low) return 1;
#if !defined(jpn)
    if (a.low > b.low) return 0;
#endif
    unsigned int va = 0;
    va = a.f12 * 1000000 + va;
    va = a.f16 * 10000 + va;
    va = a.f21 * 100 + va;
    va = a.top + va;
    unsigned int vb = 0;
    vb = b.f12 * 1000000 + vb;
    vb = b.f16 * 10000 + vb;
    vb = b.f21 * 100 + vb;
    vb = b.top + vb;
    if ((int)va < (int)vb) return 1;
    return 0;
}
