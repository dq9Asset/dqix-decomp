#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);
void InitBigStruct0205c790(char* obj);
struct Struct020dfc40;
void ResetStruct020dfc40(struct Struct020dfc40* p);

// USA: func_ov017_021a7328
ARM void InitObj_021a7328(char* obj) {
    ResetByteHeader((struct ByteHeader0204693c*)obj);
    obj[0] = 0x3f;
    *(int*)(obj + 0x8) = 0;
    *(int*)(obj + 0xc) = 0;
    *(int*)(obj + 0x10) = 0;
    *(int*)(obj + 0x20) = -1;
    *(int*)(obj + 0x14) = 0;
    *(int*)(obj + 0x18) = 0;
    InitBigStruct0205c790(obj + 0x24);
#if defined(jpn)
    ((SafeAllocator*)(obj + 0x1ec))->ResetAllocatorPointer();
    ResetStruct020dfc40((struct Struct020dfc40*)(obj + 0x200));
#else
    ((SafeAllocator*)(obj + 0x25c))->ResetAllocatorPointer();
    ResetStruct020dfc40((struct Struct020dfc40*)(obj + 0x270));
#endif
}
