#include <globaldefs.h>
#if defined(jpn)
#define data_0210cf84 data_0210cc3c
#define data_020f1ee8 data_020f2054
#define data_020f1eec data_020f2058
#endif

#if defined(jpn)
extern "C" void func_020bcf10(int i0, int i1, int i2, int i3, int i4);
extern "C" void func_020bcfe0(void);
#define SetPairEntryPointers020bb444 func_020bcf10
#define InitPairSlotStates020bb514 func_020bcfe0
#else
extern void SetPairEntryPointers020bb444(int i0, int i1, int i2, int i3, int i4);
extern void InitPairSlotStates020bb514(void);
#endif
extern int ReturnFalse020bb6f8(void);
extern "C" void func_020bb588();

extern unsigned short data_0210cf84;
extern void* data_020f1ee8;
extern void* data_020f1eec;

// JPN: func_020bcf58
// USA: func_020bb48c
ARM void ConfigurePairMode020bb48c(unsigned int mode, int installHandlers) {
    if (mode <= 2) {
        SetPairEntryPointers020bb444(4, 3, 2, 0, 1);
    } else {
        SetPairEntryPointers020bb444(4, 3, 0, 2, 1);
    }
    data_0210cf84 = (unsigned short)mode;
    InitPairSlotStates020bb514();
    if (installHandlers != 0) {
        data_020f1ee8 = (void*)&func_020bb588;
        data_020f1eec = (void*)&ReturnFalse020bb6f8;
    }
}
