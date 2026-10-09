#include <globaldefs.h>

struct Data0218bcc4 {
#if defined(jpn)
    unsigned char pad[0x3c];
#else
    unsigned char pad[0x48];
#endif
    unsigned long long counter;
};
extern struct Data0218bcc4 data_ov016_0219d0c0;

// USA: func_ov016_0218bcc4
// JPN: func_ov016_0218c7a4
ARM void IncCounter_0218bcc4(void) {
    data_ov016_0219d0c0.counter++;
}
