#if defined(jpn)
#include <globaldefs.h>
#include "System/Memory.h"

extern "C" void func_ov031_02236954(void);

struct WifiSettingsWorkPointer { void* work; };
extern WifiSettingsWorkPointer data_ov031_022918fc;

struct WifiWepMode { unsigned char mode : 2; unsigned char unknownBits2 : 6; };

// JPN: func_ov031_02236b44
// Stages a saved Wi-Fi access-point profile in the shared settings work area.
// Its fixed layout supplies four 13-byte WEP keys; the other profile fields are copied unchanged.
extern "C" ARM void StageWifiAccessPointProfile(unsigned char* profile) {
	unsigned char* settingsWork = (unsigned char*)data_ov031_022918fc.work + 0x400;

	VectorizedMemset(settingsWork, 0, 0xef);
	VectorizedInvertedMemcpy(profile, settingsWork + 0xd1, 5);
	VectorizedInvertedMemcpy(profile + 0x6, settingsWork + 0xd6, 5);
	VectorizedInvertedMemcpy(profile + 0xc, settingsWork + 0xdb, 5);
	VectorizedInvertedMemcpy(profile + 0x12, settingsWork + 0xe0, 5);
	VectorizedInvertedMemcpy(profile + 0x18, settingsWork + 0x60, 0x20);
	VectorizedInvertedMemcpy(profile + 0x39, settingsWork + 0x80, 0xd);
	VectorizedInvertedMemcpy(profile + 0x47, settingsWork + 0x90, 0xd);
	VectorizedInvertedMemcpy(profile + 0x55, settingsWork + 0xa0, 0xd);
	VectorizedInvertedMemcpy(profile + 0x63, settingsWork + 0xb0, 0xd);
	VectorizedInvertedMemcpy(profile + 0x71, settingsWork + 0x40, 0x20);

	WifiWepMode* wepMode = (WifiWepMode*)(settingsWork + 0xe6);
	wepMode->mode = 2;
	wepMode->unknownBits2 = 0;
	settingsWork[0xe7] = 1;

	VectorizedMemset(settingsWork + 0xf0, 0, 4);
	settingsWork[0xf5] = 1;
	settingsWork[0xf6] = 1;
	func_ov031_02236954();
}

#endif
