#if defined(jpn)
#include <globaldefs.h>
#include "System/Memory.h"

extern char* data_ov031_0224f13c;

struct WifiWorkAreaOptions { int mode; int bufferAddress; int bufferByteCount; int unknownC; };

#define REG0220D61C(off) (*(unsigned int*)((data_ov031_0224f13c + 0x2000) + (off)))

// JPN: func_ov031_0220ddfc
// Configures the Wi-Fi manager's optional caller-provided work buffer.
// The buffer is aligned to four bytes before clearing; null options select mode 3 and no buffer.
extern "C" ARM void ConfigureWifiConnectionWorkArea(WifiWorkAreaOptions* options, int connectionCallback) {
	if (options == NULL) {
		REG0220D61C(0x26c) = 3;
		REG0220D61C(0x270) = 0;
		REG0220D61C(0x274) = 0;
		REG0220D61C(0x278) = 0;
	} else {
		REG0220D61C(0x26c) = options->mode & 3;
		if ((((4 - (options->bufferAddress & 3)) & 3) + 0xc) > (unsigned int)options->bufferByteCount) {
			REG0220D61C(0x270) = 0;
			REG0220D61C(0x274) = 0;
		} else {
			REG0220D61C(0x270) = (options->bufferAddress + 3) & ~3;
			REG0220D61C(0x274) = options->bufferByteCount - ((4 - (options->bufferAddress & 3)) & 3);
			VectorizedMemset((void*)REG0220D61C(0x270), 0, REG0220D61C(0x274));
		}
		REG0220D61C(0x278) = options->unknownC;
	}
	REG0220D61C(0x27c) = connectionCallback;
}

#endif
