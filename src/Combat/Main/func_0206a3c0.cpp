#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/EntryGetterTypes.h"
#include "std_library_functions.h"

#if defined(jpn)
#define func_0206a3c0 func_0206bed8
#define func_02042b98 func_02043270
#define data_020f0934 data_020f0a2c
#define data_020f093d data_020f0a54
#define data_020f0943 data_020f0a5a
#define data_020f0949 data_020f0abb
#define data_020f0950 data_020f0ac2
#define data_020f0956 data_020f0ac8
#define data_020f095c data_020f0ace
#define data_020f0963 data_020f0ad5
#define data_020f096a data_020f0adc
#define data_020f0972 data_020f0ae4
extern const char data_020e88a5[][3];
extern const unsigned short data_020e884a[];
extern "C" int func_02001aec(const void*, const void*, unsigned int);
#endif

struct EntryList_203dce4;
struct Node020406f8;
struct Obj0205eaa0;
struct Vec3_020406f8 { int v[3]; };
EntryList_203dce4* GetGlobalPtr021075f4_0203cf4c();
Entry_203dce4* GetEntryUnlessFlag0x8000_0203dce4(EntryList_203dce4*, int);
void SelectVec3FromSources020406f8(Vec3_020406f8*, Node020406f8*);
int IsPrefixMatch020d857c(signed char*, signed char*);
int StringStartsWithCI020d85dc(const char*, const char*);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
extern Obj0205eaa0 data_02108760;
extern "C" int func_02005a94(const char*);
extern "C" void func_02042b98(void*, int, int, int, int);
extern const char data_020f0934[], data_020f093d[], data_020f0943[], data_020f0949[];
extern const char data_020f0950[], data_020f0956[], data_020f095c[], data_020f0963[];
extern const char data_020f096a[], data_020f0972[];

struct TextState0206a3c0
{
#if defined(jpn)
    char pad0[0x708];
#else
    char pad0[0x838];
#endif
    int entryId;
    int defaultAngle;
    int field840;
    int angle;
    char pad848[0x18];
    int width;
    int height;
    char pad868[0x14];
    unsigned short color;
#if defined(jpn)
    char pad87e[0x39];
#else
    char pad87e[0xdb];
#endif
    unsigned char wait;
    char pad95a[2];
    unsigned char variant;
#if defined(jpn)
    char pad95d[0x56];
#else
    char pad95d[0x54];
#endif
    unsigned char flag9b1;
    char pad9b2[4];
    unsigned char active;
    unsigned char animation;
    unsigned char flag9b8;
    char pad9b9[2];
    unsigned char flag9bb;
};
struct TextOwner0206a3c0
{
#if defined(jpn)
    char pad0[0x874];
#else
    char pad0[0x9a4];
#endif
    int repeat;
#if defined(jpn)
    char pad9a8[0x788];
#else
    char pad9a8[0x658];
#endif
    TextState0206a3c0 state;
};

// JPN: func_0206bed8
// USA: func_0206a3c0
extern "C" ARM const char* func_0206a3c0(TextOwner0206a3c0* self, const char* text)
{
    unsigned char scanning = 1;
    self->state.active = (unsigned char)scanning;
    GameObject* object = GameState::GetInstance()->GetUnknownGameObject();
    Entry_203dce4* entry = GetEntryUnlessFlag0x8000_0203dce4(GetGlobalPtr021075f4_0203cf4c(), self->state.entryId);
    if (object != NULL && entry != NULL)
    {
        Vec3_020406f8 original;
        Vec3_020406f8 target;
        Vec3_020406f8 selected;
        original = *(Vec3_020406f8*)&object->obj3D_.position_;
        SelectVec3FromSources020406f8(&selected, (Node020406f8*)entry);
        target = selected;
        self->state.angle = fix32ReduceAngle0To2Pi(fix32_Atan2(original.v[0] - target.v[0], original.v[2] - target.v[2]));
        self->state.active = 1;
    }
    self->state.wait = 0;
    self->state.animation = 0;
    while (scanning)
    {
        if (IsPrefixMatch020d857c((signed char*)text, (signed char*)data_020f0934))
        {
            self->state.angle = self->state.defaultAngle;
            self->state.active = 0;
            text += 8;
        }
        else if (IsPrefixMatch020d857c((signed char*)text, (signed char*)data_020f093d))
        {
            self->state.wait = 60;
            self->state.animation = 1;
            self->state.variant = 0;
            text += 5;
            DispatchWithShortB4_0205eaa0(&data_02108760, 6, 0);
        }
        else if (IsPrefixMatch020d857c((signed char*)text, (signed char*)data_020f0943))
        {
            self->state.wait = 60;
            self->state.animation = 1;
            self->state.variant = 1;
            text += 5;
            DispatchWithShortB4_0205eaa0(&data_02108760, 28, 0);
        }
        else if (StringStartsWithCI020d85dc(text, data_020f0949))
        {
            unsigned char done;
            int index = 6;
            int close = index;
            done = 0;
            while (text[close] != '>')
            {
                if (text[close] == 0) return text + close;
                close++;
            }
            int x = func_02005a94(text + 6);
            while (text[index] != ',')
            {
                if (text[index] == '>')
                {
                    text += index + 1;
                    done = 1;
                    break;
                }
                index++;
            }
            if (done) return text;
            index++;
            int y = func_02005a94(text + index);
            while (text[index] != ',')
            {
                if (text[index] == '>')
                {
                    text += index + 1;
                    done = 1;
                    break;
                }
                index++;
            }
            if (done) return text;
            index++;
            int width = func_02005a94(text + index);
            while (text[index] != ',')
            {
                if (text[index] == '>')
                {
                    text += index + 1;
                    done = 1;
                    break;
                }
                index++;
            }
            if (done) return text;
            int height = func_02005a94(text + (index + 1));
            if (x < 0) x = 0;
            if (x > 256) x = 256;
            if (y < 0) y = 0;
            if (y > 192) y = 192;
            if (width < 0) width = 256 - x;
            if (width > 256) width = 256 - x;
            if (height < 0) height = 192 - y;
            if (height > 192) height = 192 - y;
            func_02042b98(self, x, y, width, height);
            text += close + 1;
        }
        else if (StringStartsWithCI020d85dc(text, data_020f0950))
        {
            self->state.flag9b1 = 0;
            text += 5;
        }
        else if (StringStartsWithCI020d85dc(text, data_020f0956))
        {
            self->state.flag9b8 = 1;
            text += 5;
        }
        else if (StringStartsWithCI020d85dc(text, data_020f095c))
        {
            int index = 6;
            int value = func_02005a94(text + 6);
            while (text[index] != '>')
            {
                if (text[index] == 0) return text + index;
                index++;
            }
            if (value < 1) value = 1;
            self->repeat = value;
            text += index + 1;
        }
        else if (StringStartsWithCI020d85dc(text, data_020f0963))
        {
            int index = 6;
            int close = index;
            while (text[close] != '>')
            {
                if (text[close] == 0) return text + close;
                close++;
            }
            int width = func_02005a94(text + 6);
            if (width <= 0) width = 12;
            while (text[index] != ',')
            {
                if (text[index] == '>')
                {
                    text += index + 1;
                    break;
                }
                index++;
            }
            int height = func_02005a94(text + (index + 1));
            if (height <= 0) height = 16;
            self->state.width = width;
            self->state.height = height;
            text += close + 1;
        }
        else if (StringStartsWithCI020d85dc(text, data_020f096a))
        {
            int index = 7;
            int close = index;
            while (text[close] != '>')
            {
                if (text[close] == 0) return text + close;
                close++;
            }
            unsigned char done = 0;
#if defined(jpn)
            char name[3] = {};
            signed char colorIndex = 0;
            memcpy(name, text + 7, 2);
            for (; data_020e88a5[colorIndex][0]; colorIndex++) {
                if (func_02001aec(name, data_020e88a5[colorIndex], 2) == 0) {
                    self->state.color = data_020e884a[colorIndex];
                    text += close + 1;
                    done = 1;
                    break;
                }
            }
            if (done) continue;
#endif
            int red = func_02005a94(text + 7);
            if (red < 0) red = 255;
            if (red > 255) red = 255;
            while (text[index] != ',')
            {
                if (text[index] == '>')
                {
                    text += index + 1;
                    done = 1;
                    break;
                }
                index++;
            }
            if (done) continue;
            index++;
            int green = func_02005a94(text + index);
            if (green < 0) green = 255;
            if (green > 255) green = 255;
            while (text[index] != ',')
            {
                if (text[index] == '>')
                {
                    text += index + 1;
                    done = 1;
                    break;
                }
                index++;
            }
            if (done) continue;
            int blue = func_02005a94(text + (index + 1));
            if (blue < 0) blue = 255;
            if (blue > 255) blue = 255;
            self->state.color = (red >> 3) | ((green >> 3) << 5) | ((blue >> 3) << 10);
            text += close + 1;
        }
        else if (StringStartsWithCI020d85dc(text, data_020f0972))
        {
            self->state.flag9bb = 0;
            text += 6;
        }
        else scanning = 0;
    }
    return text;
}

#if defined(jpn)
#undef func_0206a3c0
#undef func_02042b98
#undef data_020f0934
#undef data_020f093d
#undef data_020f0943
#undef data_020f0949
#undef data_020f0950
#undef data_020f0956
#undef data_020f095c
#undef data_020f0963
#undef data_020f096a
#undef data_020f0972
#endif
