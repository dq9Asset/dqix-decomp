#if defined(jpn)
#include <globaldefs.h>

struct DispatchObj020a0dec {
    int selector;
};

extern "C" int func_020a2e20(int*);
extern "C" void func_020a2b64(struct DispatchObj020a0dec*);
extern "C" void func_0202e404(void*, int);
int fix32ReduceAngle0To2Pi(int);

struct Obj0202ea84 {
    char pad[0x168];
};

typedef void (Obj0202ea84::*DispatchFn0202ea84)(void*);

struct DispatchTable0202ea84 {
    DispatchFn0202ea84 fns[3];
};

extern const DispatchTable0202ea84 data_020e7d10;
extern const DispatchTable0202ea84 data_020e7d28;

// JPN: func_0202ea84
extern "C" ARM void func_0202ea84(struct Obj0202ea84* self) {
    char* obj = (char*)self;
    unsigned int flags = *(unsigned int*)(obj + 0x168);
    struct DispatchObj020a0dec* arr[3];
    arr[0] = (struct DispatchObj020a0dec*)(obj + 0x16c);
    arr[1] = (struct DispatchObj020a0dec*)(obj + 0x194);
    arr[2] = (struct DispatchObj020a0dec*)(obj + 0x1bc);

    int i;
    if (flags & 2) {
        struct DispatchTable0202ea84 table = data_020e7d28;
        for (i = 0; i < 3; i++) {
            if (func_020a2e20((int*)arr[i])) {
                func_020a2b64(arr[i]);
                void* arg = (void*)((char*)arr[i] + 4);
                (self->*table.fns[i])(arg);
            }
        }
    } else {
        struct DispatchTable0202ea84 table = data_020e7d10;
        for (i = 0; i < 3; i++) {
            if (func_020a2e20((int*)arr[i])) {
                func_020a2b64(arr[i]);
                void* arg = (void*)((char*)arr[i] + 4);
                (self->*table.fns[i])(arg);
            }
        }
    }

    if (*(unsigned short*)(obj + 0x1ee) != 0) {
        *(unsigned short*)(obj + 0x1ee) -= 1;
        *(unsigned short*)(obj + 0x7c) = (unsigned short)(*(short*)(obj + 0x7c) + *(short*)(obj + 0x1ec));
    }

    if (*(unsigned short*)(obj + 0x210) != 0) {
        *(unsigned short*)(obj + 0x210) -= 1;
        func_0202e404(obj, *(short*)(obj + 0x20e));
    }

    if (*(unsigned short*)(obj + 0x216) != 0) {
        *(unsigned short*)(obj + 0x216) -= 1;
        *(unsigned short*)(obj + 0x212) = (unsigned short)fix32ReduceAngle0To2Pi(*(short*)(obj + 0x212) + *(short*)(obj + 0x214));
    }
}

#endif
