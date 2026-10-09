#if defined(jpn)
#include <globaldefs.h>
#include "System/Cache.h"

extern "C" void func_ov031_0220e1fc(int a);
extern "C" void func_ov031_0220e34c(void);
extern "C" void func_ov031_0220e164(int a, void* b, int c, int d);
extern "C" void func_ov031_0220fb74(int a);
extern "C" void func_ov031_0220f77c(char* p);

extern void* data_ov031_0224f13c;

struct Msg0220e584 {
	unsigned short field0;
	unsigned short field2;
	unsigned short field4;
	unsigned short pad6;
	void* field8;
};

// JPN: func_ov031_0220ed64
extern "C" ARM void func_ov031_0220ed64(Msg0220e584* self) {
	switch (self->field2) {
	case 0:
		switch (self->field4) {
		case 0xe: {
			unsigned char* base = (unsigned char*)data_ov031_0224f13c;
			int val = *(int*)(base + 0x2000 + 0x260);
			if (val == 0xc) {
				func_ov031_0220e1fc(8);
				func_ov031_0220e34c();
			} else {
				func_ov031_0220e1fc(9);
				unsigned char* base2 = (unsigned char*)data_ov031_0224f13c;
				func_ov031_0220e164(0, base2 + 0x2140, 0, 0x872);
			}
			break;
		}
		case 0xf: {
			unsigned short h = *(unsigned short*)((unsigned char*)self->field8 + 0xe);
			int x = h;
			func_ov031_0220fb74((x >> 8) & 0xff);
			InvalidateDataCacheRange(self->field8, 0x620);
			func_ov031_0220f77c((char*)self->field8);
			break;
		}
		default: {
			func_ov031_0220e1fc(0xb);
			unsigned char* base = (unsigned char*)data_ov031_0224f13c;
			int f4 = self->field4;
			func_ov031_0220e164(7, base + 0x2140, f4, 0x881);
			break;
		}
		}
		break;
	case 4:
	default: {
		func_ov031_0220e1fc(0xb);
		unsigned char* base = (unsigned char*)data_ov031_0224f13c;
		func_ov031_0220e164(7, base + 0x2140, 0, 0x88c);
		break;
	}
	}
}

#endif
