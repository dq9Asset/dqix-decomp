#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/CharacterCreationUI.h"

struct Struct_0205ba68;
void SetupPointerTable0205ba68(Struct_0205ba68*, int, int, int);
struct Node0205bacc;
void SetField0AndPropagate0205bacc(Node0205bacc*, int);
struct Struct_0205bcdc;
void SetIndexIfValid0205bcdc(Struct_0205bcdc*, int);
extern "C" void func_0205bb04(void*, int);
struct Struct0200fb08;
unsigned char NormalizeField5_0200fb08(Struct0200fb08*);
extern "C" void func_ov023_021da100(char*, char*, int);
#if defined(jpn)
extern "C" void func_0205d304(void*, void*, int, int, int, int, int);
#else
extern "C" void func_0205d304(void*, void*, int, int, int, int, int, int);
#endif

// USA: func_ov023_021d9f88
extern "C" ARM void func_ov023_021d9f88(void* objRaw) {
    CharacterCreationUI* self = (CharacterCreationUI*)objRaw;
    self->selection = 0;
    SetupPointerTable0205ba68((Struct_0205ba68*)self->windows[1].frame, 1, 2, 0);
    SetupPointerTable0205ba68((Struct_0205ba68*)self->windows[1].cursor, 1, 2, 0);
    SetField0AndPropagate0205bacc((Node0205bacc*)self->windows[1].frame, 2);
    SetField0AndPropagate0205bacc((Node0205bacc*)self->windows[1].cursor, 2);
    self->windows[1].frame[1] = 1;
    self->windows[1].cursor[1] = 1;
    signed char cursor = self->selection;
    SetIndexIfValid0205bcdc((Struct_0205bcdc*)self->windows[1].frame, cursor);
    func_0205bb04(self->windows[1].cursor, cursor);
    self->windows[1].unknown94[0] = 1;
    self->windows[1].unknown94[1] = 1;

#if defined(jpn)
    int val = 0xe;
    self->windows[1].layout[0] = 7;
    self->windows[1].layout[1] = 5;
    self->windows[1].layout[2] = 0x18;
    self->windows[1].layout[3] = 0xa;
    self->windows[1].layout[4] = val;
    self->windows[1].layout[5] = 0;
    self->windows[1].layout[6] = 0xc;
    self->windows[1].layout[7] = 0x10;
    self->windows[1].nextWindow = 1;
    self->windows[1].fontHeight = 0xc;
    self->windows[1].flags = 1;
    self->windows[1].noHorizontalInset = 0;
    memset(self->textBuffer, 0, 0x800);
    func_ov023_021da100((char*)self, self->textBuffer, 0);
    func_0205d304(&self->windows[1], self->textBuffer, 0, 0, 0, 0, 0);
#else
    int val = 0x10;
    unsigned char norm = NormalizeField5_0200fb08((Struct0200fb08*)GameState::GetInstance());
    switch (norm) {
        case 2: val = 0xe; break;
        case 4: val = 0x15; break;
        case 3: val = 0xa; break;
        case 5: val = 0x15; break;
        default: break;
    }
    CreationWindow* tag = &self->windows[1];
    tag->layout[0] = 6;
    tag->layout[1] = 5;
    tag->layout[2] = 0x1a;
    tag->layout[3] = 0xa;
    tag->layout[4] = val;
    tag->layout[5] = 0;
    tag->layout[6] = 0xc;
    tag->layout[7] = 0x10;
    tag->nextWindow = 1;
    tag->fontHeight = 0xc;
    tag->flags = 1;
    tag->noHorizontalInset = 0;
    void* buf = self->textBuffer;
    memset(buf, 0, 0x960);
    func_ov023_021da100((char*)self, (char*)buf, 0);
    func_0205d304(tag, buf, 0, 0, 0, 0, 0, 1);
#endif
}
