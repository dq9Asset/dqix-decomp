#if defined(jpn)
#include <globaldefs.h>

struct ListNode02160094 {
    char pad[0x30];
    struct ListNode02160094* next;
};

struct List02160094 {
    char pad0[8];
    unsigned char count;
    char pad1[7];
    struct ListNode02160094* head;
};
extern "C" struct ListNode02160094* func_ov000_02161814(struct List02160094* list, int index);
extern "C" int func_ov000_0216017c(void* obj, short* buf, int max, int start);
extern "C" int func_ov000_0216039c(void* obj, short* buf, int max, int start);

// JPN: func_ov000_02182d08
extern "C" ARM int func_ov000_02182d08(void* obj, struct List02160094* list, int* outArray) {
    struct ListNode02160094* node = func_ov000_02161814(list, 0);
    short buf[16];
    int n1;
    int i;
    if (node == 0) {
        return 0;
    }
    n1 = 0;
    n1 = n1 + func_ov000_0216017c(obj, buf, 0x10, n1);
    n1 = n1 + func_ov000_0216039c(obj, buf + n1, 0x10 - n1, 0);
    for (i = 0; i < n1; i++) {
        outArray[i] = buf[i];
    }
    return n1;
}

#endif
