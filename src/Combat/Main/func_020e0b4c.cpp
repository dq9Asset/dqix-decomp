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
int StringLength_020d2ff0(const char* s);
extern "C" int func_0205b234(void*, short, short, int, unsigned char, unsigned char);

#if defined(jpn)
extern short data_020ee9e6[];
extern short data_020ee998[];
extern short data_020ee9b2[];
#else
extern short data_020ee864[];
extern short data_020ee87e[];
extern short data_020ee898[];
#endif
extern short data_020ee8b2[];

#if defined(jpn)
enum {
    kLabelStride = 0x24, kValuesOffset = 0x668,
    kThreeX = 100, kTwoX = 110, kOneX = 120, kOneY = 16,
    kDrawFirst = 10, kDrawSecond = 15
};
#else
enum {
    kLabelStride = 0x48, kValuesOffset = 0x6d4,
    kThreeX = 116, kTwoX = 120, kOneX = 125, kOneY = 15,
    kDrawFirst = 15, kDrawSecond = 0
};
#endif

// JPN: func_020e2788
// USA: func_020e0b4c
extern "C" ARM void func_020e0b4c(void* obj, void* buffer, int offset, int) {
    struct Struct02020520 arr[13];
#if defined(jpn)
    InitWeightedEntries02023064(arr, 13, data_020ee9e6, data_020ee998, data_020ee9b2, data_020ee8b2);
#else
    InitWeightedEntries02023064(arr, 13, data_020ee864, data_020ee87e, data_020ee898, data_020ee8b2);
#endif
    struct S_b20c localObj;
    ClearTwoWordsAndByte_0205b20c(&localObj);
    SetField0_0205b220(&localObj, (int)buffer + offset);
    SetFieldsAt0x4And0x8_0205b228(&localObj, (int)arr, 13);
    for (int i = 0; i < 3; i++) {
        func_0205b234(&localObj, (short)0xa, (short)(i * 13 + 0x10), (int)((char*)obj + 0x1fc + 0x400 + i * kLabelStride), (unsigned char)kDrawFirst, (unsigned char)kDrawSecond);
        char* s = (char*)obj + kValuesOffset + i * 8;
        if (StringLength_020d2ff0(s) == 3) {
            func_0205b234(&localObj, (short)kThreeX, (short)(i * 13 + 0x10), (int)s, (unsigned char)kDrawFirst, (unsigned char)kDrawSecond);
        } else if (StringLength_020d2ff0(s) == 2) {
            func_0205b234(&localObj, (short)kTwoX, (short)(i * 13 + 0x10), (int)s, (unsigned char)kDrawFirst, (unsigned char)kDrawSecond);
        } else if (StringLength_020d2ff0(s) == 1) {
            func_0205b234(&localObj, (short)kOneX, (short)(i * 13 + kOneY), (int)s, (unsigned char)kDrawFirst, (unsigned char)kDrawSecond);
        } else {
            func_0205b234(&localObj, (short)kThreeX, (short)(i * 13 + 0x10), (int)s, (unsigned char)kDrawFirst, (unsigned char)kDrawSecond);
        }
    }
}
