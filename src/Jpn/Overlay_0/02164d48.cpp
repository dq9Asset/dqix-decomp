#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct IntField0x68_020377bc;
extern "C" int _ZNK8Object3D9GetHeightEv(struct IntField0x68_020377bc* obj);
extern "C" int _ZNK8Object3D9GetRadiusEv(unsigned char* obj);

// JPN: func_ov000_02164d48
extern "C" ARM short func_ov000_02164d48(int id, int mode) {
    GameState* bs = GameState::GetInstance();
    if (bs == 0) {
        return 0x10a;
    }
    GameObject* c = bs->GetGameObjectByIndex(id);
    if (c == 0) {
        return 0x10a;
    }
    int result = 0x1000;
    int b = _ZNK8Object3D9GetHeightEv((struct IntField0x68_020377bc*)c);
    int a = _ZNK8Object3D9GetRadiusEv((unsigned char*)c);
    switch (mode) {
        case 0:
            if (b > a) {
                b = a;
            }
            result = b;
            break;
        case 1:
            if (b < a) {
                b = a;
            }
            result = b;
            break;
        case 2:
            result = (b + a) >> 1;
            break;
        case 3:
            result = a;
            break;
        case 4:
            result = b;
            break;
    }
    return (short)result;
}

#endif
