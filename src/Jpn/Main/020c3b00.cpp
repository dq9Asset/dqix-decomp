#if defined(jpn)
#include <globaldefs.h>

struct FixedVec3_2034 {
    int x;
    int y;
    int z;
};

struct FixedMtx3T_2034 {
    struct FixedVec3_2034 row0;
    struct FixedVec3_2034 row1;
    struct FixedVec3_2034 row2;
    struct FixedVec3_2034 trans;
};

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// JPN: func_020c3b00
extern "C" ARM void Mat4x3_ApplyToVector(struct FixedVec3_2034* v, struct FixedMtx3T_2034* m, struct FixedVec3_2034* out) {
    int vy = v->y;
    int vx = v->x;
    int vz = v->z;
    out->x = (int)(((long long)vx * m->row0.x + (long long)vy * m->row1.x + (long long)vz * m->row2.x) >> 12);
    out->x += m->trans.x;
    out->y = (int)(((long long)vx * m->row0.y + (long long)vy * m->row1.y + (long long)vz * m->row2.y) >> 12);
    out->y += m->trans.y;
    out->z = (int)(((long long)vx * m->row0.z + (long long)vy * m->row1.z + (long long)vz * m->row2.z) >> 12);
    out->z += m->trans.z;
}


#endif
