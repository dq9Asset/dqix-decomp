#if defined(jpn)
#include <globaldefs.h>
#include "System/OverlayId.h"
#include "System/Graphics.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"

struct StateBits5ccc_11570;
struct StateBits5ccc_1155c;
struct FieldBlock63d6_115a8;
struct FieldBlock63d6_115b4;
struct FieldBlock63d6_115c0;
struct Obj020128d8;
struct Actor0209c174;
struct Obj_0205e88c;
struct Manager020db0f0;

extern "C" void* func_02010684(GameState* gs);
extern "C" void func_020c5364();
extern "C" void func_020129fc();
extern "C" void func_020a2984();
extern "C" void func_020a35b0();
extern "C" void func_020a36b8(unsigned int* id);
extern "C" int func_020a392c(unsigned int* id);
void PopulateOv33BackgroundLoader(void* buffer, unsigned int size, int count);
extern "C" void func_020dda3c();
extern "C" Manager020db0f0* func_020dc998();
extern "C" void func_020dc9dc();
extern "C" void func_020dcaf8(Manager020db0f0* mgr);
extern "C" void func_020dcc30(void* mgr);
extern "C" void func_0209deec(Actor0209c174* actor);
extern "C" void func_0209e008(void* actor);
extern "C" void func_0205fb78(Obj_0205e88c* obj);
extern "C" void func_0205fd0c(void* obj, int mode);
extern "C" void func_02042964(SafeAllocator* alloc);
extern "C" void func_020726f4();
extern "C" char* func_0209b9e0();
extern "C" void func_0200f9f0(char* gs, unsigned char value);
extern "C" char func_0200f9f8(char* gs);
extern "C" void func_02011d8c(void* gs, int value);
extern "C" int func_02011d98(void* gs);
extern "C" void func_020ae3dc();
extern "C" int func_020112e0(StateBits5ccc_11570* gs);
extern "C" void func_020112cc(StateBits5ccc_1155c* gs);
extern "C" void* func_02012b78(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_02012bac(AllocatorUnion* alloc);
extern "C" void func_02012b84(AllocatorUnion* alloc, void* data, int size);
extern "C" void func_02086f2c(char* p);
extern "C" void func_0209b9ec(char* table);
extern "C" int func_02011318(FieldBlock63d6_115a8* gs);
extern "C" void func_02011324(FieldBlock63d6_115b4* gs, unsigned char value);
extern "C" void func_02011330(FieldBlock63d6_115c0* gs);
extern "C" void func_020d86bc();
extern "C" void func_0205fbc0(void* obj);
extern "C" void func_0203a3a8(void* obj);
extern "C" void func_020126a0(Obj020128d8* obj);
void InitializeActiveAlarmList();
extern "C" void func_ov031_02212430(int index);
extern "C" void func_ov031_0222786c(int kind, int value);
extern "C" int func_020d86a4();
extern "C" void func_020cb308();
extern "C" void func_020cb3bc(int mode);
extern "C" void func_02012700(void* obj);
void SetInterruptHandler(unsigned int mask, const void* handler);
void EnableSpecificInterrupts(unsigned int mask);
void EnableIRQInterrupts();
extern "C" void func_020c5330(int enable);
extern "C" void MapVRAMBanksToMainBG(int banks);
extern "C" void func_020c53e8(int mode, int a, int b);
extern "C" void func_020cb2ec();

extern "C" void func_ov015_0218c1c0(void* scene);
extern "C" void func_ov019_0218c1c8(void* scene);
extern "C" void func_ov019_0218c1c4(void* scene);
extern "C" void func_ov015_0218c1c0(void* scene);
extern "C" void func_ov020_0218c320(void* scene);
extern "C" void func_ov020_0218c310(void* scene);
extern "C" void InitializeMovieViewer(void* scene);
extern "C" void func_ov016_0218c1e4(void* scene);
extern "C" void func_ov016_0218c1e0(void* scene);
extern "C" void func_ov015_0218c1c0(void* scene);
extern "C" void func_ov021_0218c21c(void* scene);
extern "C" void func_ov016_0218c1e4(void* scene);
extern "C" void func_ov015_02193df4(void* scene);
extern "C" void func_ov015_02194058(void* scene);
extern "C" void func_ov015_02193f1c(void* scene);

extern "C" void func_020129a0();

extern AllocatorUnion data_02114ac0;
extern char data_0211fb64[];
extern char data_021098ac[];
extern char data_021086a4[];
extern char data_02114b64[];
extern char data_02114af4[];

#define REG_IME (*(volatile unsigned short*)0x04000208)
#define REG_POWCNT1 (*(volatile unsigned short*)0x04000304)

#define RUNTITLE() \
    do { \
        func_020a36b8(&OVERLAY_19_ID); \
        void* scene = func_02012b78(&data_02114ac0, 0x2d0); \
        func_ov015_0218c1c0(scene); \
        func_02012bac(&data_02114ac0); \
        func_ov019_0218c1c8(scene); \
        func_ov019_0218c1c4(scene); \
        func_02012b84(&data_02114ac0, scene, 0x2d0); \
        func_020a392c(&OVERLAY_19_ID); \
    } while (0)

#define RUNOV20() \
    do { \
        func_020a36b8(&OVERLAY_20_ID); \
        void* scene = func_02012b78(&data_02114ac0, 0x494); \
        func_ov015_0218c1c0(scene); \
        func_02012bac(&data_02114ac0); \
        func_ov020_0218c320(scene); \
        func_ov020_0218c310(scene); \
        func_02012b84(&data_02114ac0, scene, 0x494); \
        func_020a392c(&OVERLAY_20_ID); \
    } while (0)

#define RUNOV16(again16) \
    do { \
        void* scene = func_02012b78(&data_02114ac0, 0x98); \
        InitializeMovieViewer(scene); \
        func_02012bac(&data_02114ac0); \
        func_ov016_0218c1e4(scene); \
        again16 = *(int*)((char*)scene + 0x94); \
        func_ov016_0218c1e0(scene); \
        func_02012b84(&data_02114ac0, scene, 0x98); \
    } while (0)

#define RUNOV21() \
    do { \
        func_020a36b8(&OVERLAY_21_ID); \
        void* scene = func_02012b78(&data_02114ac0, 0xbc); \
        func_ov015_0218c1c0(scene); \
        func_02012bac(&data_02114ac0); \
        func_ov021_0218c21c(scene); \
        func_ov016_0218c1e4(scene); \
        func_02012b84(&data_02114ac0, scene, 0xbc); \
        func_020a392c(&OVERLAY_21_ID); \
    } while (0)

#define RUNOV15() \
    do { \
        func_020a36b8(&OVERLAY_15_ID); \
        void* scene = func_02012b78(&data_02114ac0, 0x358); \
        func_ov015_02193df4(scene); \
        func_02012bac(&data_02114ac0); \
        func_ov015_02194058(scene); \
        func_ov015_02193f1c(scene); \
        func_02012b84(&data_02114ac0, scene, 0x358); \
        func_020a392c(&OVERLAY_15_ID); \
    } while (0)

extern "C" int func_ov030_021d9b60(void* callback);
// Existing JP linker symbols for executable overlay-29 integrity checks.
extern "C" int data_ov029_021d9d20_fake(void* callback);
extern "C" int data_ov029_021d9ee0_fake(void* callback);
extern "C" void func_020d8614();
extern "C" void func_020d863c();
extern "C" void func_020d8670();

inline void ResetWordUnlessTwo(GameState* gs) {
    func_0200f9f0((char*)gs, 6);
    if (func_02011d98(gs) != 2) {
        func_02011d8c(gs, 0);
    }
}

#define RUNOV17() \
    do { \
        func_020a36b8(&OVERLAY_17_ID); \
        func_020d86bc(); \
        func_020a392c(&OVERLAY_17_ID); \
    } while (0)

// KEEP-NAME: the JP entry routine is the C symbol main.
// JPN: func_02000c9c
extern "C" ARM void main() {
    GameState* gs = GameState::GetInstance();
    char* bigManager = (char*)func_02010684(gs);
    func_020c5364();
    DISPCNTSUB &= ~0x10000;
    func_020129fc();
    func_020a2984();
    func_020a35b0();
    func_020a36b8(&OVERLAY_29_ID);
    if (!func_ov030_021d9b60((void*)func_020d8614) &&
        !data_ov029_021d9d20_fake((void*)func_020d863c) &&
        !data_ov029_021d9ee0_fake((void*)func_020d8670) &&
        BackgroundLoader::GetInstance() == 0) {
        func_020a36b8(&OVERLAY_33_ID);
        PopulateOv33BackgroundLoader(data_0211fb64, 0x30000, 0x14);
    }
    func_020a392c(&OVERLAY_29_ID);
    func_020a36b8(&OVERLAY_32_ID);
    func_020dda3c();
    Manager020db0f0* ctx = func_020dc998();
    func_020dc9dc();
    func_020dcaf8(ctx);
    func_020dcc30(ctx);
    func_0209deec((Actor0209c174*)data_021098ac);
    func_0209e008(data_021098ac);
    func_0205fb78((Obj_0205e88c*)data_021086a4);
    func_0205fd0c(data_021086a4, 100);
    SafeAllocator allocator;
    allocator.ResetAllocatorPointer();
    allocator.CreateTypeA(data_02114b64, 0xb000);
    allocator.Reset();
    func_02042964(&allocator);
    func_020726f4();
    char* table = func_0209b9e0();
    if (*(int*)0x027ffc20 != 0) {
        func_0200f9f0((char*)gs, 6);
        func_02011d8c(gs, 0);
    }
    func_020ae3dc();

    for (;;) {
        if (func_020112e0((StateBits5ccc_11570*)gs)) {
            func_020112cc((StateBits5ccc_1155c*)gs);
            RUNTITLE();
        }
        if (func_02011d98(gs) != 5) {
            func_02086f2c(bigManager);
        }
        func_0209b9ec(table);

        bool resumed = false;
        if (func_02011d98(gs) != 5) {
            ResetWordUnlessTwo(gs);
            ResetWordUnlessTwo(gs);
            if (func_0200f9f8((char*)gs) != 6) {
                RUNOV20();
            } else if (func_0200f9f8((char*)gs) == 6) {
                RUNOV20();
                // JP member storage begins at 0x6d40; this flag is at 0x7c9e.
                if (*(unsigned char*)&gs->unk_6fc0[0x7c9e - 0x6d40] == 0) {
                    func_02011324((FieldBlock63d6_115b4*)gs, 1);
                    func_020a36b8(&OVERLAY_16_ID);
                    int again16 = 1;
                    while (again16) {
                        RUNOV16(again16);
                    }
                    func_020a392c(&OVERLAY_16_ID);
                    func_02011330((FieldBlock63d6_115c0*)gs);
                } else {
                    *(unsigned char*)&gs->unk_6fc0[0x7c9e - 0x6d40] = 0;
                }
            }
            resumed = true;
        }

        switch (func_0200f9f8((char*)gs)) {
        case 2:
            func_02011d8c(gs, 0);
            break;
        case 0:
            if (resumed != true) {
                func_02011d8c(gs, 0);
            }
            break;
        case 7:
            func_0200f9f0((char*)gs, 0);
            break;
        case 5:
            if (func_02011d98(gs) != 6) {
                func_02011d8c(gs, 0);
            }
            break;
        }

        bool again = true;
        while (again) {
            again = false;
            switch (func_0200f9f8((char*)gs)) {
            case 0:
            case 4:
            case 5:
            case 9:
                RUNOV17();
                if (func_02011318((FieldBlock63d6_115a8*)gs)) {
                    func_0200f9f0((char*)gs, 3);
                    again = true;
                }
                break;
            case 2:
                RUNOV21();
                if (((unsigned char*)gs)[0x6174] != 0) {
                    RUNOV17();
                    if (func_02011318((FieldBlock63d6_115a8*)gs)) {
                        func_0200f9f0((char*)gs, 3);
                        again = true;
                    }
                }
                break;
            case 1:
                RUNOV15();
                break;
            case 3:
                func_020a36b8(&OVERLAY_16_ID);
                int more = 1;
                while (more) {
                    RUNOV16(more);
                }
                func_020a392c(&OVERLAY_16_ID);
                if (func_02011318((FieldBlock63d6_115a8*)gs)) {
                    func_0200f9f0((char*)gs, 0);
                    again = true;
                }
                break;
            case 8:
                func_0205fbc0(data_021086a4);
                func_0203a3a8(data_021098ac);
                func_020126a0((Obj020128d8*)data_02114af4);
                func_020a36b8(&OVERLAY_27_ID);
                func_020a36b8(&OVERLAY_31_ID);
                REG_IME;
                REG_IME = 0;
                InitializeActiveAlarmList();
                func_ov031_02212430(2);
                func_ov031_0222786c(0, 0x10);
                func_020d86a4();
                func_020cb308();
                func_020cb3bc(1);
                func_020a36b8(&OVERLAY_32_ID);
                func_02012700(data_02114af4);
                func_0209deec((Actor0209c174*)data_021098ac);
                func_0209e008(data_021098ac);
                SetInterruptHandler(1, (const void*)func_020129a0);
                EnableSpecificInterrupts(1);
                func_020d86a4();
                EnableIRQInterrupts();
                func_020c5330(1);
                MapVRAMBanksToMainBG(0x60);
                func_020c53e8(1, 0, 0);
                DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
                BG0CNT = (BG0CNT & 0x43) | 4;
                BG0CNT &= ~3;
                BG0CNT &= ~0x40;
                REG_POWCNT1 &= ~0x8000;
                func_020cb2ec();
                func_0200f9f0((char*)gs, 6);
                func_02011d8c(gs, 1);
                again = false;
                break;
            }
        }
        if (func_020112e0((StateBits5ccc_11570*)gs)) {
            func_020112cc((StateBits5ccc_1155c*)gs);
            RUNTITLE();
        }
    }
}


#endif
