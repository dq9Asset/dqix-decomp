#if defined(jpn)
#include <globaldefs.h>

struct PhaseState_0223a374 {
    int pad[0x10];
    int mode;
    int step;
};

typedef void (*ReportFn_0223a374)(int, const char*, ...);

struct PhaseContext_0223a374 {
    ReportFn_0223a374 volatile Report;
    PhaseState_0223a374* volatile state;
};

extern PhaseContext_0223a374 data_ov031_02291918;
extern const char data_ov031_0224d0fc[];
extern const char data_ov031_0224d120[];

extern "C" void func_ov031_02239b48(int);
extern "C" int func_ov031_0223a204();
extern "C" int func_ov031_0223a254();
extern "C" int func_ov031_0223ab38();
extern "C" int func_ov031_0223a104();
extern "C" int func_ov031_0223a134();

// JPN: func_ov031_0223ab54
extern "C" ARM void func_ov031_0223ab54(void) {
    int phase = data_ov031_02291918.state->mode;
    if (phase == 1) {
        ReportFn_0223a374 report = data_ov031_02291918.Report;
        if (report != 0) {
            report(0x8000000, data_ov031_0224d0fc);
        }
        return;
    }
    {
        ReportFn_0223a374 reportBusy = data_ov031_02291918.Report;
        if (reportBusy != 0) {
            reportBusy(0x8000000, data_ov031_0224d120, phase);
        }
    }

    int mode = data_ov031_02291918.state->mode;
    if (mode != 6 && mode != 5 && mode != 4) {
        func_ov031_02239b48(3);
        func_ov031_0223ab38();
        return;
    }
    func_ov031_02239b48(3);
    switch (data_ov031_02291918.state->step) {
    case 3:
        if (func_ov031_0223a204() == 0) {
            func_ov031_0223ab38();
        }
        break;
    case 1:
    case 5:
        if (func_ov031_0223a254() == 0) {
            func_ov031_0223ab38();
        }
        break;
    case 2:
        if (func_ov031_0223a104() == 0) {
            func_ov031_0223ab38();
        }
        break;
    case 0:
    case 4:
        if (func_ov031_0223a134() == 0) {
            func_ov031_0223ab38();
        }
        break;
    }
}

#endif
