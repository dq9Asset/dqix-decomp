#include <globaldefs.h>
#include "Resource/PairTableEncoder.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Combat/CombatantRecovery.h"

struct S021a11b4;
struct LoadEntry021bdc34 {
    unsigned char padding_0[4];
    SafeAllocator primary;
    unsigned char padding_18[0xcc - 0x18];
    Foo0207df50 primary_pairs;
    unsigned char padding_13c[0x1ac - 0x13c];
    Foo0207df50 secondary_pairs;
    unsigned char padding_21c[0x52c - 0x21c];
    SafeAllocator secondary;
};
struct LoadGlobals021bdc34 {
#if defined(jpn)
    unsigned char padding_0[0x4114];
#else
    unsigned char padding_0[0x4334];
#endif
    Object3D* first;
    Object3D* second;
    Object3D* third;
    Object3D* fourth;
};
struct LoadState021bdc34 {
    unsigned char tag;
    unsigned char done;
    unsigned char padding_2[6];
    short tasks[4];
    unsigned char stage;
    unsigned char mode;
};
LoadEntry021bdc34* FindNegativeEntry_021a11b4(S021a11b4*);
void SetFieldndDispatch_021bdb78_021bdb78(int);
void CallHelperIfCheckPasses_0218fcf8(int, int, int);
extern "C" void func_ov017_0218f5a4(void*, int, int, int, int);
#if defined(jpn)
extern const char data_ov017_021d85ec[], data_ov017_021d8606[], data_ov017_021d861e[];
extern const char data_ov017_021d8639[], data_ov017_021d8644[], data_ov017_021d864d[], data_ov017_021d8653[];
#else
extern const char data_ov017_021d7e14[], data_ov017_021d7e2e[], data_ov017_021d7e46[];
extern const char data_ov017_021d7e61[], data_ov017_021d7e6c[], data_ov017_021d7e75[], data_ov017_021d7e7b[];
#endif

// USA: func_ov017_021bdc34
extern "C" ARM void func_ov017_021bdc34(LoadState021bdc34* self) {
    GameState* game = GameState::GetInstance();
    LoadGlobals021bdc34* globals = (LoadGlobals021bdc34*)func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    CombatantRecovery* actor = (CombatantRecovery*)GetCombatantWithFlag0x100_0200ff1c(game, 0);
    if (actor == 0) return;
    LoadEntry021bdc34* entry = FindNegativeEntry_021a11b4((S021a11b4*)globals);
    if (entry == 0) {
        self->done = 1;
        return;
    }
    SafeAllocator* allocators[4] = {&entry->primary, &entry->primary, &entry->secondary, &entry->primary};
    Foo0207df50* pairs[4] = {&entry->primary_pairs, &entry->primary_pairs, &entry->secondary_pairs, &entry->primary_pairs};
    if (self->stage == 0) {
        if (self->mode == 1 && globals->first != 0 && globals->second != 0) {
            if (actor->recoveryFlags & 0x40) { self->done = 1; return; }
        }
        if (self->mode == 2 && globals->first != 0 && globals->second != 0) {
            if (!(actor->recoveryFlags & 0x40)) { self->done = 1; return; }
        }
        if (self->mode == 0 && globals->first == 0 && globals->second == 0) {
            if (!(actor->recoveryFlags & 0x40)) { self->done = 1; return; }
        }
        if (self->mode == 1 || self->mode == 2) {
            if (globals->first == 0) {
#if defined(jpn)
                self->tasks[0] = loader->QueueLoadFile(data_ov017_021d85ec, 0);
                self->tasks[1] = loader->QueueLoadFile(data_ov017_021d8606, 0);
                self->tasks[2] = loader->QueueLoadFileInGP2(data_ov017_021d861e, data_ov017_021d8639, 0);
                self->tasks[3] = loader->QueueLoadFileInGP2(data_ov017_021d861e, data_ov017_021d8644, 0);
#else
                self->tasks[0] = loader->QueueLoadFile(data_ov017_021d7e14, 0);
                self->tasks[1] = loader->QueueLoadFile(data_ov017_021d7e2e, 0);
                self->tasks[2] = loader->QueueLoadFileInGP2(data_ov017_021d7e46, data_ov017_021d7e61, 0);
                self->tasks[3] = loader->QueueLoadFileInGP2(data_ov017_021d7e46, data_ov017_021d7e6c, 0);
#endif
                for (int i = 0; i < 4; i++) {
                    allocators[i]->Reset();
                    CopyInternalFields0207df50(pairs[i]);
                }
            } else {
                for (int i = 0; i < 4; i++) self->tasks[i] = -1;
            }
            if (self->mode == 1) actor->recoveryFlags |= 0x40;
            else actor->recoveryFlags &= ~0x40;
            func_ov017_0218f5a4(globals, 0, 1, 0, 0);
            self->stage = 1;
        } else {
            globals->first = 0;
            globals->second = 0;
            globals->third = 0;
            globals->fourth = 0;
            if (actor != 0) actor->recoveryFlags &= ~0x40;
            func_ov017_0218f5a4(globals, 0, 1, 0, 0);
            self->stage = 2;
        }
    } else if (self->stage == 1) {
        int pending = 0;
        for (int i = 0; i < 4; i++) {
            if (self->tasks[i] < 0) continue;
            if (loader->GetTaskStatus(self->tasks[i]) != 0 && loader->GetDetailedTaskStatus(self->tasks[i]) == 2) {
                void* file;
                unsigned int length;
                loader->GetLoadedFileByID(self->tasks[i], &file, &length);
                SafeAllocator* allocator = allocators[i];
                Object3D* object = (Object3D*)allocator->Allocate(0xac);
                if (file != 0 && object != 0) {
                    ObjectArchiveLoadInfo info;
                    info.fileData = file;
                    info.unk_0 = 0;
                    info.unk_14 = 0;
                    info.unk_18 = 0;
                    info.packageID = 0;
                    info.unk_10 = 1;
                    info.allocator = allocator;
                    info.unk_8 = length;
                    Foo0207df50* pair = pairs[i];
                    RestorePairTables0207df90(pair);
                    object->Initialize();
                    object->LoadFromCCHROrCMOTArchive(&info, 0);
                    BackupPairTables0207dfac(pair);
                    switch (i) {
                    case 0: globals->first = object; break;
                    case 1: globals->second = object; break;
                    case 2: globals->third = object; break;
                    case 3: globals->fourth = object; break;
                    }
                }
                loader->RemoveTask(self->tasks[i]);
                self->tasks[i] = -1;
            } else pending = 1;
        }
        if (!pending) self->stage = 2;
    } else if (self->stage == 2) {
        if (self->mode == 1) SetFieldndDispatch_021bdb78_021bdb78(0);
        else {
            actor->obj3D_.unknown_9c_ = 0;
            CallHelperIfCheckPasses_0218fcf8((int)globals, 0, 0);
        }
        if (globals->first != 0) {
#if defined(jpn)
            if (self->mode == 1) globals->first->MaybeSetRegularAnimation(data_ov017_021d864d, 0);
            else globals->first->MaybeSetRegularAnimation(data_ov017_021d8653, 0);
#else
            if (self->mode == 1) globals->first->MaybeSetRegularAnimation(data_ov017_021d7e75, 0);
            else globals->first->MaybeSetRegularAnimation(data_ov017_021d7e7b, 0);
#endif
        }
        self->done = 1;
    }
}
