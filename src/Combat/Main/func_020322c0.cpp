// usa: 020322c0
// jpn: 02031df8
#include "Graphics/Vector.h"
extern "C" fix32_t func_020322c0(void* object, const fix32_t* angle) {
 Vector3fix a = *(Vector3fix*)((char*)object + 0x24);
 Vector3fix_Normalize(&a, &a);
 fix32_t c = fix32cos(*angle);
 Vector3fix b;
 b.x = fix32sin(*angle);
 b.y = 0;
 b.z = c;
 Vector3fix_Normalize(&b, &b);
 return Vector3fix_InnerProduct(&b, &a);
}
