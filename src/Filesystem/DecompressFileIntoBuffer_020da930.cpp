#if defined(jpn)
#include <globaldefs.h>
#include "Filesystem/ExtendedNitroVM.h"
#include "System/Memory.h"

// JPN: func_020da930
extern "C" ARM int func_020da930(const char* filename, void* buffer,
    unsigned int* outLength, unsigned int capacity, bool flag)
{
    *outLength = 0;
    if (buffer == NULL)
        return 0;

    ExtendedNitroVM reader;
    ClearAndInit020d84f8(&reader, sizeof(reader));
    reader.status = ExtendedNitroVM::Status_NotOpen;
    reader.isBadState = false;
    if (!reader.Open(filename, flag))
        return 0;

    int result = 0;
    unsigned int size = reader.GetFileSize();
    if (capacity >= ((size + 7) & ~3u)) {
        if (reader.DecompressBytes(buffer, *outLength, size, capacity) != 0)
            result = 1;
    }
    reader.Close();
    return result;
}
#endif
