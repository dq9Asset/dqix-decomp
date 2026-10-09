#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct ListNode02160094 {
    char pad[0x30];
    struct ListNode02160094* next;
};

struct List02160094 {
    char pad0[8];
    unsigned char count;
    char pad1[7];
    struct ListNode02160094* head;
};
extern "C" struct ListNode02160094* func_ov000_02161814(struct List02160094* list, int index);


// JPN: func_ov000_02182c14
extern "C" ARM int func_ov000_02182c14(struct List02160094* list, int index, int* out, int flag) {
    GameState* battleStruct = GameState::GetInstance();
    struct ListNode02160094* node = func_ov000_02161814(list, index);
    if (node != NULL) {
        int computed = 0;
        if (flag == 0) {
            computed = *(unsigned short*)((char*)node + 0x20) * 0xc + 0x1c;
        } else if (flag == 1) {
            computed = *(unsigned short*)((char*)node + 0x20) * 0xc + 0x1d;
        }

        GameObject* combatant = battleStruct->GetGameObjectByIndex(computed);
        if (combatant != NULL) {
            if (*(short*)((char*)combatant + 0x2) > -1) {
                *out = computed;
                return 1;
            }
        }
    }
    return 0;
}

#endif
