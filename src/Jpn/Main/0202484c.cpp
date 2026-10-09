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
    unsigned char unknown5a8[0x914 - 0x5a8];
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

// JPN: func_0202484c
extern "C" ARM void func_0202484c(void *receiver) {
    CombatActionReceiverView *obj = static_cast<CombatActionReceiverView *>(receiver);
    GameObject *actor             = GameState::GetInstance()->GetUnknownGameObject();
    void *resourceData            = func_0203b080();
    func_02012dac();
    Vector3i position = actor->obj3D_.position_;
    CombatActionPosition entries[17];
    unsigned char groups[32];
    memset(groups, 0, sizeof(groups));
    int count     = func_020230a4(entries, groups, &position);
    fix32_t scale = obj->scale;
    int originX   = (int) ((float) FIX32_MULTIPLY(position.x, scale) / 4096.0f);
    int originY   = (int) ((float) FIX32_MULTIPLY(position.z, scale) / 4096.0f);
    obj->originX  = originX;
    obj->originY  = originY;

    if (obj->resetPending) {
        obj->resetPending = 0;
        func_0203b170(resourceData, 1, 0, 0);
        for (int i = 0; i < obj->forwardingCount; i++) {
            Entry_02027878 *entry = func_020270e4(static_cast<List_02027878 *>(receiver), obj->forwardingEntries[i].index);
            if (entry) {
                func_0203b710(reinterpret_cast<Bcb8Params *>((char *) entry + 8), obj->forwardingEntries[i].parameter1,
                                    obj->forwardingEntries[i].parameter2);
            }
        }
    }
    func_02023df0(static_cast<BattleTimer0202441c *>(receiver));
    for (int i = 0; i < count; i++) {
        CombatActionPosition *entry = &entries[i];
        if (!func_02023d8c(receiver, entry->combatantId)) continue;
        fix32_t scale = obj->scale;
        int x         = (int) ((float) FIX32_MULTIPLY(entry->position.x, scale) / 4096.0f) - (obj->tileX << 3);
        int y         = (int) ((float) FIX32_MULTIPLY(entry->position.z, scale) / 4096.0f) - (obj->tileY << 3);
        if (entry->variant >= 0) {
            int group = groups[entry->group] - 1;
            x += data_020e7a04[group][entry->variant][0];
            y += data_020e7a08[group][entry->variant][0];
        }
        if (obj->flags & 1) {
            if (IsNonCombatantAction(entry->type)) continue;
        }
        if (!func_0202471c(reinterpret_cast<Actor02024d48 *>(entry), obj->actionState)) continue;
        func_02026ed0(receiver, (x - 4) << 12, (y - 4) << 12, entry->elementId, entry->type, 0, entry->palette,
                                 0xff, 0x1000, 0x1000);
    }
    func_02023524(receiver, obj->tileX << 3, obj->tileY << 3, -4, -4, 0);
    func_0202374c(receiver, entries, count, obj->tileX << 3, obj->tileY << 3, -4, -4, 0);
}

#endif
