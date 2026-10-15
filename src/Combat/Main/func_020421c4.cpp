#include <globaldefs.h>
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "std_library_functions.h"

struct Struct0204a82c {
    int f0;
    short f4;
    short f6;
    short f8;
    char fa;
};

struct ScaledElementList0204aa48 {
    char* base;
    short index;
    char pad[4];
    unsigned char flag;
};

struct RebaseStruct {
    char pad[8];
    char* off8;
    char* offc;
};

struct Struct02094a24;

#include "Resource/MessageSystem.h"

extern SafeAllocator data_0210783c;
extern char data_020f000b;
extern char data_020f0023;
extern char data_020f003f;

void RegisterFieldTableEntries02042944(void*);
void ClearStruct0204a82c(struct Struct0204a82c*);
int GetScaledElementOffset(struct ScaledElementList0204aa48*);
void InitStruct02094a24(struct Struct02094a24*);
void BlankFunction02094a20(void*, SafeAllocator*);
void StoreGlobal02109400_02094a10(int);
void RebaseOffsets_02042998(struct RebaseStruct*);

// USA: func_020421c4
extern "C" ARM void func_020421c4(SafeAllocator* alloc) {
    unsigned int fileLen;
    struct Struct0204a82c entry;
    GPCReadPair pair;
    unsigned int decLen;
    unsigned int aligned;
    unsigned int old;
    unsigned int size;
    void* buf;
    void* p;
    MessageSystem* message;
    unsigned int off;
    unsigned char* base;
    unsigned int cap;

    p = alloc->Allocate(0x400);
    data_0210783c.CreateTypeA(p, 0x400);
    data_02107800.messageSystem = static_cast<MessageSystem*>(alloc->Allocate(sizeof(MessageSystem)));
    data_02107800.glyphPixels = static_cast<unsigned char*>(alloc->Allocate(0xf99));
    data_02107800.messageSystem->textContext = static_cast<MessageTextContext*>(alloc->Allocate(sizeof(MessageTextContext)));
    data_02107800.textBuffer = alloc->Allocate(0x960);
    data_02107800.firstLineBuffer = static_cast<unsigned short*>(alloc->Allocate(0x280));
    data_02107800.secondLineBuffer = static_cast<char*>(alloc->Allocate(0x280));
    data_02107800.savedTextBuffer = static_cast<char*>(alloc->Allocate(0x960));
    data_02107800.formatBuffer = static_cast<MessageScratchBuffer*>(alloc->Allocate(0x960));
    data_02107800.expandedBuffer = static_cast<char*>(alloc->Allocate(0x960));
    RegisterFieldTableEntries02042944(alloc);
    BackgroundLoader::AddLockGlobal();

    fileLen = 0;
    buf = LoadFileIntoMemory(&data_020f000b, data_0211e33c, &fileLen);
    ClearStruct0204a82c(&entry);
    if (buf != 0) {
        memcpy(&entry, buf, 0xc);
    }
    size = GetScaledElementOffset((struct ScaledElementList0204aa48*)&entry);
    p = alloc->Allocate(size);
    data_02107800.glyphAssets = static_cast<unsigned char*>(p);
    memcpy(p, (void*)((int)data_0211e33c + 0x10), size);

    GPCReadPair* rp = &pair;
    off = 0;
    decLen = off;
    base = data_0211e33c;
    cap = 0x30000;
    ZeroInitGPCPointer(&rp->pGPCFile);
    rp->ZeroInitializeMachine();
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine, &data_020f0023,
            base, decLen, cap, 0, 0)) {
        old = decLen;
        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, base + old, decLen,
            cap - old, &data_020f003f);
        cap = (decLen + 3) & ~3;
        pair.Reset();
        cap = off + (off + (off + cap));
        decLen = cap;
        memcpy((void*)0x01ff9740, base + old, cap);
    }

    BackgroundLoader::RemoveLockGlobal();
    data_0210783c.Reset();
    message = data_02107800.messageSystem;
    message->messageAllocator = &data_0210783c;
    p = alloc->Allocate(0x68);
    InitStruct02094a24((struct Struct02094a24*)p);
    BlankFunction02094a20(p, alloc);
    StoreGlobal02109400_02094a10((int)p);
    RebaseOffsets_02042998((struct RebaseStruct*)((char*)0x01ff9740 + off));
    if ((char*)0x01ff9740 + off != 0) {
        data_02107800.font8 = reinterpret_cast<FontGlyphTable*>((char*)0x01ff9740 + off);
    }
    data_02107800.messageSystem->textBuffer = data_02107800.textBuffer;
    data_02107800.messageSystem->firstLineBuffer = data_02107800.firstLineBuffer;
    data_02107800.messageSystem->secondLineBuffer = data_02107800.secondLineBuffer;
    data_02107800.messageSystem->savedTextBuffer = data_02107800.savedTextBuffer;
    data_02107800.messageSystem->formatBuffer = data_02107800.formatBuffer;
    data_02107800.messageSystem->expandedBuffer = data_02107800.expandedBuffer;
    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
}
