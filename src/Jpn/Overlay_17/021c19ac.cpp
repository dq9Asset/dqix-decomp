#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

extern "C" int func_0200f9e8(int* obj);
extern "C" int func_0200ff54(char* obj);
extern "C" void func_0203af30(unsigned int* obj, unsigned int mask);
extern "C" void func_0203af40(unsigned int* obj, unsigned int mask);
extern "C" void func_020a4628(unsigned char* obj, int mask);
extern "C" void func_020a4618(unsigned char* obj, unsigned char mask);
extern "C" void func_02039218(void* obj);
extern "C" void func_020a3b70(int id);
extern "C" void func_020a3c68(int id);
extern "C" int func_020952d4(void);
extern "C" int func_02095b94(void);

struct Obj020397cc;
extern "C" void func_02039224(struct Obj020397cc* obj, int arg1);

extern "C" void* func_02012b50(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114ac0;
extern "C" void func_020a2a3c(unsigned int);
extern "C" void func_020a2984(void);

extern "C" void func_02095748(int val);
extern "C" void func_02095b0c(int val);
extern "C" void func_0209595c(int val, int f20, int f24, unsigned char f28, unsigned char f29);

extern "C" void func_ov003_02155e08(void* mem, unsigned char b);
extern "C" void func_ov003_02155bd4(void* mem, SafeAllocator* alloc);
extern "C" int func_ov003_021561dc(void* mem, unsigned int scaleCount);
extern "C" void func_ov003_02156090(void* mem);

extern "C" ARM void func_ov017_021c180c(void);
extern "C" void func_ov017_021c193c(void* self);

extern int data_ov017_021d8d38;

struct Obj021c1404 {
	unsigned char pad0;
	unsigned char flag1;
	char pad2[6];
	SafeAllocator allocator;
	unsigned char step;
	unsigned char pad3;
	unsigned char field1e;
};

// JPN: func_ov017_021c19ac
extern "C" ARM void func_ov017_021c19ac(struct Obj021c1404* obj) {
	GameState* battle = GameState::GetInstance();
	int* word0 = (int*)func_0200f9e8((int*)battle);
	GameObject* combatant = battle->GetUnknownGameObject();
	int fieldVal = func_0200ff54((char*)battle);
	func_0203af30((unsigned int*)word0, 0xc0);
	if (combatant) {
		func_02039224((struct Obj020397cc*)combatant, 1);
	}
	func_020a4618((unsigned char*)fieldVal, 3);
	unsigned char step = obj->step;

	if (step == 0) {
		func_020a2a3c(0x22c00);
		void* buf = func_02012b50(&data_02114ac0, 0x22c00);
		if (!buf) {
			func_020a2984();
			obj->flag1 = 1;
			return;
		}
		obj->allocator.CreateTypeA(buf, 0x22c00);
		obj->allocator.Reset();
		void* mem = obj->allocator.Allocate(0x338);
		data_ov017_021d8d38 = (int)mem;
		if (!mem) {
			func_020a2984();
			obj->flag1 = 1;
			return;
		}
		func_020a3b70(3);
		func_020a3c68(1);
		func_ov003_02155e08((void*)data_ov017_021d8d38, obj->field1e);
		func_ov003_02155bd4((void*)data_ov017_021d8d38, &obj->allocator);
		func_ov017_021c180c();
		obj->step = obj->step + 1;
		return;
	}
	if (step == 1) {
		unsigned int scaleCount = battle->GetTickCount();
		if (func_ov003_021561dc((void*)data_ov017_021d8d38, scaleCount) == 0) return;
		int val = func_020952d4();
		func_02095b0c(val);
		func_02095748(val);
		func_0209595c(val, 0x6f, 0x1388, 1, 1);
		obj->step = obj->step + 1;
		return;
	}
	if (step == 2) {
		func_020952d4();
		if (!func_02095b94()) return;
		func_ov003_02156090((void*)data_ov017_021d8d38);
		obj->step = obj->step + 1;
		return;
	}
	if (step != 3) return;

	int* dispReg = (int*)0x4000000;
	unsigned int memField = *(unsigned int*)((char*)data_ov017_021d8d38 + 0x170);
	*dispReg = (memField << 8) | (*dispReg & ~0x1f00);
	func_0203af40((unsigned int*)word0, 0xc0);
	func_02039218(combatant);
	func_020a4628((unsigned char*)fieldVal, 3);
	func_ov017_021c193c(obj);
	func_020a2984();
	obj->flag1 = 1;
	func_ov017_021c180c();
}

#endif
