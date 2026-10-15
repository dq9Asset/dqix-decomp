#include <globaldefs.h>
#include "Resource/MessageRenderResources.h"
#include <Memory/SafeAllocator.h>

struct AnimFrame0205a984 {
    unsigned short* content;
    unsigned short frames;
    unsigned short pad;
};
struct AnimSequence0205a984 {
    unsigned short frameCount;
    unsigned short loopStart;
    int animType;
    int playMode;
    AnimFrame0205a984* frames;
};
struct Table02b005c {
    unsigned short count;
    unsigned short pad;
    AnimSequence0205a984* entries;
};
int GetAnimBankBlockAlias020aff00(void*, void**);
AnimSequence0205a984* GetEntry16IfInRange_020b005c(Table02b005c*, unsigned int);

// USA: func_0205a984
extern "C" ARM int func_0205a984(LoadTable* self, void* data, unsigned int length, SafeAllocator* allocator) {
    void* buffer = data;
    Table02b005c* header;
    if (!buffer) buffer = 0;
    else if (!length) buffer = 0;
    else if (!GetAnimBankBlockAlias020aff00(buffer, (void**)&header)) buffer = 0;
    if (!buffer) return 1;
    Elem0205a3d0* track;
    AnimSequence0205a984* sequence;
    unsigned short i;
    unsigned short count;
    Elem0205a3d0* tracks;
    Container0205a3d0* bank = self->animationEntries;
    if (bank && allocator) {
        count = header->count;
        tracks = static_cast<Elem0205a3d0*>(allocator->Allocate(count * sizeof(Elem0205a3d0)));
        bank->entries = tracks;
        bank->count = count;
        for (i = 0; i < count; ++i) {
            sequence = GetEntry16IfInRange_020b005c(header, i);
            if (sequence) {
                track = &tracks[i];
                track->mode = 0;
                track->y = 0;
                track->x = 0;
                track->key = 0;
                track->count = 0;
                track->frames = 0;
                track->index = 0;
                track->elapsed = 0;
                track->field14 = 0xff;
                track->flags = 1;
                track->mode = sequence->playMode;
                track->count = sequence->frameCount;
                track->key = i;
                Frame0205a254* frames = static_cast<Frame0205a254*>(allocator->Allocate(track->count * sizeof(Frame0205a254)));
                track->frames = frames;
                for (unsigned short j = 0; j < track->count; ++j) {
                    AnimFrame0205a984* frame = &sequence->frames[j];
                    if (frame) {
                        Frame0205a254* info = &frames[j];
                        info->duration = 0;
                        info->field2 = 0;
                        info->duration = frame->frames;
                        info->field2 = *frame->content;
                    }
                }
            }
        }
    }
    return 0;
}
