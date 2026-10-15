#include <globaldefs.h>

#if defined(jpn)
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
extern char data_02108760;
extern "C" void func_0206cbe8(void*, unsigned short, unsigned short*);
extern "C" void func_0205dba0(char*);

// JPN: func_0206935c
extern "C" ARM void func_0206935c(char* self, int result) {
    switch (result) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 1, 0);
        func_0206cbe8(self, 0xff56 + result, *(unsigned short**)(self + 0x24));
        break;
    case 6:
        DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 1, 0);
    case -2:
        func_0206cbe8(self, 0xff5c, *(unsigned short**)(self + 0x24));
        break;
    default:
        return;
    }
    func_0205dba0(self + 0x50);
}
#endif
