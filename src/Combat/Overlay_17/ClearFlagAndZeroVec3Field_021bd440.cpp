#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

// USA: func_ov017_021bd440
// JPN: func_ov017_021bda38
ARM void ClearFlagAndZeroVec3Field_021bd440(void* self, int index) {
	unsigned char* base = (unsigned char*)self;
	unsigned char mask = 1 << index;
	int wasSet = 0;
#if defined(jpn)
	if (base[0x170] & mask) wasSet = 1;
	base[0x170] &= ~mask;
	base[0x171] |= mask;
#else
	if (base[0x174] & mask) wasSet = 1;
	base[0x174] &= ~mask;
	base[0x175] |= mask;
#endif
	if (!wasSet) return;
	GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(index);
	if (!combatant) return;
#if defined(jpn)
	_ZN8Vector3iaSERKS_((int*)((char*)combatant + 0x44), (int*)(base + 0x184 + index * 0xc));
	int value = *(int*)(base + 0x1b4 + index * 4);
#else
	_ZN8Vector3iaSERKS_((int*)((char*)combatant + 0x44), (int*)(base + 0x188 + index * 0xc));
	int value = *(int*)(base + 0x1b8 + index * 4);
#endif
	*(int*)((char*)combatant + 0x50) = 0;
	*(int*)((char*)combatant + 0x54) = value;
	*(int*)((char*)combatant + 0x58) = 0;
}
