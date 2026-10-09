#if defined(jpn)
#include <globaldefs.h>

extern "C" void func_ov031_02237058(int);
extern "C" void func_ov031_0222d2b8(int);
extern "C" void func_ov031_0222cb94(int);
extern "C" void func_ov031_022359d8(int);
extern "C" void func_ov031_0222d0ac(void);
extern "C" void func_ov031_0222cefc(void);
extern "C" void* func_ov031_0223e9f8(void*, void*, void*, int);

struct StateBlock0222c918 {
	unsigned char state;
	unsigned char pad0;
	unsigned short field2;
	char* target;
};
extern StateBlock0222c918 data_ov031_0229188c;

// JPN: func_ov031_0222d0f8
extern "C" ARM void func_ov031_0222d0f8(int cmd) {
	int doFollowup = 1;
	int state = data_ov031_0229188c.state;
	switch (state) {
	case 0:
		if (cmd == 1) {
			if (data_ov031_0229188c.field2 == 0) {
				data_ov031_0229188c.state = 4;
				break;
			}
			func_ov031_02237058(0x13);
			void* result = func_ov031_0223e9f8((void*)0, (void*)func_ov031_0222cefc, (void*)0, 0x78);
			*(int*)(data_ov031_0229188c.target + 0x38) = (int)result;
			return;
		}
		if (*(unsigned char*)(data_ov031_0229188c.target + 0x51) > 1) {
			data_ov031_0229188c.state = state + 1;
		} else {
			doFollowup = 0;
		}
		break;
	case 1:
	case 2:
		if (cmd == 1) {
			data_ov031_0229188c.state = state - 1;
			break;
		}
		if (*(unsigned char*)(data_ov031_0229188c.target + 0x51) > state + 1) {
			data_ov031_0229188c.state = state + 1;
		} else {
			doFollowup = 0;
		}
		break;
	case 3:
		if (cmd == 1) {
			data_ov031_0229188c.state = state - 1;
			break;
		}
		func_ov031_0222d2b8(cmd);
		return;
	case 4:
		if (cmd == 1) {
			doFollowup = 0;
			break;
		}
		data_ov031_0229188c.field2 = 0;
		data_ov031_0229188c.state = 0;
		func_ov031_0222cb94(0);
		func_ov031_022359d8(0);
		break;
	}
	if (!doFollowup) {
		if (*(unsigned char*)(data_ov031_0229188c.target + 0x59) != 0) return;
		func_ov031_02237058(9);
		*(unsigned char*)(data_ov031_0229188c.target + 0x59) = 1;
		return;
	}
	func_ov031_02237058(8);
	func_ov031_0222d0ac();
}

#endif
