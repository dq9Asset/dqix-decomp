#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c;
struct ShortArrays0204c654;

struct Offsets_0216c98a {
    short v[4];
};

struct Elem_0205d81c *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);
void SetEntryFields02154bcc(int a, int b, void *obj, int idx, unsigned char arg5, unsigned char arg6);
void SetFourShortsAtIndex(ShortArrays0204c654 *arr, int idx, short a, short b, short c, short d);

#if defined(jpn)
enum { WindowOffset = 0xe20, SpriteOffset = 0x19c0, SelectionOffset = 0x1ace,
       GridKey = 0x1d, LabelKey = 0x1e, FirstTile = 0x18, CursorTile = 0x13, LabelTile = 0x16 };
#define data_ov002_0216c98a data_ov002_0216cfe6
#else
enum { WindowOffset = 0xec8, SpriteOffset = 0x1a68, SelectionOffset = 0x1c06,
       GridKey = 0x1c, LabelKey = 0x1d, FirstTile = 0x16, CursorTile = 0x11, LabelTile = 0x14 };
#endif
extern Offsets_0216c98a data_ov002_0216c98a;

// USA: func_ov002_0215ad70
// JPN: func_ov002_0215c0d8
extern "C" ARM void func_ov002_0215ad70(unsigned char *obj) {
    struct Elem_0205d81c *elem =
        FindElementByC40205d81c((struct Struct_0205d81c *) (obj + WindowOffset), GridKey);
    if (elem == 0) {
        return;
    }
    int baseX             = (short) (*(short *) ((char *) elem + 0xac) * 8);
    int baseY             = (short) (*(short *) ((char *) elem + 0xae) * 8);
    Offsets_0216c98a offs = data_ov002_0216c98a;
    unsigned char k       = 0;
    unsigned short tile   = FirstTile;
    for (unsigned char row = 0; row < 4; row++) {
        for (unsigned char col = 0; col < 4; col++) {
            short idx;
            int py;
            short dx;
            dx       = offs.v[col];
            short dy = offs.v[row];
            short px = (short) (dx + baseX);
            py       = (short) (dy + baseY);
            SetEntryFields02154bcc(px, py, *(void **) (obj + SpriteOffset), tile++, (unsigned char) (k * 4 + 0xc),
                                              0xff);
            idx = (short) (col + row * 4);
            if (*(short *) (obj + SelectionOffset) == idx) {
                SetEntryFields02154bcc(px, py, *(void **) (obj + SpriteOffset), CursorTile, 8, 0xff);
            }
            SetFourShortsAtIndex((ShortArrays0204c654 *) elem, idx, dx, dy, 0x18, 0x18);
            k++;
        }
    }
    elem = FindElementByC40205d81c((struct Struct_0205d81c *) (obj + WindowOffset), LabelKey);
    if (elem == 0) {
        return;
    }
    int x2 = *(short *) ((char *) elem + 0xac);
    int y2 = *(short *) ((char *) elem + 0xae);
    x2     = (short) (x2 * 8) + 0x10;
    y2     = (short) (y2 * 8) + 0x18;
    SetEntryFields02154bcc(x2, y2, *(void **) (obj + SpriteOffset), LabelTile, 0x54, 8);
}

#if defined(jpn)
#undef data_ov002_0216c98a
#endif
