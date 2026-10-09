#if defined(jpn)
#include <globaldefs.h>

struct FixedVec3 { int x; int y; int z; };
struct ViewMatrix020c20d4 { int m[3][3]; int t[3]; };

extern "C" void Vector3fix_CrossProduct(int* a, int* b, int* out);
extern "C" void Vector3fix_Normalize(struct FixedVec3* out, struct FixedVec3* in);
extern "C" int Vector3fix_InnerProduct(struct FixedVec3* a, struct FixedVec3* b);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// JPN: func_020c3ba0
extern "C" ARM void Mat4x3_WriteViewMatrix(struct FixedVec3* eye, struct FixedVec3* up, struct FixedVec3* target, struct ViewMatrix020c20d4* out) {
    struct FixedVec3 forward;
    forward.x = eye->x - target->x;
    forward.y = eye->y - target->y;
    forward.z = eye->z - target->z;
    Vector3fix_Normalize(&forward, &forward);

    struct FixedVec3 right;
    Vector3fix_CrossProduct((int*)up, (int*)&forward, (int*)&right);
    Vector3fix_Normalize(&right, &right);

    struct FixedVec3 upAxis;
    Vector3fix_CrossProduct((int*)&forward, (int*)&right, (int*)&upAxis);

    out->m[0][0] = right.x;
    out->m[0][1] = upAxis.x;
    out->m[0][2] = forward.x;
    out->m[1][0] = right.y;
    out->m[1][1] = upAxis.y;
    out->m[1][2] = forward.y;
    out->m[2][0] = right.z;
    out->m[2][1] = upAxis.z;
    out->m[2][2] = forward.z;

    out->t[0] = -Vector3fix_InnerProduct(eye, &right);
    out->t[1] = -Vector3fix_InnerProduct(eye, &upAxis);
    out->t[2] = -Vector3fix_InnerProduct(eye, &forward);
}


#endif
