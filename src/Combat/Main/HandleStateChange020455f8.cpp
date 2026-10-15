#include <globaldefs.h>
#include <Resource/MessageSystem.h>
#include <Resource/MessageUpdate.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);

extern int data_02108760;
extern int data_02107820;

// USA: func_020455f8
ARM void HandleStateChange020455f8(MessageSystem* obj) {
    if (obj->b19b3 == 1 || obj->b19b2 == 0) {
        return;
    }
    switch (obj->state) {
        case 0:
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0xa, (int)&data_02107820);
            break;
        case 1:
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0xc, (int)&data_02107820);
            break;
        case 2:
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0xb, (int)&data_02107820);
            break;
    }
    obj->b19b3 = 1;
}
