// usa: 02032090
// jpn: 02031bc8
#include "Graphics/Vector.h"
struct Plane32090 { Vector3fix normal; fix32_t distance; };
extern "C" int func_02032090(const Vector3fix* start, const Vector3fix* end, const Plane32090* plane, fix32_t* fraction, Vector3fix* hit) {
 Vector3fix delta;
 Vector3fix_Subtract(end,start,&delta);
 fix32_t startDot=Vector3fix_InnerProduct(&plane->normal,start);
 fix32_t deltaDot=Vector3fix_InnerProduct(&plane->normal,&delta);
 *fraction=fix32_Divide(plane->distance-startDot,deltaDot);
 if (*fraction>=0 && *fraction<=0x1000) {
  Vector3fixMultiplyScalar(&delta,*fraction,hit);
  Vector3fix_Add(start,hit,hit);
  return 1;
 }
 return 0;
}
