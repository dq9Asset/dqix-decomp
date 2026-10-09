#if defined(jpn)
#include <globaldefs.h>

struct GlobalCtx0221087c {
	int field0;
	int field4;
	char pad8[0x40 - 8];
	volatile int field40;
};

extern void* volatile data_ov031_0224f188;

extern "C" void func_ov031_02210bbc(void* value);
extern "C" void func_ov031_02210bd8(void* value);
extern "C" int func_ov031_02212d78(void);
extern "C" int func_ov031_02212d9c(void);
extern "C" int func_ov031_02212d04(char* str, void* b);
void SleepCurrentContext(unsigned int ms);

// JPN: func_ov031_0221105c
extern "C" ARM void func_ov031_0221105c(void) {
	{
		GlobalCtx0221087c* obj = (GlobalCtx0221087c*)data_ov031_0224f188;
		if (obj->field4 == 1 && obj->field40 == 3) {
			func_ov031_02210bbc((void*)4);
			return;
		}
	}

	{
		GlobalCtx0221087c* obj = (GlobalCtx0221087c*)data_ov031_0224f188;
		if (!func_ov031_02212d04((char*)obj + 0x38, (char*)obj + 0x44)) return;
	}

	GlobalCtx0221087c* obj;
	while ((obj = (GlobalCtx0221087c*)data_ov031_0224f188)->field40 != 3 && obj->field40 != 5 && obj->field40 != 4) {
		int state = func_ov031_02212d78();
		obj = (GlobalCtx0221087c*)data_ov031_0224f188;
		obj->field40 = state;
		obj = (GlobalCtx0221087c*)data_ov031_0224f188;
		switch (obj->field40) {
		case 1:
		case 2:
			SleepCurrentContext(0x64);
			obj = (GlobalCtx0221087c*)data_ov031_0224f188;
			if (obj->field4 == 2) {
				func_ov031_02212d9c();
			}
			break;
		case 0:
		case 3:
		case 4:
		case 5:
			if (obj->field40 == 3 && obj->field4 == 1) {
				func_ov031_02210bbc((void*)4);
			} else {
				func_ov031_02210bd8((void*)1);
				obj = (GlobalCtx0221087c*)data_ov031_0224f188;
				obj->field40;
			}
			break;
		}
	}
}

#endif
