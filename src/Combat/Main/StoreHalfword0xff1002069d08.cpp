#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "std_library_functions.h"


int* GetGlobal02109418_02094d6c(void);
struct FindTableIndexOrFFData;
unsigned char FindTableIndexOrFF_020965c0(struct FindTableIndexOrFFData *s, unsigned int val);

// USA: func_02069d08
ARM int StoreHalfword0xff1002069d08(char** obj, const char* value) {
    int local;
    func_020696bc(value, &local, 1);
    unsigned char idx = FindTableIndexOrFF_020965c0((struct FindTableIndexOrFFData*)GetGlobal02109418_02094d6c(), local & 0xff);
    GetGlobalField0x1c020421a0()->pendingActorId = idx;
    void* d = *obj;
    unsigned short v = 0xff10;
    memcpy(d, &v, 2);
    return 2;
}
