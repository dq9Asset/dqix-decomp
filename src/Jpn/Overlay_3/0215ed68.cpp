#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Container020e0310;
struct Entry_0205d6a0;

extern "C" char* func_02042940();
extern "C" void func_02043978(char* ctrl);
extern "C" int func_020e2070(struct Container020e0310* c, int key);
extern "C" void func_0205e9b4(struct Entry_0205d6a0* list, int flag);
extern "C" void* func_0202a9d0(void);
extern "C" int func_0202c094(void* obj);
extern "C" void func_ov003_0215ddcc(void* self, int msg);

struct BattleMenu_0215ed68 {
    char unk_0[0x64];
    char messages[0xb0 - 0x64];
    char entries[0x3d0 - 0xb0];
    unsigned char step;
    char unk_3b9[3];
    unsigned char mode;
    char unk_3bd[0x408 - 0x3d5];
    unsigned char showResult;
    unsigned char resultFlag;
    unsigned char unk_3f2;
    unsigned char skipMessage;
};

// JPN: func_ov003_0215ed68
extern "C" ARM void func_ov003_0215ed68(struct BattleMenu_0215ed68* self) {
    char* global;
    GameState* gs;
    void* ctx;
    unsigned char step;
    int zero;
    int nonZero;

    gs = GameState::GetInstance();
    global = func_02042940();
    ctx = func_0202a9d0();

    zero = 0;
    if (func_0202c094(ctx) && gs->GetUnknownGameObject()->obj3D_.unknown_4_ == 0) {
        zero = 1;
    }
    nonZero = 0;
    if (func_0202c094(ctx) && gs->GetUnknownGameObject()->obj3D_.unknown_4_ != 0) {
        nonZero = 1;
    }

    step = self->step;
    if (step == 0) {
        if (self->skipMessage) {
            func_02043978(global);
            self->step++;
            return;
        }
        int key = 0x442;
        if (self->showResult) {
            if (zero) {
                self->resultFlag = 1;
                key = 0x6e;
            } else if (nonZero) {
                key = 0x74;
            } else {
                key = 0x73;
            }
        }
        func_ov003_0215ddcc(self, func_020e2070((struct Container020e0310*)self->messages, key));
        self->step++;
    }
    if (step == 1 && *(int*)(global + 0x868) == 0) {
        func_0205e9b4((struct Entry_0205d6a0*)self->entries, 1);
        self->mode = 5;
        self->step = 0;
    }
}

#endif
