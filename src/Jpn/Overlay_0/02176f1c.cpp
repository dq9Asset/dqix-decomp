#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0207a6d0(void);
extern "C" void* func_0207ac64(char* p, int key);
extern "C" void* func_02010684(GameState* battleStruct);
extern "C" void* func_ov000_02162a84(void* obj, int id);
extern "C" int func_ov000_02172c44(void* a, void* b);

// JPN: func_ov000_02176f1c
extern "C" ARM void func_ov000_02176f1c(void* obj) {
    void* data = func_0207a6d0();
    if (data == 0) {
        return;
    }
    signed char idx = *((signed char*)obj + 0x1f00 + 0xa5);
    signed short val = *(signed short*)((char*)obj + idx * 2 + 0x10);
    void* tableEntry = func_0207ac64((char*)data, val);
    if (tableEntry == 0) {
        return;
    }
    GameState* battleStruct = GameState::GetInstance();
    unsigned char* field2a04 = (unsigned char*)func_02010684(battleStruct);
    signed char combIdx = *(signed char*)(field2a04 + 0xf00 + 0x78);
    char* entry = (char*)func_ov000_02162a84(obj, combIdx);
    if (entry == 0) {
        return;
    }
    signed char cnt = *((signed char*)obj + 0x1f00 + 0xa0);
    *((char*)obj + 0x1000 + 0xfa0) = (char)(cnt + 1);
    int result = func_ov000_02172c44(tableEntry, entry);
    signed char cnt2 = *((signed char*)obj + 0x1f00 + 0xa0);
    *((char*)obj + cnt2 + 0x1000 + 0xf98) = (char)result;
    *((char*)obj + 0x1c) = entry[0x1d];
}

#endif
