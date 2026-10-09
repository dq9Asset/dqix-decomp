#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_02154f38(char* self, short id, void* rec);
extern "C" void* func_0207a6d0(void);
extern "C" int func_ov000_02155b74(GameObject* combatant);
extern "C" void* func_0207ac64(char* p, int key);

// JPN: func_ov000_02160890
extern "C" ARM void func_ov000_02160890(char* self) {
    char* selfP = self;
    void* data = func_0207a6d0();
    int i = 0;
    while (i < *(int*)(selfP + 0x8000 + 0xe7c)) {
        char* rec = (char*)(*(int**)(selfP + 0x8000 + 0xe78)) + i * 0x28;
        short id = *(short*)((char*)(*(void**)(rec + 0x10)) + 0x20);
        GameState* bs = GameState::GetInstance();
        GameObject* c = bs->GetCombatantByIndex(id);
        if (c == NULL) {
            return;
        }
        if (!func_ov000_02155b74(c)) {
            short key = *(short*)rec;
            void* res = func_0207ac64((char*)data, key);
            if (res != NULL) {
                unsigned int v = *(unsigned int*)((char*)res + 8);
                if (((v << 3) >> 31) != 0) {
                    short sh = *(short*)((char*)(*(void**)(rec + 0x10)) + 0x20);
                    func_ov000_02154f38(selfP, sh, rec);
                }
            }
        }
        i++;
    }
}

#endif
