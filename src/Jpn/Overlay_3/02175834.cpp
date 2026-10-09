#if defined(jpn)
#include <globaldefs.h>

struct Obj2081;
extern "C" void func_02081720(struct Obj2081* obj, int key);
extern "C" void func_02081768(void* obj, int id, int value);
extern "C" void func_02081654(void* obj, int id);
extern "C" void func_02081130(void* obj, int id);
extern "C" void func_02081c0c(void* obj, int id, int flag);

struct Container020dedd0;
struct Element020de650;
extern "C" struct Element020de650* func_020e0868(struct Container020dedd0* c, int key);
extern "C" unsigned int func_ov003_021748e0(char* obj, void* s);

extern "C" void func_0208129c(void* obj, int id, short value);
extern "C" int func_02081640(void* obj, int id);

struct Arg1_0217818c;


struct Container02080f8c;
extern "C" void func_02081a8c(struct Container02080f8c* obj, int id, int value);
struct Container02080fa8;
extern "C" void func_02081aa8(struct Container02080fa8* obj, int id, int value);

extern "C" void func_020811ec(void* obj, int id);
extern "C" int func_02081cf0(void* obj, int id);

// JPN: func_ov003_02175834
extern "C" ARM int func_ov003_02175834(char* self) {
    struct Obj2081* o = *(struct Obj2081**)(self + 0x818);
    short id0 = 7;
    short id1 = 13;
    short id2 = 19;

    func_02081720(o, 3);
    func_02081768(o, 3, 0);
    func_02081654(o, 3);
    func_02081130(o, 3);

    unsigned short flags1046 = *(unsigned short*)(self + 0xfc2);
    func_02081c0c(o, 3, (flags1046 & 0x400) != 0);

    short mult = *(short*)(self + 0xf90);
    unsigned char bound;
    unsigned char idx = mult * 6;
    bound = idx + 6;

    for (; idx < bound; ) {
        int local1 = 0;
        unsigned int local2 = 0;
        unsigned char limit = *(unsigned char*)(self + 0x7b1);
        if (idx < limit) {
            short key = *(short*)(self + 0x7c4 + idx * 2);
            struct Element020de650* elem = func_020e0868((struct Container020dedd0*)(self + 0x7f0), key);
            if (elem != NULL) {
                local1 = *(unsigned int*)((char*)elem + 4);
                local2 = func_ov003_021748e0(self, elem);
                func_0208129c(o, id0, 0xc);
                func_02081640(o, id0);
                func_02081640(o, id1);
                func_02081640(o, id2);
            }
            func_02081a8c((struct Container02080f8c*)o, id0, local1);
            func_02081aa8((struct Container02080fa8*)o, id1, local2);
            func_020811ec(o, id0);
        }
        id0 = id0 + 1;
        id1 = id1 + 1;
        id2 = id2 + 1;
        idx = idx + 1;
    }

    func_02081640(o, 0x19);
    func_02081640(o, 0x1a);
    func_02081640(o, 0x1b);
    func_02081aa8((struct Container02080fa8*)o, 0x19, *(short*)(self + 0xf90) + 1);
    func_02081aa8((struct Container02080fa8*)o, 0x1a, *(short*)(self + 0xf92));
    return func_02081cf0(o, 3);
}

#endif
