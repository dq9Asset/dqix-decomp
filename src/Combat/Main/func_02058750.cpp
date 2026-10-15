#include <globaldefs.h>
#include <Memory/SignedAllocator.h>

struct S02055080;
struct Track02058750 { char pad[0xb0]; SignedAllocatorList entries[2]; };
struct Entry02058750 { unsigned int time; unsigned int value; };
struct Node02058750 { Entry02058750* entry; };
struct Count02058750 { char pad[8]; unsigned char count[2]; };
struct Obj02058750 {
    char pad0[4];
    unsigned int time;
    char pad1[0x20];
    Track02058750* track;
    char pad2[4];
    float scale;
    float velocityRed;
    float velocityGreen;
    float velocityBlue;
    float velocityValue;
    char pad3[0x20];
    unsigned short index[2];
};
void* GetSubField0x18_02055120(S02055080*);

// USA: func_02058750
extern "C" ARM void func_02058750(Obj02058750* self) {
    Count02058750* counts = (Count02058750*)GetSubField0x18_02055120((S02055080*)self->track);
    if (counts->count[0] > 1 && counts->count[0] > self->index[0]) {
        Node02058750* previous = (Node02058750*)self->track->entries[0].GetNthElement(self->index[0]);
        if (previous && previous->entry->time < self->time) {
            self->index[0]++;
            if (self->index[0] >= counts->count[0]) {
                self->velocityRed = 0;
                self->velocityGreen = 0;
                self->velocityBlue = 0;
            } else {
                Node02058750* next = (Node02058750*)self->track->entries[0].GetNthElement(self->index[0]);
                if (next) {
                    unsigned int prevRed;
                    unsigned int prevGreen;
                    unsigned int prevBlue;
                    unsigned int nextRed;
                    unsigned int nextGreen;
                    unsigned int nextBlue;
                    Entry02058750* prevEntry;
                    Entry02058750* nextEntry;
                    prevEntry = previous->entry;
                    nextEntry = next->entry;
                    prevRed = prevEntry->value & 0x1f;
                    prevGreen = (prevEntry->value & 0x3e0) >> 5;
                    prevBlue = (prevEntry->value & 0x7c00) >> 10;
                    nextRed = nextEntry->value & 0x1f;
                    nextGreen = (nextEntry->value & 0x3e0) >> 5;
                    nextBlue = (nextEntry->value & 0x7c00) >> 10;
                    self->velocityRed = (float)(nextRed - prevRed) / (float)(int)(nextEntry->time - prevEntry->time);
                    self->velocityGreen = (float)(nextGreen - prevGreen) / (float)(int)(next->entry->time - previous->entry->time);
                    self->velocityBlue = (float)(nextBlue - prevBlue) / (float)(int)(next->entry->time - previous->entry->time);
                }
            }
        }
    }
    if (counts->count[1] > 1 && counts->count[1] > self->index[1]) {
        Node02058750* previous = (Node02058750*)self->track->entries[1].GetNthElement(self->index[1]);
        if (previous && (float)previous->entry->time * self->scale < (float)self->time) {
            self->index[1]++;
            if (self->index[1] >= counts->count[1]) {
                self->velocityValue = 0;
            } else {
                Node02058750* next = (Node02058750*)self->track->entries[1].GetNthElement(self->index[1]);
                if (next) {
                    Entry02058750* prevEntry = previous->entry;
                    float firstPosition = (float)prevEntry->time * self->scale;
                    Entry02058750* nextEntry = next->entry;
                    float secondPosition = (float)nextEntry->time * self->scale;
                    float valueDifference = (float)(int)(nextEntry->value - prevEntry->value);
                    self->velocityValue = valueDifference / (secondPosition - firstPosition);
                }
            }
        }
    }
}
