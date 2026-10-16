#include <globaldefs.h>

struct Struct02020520 {
    int a;
    short b;
    short c;
    short d;
    short e;
};

struct S_b20c {
    int field0;
    int field4;
    unsigned char field8;
};

void InitWeightedEntries02023064(struct Struct02020520* arr, unsigned int count, short* a, short* b, short* c, short* d);
void ClearTwoWordsAndByte_0205b20c(struct S_b20c* obj);
void SetField0_0205b220(void* obj, int value);
void SetFieldsAt0x4And0x8_0205b228(void* obj, int value, unsigned char flag);
extern "C" int func_0205b234(void*, short, short, int, unsigned char, unsigned char);

#if defined(jpn)
int StringLength_020d2ff0(const char*);
extern short data_020ee980[];
extern short data_020ee938[];
extern short data_020ee950[];
extern short data_020ee968[];
enum { kEntryCount = 12, kY = 7, kDrawFirst = 10, kDrawSecond = 15 };
#else
extern short data_020ee82c[];
extern short data_020ee848[];
extern short data_020ee856[];
extern short data_020ee83a[];
enum { kEntryCount = 7, kY = 2, kDrawFirst = 15, kDrawSecond = 0 };
#endif

// JPN: func_020e29f0
// USA: func_020e0df8
ARM void SetupWeightedEntriesAndSubmit_020e0df8(void* obj, int b, int c, int) {
    struct Struct02020520 arr[kEntryCount];
#if defined(jpn)
    InitWeightedEntries02023064(arr, kEntryCount, data_020ee980, data_020ee938, data_020ee950, data_020ee968);
#else
    InitWeightedEntries02023064(arr, kEntryCount, data_020ee82c, data_020ee848, data_020ee856, data_020ee83a);
#endif
    struct S_b20c localObj;
    ClearTwoWordsAndByte_0205b20c(&localObj);
    SetField0_0205b220(&localObj, b + c);
    SetFieldsAt0x4And0x8_0205b228(&localObj, (int)arr, kEntryCount);
#if defined(jpn)
    func_0205b234((void*)&localObj, (short)6, (short)kY, (int)((char*)obj + 0x1b4 + 0x400), (unsigned char)kDrawFirst, (unsigned char)kDrawSecond);
    int byteLength = StringLength_020d2ff0((char*)obj + 0x1b4 + 0x400);
    short val = (byteLength / 2) * 10 + 7;
#else
    int ret = func_0205b234((void*)&localObj, (short)6, (short)kY, (int)((char*)obj + 0x1b4 + 0x400), (unsigned char)kDrawFirst, (unsigned char)kDrawSecond);
    short val = ret + 9;
#endif
    func_0205b234((void*)&localObj, val, (short)kY, (int)((char*)obj + 0x1f4 + 0x400), (unsigned char)kDrawFirst, (unsigned char)kDrawSecond);
}
