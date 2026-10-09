#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov003_02160db4(unsigned char* self, short* outHigh, short* outLow);
extern "C" void* func_02010684(GameState*);

extern "C" void func_ov003_02165c48(unsigned char* self);

// JPN: func_ov003_02165b84  (semantic: UpdateCursorState_02165b84)
extern "C" ARM void func_ov003_02165b84(unsigned char* self) {
    short outHigh, outLow;
    func_ov003_02160db4(self, &outHigh, &outLow);

    unsigned char byteF7C = *((unsigned char*)func_02010684(GameState::GetInstance()) + 0xf7c);
    outLow = outLow - (byteF7C - 1);

    unsigned char* base = (unsigned char*)func_02010684(GameState::GetInstance()) + 0x2000;
    int byteC8C = base[0xc8c];
    if (outLow != 0) {
        byteC8C += 1;
    }
    int limit = (byteC8C + 3) / 4;

    int flags = *(int*)(self + 0x284);
    if (flags & 0x10) {
        self[0x2c7] = (signed char)self[0x2c7] + 1;
    } else if (flags & 0x20) {
        self[0x2c7] = (signed char)self[0x2c7] - 1;
    }
    if (limit <= (signed char)self[0x2c7]) {
        self[0x2c7] = 0;
    } else if ((signed char)self[0x2c7] < 0) {
        self[0x2c7] = limit - 1;
    }

    func_ov003_02165c48(self);
}

#endif
