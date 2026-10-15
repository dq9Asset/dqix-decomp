#include <globaldefs.h>
#include <System/Matrix.h>

int fix32sin(int);
int fix32abs(int);

struct Obj02015cd0 {
    char pad0[0xe];
    short angle;
    unsigned short counter;
    char pad12[6];
    unsigned char special;
};

// USA: func_02015cd0
extern "C" ARM int func_02015cd0(Obj02015cd0* self) {
    if (self->special == 0) {
        unsigned short counter = self->counter;
        int firstDuration = 0xbff4;
        if ((float)counter <= (float)firstDuration / 4096.0f) {
            int square = (self->counter * self->counter) << 12;
            int coefficient = fix32_Divide(-0x800, 0x8fee0);
            self->angle = FIX32_MULTIPLY(coefficient, square) + 0x4800;
            self->counter = self->counter + 1;
        } else {
            int totalDuration = 0x17fe8;
            if ((float)counter <= (float)totalDuration / 4096.0f) {
                int elapsed = (int)(4096.0f * ((float)counter - (float)firstDuration / 4096.0f));
                int remaining = 0x1000 - fix32_Divide(elapsed, 0x17fe8);
                int coefficient = fix32_Divide(0xc90f, 0x17fe8);
                int angle = FIX32_MULTIPLY(coefficient, elapsed);
                if (angle > 0x647a) angle = 0x647a;
                int correction = FIX32_MULTIPLY(fix32sin(angle), 0x101);
                self->angle = FIX32_MULTIPLY(correction, remaining) + 0x4000;
                self->counter = self->counter + 1;
            } else {
                return 1;
            }
        }
    } else if (self->special == 1) {
        if (self->counter == 0) {
            int delta = FIX32_MULTIPLY(0x647a - self->angle, 0x333);
            self->angle += delta;
            if (fix32abs(delta) < 4) {
                self->angle = 0x647a;
                self->counter = self->counter + 1;
                return 1;
            }
        } else {
            return 1;
        }
    }
    return 0;
}
