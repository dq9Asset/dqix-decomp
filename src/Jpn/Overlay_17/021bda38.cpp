#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

// JPN: func_ov017_021bda38
extern "C" ARM void func_ov017_021bda38(void* self, int index) {
	unsigned char* base = (unsigned char*)self;
	unsigned char mask = 1 << index;
	int wasSet = 0;
	if (base[0x170] & mask) wasSet = 1;
	base[0x170] &= ~mask;
	base[0x171] |= mask;
	if (!wasSet) return;
	GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(index);
	if (!combatant) return;
	_ZN8Vector3iaSERKS_((int*)((char*)combatant + 0x44), (int*)(base + 0x184 + index * 0xc));
	int value = *(int*)(base + 0x1b4 + index * 4);
	*(int*)((char*)combatant + 0x50) = 0;
	*(int*)((char*)combatant + 0x54) = value;
	*(int*)((char*)combatant + 0x58) = 0;
}

#endif
