#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "System/OverlayId.h"

struct AllocatorUnion;
struct Obj020979c0;

extern "C" void func_020a2a3c(unsigned int size);
extern "C" void func_020a2984(void);
extern "C" void* func_02012b50(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_02099610(Obj020979c0* obj, unsigned char flag);
extern "C" void func_020a36b8(unsigned int id);
extern "C" void func_020a3c68(int value);
extern "C" void func_020a3cc4(int value);
extern "C" void func_ov014_02187a04(void* obj);
extern "C" void func_ov014_0218784c(void* obj, SafeAllocator* allocator);
extern "C" int func_ov014_02187b5c(void* obj, unsigned int tick);
extern "C" void func_ov014_02187ac4(void* obj);
extern "C" int func_02099654(void* obj);
extern "C" void func_02099784(void* obj);
extern char data_02114ac0;

struct Task021c03a4 {
    char pad0;
    unsigned char failed;
    char pad1[8 - 2];
    SafeAllocator allocator;
    void* f1c;
    void* f20;
    unsigned char step;
};

extern "C" void func_ov017_021c090c(Task021c03a4* task);

// JPN: func_ov017_021c094c
extern "C" ARM void func_ov017_021c094c(Task021c03a4* task) {
    if (task->step == 0) {
        *(unsigned short*)0x4000304 |= 0x8000;
        func_020a2a3c(0x3f000);
        void* buffer = func_02012b50((AllocatorUnion*)&data_02114ac0, 0x3f000);
        if (buffer == NULL) {
            func_020a2984();
            task->failed = 1;
            return;
        }
        task->allocator.CreateTypeA(buffer, 0x3f000);
        task->allocator.Reset();
        task->f1c = task->allocator.Allocate(0x20);
        task->f20 = task->allocator.Allocate(0x194);
        if (task->f1c == NULL || task->f20 == NULL) {
            func_020a2984();
            task->failed = 1;
            return;
        }
        func_02099610((Obj020979c0*)task->f1c, 1);
        func_020a36b8(OVERLAY_ID(14));
        func_020a3c68(1);
        func_ov014_02187a04(task->f20);
        func_ov014_0218784c(task->f20, &task->allocator);
        task->step++;
        return;
    }
    if (task->step == 1) {
        if (func_02099654(task->f1c)) {
            task->step++;
        }
        return;
    }
    if (task->step == 2) {
        if (func_ov014_02187b5c(task->f20, GameState::GetInstance()->GetTickCount())) {
            task->step++;
        }
        return;
    }
    if (task->step != 3) {
        return;
    }
    func_ov014_02187ac4(task->f20);
    func_02099784(task->f1c);
    func_ov017_021c090c(task);
    func_020a2984();
    func_020a3cc4(1);
    task->failed = 1;
}

#endif
