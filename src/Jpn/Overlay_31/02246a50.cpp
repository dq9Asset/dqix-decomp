#if defined(jpn)
#include <globaldefs.h>

struct BlockedContextList;
void UnblockContexts(struct BlockedContextList* list);
extern "C" void func_020c98d8(void* data, int a, int b);
extern "C" void func_020c9a10(void* data, int a, int b);
extern "C" int func_020c9aac(void* obj, unsigned int* out, int canWait);

struct Cache0224c954 { short lastValue; short lastType; };
struct Msg02245e5c { short type; short value; };
struct State02291f24 { char pad0[8]; int field8; char pad_c[4]; int field10; char pad14[4]; int field18; };

extern struct Cache0224c954 data_ov031_0224d554;
extern struct State02291f24 data_ov031_02292b24;
extern struct BlockedContextList data_ov031_02292b3c;
extern int data_ov031_02292b60;

// JPN: func_ov031_02246a50
extern "C" ARM void func_ov031_02246a50(struct Msg02245e5c* msg) {
	if (data_ov031_0224d554.lastType != msg->type || data_ov031_0224d554.lastValue != msg->value) {
		data_ov031_0224d554.lastType = msg->type;
		data_ov031_0224d554.lastValue = msg->value;
	}
	switch (msg->type) {
	case 1:
		data_ov031_02292b24.field10 = 0;
	case 2:
	case 3:
	case 4:
	case 5:
	case 9:
		data_ov031_02292b24.field8 = msg->value;
		UnblockContexts(&data_ov031_02292b3c);
		return;
	case 6:
		if (data_ov031_02292b24.field18 != 0) {
			data_ov031_02292b24.field8 = msg->value;
			UnblockContexts(&data_ov031_02292b3c);
			return;
		}
		if (msg->value == 0) {
			func_020c98d8(&data_ov031_02292b60, 2, 0);
		} else {
			func_020c9a10(&data_ov031_02292b60, 3, 0);
		}
		return;
	case 7:
		if (msg->value == 0) {
			unsigned int tmp;
			if (func_020c9aac(&data_ov031_02292b60, &tmp, 0) != 0) return;
			func_020c98d8(&data_ov031_02292b60, 1, 0);
		} else {
			func_020c9a10(&data_ov031_02292b60, 3, 0);
		}
		return;
	case 8:
		data_ov031_02292b24.field10++;
		return;
	}
}

#endif
