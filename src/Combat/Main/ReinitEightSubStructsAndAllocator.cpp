#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "Resource/MessageSystem.h"

struct Foo02048004;
extern void MaybeInvoke0204719c_02047230(struct Foo02048004* obj);
extern void InitEightSubStructs_0202f1a4(MessageSlotController* obj);
extern void TailForward02012da4(AllocatorUnion* alloc, void* data);

extern AllocatorUnion data_02114e20;

// USA: func_0202f1dc
ARM void ReinitEightSubStructsAndAllocator_0202f1dc(MessageSlotController* obj) {
    Foo02048004* p;
    int i;
    p = obj->slots;
    for (i = 0; i < 8; i++) {
        MaybeInvoke0204719c_02047230(p);
        p++;
    }

    if (obj->allocator != NULL) {
        SignedAllocatorHeader* header = obj->allocator->GetSignedAllocator();
        obj->allocator->Destroy();
        TailForward02012da4(&data_02114e20, header);
        TailForward02012da4(&data_02114e20, obj->allocator);
    }

    InitEightSubStructs_0202f1a4(obj);
}
