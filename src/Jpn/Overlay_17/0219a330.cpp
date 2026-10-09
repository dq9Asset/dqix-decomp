#if defined(jpn)
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "System/Cache.h"
#include "std_library_functions.h"


struct Struct020dfc40;
extern "C" void func_020e1840(struct Struct020dfc40* p);

struct Entry_02199684 { unsigned char pad[0x14]; int val; unsigned char pad2[0x20 - 0x18]; };
extern "C" void func_ov017_0219a234(Entry_02199684* arr, int count, int value);
extern "C" void func_ov017_0219a26c(Entry_02199684* arr, int count);

struct Cont0205d1e0;
extern "C" void func_0205e510(Cont0205d1e0*);
struct Cont0205d274;
extern "C" void func_0205e5a4(Cont0205d274*);
struct Obj0205d2bc;
extern "C" void func_0205e5ec(struct Obj0205d2bc*);
extern "C" void func_0205e378(void* obj);

extern "C" void func_ov017_0219a2ac(unsigned char* base);

extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);

extern "C" int func_ov017_0219a514(int size, int colorMode, int mapBase, int tileBase, int wrap);
extern "C" int func_ov017_0219a548(int priority);
extern "C" int func_ov017_0219a564(int screenSize, int colorMode, int screenBase, int charBase);
extern "C" int func_ov017_0219a590(int priority);

struct BgConfig02199780 {
	unsigned short priority : 2;
	unsigned short tileBase : 4;
	unsigned short unused6 : 1;
	unsigned short colorMode : 1;
	unsigned short mapBase : 5;
	unsigned short wrap : 1;
	unsigned short size : 2;
};

// JPN: func_ov017_0219a330
extern "C" ARM void func_ov017_0219a330(unsigned char* self) {
	if (*(int*)(self + 0x3000 + 0xe60) == 0) {
		return;
	}

	if (*(int*)(self + 0x3000 + 0xe58) != 0) {
		*(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | 0x100;

		int off = *(int*)(self + 0x3000 + 0xe5c);
		if (off >= 0) {
			int p = (int)BackgroundLoader::GetInstance();
			((BackgroundLoader*)(p))->RemoveTask((int)(*(int*)(self + 0x3000 + 0xe5c)));
		}

		*(volatile unsigned short*)0x4000050 = 0;
		*(volatile unsigned short*)0x4000008 = (*(volatile unsigned short*)0x4000008 & ~3) | 1;

		BgConfig02199780* bg1 = *(BgConfig02199780**)(self + 0x3000 + 0xa88);
		func_ov017_0219a514(bg1->size, bg1->colorMode, bg1->mapBase, bg1->tileBase, bg1->wrap);
		func_ov017_0219a548(bg1->priority);

		BgConfig02199780* bg2 = *(BgConfig02199780**)(self + 0x3000 + 0xa8c);
		func_ov017_0219a564(bg2->size, bg2->colorMode, bg2->mapBase, bg2->tileBase);
		func_ov017_0219a590(bg2->priority);

		if (*(int*)(self + 0x3000 + 0xe64) != 0) {
			func_020e1840((Struct020dfc40*)*(int*)(self + 0x3000 + 0xe64));
			*(int*)(self + 0x3000 + 0xe64) = 0;
		}

		if (*(int*)(self + 0x3000 + 0xe54) != 0) {
			func_ov017_0219a234((Entry_02199684*)(self + 0x294 + 0x3800), 2, 0x800);
			func_0205e510(*(Cont0205d1e0**)(self + 0x3000 + 0xa90));
			func_0205e5a4(*(Cont0205d274**)(self + 0x3000 + 0xa90));
			func_0205e5ec(*(Obj0205d2bc**)(self + 0x3000 + 0xa90));
			func_ov017_0219a26c((Entry_02199684*)(self + 0x294 + 0x3800), 2);
			func_0205e378(*(void**)(self + 0x3000 + 0xa90));

			memset(*(void**)(self + 0x3000 + 0xe54), 0, 0x20);
			CleanInvalidateCacheRange(*(void**)(self + 0x3000 + 0xe54), 0x20);
			LoadToMainBG1CharacterData(*(int*)(self + 0x3000 + 0xe54), 0, 0x20);
		}

		*(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | 0x1300;
	}

	func_ov017_0219a2ac(self);
}

#endif
