#if defined(jpn)
#include <globaldefs.h>
#include "System/Memory.h"
#include "System/Timing.h"

struct Overlay31AddressEntry {
    unsigned int address;
    unsigned char identifier[6];
    unsigned short timestamp;
};
struct Overlay31AddressState {
    char unknown[0x50];
    unsigned int localAddress;
};
extern Overlay31AddressState data_ov031_0224d580;
extern Overlay31AddressEntry data_ov031_0224d600[8];
struct Overlay31TimestampView { unsigned short timestamp; char stride[10]; };
extern Overlay31TimestampView data_ov031_0224d60a[];
extern "C" {
int func_ov031_02200ed0(unsigned int);
int func_ov031_02200f70(unsigned int);

// JPN: func_ov031_02201618
extern "C" ARM void func_ov031_02201618(const void* identifier, unsigned int address, int allowInsert) {
    if (address == 0x7f000001 || address == data_ov031_0224d580.localAddress) return;
    if (!func_ov031_02200ed0(address)) return;
    if (func_ov031_02200f70(address)) return;
    unsigned short timestamp = GetCurrentTimestamp() >> 16;
    {
    unsigned int i = 0;
    Overlay31AddressEntry* entry = data_ov031_0224d600;
    do {
        if (address == entry->address) {
            data_ov031_0224d60a[i].timestamp = timestamp;
            VectorizedInvertedMemcpy(identifier, data_ov031_0224d600[i].identifier, 6);
            return;
        }
        ++i;
        ++entry;
    } while (i < 8);
    }
    if (!allowInsert) return;
    unsigned int selected;
    unsigned short oldestAge = 0;
    selected = oldestAge;
    Overlay31AddressEntry* entry = data_ov031_0224d600;
    unsigned int i = 0;
    do {
        if (!entry->address) {
            selected = i;
            break;
        }
        unsigned int age = timestamp - entry->timestamp;
        if (oldestAge < static_cast<short>(age)) {
            selected = i;
            oldestAge = age;
        }
        ++i;
        ++entry;
    } while (i < 8);
    data_ov031_0224d600[selected].address = address;
    VectorizedInvertedMemcpy(identifier, data_ov031_0224d600[selected].identifier, 6);
    data_ov031_0224d60a[selected].timestamp = timestamp;
}
}

#endif
