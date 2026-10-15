#include <globaldefs.h>

struct Struct020dfc40;
void ResetStruct020dfc40(Struct020dfc40* p);
void* ResetAndReturnSelf020dfc2c(void* p);
#if defined(jpn)
extern "C" int func_020e2168(char* destination, const char* tablePath,
    int index, int variant, bool lock);
extern const char* data_020f2ca0;
#else
int ComputeAndApplyWithCounter020e04f4(int p0, void* p1, int p2, int p3, unsigned char p4, int p5);
extern int data_020f2a3c;
extern int data_020f2a24;
#endif

struct LocalBuf020dcfc8 { unsigned char pad[0x18]; };

// JPN: func_020de9cc
// USA: func_020dcfc8
ARM void NotifyLocalizedResourceLoad020dcfc8(int len, char* buf) {
    if (len > 0 && buf != NULL) {
        LocalBuf020dcfc8 local;
#if defined(jpn)
        const char* tablePath;
        buf[0] = 0;
        tablePath = data_020f2ca0;
#else
        int v2, v1;
        buf[0] = 0;
        v1 = data_020f2a3c;
        v2 = data_020f2a24;
#endif
        ResetAndReturnSelf020dfc2c(&local);
        ResetStruct020dfc40((Struct020dfc40*)&local);
#if defined(jpn)
        func_020e2168(buf, tablePath, len, 0, true);
#else
        ComputeAndApplyWithCounter020e04f4((int)buf, (void*)v2, len, 0, 1, v1);
#endif
    }
}
