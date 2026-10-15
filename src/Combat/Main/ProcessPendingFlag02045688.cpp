#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"

void ForwardToTargetOrDefault0205eabc(void*, void*, int);
extern int data_02108760;
extern int data_02107820;

// USA: func_02045688
ARM void MessageSystem::ProcessPendingFlag02045688() {
    if (this->b19b3 && this->b19b2) {
        ForwardToTargetOrDefault0205eabc(&data_02108760, &data_02107820, 0);
        this->b19b3 = 0;
    }
}
