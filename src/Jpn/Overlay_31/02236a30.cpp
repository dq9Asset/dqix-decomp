#if defined(jpn)
#include <globaldefs.h>
#include "System/Memory.h"

extern "C" void func_ov031_02236954(void);

struct WifiSettingsWorkPointer { void* work; };
extern WifiSettingsWorkPointer data_ov031_022918fc;

struct WifiWepMode { unsigned char mode : 2; unsigned char unknownBits2 : 6; };

// JPN: func_ov031_02236a30
// Stages an SSID and four WEP keys in the Wi-Fi settings work area.
// The selected WEP mode determines how many key bytes are copied; it does not write persistent settings here.
extern "C" ARM void StageWifiAccessPointSettings(unsigned char* settings) {
	unsigned char* settingsWork = (unsigned char*)data_ov031_022918fc.work;

	VectorizedMemset(settingsWork + 0x400, 0, 0xef);
	VectorizedInvertedMemcpy(settings, settingsWork + 0x440, 0x20);

	int wepKeyBytes;
	switch (*(int*)(settings + 0x20)) {
	case 1:
		((WifiWepMode*)(settingsWork + 0x4e6))->mode = 1;
		wepKeyBytes = 5;
		break;
	case 2:
		((WifiWepMode*)(settingsWork + 0x4e6))->mode = 2;
		wepKeyBytes = 0xd;
		break;
	case 3:
		((WifiWepMode*)(settingsWork + 0x4e6))->mode = 3;
		wepKeyBytes = 0x10;
		break;
	default:
		((WifiWepMode*)(settingsWork + 0x4e6))->mode = 0;
		wepKeyBytes = 0;
		break;
	}
	((WifiWepMode*)(settingsWork + 0x4e6))->unknownBits2 = 0;

	int keyIndex = 0;
	unsigned char* destinationKey = settingsWork + 0x480;
	unsigned char* sourceKey = settings + 0x28;
	do {
		VectorizedInvertedMemcpy(sourceKey, destinationKey, wepKeyBytes);
		keyIndex++;
		destinationKey += 0x10;
		sourceKey += 0x20;
	} while (keyIndex < 4);

	settingsWork[0x4e7] = 2;
	VectorizedMemset(settingsWork + 0x4f0, 0, 4);
	settingsWork[0x4f5] = 1;
	settingsWork[0x4f6] = 1;
	func_ov031_02236954();
}

#endif
