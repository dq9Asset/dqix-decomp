#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct;

struct Group021cc388 {
	unsigned char pad0[4];
	signed char ownerId;
	unsigned char count;
	unsigned char ids[3];
	unsigned char kinds[3];
};

extern "C" int func_0200ff04(GameState* battleStruct);
extern "C" GameObject* func_0200fdb4(GameState* battleStruct, int combatantId);
extern "C" GameObject* func_0200fd3c(GameState* battleStruct, int combatantId);

extern "C" void func_ov017_02190e48(unsigned char* ov, int combatantId);
extern "C" void func_ov017_0219119c(unsigned char* ov, int combatantId, int mode);
extern "C" void func_ov017_0218fc44(unsigned char* ov, int combatantId, int flag, int c, int d);

extern "C" void func_ov017_021cc960(unsigned char combatantId, int tag, int value);
extern "C" ARM void func_02025d84(unsigned char* bits, unsigned int index);

extern "C" void func_0202be38(struct SearchStruct* search);

// JPN: func_ov017_021cc830
extern "C" ARM void func_ov017_021cc830(int tag, Group021cc388* group, GameState* battleStruct,
                                        unsigned char* ov, struct SearchStruct* search) {
	if (group->ownerId >= 0) {
		if (group->ownerId != func_0200ff04(battleStruct)) return;
	}

	unsigned char* bits = *(unsigned char**)(ov + 0x3000 + 0x4c0);
	unsigned char count = group->count;
	int lowValue = 0x3ff - 0x180;
	int flag, value;
	for (int i = 0; i < count; i++) {
		unsigned char idByte = group->ids[i];
		int id = idByte;
		int kind = group->kinds[i];
		if (func_0200fdb4(battleStruct, id)) {
			func_ov017_02190e48(ov, id);
		} else if (func_0200fd3c(battleStruct, id)) {
			func_ov017_0219119c(ov, id, 1);
		}
		if (kind == 0) {
			flag = 0x200;
			value = lowValue;
		} else if (kind == 1) {
			flag = 0x1000;
			value = 0x3ff;
		}
		func_ov017_0218fc44(ov, id, flag, 0, 0);
		func_ov017_021cc960(idByte, tag, value);
		func_02025d84(bits, id);
	}
	func_0202be38(search);
}

#endif
