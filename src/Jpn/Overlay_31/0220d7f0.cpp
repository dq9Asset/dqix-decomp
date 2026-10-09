#if defined(jpn)
#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Memory.h"

extern "C" int func_020d8530(int arg, int a, int b, int c, unsigned short d);
extern "C" void func_ov031_0220e1fc(int);
extern "C" void func_ov031_0220dd50(int);
extern "C" void func_ov031_0220e420(void);
extern int data_ov031_0224f13c;

// JPN: func_ov031_0220d7f0
// Begins connecting to an access point with optional WEP settings.
// The descriptor and key settings are copied into manager-owned storage before the asynchronous transition.
extern "C" ARM int ConnectWifiAccessPoint(void* accessPoint, unsigned char* wepSettings, int connectionOptions) {
	int irqState = DisableIRQInterrupts();
	if (data_ov031_0224f13c == 0) {
		SetIRQInterruptState(irqState);
		return 1;
	}
	int connectionState = *(int*)((char*)data_ov031_0224f13c + 0x2260);
	switch (connectionState) {
	case 3: {
		if (accessPoint == 0) {
			SetIRQInterruptState(irqState);
			return 1;
		}
		if (*(unsigned short*)((char*)accessPoint + 0x3c) != 0) {
			SetIRQInterruptState(irqState);
			return 1;
		}
		if (wepSettings != 0) {
			if (!(wepSettings[0] < 4 && wepSettings[1] < 4)) {
				SetIRQInterruptState(irqState);
				return 1;
			}
			*(unsigned char*)((char*)data_ov031_0224f13c + 0x2250) = wepSettings[0];
			*(unsigned char*)((char*)data_ov031_0224f13c + 0x2251) = wepSettings[1];
			if (*(unsigned char*)((char*)data_ov031_0224f13c + 0x2250) == 0) {
				VectorizedMemset((char*)data_ov031_0224f13c + 0x2200, 0, 0x50);
			} else {
				VectorizedInvertedMemcpy(wepSettings + 2, (char*)data_ov031_0224f13c + 0x2200, 0x50);
			}
		} else {
			VectorizedMemset((char*)data_ov031_0224f13c + 0x2200, 0, 0x52);
		}

		VectorizedInvertedMemcpy(accessPoint, (char*)data_ov031_0224f13c + 0x2140, 0xc0);
		*(unsigned short*)((char*)data_ov031_0224f13c + 0x2170) = *(unsigned short*)((char*)data_ov031_0224f13c + 0x216e) | 3;
		func_ov031_0220dd50(connectionOptions);
		break;
	}
	case 8:
		SetIRQInterruptState(irqState);
		return 2;
	case 9:
		SetIRQInterruptState(irqState);
		return 0;
	default:
		SetIRQInterruptState(irqState);
		return 1;
	}

	int setupResult = func_020d8530((int)func_ov031_0220e420, 0xffff, 0x50, 0xffff, 0xffff);
	switch (setupResult) {
	case 2:
		func_ov031_0220e1fc(8);
		*(unsigned short*)((char*)data_ov031_0224f13c + 0x2280) = 5;
		goto ret3;
	case 8:
		SetIRQInterruptState(irqState);
		return 4;
	case 3:
	default:
		func_ov031_0220e1fc(0xb);
		SetIRQInterruptState(irqState);
		return 7;
	}
ret3:
	SetIRQInterruptState(irqState);
	return 3;
}

#endif
