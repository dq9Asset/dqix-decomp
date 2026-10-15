#include <globaldefs.h>
#include "Resource/MessageRenderResources.h"

struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* entry);
struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);
extern "C" int func_0205a528(LoadTable* a, void* ptr, unsigned int length, SafeAllocator* allocator);

// USA: func_0205a498
ARM int ProcessRecords0205a498(LoadTable* a, struct Rec020467f0* b, int flag, SafeAllocator* d) {
    int ret;
    if (flag) {
        int count = CountActiveEntries((struct ActiveEntry02046900*)b);
        for (int i = 0; i < count; i++) {
            void* dummyOut = 0;
            int fieldOut = 0;
            void* result = FindRecordByIndex(b, i, &dummyOut, &fieldOut);
            if (result) {
                func_0205a528(a, result, fieldOut, d);
            }
        }
        ret = 0;
    } else {
        ret = 1;
    }
    return ret;
}
