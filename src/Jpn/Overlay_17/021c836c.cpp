#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8988(void* obj);
extern "C" void* func_ov017_021b8978(void* obj);
extern "C" void* func_ov017_021b8980(void* obj);
extern "C" int func_0200ff04(GameState* battleStruct);

struct Ret021c7ebc {
	unsigned char pad0[8];
	unsigned short field8;
	unsigned char pad1[0x20];
	signed char field2a;
};

struct Src021c7ebc {
	unsigned char pad0[4];
	unsigned short field4;
	unsigned short field6;
	unsigned int v1;
	unsigned int v2;
	unsigned char selector;
};

struct StatLevelsLow_021c7ebc {
	unsigned int s0:3, s1:3, s2:3, s3:3, s4:3, s5:3, s6:3, s7:3, s8:3, s9:3;
};

struct StatLevelsHigh_021c7ebc {
	unsigned int s0:3, s1:3, s2:3, s3:3, s4:4;
};

struct StatDisplay_021c7ebc {
	unsigned char levels[15];
};

// JPN: func_ov017_021c836c
extern "C" ARM void func_ov017_021c836c(int unused0, Src021c7ebc* src, GameState* battleStruct, unsigned char* globalObj) {
	unsigned char* base = globalObj + 0x3000;
	void* h = *(void**)(base + 0x508);
	Ret021c7ebc* r = (Ret021c7ebc*)func_ov017_021b8988(h);
	if (!r) return;
	if (!func_ov017_021b8978(h)) return;
	if (!func_ov017_021b8980(h)) return;
	int val = func_0200ff04(battleStruct);
	if (r->field2a == val) return;
	if (r->field8 != src->field4) return;
	GameObject* c = battleStruct->GetCombatantByIndex(src->field6);
	if (!c) return;
	StatLevelsLow_021c7ebc* low = (StatLevelsLow_021c7ebc*)&src->v1;
	StatLevelsHigh_021c7ebc* high = (StatLevelsHigh_021c7ebc*)&src->v2;
	if (src->selector == 1) {
		StatDisplay_021c7ebc* out = (StatDisplay_021c7ebc*)((unsigned char*)(*(void**)((unsigned char*)c + 0x138)) + 0x70);
		out->levels[0] = low->s0;
		out->levels[1] = low->s1;
		out->levels[2] = low->s2;
		out->levels[3] = low->s3;
		out->levels[4] = low->s4;
		out->levels[5] = low->s5;
		out->levels[6] = low->s6;
		out->levels[7] = low->s7;
		out->levels[8] = low->s8;
		out->levels[9] = low->s9;
		out->levels[10] = high->s0;
		out->levels[11] = high->s1;
		out->levels[12] = high->s2;
		out->levels[13] = high->s3;
		out->levels[14] = high->s4;
	} else {
		StatDisplay_021c7ebc* out = (StatDisplay_021c7ebc*)((unsigned char*)(*(void**)((unsigned char*)c + 0x138)) + 0x93);
		out->levels[0] = low->s0;
		out->levels[1] = low->s1;
		out->levels[2] = low->s2;
		out->levels[3] = low->s3;
		out->levels[4] = low->s4;
		out->levels[5] = low->s5;
		out->levels[6] = low->s6;
		out->levels[7] = low->s7;
		out->levels[8] = low->s8;
		out->levels[9] = low->s9;
		out->levels[10] = high->s0;
		out->levels[11] = high->s1;
		out->levels[12] = high->s2;
		out->levels[13] = high->s3;
		out->levels[14] = high->s4;
	}
}

#endif
