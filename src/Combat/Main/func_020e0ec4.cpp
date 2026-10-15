#include <globaldefs.h>
#include "Resource/MessageFrame.h"
#include "GameState/GameState.h"

struct Struct0200fb08;



void InitWeightedEntries02023064(struct Struct02020520* arr, unsigned int count, short* a, short* b, short* c, short* d);
int NormalizeField5_0200fb08(Struct0200fb08*);
extern "C" int func_0205b234(GlyphDestination0205b234*, short, short, const char*, unsigned char, unsigned char);

#if defined(jpn)
extern short data_020ee91a[];
extern short data_020ee92c[];
extern short data_020ee914[];
enum { kEntryCount = 3 };
#else
extern short data_020ee8e8[];
extern short data_020ee8cc[];
extern short data_020ee904[];
extern const short data_020ee820[];
enum { kEntryCount = 14 };
#endif
extern short data_020ee920[];

// JPN: func_020e2ad4
// USA: func_020e0ec4
extern "C" ARM void func_020e0ec4(void* obj, void* buffer, int offset, int) {
    struct Struct02020520 arr[kEntryCount];
#if defined(jpn)
    InitWeightedEntries02023064(arr, kEntryCount, data_020ee920, data_020ee91a, data_020ee92c, data_020ee914);
#else
    InitWeightedEntries02023064(arr, kEntryCount, data_020ee920, data_020ee8cc, data_020ee8e8, data_020ee904);
#endif
    GlyphDestination0205b234 localObj;
    ClearTwoWordsAndByte_0205b20c(&localObj);
    SetField0_0205b220(&localObj, static_cast<unsigned char*>(buffer) + offset);
    SetFieldsAt0x4And0x8_0205b228(&localObj, arr, kEntryCount);

#if defined(jpn)
    func_0205b234(&localObj, (short)44, (short)18, static_cast<char*>(obj) + 0x680, (unsigned char)10, (unsigned char)15);
#else
    int idx = NormalizeField5_0200fb08((Struct0200fb08*)GameState::GetInstance());
    func_0205b234(&localObj, data_020ee820[idx], (short)6, static_cast<char*>(obj) + 0x2ec + 0x400, (unsigned char)0xf, (unsigned char)0);
#endif
}
