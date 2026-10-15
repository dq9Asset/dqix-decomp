#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"

struct MessageSystem;
struct TableA68;
struct StoreStruct;
struct SearchStruct0202c1a4;
struct Container020e0310;

struct ProfileData_021e868c {
    unsigned int year_ : 12;
    unsigned int month_ : 4;
    unsigned int day_ : 5;
    unsigned int unk_0_21 : 4;
    unsigned int female_ : 1;
    unsigned int initialized_ : 1;
    unsigned int designChosen_ : 1;
    unsigned int birthdayChosen_ : 1;
    unsigned int accoladeChosen_ : 1;
    unsigned int vocationAccolade_ : 1;
    unsigned int showBirthday_ : 1;
    unsigned int unk_4_0 : 9;
    int title_ : 10;
    int accolade_ : 11;
    int edited_ : 1;
    unsigned int unk_4_31 : 1;
};

struct PartyMemberData_021e868c {
    char unk_0[0x3c];
    char name_[1];
};

struct ProfileCard_021e868c {
    char unk_0[0x5d8];
    char* text_;
    char unk_5dc[0x5f4 - 0x5dc];
    TableA68* strings_;
#if defined(jpn)
    Container020e0310* vocationStrings_;
#endif
};

struct SaveData_021e868c {
    char unk_0[0x5400];
    ProfileData_021e868c profile_;
};

struct ProfileSaveView_021e868c {
#if defined(jpn)
    char unk_0[0x3c];
#else
    char unk_0[0x29c];
#endif
    SaveData_021e868c save_;
};

static inline ProfileData_021e868c* GetProfile(GameState* gameState)
{
    return &((ProfileSaveView_021e868c*)gameState)->save_.profile_;
}

int GetGlobalField0x1c020421a0();
int CheckField0NonZero_0202b7d8(int* unknown);
PartyMemberData_021e868c* GetFieldAt0x150_02053c6c(unsigned char* member);
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* unknown);
void AppendXTag_02041a28(char* text, int x);
#if defined(jpn)
extern "C" int func_020420e8(char* text, int y);
#define AppendYTag_02041a5c func_020420e8
#else
int AppendYTag_02041a5c(char* text, int y);
#endif
void AppendXYTag_02041a90(char* text, int x, int y);
void AppendNameTag_02041b70(char* text, int item, const char* itemText);
#if defined(jpn)
extern "C" int func_02042638(char* text, int line, int size);
#define AppendFormatted02041fac func_02042638
#else
int AppendFormatted02041fac(char* text, int line, int size);
#endif
void AppendString02042058(char* text, const char* append);
const char* FindEntryByKey_02072a68(TableA68* texts, int id);
void StoreInArray0x8b0_020465c0(StoreStruct* messages, int index, int value);
void SetByteAtIndex_020465d8(unsigned char* messages, int index, unsigned char value);
void SetByteInRange_020465f0(unsigned char* messages, int index, unsigned char digits);

extern "C" {
void* func_0202ae18();
#if defined(jpn)
void func_020474a8(MessageSystem* messages, unsigned char font, const char* format, char* output);
#else
int func_020420e8(const char* text, int large);
void func_02046608(MessageSystem* messages, int a, const char* format, char* output, int size, int b, int c);
#endif
}
#if defined(jpn)
int GetFieldByKey020e0434(Container020e0310* strings, int key);
#endif

// USA: func_ov023_021e868c
// JPN: func_ov023_021e85e0
extern "C" ARM void func_ov023_021e868c(ProfileCard_021e868c* self)
{
    GameState* gameState = GameState::GetInstance();
    MessageSystem* messages = (MessageSystem*)GetGlobalField0x1c020421a0();
    void* unknown = func_0202ae18();
    PartyMemberData_021e868c* data = NULL;
    if (CheckField0NonZero_0202b7d8((int*)unknown) == 0)
    {
        void* member = GetCombatantWithFlag0x100_0200ff1c(gameState, 0);
        if (member != NULL)
            data = GetFieldAt0x150_02053c6c((unsigned char*)member);
    }
    else
    {
        void* member = GetCombatantWithFlag0x100_0200ff1c(gameState, GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)unknown));
        if (member != NULL)
            data = GetFieldAt0x150_02053c6c((unsigned char*)member);
    }
    if (data == NULL)
        return;
    ProfileData_021e868c* profile = GetProfile(gameState);
    char* text = self->text_;
    char buffer[0x20] = {};
#if defined(jpn)
    AppendXTag_02041a28(text, (0xd0 - (strlen(data->name_) * 10 / 2)) / 2);
#else
    AppendXTag_02041a28(text, (0xd0 - func_020420e8(data->name_, 0)) >> 1);
#endif
    AppendFormatted02041fac(text, (int)data->name_, 0x10);
    const char* title = FindEntryByKey_02072a68(self->strings_, (short)(profile->title_ + 10000));
    AppendNameTag_02041b70(text, 0, FindEntryByKey_02072a68(self->strings_, 2));
    AppendString02042058(text, FindEntryByKey_02072a68(self->strings_, 0x6c));
#if defined(jpn)
    int titleX = (0x6e - strlen(title) * 10 / 2) / 2 + 0x56;
    AppendXTag_02041a28(text, titleX);
#else
    AppendXTag_02041a28(text, ((0x6e - func_020420e8(title, 0)) >> 1) + 0x56);
#endif
    AppendString02042058(text, title);
    AppendString02042058(text, FindEntryByKey_02072a68(self->strings_, 0));
    AppendNameTag_02041b70(text, 1, FindEntryByKey_02072a68(self->strings_, 3));
    AppendXTag_02041a28(text, 0x4c);
    AppendString02042058(text, FindEntryByKey_02072a68(self->strings_, 0x6c));
    if (profile->showBirthday_)
    {
        AppendXTag_02041a28(text, 0x5a);
    }
    else
    {
        AppendXYTag_02041a90(text, 0x6e, 0x34);
#if defined(jpn)
        func_020474a8(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x78), buffer);
#else
        func_02046608(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x78), buffer, 0x100, 0, 0);
#endif
        AppendString02042058(text, buffer);
        AppendXYTag_02041a90(text, 0x5a, 0x28);
    }
    if (profile->birthdayChosen_)
    {
        StoreInArray0x8b0_020465c0((StoreStruct*)messages, 0, profile->year_);
        SetByteAtIndex_020465d8((unsigned char*)messages, 0, 1);
        SetByteInRange_020465f0((unsigned char*)messages, 0, 4);
#if defined(jpn)
        const char* yearFormat = FindEntryByKey_02072a68(self->strings_, 0x64);
        func_020474a8(messages, 10, yearFormat, buffer);
#else
        func_02046608(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x64), buffer, 0x100, 0, 0);
#endif
        AppendString02042058(text, buffer);
        memset(buffer, 0, sizeof(buffer));
        StoreInArray0x8b0_020465c0((StoreStruct*)messages, 0, profile->month_);
        SetByteAtIndex_020465d8((unsigned char*)messages, 0, 1);
        SetByteInRange_020465f0((unsigned char*)messages, 0, 2);
#if defined(jpn)
        const char* monthFormat = FindEntryByKey_02072a68(self->strings_, 0x65);
        func_020474a8(messages, 10, monthFormat, buffer);
#else
        func_02046608(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x65), buffer, 0x100, 0, 0);
#endif
        AppendString02042058(text, buffer);
        memset(buffer, 0, sizeof(buffer));
        StoreInArray0x8b0_020465c0((StoreStruct*)messages, 0, profile->day_);
        SetByteAtIndex_020465d8((unsigned char*)messages, 0, 1);
        SetByteInRange_020465f0((unsigned char*)messages, 0, 2);
#if defined(jpn)
        const char* dayFormat = FindEntryByKey_02072a68(self->strings_, 0x66);
        func_020474a8(messages, 10, dayFormat, buffer);
#else
        func_02046608(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x66), buffer, 0x100, 0, 0);
#endif
        AppendString02042058(text, buffer);
        AppendString02042058(text, FindEntryByKey_02072a68(self->strings_, 0));
    }
    else
    {
#if defined(jpn)
        func_020474a8(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x6e), buffer);
#else
        func_02046608(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x6e), buffer, 0x100, 0, 0);
#endif
        AppendString02042058(text, buffer);
        memset(buffer, 0, sizeof(buffer));
#if defined(jpn)
        func_020474a8(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x6f), buffer);
#else
        func_02046608(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x6f), buffer, 0x100, 0, 0);
#endif
        AppendString02042058(text, buffer);
        memset(buffer, 0, sizeof(buffer));
#if defined(jpn)
        func_020474a8(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x70), buffer);
#else
        func_02046608(messages, 10, FindEntryByKey_02072a68(self->strings_, 0x70), buffer, 0x100, 0, 0);
#endif
        AppendString02042058(text, buffer);
        AppendString02042058(text, FindEntryByKey_02072a68(self->strings_, 0));
    }
    int accolade = profile->accolade_;
#if defined(jpn)
    const char* accoladeText;
    if (accolade < 700)
        accoladeText = (const char*)GetFieldByKey020e0434(self->vocationStrings_, (short)accolade);
    else
        accoladeText = FindEntryByKey_02072a68(self->strings_, (short)(accolade + 20000));
#else
    short accoladeId = accolade + 20000;
    if (accolade < 700)
        accoladeId = accolade;
    const char* accoladeText = FindEntryByKey_02072a68(self->strings_, accoladeId);
#endif
    AppendYTag_02041a5c(text, 0x42);
    AppendNameTag_02041b70(text, 2, FindEntryByKey_02072a68(self->strings_, 4));
    AppendXTag_02041a28(text, 0x4c);
    AppendString02042058(text, FindEntryByKey_02072a68(self->strings_, 0x6c));
#if defined(jpn)
    int accoladeX = (0x6e - strlen(accoladeText) * 10 / 2) / 2 + 0x56;
    AppendXTag_02041a28(text, accoladeX);
#else
    AppendXTag_02041a28(text, ((0x6e - func_020420e8(accoladeText, 0)) >> 1) + 0x56);
#endif
    AppendString02042058(text, accoladeText);
    AppendString02042058(text, FindEntryByKey_02072a68(self->strings_, 0));
#if defined(jpn)
    const char* vocation;
    if (profile->designChosen_)
        vocation = FindEntryByKey_02072a68(self->strings_, (short)(profile->unk_0_21 + 30000));
    else
        vocation = FindEntryByKey_02072a68(self->strings_, 0x6d);
#else
    short id = 0x6d;
    if (profile->designChosen_)
        id = profile->unk_0_21 + 30000;
    const char* vocation = FindEntryByKey_02072a68(self->strings_, id);
#endif
    AppendNameTag_02041b70(text, 3, FindEntryByKey_02072a68(self->strings_, 5));
    AppendXTag_02041a28(text, 0x4c);
    AppendString02042058(text, FindEntryByKey_02072a68(self->strings_, 0x6c));
#if defined(jpn)
    int vocationX = (0x6e - strlen(vocation) * 10 / 2) / 2 + 0x56;
    AppendXTag_02041a28(text, vocationX);
#else
    AppendXTag_02041a28(text, ((0x6e - func_020420e8(vocation, 0)) >> 1) + 0x56);
#endif
    AppendString02042058(text, vocation);
}

#if defined(jpn)
#undef AppendYTag_02041a5c
#undef AppendFormatted02041fac
#endif
