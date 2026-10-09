#if defined(jpn)
#include <globaldefs.h>

extern "C" void func_ov017_021a123c(char* obj);
extern "C" void func_ov017_021a140c(char* obj);
extern "C" void func_ov017_021a164c(char* obj);
extern "C" void func_ov017_021a19dc(char* obj);
extern "C" void func_ov017_021a1bac(char* obj);
extern "C" void func_ov017_021a180c(char* obj);

extern "C" void func_ov017_021a10e0(char* obj);
extern "C" void func_ov017_021a12a0(char* obj);
extern "C" void func_ov017_021a1470(char* obj);
extern "C" void func_ov017_021a16b0(char* obj);
extern "C" void func_ov017_021a1870(char* obj);
extern "C" void func_ov017_021a1a40(char* obj);

extern "C" void func_020a3b5c();
extern "C" void func_020a3c54();
extern "C" void func_020a3b70(int id);
extern "C" void func_020a3c68(int id);

struct NibbleFieldStruct0219de70 {
	char pad[0xc];
	unsigned char val:4;
	unsigned char rest:4;
};

// JPN: func_ov017_0219e960
extern "C" ARM void func_ov017_0219e960(char* obj, void* unused, NibbleFieldStruct0219de70* src) {
	int val = src->val;
	int newState;
	if ((unsigned int)(val - 2) <= 1) newState = 0;
	else if (val == 5) newState = 2;
	else if (val == 6) newState = 3;
	else if (val == 7) newState = 4;
	else if (val == 8) newState = 5;
	else newState = 1;

	if (*(int*)(obj + 0x2000 + 0x8f8) == newState) return;

	switch (*(int*)(obj + 0x2000 + 0x8f8)) {
	case 0: func_ov017_021a123c(obj); break;
	case 1: func_ov017_021a140c(obj); break;
	case 3: func_ov017_021a19dc(obj); break;
	case 4: func_ov017_021a1bac(obj); break;
	case 2: func_ov017_021a164c(obj); break;
	case 5: func_ov017_021a180c(obj); break;
	}

	*(int*)(obj + 0x2000 + 0x8f8) = newState;

	switch (newState) {
	case 0: func_ov017_021a10e0(obj); break;
	case 1: func_ov017_021a12a0(obj); break;
	case 3: func_ov017_021a1870(obj); break;
	case 4: func_ov017_021a1a40(obj); break;
	case 2: func_ov017_021a1470(obj); break;
	case 5: func_ov017_021a16b0(obj); break;
	}

	func_020a3b5c();
	func_020a3c54();

	int s = *(int*)(obj + 0x2000 + 0x8f8);
	if (s == 0 || s == 2 || s == 5) {
		func_020a3b70(3);
		func_020a3c68(1);
	} else if (s == 1) {
		func_020a3b70(0);
		func_020a3c68(1);
	}
}

#endif
