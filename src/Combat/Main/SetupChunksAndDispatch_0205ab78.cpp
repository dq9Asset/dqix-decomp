#include <globaldefs.h>
#include "Resource/MessageRenderResources.h"

void InitFieldArray_020b033c(struct FieldArray* obj);

struct Hdr02b0288 {
    unsigned char pad[0xc];
    unsigned short dataOffset;
    unsigned short count;
};
int FindPcmpChunk_020b022c(struct Hdr02b0288* h, void** out);
int FindPlttChunkAndRelocate_020b01f0(struct Hdr02b0288* h, void** out);

extern "C" void func_020b08b8(void* plttChunk, void* pcmpChunk, int zero, int mode, void* fieldArr);
extern "C" void func_020b07c0(void* plttChunk, int zero, int mode, void* fieldArr);


// USA: func_0205ab78  (semantic: SetupChunksAndDispatch_0205ab78)
extern "C" ARM int func_0205ab78(LoadTable* obj, void* data, unsigned int length) {
    Hdr02b0288* h = static_cast<Hdr02b0288*>(data);
    int fail;
    int mode;

    InitFieldArray_020b033c(&obj->resource24);
    void* plttChunk = 0;
    void* pcmpChunk = 0;
    int pcmpFound = FindPcmpChunk_020b022c(h, &pcmpChunk);

    if (h == 0) {
        fail = 1;
    } else if (length == 0) {
        fail = 1;
    } else {
        if (FindPlttChunkAndRelocate_020b01f0(h, &plttChunk)) {
            fail = 0;
        } else {
            fail = 1;
        }
    }
    if (fail) {
        return 1;
    }

    mode = (obj->subScreen == 0) ? 1 : 2;
    if (pcmpFound) {
        func_020b08b8(plttChunk, pcmpChunk, 0, mode, &obj->resource24);
    } else {
        func_020b07c0(plttChunk, 0, mode, &obj->resource24);
    }
    return 0;
}
