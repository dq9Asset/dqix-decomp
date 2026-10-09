#include <globaldefs.h>

#if defined(jpn)
static const int frameReadIndexOffset = 0xc0;
static const int frameBufferCountOffset = 0xa4;
#else
static const int frameReadIndexOffset = 0xc4;
static const int frameBufferCountOffset = 0xa8;
#endif

// USA: func_ov016_0218f2f0
// JPN: func_ov016_0218f510
ARM int IncrementCounters_0218f2f0(void* obj) {
	char* o = (char*)obj;
	unsigned int count = *(unsigned int*)(o + 0x9c);
	unsigned int limit = *(unsigned int*)(o + 0xa0);
	if (count >= limit) return 0;
	*(unsigned int*)(o + 0x9c) = count + 1;
	unsigned int c2 = *(unsigned int*)(o + frameReadIndexOffset) + 1;
	*(unsigned int*)(o + frameReadIndexOffset) = c2;
	if (c2 == *(unsigned int*)(o + frameBufferCountOffset)) {
		*(unsigned int*)(o + frameReadIndexOffset) = 0;
	}
	return 1;
}
