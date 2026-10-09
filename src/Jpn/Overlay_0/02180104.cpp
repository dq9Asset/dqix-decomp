#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned char func_0201125c(char* obj, void* dst);
extern "C" void* func_ov000_02162a84(void* obj, int index);

struct SlotIdList02180104 {
    signed char ids[4];
};

extern SlotIdList02180104 data_ov000_021846fa;

// JPN: func_ov000_02180104
extern "C" ARM void func_ov000_02180104(void* obj, signed char* out, signed char* outCount) {
    SlotIdList02180104 list = data_ov000_021846fa;
    signed char buf[4];
    int n = (signed char)func_0201125c((char*)GameState::GetInstance(), buf);
    memcpy(&list, buf, n);
    *outCount = 0;
    for (int i = 0; i < n; i++) {
        if (func_ov000_02162a84(obj, list.ids[i]) != NULL) {
            out[*outCount] = list.ids[i];
            (*outCount)++;
        }
    }
}

#endif
