#if defined(jpn)
#include <globaldefs.h>
#include <System/Interrupts.h>

struct SoundCommand020d3f90 {
    SoundCommand020d3f90* next;
};

struct SoundCommandState020d3f90 {
    SoundCommand020d3f90* freeList;
    unsigned long finishedTag;
    SoundCommand020d3f90* reserveList;
    SoundCommand020d3f90* reserveListEnd;
    SoundCommand020d3f90* freeListEnd;
    int waitingQueueRead;
    int waitingQueueWrite;
    int waitingCount;
    unsigned long currentTag;
};

extern SoundCommandState020d3f90 data_02112420;
extern SoundCommand020d3f90* data_02112444[9];
extern unsigned char data_02112700[0x1800];

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
int SendCommandToArm7(int command, int data, bool error);
extern "C" void func_020d434c();
extern "C" void* func_020d3dc0(unsigned long flags);

// JPN: func_020d3f90
extern "C" ARM int func_020d3f90(unsigned long flags) {
    int lastState = DisableIRQInterrupts();
    if (data_02112420.reserveList == NULL) {
        SetIRQInterruptState(lastState);
        return true;
    }
    if (data_02112420.waitingCount >= 8) {
        if (!(flags & 1)) {
            SetIRQInterruptState(lastState);
            return false;
        }
        do {
            func_020d3dc0(1);
        } while (data_02112420.waitingCount >= 8);
        if (data_02112420.reserveList == NULL) {
            SetIRQInterruptState(lastState);
            return true;
        }
    }
    CleanInvalidateCacheRange(data_02112700, sizeof(data_02112700));
    if (SendCommandToArm7(7, (int)data_02112420.reserveList, false) < 0) {
        if (!(flags & 1)) {
            SetIRQInterruptState(lastState);
            return false;
        }
        while (data_02112420.waitingCount >= 8 ||
               SendCommandToArm7(7, (int)data_02112420.reserveList, false) < 0) {
            SetIRQInterruptState(lastState);
            func_020d3dc0(0);
            lastState = DisableIRQInterrupts();
            CleanInvalidateCacheRange(data_02112700, sizeof(data_02112700));
            if (data_02112420.reserveList == NULL) {
                SetIRQInterruptState(lastState);
                return true;
            }
        }
    }
    data_02112444[data_02112420.waitingQueueWrite] = data_02112420.reserveList;
    data_02112420.waitingQueueWrite++;
    if (data_02112420.waitingQueueWrite > 8)
        data_02112420.waitingQueueWrite = 0;
    data_02112420.reserveList = NULL;
    data_02112420.reserveListEnd = NULL;
    data_02112420.waitingCount++;
    data_02112420.currentTag++;
    SetIRQInterruptState(lastState);
    if (flags & 2)
        func_020d434c();
    return true;
}

#endif
