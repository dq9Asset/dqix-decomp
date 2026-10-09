#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_020425fc(char* buf, int a, int b);
extern "C" int func_020420b4(char* dst, int x);
struct Container020e0310;
extern "C" int func_020e2070(struct Container020e0310* c, int key);
extern "C" int func_02039188(void* unused, int index);
extern "C" int func_020426d4(char* buffer, char* label, int width, int extra);

struct Table_0219a544 { int values[5]; };
extern struct Table_0219a544 data_ov017_021d68c0;
extern int data_ov017_021d68b0[4];

// JPN: func_ov017_0219b0e8
extern "C" ARM void func_ov017_0219b0e8(unsigned char* a, char* buf, int type, int value) {
	if (!buf) return;
	if (type == 3 && value > 0) {
		func_020425fc(buf, 3, 2);
	}
	int resultByte = value;
	if (type == 3 && value <= 0) {
		struct Table_0219a544 local = data_ov017_021d68c0;
		GameObject* combatant;
		int idx = 0;
		GameState* battle = GameState::GetInstance();
		combatant = battle->GetProtagonist();
		while (((volatile int*)local.values)[idx] != 7) {
			resultByte = (signed char)func_02039188(combatant, ((volatile int*)local.values)[idx]);
			if (resultByte > 0) break;
			idx = (idx + 1) & 0xff;
		}
	}
	int key = (resultByte < 0) ? 0 : resultByte;
	struct Container020e0310* container = *(struct Container020e0310**)(a + 0x3e64);
	int fieldResult = func_020e2070(container, key);
	if (!fieldResult) return;
	func_020420b4(buf, 0);
	int width = data_ov017_021d68b0[type];
	func_020426d4(buf, (char*)fieldResult, width, 10);
}

#endif
