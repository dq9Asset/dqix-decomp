#include <globaldefs.h>
#include "GameState/GameState.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

struct ShortArrays0204c610 {
    u8 pad0[0xc];
    short x[18];
    short y[18];
    short width[18];
    short height[18];
};
struct Elem_0205d81c : ShortArrays0204c610 {
    u8 pad9c[0xac - 0x9c];
    short xOrigin;
    short yOrigin;
    u8 padb0[0xc5 - 0xb0];
    u8 flags;
    u8 padc6[0xe0 - 0xc6];
};
struct Struct_0205d81c {
    u8 pad0[0x98];
    int active;
    Elem_0205d81c* entries;
    u8 pada0[0xb3 - 0xa0];
    u8 count;
    u8 selected;
    u8 padb5[3];
};
#if defined(jpn)
enum { WindowOffset = 0xe20, SpriteOffset = 0x19c0, MemberOffset = 0x1b32,
       BlockingKey = 0x1a, PositionsKey = 0x19, FirstIcon = 0x14, SecondIcon = 0x17 };
#else
enum { WindowOffset = 0xec8, SpriteOffset = 0x1a68, MemberOffset = 0x1c6e,
       BlockingKey = 0x19, PositionsKey = 0x18, FirstIcon = 0x12, SecondIcon = 0x15 };
#endif

struct FormationMenu {
    u8 pad0[WindowOffset];
    Struct_0205d81c elements;
    u8 padf80[SpriteOffset - WindowOffset - sizeof(Struct_0205d81c)];
    void* entryList;
    u8 pad1a6c[MemberOffset - SpriteOffset - 4];
    s8 memberIds[5];
    u8 count;
#if !defined(jpn)
    u8 pad1c74[0x245c - 0x1c74];
    short xOffset;
#endif
};
struct FormationCombatStats {
    u8 pad0[0x3c];
    u32 : 30;
    u32 icon : 1;
    u32 : 1;
};
Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c*, int);
void GetFourShortsAtIndex(ShortArrays0204c610*, int, short*, short*, short*, short*);
void SetEntryFields02154bcc(int, int, void*, int, u8, u8);

#if !defined(jpn)
static inline short GetX(Elem_0205d81c* entry) { SDK_NULL_ASSERT(entry); return entry->xOrigin; }
static inline short GetY(Elem_0205d81c* entry) { SDK_NULL_ASSERT(entry); return entry->yOrigin; }
static inline short GetOffset(FormationMenu* self) { SDK_NULL_ASSERT(self); return self->xOffset; }

#endif

static inline int AddOrigin(const short* value, short origin) { SDK_NULL_ASSERT(value); return *value + origin; }
static inline short AddPosition(short offset, short x) { return x + (offset + 3); }

// USA: func_ov002_0215ab60
// JPN: func_ov002_0215bf4c
extern "C" ARM void func_ov002_0215ab60(FormationMenu* self) {
#if !defined(jpn)
    Elem_0205d81c* entry = FindElementByC40205d81c(&self->elements, 0x1a);
    if (entry && !(entry->flags & 0x20)) {
        short y = GetY(entry) * 8;
        short x = GetX(entry) * 8;
        short positionY = y + 3;
        short positionX = AddPosition(GetOffset(self), x);
        SetEntryFields02154bcc(positionX, positionY, self->entryList, 0x2a, 0xc, 0xff);
    }
#endif
    if (!FindElementByC40205d81c(&self->elements, BlockingKey)) {
        Elem_0205d81c* positions = FindElementByC40205d81c(&self->elements, PositionsKey);
        if (positions) {
            GameState* gameState = GameState::GetInstance();
            GetPtrField0x2a04_02010828(gameState);
            u8 count = self->count;
            short originX = positions->xOrigin * 8;
            short originY = positions->yOrigin * 8;
            for (u8 i = 0; i < count; ++i) {
                s8 memberId = self->memberIds[i];
                GameObject* member = gameState->GetPartyMemberByIndex(memberId);
                if (member) {
                    short x, y, width, height;
                    short index = i + count + 1;
                    GetFourShortsAtIndex(positions, index, &x, &y, &width, &height);
                    int positionX = AddOrigin(&x, originX);
                    int positionY = AddOrigin(&y, originY);
                    u16 icon = ((FormationCombatStats*)member->baseStats_)->icon;
                    icon = icon + FirstIcon;
                    SetEntryFields02154bcc(positionX, positionY, self->entryList, icon, (u8)(i + 0x4c), 0xff);
                    GetFourShortsAtIndex(positions, (short)(index + count + 1), &x, &y, &width, &height);
                    SetEntryFields02154bcc(x + originX, y + originY, self->entryList, SecondIcon, (u8)(memberId + 0x50), (u8)(memberId + 9));
                }
            }
        }
    }
}
