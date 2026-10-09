#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
extern "C" GameResources* func_ov017_0218c1d0(void);
#include "System/OverlayId.h"

struct AllocatorUnion;
struct Obj020397cc;
struct Obj020d7aa0;
struct SearchStruct;
struct Layout02189284;
struct Manager0218936c;

extern "C" SearchStruct* func_0202a9d0(void);
extern "C" void func_02039224(Obj020397cc* obj, int flag);
extern "C" void func_0203af30(unsigned int* field, unsigned int bits);
extern "C" void func_0203af40(unsigned int* field, unsigned int bits);
extern "C" void func_020a2a3c(unsigned int size);
extern "C" void func_020a2984(void);
extern "C" void* func_02012b50(AllocatorUnion* alloc, unsigned int size);
extern "C" Obj020d7aa0* func_020d9458();
extern "C" void func_020d94a4(Obj020d7aa0* obj);
extern "C" void func_020a3c68(int value);
extern "C" void func_020a3cc4(int value);
extern "C" void func_020a36b8(unsigned int id);
extern "C" void func_ov008_02189c84(void* scene, int index, int arg);
extern "C" void func_ov008_02189f8c(Layout02189284* layout, SafeAllocator* allocator);
extern "C" unsigned char func_ov008_0218a074(Manager0218936c* manager);
extern "C" int func_0202c104(SearchStruct* search, int index);
extern "C" void func_ov008_0218be84(void* scene);
extern "C" void func_ov008_0218a1c0(void* scene);
extern "C" void func_02039218(void* obj);
extern char data_02114ac0;

struct Scene021a9768 {
    char pad[0x14];
    int planes;
};

struct Task021a9768 {
    char pad0;
    unsigned char failed;
    char pad1[8 - 2];
    unsigned char step;
    char pad2[0xc - 9];
    SafeAllocator allocator;
    Scene021a9768* scene;
    signed char index;
    char pad3[0x54 - 0x25];
    int f54;
};

extern "C" void func_ov017_021a9ee8(Task021a9768* task);

// JPN: func_ov017_021a9f3c
extern "C" ARM void func_ov017_021a9f3c(Task021a9768* task) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218c1d0();
    GameObject* unknown = gs->GetUnknownGameObject();
    SearchStruct* search = func_0202a9d0();
    func_02039224((Obj020397cc*)unknown, 1);
    func_0203af30((unsigned int*)res, 0xc0);
    if (task->step == 0) {
        func_020a2a3c(0x1c704);
        void* buffer = func_02012b50((AllocatorUnion*)&data_02114ac0, 0x1c704);
        if (buffer == NULL) {
            func_020a2984();
            task->failed = 1;
            return;
        }
        func_020d94a4(func_020d9458());
        task->allocator.CreateTypeA(buffer, 0x1c704);
        task->allocator.Reset();
        func_020a3c68(1);
        func_020a36b8(OVERLAY_ID(8));
        task->scene = (Scene021a9768*)task->allocator.Allocate(0xec4);
        if (task->f54 == 0) {
            func_ov008_02189c84(task->scene, task->index, 0);
        } else {
            func_ov008_02189c84(task->scene, -1, task->f54);
        }
        func_ov008_02189f8c((Layout02189284*)task->scene, &task->allocator);
        task->step++;
        return;
    }
    if (task->step == 1) {
        if (((unsigned char (*)(Scene021a9768*, unsigned int))func_ov008_0218a074)(task->scene, gs->GetTickCount())) {
            task->step++;
        }
        if (func_0202c104(search, 0)) {
            func_ov008_0218be84(task->scene);
        }
        int valid = 0;
        if (task->index >= 0 && task->index <= 3) {
            valid = 1;
        }
        if (!valid) {
            return;
        }
        if (gs->GetGameObjectByIndex(task->index) != NULL && !func_0202c104(search, task->index)) {
            return;
        }
        func_ov008_0218be84(task->scene);
        return;
    }
    if (task->step == 2) {
        func_ov008_0218a1c0(task->scene);
        task->step++;
        return;
    }
    if (task->step != 3) {
        return;
    }
    func_02039218(GameState::GetInstance()->GetUnknownGameObject());
    *(volatile unsigned int*)0x4000000 = (task->scene->planes << 8) | (*(volatile unsigned int*)0x4000000 & ~0x1f00);
    task->scene = NULL;
    func_020a3cc4(1);
    func_ov017_021a9ee8(task);
    func_020a2984();
    func_0203af40((unsigned int*)res, 0x80);
    task->failed = 1;
}

#endif
