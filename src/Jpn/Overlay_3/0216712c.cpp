#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Obj0216712c {
	void* field0;
	SafeAllocator* allocArray;
};

struct Sizes3_0216712c { unsigned int v[3]; };
extern struct Sizes3_0216712c data_ov003_0217e18c;

// JPN: func_ov003_0216712c  (semantic: InitAllocatorArray_0216712c)
extern "C" ARM void func_ov003_0216712c(struct Obj0216712c* obj, SafeAllocator* alloc) {
	int i;
	struct Sizes3_0216712c sizes;
	if (alloc == NULL) return;
	obj->allocArray = (SafeAllocator*)alloc->Allocate(0x3c);
	sizes = data_ov003_0217e18c;
	for (i = 0; i < 3; i++) {
		unsigned int sz = sizes.v[i];
		void* p = alloc->Allocate(sz);
		obj->allocArray[i].CreateTypeA(p, sz);
	}
	if (obj->field0 == NULL) {
		obj->field0 = alloc->Allocate(0x4000);
	}
}

#endif
