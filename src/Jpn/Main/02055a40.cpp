#if defined(jpn)
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/SignedAllocator.h"

struct S02055080;

extern "C" extern void* func_02056408(struct S02055080* obj);
extern "C" extern void* func_02056420(struct S02055080* obj);
extern "C" extern void* func_02056438(struct S02055080* p);
extern "C" extern void* func_02056450(struct S02055080* p);
extern "C" extern void* func_02056498(struct S02055080* p);
extern "C" extern void* func_020564b0(struct S02055080* obj);
extern "C" extern void* func_020564c8(struct S02055080* obj);
extern "C" extern int func_020564e0(struct S02055080* obj);

struct Obj02054f3c;
extern "C" extern bool func_020562b4(struct Obj02054f3c** out, SafeAllocator* alloc);
struct Obj02054ef8;
extern "C" extern bool func_02056270(struct Obj02054ef8** out, SafeAllocator* alloc);
struct Obj02054eb4;
extern "C" extern bool func_0205622c(struct Obj02054eb4** out, SafeAllocator* alloc);
struct T02054e70;
extern "C" extern int func_020561e8(struct T02054e70** out, SafeAllocator* alloc);

struct S02055080 {
    SafeAllocator* alloc;          // 0x0
    void* fieldSub;                // 0x4
    SignedAllocatorList listB[3];  // 0x8
    SignedAllocatorList listC[3];  // 0x2c
    SignedAllocatorList listD[3];  // 0x50
    SignedAllocatorList listE;     // 0x74
    SignedAllocatorList listF[3];  // 0x80
    SignedAllocatorList listG;     // 0xa4
    SignedAllocatorList listH[2];  // 0xb0
    SignedAllocatorList listI[2];  // 0xc8
    SignedAllocatorList listJ;     // 0xe0
    SignedAllocatorList listK[4];  // 0xec
    SignedAllocatorList listA;     // 0x11c
};

struct R1_020546c8 {
    char pad0[4];
    void* arr;
    char pad8[4];
    unsigned short count;
};

struct R2_020546c8 {
    void* arrB[3];
    void* arrC[3];
    void* arrD[3];
    unsigned char countB[3];
    unsigned char countC[3];
    unsigned char countD[3];
};

struct R3_020546c8 {
    void* arr;
    unsigned char count;
};

struct R4_020546c8 {
    void* arr[3];
    void* arrExtra;
    unsigned char count[3];
    unsigned char countExtra;
};

struct RArrCount2_020546c8 {
    void* arr[2];
    unsigned char count[2];
};

struct R7_020546c8 {
    char pad0[4];
    void* arr;
    unsigned char count;
};

struct R8_020546c8 {
    void* arr[4];
    unsigned char count[4];
};

// JPN: func_02055a40
extern "C" ARM void func_02055a40(struct S02055080* sl) {
    struct R1_020546c8* r1s = (struct R1_020546c8*)func_02056408(sl);
    if (r1s != NULL && r1s->count != 0) {
        struct Obj02054f3c* pA = NULL;
        if (func_020562b4(&pA, sl->alloc)) {
            sl->listA.InsertAtEnd((SignedAllocatorHeader*)pA);
            *(int*)pA = (int)r1s->arr;
            for (int i = 1; i < r1s->count; i++) {
                pA = NULL;
                if (func_020562b4(&pA, sl->alloc)) {
                    sl->listA.InsertAtEnd((SignedAllocatorHeader*)pA);
                    *(int*)pA = (int)((char*)r1s->arr + i * 0x1c);
                }
            }
        }
    }

    struct R2_020546c8* r2s = (struct R2_020546c8*)func_02056420(sl);
    if (r2s != NULL) {
        for (int sb = 0; sb < 3; sb++) {
            if (r2s->countB[sb] != 0) {
                struct Obj02054ef8* pB = NULL;
                if (func_02056270(&pB, sl->alloc)) {
                    sl->listB[sb].InsertAtEnd((SignedAllocatorHeader*)pB);
                    *(int*)pB = (int)r2s->arrB[sb];
                    for (int j = 1; j < r2s->countB[sb]; j++) {
                        pB = NULL;
                        if (func_02056270(&pB, sl->alloc)) {
                            sl->listB[sb].InsertAtEnd((SignedAllocatorHeader*)pB);
                            *(int*)pB = (int)((char*)r2s->arrB[sb] + j * 8);
                        }
                    }
                }
            }
            if (r2s->countC[sb] != 0) {
                struct Obj02054ef8* pC = NULL;
                if (func_02056270(&pC, sl->alloc)) {
                    sl->listC[sb].InsertAtEnd((SignedAllocatorHeader*)pC);
                    *(int*)pC = (int)r2s->arrC[sb];
                    for (int j = 1; j < r2s->countC[sb]; j++) {
                        pC = NULL;
                        if (func_02056270(&pC, sl->alloc)) {
                            sl->listC[sb].InsertAtEnd((SignedAllocatorHeader*)pC);
                            *(int*)pC = (int)((char*)r2s->arrC[sb] + j * 8);
                        }
                    }
                }
            }
            if (r2s->countD[sb] != 0) {
                struct Obj02054ef8* pD = NULL;
                if (func_02056270(&pD, sl->alloc)) {
                    sl->listD[sb].InsertAtEnd((SignedAllocatorHeader*)pD);
                    *(int*)pD = (int)r2s->arrD[sb];
                    for (int j = 1; j < r2s->countD[sb]; j++) {
                        pD = NULL;
                        if (func_02056270(&pD, sl->alloc)) {
                            sl->listD[sb].InsertAtEnd((SignedAllocatorHeader*)pD);
                            *(int*)pD = (int)((char*)r2s->arrD[sb] + j * 8);
                        }
                    }
                }
            }
        }
    }

    struct R3_020546c8* r3s = (struct R3_020546c8*)func_02056438(sl);
    if (r3s != NULL && r3s->count != 0) {
        struct Obj02054ef8* pE = NULL;
        if (func_02056270(&pE, sl->alloc)) {
            sl->listE.InsertAtEnd((SignedAllocatorHeader*)pE);
            *(int*)pE = (int)r3s->arr;
            for (int i = 1; i < r3s->count; i++) {
                pE = NULL;
                if (func_02056270(&pE, sl->alloc)) {
                    sl->listE.InsertAtEnd((SignedAllocatorHeader*)pE);
                    *(int*)pE = (int)((char*)r3s->arr + i * 8);
                }
            }
        }
    }

    struct R4_020546c8* r4s = (struct R4_020546c8*)func_02056450(sl);
    if (r4s != NULL) {
        for (int sb = 0; sb < 3; sb++) {
            if (r4s->count[sb] != 0) {
                struct Obj02054ef8* pF = NULL;
                if (func_02056270(&pF, sl->alloc)) {
                    sl->listF[sb].InsertAtEnd((SignedAllocatorHeader*)pF);
                    *(int*)pF = (int)r4s->arr[sb];
                    for (int j = 1; j < r4s->count[sb]; j++) {
                        pF = NULL;
                        if (func_02056270(&pF, sl->alloc)) {
                            sl->listF[sb].InsertAtEnd((SignedAllocatorHeader*)pF);
                            *(int*)pF = (int)((char*)r4s->arr[sb] + j * 8);
                        }
                    }
                }
            }
        }
        if (r4s->countExtra != 0) {
            struct Obj02054eb4* pG = NULL;
            if (func_0205622c(&pG, sl->alloc)) {
                sl->listG.InsertAtEnd((SignedAllocatorHeader*)pG);
                *(int*)pG = (int)r4s->arrExtra;
                for (int i = 1; i < r4s->countExtra; i++) {
                    pG = NULL;
                    if (func_0205622c(&pG, sl->alloc)) {
                        sl->listG.InsertAtEnd((SignedAllocatorHeader*)pG);
                        *(int*)pG = (int)((char*)r4s->arrExtra + i * 0x10);
                    }
                }
            }
        }
    }

    struct RArrCount2_020546c8* r5s = (struct RArrCount2_020546c8*)func_02056498(sl);
    if (r5s != NULL) {
        for (int r8i = 0; r8i < 2; r8i++) {
            if (r5s->count[r8i] != 0) {
                struct Obj02054ef8* pH = NULL;
                if (func_02056270(&pH, sl->alloc)) {
                    sl->listH[r8i].InsertAtEnd((SignedAllocatorHeader*)pH);
                    *(int*)pH = (int)r5s->arr[r8i];
                    for (int j = 1; j < r5s->count[r8i]; j++) {
                        pH = NULL;
                        if (func_02056270(&pH, sl->alloc)) {
                            sl->listH[r8i].InsertAtEnd((SignedAllocatorHeader*)pH);
                            *(int*)pH = (int)((char*)r5s->arr[r8i] + j * 8);
                        }
                    }
                }
            }
        }
    }

    struct RArrCount2_020546c8* r6s = (struct RArrCount2_020546c8*)func_020564b0(sl);
    if (r6s != NULL) {
        for (int r8i = 0; r8i < 2; r8i++) {
            if (r6s->count[r8i] != 0) {
                struct Obj02054eb4* pI = NULL;
                if (func_0205622c(&pI, sl->alloc)) {
                    sl->listI[r8i].InsertAtEnd((SignedAllocatorHeader*)pI);
                    *(int*)pI = (int)r6s->arr[r8i];
                    for (int j = 1; j < r6s->count[r8i]; j++) {
                        pI = NULL;
                        if (func_0205622c(&pI, sl->alloc)) {
                            sl->listI[r8i].InsertAtEnd((SignedAllocatorHeader*)pI);
                            *(int*)pI = (int)((char*)r6s->arr[r8i] + j * 0x10);
                        }
                    }
                }
            }
        }
    }

    struct R7_020546c8* r7s = (struct R7_020546c8*)func_020564c8(sl);
    if (r7s != NULL && r7s->count != 0) {
        struct T02054e70* pJ = NULL;
        if (func_020561e8(&pJ, sl->alloc)) {
            sl->listJ.InsertAtEnd((SignedAllocatorHeader*)pJ);
            *(int*)pJ = (int)r7s->arr;
            for (int i = 1; i < r7s->count; i++) {
                pJ = NULL;
                if (func_020561e8(&pJ, sl->alloc)) {
                    sl->listJ.InsertAtEnd((SignedAllocatorHeader*)pJ);
                    *(int*)pJ = (int)((char*)r7s->arr + i * 0xc);
                }
            }
        }
    }

    struct R8_020546c8* r8s = (struct R8_020546c8*)func_020564e0(sl);
    if (r8s != NULL) {
        for (int r8i = 0; r8i < 4; r8i++) {
            if (r8s->count[r8i] != 0) {
                struct Obj02054ef8* pK = NULL;
                if (func_02056270(&pK, sl->alloc)) {
                    sl->listK[r8i].InsertAtEnd((SignedAllocatorHeader*)pK);
                    *(int*)pK = (int)r8s->arr[r8i];
                    for (int j = 1; j < r8s->count[r8i]; j++) {
                        pK = NULL;
                        if (func_02056270(&pK, sl->alloc)) {
                            sl->listK[r8i].InsertAtEnd((SignedAllocatorHeader*)pK);
                            *(int*)pK = (int)((char*)r8s->arr[r8i] + j * 8);
                        }
                    }
                }
            }
        }
    }
}


#endif
