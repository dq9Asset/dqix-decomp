#include <globaldefs.h>
#include <Resource/MessageSystem.h>
#include <Resource/MessageUpdate.h>

struct EntryList_203dce4;
struct Entry_203dce4;
void* GetGlobalPtr021075f4_0203cf4c(void);
Entry_203dce4* GetEntryUnlessFlag0x8000_0203dce4(EntryList_203dce4* list, int id);

// USA: func_02065758
ARM int UpdateCounterAndFlag02065758(MessageSystem* a, int b) {
    Entry_203dce4* entry;
    int result;
    unsigned char amt;

    entry = GetEntryUnlessFlag0x8000_0203dce4((EntryList_203dce4*)GetGlobalPtr021075f4_0203cf4c(), a->selectedEntry);
    if (entry == NULL) {
        return 0;
    }
    if (a->textAnimationActive == 0) {
        return 0;
    }
    amt = (unsigned char)b;
    result = 1;
    if (a->textWaitTicks < amt) {
        a->textWaitTicks = 0;
    } else {
        a->textWaitTicks = a->textWaitTicks - amt;
    }
    if (a->textWaitTicks == 0) {
        result = 0;
        a->textAnimationActive = 0;
    }
    return result;
}
