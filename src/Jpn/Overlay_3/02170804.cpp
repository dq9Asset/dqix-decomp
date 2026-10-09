#if defined(jpn)
#include <globaldefs.h>

class Base02170804 {
public:
    virtual void Method();
};
typedef void (Base02170804::*Method02170804)();

extern Method02170804 data_ov003_0217ead8[12];
extern Method02170804 data_020e7604;
extern int data_ov003_0217ef3c;

extern "C" void* func_0202a9d0(void);
extern "C" void func_ov017_021d4d40(void* p);
extern "C" void func_0202aca4(void* p);
extern "C" void* func_0202a9dc(void);
extern "C" int func_0202b5b0(int* obj);
extern "C" void func_0202d898(void);

// JPN: func_ov003_02170804  (semantic: DispatchOrIssueCommand_02170804)
extern "C" ARM int func_ov003_02170804(Base02170804* obj) {
    void* ptr = func_0202a9d0();
    func_ov017_021d4d40(func_0202a9dc());

    if (func_0202b5b0((int*)ptr) == -1) {
        func_0202d898();
        func_0202aca4(ptr);
        return 0;
    }

    if (!(data_ov003_0217ef3c & 1)) {
        data_ov003_0217ead8[11] = data_020e7604;
        data_ov003_0217ef3c |= 1;
    }

    unsigned char idx = *(unsigned char*)obj;
    (obj->*data_ov003_0217ead8[idx])();
    return 1;
}

#endif
