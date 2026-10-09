#if defined(jpn)
#include <globaldefs.h>
#include <System/DMA.h>
#include <System/DTCM.h>

struct DMAOrTimerResponse
{
    DMACompletionCallback callback;
    unsigned int stayEnabledAfter;
    int userdata;
};

extern DMAOrTimerResponse data_02110f1c[8];
extern unsigned short data_020f23e0[8];

unsigned int DisableSpecificInterrupts(unsigned int flagMask);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// JPN: func_020c8498
ARM void OnDMAOrTimerCompletion(int index)
{
    unsigned int mask = 1 << data_020f23e0[index];
    DMACompletionCallback callback = data_02110f1c[index].callback;
    data_02110f1c[index].callback = NULL;
    if (callback != NULL)
        callback(data_02110f1c[index].userdata);
    DTCM_DATA_INTERRUPTS_FIRED |= mask;
    if (!data_02110f1c[index].stayEnabledAfter)
        DisableSpecificInterrupts(mask);
}


#endif
