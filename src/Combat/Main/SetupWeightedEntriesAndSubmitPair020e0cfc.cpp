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
extern "C" int func_020420e8(char*, int);
extern "C" int func_0205b234(void*, short, short, int, unsigned char, unsigned char);

#if defined(jpn)
extern short data_020ee908[];
extern short data_020ee926[];
extern short data_020ee90e[];
extern short data_020ee932[];
enum { kEntryCount = 3 };
#else
extern short data_020ee818[];
extern short data_020ee800[];
extern short data_020ee810[];
extern short data_020ee808[];
enum { kEntryCount = 4 };
#endif

// JPN: func_020e292c
// USA: func_020e0cfc
ARM void SetupWeightedEntriesAndSubmitPair020e0cfc(void* obj, int b, int c, int) {
    struct Struct02020520 arr[kEntryCount];
#if defined(jpn)
    InitWeightedEntries02023064(arr, kEntryCount, data_020ee908, data_020ee926, data_020ee90e, data_020ee932);
#else
    InitWeightedEntries02023064(arr, kEntryCount, data_020ee818, data_020ee800, data_020ee810, data_020ee808);

    int len1 = func_020420e8((char*)obj + 0x2f4 + 0x400, 0);
    int len2 = func_020420e8((char*)obj + 0x324 + 0x400, 0);

#endif
    struct S_b20c localObj;
    ClearTwoWordsAndByte_0205b20c(&localObj);
    SetField0_0205b220(&localObj, b + c);
    SetFieldsAt0x4And0x8_0205b228(&localObj, (int)arr, kEntryCount);

#if defined(jpn)
    func_0205b234(&localObj, (short)45, (short)5, (int)((char*)obj + 0x288 + 0x400), (unsigned char)10, (unsigned char)15);
    func_0205b234(&localObj, (short)45, (short)17, (int)((char*)obj + 0x298 + 0x400), (unsigned char)10, (unsigned char)15);
#else
    func_0205b234(&localObj, (short)(0x5f - len1), (short)0x14, (int)((char*)obj + 0x2f4 + 0x400), (unsigned char)0xf, (unsigned char)0);
    func_0205b234(&localObj, (short)(0x5f - len2), (short)0x2c, (int)((char*)obj + 0x324 + 0x400), (unsigned char)0xf, (unsigned char)0);
#endif
}
