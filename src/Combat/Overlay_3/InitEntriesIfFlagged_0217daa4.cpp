#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#if defined(jpn)
enum { kRegion90 = 0x8c };
#else
enum { kRegion90 = 0x90 };
#endif

struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc* obj);

// USA: func_ov003_0217daa4  (semantic: InitEntriesIfFlagged_0217daa4)
extern "C" ARM void func_ov003_0217daa4(char* obj) {
    MessageSystem* g = GetGlobalField0x1c020421a0();
    Forward0204359c(g, 2);
    func_020439b0(g, 0);
    struct Obj0205d2bc* p = *(struct Obj0205d2bc**)(obj + kRegion90);
    if (p == 0) return;
    if (*(signed char*)(obj + 4) == 2 || *(signed char*)(obj + 5) == 0) {
        InitEntries0205d2bc(p);
    }
}
