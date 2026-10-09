#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02010684(GameState*);
extern "C" int func_ov003_0216698c(char* self, int val);

struct FindEntryContainer02086a04;
extern "C" int func_02087324(struct FindEntryContainer02086a04* c, int id);

extern "C" void* func_0205ff20(void);
extern "C" void func_0206f0c0(void* unused, unsigned char* array, int bit, int value);


struct Obj020397cc;
extern "C" void func_02039224(struct Obj020397cc* obj, int arg1);

// JPN: func_ov003_021668ec  (semantic: HandleMarkedEntryRemoval_021668ec)
extern "C" ARM int func_ov003_021668ec(char* self) {
	GameState* bs;
	void* p2a04;
	int r;
	GameObject* c;

	if (*(short*)(self + 0x2a8) < 0) return 1;

	bs = GameState::GetInstance();
	p2a04 = func_02010684(bs);
	r = func_ov003_0216698c(self, *(short*)(self + 0x2a8));
	if (r == 0) return 0;
	if (r == 1) {
		func_02087324((struct FindEntryContainer02086a04*)p2a04, (signed char)*(short*)(self + 0x2a8));
		void* p = func_0205ff20();
		func_0206f0c0(p, (unsigned char*)p + 0x8c, 0x784, 1);
	}

	c = bs->GetProtagonist();
	if (c != NULL) {
		func_02039224((struct Obj020397cc*)c, 1);
	}
	return 1;
}

#endif
