#if defined(jpn)
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"

struct List0202fec8;

extern "C" void* func_ov017_0218c1d0(void);

struct Foo0207df50;
extern "C" void func_0207ecd0(struct Foo0207df50* p);
extern "C" void func_0207ed10(char* obj);
extern "C" void func_0207ed2c(char* obj);
extern "C" void _ZN8Object3D8SetScaleEPK8Vector3i(unsigned char* dst, int* src);

extern "C" void _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void* obj, void* params, int flag);
extern "C" int _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* obj, void* data, int mode);

extern char data_ov003_0217ee49;
extern char data_ov003_0217ee4f;

struct PreviewScaleVector { unsigned int v[3]; };
extern struct PreviewScaleVector data_ov003_0217e3fc;

struct PreviewArchiveLoadParameters {
    int flag;
    void* data;
    unsigned int size;
    void* alloc;
    int one;
    int unknown14;
    int unknown18;
    int unknown1c;
};

// JPN: func_ov003_0217b69c
// Loads the service menu's enemy preview from the completed archive task.
// It extracts a .cchr, restores the shared texture tables, and starts the stand animation.
extern "C" ARM void LoadServiceEnemyPreviewModel(char* preview) {
    int backgroundLoader = (int)BackgroundLoader::GetInstance();
    int archiveData, archiveSize;
    ((BackgroundLoader*)((struct List0202fec8*)backgroundLoader))->GetLoadedFileByID((int)(*(int*)(preview + 0x130)), (void**)(&archiveData), (unsigned int*)(&archiveSize));

    void* fieldManager = func_ov017_0218c1d0();
    func_0207ecd0((struct Foo0207df50*)((char*)fieldManager + 0x27c));
    func_0207ed10((char*)fieldManager + 0x27c);

    unsigned int fileSize;
    const void* filePtr;
    if (FindFilesInNarcBySubstring((const void*)archiveData, &data_ov003_0217ee49, &filePtr, &fileSize, 1) == 0) {
        return;
    }

    unsigned int decompSize;
    void* decompressed = DecompressLZ77FileIntoAllocatedSpace(*(SafeAllocator*)(preview + 4), filePtr, decompSize);
    if (decompressed == 0) {
        return;
    }

    struct PreviewArchiveLoadParameters params;
    params.flag = 0;
    params.data = decompressed;
    params.unknown14 = 0;
    params.unknown18 = 0;
    params.unknown1c = 0;
    params.alloc = preview + 4;
    params.size = decompSize;
    params.one = 1;
    _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(preview + 0x80, &params, 0);

    func_0207ed2c((char*)fieldManager + 0x27c);

    struct PreviewScaleVector previewScale = data_ov003_0217e3fc;
    *(int*)(preview + 0xc4) = 0;
    *(int*)(preview + 0xc8) = 0xfae;
    *(int*)(preview + 0xcc) = 0;
    _ZN8Object3D8SetScaleEPK8Vector3i((unsigned char*)(preview + 0x80), (int*)&previewScale);

    _ZN8Object3D24MaybeSetRegularAnimationEPKci(preview + 0x80, &data_ov003_0217ee4f, 0);
}

#endif
