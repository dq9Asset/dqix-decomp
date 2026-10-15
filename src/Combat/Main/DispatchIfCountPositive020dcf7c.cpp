#include <globaldefs.h>

#if defined(jpn)
struct Struct020dfc40;
void ResetStruct020dfc40(Struct020dfc40* p);
void* ResetAndReturnSelf020dfc2c(void* p);
extern "C" int func_020e2168(char* destination, const char* tablePath,
    int index, int variant, bool lock);
extern const char data_020f2b6c[];
struct LocalBuf020dcf7c { unsigned char pad[0x18]; };
#else
extern char data_020f296c;
extern char data_020f297e;
void ComputeAndApplyWithCounter020e54bc(int, void*, int, int, unsigned char, int);
#endif

// JPN: func_020de968
// USA: func_020dcf7c
ARM void DispatchIfCountPositive020dcf7c(int count, void* buf) {
#if defined(jpn)
    const char* tablePath;
    if (count > 0 && buf != NULL) {
        LocalBuf020dcf7c local;
        tablePath = data_020f2b6c;
        *(char*)buf = 0;
        ResetAndReturnSelf020dfc2c(&local);
        ResetStruct020dfc40((Struct020dfc40*)&local);
    } else {
        return;
    }
    func_020e2168((char*)buf, tablePath, count, 0, true);
#else
    if (count <= 0) return;
    if (buf == NULL) return;
    ComputeAndApplyWithCounter020e54bc((int)buf, &data_020f296c, count, 0, 1, (int)&data_020f297e);
#endif
}
