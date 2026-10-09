#if defined(jpn)
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
extern "C" GameResources* func_ov017_0218c1d0(void);
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "std_library_functions.h"

extern "C" int func_0200ff54(char* obj);
extern "C" unsigned int func_0203af28(unsigned int* obj);
struct Obj020397cc;
extern "C" void func_02039224(struct Obj020397cc* obj, int arg1);
extern "C" void func_020a4618(unsigned char* obj, unsigned char mask);
extern "C" void func_020a4530(unsigned char* obj);
extern "C" int func_02047928(void** obj);
extern "C" void func_0203aef8(unsigned int* obj, unsigned int mask);
extern "C" void func_020a2a3c(unsigned int);
extern "C" void* func_02012b50(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_020cb6ac(void);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void* obj, int value, int frames);
struct ResetObj020d7a5c;
extern "C" struct ResetObj020d7a5c* func_020d9458();
struct Obj020d7aa0;
extern "C" void func_020d94a4(struct Obj020d7aa0* obj);

extern int data_02114ac0;
extern char data_ov017_021d8178;

struct Flags38_021b2388 {
    unsigned int lowBits : 4;
    unsigned int bit4 : 1;
    unsigned int rest : 27;
};

struct Obj021b2388 {
    char pad0[0x8];
    int field8;
    int fieldc;
    SafeAllocator allocator;   // 0x10
    char name[0x14];           // 0x24
    struct Flags38_021b2388 field38;  // 0x38
    char pad2[0x2];
    unsigned char field3e;     // 0x3e
    unsigned int field40;      // 0x40
    void* field44;             // 0x44
};

// JPN: func_ov017_021b2aa0
extern "C" ARM int func_ov017_021b2aa0(struct Obj021b2388* ctx) {
    GameState* battle = (GameState*)GameState::GetInstance();
    int base = ((int)func_ov017_0218c1d0());
    unsigned char* fieldPtr;
    GameObject* combatant = battle->GetUnknownGameObject();
    fieldPtr = (unsigned char*)func_0200ff54((char*)battle);
    int loadedList = (int)BackgroundLoader::GetInstance();
    void** entry = *(void***)((char*)base + 0x34f0);
    unsigned int val40 = func_0203af28((unsigned int*)base);
    ctx->field40 = val40;

    if (combatant) {
        func_02039224((struct Obj020397cc*)combatant, 1);
    }

    if (fieldPtr) {
        ctx->field3e = (fieldPtr[0x244] & 2) != 0;
        func_020a4618(fieldPtr, 2);
        func_020a4530(fieldPtr);
        ctx->field44 = fieldPtr;
    }

    if (!func_02047928(entry)) {
        return ctx->field8;
    }

    func_0203aef8((unsigned int*)base, 0x10);
    func_020a2a3c(0x2f800);
    void* buf = func_02012b50((AllocatorUnion*)&data_02114ac0, 0x2f800);
    if (!buf) {
        func_020cb6ac();
    }
    ctx->allocator.CreateTypeA(buf, 0x2f800);

    char tmp[0x50];
    sprintf(tmp, &data_ov017_021d8178, ctx->name);
    ctx->fieldc = ((BackgroundLoader*)(loadedList))->QueueLoadFile((const char*)((int)tmp), (SafeAllocator*)((int)&ctx->allocator));

    if (!ctx->field38.bit4) {
        _Z13SetBrightnessP13GameResourcesii((void*)base, -16, 30);
    }

    func_020d94a4((struct Obj020d7aa0*)func_020d9458());
    return 1;
}

#endif
