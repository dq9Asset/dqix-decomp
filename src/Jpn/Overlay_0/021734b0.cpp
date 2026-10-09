#if defined(jpn)
#include <globaldefs.h>
#include <GameState/GameState.h>

struct BattleEquipmentEntry {
    unsigned char unknown00[8];
    unsigned int category : 4;
    unsigned int unknownFlags : 28;
    unsigned char unknown0c[0xc];
    short count;
    unsigned char unknown1a[6];
};
struct BattleEquipmentView {
    unsigned char unknown00[0x194];
    BattleEquipmentEntry entries[8];
};
struct BattleEquipmentList {
    unsigned char unknown00[0x4c];
    int partyIndex;
    unsigned char unknown50[0xc6 - 0x50];
    signed char entryCount;
    unsigned char unknown87[0x430 - 0xc7];
    BattleEquipmentEntry* entries[16];
};
extern "C" {
    char* func_0200fd78(GameState*, unsigned int);
    void* func_02054fe4(void*);
    extern unsigned char data_ov000_02184420[8];
    void func_ov000_02173414(BattleEquipmentList*, int, BattleEquipmentEntry*);
}

// JPN: func_ov000_021734b0
extern "C" ARM void func_ov000_021734b0(BattleEquipmentList* list)
{
    signed char partyIndex = list->partyIndex;
    int valid = partyIndex >= 0 && partyIndex <= 3;
    if (valid) {
        char* actor = func_0200fd78(GameState::GetInstance(), partyIndex);
        if (actor && func_02054fe4(actor)) {
            list->entryCount = 0;
            for (signed char slot = 0; slot < 16; ++slot) {
                BattleEquipmentEntry* entry = list->entries[slot];
                if (!entry)
                    break;
                int equipmentCategory = entry->category <= 7;
                if (equipmentCategory)
                    break;
                ++list->entryCount;
            }
            unsigned char nextSlot = (list->entryCount + 3) & ~3;
            for (unsigned char slot = nextSlot; slot < 16; ++slot)
                list->entries[slot] = NULL;
            unsigned char equipmentOrder[8];
            unsigned int bytes = sizeof(equipmentOrder);
            unsigned char* output = equipmentOrder;
            const unsigned char* input = data_ov000_02184420;
            do {
                unsigned char value = *input;
                *output = value;
                ++input;
                ++output;
            } while (--bytes);
            for (unsigned char slot = 0; slot < 8; ++slot) {
                BattleEquipmentView* equipment = *reinterpret_cast<BattleEquipmentView**>(actor + 0x144);
                BattleEquipmentEntry* entry = &equipment->entries[equipmentOrder[slot]];
                if (entry && entry->count > 0) {
                    int equipmentCategory = entry->category <= 7;
                    if (equipmentCategory) {
                        func_ov000_02173414(list, nextSlot, entry);
                        ++nextSlot;
                    }
                }
            }
        }
    }
}

#endif
