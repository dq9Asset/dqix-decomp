#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int _ZNK8Object3D9GetRadiusEv(unsigned char* obj);
extern "C" int func_ov000_021692f0(unsigned char* obj, int id);

// JPN: func_ov000_02169364
extern "C" ARM int func_ov000_02169364(unsigned char* obj, int id) {
    GameState* battle = GameState::GetInstance();
    GameObject* combatant = battle->GetCombatantByIndex(id);
    if (!combatant) return -1;

    for (int i = 0; i < 8; i++) {
        int* p = (int*)((char*)*(void**)(obj + 0x218) + 0x8000 + 0xde0);
        int val = p[i] & 0xff;
        if (val == id) {
            p[i] = -1;
            break;
        }
    }

    int threshold = _ZNK8Object3D9GetRadiusEv((unsigned char*)combatant);
    for (int j = 0; j < 8; j++) {
        if (func_ov000_021692f0(obj, j) < threshold) continue;
        *(int*)((char*)*(void**)(obj + 0x218) + j * 4 + 0x8000 + 0xde0) = id;
        return j;
    }
    return -1;
}

#endif
