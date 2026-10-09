#if defined(jpn)
#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Timing.h"

extern "C" ARM void func_ov031_0220f73c(void);
extern "C" ARM void func_ov031_0220e0b4(void);
extern void* data_ov031_0224f13c;

// JPN: func_ov031_0220d150
extern "C" ARM int func_ov031_0220d150(unsigned int a, unsigned int b) {
	int state = DisableIRQInterrupts();
	if (data_ov031_0224f13c != 0) {
		SetIRQInterruptState(state);
		return 1;
	}
	if (a == 0) {
		SetIRQInterruptState(state);
		return 1;
	}
	if (a & 0x1f) {
		SetIRQInterruptState(state);
		return 1;
	}
	if (b < 0x2300) {
		SetIRQInterruptState(state);
		return 6;
	}
	data_ov031_0224f13c = (void*)a;
	*(unsigned int*)((char*)a + 0x2000 + 0x260) = 1;
	*(unsigned short*)((char*)data_ov031_0224f13c + 0x2200 + 0x80) = 0;
	*(unsigned short*)((char*)data_ov031_0224f13c + 0x2200 + 0x68) = 0;
	*(unsigned char*)((char*)data_ov031_0224f13c + 0x2000 + 0x26a) = 0;
	*(unsigned char*)((char*)data_ov031_0224f13c + 0x2000 + 0x26b) = 0;
	*(unsigned short*)((char*)data_ov031_0224f13c + 0x2200 + 0x82) = 0;
	*(unsigned short*)((char*)data_ov031_0224f13c + 0x2200 + 0xf8) = 0;
	func_ov031_0220e0b4();
	func_ov031_0220f73c();
	if (!Is64BitTimerInitialized()) Initialize64BitTimer();
	if (!IsAlarmListInitialized()) InitializeActiveAlarmList();
	ZeroInitializeAlarm((Alarm*)((char*)data_ov031_0224f13c + 0x22cc));
	SetIRQInterruptState(state);
	return 0;
}

#endif
