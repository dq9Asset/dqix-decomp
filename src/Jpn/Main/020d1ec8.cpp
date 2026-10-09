#if defined(jpn)
#include <globaldefs.h>
#include "Filesystem/CardReadManager.h"
#include "System/Cache.h"
#include "System/Memory.h"
#include "System/Interrupts.h"
#include "System/ProcessorContext.h"

extern "C" void func_02000b9c(unsigned int);
extern "C" int func_020d2a90(CardReadManager* manager, int command, int arg);
extern "C" int func_020d21b4();

extern CardReadManager data_02111580;

// JPN: func_020d1ec8
extern "C" ARM void func_020d1ec8(CardReadManager* manager) {
    int mode;
    unsigned int chunkSizeLimit;
    unsigned char* scratch;
    int command;

    command = manager->unknown_2c[0];
    mode = manager->unknown_2c[2];
    int arg = manager->unknown_2c[1];
    chunkSizeLimit = 0x100;

    func_02000b9c(0x2000bc4);

    if (command == 0xb) {
        chunkSizeLimit = func_020d21b4();
    } else if (command == 0xf) {
        chunkSizeLimit = data_02111580.pSharedData->unknown_4[7];
    }

    scratch = (unsigned char*)manager->unknown;
    int extraCommand = 9;

    do {
        unsigned int chunkSize = manager->writeLength;
        if (chunkSizeLimit < chunkSize)
            chunkSize = chunkSizeLimit;
        manager->pSharedData->unknown_4[4] = chunkSize;

        if (manager->flags & (1 << CARTRIDGE_READ_CONTEXT_FLAG_6)) {
            manager->flags &= ~(1 << CARTRIDGE_READ_CONTEXT_FLAG_6);
            manager->pSharedData->unknown_0 = 7;
            break;
        }

        switch (mode) {
        case 0:
            InvalidateDataCacheRange(scratch, chunkSize);
            manager->pSharedData->unknown_4[2] = manager->cartridgeReadOffset;
            manager->pSharedData->unknown_4[3] = (int)scratch;
            break;
        case 1:
        case 2:
            VectorizedInvertedMemcpy((const void*)manager->cartridgeReadOffset, scratch, chunkSize);
            CleanInvalidateCacheRange(scratch, chunkSize);
            DrainWriteBuffer();
            manager->pSharedData->unknown_4[2] = (int)scratch;
            manager->pSharedData->unknown_4[3] = (int)manager->writeDst;
            break;
        case 3:
            manager->pSharedData->unknown_4[2] = manager->cartridgeReadOffset;
            manager->pSharedData->unknown_4[3] = (int)manager->writeDst;
            break;
        }

        if (!func_020d2a90(manager, command, arg))
            break;

        if (mode == 2) {
            if (!func_020d2a90(manager, extraCommand, 1))
                break;
        } else if (mode == 0) {
            VectorizedInvertedMemcpy(scratch, manager->writeDst, chunkSize);
        }

        manager->cartridgeReadOffset += chunkSize;
        manager->writeDst += chunkSize;
        manager->writeLength -= chunkSize;
    } while (manager->writeLength != 0);

    int oldState;
    NitroHandle* handle;
    CardReadManager::CompletionCallback onComplete;

    onComplete = manager->onComplete;
    handle = manager->handle;

    oldState = DisableIRQInterrupts();
    manager->flags &= ~((1 << READ_MANAGER_FLAG_HARDWARE_READ_IN_PROGRESS) | (1 << READ_MANAGER_FLAG_CONTEXT_HAS_TASK_PENDING) | (1 << CARTRIDGE_READ_CONTEXT_FLAG_6));
    UnblockContexts(&manager->ongoingReadBlock);
    if (manager->flags & (1 << CARTRIDGE_READ_CONTEXT_FLAG_4)) {
        MarkContextReadyAndSwitch(&manager->cartridgeReadContext);
    }
    SetIRQInterruptState(oldState);

    if (onComplete != NULL) {
        onComplete(handle);
    }
}


#endif
