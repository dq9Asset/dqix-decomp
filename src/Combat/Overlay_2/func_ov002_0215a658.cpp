#include <globaldefs.h>
#include "GameState/GameState.h"

struct Element020dedd0 {
    int unk_0;
    int unk_4;
    unsigned int unk_8_0 : 20;
    unsigned int keep : 1;
    unsigned int unk_8_21 : 11;
};
struct Container020dedd0;
struct Slots02083994;
struct KeyMap020a095c;

struct Element020dedd0* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
void* GetPtrField0x2a04_02010828(GameState* battleStruct);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
int CountMatchingUntilNegative02083994(struct Slots02083994* s, int value);
int AddKeyValueClamped020a095c(struct KeyMap020a095c* map, int key, int amount);
extern "C" void func_ov017_021c9e00(int id, int flagA, int flagB, int flagC);
extern "C" void func_ov002_0215b2c8(char* self);

// USA: func_ov002_0215a658
extern "C" ARM void func_ov002_0215a658(char* self, int val) {
    int off;
    char* slots;
    GameState* battle = GameState::GetInstance();
    void* keymap = GetPtrField0x2a04_02010828(battle);
    for (int i = 0; i < *(int*)(self + 0x1c38); i++) {
        int id = *(int*)(self + i * 4 + 0x1c3c);
        if (val == id || val == 4) {
            GameObject* c = GetCombatantWithFlag0x100_0200ff1c(battle, id);
            if (c != NULL) {
                char* f = (char*)GetFieldAt0x150_02053c6c((unsigned char*)c);
                int j;
                unsigned char n = 0;
                for (j = 0; j < 8; j++) {
                    off = j * 2;
                    slots = f + 0x454;
                    if (*(short*)(slots + off) > 0) {
                        struct Element020dedd0* e = FindElementByKey020dedd0((struct Container020dedd0*)(self + 0x7ec), *(short*)(slots + off));
                        if (e->keep) {
                            short key = *(short*)(slots + off);
                            *(short*)(slots + off) = -1;
                            *(short*)(f + n++ * 2 + 0x454) = key;
                        } else {
                            if (*(short*)(slots + off) == 0x570a) {
                                if (CountMatchingUntilNegative02083994((struct Slots02083994*)f, 0x570a) == 1) {
                                    *(char*)(*(char**)((char*)c + 0x130) + 8) = 0;
                                    func_ov017_021c9e00(*(short*)((char*)c + 4), 0, 0, 1);
                                }
                            }
                            AddKeyValueClamped020a095c((struct KeyMap020a095c*)keymap, *(short*)(slots + off), 1);
                            *(short*)(slots + off) = -1;
                        }
                    }
                }
            }
        }
    }
    func_ov002_0215b2c8(self);
}
