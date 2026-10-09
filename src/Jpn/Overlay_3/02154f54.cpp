#if defined(jpn)
#include <globaldefs.h>

class PMFObj02154f54 { public: virtual void Dummy02154f54(); };
typedef void (PMFObj02154f54::*MemFn02154f54)();

struct Entry02154f54 { unsigned int a; unsigned int b; };

extern int data_ov003_0217ef20;
extern struct Entry02154f54 data_020e7604;
extern struct Entry02154f54 data_ov003_0217e500[];
extern struct Entry02154f54 data_ov003_0217e500_tbl[];

union PMFCast02154f54 { struct Entry02154f54* raw; MemFn02154f54* fn; };

// JPN: func_ov003_02154f54
extern "C" ARM int func_ov003_02154f54(PMFObj02154f54* obj) {
    if (!(data_ov003_0217ef20 & 1)) {
        *(unsigned long long*)((char*)data_ov003_0217e500 + 0x18) = *(const unsigned long long*)&data_020e7604;
        data_ov003_0217ef20 |= 1;
    }
    unsigned char idx = *((unsigned char*)obj + 0x5a);
    struct Entry02154f54* tbl = data_ov003_0217e500_tbl;
    if (tbl[idx].a == 0) {
        return 1;
    }
    union PMFCast02154f54 pmf;
    pmf.raw = &tbl[idx];
    (obj->*(*pmf.fn))();
    return 0;
}

#endif
