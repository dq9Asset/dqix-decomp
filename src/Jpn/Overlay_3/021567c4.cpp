#if defined(jpn)
#include <globaldefs.h>

struct Outer020e28dc;

struct Menu {
    char unk_0[0x2a];
    short cursor_;
};

extern unsigned short data_02114ad0;
extern unsigned char data_02114af4;

extern "C" int func_020121c0(unsigned short* obj, int mask);
extern "C" int func_020e447c(struct Outer020e28dc* o);
extern "C" int func_020e44b8(signed char* param);
extern "C" void func_0201284c(unsigned char* obj, int* out1, int* out2);
extern "C" int func_020818d4(void* obj, int p1, int unused2, int unused3, unsigned char* outFlag, unsigned char extra);
extern "C" void func_02081cf0(void* obj, int key);

struct Ctx021567c4 {
    char unk_0[0x8];
    short* cursor_;
    char unk_c[0x18 - 0xc];
    Menu* menu_;
    Outer020e28dc* choice_;
    char unk_20[0x1e2 - 0x20];
    short group_;
    short previousCursor_;
};

// JPN: func_ov003_021567c4
extern "C" ARM unsigned char func_ov003_021567c4(Ctx021567c4* self) {
    unsigned char confirmed = 0;
    if (func_020121c0(&data_02114ad0, 0x401)) {
        confirmed = 1;
    }
    if (self->choice_ != NULL && func_020e447c(self->choice_)) {
        int choice = func_020e44b8((signed char*)self->choice_);
        if (choice >= 0) {
            confirmed = 1;
            *self->cursor_ = choice + 6;
        }
    } else if ((&data_02114af4)[0x55] != 0 && self->cursor_ != NULL) {
        Menu* menu = self->menu_;
        int x, y;
        func_0201284c(&data_02114af4, &x, &y);
        self->previousCursor_ = *self->cursor_;
        int item = func_020818d4(menu, self->group_, (short)x, (short)y, &confirmed, 1);
        if (item < 0) {
            return 0;
        }
        *self->cursor_ = item;
        short cursor = *self->cursor_;
        if (self->previousCursor_ != cursor) {
            menu->cursor_ = cursor;
            func_02081cf0(menu, self->group_);
        }
    }
    return confirmed;
}

#endif
