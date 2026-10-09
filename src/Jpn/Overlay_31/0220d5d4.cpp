#if defined(jpn)
#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Cache.h"

extern int data_ov031_0224f13c;

extern "C" void func_ov031_0220df1c(int, int, int);
extern "C" void func_ov031_0220e1fc(int);
extern "C" void func_ov031_0220e6dc(void);

struct WirelessScanParameters;
extern "C" int func_020d6d9c(int callback, struct WirelessScanParameters* scanParameters);

// JPN: func_ov031_0220d5d4
// Requests an asynchronous Wi-Fi access-point scan using the shared scan parameters.
// The result buffer is invalidated before the wireless processor writes it.
extern "C" ARM int StartWifiAccessPointScan(int scanOptionA, int scanOptionB, int scanOptionC) {
	int irqState = DisableIRQInterrupts();
	if (data_ov031_0224f13c == 0) {
		SetIRQInterruptState(irqState);
		return 1;
	}
	int connectionState = *(int*)((char*)data_ov031_0224f13c + 0x2260);
	switch (connectionState) {
	case 5:
		func_ov031_0220df1c(scanOptionA, scanOptionB, scanOptionC);
		SetIRQInterruptState(irqState);
		return 2;
	case 6:
		func_ov031_0220df1c(scanOptionA, scanOptionB, scanOptionC);
		SetIRQInterruptState(irqState);
		return 0;
	default:
		SetIRQInterruptState(irqState);
		return 1;
	case 3: {
		func_ov031_0220df1c(scanOptionA, scanOptionB, scanOptionC);
		InvalidateDataCacheRange(*(void**)((char*)data_ov031_0224f13c + 0x2288), *(unsigned short*)((char*)data_ov031_0224f13c + 0x228c));
		*(int*)((char*)data_ov031_0224f13c + 0x2284) += 1;
		int scanResult = func_020d6d9c((int)func_ov031_0220e6dc, (struct WirelessScanParameters*)((char*)data_ov031_0224f13c + 0x2288));
		switch (scanResult) {
		case 2:
			func_ov031_0220e1fc(5);
			*(unsigned short*)((char*)data_ov031_0224f13c + 0x2280) = 3;
			break;
		case 8:
			SetIRQInterruptState(irqState);
			return 4;
		case 3:
		default:
			func_ov031_0220e1fc(0xb);
			SetIRQInterruptState(irqState);
			return 7;
		}
		SetIRQInterruptState(irqState);
		return 3;
	}
	}
}

#endif
