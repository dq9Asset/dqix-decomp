#if defined(jpn)
#include <globaldefs.h>

extern "C" void func_ov031_0220e1fc(int);
extern "C" void func_ov031_0220e34c(void);
extern "C" void func_ov031_0220e164(int, int, int, int);
extern "C" int func_020d6ff8(int, unsigned int);
extern void* data_ov031_0224f13c;

struct TypeStruct_0220e694 { short f0; unsigned short type; };
struct TypeStruct_0220e4bc;
extern "C" void func_ov031_0220ec9c(struct TypeStruct_0220e4bc *s);

// JPN: func_ov031_0220ee74
extern "C" ARM void func_ov031_0220ee74(struct TypeStruct_0220e694 *s) {
	switch (s->type) {
	case 0: {
		int f260 = *(int*)((char*)data_ov031_0224f13c + 0x2000 + 0x260);
		if (f260 == 0xc) {
			func_ov031_0220e1fc(0xa);
			func_ov031_0220e34c();
			return;
		}
		int r = func_020d6ff8((int)func_ov031_0220ec9c, 0);
		if (r == 2) return;
		if (r == 3) goto case0_r3;
		if (r != 8) goto case0_r740;
		func_ov031_0220e1fc(0xc);
		func_ov031_0220e164(1, (int)((char*)data_ov031_0224f13c + 0x2140), 0, 0x8b4);
		return;
	case0_r3:
		func_ov031_0220e1fc(0xa);
		func_ov031_0220e34c();
		return;
	case0_r740:
		func_ov031_0220e1fc(0xb);
		func_ov031_0220e164(7, (int)((char*)data_ov031_0224f13c + 0x2140), 0, 0x8c0);
		return;
	}
	case 1:
	case 3:
		func_ov031_0220e1fc(0xa);
		func_ov031_0220e34c();
		return;
	case 2:
	case 4:
	default:
		func_ov031_0220e1fc(0xb);
		func_ov031_0220e164(7, (int)((char*)data_ov031_0224f13c + 0x2140), 0, 0x8d3);
		return;
	}
}

#endif
