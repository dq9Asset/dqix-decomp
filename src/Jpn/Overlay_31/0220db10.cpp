#if defined(jpn)
#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
void SetIRQInterruptState(int mask);
void InvalidateDataCacheRange(const void* addr, unsigned int size);
extern "C" int func_020d5a38(void);
extern "C" int func_020d6918(int value);
extern "C" int func_020d6998(int fn);
extern "C" int func_020d6a60(int fn);
extern "C" unsigned short* func_020d6104(void);
extern "C" void func_ov031_0220e1fc(int);
extern "C" void func_ov031_0220e420(void);
extern "C" void func_ov031_0220ef90(void);

struct WifiConnectionManager {
	char unknown0[0x2260];
	int state;
	char unknown2264[0x226b - 0x2264];
	unsigned char unknown226b;
	char unknown226c[0x2280 - 0x226c];
	short pendingOperation;
};

extern WifiConnectionManager* data_ov031_0224f13c;

// JPN: func_ov031_0220db10
// Requests shutdown of the Wi-Fi connection manager.
// The operation follows the current wireless state and may complete asynchronously.
extern "C" ARM int StopWifiConnectionManager(void) {
	int irqState = DisableIRQInterrupts();
	if (data_ov031_0224f13c == 0) {
		SetIRQInterruptState(irqState);
		return 1;
	}

	int result;
	switch (data_ov031_0224f13c->state) {
		case 13:
			SetIRQInterruptState(irqState);
			return 2;
		case 1:
			SetIRQInterruptState(irqState);
			return 0;
		case 6:
			func_ov031_0220e1fc(0xd);
			data_ov031_0224f13c->pendingOperation = 9;
			SetIRQInterruptState(irqState);
			return 3;
		case 0:
		case 2:
		case 4:
		case 5:
		case 7:
		case 8:
		case 10:
		case 11:
		default:
			SetIRQInterruptState(irqState);
			return 1;
		case 3:
		case 9:
		case 12:
			if (data_ov031_0224f13c->unknown226b == 1) {
				func_ov031_0220e1fc(0xd);
				data_ov031_0224f13c->pendingOperation = 9;
				goto epilogue3;
			}
			{
				unsigned short* wirelessStatus = func_020d6104();
				InvalidateDataCacheRange(wirelessStatus, 2);
				switch (*wirelessStatus) {
					case 0:
						result = func_020d5a38();
						if (result != 0) break;
						func_ov031_0220e1fc(1);
						data_ov031_0224f13c->pendingOperation = 0;
						SetIRQInterruptState(irqState);
						return 0;
					case 1:
						result = func_020d6918((int)func_ov031_0220e420);
						break;
					case 2:
						result = func_020d6998((int)func_ov031_0220e420);
						break;
					default:
						data_ov031_0224f13c->unknown226b = 1;
						result = func_020d6a60((int)func_ov031_0220ef90);
						break;
				}
			}
			break;
	}

	switch (result) {
		case 2:
			func_ov031_0220e1fc(0xd);
			data_ov031_0224f13c->pendingOperation = 9;
			goto epilogue3;
		case 8:
			SetIRQInterruptState(irqState);
			return 4;
		case 3:
		default:
			func_ov031_0220e1fc(0xb);
			SetIRQInterruptState(irqState);
			return 7;
	}

epilogue3:
	SetIRQInterruptState(irqState);
	return 3;
}

#endif
