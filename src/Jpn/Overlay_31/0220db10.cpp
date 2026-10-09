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

struct StructE53C_0220d330 {
	char pad[0x2260];
	int state;
	char pad2[0x226b - 0x2264];
	unsigned char flag226b;
	char pad3[0x2280 - 0x226c];
	short field2280;
};

extern StructE53C_0220d330* data_ov031_0224f13c;

// JPN: func_ov031_0220db10
extern "C" ARM int func_ov031_0220db10(void) {
	int mask = DisableIRQInterrupts();
	if (data_ov031_0224f13c == 0) {
		SetIRQInterruptState(mask);
		return 1;
	}

	int result;
	switch (data_ov031_0224f13c->state) {
		case 13:
			SetIRQInterruptState(mask);
			return 2;
		case 1:
			SetIRQInterruptState(mask);
			return 0;
		case 6:
			func_ov031_0220e1fc(0xd);
			data_ov031_0224f13c->field2280 = 9;
			SetIRQInterruptState(mask);
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
			SetIRQInterruptState(mask);
			return 1;
		case 3:
		case 9:
		case 12:
			if (data_ov031_0224f13c->flag226b == 1) {
				func_ov031_0220e1fc(0xd);
				data_ov031_0224f13c->field2280 = 9;
				goto epilogue3;
			}
			{
				unsigned short* field4 = func_020d6104();
				InvalidateDataCacheRange(field4, 2);
				switch (*field4) {
					case 0:
						result = func_020d5a38();
						if (result != 0) break;
						func_ov031_0220e1fc(1);
						data_ov031_0224f13c->field2280 = 0;
						SetIRQInterruptState(mask);
						return 0;
					case 1:
						result = func_020d6918((int)func_ov031_0220e420);
						break;
					case 2:
						result = func_020d6998((int)func_ov031_0220e420);
						break;
					default:
						data_ov031_0224f13c->flag226b = 1;
						result = func_020d6a60((int)func_ov031_0220ef90);
						break;
				}
			}
			break;
	}

	switch (result) {
		case 2:
			func_ov031_0220e1fc(0xd);
			data_ov031_0224f13c->field2280 = 9;
			goto epilogue3;
		case 8:
			SetIRQInterruptState(mask);
			return 4;
		case 3:
		default:
			func_ov031_0220e1fc(0xb);
			SetIRQInterruptState(mask);
			return 7;
	}

epilogue3:
	SetIRQInterruptState(mask);
	return 3;
}

#endif
