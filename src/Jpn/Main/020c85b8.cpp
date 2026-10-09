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
// JPN: func_020c85b8
ARM void SetInterruptHandler(unsigned int mask, const void *proc) {
    int dmaTimerIndex;
    int interruptID;

    interruptID = 0;
    do {
        if (mask & 1) {
            DMAOrTimerResponse *dmaTimerData = NULL;
            if (interruptID >= 8 && interruptID <= 11) {
                int dmaTimerIndex = interruptID - 8;
                dmaTimerData      = &data_0211127c[dmaTimerIndex];
            } else if (interruptID >= 3 && interruptID <= 6) {
                dmaTimerIndex = interruptID + 1;
                dmaTimerData  = &data_0211127c[dmaTimerIndex];
            } else {
                data_027e0000.interruptProcTable[interruptID] = (InterruptHandlerProc) proc;
            }

            if (dmaTimerData != NULL) {
                dmaTimerData->callback         = (DMACompletionCallback) proc;
                dmaTimerData->userdata         = 0;
                dmaTimerData->stayEnabledAfter = true;
            }
        }
        interruptID++;
        mask >>= 1;
    } while (interruptID < 22);
}



#endif
