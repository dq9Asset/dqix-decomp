#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/MessageFrame.h"
#include "Resource/MessageRenderResources.h"

// USA: func_020e2490
ARM void InitEntryManager020e2490(EntryManager020e2490* manager, int arg1, int arg2,
    Container0205a3d0* entries, SafeAllocator* allocator, int count, unsigned char flag) {
    manager->short1c = 0;
    manager->byte1e = 8;
    manager->short18 = 0;
    manager->short1a = 0;
    manager->byte16 = 0;
    ResetBytes020e25cc(manager);

    manager->layouts = static_cast<Struct02020520*>(allocator->Allocate(count * 0xc));
    manager->destination = static_cast<GlyphDestination0205b234*>(allocator->Allocate(0xc));
    manager->clips = static_cast<ZeroStruct*>(allocator->Allocate(count * 0xc));
    manager->panel = static_cast<MessageFramePanel*>(allocator->Allocate(0x40));
    manager->frame = static_cast<MessageFrame*>(allocator->Allocate(0x4c));
    manager->entries = entries;

    int i;
    for (i = 0; i < count; i++) {
        ClearStruct02020520(&manager->layouts[i]);
        ClearZeroStruct_020e1568(&manager->clips[i]);
    }

    InitStruct020e1588(manager->panel);
    manager->panel->layouts = manager->layouts;
    manager->panel->object = manager->destination;
    manager->panel->clips = manager->clips;
    manager->panel->count = (unsigned char)count;
    manager->panel->flag3d = flag;

    InitObj020e15f8(manager->frame, arg1, arg2);
    manager->frame->panel = manager->panel;
    if (manager->entries != NULL) {
        ClearField0And40205a234(manager->entries);
    }
}
