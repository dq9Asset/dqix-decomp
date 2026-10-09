#if defined(jpn)
#include "System/DTCM.h"
#include "System/Interrupts.h"
#include <globaldefs.h>

#if defined(jpn)
    #define data_0211127c data_02110f1c
#endif

struct DMAOrTimerResponse {
    DMACompletionCallback callback;
    unsigned int stayEnabledAfter;
    int userdata;
};

extern DMAOrTimerResponse data_0211127c[8];

inline DMACompletionCallback &CallbackByIndex(int n, int base = 0) {
    return *(DMACompletionCallback *) ((unsigned int) &data_0211127c[base].callback + n * sizeof(DMAOrTimerResponse));
}

inline unsigned int &ShouldStayEnabledByIndex(int n, int base = 0) {
    return *(unsigned int *) ((unsigned int) &data_0211127c[base].stayEnabledAfter + n * sizeof(DMAOrTimerResponse));
}

inline int &CallbackUserdataByIndex(int n, int base = 0) {
    return *(int *) ((unsigned int) &data_0211127c[base].userdata + n * sizeof(DMAOrTimerResponse));
}

// KEEP-NAME: shared mask/opaque handler interface serves two callback signatures.
// JPN: func_020c8640
// KEEP-NAME: curated interrupt-handler lookup interface.
ARM InterruptHandlerProc GetInterruptHandler(unsigned int mask) {
    int interruptId             = 0;
    InterruptHandlerProc *pProc = &data_027e0000.interruptProcTable[0];
    do {
        if (!(mask & 1)) continue;

        if (interruptId >= 8 && interruptId <= 11) {
            return (InterruptHandlerProc) data_0211127c[interruptId - 8].callback;
        } else if (interruptId >= 3 && interruptId <= 6) {
            return (InterruptHandlerProc) data_0211127c[interruptId + 1].callback;
        } else {
            return *pProc;
        }

    } while (interruptId++, mask >>= 1, pProc++, interruptId < 22);
    return NULL;
}

// KEEP-NAME


#endif
