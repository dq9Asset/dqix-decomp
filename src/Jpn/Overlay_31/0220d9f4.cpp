#if defined(jpn)
#include <globaldefs.h>
#include "System/Interrupts.h"

extern "C" void func_ov031_0220e1fc(int);
extern "C" void func_ov031_0220ee74(void*);
extern "C" int func_020d7724(int value);
extern void* data_ov031_0224f13c;

// JPN: func_ov031_0220d9f4
extern "C" ARM int func_ov031_0220d9f4(void) {
	int state = DisableIRQInterrupts();
	if (data_ov031_0224f13c == 0) {
		SetIRQInterruptState(state);
		return 1;
	}
	int v = *(int*)((char*)data_ov031_0224f13c + 0x2000 + 0x260);
	if (v == 3) goto ret0;
	if (v == 9) goto case9;
	if (v != 0xa) goto ret1;
	SetIRQInterruptState(state);
	return 2;
ret0:
	SetIRQInterruptState(state);
	return 0;
ret1:
	SetIRQInterruptState(state);
	return 1;
case9:
	if (*(unsigned char*)((char*)data_ov031_0224f13c + 0x2000 + 0x26b) == 1) {
		func_ov031_0220e1fc(0xa);
		*(unsigned short*)((char*)data_ov031_0224f13c + 0x2200 + 0x80) = 6;
		goto ret3;
	}
	{
		int r = func_020d7724((int)func_ov031_0220ee74);
		switch (r) {
		case 2:
			func_ov031_0220e1fc(0xa);
			*(unsigned short*)((char*)data_ov031_0224f13c + 0x2200 + 0x80) = 6;
			goto ret3;
		case 8:
			SetIRQInterruptState(state);
			return 4;
		case 3:
		default:
			func_ov031_0220e1fc(0xb);
			SetIRQInterruptState(state);
			return 7;
		}
	}
ret3:
	SetIRQInterruptState(state);
	return 3;
}

#endif
