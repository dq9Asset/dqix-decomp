#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" int func_020952d4(void);
extern "C" void func_02095748(void);
struct Struct02074bd0;
extern "C" void func_02075d5c(struct Struct02074bd0* obj);
extern "C" void func_0205e510(void* obj);
extern "C" void func_0205e5a4(void* obj);
extern "C" void func_0205e5ec(void* obj);
extern "C" void func_0205e378(void* obj);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" int func_02042940(void);
extern "C" void func_02043898(void* self);
extern "C" void func_02043978(char* obj);
extern "C" void* __clear(void* dst, int count);

// JPN: func_ov003_021681ac  (semantic: TeardownControllerAndDestroyAllocators_021681ac)
extern "C" ARM void func_ov003_021681ac(char* obj) {
    func_020952d4();
    func_02095748();

    int* reg = (int*)0x4000000;
    *reg = (*reg & ~0x1f00) | 0x100;
    *(short*)((char*)reg + 0x50) = 0;
    func_02075d5c((struct Struct02074bd0*)(obj + 0xc8));

    func_0205e510(obj + 0xe0);
    func_0205e5a4(obj + 0xe0);
    func_0205e5ec(obj + 0xe0);
    func_0205e378(obj + 0xe0);

    memset(*(void**)(obj + 0x7c), 0, 0x20);
    CleanInvalidateCacheRange(*(void**)(obj + 0x7c), 0x20);
    LoadToMainBG1CharacterData((int)*(void**)(obj + 0x7c), 0, 0x20);

    void* g = (void*)func_02042940();
    func_02043898(g);
    func_02043978((char*)g);
    *(int*)((char*)g + 0x228) = 0;
    *(int*)((char*)g + 0x22c) = 0;
    *(int*)((char*)g + 0x230) = 0;
    *(int*)(obj + 0x4e0) = 0;

    SafeAllocator* arr[6];
    __clear(arr, sizeof(arr));
    arr[0] = (SafeAllocator*)(obj + 0x50);
    arr[1] = (SafeAllocator*)(obj + 0x3c);
    arr[2] = (SafeAllocator*)(obj + 0x28);
    arr[3] = (SafeAllocator*)(obj + 0x14);
    arr[4] = (SafeAllocator*)obj;

    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i]->GetSignedAllocator() != NULL) {
            arr[i]->Destroy();
        }
    }
}

#endif
