#include <globaldefs.h>
#include <Resource/MessageSystem.h>
#include <Resource/MessageUpdate.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);
extern unsigned short data_02114e30;

// USA: func_02045740
ARM void HandleRepeatInput02045740(MessageSystem* self) {
    int poll = self->w94c[3];
    self->w94c[3] = (poll + 1) & 0x1f;
    if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x40)) {
        int c = self->w94c[2] - 1;
        self->w94c[2] = c;
        if (c < 0) {
            self->w94c[2] = self->w9a4 - 1;
        }
        self->w994 = self->w94c[2];
        self->w94c[3] = 0;
        return;
    }
    if (!TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x80)) {
        return;
    }
    self->w94c[2] = self->w94c[2] + 1;
    if (self->w94c[2] >= self->w9a4) {
        self->w94c[2] = 0;
    }
    self->w994 = self->w94c[2];
    self->w94c[3] = 0;
}
