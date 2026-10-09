#if defined(jpn)
#include <globaldefs.h>

struct Vec3s32_020c3030 { int x; int y; int z; };

#define REG_SQRTCNT_020c3030      (*(volatile unsigned short*)0x040002b0)
#define REG_SQRT_RESULT_020c3030  (*(volatile unsigned int*)0x040002b4)
#define REG_SQRTPARAM_LO_020c3030 (*(volatile unsigned int*)0x040002b8)
#define REG_SQRTPARAM_HI_020c3030 (*(volatile unsigned int*)0x040002bc)

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// JPN: func_020c4afc
extern "C" ARM int Vector3fix_Distance(Vec3s32_020c3030* a, Vec3s32_020c3030* b) {
    int dx = a->x - b->x;
    long long sq = (long long)dx * dx;
    int dy = a->y - b->y;
    sq += (long long)dy * dy;
    int dz = a->z - b->z;
    sq += (long long)dz * dz;
    REG_SQRTCNT_020c3030 = 1;
    unsigned long long scaled = (unsigned long long)sq << 2;
    REG_SQRTPARAM_LO_020c3030 = (unsigned int)scaled;
    REG_SQRTPARAM_HI_020c3030 = (unsigned int)(scaled >> 32);
    while (REG_SQRTCNT_020c3030 & 0x8000) {}
    return (int)(REG_SQRT_RESULT_020c3030 + 1) >> 1;
}


#endif
