#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" GameResources* func_ov017_0218c1d0(void);
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"


struct Struct0218d618;
extern "C" int func_ov017_0218e1f8(struct Struct0218d618* p);

extern "C" void* func_02012dac(void);
extern "C" int func_0200ff04(GameState* battleStruct);
extern "C" void* func_02012b50(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114ac0;

struct Struct02047230;
extern "C" void func_02048050(struct Struct02047230* obj);
extern "C" void func_02047fbc(struct Struct02047230* obj);

struct State0207dfc8;
extern "C" void func_0207ed48(struct State0207dfc8* src, struct State0207dfc8* dst);
extern "C" void func_0207ed10(char* obj);
extern "C" void func_0207ed2c(char* obj);
extern "C" void func_02048950(void* a, int b, int c, int d);

// JPN: func_ov017_021b6378
extern "C" ARM int func_ov017_021b6378(char* self) {
    if (*(unsigned char*)(self + 0x54) != 0) {
        if (!func_ov017_0218e1f8((struct Struct0218d618*)((char*)func_ov017_0218c1d0())))
            return 3;
    } else {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(*(int*)(self + 0x28)) != 0) {
            if (loader->GetDetailedTaskStatus(*(int*)(self + 0x28)) == BackgroundLoader::TaskStatus_Complete) {
                void* outPtr;
                unsigned int outSize;
                loader->GetLoadedFileByID(*(int*)(self + 0x28), &outPtr, &outSize);
                void* allocated = func_02012b50(&data_02114ac0, 0x100);
                if (outSize != 0 && allocated != 0) {
                    ((SafeAllocator*)(self + 0x40))->CreateTypeA(allocated, 0x100);
                    GameState* battle = GameState::GetInstance();
                    char* base = (char*)func_02012dac();
                    int idx = func_0200ff04(battle);
                    char* p = base + 0x620 + idx * 0x88;
                    *(int*)(self + 0x20) = (int)p;
                    func_02048050((struct Struct02047230*)*(int*)(self + 0x20));
                    func_02047fbc((struct Struct02047230*)*(int*)(self + 0x20));
                    unsigned char local[0x70];
                    short* mid = (short*)(((char*)func_ov017_0218c1d0()) + 0x27c);
                    func_0207ed48((struct State0207dfc8*)((char*)mid + 0x230), (struct State0207dfc8*)local);
                    func_0207ed10((char*)local);
                    func_02048950((void*)*(int*)(self + 0x20), (int)outPtr, (int)outSize, (int)(self + 0x40));
                    func_0207ed2c((char*)local);
                }
            }
            loader->RemoveTask(*(int*)(self + 0x28));
            *(int*)(self + 0x28) = -1;
        }
    }
    return (*(int*)(self + 0x28) < 0) ? 4 : 3;
}

#endif
