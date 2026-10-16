#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"


struct StreamHeader;
struct FindEntryByKindContainer020d3d90;
struct Foo0207df50;
struct Obj02054664;
struct Target02059f38;
struct Vec3_02059f38;
struct Obj02033874;
struct Bytes02033b88;
struct Entry021c1e6c {
#if defined(jpn)
    char name[0xb];
#else
    char name[0x10];
#endif
    unsigned char kind:3, special:1, flags:4;
    unsigned char effect;
#if defined(jpn)
    char pad_12[0x13];
#else
    char pad_12[0x12];
#endif
};
struct HandlerSlotArray020d3c84 { Entry021c1e6c entries[5]; int count; };
struct Status021c1e6c {
    char pad_0[0x56b]; unsigned char mode:4, flags:4;
    void SetMode(int value) { unsigned char narrowed = value; mode = narrowed; }
};
struct Combatant021c1e6c {
    GameObject object;
#if defined(jpn)
    char pad_13c[0x144 - 0x13c];
#else
    char pad_13c[0x150 - 0x13c];
#endif
    Status021c1e6c* status;
    char pad_154[0x1c4 - 0x154];
    Entry021c1e6c* record;
};
struct Global021c1e6c { char pad_0[0xf7d]; unsigned char selection; };
struct GamePosition021c1e6c {
#if defined(jpn)
    char pad_0[0x7c88];
#else
    char pad_0[0x7f5c];
#endif
    int height; Vector3i position;
};

struct Summon021c1e6c { char pad_0; unsigned char done; char pad_2[6]; short task; unsigned char state, kind; };
extern "C" unsigned short* func_02012fe4();
void ResetStruct020d3c08(char*);
void InitHandlerArrayAndRunScript020d3c84(HandlerSlotArray020d3c84*, StreamHeader*, int);
Entry021c1e6c* FindEntryByKind(FindEntryByKindContainer020d3d90*, int);
extern "C" void func_ov017_0218f064(GameResources*, int, int, int, int);
unsigned char FindUnusedSlot_02191764(int, int);
extern "C" void* func_0202ae18();
extern "C" int func_0202c508(void*);
void CopyInternalFields0207df50(Foo0207df50*);
extern "C" void func_02082828(void*);
void ResetSelectionState02054664(Obj02054664*);
void SetPointerFields02053c4c(char*, char*);
void RegisterCombatantSlot_0200fd38(GameState*, int, GameObject*);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState*, int);
void SetField0x2d0_020546a0(void*, int);
void SetField0x2d1_020546b4(void*, int);
void CopyVec3ToField0x44(Target02059f38*, Vec3_02059f38*);
void SetVecYFromValue02033874(Obj02033874*, int);
extern "C" void func_ov017_02191508(int, Entry021c1e6c*);
void CopyByteField0x253To0x252_02039830(void*);
extern "C" void func_ov017_02191108(GameResources*, int, int, int, int);
extern "C" void func_ov017_02191234(GameResources*);
extern "C" int func_0202c540(void*);
void CallHelperWithBuf_021907dc(int, int, int, int, int);
void RestorePairTables0207df90(char*);
void BackupPairTables0207dfac(char*);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
void ClearFlag0x1ceBit0x4_02039d58(unsigned char*);
int CheckFlag0x1ceBit2Set_02039d68(unsigned char*);
void SetFlag0x1ceBit0x4_02039d48(unsigned char*);
#if defined(jpn)
extern char data_ov017_021d87c4[], data_ov017_021d87d8[];
#else
extern char data_ov017_021d7f2c[], data_ov017_021d7f40[], data_ov017_021d7f50[];
#endif

static inline char* GetSummonPairTables(GameResources* resources) { return resources->unknown_11d4; }

// USA: func_ov017_021c1e6c
extern "C" ARM void func_ov017_021c1e6c(Summon021c1e6c* self) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    unsigned short* data = func_02012fe4();
    if (self->state == 0) {
#if defined(jpn)
        self->task = loader->QueueLoadFile(data_ov017_021d87c4, 0);
#else
        self->task = loader->QueueLoadFileInGP2(data_ov017_021d7f2c, data_ov017_021d7f40, 0);
#endif
        self->state = 1;
    } else if (self->state == 1) {
        if (!loader->GetTaskStatus(self->task)) return;
        Entry021c1e6c* entry = 0;
        if (loader->GetDetailedTaskStatus(self->task) == 2) {
            void* file;
            unsigned int length;
            loader->GetLoadedFileByID(self->task, &file, &length);
            if (file) {
                HandlerSlotArray020d3c84 handlers;
                ResetStruct020d3c08((char*)&handlers);
                InitHandlerArrayAndRunScript020d3c84(&handlers, (StreamHeader*)file, length);
                entry = FindEntryByKind((FindEntryByKindContainer020d3d90*)&handlers, self->kind);
            }
        }
        loader->RemoveTask(self->task);
        self->task = -1;
        if (!entry) { self->done = 1; return; }
        int combatantId;
        unsigned char slot;
        if (entry->special) {
            int kind = entry->kind;
            combatantId = 3;
            func_ov017_0218f064(resources, combatantId, 4, 1, kind);
            slot = FindUnusedSlot_02191764(combatantId, 0);
            self->done = 1;
        } else {
            if (func_0202c508(func_0202ae18())) ((Global021c1e6c*)GetPtrField0x2a04_02010828(game))->selection = self->kind;
            combatantId = 0xce;
            slot = 4;
            char* initialBank = GetSummonPairTables(resources);
            resources->allocator_11c0.Reset();
            CopyInternalFields0207df50((Foo0207df50*)initialBank);
            Entry021c1e6c* saved = (Entry021c1e6c*)resources->allocator_11c0.Allocate(sizeof(Entry021c1e6c));
            if (!saved) goto configureCombatant;
            memcpy(saved, entry, sizeof(Entry021c1e6c));
#if defined(jpn)
            void* stats = resources->allocator_11c0.Allocate(0x8cc);
#else
            void* stats = resources->allocator_11c0.Allocate(0x964);
#endif
            if (!stats) goto configureCombatant;
            func_02082828(stats);
#if defined(jpn)
            Combatant021c1e6c* combatant = (Combatant021c1e6c*)resources->allocator_11c0.Allocate(0x2c8);
#else
            Combatant021c1e6c* combatant = (Combatant021c1e6c*)resources->allocator_11c0.Allocate(0x2d4);
#endif
            if (!combatant) goto configureCombatant;
            ResetSelectionState02054664((Obj02054664*)combatant);
            SetPointerFields02053c4c((char*)combatant, (char*)stats);
            unsigned char kind = saved->kind;
            if (combatant->status) combatant->status->SetMode(kind);
            combatant->record = saved;
            RegisterCombatantSlot_0200fd38(game, 0xce, &combatant->object);
            char filename[0x50];
#if defined(jpn)
            sprintf(filename, data_ov017_021d87d8, entry->effect);
#else
            sprintf(filename, data_ov017_021d7f50, entry->effect);
#endif
            self->task = loader->QueueLoadFile(filename, &resources->allocator_11c0);
            self->state = 2;
        }
configureCombatant:
        GameObject* combatant = GetCombatantWithFlag0x1000_0200ff58(game, combatantId);
        if (combatant) {
            SetField0x2d0_020546a0(combatant, 0);
            SetField0x2d1_020546b4(combatant, slot);
            combatant->obj3D_.SetField06(*data);
            if (game->GetUnknownGameObject()) {
                CopyVec3ToField0x44((Target02059f38*)combatant, (Vec3_02059f38*)&((GamePosition021c1e6c*)game)->position);
                SetVecYFromValue02033874((Obj02033874*)combatant, ((GamePosition021c1e6c*)game)->height);
            }
            if (entry->special) func_ov017_02191508(combatantId, entry);
            GameObject* leader = game->GetUnknownGameObject();
            if (leader) CopyByteField0x253To0x252_02039830(leader);
            func_ov017_02191108(resources, 1, 1, 1, 1);
            func_ov017_02191234(resources);
            if (func_0202c540(func_0202ae18())) CallHelperWithBuf_021907dc((int)resources, 0, 1, 1, 1);
        } else self->done = 1;
    } else if (self->state == 2) {
        if (!loader->GetTaskStatus(self->task)) return;
        if (loader->GetDetailedTaskStatus(self->task) == 2) {
            void* file;
            unsigned int length;
            loader->GetLoadedFileByID(self->task, &file, &length);
            if (file) {
                ObjectArchiveLoadInfo info;
                info.allocator = &resources->allocator_11c0;
                info.unk_0 = 0;
                info.unk_10 = 0; info.unk_14 = 0; info.unk_18 = 0; info.packageID = 0;
                info.fileData = file;
                info.unk_8 = length;
                char* pairTables = GetSummonPairTables(resources);
                GameObject* combatant = GetCombatantWithFlag0x1000_0200ff58(game, 0xce);
                if (combatant) {
                    RestorePairTables0207df90(pairTables);
                    combatant->obj3D_.LoadFromCCHROrCMOTArchive(&info, 0);
                    BackupPairTables0207dfac(pairTables);
                    combatant->obj3D_.SetScale(0x10a, 0x10a, 0x10a);
                    SetField0x2d0_020546a0(combatant, 0);
                    SetByte0xbeShiftPrev((Bytes02033b88*)combatant, 0);
                    ClearFlag0x1ceBit0x4_02039d58((unsigned char*)combatant);
                    for (int i = 0; i < 4; i++) {
                        GameObject* member = GetCombatantWithFlag0x1000_0200ff58(game, i);
                        if (member && CheckFlag0x1ceBit2Set_02039d68((unsigned char*)member)) SetFlag0x1ceBit0x4_02039d48((unsigned char*)combatant);
                    }
                    GameObject* leader = game->GetGameObjectByIndex(0);
                    if (leader) {
                        CopyVec3ToField0x44((Target02059f38*)combatant, (Vec3_02059f38*)&((GamePosition021c1e6c*)game)->position);
                        SetVecYFromValue02033874((Obj02033874*)combatant, ((GamePosition021c1e6c*)game)->height);
                        combatant->obj3D_.SetField06(leader->obj3D_.GetField06());
                    }
                }
            }
        }
        loader->RemoveTask(self->task);
        self->task = -1;
        self->done = 1;
    }
}
