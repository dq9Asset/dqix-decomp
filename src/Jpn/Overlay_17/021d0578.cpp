#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02010684(GameState* gameState);
extern "C" GameObject* func_0200fd78(GameState* gameState, int characterId);
extern "C" int func_02054fe4(unsigned char* obj);

struct CharacterHeldItemUpdate {
    int characterId;
    unsigned char firstSlot;
    unsigned char itemCount;
    short itemIds[6];
};

// JPN: func_ov017_021d0578
// Applies a range of held-item IDs to a character outside the active party-ID list.
// The packet supplies the starting slot and count; the broader synchronization protocol is not established.
extern "C" ARM void ApplyCharacterHeldItemUpdate(int unused0, char* commandBytes, GameState* gameState) {
    struct CharacterHeldItemUpdate* update = (struct CharacterHeldItemUpdate*)(commandBytes + 4);
    int characterId = update->characterId;
    unsigned char* partyState = (unsigned char*)func_02010684(gameState);
    int partySlot;
    for (partySlot = 0; partySlot < partyState[0xf7c]; partySlot++) {
        unsigned char* partyEntry = partyState + partySlot;
        if (characterId == partyEntry[0xf78]) return;
    }

    GameObject* character = func_0200fd78(gameState, characterId);
    if (!character) return;
    int characterRecord = func_02054fe4((unsigned char*)character);
    if (!characterRecord) return;

    char* heldItemIds = (char*)characterRecord + 0x454;
    unsigned char firstSlot = update->firstSlot;
    unsigned char itemCount = update->itemCount;
    for (int itemIndex = 0; itemIndex < itemCount; itemIndex++) {
        *(short*)(heldItemIds + (firstSlot + itemIndex) * 2) = update->itemIds[itemIndex];
    }
}

#endif
