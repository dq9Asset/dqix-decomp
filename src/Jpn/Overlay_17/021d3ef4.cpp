#if defined(jpn)
#include <globaldefs.h>

struct SearchStruct0202c1a4;
extern "C" signed char func_0202bd54(struct SearchStruct0202c1a4* obj);
extern "C" void func_0208e9b8(void);
extern "C" int func_0202c094(void* obj);
extern "C" ARM int* func_02011e34(char* obj, int index);
extern "C" void func_ov017_021d3d48(unsigned char a0, signed char a1, unsigned char a2, unsigned char a3, int* p);
extern "C" int func_ov017_021d3da0(void* p);

struct Evt021d3aa4 {
    unsigned char pad0[4];
    unsigned char mode;
    signed char idx;
    unsigned char field6;
    unsigned char field7;
    int field8;
};

// JPN: func_ov017_021d3ef4
extern "C" ARM void func_ov017_021d3ef4(int p0, struct Evt021d3aa4* evt, char* buf, int table, struct SearchStruct0202c1a4* search) {
    func_0208e9b8();
    unsigned char* entryObj = *(unsigned char**)((char*)table + 0x3000 + 0x908);

    if (func_0202c094(search)) {
        if (evt->mode != 1) return;

        if (func_ov017_021d3da0(&evt->mode) != 0) {
            func_ov017_021d3d48(1, p0, evt->field6, evt->field7, &evt->field8);
        } else {
            func_ov017_021d3d48(2, p0, evt->field6, evt->field7, &evt->field8);
        }
        return;
    }

    if (p0 != 0) return;

    if (evt->mode == 0) {
        int* e = func_02011e34(buf, evt->field7);
        if (e) *e = evt->field8;
    } else if (evt->mode == 1) {
        signed char cur = func_0202bd54(search);
        if (evt->idx == cur) {
            if (entryObj[2] != 0) entryObj[9] = 1;
        }
        func_ov017_021d3da0(&evt->mode);
    } else if (evt->mode == 2) {
        signed char cur = func_0202bd54(search);
        if (evt->idx == cur) {
            entryObj[9] = 2;
        }
    }
}

#endif
