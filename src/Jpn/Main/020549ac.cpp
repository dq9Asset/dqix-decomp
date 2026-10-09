#if defined(jpn)
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

extern "C" int func_02042940(void);
extern "C" unsigned char func_0200ff0c(GameState* battleStruct);
extern "C" int func_020392cc(void* obj);
extern "C" int func_0205497c(signed char* obj);

// Object3D methods, declared by mangled name like the sibling files in this module.
extern "C" void _ZN8Object3D26RemoveAnimationPackageByIDEi(void* obj, int packageId);
extern "C" int _ZNK8Object3D19HasAnimationStoppedEv(void* obj);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void* obj);

extern "C" void func_02054568(void* obj);
extern "C" int _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void* obj, void* loadInfo, void* animCallback);
extern "C" int _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* obj, const char* name, int flags);
extern "C" void* func_02012dac(void);
extern "C" void func_0205445c(void* obj, int val);
extern "C" void* func_0205ff20(void);
extern "C" void func_020708dc(void* p);

struct Obj0205eaa0;
extern "C" void func_0205fd8c(struct Obj0205eaa0* obj, int a, int b);

extern "C" void func_0205fda8(void* obj, void* target, int arg);
extern "C" int func_02065d88(void* param0, void* param1);
extern "C" int func_0200ff54(char* obj);
extern "C" int func_020121c0(unsigned short* obj, int mask);
extern "C" void func_ov017_021cc798(int a0);
extern "C" void func_020a4618(unsigned char* obj, unsigned char mask);
extern "C" void func_020a4628(unsigned char* obj, int mask);

struct Params02036804 {
    int flag;
    void* data;
    unsigned int size;
    void* alloc;
    int one;
    int pad18;
    int pad1c;
    int pad20;
};

struct Entry02053634 { short id; short kind; };
extern struct Entry02053634 data_020e866c[];

extern char data_020f04e4;
extern char data_020f04eb;
extern int data_021086a4;
extern char data_020f04ee;
extern unsigned short data_02114ad0;
extern char data_020f04f3;

// JPN: func_020549ac
extern "C" ARM void func_020549ac(void* obj) {
    char* ctx = (char*)obj;
    GameState* bs = GameState::GetInstance();

    int hasEntries0 = ctx[0x170] > 0 ? 1 : 0;
    if (hasEntries0 != 0) {
        short cid0 = *(short*)(ctx + 4);
        int activeCid0 = func_0200ff0c(bs);
        if (activeCid0 == cid0
            && ((unsigned char*)func_02042940())[0x17e1] != 0) {
            func_02054568(ctx);
            return;
        }
    }

    GameObject* combatant = bs->GetPartyMemberByIndex(*(short*)(ctx + 4));
    int hasEntries = ctx[0x170] > 0 ? 1 : 0;
    if (hasEntries != 0) {
        if (func_020392cc(combatant) > 0) {
            func_02054568(ctx);
            return;
        }
    }

    signed char state = ctx[0x172];
    if (state == 0) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(*(int*)(ctx + 0x174)) == 0) {
            return;
        }
        if (*(int*)(ctx + 0x188) >= 0) {
            if (loader->GetTaskStatus(*(int*)(ctx + 0x188)) == 0) {
                return;
            }
        }

        int moreAvailable = 0;
        if (loader->GetDetailedTaskStatus(*(int*)(ctx + 0x174)) != 2) {
            goto detailFail;
        }
        {
        _ZN8Object3D26RemoveAnimationPackageByIDEi(ctx, 2);
        void* filePtr;
        unsigned int fileLen;
        loader->GetLoadedFileByID(*(int*)(ctx + 0x174), &filePtr, &fileLen);
        if (filePtr != 0) {
            void* base = *(void**)(ctx + 0x148);
            void* alloc = (char*)base + 0x554;
            ((SafeAllocator*)alloc)->Reset();

            struct Params02036804 params;
            params.data = filePtr;
            params.flag = 0;
            params.pad18 = 0;
            params.pad1c = 0;
            params.size = fileLen;
            params.alloc = alloc;
            params.pad20 = 2;
            params.one = 1;
            if (_ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(ctx, &params, 0) == 0) {
                goto loadFail;
            }
            if (_ZN8Object3D24MaybeSetRegularAnimationEPKci(ctx, &data_020f04e4, 1) == 0) {
                if (_ZN8Object3D24MaybeSetRegularAnimationEPKci(ctx, &data_020f04eb, 1) == 0) {
                    func_02054568(ctx);
                    return;
                }
                ctx[0x173] = 1;
            } else {
                ctx[0x173] = 0;
            }

            if (ctx[0x173] == 0) {
                if (ctx[0x171] + 1 < ctx[0x170]) {
                    moreAvailable = 1;
                }
            }

            struct Entry02053634* e = data_020e866c;
            for (; e->id > 0; e++) {
                if (e->id != func_0205497c((signed char*)ctx)) continue;
                void* arg2 = 0;
                if (e->kind == 0x4e) {
                    arg2 = ctx + 0x18c;
                }
                unsigned short val = *(unsigned short*)func_02012dac();
                if (val == _ZNK8Object3D10GetField06Ev(ctx)) {
                    func_0205fd8c((struct Obj0205eaa0*)&data_021086a4, e->kind, (int)arg2);
                }
                break;
            }
            ctx[0x172] = 1;
            goto loadOK;
        loadFail:
            func_02054568(ctx);
            return;
        } else {
            goto loadOK;
        }
    loadOK:
        ctx[0x179] = 1;
        goto detailOK;
    detailFail:
        func_02054568(ctx);
        return;
        }
    detailOK:
        loader->RemoveTask(*(int*)(ctx + 0x174));
        *(int*)(ctx + 0x174) = -1;
        if (moreAvailable != 0) {
            if (*(unsigned char*)(ctx + 0x179) != 0) {
                ctx[0x17a] = 1;
            } else {
                signed char idx = ctx[0x171];
                char* p = ctx + (idx + 1) + 0x100;
                func_0205445c(ctx, p[0x6c]);
            }
        }
    } else {
        if (state == 1) {
            if (_ZNK8Object3D19HasAnimationStoppedEv(ctx) == 0) {
                return;
            }
            if (ctx[0x173] == 0) {
                ctx[0x171] = ctx[0x171] + 1;
                if (ctx[0x171] < ctx[0x170]) {
                    ctx[0x172] = 0;
                    *(int*)(ctx + 0x184) = 0;
                    return;
                }
                short cid = *(short*)(ctx + 4);
                if (cid == func_0200ff0c(bs)) {
                    void* p = func_0205ff20();
                    unsigned char req[0x34];
                    for (int i = 0; i < 4; i++) {
                        char* q = ctx + i;
                        q = q + 0x100;
                        ((signed char*)(req + 0x2a))[i] = q[0x6c];
                    }
                    if (func_02065d88(p, req) != 0) {
                        func_020708dc(req);
                    }
                }
                func_02054568(ctx);
                return;
            } else if (ctx[0x173] == 1) {
                int mode = 0;
                if (ctx[0x170] > 1) {
                    mode = 1;
                    if (func_0205497c((signed char*)ctx) == 0x19) {
                        func_0205fda8((void*)&data_021086a4, ctx + 0x18c, 0);
                    }
                }
                if (_ZN8Object3D24MaybeSetRegularAnimationEPKci(ctx, &data_020f04ee, mode) != 0) {
                    ctx[0x172] = 2;
                    return;
                }
                func_02054568(ctx);
                return;
            } else {
                func_02054568(ctx);
                return;
            }
        } else if (state == 2) {
            bs = GameState::GetInstance();
            int target = func_0200ff54((char*)bs);
            int flag = 0;
            if (ctx[0x170] > 1) {
                if (_ZNK8Object3D19HasAnimationStoppedEv(ctx) != 0) {
                    flag = 1;
                }
            } else {
                short cid = *(short*)(ctx + 4);
                if (cid == func_0200ff0c(bs)
                    && func_020121c0(&data_02114ad0, 0xc03) != 0) {
                    flag = 1;
                    func_ov017_021cc798(*(short*)(ctx + 4));
                } else {
                    if (*(unsigned char*)(ctx + 0x178) != 0) {
                        ctx[0x178] = *(unsigned char*)(ctx + 0x178) - 1;
                        flag = 1;
                    } else if (target != 0) {
                        func_020a4618((unsigned char*)target, 1);
                    }
                }
                if (flag != 0 && target != 0) {
                    func_020a4628((unsigned char*)target, 1);
                }
            }
            if (flag == 0) {
                return;
            }
            if (_ZN8Object3D24MaybeSetRegularAnimationEPKci(ctx, &data_020f04f3, 1) == 0) {
                func_02054568(ctx);
                return;
            }
            {
                signed char cursor = ctx[0x171];
                signed char count = ctx[0x170];
                int next = cursor + 1;
                if (next < count) {
                    char* q = ctx + next;
                    q = q + 0x100;
                    func_0205445c(ctx, q[0x6c]);
                }
            }
            ctx[0x172] = 3;
            return;
        } else if (state == 3) {
            if (_ZNK8Object3D19HasAnimationStoppedEv(ctx) == 0) {
                return;
            }
            if (func_0205497c((signed char*)ctx) == 0x19) {
                func_0205fda8((void*)&data_021086a4, ctx + 0x18c, 0);
            }
            ctx[0x171] = ctx[0x171] + 1;
            if (ctx[0x171] < ctx[0x170]) {
                ctx[0x172] = 0;
                *(int*)(ctx + 0x184) = 0;
                return;
            }
            short cid = *(short*)(ctx + 4);
            if (cid == func_0200ff0c(bs)) {
                void* p = func_0205ff20();
                unsigned char req[0x34];
                for (int i = 0; i < 4; i++) {
                    char* q = ctx + i;
                    q = q + 0x100;
                    ((signed char*)(req + 0x2a))[i] = q[0x6c];
                }
                if (func_02065d88(p, req) != 0) {
                    func_020708dc(req);
                }
            }
            func_02054568(ctx);
            return;
        }
    }
}


#endif
