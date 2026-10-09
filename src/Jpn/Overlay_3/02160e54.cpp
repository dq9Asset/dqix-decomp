#if defined(jpn)
#include <globaldefs.h>
#include "Resource/Brightness.h"
#include "Memory/SafeAllocator.h"

extern "C" void* func_020d8608(void);
extern "C" void func_02047504(unsigned int* word, unsigned int bits);
extern "C" void func_ov003_02161520(void* obj);

struct View02160e54 {
	void* field0;
};

extern "C" void func_ov003_021671c4(struct View02160e54* view, int a, int b);
extern "C" void func_ov003_0216712c(struct View02160e54* view, SafeAllocator* alloc);
extern "C" int func_ov003_0216747c(struct View02160e54* view);

struct Self02160e54 {
	char pad0[0x124];
	SafeAllocator alloc23c;
	char pad250[0x200 - 0x124 - sizeof(SafeAllocator)];
	struct View02160e54* view;
	char pad31c[0x280 - 0x204];
	void* field398;
	char pad39c[0x28c - 0x284];
	unsigned int flags464;
	char pad468[0x2d0 - 0x290];
	unsigned char state;
};

// JPN: func_ov003_02160e54
extern "C" ARM int func_ov003_02160e54(struct Self02160e54* self) {
	GameResources* res = func_ov017_0218c1d0();
	void* dataPtr = func_020d8608();
	int result = 0;

	if (self->state == 0) {
		SetSubBrightness(res, -16, 8);
		self->state++;
	} else if (self->state == 1) {
		if (IsSubBrightnessTransitionActive(res) == 0) {
			func_02047504((unsigned int*)dataPtr, 1);
			self->alloc23c.Reset();
			func_ov003_021671c4(self->view, 0, -1);
			self->view->field0 = self->field398;
			func_ov003_0216712c(self->view, &self->alloc23c);
			self->state++;
		}
	} else if (self->state == 2) {
		if (func_ov003_0216747c(self->view) != 0) {
			func_ov003_02161520(self);
			self->state++;
		}
	} else if (self->state == 3) {
		SetSubBrightness(res, 0, 8);
		self->state++;
	} else if (self->state == 4) {
		if (IsSubBrightnessTransitionActive(res) == 0) {
			self->state = 0;
			result = 1;
			self->flags464 &= ~0x400;
		}
	}
	return result;
}

#endif
