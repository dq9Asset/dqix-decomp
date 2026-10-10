// usa: 02032424
// jpn: 02031f5c
#include "Graphics/Vector.h"
extern "C" fix32_t func_02032424(const Vector3fix* a, const Vector3fix* b) {
 Vector3fix delta;
 Vector3fix_Subtract(b,a,&delta);
 Vector3fix_Normalize(&delta,&delta);
 return fix32ReduceAngle0To2Pi(fix32_Atan2(-delta.x,-delta.z));
}
