#if defined(jpn)
#include <globaldefs.h>

extern int data_020f1de0;

extern "C" void func_020cbe5c(int val, void* dst, unsigned int nBytes);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// JPN: func_020b930c
extern "C" ARM void _Z31InitializeModelAnimationFromJACP13AnimationDataPvP18NSBXXInternalModel(void* p0, void* p1, unsigned char* p2) {
    unsigned char byteVal;
    unsigned int i;
    unsigned short* arr;

    *(void**)((char*)p0 + 0x8) = p1;
    *(int*)((char*)p0 + 0xc) = data_020f1de0;
    byteVal = p2[0x17];
    *(unsigned char*)((char*)p0 + 0x19) = byteVal;
    func_020cbe5c(0, (char*)p0 + 0x1a, byteVal << 1);

    i = 0;
    arr = (unsigned short*)((char*)p1 + 0x14);
    if (i < *(unsigned short*)((char*)p1 + 0x6)) {
        do {
            unsigned short idx = arr[i];
            unsigned int val = *(unsigned int*)((char*)p1 + idx);
            *(unsigned short*)((char*)p0 + 0x1a + i * 2) = (unsigned short)((val >> 0x18) | 0x100);
            i++;
        } while (i < *(unsigned short*)((char*)p1 + 0x6));
    }
}


#endif
