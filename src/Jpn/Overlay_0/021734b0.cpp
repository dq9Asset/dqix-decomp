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
    unsigned char unknownC7[0x430 - 0xc7];
    BattleEquipmentEntry* entries[16];
};
extern "C" {
    char* func_0200fd78(GameState*, unsigned int);
    void* func_02054fe4(void*);
    extern unsigned char data_ov000_02184420[8];
    void func_ov000_02173414(BattleEquipmentList*, int, BattleEquipmentEntry*);
}

// JPN: func_ov000_021734b0
// Appends the selected party member's equipment to the battle item list.
// Existing non-equipment entries remain first; the equipment section starts on a four-entry boundary.
extern "C" ARM void AppendBattleEquipmentEntries(BattleEquipmentList* list)
{
    signed char partyIndex = list->partyIndex;
    int validPartyIndex = partyIndex >= 0 && partyIndex <= 3;
    if (validPartyIndex) {
        char* partyMember = func_0200fd78(GameState::GetInstance(), partyIndex);
        if (partyMember && func_02054fe4(partyMember)) {
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
            unsigned int orderBytesRemaining = sizeof(equipmentOrder);
            unsigned char* orderDestination = equipmentOrder;
            const unsigned char* orderSource = data_ov000_02184420;
            do {
                unsigned char equipmentSlot = *orderSource;
                *orderDestination = equipmentSlot;
                ++orderSource;
                ++orderDestination;
            } while (--orderBytesRemaining);
            for (unsigned char slot = 0; slot < 8; ++slot) {
                BattleEquipmentView* equipment = *reinterpret_cast<BattleEquipmentView**>(partyMember + 0x144);
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
