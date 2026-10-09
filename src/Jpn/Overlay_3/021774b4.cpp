#if defined(jpn)
#include <globaldefs.h>

extern "C" short func_02080fa4(void* obj, int id);
extern "C" void func_ov003_02177428(void* self);
extern "C" void func_ov003_02175834(void* self);
extern "C" void func_ov003_021759f8(void* self);
extern "C" void func_ov003_02175ed0(void* self);
extern "C" void func_ov003_02175f8c(void* self);

// JPN: func_ov003_021774b4  (semantic: AdjustMappedIndexAndRefresh_021774b4)
extern "C" ARM void func_ov003_021774b4(char* obj) {
    int flags = *(int*)(obj + 0xf60);
    int delta = 0;
    if (flags & 0x10) {
        delta = 1;
    } else if (flags & 0x20) {
        delta -= 1;
    }

    *(short*)(obj + 0xf7c + 0x14) = *(short*)(obj + 0xf7c + 0x14) + delta;
    if (*(short*)(obj + 0xf7c + 0x16) <= *(short*)(obj + 0xf7c + 0x14)) {
        *(short*)(obj + 0xf7c + 0x14) = 0;
    }
    if (*(short*)(obj + 0xf7c + 0x14) < 0) {
        *(short*)(obj + 0xf7c + 0x14) = *(short*)(obj + 0xf7c + 0x16) - 1;
    }

    if (delta != 0) {
        void* p89c = *(void**)(obj + 0x818);
        short id = func_02080fa4(p89c, 3);
        *(short*)(*(void**)(obj + 0xf74)) = id;
        func_ov003_02177428(obj);
        func_ov003_02175834(obj);
        func_ov003_021759f8(obj);
        func_ov003_02175ed0(obj);
        func_ov003_02175f8c(obj);
    }

    func_ov003_02177428(obj);
    if (*(short*)(obj + 0xf7c) == *(short*)(*(void**)(obj + 0xf74))) {
        return;
    }
    func_ov003_02175834(obj);
    func_ov003_021759f8(obj);
    func_ov003_02175ed0(obj);
    func_ov003_02175f8c(obj);
}

#endif
