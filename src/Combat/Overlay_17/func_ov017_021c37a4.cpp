#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
#include "Combat/CombatantRecovery.h"

struct SearchState021c37a4 {
    char unk0[0x100d];
    unsigned char mode;
    char unk100e[0x1029 - 0x100e];
    unsigned char flags;
};

struct Slot021c37a4 {
    unsigned char data[6];
    signed char first;
    unsigned char a;
    unsigned char b;
    signed char last;
};

struct Battle021c37a4 {
#if defined(jpn)
    char unk0[0x5a6c];
#else
    char unk0[0x5ccc];
#endif
    unsigned int flags;
#if defined(jpn)
    char unk5a70[0x7280 - 0x5a70];
#else
    char unk5cd0[0x74c0 - 0x5cd0];
#endif
    Slot021c37a4 slots[3];
    char unk74de[0x7e74 - 0x74de];
    int value;
};

struct Party021c37a4 {
    char unk0[0xf78];
    unsigned char memberIds[4];
    unsigned char memberCount;
    char unkf7d[0x2c94 - 0xf7d];
    int value;
};

struct Swap021c37a4 {
    unsigned char from;
    unsigned char to;
};

// Entry-table context at zone+0x860 (JPN) / +0x840 (USA/EUR).
// ResetEntryTableAndContext020982b4 also clears this ushort at +0x1b64.
struct FieldEntryContext021c37a4 {
    char unk0[0x1b64];
    unsigned short value;
};

struct Field021c37a4 {
#if defined(jpn)
    char unk0[0x860];
#else
    char unk0[0x840];
#endif
    FieldEntryContext021c37a4 entries;
#if defined(jpn)
    char unk23c6[0x2860 - 0x23c6];
#else
    char unk23a6[0x2820 - 0x23a6];
#endif
    unsigned char flag;
    FieldEntryContext021c37a4* GetEntries() { return &entries; }
};

struct Actor021c37a4 {
    char unk0[0xc8];
    unsigned char flags;
};

struct Global021c37a4 {
#if defined(jpn)
    char unk0[0x1790];
#else
    char unk0[0x1962];
#endif
    unsigned char flag;
};

typedef char WorldSlotSizeCheck[sizeof(Slot021c37a4) == 10 ? 1 : -1];
typedef char WorldEntryValueCheck[offsetof(FieldEntryContext021c37a4, value) == 0x1b64 ? 1 : -1];
#if defined(jpn)
typedef char WorldBattleFlagsCheck[offsetof(Battle021c37a4, flags) == 0x5a6c ? 1 : -1];
typedef char WorldSlotsCheck[offsetof(Battle021c37a4, slots) == 0x7280 ? 1 : -1];
typedef char WorldBattleValueCheck[offsetof(Battle021c37a4, value) == 0x7c34 ? 1 : -1];
typedef char WorldEntryContextCheck[offsetof(Field021c37a4, entries) == 0x860 ? 1 : -1];
typedef char WorldFieldFlagCheck[offsetof(Field021c37a4, flag) == 0x2860 ? 1 : -1];
#else
typedef char WorldBattleFlagsCheck[offsetof(Battle021c37a4, flags) == 0x5ccc ? 1 : -1];
typedef char WorldSlotsCheck[offsetof(Battle021c37a4, slots) == 0x74c0 ? 1 : -1];
typedef char WorldBattleValueCheck[offsetof(Battle021c37a4, value) == 0x7e74 ? 1 : -1];
typedef char WorldEntryContextCheck[offsetof(Field021c37a4, entries) == 0x840 ? 1 : -1];
typedef char WorldFieldFlagCheck[offsetof(Field021c37a4, flag) == 0x2820 ? 1 : -1];
#endif

struct Obj02039d84;
struct PackedNibbleArray0206e2dc;
struct PackedNibbleArray0206e2a0;
struct Struct020d9ae8;
struct TailList020469b4;
struct TailNode020469b4;
struct SlotTable020e3004;
struct Bytes020e358c;
struct Entry020e3840;
struct Actor0209c678;
struct Actor0209c20c;
struct FlagWord020466f4;

extern "C" void* func_0202ae18(void);
void* GetData02100044_0202ae24(void);
void* GetData02153637_020e2ff8(void);
void* GetData02153634_020e3580(void);
void* GetData02153660_020e3808(void);
void* GetDataPtr02114e04_020d6c00(void);
extern "C" int func_0202c540(void* obj);
int GetFieldAt0x0_0202ba00(int* obj);
void UpdatePlayClocks020ac4f8(int arg);
extern "C" void __clear(void* buf, int len);
void Clear0x20BytesAt0x74de_02012084(unsigned char* obj);
void ClearFieldKeepBit0x10_02011af0(void* obj);
extern "C" void func_02046a8c(void* a, void* b);
void SetBitsInWord_0203b4a0(unsigned int* word, unsigned int bits);
void BlankFunction020d84e0(void);
extern "C" void func_0202b0f4(void* obj);
extern "C" void func_0205e22c(void* obj);
int GetField0x3acValue_020100a8(GameState* gs);
int GetByte0x26c_02039d7c(char* obj);
void ResetObjectState02039d84(Obj02039d84* obj);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* gs, int idx);
int GetSignedByte0x2d0_020546a8(void* obj);
extern "C" void func_ov017_02190264(void* obj, int idx);
extern "C" void func_ov017_021c32b0(Swap021c37a4* swap, int count);
extern "C" void func_0202c288(void* obj);
void SetField0x3acValue_020100a0(GameState* gs, int value);
extern "C" void func_020dcd40(void);
extern "C" void func_020dc7e8(int a, int b);
extern "C" void func_ov017_02191234(void* obj);
extern "C" void func_ov017_02191108(void* obj, int a, int b, int c, int d);
void SetField0x2d0_020546a0(void* obj, int value);
void SetByte0x1c8_02039858(unsigned char* obj, int value);
void ClearBytesAndZeroBlock02039d24(unsigned char* obj);
void* GetFieldIfFlag4_020100f8(char* obj);
void SetField0x21c_020a2770(void* obj, short value);
extern "C" void* func_0205ec34(void);
int GetPackedNibbleFlag0x8(PackedNibbleArray0206e2dc* arr, int idx);
extern "C" int func_020abd20(int unused);
void SetPackedNibbleFlag0x8(PackedNibbleArray0206e2a0* arr, int idx);
void Init020d9ae8(Struct020d9ae8* obj, int arg);
void CopyStringInto020d9dc4(char* dst, char* src);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void DecrementKeyEverywhere02086d88(unsigned char* obj, int key);
void ClearByteField17201_0218d500(void* obj);
void ClearAllTreasureMapUnknownBits_020116c8(void* obj);
extern "C" void func_ov017_02191aac(void* obj, int mode, int idx, unsigned char mask);
extern "C" void VectorizedMemset(void* dst, int value, int len);
char* GetGlobal02109030_020936f8(void);
void ResetEightRegionsAndFlags_02093a14(char* obj);
extern "C" Field021c37a4* func_02012fe4(void);
void ClearTwoBytesAtField_02195748(unsigned char* obj);
void ApplyVecFromField0x246_020a2718(char* obj);
void InitSlotTable020e3004(SlotTable020e3004* p);
void ClearThreeBytes020e358c(Bytes020e358c* p);
void ResetEntryArray020e3814(Entry020e3840* p);
int GetField0xcd0209c3ac(char* obj);
extern "C" void func_0209c2e0(void* obj, int a, int b);
void DispatchContextByState0209c678(Actor0209c678* obj, int state);
extern "C" void func_020bbd9c(void);
int IsHandleB8Active0209c6bc(void* obj);
void InitActorContext0209c20c(Actor0209c20c* obj);
void ClearFlags020466f4(FlagWord020466f4* obj, unsigned int flags);
int GetGlobalField0x1c020421a0(void);

extern Actor021c37a4 data_02109bf4;

// USA: func_ov017_021c37a4
extern "C" ARM void func_ov017_021c37a4(void) {
    GameState* gs = GameState::GetInstance();
    Battle021c37a4* battle = (Battle021c37a4*)gs;
    SearchState021c37a4* search = (SearchState021c37a4*)func_0202ae18();
    GameResources* res = func_ov017_0218b5b0();
    void* d100044 = GetData02100044_0202ae24();
    void* d153637 = GetData02153637_020e2ff8();
    void* d153634 = GetData02153634_020e3580();
    void* d153660 = GetData02153660_020e3808();
    void* d114e04 = GetDataPtr02114e04_020d6c00();
    int active = func_0202c540(search);
    int state = GetFieldAt0x0_0202ba00((int*)search);
    int mode = search->mode;
#if defined(jpn)
    char name[0xb];
#else
    char name[0x30];
#endif
    unsigned char bits[0x1a];
    Swap021c37a4 leader;
    Swap021c37a4 swap;

    if ((state == 5 && mode > 1) || state == 6) {
        UpdatePlayClocks020ac4f8(1);
    }

#if !defined(jpn)
    __clear(name, sizeof(name));
#endif
    if (active) {
        GameObject* first = gs->GetPartyMemberByIndex(0);
#if defined(jpn)
        memset(name, 0, sizeof(name));
#endif
        char* src = first->baseStats_->unk;
        memcpy(name, src, strlen(src));
        Clear0x20BytesAt0x74de_02012084((unsigned char*)gs);
        ClearFieldKeepBit0x10_02011af0(gs);
        func_02046a8c(res->unknown_ptr_array_36fc[0], res->unknown_ptr_array_3afc[0x14]);
    }

    SetBitsInWord_0203b4a0(&res->brightnessFlags_0, 2);
    BlankFunction020d84e0();
    func_0202b0f4(search);
    func_0205e22c(d100044);
#if !defined(jpn)
    search->flags &= ~0x10;
#endif

    for (int i = 0; i < 4; i++) {
        if (i == GetField0x3acValue_020100a8(gs)) {
            GameObject* member = gs->GetPartyMemberByIndex(i);
            if (active && member && GetByte0x26c_02039d7c((char*)member)) {
                ResetObjectState02039d84((Obj02039d84*)member);
            }
        } else {
            GameObject* combatant = GetCombatantWithFlag0x1000_0200ff58(gs, i);
            if (combatant && GetSignedByte0x2d0_020546a8(combatant) == GetField0x3acValue_020100a8(gs)) {
                continue;
            }
            func_ov017_02190264(res, i);
        }
    }

    leader.from = GetField0x3acValue_020100a8(gs);
    leader.to = 0;
    if (leader.from != leader.to) {
        func_ov017_021c32b0(&leader, 1);
    }

    for (int i = 3; i >= 0; i--) {
        GameObject* obj = gs->GetGameObjectByIndex(i);
        if (obj && (obj->obj3D_.unknown_0_ & 0x1000)) {
            int empty = -1;
            for (int j = 3; i < j; j--) {
                if (gs->GetGameObjectByIndex(j) == NULL) {
                    empty = j;
                    break;
                }
            }
            if (empty != -1) {
                swap.from = i;
                swap.to = empty;
                if (swap.from != swap.to) {
                    func_ov017_021c32b0(&swap, 1);
                }
            }
        }
    }

    func_0202c288(search);
    SetField0x3acValue_020100a0(gs, 0);
    if (active) {
        func_020dcd40();
        func_020dc7e8(6, -1);
        func_020dc7e8(7, -1);
        func_ov017_02191234(res);
        func_ov017_02191108(res, 1, 1, 1, 1);
    }

    for (int i = 0; i < 4; i++) {
        GameObject* combatant = GetCombatantWithFlag0x1000_0200ff58(gs, i);
        if (combatant) {
            SetField0x2d0_020546a0(combatant, GetField0x3acValue_020100a8(gs));
            SetByte0x1c8_02039858((unsigned char*)combatant, GetField0x3acValue_020100a8(gs));
            ClearBytesAndZeroBlock02039d24((unsigned char*)combatant);
        }
    }

    void* follower = GetFieldIfFlag4_020100f8((char*)gs);
    if (follower) {
        SetField0x21c_020a2770(follower, 0);
    }
    func_ov017_02191108(res, 1, 0, 1, 1);
    func_ov017_02191234(res);
    battle->flags |= 2;

    Party021c37a4* party = (Party021c37a4*)GetPtrField0x2a04_02010828(gs);
    if (active) {
        void* store = func_0205ec34();
        memset(bits, 0, 0x1a);
        unsigned char* p = bits;
        unsigned char bit = 0;
        for (int i = 0; i < 0xcc; i++) {
            if (GetPackedNibbleFlag0x8((PackedNibbleArray0206e2dc*)store, i)) {
                *p |= 1 << bit;
            }
            bit++;
            if (bit == 8) {
                p++;
                bit = 0;
            }
        }
        func_020abd20(0);
        party->value = battle->value;

        bit = 0;
        p = bits;
        bool changed = false;
        for (int i = 0; i < 0xcc; i++) {
            if (*p & (1 << bit)) {
                if (!GetPackedNibbleFlag0x8((PackedNibbleArray0206e2dc*)store, i)) {
                    changed = true;
                }
                SetPackedNibbleFlag0x8((PackedNibbleArray0206e2a0*)store, i);
            }
            bit++;
            if (bit == 8) {
                p++;
                bit = 0;
            }
        }
        if (changed) {
            void* list;
            void* node = res->unknown_ptr_array_3afc[0x31];
            list = res->unknown_ptr_array_36fc[0];
            Init020d9ae8((Struct020d9ae8*)node, 0);
            CopyStringInto020d9dc4((char*)node, name);
            AppendNodeToTail((TailList020469b4*)list, (TailNode020469b4*)node);
        }
    }

    DecrementKeyEverywhere02086d88((unsigned char*)party, 0x5612);
    ClearByteField17201_0218d500(res);
    if (active) {
        ClearAllTreasureMapUnknownBits_020116c8(gs);
    }

    CombatantRecovery* hero = (CombatantRecovery*)gs->GetPartyMemberByIndex(0);
    if (hero && (hero->combatFields_.savedState_130_->flags & 1)) {
        func_02048150(hero, 0, 1);
        hero->combatFields_.savedState_130_->hp = 1;
        hero->recoveryFlags &= ~1;
    }

    Party021c37a4* members = (Party021c37a4*)GetPtrField0x2a04_02010828(gs);
    for (int i = 0; i < members->memberCount; i++) {
        unsigned char id = members->memberIds[i];
        if (GetCombatantWithFlag0x100_0200ff1c(gs, id)) {
            func_ov017_02191aac(res, 0, id, 2);
        }
    }

    Slot021c37a4* slot = battle->slots;
    for (int i = 0; i < 3; i++, slot++) {
        VectorizedMemset(slot, 0, 6);
        slot->first = -1;
        slot->a = 0;
        slot->b = 0;
        slot->last = -1;
    }

    ResetEightRegionsAndFlags_02093a14(GetGlobal02109030_020936f8());
    Field021c37a4* field = func_02012fe4();
    FieldEntryContext021c37a4* entries = field->GetEntries();
    entries->value = 0;
    res->unknown_flag_42e2 = 0;
    ClearTwoBytesAtField_02195748((unsigned char*)res);
    ApplyVecFromField0x246_020a2718((char*)follower);
    InitSlotTable020e3004((SlotTable020e3004*)d153637);
    ClearThreeBytes020e358c((Bytes020e358c*)d153634);
    ResetEntryArray020e3814((Entry020e3840*)d153660);
    field->flag = 1;

    if (GetField0xcd0209c3ac((char*)&data_02109bf4) != 0x7f) {
        func_0209c2e0(&data_02109bf4, 0x7f, 0);
        DispatchContextByState0209c678((Actor0209c678*)&data_02109bf4, 0);
        func_020bbd9c();
    }
    data_02109bf4.flags &= ~4;
    if (!IsHandleB8Active0209c6bc(&data_02109bf4)) {
        InitActorContext0209c20c((Actor0209c20c*)&data_02109bf4);
    }
    ClearFlags020466f4((FlagWord020466f4*)d114e04, 0x800);
    ((Global021c37a4*)GetGlobalField0x1c020421a0())->flag = 0;
}
