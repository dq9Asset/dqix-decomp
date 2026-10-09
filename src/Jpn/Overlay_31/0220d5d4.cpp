#if defined(jpn)
#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Cache.h"

extern int data_ov031_0224f13c;

extern "C" void func_ov031_0220df1c(int, int, int);
extern "C" void func_ov031_0220e1fc(int);
extern "C" void func_ov031_0220e6dc(void);

struct BattleCtx020d5340;
extern "C" int func_020d6d9c(int a0, struct BattleCtx020d5340* ctx);

// JPN: func_ov031_0220d5d4
extern "C" ARM int func_ov031_0220d5d4(int a, int b, int c) {
	int state = DisableIRQInterrupts();
	if (data_ov031_0224f13c == 0) {
		SetIRQInterruptState(state);
		return 1;
	}
	int mode = *(int*)((char*)data_ov031_0224f13c + 0x2260);
	switch (mode) {
	case 5:
		func_ov031_0220df1c(a, b, c);
		SetIRQInterruptState(state);
		return 2;
	case 6:
		func_ov031_0220df1c(a, b, c);
		SetIRQInterruptState(state);
		return 0;
	default:
		SetIRQInterruptState(state);
		return 1;
	case 3: {
		func_ov031_0220df1c(a, b, c);
		InvalidateDataCacheRange(*(void**)((char*)data_ov031_0224f13c + 0x2288), *(unsigned short*)((char*)data_ov031_0224f13c + 0x228c));
		*(int*)((char*)data_ov031_0224f13c + 0x2284) += 1;
		int r = func_020d6d9c((int)func_ov031_0220e6dc, (struct BattleCtx020d5340*)((char*)data_ov031_0224f13c + 0x2288));
		switch (r) {
		case 2:
			func_ov031_0220e1fc(5);
			*(unsigned short*)((char*)data_ov031_0224f13c + 0x2280) = 3;
			break;
		case 8:
			SetIRQInterruptState(state);
			return 4;
		case 3:
		default:
			func_ov031_0220e1fc(0xb);
			SetIRQInterruptState(state);
			return 7;
		}
		SetIRQInterruptState(state);
		return 3;
	}
	}
}

#endif
