#if defined(jpn)
#include <globaldefs.h>

#include "Combat/ActionDisplay.h"
extern int data_020e7a04[][4][2];
extern int data_020e7a08[][4][2];
extern "C" int func_020230a4(CombatActionPosition*, unsigned char*, Vector3i*);
extern "C" void func_02023524(void*, int, int, int, int, unsigned char);
extern "C" void func_0202374c(void*, CombatActionPosition*, int, int, int, int, int, int);
#include "GameState/GameState.h"
#include "System/Memory.h"
#include "std_library_functions.h"

struct ForwardingEntry {
    int unknown0;
    int index;
    int parameter1;
    int parameter2;
};

struct CombatActionReceiverView {
    unsigned char unknown0[0x18];
    int tileX;
    int tileY;
    unsigned char unknown20[0xc];
    ForwardingEntry *forwardingEntries;
    int forwardingCount;
    unsigned char unknown34[4];
    fix32_t scale;
    unsigned char unknown3c[8];
    int originX;
    int originY;
    unsigned char unknown4c[0x510];
    unsigned char resetPending;
    unsigned char unknown55d[0x47];
    int flags;
    unsigned char unknown5a8[0x418];
    unsigned char actionState;
};

struct List_02027878;
struct Entry_02027878;
struct Bcb8Params;
struct BattleTimer0202441c;
struct Actor02024d48;

extern "C" void *func_0203b080();
extern "C" void *func_02012dac();
extern "C" void func_0203b170(void *owner, int mode, int index, int value);
extern "C" Entry_02027878 *func_020270e4(List_02027878 *list, int index);
extern "C" void func_0203b710(Bcb8Params *params, int a, int b);
extern "C" void func_02023df0(BattleTimer0202441c *receiver);
extern "C" int func_02023d8c(void *receiver, int combatantId);
extern "C" int func_0202471c(Actor02024d48 *entry, int state);
extern "C" void func_02026ed0(void *receiver, int x, int y, int index, unsigned char type, unsigned char flags,
                              unsigned short palette, unsigned char opacity, int scaleX, int scaleY);

struct ForwardingRecordView {
    int unknown0;
    int entryIndex;
    int x;
    int z;
};

struct CombatProjectionReceiverView {
    unsigned char unknown0[0x18];
    int xOrigin;
    int forwardingOrigin;
    unsigned char unknown20[0xc];
    ForwardingRecordView *forwarding;
    int forwardingCount;
    unsigned char unknown34[4];
    fix32_t scale;
    int tileX;
    int tileZ;
    int screenX;
    int screenZ;
    unsigned char unknown4c[0x74 - 0x4c];
    int forwardingFill;
    unsigned char unknown78[0x55c - 0x78];
    unsigned char forwardingPending;
    unsigned char unknown55d[0x5a4 - 0x55d];
    int flags5a4;
    unsigned char unknown5a8[0x914 - 0x5a8];
    unsigned char actionFlag;
};


// JPN: func_02024b90
extern "C" ARM void func_02024b90(void *receiver) {
    CombatProjectionReceiverView *state = static_cast<CombatProjectionReceiverView *>(receiver);
    GameObject *object                  = GameState::GetInstance()->GetUnknownGameObject();
    void *displayState                  = func_0203b080();
    func_02012dac();
    Vector3fix position = object->obj3D_.position_;
    CombatActionPosition records[17];
    unsigned char groupCounts[32];
    memset(groupCounts, 0, sizeof(groupCounts));
    int count = func_020230a4(records, groupCounts, &position);

    fix32_t scale  = state->scale;
    int screenX    = (int) ((float) FIX32_MULTIPLY(position.x, scale) / 4096.0f);
    int screenZ    = (int) ((float) FIX32_MULTIPLY(position.z, scale) / 4096.0f);
    state->screenX = screenX;
    int tileX      = screenX < 0 ? screenX / 8 - 1 : screenX / 8;
    state->screenZ = screenZ;
    int tileZ      = screenZ < 0 ? screenZ / 8 - 1 : screenZ / 8;
    if (state->tileZ != tileZ) state->forwardingPending = 1;
    state->tileX = tileX;
    state->tileZ = tileZ;

    if (state->forwardingPending) {
        state->forwardingPending = 0;
        func_0203b170(displayState, 1, 0, state->forwardingFill);
        for (int i = 0; i < state->forwardingCount; i++) {
            Entry_02027878 *entry =
                func_020270e4(reinterpret_cast<List_02027878 *>(receiver), state->forwarding[i].entryIndex);
            if (entry) {
                func_0203b710(reinterpret_cast<Bcb8Params *>(reinterpret_cast<unsigned char *>(entry) + 8),
                                    state->forwarding[i].x, state->forwardingOrigin + state->forwarding[i].z - tileZ + 16);
            }
        }
    }
    func_02023df0(reinterpret_cast<BattleTimer0202441c *>(receiver));
    for (int i = 0; i < count; i++) {
        CombatActionPosition *record = &records[i];
        if (!func_02023d8c(receiver, record->combatantId)) continue;
        fix32_t recordScale = state->scale;
        int x               = (int) ((float) FIX32_MULTIPLY(record->position.x, recordScale) / 4096.0f) - state->xOrigin * 8;
        int z               = (int) ((float) FIX32_MULTIPLY(record->position.z, recordScale) / 4096.0f) - state->screenZ;
        if (record->variant >= 0) {
            int group = groupCounts[record->group] - 1;
            x += data_020e7a04[group][record->variant][0];
            z += data_020e7a08[group][record->variant][0];
        }
        if (state->flags5a4 & 1) {
            if (IsNonCombatantAction(record->type)) continue;
        }
        if (!func_0202471c(reinterpret_cast<Actor02024d48 *>(record), state->actionFlag)) continue;
        func_02026ed0(receiver, (x - 4) * 0x1000, (z + 0x5c) * 0x1000, record->elementId, record->type, 0,
                                 record->palette, 0xff, 0x1000, 0x1000);
    }
    func_02023524(receiver, state->xOrigin * 8, state->screenZ, -4, 0x5c, 0);
    func_0202374c(receiver, records, count, state->xOrigin * 8, state->screenZ, -4, 0x5c, 0);
}


#endif
