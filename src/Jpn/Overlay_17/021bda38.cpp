#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

// JPN: func_ov017_021bda38
// Restores a marked party member's saved field position and facing.
// The restore flag is cleared and the companion mask at +0x171 is set before the actor is resolved.
extern "C" ARM void RestorePartyMemberFieldTransform(void* savedParty, int partyIndex) {
	unsigned char* savedPartyBytes = (unsigned char*)savedParty;
	unsigned char partyMask = 1 << partyIndex;
	int hasSavedTransform = 0;
	if (savedPartyBytes[0x170] & partyMask) hasSavedTransform = 1;
	savedPartyBytes[0x170] &= ~partyMask;
	savedPartyBytes[0x171] |= partyMask;
	if (!hasSavedTransform) return;
	GameObject* partyMember = GameState::GetInstance()->GetPartyMemberByIndex(partyIndex);
	if (!partyMember) return;
	_ZN8Vector3iaSERKS_((int*)((char*)partyMember + 0x44), (int*)(savedPartyBytes + 0x184 + partyIndex * 0xc));
	int savedYaw = *(int*)(savedPartyBytes + 0x1b4 + partyIndex * 4);
	*(int*)((char*)partyMember + 0x50) = 0;
	*(int*)((char*)partyMember + 0x54) = savedYaw;
	*(int*)((char*)partyMember + 0x58) = 0;
}

#endif
