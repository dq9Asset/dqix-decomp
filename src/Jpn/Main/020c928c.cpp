#if defined(jpn)
#include "System/Interrupts.h"
#include "System/Mutex.h"
#include "System/ProcessorContext.h"
#include <globaldefs.h>

extern "C" void func_020ca3ec(int value, void *destination, unsigned int length);
extern "C" void func_020c9be0(void);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// JPN: func_020c928c
ARM void ShutdownContext(ProcessorContext *context) {
    int priorIRQState = DisableIRQInterrupts();
    if (data_021112e0.substruct_24.activeContext == context) {
        ShutdownCurrentContext();
    }

    AddContextSwitchLock();
    UnlockAllMutexesLockedByContext(context);
    CancelContextSleepAlarm(context);
    if (context->containerBlockedQueue != NULL) {
        context->containerBlockedQueue->Remove(context);
    }
    RemoveContextFromGlobalList(context);
    context->blockState = CONTEXT_STATE_INVALID;
    UnblockContexts(&context->contextsAwaitingThisCompletion);
    RemoveContextSwitchLock();
    SetIRQInterruptState(priorIRQState);
    SwitchContextUninterrupted();
}



#endif
