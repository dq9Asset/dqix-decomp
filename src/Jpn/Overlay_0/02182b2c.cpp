#if defined(jpn)
#include <globaldefs.h>

struct ListNode021600f8 { char pad[0x20]; struct ListNode021600f8* next; };
struct List021600f8 { char pad0[9]; unsigned char count; char pad1[10]; struct ListNode021600f8* head; };
extern "C" struct ListNode021600f8* func_ov000_02161878(struct List021600f8* list, int index);

struct ListNode02160094 { char pad[0x30]; struct ListNode02160094* next; };
struct List02160094 { char pad0[8]; unsigned char count; char pad1[7]; struct ListNode02160094* head; };
extern "C" struct ListNode02160094* func_ov000_02161814(struct List02160094* list, int index);

extern "C" int func_ov000_02161720(struct ListNode021600f8* node);

// JPN: func_ov000_02182b2c  (semantic: GetListFieldBySelector_02182b2c)
extern "C" ARM int func_ov000_02182b2c(int selector, int index, void* list, int* out) {
    switch (selector) {
    case 0: {
        struct List021600f8* l = (struct List021600f8*)list;
        if (l->count < index + 1) return 0;
        struct ListNode021600f8* node = func_ov000_02161878(l, index);
        *out = *(short*)((char*)node + 0xe);
        return 1;
    }
    case 1: {
        struct List02160094* l = (struct List02160094*)list;
        if (l->count < index + 1) return 0;
        struct ListNode02160094* node = func_ov000_02161814(l, index);
        *out = *(unsigned short*)((char*)node + 0x20);
        return 1;
    }
    case 2: {
        struct List021600f8* l = (struct List021600f8*)list;
        if (l->count < index + 1) return 0;
        struct ListNode021600f8* node = func_ov000_02161878(l, index);
        *out = func_ov000_02161720(node);
        return 1;
    }
    }
    return 0;
}

#endif
