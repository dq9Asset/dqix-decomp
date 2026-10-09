#if defined(jpn)
#include <globaldefs.h>

struct ProgressStruct384_02245548 {
	char pad[0x34];
	unsigned char type34;
	unsigned char type35;
	char pad2[0x374 - 0x35 - 1];
	unsigned char flags374;
	char pad3[0x384 - 0x374 - 1];
	int progress384;
};

// JPN: func_ov031_02246110
extern "C" ARM void func_ov031_02246110(ProgressStruct384_02245548* p) {
	if (p->flags374 & 1) {
		switch (p->type34) {
		case 2:
			if (p->progress384 < 0x3c000) p->progress384 = p->progress384 + 0x28;
			if (p->type35 == 6) p->progress384 = 0x3c000;
			break;
		case 3:
			if (p->progress384 < 0x46000) p->progress384 = p->progress384 + 0x51;
			if (p->type35 == 6) p->progress384 = 0x46000;
			break;
		case 4:
			if (p->progress384 < 0x77f33) p->progress384 = p->progress384 + 0xcc;
			if (p->type35 == 5) p->progress384 = 0x78000;
			break;
		}
	} else if (p->flags374 & 4) {
		switch (p->type34) {
		case 2:
			if (p->progress384 < 0x64000) p->progress384 = p->progress384 + 0x51;
			if (p->type35 == 6) p->progress384 = 0x64000;
			break;
		case 3:
			if (p->progress384 < 0x77f85) p->progress384 = p->progress384 + 0x7a;
			if (p->type35 == 6) p->progress384 = 0x78000;
			break;
		}
	} else if (p->flags374 & 2) {
		switch (p->type34) {
		case 2:
			if (p->progress384 < 0x3c000) p->progress384 = p->progress384 + 0x28;
			if (p->type35 == 6) p->progress384 = 0x3c000;
			break;
		case 3:
			if (p->progress384 < 0x46000) p->progress384 = p->progress384 + 0x51;
			if (p->type35 == 6) p->progress384 = 0x46000;
			break;
		case 5:
			if (p->progress384 < 0x77f33) p->progress384 = p->progress384 + 0xcc;
			if (p->type35 == 5) p->progress384 = 0x78000;
			break;
		}
	}
}

#endif
