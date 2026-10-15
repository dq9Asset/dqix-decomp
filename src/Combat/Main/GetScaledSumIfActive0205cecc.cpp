#include <globaldefs.h>
#include "Resource/MessageSystem.h"

// USA: func_0205cecc
ARM int GetScaledSumIfActive0205cecc(MessageChoicePanel* s) {
    if (CheckActive0205bd20(
            &s->channels.first, 1) == 0) {
        return -1;
    }
    return GetActiveScaledSum0205c570(&s->channels);
}
