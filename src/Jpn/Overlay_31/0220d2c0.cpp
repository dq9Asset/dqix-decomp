#if defined(jpn)
#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int state);
extern "C" int func_020d6504(void);
extern "C" int func_020d5a38(void);
extern "C" int func_020d6188(void* param);
extern "C" int func_020d68a4(int a);
extern "C" int func_020d5828(int a, int b);
extern "C" void func_ov031_0220e1fc(int);
extern "C" void func_ov031_0220ddfc(int, int);
extern "C" void func_ov031_0220e420(void);
struct CmdCheckStruct_0220dbc8;
extern "C" void func_ov031_0220e3a8(struct CmdCheckStruct_0220dbc8* s);
extern int data_ov031_0224f13c;

// JPN: func_ov031_0220d2c0
extern "C" ARM int func_ov031_0220d2c0(int a0, int a1) {
	unsigned int state = DisableIRQInterrupts();
	if (data_ov031_0224f13c == 0) {
		SetIRQInterruptState(state);
		return 1;
	}
	int v = *(int*)((char*)data_ov031_0224f13c + 0x2260);
	switch (v) {
	case 1:
		func_ov031_0220ddfc(a0, a1);
		break;
	case 2:
		SetIRQInterruptState(state);
		return 2;
	case 3:
		SetIRQInterruptState(state);
		return 0;
	default:
		SetIRQInterruptState(state);
		return 1;
	}

	int trunc = (unsigned short)(*(int*)((char*)data_ov031_0224f13c + 0x226c));
	int result = func_020d5828(data_ov031_0224f13c, trunc);
	switch (result) {
	case 3:
		func_ov031_0220e1fc(0xb);
		SetIRQInterruptState(state);
		return 7;
	case 4:
		SetIRQInterruptState(state);
		return 5;
	case 1:
	case 2:
	case 5:
	case 6:
	default:
		func_ov031_0220e1fc(0xb);
		SetIRQInterruptState(state);
		return 7;
	case 0: {
		int shared = func_020d6504();
		if (shared == 0) {
			if (func_020d5a38() != 0) {
				func_ov031_0220e1fc(0xb);
				SetIRQInterruptState(state);
				return 7;
			}
			SetIRQInterruptState(state);
			return 5;
		}
		if (func_020d6188((void*)func_ov031_0220e3a8) != 0) {
			func_ov031_0220e1fc(0xb);
			SetIRQInterruptState(state);
			return 7;
		}
		int act = func_020d68a4((int)func_ov031_0220e420);
		switch (act) {
		case 2:
			func_ov031_0220e1fc(2);
			*(unsigned short*)((char*)data_ov031_0224f13c + 0x2280) = 1;
			goto ret3;
		case 8:
			func_ov031_0220e1fc(0xc);
			SetIRQInterruptState(state);
			return 1;
		case 3:
		default:
			func_ov031_0220e1fc(0xb);
			SetIRQInterruptState(state);
			return 7;
		}
	ret3:
		SetIRQInterruptState(state);
		return 3;
	}
	}
}

#endif
