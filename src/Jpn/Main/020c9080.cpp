#if defined(jpn)
#include "System/Interrupts.h"
#include "System/Mutex.h"
#include "System/ProcessorContext.h"
#include <globaldefs.h>

extern "C" void func_020cbeb8(int value, void *destination, unsigned int length);
extern "C" void func_020c9be0(void);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// JPN: func_020c9080
ARM void PopulateContext(ProcessorContext *context, unsigned int startAddress, unsigned int userdata, unsigned int stackBottom,
                         unsigned int stackSize, unsigned int priority) {
    int prior           = DisableIRQInterrupts();
    int id              = GenerateUniqueContextID();
    context->priority   = priority;
    context->uniqueID   = id;
    context->blockState = CONTEXT_STATE_BLOCKED;
    context->unknown_74 = 0;
    InsertContextIntoGlobalList(context);
    context->stackBottom                          = stackBottom;
    context->stackTop                             = stackBottom - stackSize;
    context->stackUnknownTopSubspaceSize          = 0;
    *(unsigned int *) (context->stackBottom - 4)  = STACK_BOTTOM_MAGIC;
    *(unsigned int *) context->stackTop           = STACK_TOP_MAGIC;
    context->contextsAwaitingThisCompletion.first = context->contextsAwaitingThisCompletion.last = NULL;
    InitializeContextRegisters(context, startAddress, stackBottom - 4);
    context->userModeRegisters[0]  = userdata;
    context->userModeRegisters[14] = (unsigned int) ContextExecutionReturnProc;
    func_020cbeb8(0, (void *) (stackBottom - stackSize + 4), stackSize - 8);
    context->blockingMutex        = NULL;
    context->lockedMutexes.pFirst = NULL;
    context->lockedMutexes.pLast  = NULL;
    SetContextEndProc(context, NULL);
    context->containerBlockedQueue = NULL;
    context->pNextBlocked          = NULL;
    context->pPrevBlocked          = NULL;
    func_020cbeb8(0, &context->unknown_A4, 0xc);
    context->sleepAlarm = NULL;
    SetIRQInterruptState(prior);
}



#endif
