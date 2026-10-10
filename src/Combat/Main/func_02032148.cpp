// usa: 02032148
// jpn: 02031c80
#include "Graphics/Vector.h"
struct Cylinder32148 { int x,y,z,radius,height; };
static inline int square(int x) { return FIX32_MULTIPLY(x,x); }
extern "C" int func_02032148(const Vector3fix* point, const Cylinder32148* cylinder) {
 if (cylinder->y > point->y) return 0;
 if (cylinder->y + cylinder->height < point->y) return 0;
int dx=point->x-cylinder->x;
int dz=point->z-cylinder->z;
int r=cylinder->radius;
int zs=square(dz);
int xs=square(dx);
int rs=square(cylinder->radius);
return rs >= xs+zs;
}