#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

struct Element020de650;
struct Container020dedd0 {
    unsigned short count;
    unsigned char pad[10];
    struct Element020de650* base;
    unsigned char pad2[4];
    unsigned char useBinarySearch;
};
struct Field150Holder02052e2c;
struct Field150Holder02052df8;

struct ItemDef {
    int field0;
    unsigned int low : 27;
    unsigned int bit27 : 1;
    unsigned int bit28 : 1;
    unsigned int bit29 : 1;
    unsigned int high : 2;
};
struct EquipEntry {
    ItemDef *def;
    unsigned char unknown4[4];
    unsigned int category : 4;
    unsigned int unknownFlags : 28;
    unsigned char unknownc[0xc];
    short itemId;
    unsigned char unknown1a[6];
};
struct EquipView {
    unsigned char unknown0[0x194];
    EquipEntry entries[8];
    unsigned char unknown294[0x49c - 0x294];
    unsigned char flag49c : 1;
};
struct Combatant0217599c {
    #if defined(jpn)
    unsigned char unknown0[0x144];
#else
    unsigned char unknown0[0x150];
#endif
    EquipView *view;
};
struct EquipOrder {
    unsigned char v[8];
};
struct TextContext {
    SafeAllocator allocator;
    char list[0x18];
    Container020dedd0 *containerData;
    int field30;
    int field34;
};
struct Menu0217599c {
    char pad0[0x74];
    char container[4];
    char pad78[0x103a - 0x78 - 0x800];
};
struct MenuB {
#if defined(jpn)
    char padding0[0x7f0];
#else
    char padding0[0x874];
#endif
    Container020dedd0 entries;
    char paddingAfterEntries[0x103a - 0x874 - sizeof(Container020dedd0)];
    short selected;
    unsigned char count;
    char pad3d[6];
    signed char character;
};

extern "C" int *func_0202ae18();
int CheckField0NonZero_0202b7d8(int *);
short *GetField150Ptr0x488_02052e2c(Field150Holder02052e2c *);
EquipEntry *FindElementByKey020dedd0(Container020dedd0 *, int);
void *ZeroInitReturn020de824(void *);
void InitStruct0207cbe8(char *);
extern "C" void func_0207cc18(void *, EquipEntry *);
void InitStruct0207cc0c(char *);
extern "C" int func_020dd4c4(int, void *);
int GetHalfwordEntryFromField150(Field150Holder02052df8 *, int);
extern "C" void func_02052d7c(Combatant0217599c *, int, short);
void *GetFieldAt0x150_02053c6c(unsigned char *);
extern "C" void func_0208358c(void *, EquipEntry *, int);
extern "C" void func_0207c378(char *, int, int, int);
static inline int IsType0217599c(unsigned int type) {
    return type <= 7;
}
extern "C" void func_ov017_021c3fb4(int, int);
extern "C" void func_ov017_021c4418(int, int);
extern "C" GameResources *func_ov017_0218b5b0();
extern "C" void func_ov017_0218f5a4(GameResources *, int, int, int, int);

#if defined(jpn)
extern int data_ov003_0217e388[9];
extern EquipOrder data_ov003_0217e33c;
#else
extern int data_ov003_0217faf4[9];
extern EquipOrder data_ov003_0217faac;
#endif

// JPN: func_ov003_0217599c (021749d4)
// USA: func_ov003_0217599c
extern "C" ARM int func_ov003_0217599c(MenuB *menu) {
    GameState *gs        = GameState::GetInstance();
    int *search          = func_0202ae18();
    Combatant0217599c *c = (Combatant0217599c *) GetCombatantWithFlag0x100_0200ff1c(gs, menu->character);
    if (!c) return 0;
    if (!GetField150Ptr0x488_02052e2c((Field150Holder02052e2c *) c)) return 0;
    EquipEntry *elem =
        FindElementByKey020dedd0(&menu->entries, menu->selected);
    if (!elem) return 0;
    unsigned int category = elem->category;
    TextContext context;
    context.allocator.ResetAllocatorPointer();
    ZeroInitReturn020de824(context.list);
    InitStruct0207cbe8((char *) &context);
    InitStruct0207cbe8((char *) &context);
    context.containerData = &menu->entries;
    func_0207cc18(&context, elem);
    InitStruct0207cc0c((char *) &context);
    if (!IsType0217599c(category)) return 0;
    if (func_020dd4c4(menu->character, elem)) return 0;
#if defined(jpn)
    int slotId = data_ov003_0217e388[category];
#else
    int slotId = data_ov003_0217faf4[category];
#endif
    if (slotId < 0) return 1;
    char *bag      = (char *) GetPtrField0x2a04_02010828(gs);
    int equippedId = GetHalfwordEntryFromField150((Field150Holder02052df8 *) c, slotId);
    int same       = menu->selected == equippedId;
    if (!same) {
        func_02052d7c(c, slotId, menu->selected);
        func_0208358c(GetFieldAt0x150_02053c6c((unsigned char *) c), elem, -1);
    }
    if (FindElementByKey020dedd0(&menu->entries, equippedId)) {
        func_0207c378(bag + 0x1d4, equippedId, 1, category);
    }
    menu->count--;
    if (same) return 1;
    if (equippedId == 0x4680) {
#if defined(jpn)
        EquipOrder order = data_ov003_0217e33c;
#else
        EquipOrder order = data_ov003_0217faac;
#endif
        unsigned char flags[2];
        for (unsigned char i = 0; i < 8; i++) {
            if (order.v[i] == 0xff) break;
            EquipView *view   = c->view;
            EquipEntry *entry = &c->view->entries[order.v[i]];
            if (!entry || entry->itemId < 0) continue;
            ItemDef *def = entry->def;
            if (!def || def->bit29) continue;
            flags[0] = def->bit27 ? 1 : 0;
            flags[1] = def->bit28 ? 1 : 0;
            if (flags[view->flag49c]) continue;
#if defined(jpn)
            func_02052d7c(c, data_ov003_0217e388[i], -1);
#else
            func_02052d7c(c, data_ov003_0217faf4[i], -1);
#endif
            if (!entry) continue;
            func_0207c378(bag + 0x1d4, entry->itemId, 1, entry->category);
        }
    }
    if (CheckField0NonZero_0202b7d8(search)) {
        func_ov017_021c3fb4(menu->character, 1);
        func_ov017_021c4418(menu->character, -1);
    }
    GameResources *resources = func_ov017_0218b5b0();
    BackgroundLoader::GetInstance();
    func_ov017_0218f5a4(resources, menu->character, 1, 0, 0);
    return 1;
}
