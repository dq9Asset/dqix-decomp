#if defined(jpn)
#include <globaldefs.h>
#include <GameState/GameState.h>

extern "C" void* func_02010684(GameState*);

// JPN: func_ov000_021801ac
// Filters the battle party selection and compacts removed entries.
// Mode 1 keeps members in the active party list; mode 2 removes the requested party index.
extern "C" ARM void FilterBattlePartySelection(signed char* selectedPartyIndices, signed char* selectionCount,
                                     int removedPartyIndex, int mode)
{
    unsigned char* partyState = static_cast<unsigned char*>(func_02010684(GameState::GetInstance()));
    signed char remainingCount = *selectionCount;
    switch (mode) {
    case 0:
        break;
    case 1:
        for (signed char slot = 0; slot < *selectionCount; ++slot) {
            signed char selectedPartyIndex = selectedPartyIndices[slot];
            int isInParty = 0;
            for (signed char partySlot = 0; partySlot < partyState[0xf7c]; ++partySlot) {
                if (selectedPartyIndex == (partyState + partySlot)[0xf78]) {
                    isInParty = true;
                    break;
                }
            }
            if (!isInParty) {
                --remainingCount;
                selectedPartyIndices[slot] = -1;
            }
        }
        break;
    case 2:
        int validPartyIndex = removedPartyIndex >= 0 && removedPartyIndex <= 3;
        if (validPartyIndex) {
            for (signed char slot = 0; slot < remainingCount; ++slot) {
                if (removedPartyIndex == selectedPartyIndices[slot]) {
                    --remainingCount;
                    selectedPartyIndices[slot] = -1;
                    break;
                }
            }
        }
        break;
    }
    for (signed char slot = 0; slot < *selectionCount - 1; ++slot) {
        if (selectedPartyIndices[slot] < 0) {
            for (signed char next = slot + 1; next < *selectionCount; ++next) {
                if (selectedPartyIndices[next] >= 0) {
                    selectedPartyIndices[slot] = selectedPartyIndices[next];
                    selectedPartyIndices[next] = -1;
                    break;
                }
            }
        }
    }
    *selectionCount = remainingCount;
}

#endif
