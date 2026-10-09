#if defined(jpn)
#include <globaldefs.h>

struct ThreeWords {
    unsigned int first;
    unsigned int second;
    unsigned int third;
};

// JPN: func_ov000_02169290
extern "C" ARM void func_ov000_02169290(ThreeWords* self, unsigned int first, unsigned int second, unsigned int third) {
    self->first = first;
    self->second = second;
    self->third = third;
}

#endif

