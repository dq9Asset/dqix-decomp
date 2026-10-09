#if defined(jpn)
#include <globaldefs.h>

struct FixedVec3_189c { int x; int y; int z; };

struct FixedMtx43_189c {
    struct FixedVec3_189c row0;
    struct FixedVec3_189c row1;
    struct FixedVec3_189c row2;
    struct FixedVec3_189c row3;
};

extern "C" void func_020cbff4(struct FixedMtx43_189c* src, struct FixedMtx43_189c* dst);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// JPN: func_020c3368
extern "C" ARM void Mat4x3_ApplyTranslation(struct FixedMtx43_189c* src, struct FixedMtx43_189c* dst, int x, int y, int z) {
    if (src != dst) func_020cbff4(src, dst);
    dst->row3.x = src->row3.x + (int)(((long long)x * src->row0.x + (long long)y * src->row1.x + (long long)z * src->row2.x) >> 12);
    dst->row3.y = src->row3.y + (int)(((long long)x * src->row0.y + (long long)y * src->row1.y + (long long)z * src->row2.y) >> 12);
    dst->row3.z = src->row3.z + (int)(((long long)x * src->row0.z + (long long)y * src->row1.z + (long long)z * src->row2.z) >> 12);
}


#endif
