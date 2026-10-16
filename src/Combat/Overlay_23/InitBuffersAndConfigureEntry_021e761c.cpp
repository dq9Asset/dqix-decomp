#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

namespace {
struct ProfileBufferState {
    unsigned char unknown0[0x78];
    CreationWindow window;
    unsigned char unknownAfterWindow[0x5dc - 0x78 - sizeof(CreationWindow)];
    int ready;
};
}

struct Cont0205d1e0;
void ClearBuffers0204b010OverList0x98(Cont0205d1e0*);

struct Cont0205d228;
void CallFunc0204c8f0OverList0x9c(Cont0205d228*);

struct Cont0205d274;
void CallFunc0204b04cOverList0x98(Cont0205d274*);

extern "C" int func_0205ac40(void*, void*);

#if defined(jpn)
#define InitBuffersAndConfigureEntry_021e761c func_ov023_021e7868
extern "C" void func_ov023_021e7868(void* obj);
#endif

// USA: func_ov023_021e761c
// JPN: func_ov023_021e7868
ARM void InitBuffersAndConfigureEntry_021e761c(void *obj) {
	ProfileBufferState* state = static_cast<ProfileBufferState*>(obj);
	if (state->ready == 0) return;

	ClearBuffers0204b010OverList0x98(reinterpret_cast<Cont0205d1e0*>(&state->window));
	CallFunc0204c8f0OverList0x9c(reinterpret_cast<Cont0205d228*>(&state->window));
	CallFunc0204b04cOverList0x98(reinterpret_cast<Cont0205d274*>(&state->window));

#if !defined(jpn)
	char* base = static_cast<char*>(obj);
	if (*(int*)(base + 0x3c) != 2) return;
	if (*(int*)(base + 0x604) == 0) return;

	char *p = *(char**)(base + 0x608);
	if (p == NULL) return;

	unsigned char flag = *(unsigned char*)(base + 0x60d);
	int kind;
	if (flag != 0) {
		unsigned char idx = *(unsigned char*)(base + 0x60c);
		p = p + idx * 0x28;
		kind = idx + 3;
	} else {
		p = p + 0x50;
		kind = 5;
	}
	*(unsigned char*)(p + 0x22) = (unsigned char)kind;
	*(int*)(p + 0x14) = 0xd0000;
	*(int*)(p + 0x18) = 0x10000;

	func_0205ac40(*(void**)(base + 0x604), p);
#endif
}

#if defined(jpn)
#undef InitBuffersAndConfigureEntry_021e761c
#endif
