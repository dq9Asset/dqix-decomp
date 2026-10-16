#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetPtrField0x2a04_02010828(GameState* battleStruct);
int GetGlobalField0x1c020421a0(void);

struct StoreStruct;
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
void SetByteAtIndex_020465d8(unsigned char* base, int index, unsigned char value);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);

#if defined(jpn)
extern "C" void func_020474a8(void* messages, unsigned char font, const char* format, char* output);
#else
extern "C" void func_02046608(int a, int b, void* c, void* d, int e, int f, int g);
#endif

struct Combatant021e8604 { char pad[0xf74]; int val; };

// USA: func_ov023_021e8604  (semantic: StoreAndDispatchEntry_021e8604)
// JPN: func_ov023_021e8574
extern "C" ARM void func_ov023_021e8604(void* obj) {
    GameState* battleStruct = GameState::GetInstance();
    struct Combatant021e8604* combatant = (struct Combatant021e8604*)GetPtrField0x2a04_02010828(battleStruct);
    int field = GetGlobalField0x1c020421a0();
    StoreInArray0x8b0_020465c0((struct StoreStruct*)field, 0, combatant->val);
    SetByteAtIndex_020465d8((unsigned char*)field, 0, 1);
    SetByteInRange_020465f0((unsigned char*)field, 0, 0xa);
    int key = GetFieldByKey020e0434((struct Container020e0310*)((char*)obj + 0x4c), 2);
#if defined(jpn)
    func_020474a8((void*)field, 0xa, (const char*)key, *(char**)((char*)obj + 0x5d8));
#else
    func_02046608(field, 0xa, (void*)key, *(void**)((char*)obj + 0x5d8), 0x100, 0, 0);
#endif
}
