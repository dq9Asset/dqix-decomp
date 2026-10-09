#if defined(jpn)
#include "System/DTCM.h"
#include "System/Interrupts.h"
#include <globaldefs.h>

extern BlockedContextList data_027e0060;

// KEEP-NAME
// JPN: func_020c8420
extern "C" ARM void _Z16WaitForInterruptbj(bool onlySubsequent, unsigned int mask) {
    int priorState = DisableIRQInterrupts();

    if (onlySubsequent) {
        DTCMData *dtcm = &data_027e0000;
        dtcm++;
        (dtcm - 1)->interruptsFired &= ~mask;
    }

    SetIRQInterruptState(priorState);
    DTCMData *dtcm = &data_027e0000;
    dtcm++;

    if (mask & (dtcm - 1)->interruptsFired) {
        return;
    }

    unsigned int *fired = (unsigned int *) ((char *) (dtcm - 1) + 0x3ff8);
    do {
        BlockCurrentContext(&data_027e0060);
    } while (!(mask & *fired));
}


#endif
