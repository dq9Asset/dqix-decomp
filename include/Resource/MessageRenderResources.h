#pragma once

#include "Memory/SafeAllocator.h"

struct Cell0205a658 {
    unsigned short y, x, attributes;
};

struct Struct0205a198 {
    unsigned short count, flags;
    Cell0205a658* cells;
    Cell0205a658* copy;
    int scaleX, scaleY;
    int position[2];
    unsigned short angle, index, matrixIndex;
    unsigned char firstObject, transformed, doubleSize;
    signed char palette, priority;
    char padding27;
};

struct Frame0205a254 {
    unsigned short duration, field2;
};

struct Elem0205a3d0 {
    int mode;
    short x, y;
    unsigned short key, count;
    Frame0205a254* frames;
    unsigned short index, elapsed;
    unsigned char field14, flags;
    unsigned short field16;
};

struct Container0205a3d0 {
    Elem0205a3d0* entries;
    unsigned short count;
};

struct RendererResource00 {
    int words[3];
    unsigned char unknown0c[0x18];
};

struct FieldArray {
    char pad[8];
    int arr[3];
};

struct LoadTable {
    RendererResource00 resource00;
    FieldArray resource24;
    int mappingMode;
    Container0205a3d0* animationEntries;
    Struct0205a198* records;
    int field44;
    unsigned int capacity;
    unsigned short recordCount;
    unsigned short entryCount;
    unsigned char subScreen;
};

void InitStruct0205a444(LoadTable* renderer);
void ClearField0And40205a234(Container0205a3d0* entries);
void IterateEntries0205a330(Container0205a3d0* entries, int delta);

struct Rec020467f0;
int ProcessRecords0205a498(LoadTable* renderer, Rec020467f0* records, int flag, SafeAllocator* allocator);
void SetBitfieldStoreBytes0205af38(LoadTable* renderer, Struct0205a198* record, int first, int second);
void SetBitfield0205af84(LoadTable* renderer, Struct0205a198* record, int value);
void SetBitfield0205afb0(LoadTable* renderer, Struct0205a198* record, int value);
void SetBitfield0205afdc(LoadTable* renderer, Struct0205a198* record, int value);
