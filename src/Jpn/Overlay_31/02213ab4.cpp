#if defined(jpn)
#include <globaldefs.h>

extern "C" char* func_ov031_02213bd8(int);
extern int data_ov031_0224f1c4;

typedef void (*WifiReleaseCallback)(int, void*, int);

// JPN: func_ov031_02213ab4
// Releases each owned Wi-Fi resource block through the registered release callback.
// Ownership bits are cleared before callbacks run, and the callback state is released last.
extern "C" ARM void* ReleaseWifiConnectionResources(void) {
	char* callbackState = func_ov031_02213bd8(1);
	if (callbackState == 0) return callbackState;

	if ((*(unsigned char*)(callbackState+8)) & 0x10) {
		void* allocation = func_ov031_02213bd8(0x10);
		(*(unsigned char*)(callbackState+8)) = (*(unsigned char*)(callbackState+8)) & ~0x10;
		(*(WifiReleaseCallback*)(callbackState + 4))(0x10, allocation, 0xd18);
	}

	if ((*(unsigned char*)(callbackState+8)) & 0x8) {
		void* allocation = func_ov031_02213bd8(0x8);
		(*(unsigned char*)(callbackState+8)) = (*(unsigned char*)(callbackState+8)) & ~0x8;
		(*(WifiReleaseCallback*)(callbackState + 4))(0x8, allocation, 0xc);
	}

	if ((*(unsigned char*)(callbackState+8)) & 0x4) {
		void* allocation = func_ov031_02213bd8(0x4);
		(*(unsigned char*)(callbackState+8)) = (*(unsigned char*)(callbackState+8)) & ~0x4;
		(*(WifiReleaseCallback*)(callbackState + 4))(0x4, allocation, 0x58);
	}

	if ((*(unsigned char*)(callbackState+8)) & 0x2) {
		void* allocation = func_ov031_02213bd8(0x2);
		(*(unsigned char*)(callbackState+8)) = (*(unsigned char*)(callbackState+8)) & ~0x2;
		(*(WifiReleaseCallback*)(callbackState + 4))(0x2, allocation, 0x2300);
	}

	if (!((*(unsigned char*)(callbackState+8)) & 0x1)) return (void*)(int)(*(unsigned char*)(callbackState+8));
	(*(unsigned char*)(callbackState+8)) = (*(unsigned char*)(callbackState+8)) & ~0x1;
	(*(WifiReleaseCallback*)(callbackState + 4))(0x1, callbackState, 0x24);
	*(int*)((char*)&data_ov031_0224f1c4 + 0xc) = 0;
	return &data_ov031_0224f1c4;
}

#endif
