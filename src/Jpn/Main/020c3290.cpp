#if defined(jpn)
#include <globaldefs.h>

struct FixedVec3_17c4 {
    int x;
    int y;
    int z;
};

struct FixedMtx3_17c4 {
    struct FixedVec3_17c4 row0;
    struct FixedVec3_17c4 row1;
    struct FixedVec3_17c4 row2;
};

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// JPN: func_020c3290
extern "C" ARM void Mat3x3_ApplyToVector(struct FixedVec3_17c4* v, struct FixedMtx3_17c4* m, struct FixedVec3_17c4* out) {
    int vy = v->y;
    int vx = v->x;
    int vz = v->z;
    out->x = (int)(((long long)vx * m->row0.x + (long long)vy * m->row1.x + (long long)vz * m->row2.x) >> 12);
    out->y = (int)(((long long)vx * m->row0.y + (long long)vy * m->row1.y + (long long)vz * m->row2.y) >> 12);
    out->z = (int)(((long long)vx * m->row0.z + (long long)vy * m->row1.z + (long long)vz * m->row2.z) >> 12);
}


#endif
