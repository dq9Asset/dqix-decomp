#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_0200ff18(GameState* battleStruct);
extern "C" unsigned int func_0203af54(unsigned int* obj, unsigned int mask);
extern "C" void func_02016614(void* big);
extern "C" void func_ov000_0216278c(void* obj);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
struct Vec3i_020374f0 { int x; int y; int z; };
extern "C" struct Vec3i_020374f0 _ZNK8Object3D8GetScaleEv(unsigned char* src);
extern "C" void _ZN8Object3D8SetScaleEPK8Vector3i(unsigned char* dst, int* src);
extern "C" void _ZN8Object3D4DrawEb(void* obj, int flag);
extern "C" void _ZN12RenderConfig12SubmitToFifoEv(void);
extern "C" int func_020a3d20(void);
extern "C" void func_ov025_021e0174(void* arg);

// JPN: func_ov000_021622d0  (semantic: RefreshCombatantAndDispatch_021622d0)
extern "C" ARM void func_ov000_021622d0(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    unsigned int* v = ((unsigned int*)func_ov017_0218c1d0());
    func_0200ff18(battle);
    if (!(*(int*)(obj + 0x57e4) & 0x200)) {
        return;
    }
    if (func_0203af54(v, 0x100000) == 0) {
        func_02016614(obj + 0xe44);
    }
    func_ov000_0216278c(obj);
    if (func_0203af54(v, 4) == 0) {
        GameObject* c1 = battle->GetGameObjectByIndex(*(short*)(obj + 0x71c6));
        GameObject* c2 = battle->GetGameObjectByIndex(0xc8);
        if (c2 != 0) {
            if (c1 != 0) {
                _ZN8Vector3iaSERKS_((int*)((char*)c2 + 0x44), (int*)((char*)c1 + 0x44));
                _ZN8Vector3iaSERKS_((int*)((char*)c2 + 0x50), (int*)((char*)c1 + 0x50));
                const struct Vec3i_020374f0& tmp = _ZNK8Object3D8GetScaleEv((unsigned char*)c1);
                _ZN8Object3D8SetScaleEPK8Vector3i((unsigned char*)c2, (int*)&tmp);
            }
            _ZN8Object3D4DrawEb(c2, 0);
        }
    }
    _ZN12RenderConfig12SubmitToFifoEv();
    if (*(int*)(obj + 0xe24) != 8) {
        return;
    }
    if (func_020a3d20() != 4) {
        return;
    }
    func_ov025_021e0174(obj + 0x5ca0);
}

#endif
