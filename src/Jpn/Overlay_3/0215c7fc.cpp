#if defined(jpn)
#include <globaldefs.h>

struct Struct_0205ba68;
extern "C" void func_0205cdc8(struct Struct_0205ba68* s, int a, int b, int mode);
struct Node0205bacc;
extern "C" void func_0205ce2c(struct Node0205bacc* s, int val);
struct Struct_0205bcdc;
extern "C" void func_0205d03c(struct Struct_0205bcdc* s, int index);
extern "C" void func_0205ce64(void* s, int n);

// JPN: func_ov003_0215c7fc  (semantic: InitNodesFromState_0215c7fc)
extern "C" ARM void func_ov003_0215c7fc(char* obj) {
    int count, isSet, idx;
    unsigned char state = *(unsigned char*)(obj + 0x1a4);
    switch (state) {
    case 1:
        count = *(unsigned char*)(obj + 0x589);
        idx = *(signed char*)(obj + 0x584);
        isSet = 1;
        break;
    case 2:
        count = *(unsigned char*)(obj + 0x590);
        idx = *(signed char*)(obj + 0x585);
        isSet = 1;
        break;
    case 3:
        idx = *(signed char*)(obj + 0x586);
        isSet = 1;
        count = 2;
        break;
    }

    func_0205cdc8((struct Struct_0205ba68*)(obj + 0xf8), isSet, count, 0);
    func_0205cdc8((struct Struct_0205ba68*)(obj + 0x148), isSet, count, 0);
    func_0205ce2c((struct Node0205bacc*)(obj + 0xf8), count);
    func_0205ce2c((struct Node0205bacc*)(obj + 0x148), count);
    *(int*)(obj + 0xfc) = isSet;
    *(int*)(obj + 0x14c) = isSet;
    func_0205d03c((struct Struct_0205bcdc*)(obj + 0xf8), idx);
    func_0205ce64((void*)(obj + 0x148), idx);
}

#endif
