#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameResources* func_ov017_0218c1d0(void);
#include "Memory/SafeAllocator.h"
#include "System/OverlayId.h"

#include "Resource/GameResources.h"

struct Obj_02243690;

extern "C" void func_020a36b8(unsigned int id);
extern "C" void func_ov031_02243cf8(void* state, int mode);
extern "C" void func_ov031_02243e70(Obj_02243690* obj);
extern "C" void func_0205fc18(void* obj);
extern "C" void func_0209dff0(void* obj);
extern "C" void func_0209e008(void* obj);
extern "C" void func_0205fd0c(void* obj, int mode);
extern char data_021086a4;
extern char data_021098ac;

struct State021b1e24 {
    char pad0[0x28];
    SafeAllocator* allocator;
    char pad1[0x30 - 0x2c];
    int done;
    char pad2[0x37c - 0x34];
    int f37c;
    int f380;
};

struct Task021b1e24 {
    char pad0;
    unsigned char failed;
    char pad1[8 - 2];
    SafeAllocator* heap;
    SafeAllocator allocator;
    unsigned char step;
    unsigned char mode;
    char pad2[0x24 - 0x22];
    State021b1e24* state;
    char pad3[0x32 - 0x28];
    unsigned char busy;
    char pad4;
    int f34;
    int f38;
};

static inline void SetPair(State021b1e24* state, int first, int second) {
    state->f37c = first;
    state->f380 = second;
}

// JPN: func_ov017_021b24ac
extern "C" ARM void func_ov017_021b24ac(Task021b1e24* task) {
    GameState::GetInstance();
    func_ov017_0218c1d0();
    if (task->step == 0) {
        if (task->heap == NULL || task->busy != 0) {
            task->failed = 1;
            return;
        }
        task->state = (State021b1e24*)task->heap->Allocate(0xa3c);
        if (task->state == NULL) {
            task->failed = 1;
            return;
        }
        unsigned int size = task->heap->GetMaxPossibleAllocation();
        task->allocator.CreateTypeA(task->heap->Allocate(size), size);
        task->allocator.Reset();
        func_0205fc18(&data_021086a4);
        func_0209dff0(&data_021098ac);
        func_020a36b8(OVERLAY_ID(31));
        func_ov031_02243cf8(task->state, task->mode);
        task->state->allocator = &task->allocator;
        SetPair(task->state, task->f34, task->f38);
        func_ov031_02243e70((Obj_02243690*)task->state);
        task->step++;
        return;
    }
    if (task->step != 1) {
        return;
    }
    func_ov031_02243e70((Obj_02243690*)task->state);
    if (task->state->done == 0) {
        return;
    }
    func_020a36b8(OVERLAY_ID(32));
    func_0209dff0(&data_021098ac);
    func_0209e008(&data_021098ac);
    func_0205fc18(&data_021086a4);
    func_0205fd0c(&data_021086a4, 100);
    SignedAllocatorHeader* block = task->allocator.GetSignedAllocator();
    if (block != NULL) {
        task->allocator.Destroy();
        task->heap->Free(block);
    }
    task->failed = 1;
}

#endif
