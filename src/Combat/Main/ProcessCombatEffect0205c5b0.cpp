#include <globaldefs.h>
#include "Resource/MessageSystem.h"
int CallFunc0205bea0IfFlag0x94(Struct_0205c53c*);
extern "C" void func_0205bb04(Struct_0205ba2c*, int);
void ResetState0205bf3c(Struct_0205bef8*);
void ClearBytes0x4cTo0x4e(Struct_0205bbcc*);
int UpdateActiveState0205bc2c(Struct_0205bbcc*, int);
extern "C" int func_0205bf58(Struct_0205bef8*, unsigned int);
void SetIndexIfValid0205bcdc(Struct_0205bbcc*, int);

// USA: func_0205c5b0  (semantic: ProcessCombatEffect0205c5b0)
extern "C" ARM int func_0205c5b0(Struct_0205c53c* self, unsigned int ticks) {
    int result = 0;
    int field34 = self->first.selectedIndex;

    if (self->field94 != 0) {
        if (CallFunc0205bea0IfFlag0x94(self) != 0) {
            int sum = GetScaledSumIfActive0205bd04(&self->first);
            func_0205bb04(&self->second.base, sum);
            ResetState0205bf3c(&self->second);
            ClearBytes0x4cTo0x4e(&self->first);
            result = 1;
            goto done;
        }
    }

    if (self->field94 != 0) {
        if (UpdateActiveState0205bc2c(&self->first, ticks) != 0) {
            int sum = GetScaledSumIfActive0205bd04(&self->first);
            if (field34 != sum) result = 2;
            func_0205bb04(&self->second.base, sum);
            ResetState0205bf3c(&self->second);
            goto done;
        }
    }

    if (self->field95 != 0) {
        int before = ComputeScaledSum0205bb84(&self->second.base);
        if (func_0205bf58(&self->second, ticks) != 0) {
            int after = ComputeScaledSum0205bb84(&self->second.base);
            if (before != after) {
                result = 1;
                int idx = ComputeScaledSum0205bb84(&self->second.base);
                SetIndexIfValid0205bcdc(&self->first, idx);
                self->first.selectedIndex = -1;
                ClearBytes0x4cTo0x4e(&self->first);
            }
        }
    }

done:
    return result;
}
